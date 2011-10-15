#include "include/archive.h"
using namespace std;
namespace cordite {
  namespace io {
    Resource* Archive::operator[] (const std::string fname) {
      return contents[fname];
    }
    Archive::~Archive(){
      map<string,Resource*>::iterator it;
      for(it = contents.begin(); it != contents.end(); it++){
	Resource* rsc = (*it).second;
	if(rsc)
	  delete rsc;
      }
      contents.clear();
    }
  };
};