#include "include/locator.h"
#include "include/resource.h"
#include "include/archive.h"
namespace cordite {
  namespace io {
    Locator::Locator(){
      
    }
    Locator::~Locator(){
      std::list<archiveAndPriority>::iterator it;
      for(it = archives.begin(); it != archives.end(); it++){
	archiveAndPriority& ap = (*it);
	if(ap.arch)
	  delete ap.arch;
      }
      archives.clear();
    }
    Resource* Locator::operator[] (const std::string fname){
      std::list<archiveAndPriority>::iterator it;
      for(it = archives.begin(); it != archives.end(); it++){
	archiveAndPriority& ap = (*it);
	if(ap.arch){
	  Archive& arch = *ap.arch;
	  Resource* rsc = arch[fname];
	  if(rsc){
	    return rsc;
	  }
	}
      }
      return 0;
    }
    Resource* Locator::withinPriority(
      const std::string fname,
      const int min,
      const int max){
      std::list<archiveAndPriority>::iterator it;
      for(it = archives.begin(); it != archives.end(); it++){
	archiveAndPriority& ap = (*it);
	if(ap.arch && (ap.priority >= min && ap.priority <= max)){
	  Archive& arch = *ap.arch;
	  Resource* rsc = arch[fname];
	  if(rsc){
	    return rsc;
	  }
	}
      }
      return 0;
    }
    void Locator::addArchive(Archive* arch, const int priority){
      archiveAndPriority a;
      a.arch = arch;
      a.priority = priority;
      archives.push_front(a);
      archives.sort();
      archives.reverse();//So higher priority is at the beginning
    }
  };
};