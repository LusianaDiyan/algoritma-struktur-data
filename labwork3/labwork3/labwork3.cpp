// Labwork1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <cstdlib>
#include "OperationFile.h"

using namespace std;

//mendeklarasikan struct
struct Transaksi {
	string id_trans;
	string jenis_trans;
	string metode_pembayaran;
	string harga;
	string tanggal;
	Transaksi* next = NULL;
	string waktu;
} *head, *tail, *print;

//mendeklarasikan fungsi
void initiate();
int isEmpty();
void addLast(string id_trans, string jenis_trans, string metode_pembayaran, string harga, string tanggal);
void getXMLData(string filename);
int CountTransaksi(string filename);
void PrintList();
void jenispalingbanyak();
void nominalpalingbanyak();
void total();
void cashback();
void banyaktransaksi(string waktu);

int main() {
	initiate();
	OperationFile op;

	//memanggil file xml
	getXMLData("D://PENS//semester3//algoritma dan struktur data//transaksi.xml");
	
	//memanggil fungsi
	PrintList();
	jenispalingbanyak();
	nominalpalingbanyak();
	total();
	cashback();
	banyaktransaksi("11 Sept 2019");
	system("PAUSE");
}

//deklarasi bahwa di list tidak terdapat data
void initiate() {
	head = tail = NULL;
}

//mengecek linked list
int isEmpty() {
	return (head == NULL) ? 1 : 0; //jika list kosong bernilai 1
}

//menambahkan data terakhir 
void addLast(string id_trans, string jenis_trans, string metode_pembayaran, string harga, string tanggal) {
	
	//create variable list baru
	Transaksi *baru;
	baru = new Transaksi;

	//mengisi variabel list
	baru->id_trans = id_trans;
	baru->jenis_trans = jenis_trans;
	baru->metode_pembayaran = metode_pembayaran;
	baru->harga = harga;
	baru->tanggal = tanggal;

	//menyambungkan data baru dg linked list yg sudah ada
	if (isEmpty() == 1)
		head = tail = baru;
	else {
		tail->next = baru;	//memindah tail ke data baru
		tail = baru;
	}
}

//untuk mengambil data dari file xml yg sudah dibaca oleh
void getXMLData(string filename) {
	OperationFile op;	//memanggil fungsi OperationFile
	Transaksi output;	
	string text = op.getFile(filename);	

	//inisiasi variabel
	int open = 0;
	int pos = 0;
	int close = 0;
	int start = 0;
	int index = 0;

	while (true) {
		index = text.find("<transaksi>", start);
		if (index > text.length())
			break;
		else {
			open = text.find("<id_trans>", start);
			close = text.find("</id_trans>", pos);
			string id_trans = text.substr(open + 10, close - open - 10);

			open = text.find("<jenis_trans>", start);
			close = text.find("</jenis_trans>", pos);
			string jenis_trans = text.substr(open + 13, close - open - 13);

			open = text.find("<metode_pembayaran>", start);
			close = text.find("</metode_pembayaran>", pos);
			string metode_pembayaran = text.substr(open + 19, close - open - 19);

			open = text.find("<harga>", start);
			close = text.find("</harga>", pos);
			string harga = text.substr(open + 7, close - open - 7);

			open = text.find("<tanggal>", start);
			close = text.find("</tanggal>", pos);
			string tanggal = text.substr(open + 9, close - open - 9);

			addLast(id_trans, jenis_trans, metode_pembayaran, harga, tanggal);

			start = close + 1;
			pos = close + 1;
		}
	}
}

//untuk menghitung jumlah transaksi 
int CountTransaksi(string filename) {
	OperationFile op;
	string text = op.getFile(filename);
	int index = 0; //inisiasi variabel
	int output = 0;
	int start = 0;
	while (true) {
		index = text.find("<transaksi>", start);

		if (index > text.length())
			break;
		else {
			output++;
			start = index + 1;
		}
	}
	return output;
}

//menampilkan data
void PrintList() {
	Transaksi *it = head; //membuat list baru

	while (it != NULL) {
		cout << it->id_trans << endl;
		cout << it->jenis_trans << endl;
		cout << it->metode_pembayaran << endl;
		cout << it->harga << endl;
		cout << it->tanggal << endl << endl;

		it = it->next;
	}
}

