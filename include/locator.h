#ifndef LOCATOR_H
#define LOCATOR_H
#include <string>
#include <list>
namespace cordite {
  namespace io {
    class Archive;
    class Resource;
    class Locator {
    protected:
      struct archiveAndPriority {
	Archive* arch;
	int priority;
	inline bool operator< (archiveAndPriority& b){
	  return priority < b.priority;
	}
	inline bool operator> (archiveAndPriority& b){
	  return priority > b.priority;
	}
      };
      std::list<archiveAndPriority> archives;
    public:
      Locator();
      virtual ~Locator();
      Resource& operator[] (const std::string fname);
      Resource* withinPriority(
	const std::string fname,
	const int min,
	const int max);
      void addArchive(Archive* arch, const int priority);
    };
  };
};
#endif // LOCATOR_H
