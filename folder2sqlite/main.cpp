#include <iostream>
extern "C" {
#include <sqlite3.h>
};
#include <boost/filesystem.hpp>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <sstream>
using namespace std;
const char* usage_string = 
  "Cordite Folder To Sqlite USAGE:\n"
  "folder2sqlite <folder> <output sqlite file>\n"
  "\tDatabases are overwritten, not updated.\n"
  "\n\tOne can also include multiple folders\n"
  "folder2sqlite <folder1> <folder2> <...> <output sqlite file>\n"
  "\tFile Name collision is undefined, Whether you get the first file that is ever seen or the last you cannot depend on. They are unique identifiers.";
void initdb(sqlite3* db);
void insertFile(sqlite3* db, string& path);
  int main(int argc, char* argv[]) {
  if(argc < 3){
    cout << "Incorrect usage.\n" << usage_string << "\n"; 
    return 1;
  }
  vector<string> folders;
  for(int i = 1; i < argc-1; i++){
    folders.push_back(argv[i]);
  }
  string dbname = argv[argc-1];
  for(int i = 0; i < folders.size(); i++){
   if(!boost::filesystem::is_directory(folders[i])){
     cout << folders[i] << " is not a directory!\n";
     return 1;
   }
  }
  if(boost::filesystem::exists(dbname)){
    boost::filesystem::remove(dbname);//delete
  }
  //Now for the sqlite stuff
  sqlite3* db = 0;
  if(sqlite3_open(dbname.c_str(),&db)){
    sqlite3_close(db);
    cout << "Could not open " << dbname << "\n";
    return 1;
  }
  initdb(db);
  //Now, go through all the files in the folders.
  for(int i = 0; i < folders.size(); i++){
    boost::filesystem::recursive_directory_iterator enditr;
    boost::filesystem::recursive_directory_iterator d(folders[i]);
    for(;d != enditr; d++){
     if(boost::filesystem::is_regular_file(d->status())){ 
      std::string fullName = d->path().string();
      insertFile(db,fullName);
     }
    }
  };
  //Finally
  sqlite3_close(db);
  return 0; 
}
void initdb(sqlite3* db){
  //Create table data
  //CREATE TABLE 'files' ( 'filename' VARCHAR ( 60 ) NOT NULL PRIMARY KEY , 'contents' BLOB , 'size' BIGINT NOT NULL ) ;
  const char* sql = "CREATE TABLE 'files'"
		    "( 'filename' VARCHAR ( 60 ) NOT NULL PRIMARY KEY , "
		    "'contents' BLOB , 'size' BIGINT NOT NULL ) ;";
  sqlite3_exec(db, sql,0,0,0);
}
void insertFile(sqlite3* db, string& path){
  if(boost::filesystem::is_regular_file(path)){
    cout << "Doing " << path << "\n";
   //We shall commense!
   sqlite3_stmt *stmt=0;
   

   boost::filesystem::path p(path);
   ifstream reader;
   //Note: this will stick it ALL in RAM and then into sqlite. Incremental blob IO 
   //Can be done with http://www.sqlite.org/capi3ref.html#sqlite3_blob_open
   reader.open(path.c_str());
   reader.seekg (0, ios::end);
   long int size = reader.tellg();
   reader.seekg (0, ios::beg);
   char* buffer;
   if(size > 0){
    buffer = (char*)malloc(size);
    reader.read(buffer, size);
cout << size << " is the size...\n";
    stringstream sqls;
    sqls << "INSERT INTO 'files' VALUES('";  
    sqls << p.filename();
    sqls << "',?,'";
    sqls << size;
    sqls << "')";
    string sqls2 = sqls.str();
    char* sql = (char*)sqls2.c_str();
    sqlite3_prepare(db, sql,strlen(sql),&stmt,0);
    //sqlite3_bind_text(stmt,0,path.c_str(), path.length(),SQLITE_STATIC);
    sqlite3_bind_blob(stmt,1,buffer,size,SQLITE_STATIC);
    //sqlite3_bind_int64(stmt,2,size);
    if(sqlite3_step(stmt) != SQLITE_DONE){
      cout << "Sqlite error \"" << sqlite3_errmsg(db) << "\" for file " << path << "\n"; 
    }
    sqlite3_finalize(stmt);
    free(buffer);
   }
  }
}

