#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>
namespace cordite {
  namespace io {
    enum ResorceType{
      RT_REAL,
      RT_DB,
      RT_COMPRESSED
    };
    class File;
    class Archive;
    class Resource{
    protected:
      friend class Archive;
      ResorceType type;
      std::string fname;
      File* fpointer;
      Resource();
      
    public:
	
	virtual ~Resource();
	inline const std::string fileName() const {return fname;};
	virtual File* file() const;
    };
  };
};
#endif // RESOURCE_H
