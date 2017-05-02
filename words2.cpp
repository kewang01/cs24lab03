// words1.cpp - implements class Words
// (dynamic size array version)

#include <cassert>
#include <string>
#include "words2.h"

using std::string;

namespace lab03_2
{
    Words::Words(unsigned int initial_capacity) {
      std::string *data=new std::string[initial_capacity];
      used = 0;
      capacity = initial_capacity;
    }

    Words::Words(const Words& source){
      std::string *data=new std::string[source.size()];
      used=source.size();
      capacity=source.get_capacity();
      for(int i=0;i<used;i++){
	data[i]=source[i];
      }
    }

  Words::~Words(){
    delete [] data;
  }
    
  void Words::append(string word) {
    if(used < capacity){
	data[used]=word;
	++used;
      }
    else{
      string *p=new std::string[used+1];
      for(int i=0;i<used;i++){
	p[i]=data[i];
      }
      p[used]=word;
      used++;
      capacity++;
      delete [] data;
      data=p;
    }
  }

  Words& Words::operator=(const Words& source){
    if(this==&source){
      return *this;
    }
    else{
      delete data;
      string *p=new string[source.get_capacity()];
      used=source.size();
      capacity=source.get_capacity();
      for(int i=0;i<used;i++){
	p[i]=source[i];
      }
      data=p;
      return *this;
    }
  }
      
  
	
    string& Words::operator[] (unsigned int index) {
        assert(index < used);
        return data[index];
    }
    
    unsigned int Words::size() const {
        return used;
    }
    
    unsigned int Words::get_capacity() const {
        return capacity;
    }
    
    string Words::operator[] (unsigned int index) const {
        assert(index < used);
        return data[index];
    }
    
}
