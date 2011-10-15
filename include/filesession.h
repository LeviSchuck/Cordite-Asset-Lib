#ifndef FILESESSION_H
#define FILESESSION_H
namespace cordite {
  namespace io {
    class Resource;
    class File;
    class FileSession{
      friend class Resource;
      friend class File;
      File* parent;
      
    public:
      virtual unsigned long getPos() = 0;
      virtual unsigned long getSize() = 0;
      virtual void read(
	void* buffer, 
	const unsigned long sizeToRead) = 0;
      virtual bool seek(
	const unsigned long Position, 
	const bool relative = false) = 0;
      
    };
  };
};


#endif // FILESESSION_H
