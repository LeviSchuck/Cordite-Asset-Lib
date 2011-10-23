#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "include/tarc/tcarchive.h"
#include "include/tarc/tcresource.h"
#include "include/tar/tresource.h"
#include <boost/algorithm/string.hpp>
#include "include/tarc/tarparts.h"
#include "zlib/zlib.h"
//namespace fs = boost::filesystem;
using namespace std;
namespace cordite{
  namespace io {
    TCArchive::TCArchive(const std::string& path){
      //Do archiving;
      vector<string> parts;
      boost::split(parts,path,boost::is_any_of("."));
      string ext = parts[parts.size()-1];
      //If you want, make lower case code here.
      archive_info ai;
      ai.path = path;
      ai.type = AT_UNSUPPORTED;
      if(!ext.compare("tar")){
	ai.type = AT_RAW;
      }
      if(!ext.compare("gz")){
	ai.type = AT_GZ;
      }
      if(!ext.compare("bz2")){
	ai.type = AT_BZ2;
      }
      if(!ext.compare("lzma")){
	ai.type = AT_LZMA;
      }
      if(!ext.compare("zip")){
	ai.type = AT_ZIP;
      }
      //cout << "Extension is \"" << ext << "\"\n";
      switch(ai.type){
	case AT_RAW:{
	  ifstream reader(path.c_str(), ifstream::in | ios::binary);
	  int zeroevents = 0;
	  while(reader.good() && zeroevents < 2){
	    //cout << "Currently at " << reader.tellg() << "\n";
	    tar_header h;
	    reader.read((char*)&h,sizeof(tar_header));
	    if(strlen(h.filename) == 0){
	      reader.seekg((unsigned long)reader.tellg()+(512-sizeof(tar_header)));
	      //cout << "Hit empty segment\n";
	      zeroevents++;
	      continue;
	    }
	    tar_info info(h);
	    //cout << "file: " << info.filename << " size: " << info.size << "\n";
	    reader.seekg((unsigned long)reader.tellg()+(512-sizeof(tar_header)));//Now at file position;
	    //do file stuff
	    unsigned long blocks = info.size/512+1;
	    unsigned long blockbytes = blocks << 9;
	    if(info.type == TF_REGULAR){
	      //cout << "Current at " << reader.tellg() << "\n";
	      //cout << "seeking " << blockbytes << " bytes ahead \n";
	      //I'm not going to bother with trimming directories.
	      if(fnames.find(info.filename) != fnames.end()){
		    delete contents[info.filename];//Though this should never happen...
	      }
	      contents[info.filename] = new TResource(path,info,reader.tellg());
	      fnames.insert(info.filename);
	      reader.seekg((unsigned long)reader.tellg()+blockbytes);

	      zeroevents = 0;
	    }//I'm not going to handle linked or symbolic files

	  }
	  reader.close();
	}break;
	case AT_GZ:{
	  gzFile file;
	  file = gzopen(path.c_str(),"rb");
	  if(!file){
	    return;
	    cout << "Could not open " << path << "\n";
	  }
	  bool okay = true;
	  int zeroevents = 0;
	  while(okay && zeroevents < 2){
	    tar_header h;
	    int readlen = 0;
	    readlen = gzread(file,&h,sizeof(tar_header));
	    if(readlen <= 0){okay = false; break;}
	    
	    gzseek(file,(512-sizeof(tar_header)),SEEK_CUR);
	    if(strlen(h.filename) == 0){
	      //cout << "Hit empty segment\n";
	      zeroevents++;
	      continue;
	    }
	    tar_info info(h);
	    //cout << "file: " << info.filename << " size: " << info.size << "\n";
	    unsigned long blocks = info.size/512+1;
	    unsigned long blockbytes = blocks << 9;
	    if(info.type == TF_REGULAR){
	      //cout << "Current at " << reader.tellg() << "\n";
	      
	      //I'm not going to bother with trimming directories.
	      if(fnames.find(info.filename) != fnames.end()){
		    delete contents[info.filename];//Though this should never happen...
	      }
	      ai.info = info;
	      ai.offset = gztell(file);
	      contents[info.filename] = new TCResource(ai);
	      fnames.insert(info.filename);
	      //cout << "seeking " << blockbytes << " bytes ahead \n";
	      gzseek(file,blockbytes,SEEK_CUR);
	      zeroevents = 0;
	    }
	  }
	  gzclose(file);
	}break;
	case AT_ZIP:
	case AT_LZMA:
	case AT_BZ2:
	
	default:
	  cout << "Unsupported archive type " << ai.type << "\n";
      }
      
    }
    
    TCArchive::~TCArchive(){
      //clean up
      map<string,Resource*>::iterator it;
      for(it = contents.begin(); it != contents.end(); it++){
	TCResource* rsc = (TCResource*)((*it).second);
	if(rsc)
	  delete rsc;
      }
    }
    
  };
};