#include "File.h"

File::File(string name){
	file_name=name;
}

string File:: read_file(){
	ifstream inputFile;
	string text="";
	inputFile.open(file_name);
	while(!inputFile.eof()){
		text += inputFile.get();
	}
	inputFile.close();
	return text;
}

void File::write_file(string text){
	ofstream outputFile;
	outputFile.open(file_name);
	outputFile<<text;
	outputFile<<"\n";
	outputFile.close();
}
