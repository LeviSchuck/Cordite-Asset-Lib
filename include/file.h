#ifndef FILE_H
#define FILE_H
#include <list>
namespace cordite {
  namespace io {
    class Resource;
    class FileSession;
    class File{
      friend class Resource;
      friend class FileSession;
    protected:
      Resource* parent;
      File();
    public:
      virtual FileSession* newSession() = 0;
      virtual ~File();
    };
  };
};


#endif // FILE_H
