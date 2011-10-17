#ifndef ZFILESESSION_H
#define ZFILESESSION_H
#include <string>
#include "include/filesession.h"
namespace cordite {
  namespace io {
    class ZResource;
    class ZFileSession: public FileSession{
      friend class ZResource;
    protected:
      ZFileSession(const std::string& path);
      unsigned long size;
      void* db;
    public:
	
	virtual ~ZFileSession();
	unsigned long getPos();
	unsigned long getSize();
	void read(
	  char* buffer,
	  const unsigned long sizeToRead);
	bool seek(
	const long Position,
	const bool relative = false);
    };
  };
};

#endif // ZFILESESSION_H
