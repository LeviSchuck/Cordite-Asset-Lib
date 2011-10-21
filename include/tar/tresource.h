#ifndef TRESOURCE_H
#define TRESOURCE_H
#include "include/resource.h"
#include "tarparts.h"
#include <string>
//class tar_info;
namespace cordite {
  namespace io {
    class TArchive;
    class TResource: public Resource {
      friend class TArchive;
      TResource(
	const std::string &tarname,
	const tar_info info,
	const unsigned long &seekpos);
      unsigned long _seekpos;
      std::string _tarname;
      const tar_info _info;
    public:
      virtual ~TResource();
      FileSession* session();
    };
  };
};


#endif // TRESOURCE_H
