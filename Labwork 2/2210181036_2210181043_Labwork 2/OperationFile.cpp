//#include "pch.h"
#include "OperationFile.h"


OperationFile::OperationFile() {
}


OperationFile::~OperationFile() {
}
/*
	Fungsi ini digunakan untuk memindahkan file atau mengubah nama file.
	parameter oldname menunjukkan lokasi lama file.
	parameter newname menunjukkan lokasi baru file

	contoh pemanggilan fungsi
	char lama = "D:\\OneDrive\\Kuliah\\Algoritma dan Struktur Data\\project\\Labwork1\\Labwork1\\dea2.txt";
	char baru = "D:\\OneDrive\\Kuliah\\Algoritma dan Struktur Data\\project\\Labwork1\\Labwork1\\dea.txt";

	moveFile (lama, baru);
*/
void OperationFile::moveFile(char oldname[], char newname[]) {
	if (rename(oldname, newname) != 0)
		perror("Error moving file");
	else
		cout << "File moved successfully";
}

void OperationFile::OverwriteToFile(string filename, string content) {
	ofstream myfile;
	myfile.open(filename);
	myfile << content << endl;
	myfile.close();
}

/*
	Fungsi ini digunakan untuk mencetak isi file ke layar.
	parameter filename menunjukkan nama file yang perlu dicetak

	contoh pemanggilan fungsi
	string filename = "D:\\OneDrive\\Kuliah\\Algoritma dan Struktur Data\\project\\Labwork1\\Labwork1\\dea.txt";

	printToScreen (filename);
*/
void OperationFile::printToScreen(string filename) {
	char ch;
	ifstream file;
	file.open(filename, ios::in);
	if (!file) {
		cout << "Error in opening file!!!" << endl;
	}

	while (!file.eof()) {
		file >> noskipws >> ch;
		cout << ch;
	}
	file.close();
}


string OperationFile::getFile(string filename) {
	string buffer;
	char c;
	ifstream in(filename);
	if (!in) {
		cout << filename << " not found";   exit(1);
	}
	while (in.get(c)) buffer += c;
	in.close();
	return buffer;
}
vector <string> OperationFile::getData(const string& text, string tag) {
	vector<string> collection;
	unsigned int pos = 0, start;

	while (true) {
		start = text.find("<" + tag, pos);   if (start == string::npos) return collection;
		start = text.find(">", start);
		start++;

		pos = text.find("</" + tag, start);   if (pos == string::npos) return collection;
		collection.push_back(text.substr(start, pos - start));
	}
}
void OperationFile::stripTags(string& text) {
	unsigned int start = 0, pos;
	while (start < text.size()) {
		start = text.find("<", start);    if (start == string::npos) break;
		pos = text.find(">", start);    if (pos == string::npos) break;
		text.erase(start, pos - start + 1);
	}
}

/*
	Fungsi ini digunakan untuk mencetak file xml.
	filename menunjukkan nama fungsi.
	tag menunjukkan tag xml.
	semisal :

	<mahasiswa> a </mahasiswa>

	string filename = "D:\\OneDrive\\Kuliah\\Algoritma dan Struktur Data\\project\\Labwork1\\Labwork1\\dea.txt";
	string tag = "mahasiswa";

	printXMLToScreen (filename, tag);
*/
void OperationFile::printXMLToScreen(string filename, string tag) {
	bool stripOtherTags = true;
	string text = getFile(filename);
	vector<string> all = getData(text, tag);

	for (string& s : all) {
		if (stripOtherTags) stripTags(s);
		cout << s << '\n';
	}
}



string OperationFile::ConcantenateText(string filename, string input) {
	char ch;
	string output = "";
	ifstream file;
	file.open(filename, ios::in);
	if (!file) {
		cout << "Error in opening file!!!" << endl;
	}

	while (!file.eof()) {
		file >> noskipws >> ch;
		output = output + ch;
	}
	file.close();
	output = output + input;
	return output;
}

/*
	Fungsi ini digunakan untuk menambahkan menulis ke dalam file.

	Parameter filename menunjukkan nama file yang ingin ditulis isinya.
	input menunjukkan teks yang akan dimasukkan.

	Contoh

	string filename = "D:\\OneDrive\\Kuliah\\Algoritma dan Struktur Data\\project\\Labwork1\\Labwork1\\dea.txt";
	string input = "test";

	WriteToFile (filename, input);
*/
void OperationFile::WriteToFile(string filename, string input) {
	string out = ConcantenateText(filename, input);
	OverwriteToFile(filename, out);
}