#include "include/archive.h"
#include <iostream>
using namespace std;
namespace cordite {
  namespace io {
    Resource* Archive::operator[] (const std::string fname) {
      return contents[fname];
    }
    Archive::~Archive(){
      //std::cout << "Base Archive destruction\n";

    }
  };
};