#include <iostream>
#include "include/cassetlib.h"
#include <stdlib.h>
#include <sstream>
using namespace cordite::io;
using namespace std;
int main(int argc, char **argv) {
    
    Locator l;
    {
      cout << "Starting the Real File implementation tests\n\n";
      RArchive* ra = new RArchive("tests/test1");
      l.addArchive(ra,1);
      Resource* r = l["awesome.txt"];
      if(r){
	cout << "awesome.txt was found.\n";
      }else{
	cout << "awesome.txt was NOT found.\n";
      }
      {
	FileSession* fs = r->session();
	void* data = malloc(fs->getSize());
	fs->read((char*)data, fs->getSize());
	stringstream ss;
	ss.write((char*)data,fs->getSize());
	free(data);
	delete fs;
	if(ss.str().compare("I am awesome.") == 0){
	  cout << "Override and collection test\tpassed.\n";
	}else{
	  cout << "Override and collection\t\tDID NOT pass.\n";
	  cout << "Expected \"I am awesome.\" but got \""
	      << ss.str() << "\"\n";
	}
      }
      l.addArchive(new RArchive("tests/test2"),3);
      //Now, lets try to add another folder
      {
	r = l["awesome.txt"];
	FileSession* fs = r->session();
	void* data = malloc(fs->getSize());
	fs->read((char*)data, fs->getSize());
	stringstream ss;
	ss.write((char*)data,fs->getSize());
	free(data);
	delete fs;
	if(ss.str().compare("I was awesome.") == 0){
	  cout << "Override and priority test\tpassed.\n";
	}else{
	  cout << "Override and priority \t\tDID NOT pass.\n";
	  cout << "Expected \"I was awesome.\" but got \""
	      << ss.str() << "\"\n";
	}
      }
      {
	r = l.withinPriority("awesome.txt",0,1);
	FileSession* fs = r->session();
	void* data = malloc(fs->getSize());
	fs->read((char*)data, fs->getSize());
	stringstream ss;
	ss.write((char*)data,fs->getSize());
	free(data);
	delete fs;
	if(ss.str().compare("I am awesome.") == 0){
	  cout << "priority range test\t\tpassed.\n";
	}else{
	  cout << "priority range\t\t\tDID NOT pass.\n";
	  cout << "Expected \"I am awesome.\" but got \""
	      << ss.str() << "\"\n";
	}
      }
      {
	r = l["another.txt"];
	FileSession* fs = r->session();
	void* data = malloc(fs->getSize());
	fs->read((char*)data, fs->getSize());
	stringstream ss;
	ss.write((char*)data,fs->getSize());
	free(data);
	delete fs;
	if(ss.str().compare("Some content here.") == 0){
	  cout << "Previous Retention test\t\tpassed.\n";
	}else{
	  cout << "Previous Retention\t\t\tDID NOT pass.\n";
	  cout << "Expected \"Some content here.\" but got \""
	      << ss.str() << "\"\n";
	}
      }
    }
    
    
    
    return 0;
}
