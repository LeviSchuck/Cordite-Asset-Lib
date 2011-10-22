#ifndef TCFILESESSION_H
#define TCFILESESSION_H
#include <string>
#include "include/filesession.h"
namespace cordite {
  namespace io {
    class TCResource;
    class TCFileSession: public FileSession{
      friend class TCResource;
    protected:
      TCFileSession(const std::string& path);
      unsigned long size;
    public:
	
	virtual ~TCFileSession();
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
