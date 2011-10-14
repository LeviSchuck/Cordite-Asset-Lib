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
      virtual unsigned long getPos();
      virtual unsigned long getSize();
      virtual void read(
	void* buffer, 
	const unsigned long sizeToRead);
      virtual bool seek(
	const unsigned long Position, 
	const bool relative = false);
      
    };
  };
};


#endif // FILESESSION_H
