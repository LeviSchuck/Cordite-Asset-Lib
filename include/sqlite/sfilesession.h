#ifndef SFILESESSION_H
#define SFILESESSION_H
#include <string>
#include "include/filesession.h"
#include <sqlite3.h>
namespace cordite {
  namespace io {
    class SResource;
    class SFileSession: public FileSession{
      friend class SResource;
    protected:
      SFileSession();
      unsigned long size;
      sqlite3* db;
      sqlite3_blob* b;
      long int pos;
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
