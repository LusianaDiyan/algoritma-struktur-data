//#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <cstdlib>
#include "OperationFile.h"
#include <stdlib.h>


using namespace std;

int main() {

	string lokasi = "D:\\ASDAT\\lusi.xml";
	printf_s("Masukkan Nama : ");
	string nama,nrp;
	cin >> nama;
	printf_s("Masukkan NRP : ");
	cin >> nrp;

	OperationFile op;
	//op.OverwriteToFile(lokasi, "");

	// Write to file untuk memasukkan data dengan tidak menghapus data lama
	op.WriteToFile(lokasi, "<mahasiswa>\n\t<nama>" + nama + "</nama>\n\t<nrp>" + nrp +"</nrp>\n</mahasiswa>\n");
	
	// Print to screen untuk menampilkan data dari lokasi yang telah di tentukan
	op.printToScreen(lokasi);
	
	//op.printXMLToScreen(lokasi, "nrp");
	//string file = op.getFile(lokasi);
	//vector<string> data = op.getData(file,"mahasiswa");
	
	/*for (size_t i = 0; i < data.size(); i++)
	{
		cout << data[i];
	}*/

	/*
	op.printToScreen("D:\\ASDAT\\lusi.txt");
	op.WriteToFile("D:\\ASDAT\\lusi.txt", "abc");
	op.printToScreen("D:\\ASDAT\\lusi.txt");
	*/
	
	//Memindah file
	char oldname[] = "D:\\ASDAT\\lusi.xml";
	char newname[] = "D:\\ASDAT\\lusi.xml";

	//op.OverwriteToFile("D:\\ASDAT\\lusi.xml", "say hi to me");
	op.moveFile(oldname, newname);
	
	system("pause");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
