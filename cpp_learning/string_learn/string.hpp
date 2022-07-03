#include<iostream>
#include<string.h>
#ifndef _MY_STRING
#define _MY_STRING
class String{
public:
    //ctor
    String(char* m_data);
    
    //dector
    ~String() {
        std::cout << "delete!" <<std::endl;
        delete[] data_;
    };
    
    //copy ctor
    String(const String& ref );
    
    //overide =
    String& operator = (const String& ref);
    //overide cout
    friend std::ostream& operator << (std::ostream& os, const String& ref);
    char* get_ptr() {
        return data_;
    }
private:
    char* data_;
    int val;
};

class Test {
public:
    Test(int* data = NULL) {data_ = data;}
    ~Test(){
        std::cout << "delete!" << std::endl;
    }
    int* get_ptr() {return data_;}
private:
    int* data_;
};



#endif