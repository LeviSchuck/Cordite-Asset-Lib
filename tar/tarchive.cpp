#include <fstream>
#include <iostream>
#include <cstring>
#include "include/tar/tarchive.h"
#include "include/tar/tresource.h"
#include "include/tar/tarparts.h"

using namespace std;
namespace cordite{
  namespace io {
    TArchive::TArchive(const std::string& path){
      ifstream reader(path.c_str(),ifstream::in);
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
    }
    
    TArchive::~TArchive(){
      //clean up
      //cout << "Tar Archive destruction\n";
      map<string,Resource*>::iterator it;
      for(it = contents.begin(); it != contents.end(); it++){
	TResource* rsc = (TResource*)((*it).second);
	if(rsc)
	  delete rsc;
      }
    }
    
  };
};
