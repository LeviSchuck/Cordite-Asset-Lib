#ifndef TFILESESSION_H
#define TFILESESSION_H
#include <string>
#include <fstream>
#include "include/filesession.h"
namespace cordite {
  namespace io {
    class TResource;
    class TFileSession: public FileSession{
      friend class TResource;
    protected:
      TFileSession(
	const std::string& path,
	const unsigned long offset,
	const unsigned long size
      );
      unsigned long _size;
      unsigned long _offset;
      std::ifstream reader;
      unsigned long pos;
    public:
	
	virtual ~TFileSession();
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

#endif // TFILESESSION_H
