#include "File.h"

File::File(char name, t){
	strcpy(file_name, name);
	strcpy(text, t);
}

char* File:: read_file(){
	ifstream inputFile;
	char name[20];
	strcpy(file_name, name);
	strcat(name, ".txt");
	inputFile.open(name);
	while(!inputFile.eof()){
		inputFile.get(text);
	}
	inputFile.close();
	return text;
}

void write_file(){
	ofstream outputFile;
	char name[20];
	strcpy(file_name, name);
	strcat(name, ".txt");
	outputFile.open(name);
	outputFile<<text;
	outputFile<<"\n";
	outputFile.close();
	return;
}