#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class File{
protected:
    char[20] file_name;
    char[200] text;
public:
    File (char name, char t);
    char* read_file();
    void write_file();
};

#endif //FILE_H
