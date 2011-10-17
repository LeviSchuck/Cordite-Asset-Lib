#ifndef SFILESESSION_H
#define SFILESESSION_H
#include <string>
#include "include/filesession.h"
namespace cordite {
  namespace io {
    class SResource;
    class SFileSession: public FileSession{
      friend class SResource;
    protected:
      SFileSession(const std::string& path);
      unsigned long size;
      void* db;
    public:
	
	virtual ~SFileSession();
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

#endif // SFILESESSION_H
