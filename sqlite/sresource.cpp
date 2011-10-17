#include "include/sqlite/sresource.h"
#include "include/sqlite/sfilesession.h"
#include <iostream>
#include <boost/filesystem/path.hpp>
using namespace std;
namespace cordite {
  namespace io {
    SResource::SResource(std::string& finame, long int& rowid, std::string& dbpath){
      type = cordite::io::RT_DB;
      _rowid = rowid;
      _dbpath = dbpath;
      fname = finame;
    }
    SResource::~SResource(){
    }
    FileSession* SResource::session(){
      SFileSession* nfile = 0;
      sqlite3 *db;
      if(sqlite3_open(_dbpath.c_str(),&db)){
	cout << "Could not open database " << _dbpath << "\n";
	sqlite3_close(db);
	return 0;
      }
      sqlite3_blob *b;
      int res = sqlite3_blob_open(db,"main","files","contents",_rowid,0,&b);
      if(res > 0){
	sqlite3_close(db);
	cout << "SQLITE ERROR:" << res << "\n";
	return 0;
      }
      nfile = new SFileSession();
      nfile->b = b;
      nfile->db = db;
      
	
      return nfile;
    }
    

  };
};