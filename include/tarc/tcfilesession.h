#ifndef TCFILESESSION_H
#define TCFILESESSION_H
#include <string>
#include "include/filesession.h"
#include "zlib/zlib.h"
struct archive_info;
namespace cordite {
  namespace io {
    class TCResource;
    class TCFileSession: public FileSession{
      friend class TCResource;
    protected:
      TCFileSession(const archive_info& ai);
      unsigned long size;
      const archive_info &_ai;
      gzFile file;
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
