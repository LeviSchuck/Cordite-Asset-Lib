#ifndef FILESESSION_H
#define FILESESSION_H


namespace cordite {
  namespace io {
    class Resource;
    class FileSession{
    protected:
      friend class Resource;
      Resource* parent;
      
    public:
      virtual unsigned long getPos() = 0;
      virtual unsigned long getSize() = 0;
      virtual void read(
	char* buffer,
	const unsigned long sizeToRead) = 0;
      virtual bool seek(
	const long Position,
	const bool relative = false) = 0;
      
    };
  };
};


#endif // FILESESSION_H
