#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <queue>
#include "include/real/rarchive.h"
#include "include/real/rresource.h"
#include <iostream>
namespace fs = boost::filesystem;
namespace cordite{
  namespace io {
    RArchive::RArchive(const std::string& path){
      traverse(path);
    }
    void RArchive::traverse(const std::string& path){
      fs::path full_path(path);
      if(!fs::exists(full_path))
	return;
      std::queue<fs::path> toTraverse;
      if(fs::is_directory(full_path)){
	//We can traverse!
	fs::directory_iterator end_iter;
	for(fs::directory_iterator d(full_path);
	  d != end_iter; d++
	){
	  try {
	    if(fs::is_directory(d->status())){
	      toTraverse.push(d->path());
	    }else if(fs::is_regular_file(d->status())){
	      //TODO: code to create resource and stick it in the map
	      //Ensure that we do no overrides, or, if we do, we free
	      //The old resource pointers.
	      std::string fileName = d->path().filename();
	      //std::cout << "Found " << fileName << "\n";
	      bool putinset = true;
	      if(fnames.find(fileName) != fnames.end()){
		delete contents[fileName];
		putinset = false;
		//std::cout << "Deleted duplicate resource for "
		//  << fileName << "\n";
	      }
	      std::string fullName = d->path().string();
	      contents[fileName] = new RResource(fullName);
	      if(putinset){
		fnames.insert(fileName);
	      }
	    }
	    
	  }catch(...){}//I don't care to know what is wrong
	  //if you do, it should be a const std::exception &ex
	}
      }
      while(!toTraverse.empty()){
	fs::path go = toTraverse.front();
	traverse(go.string());
	toTraverse.pop();
      }
    }
    RArchive::~RArchive(){
      
    }
    
  };
};