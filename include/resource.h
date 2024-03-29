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
    class FileSession;
    class Archive;
    class Resource{
    protected:
      friend class Archive;
      ResorceType type;
      std::string fname;
      std::string fullpath;
    public:
	
	inline const std::string fileName() const {return fname;};
	virtual FileSession* session() = 0;
	virtual ~Resource(){}
    };
  };
};
#endif // RESOURCE_H
