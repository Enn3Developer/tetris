#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class File{
protected:
    string file_name;
public:
    File (string name);
    string read_file();
    void write_file(string text);
};

#endif //FILE_H
