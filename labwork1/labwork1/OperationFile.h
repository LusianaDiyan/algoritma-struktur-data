#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <cstdlib>

using namespace std;
//this class contains function to manipulate XML file

class OperationFile
{
public:
	OperationFile();
	~OperationFile();
	void moveFile(char oldname[], char newname[]);
	void OverwriteToFile(string filename, string content);
	void printToScreen(string filename);
	string getFile(string filename);
	vector<string> getData(const string &text, string tag);
	void stripTags(string &text);
	void printXMLToScreen(string filename, string tag);
	string ConcantenateText(string filename, string input);
	void WriteToFile(string filename, string input);
}; //#pragma once
