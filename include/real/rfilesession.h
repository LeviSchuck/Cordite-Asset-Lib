#ifndef RFILESESSION_H
#define RFILESESSION_H
#include <string>
#include <fstream>
#include "include/filesession.h"
namespace cordite {
  namespace io {
    class RResource;
    class RFileSession: public FileSession{
      friend class RResource;
    protected:
      RFileSession(const std::string& path);
      std::ifstream reader;
      unsigned long size;
    public:
	
	virtual ~RFileSession();
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

#endif // RFILESESSION_H
