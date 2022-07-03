#include "string.hpp"
String::String(char* m_data) {
    if (*m_data != NULL) {
        data_ = new char[strlen(m_data) + 1];
        strcpy(data_, m_data);
    } else {
        strcpy(data_,"\0");
    }
}

String::String(const String& ref) {
    if(ref.data_) {
        data_ = new char[strlen(ref.data_) + 1];
        strcpy(data_, ref.data_);
    } else {
        strcpy(data_, "\0");
    }
}

String& String::operator = (const String& ref) {
    if(ref.data_) {
        delete[] data_;
        data_ = new char[strlen(ref.data_) + 1];
        strcpy(data_, ref.data_);
    } else {
        strcpy(data_, "\0");
    }
    return *this;
}

std::ostream& operator << (std::ostream& os, const String& ref) {
    for(int i = 0; i < strlen(ref.data_); i++) {
        os << ref.data_[i] ;
    }
    os << std::endl;
    return os;
}