//untuk menghitung jumlah terbanyak dari metode pembayaran
void jenispalingbanyak() {
	print = head;	//mendeklarasikan head linkedlist sebagai variabel print
	int a = 0, ovocash = 0, ovopoint = 0, cash = 0; //inisiasi variabel
	if (head != NULL) { 
		while (print != NULL)
		{
			if (print->metode_pembayaran == "OVO Cash") ovocash++; 
			if (print->metode_pembayaran == "OVO Points") ovopoint++;
			if (print->metode_pembayaran == "Cash") cash++;
			print = print->next;
			a++;
			if (a == 50) print = NULL;
		}
	}
	if (ovocash > (ovopoint && cash)) {
		cout << "\nJenis Pembayaran paling sering digunakan adalah Dengan OVO Cash yaitu sebanyak " << ovocash << " kali" << endl;
	}
	else if (ovopoint > (ovocash && cash)) {
		cout << "\nJenis Pembayaran paling sering digunakan adalah Dengan OVO Point yaitu sebanyak " << ovopoint << " kali" << endl;
	}
	else cout << "\nJenis Pembayaran paling sering digunakan adalah Dengan Cash yaitu sebanyak " << cash << " kali" << endl;
}

//untuk menghitung nominal dari transaksi terbanyak
void nominalpalingbanyak() {
	print = head; //mendeklarasikan head linkedlist sebagai variabel print
	int a = 0, ovocash = 0, ovopoint = 0, cash = 0; //inisiasi variabel
	if (head != NULL) {
		while (print != NULL) //print akan bernilai NULL jika sudah mencapai tail linked list
		{
			if (print->metode_pembayaran == "OVO Cash") ovocash += stoi(print->harga);
			if (print->metode_pembayaran == "OVO Points") ovopoint += stoi(print->harga);
			if (print->metode_pembayaran == "Cash") cash += stoi(print->harga);
			print = print->next;
			a++;
			if (a == 50) print = NULL;
		}
	}
	if (ovocash > (ovopoint && cash)) {
		cout << "\nJenis Pembayaran dengan nominal terbanyak adalah Dengan OVO Cash yaitu sebanyak Rp" << ovocash << endl;
	}
	else if (ovopoint > (ovocash && cash)) {
		cout << "\nJenis Pembayaran dengan nominal terbanyak adalah Dengan OVO Point yaitu sebanyak Rp " << ovopoint << endl;
	}
	else cout << "\nJenis Pembayaran dengan nominal terbanyak adalah Dengan Cash yaitu sebanyak Rp " << cash << endl;
}

//untuk menghitung total biaya transaksi
void total() {
	print = head; //mendeklarasi head sebagai variabel print
	int a = 0, ovocash = 0, ovopoint = 0, cash = 0; //inisiasi variabel
	if (head != NULL) {	
		while (print != NULL) //print akan bernilai NULL jika sudah mencapai tail linked list
		{
			if (print->metode_pembayaran == "OVO Cash") ovocash += stoi(print->harga);
			if (print->metode_pembayaran == "OVO Points") ovopoint += stoi(print->harga);
			if (print->metode_pembayaran == "Cash") cash += stoi(print->harga);
			print = print->next;
			a++;
			if (a == 10) print = NULL;
		}
	}
	cout << "\nTotal pembayaran transaksi sebanyak Rp " << ovocash + ovopoint + cash << endl;
}

//untuk mengetahui total cashback
void cashback() {
	print = head; //mendeklarasikan head linkedlist sebagai variabel print
	int a = 0, pengembalian = 0; //inisiasi variabel
	if (head != NULL) {
		while (print != NULL) //print akan bernilai NULL jika sudah mencapai tail linked list
		{
			if (print->jenis_trans == "Pengembalian") pengembalian += stoi(print->harga);
			print = print->next;
			a++;
			if (a == 10) print = NULL;
		}
	}
	cout << "\nTotal cashback sebanyak Rp " << pengembalian << endl;
}

//untuk menghitung banyak transaksi dalam sehari
void banyaktransaksi(string waktu) {
	print = head; //mendeklarasikan head linkedlist sebagai variabel print
	int a = 0, transaksi = 0; //inisiasi variabel
	if (head != NULL) {
		while (print != NULL) //print akan bernilai NULL jika sudah mencapai tail linked list
		{
			if (print->tanggal == waktu)
			{
				cout << "Transaksi pada hari " << waktu << " adalah " << endl;
				cout << print->jenis_trans << endl;
				cout << print->metode_pembayaran << endl;
				cout << print->harga << endl;
				cout << print->tanggal << endl;
			}
			if (print->tanggal == "11 Sept 2019")
			transaksi++;
			print = print->next;
			a++;
			cout << endl;
			if (a == 50) print = NULL;
		}
	}
	cout << "\nTotal transaksi pada tanggal tersebut sebanyak " << transaksi << endl;
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
