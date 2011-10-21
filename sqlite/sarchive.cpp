#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include "include/sqlite/sarchive.h"
#include "include/sqlite/sresource.h"
#include <sqlite3.h>
#include <iostream>
namespace fs = boost::filesystem;
using namespace std;
namespace cordite{
  namespace io {
    SArchive::SArchive(const string &path){
      //Do archiving;
      if(fs::is_regular_file(path)){

	sqlite3 *db;
	if(sqlite3_open(path.c_str(),&db)){
	  cout << "Could not open database " << path << "\n";
	  sqlite3_close(db);
	  return;
	}
	sqlite3_stmt *stmt;
	if(!sqlite3_prepare_v2(db,"SELECT filename, rowid FROM files",-1, &stmt,0)){
	 int rc;
	 do {
	   rc = sqlite3_step(stmt);
	   if(rc == SQLITE_DONE)
	     break;
	   if(rc == SQLITE_ROW){
	     long int rowid = 0;
	     string fname;
	     fname = (const char*)sqlite3_column_text(stmt, 0);
	     rowid = sqlite3_column_int64(stmt,1);
	     string dbpath(path);
	     contents[fname] = new SResource(fname, rowid,dbpath);
	     fnames.insert(fname);
	   }
	 }while(rc== SQLITE_ROW);
	 sqlite3_finalize(stmt);
	}
	
	sqlite3_close(db);
      }
    }
    
    SArchive::~SArchive(){
      //clean up
      map<string,Resource*>::iterator it;
      for(it = contents.begin(); it != contents.end(); it++){
	SResource* rsc = (SResource*)((*it).second);
	if(rsc)
	  delete rsc;
      }
    }
    
  };
};