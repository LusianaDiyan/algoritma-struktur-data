// Labwork1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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


using namespace std;
string metode_pembayaran, tanggal, bulan, tahun;
string jum_pembayaran;
string pukul;
bool kondisi = true;
int i;
/*int main() {

	//OperationFile op;
	OperationFile gas;
	//op.printToScreen("D:\\OneDrive\\Kuliah\\Algoritma dan Struktur Data\\project\\Labwork1\\Labwork1\\dea2.xml");
	//gas.printToScreen("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\test-2.xml");
	//op.OverwriteToFile("dea2.xml", "");
	//gas.OverwriteToFile("test-2.xml", "");
	//op.WriteToFile("dea2.xml", "abc");
	//cout << "Masukkan data mahasiswa";
	string nama, nrp;
	cout << "\nMasukkan nama : ";
	getline(cin, nama);
	cout << "Masukkan NRP : ";
	getline(cin, nrp);
	//gas.WriteToFile("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\test-3.xml","<Mahasiswa>");
	gas.WriteToFile("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\test-3.xml", "<Mahasiswa>\n\t<Nama>" +nama+ "</nama>\n\t<nrp>"+nrp+"</nrp>\n<\Mahasiswa>");
	//op.printToScreen("dea2.xml");
	gas.printToScreen("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\test-3.xml");
	gas.printXMLToScreen("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\test-3.xml","Mahasiswa");
	//char oldname[] = "D:\\OneDrive\\Kuliah\\Algoritma dan Struktur Data\\project\\Labwork1\\Labwork1\\dea.xml";
	//char oldname[] = "E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\test.xml";
	//char newname[] = "D:\\OneDrive\\Kuliah\\Algoritma dan Struktur Data\\project\\Labwork1\\Labwork1\\dea2.xml";
	//char newname[] = "E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\test-2.xml";
	//op.OverwriteToFile("dea.xml", "say hi to me");
	//gas.OverwriteToFile("test.xml", "Halo");
	//op.moveFile(oldname, newname);
	//gas.moveFile(oldname, newname);
	//~OperationFile;



	cout << "Masukkan elemen : ";
		getline(cin, jenis[i]);
		cout << "Apakah ada sub elemen : ";
		getline(cin, subelemen[i]);
		if (konfirmasi == "Y" || konfirmasi == "y") {

		}
		cout << "Masukkan isi : ";
		getline(cin, elemen[i]);
		gas.WriteToFile("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\LabWork2.xml", "\t<" + jenis[i] + ">" + elemen[i] + "</" + jenis[i] + ">");
		cout << "Apakah ada data lagi?";
		getline(cin, konfirmasi);
		if (konfirmasi == "Y" || konfirmasi == "y") {
			i++;
		}
		else {
			kondisi = false;
		}
}
*/
void baca() {
	OperationFile gas;
	gas.printToScreen("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\LabWork2.xml");
	kondisi = false;
}
void pembayaran() {
	char choice;
	OperationFile gas;
	cout << "Jumlah pembayaran : ";
	//getline(cin, jum_pembayaran);
	cin >> jum_pembayaran;
	cout << "Metode Pembayaran : ";
	//getline(cin, metode_pembayaran);
	cin >> metode_pembayaran;
	cout << "Masukkan tanggal : ";
	cin >> tanggal;
	cout << "Masukkan Bulan : ";
	cin >> bulan;
	cout << "Masukkan Tahun : ";
	cin >> tahun;
	cout << "Masukkan Jam : ";
	cin >> pukul;
	gas.WriteToFile("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\LabWork2.xml", "<\tPembayaran>");
	gas.WriteToFile("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\LabWork2.xml", "\t<Jumlah Pembayaran>" + jum_pembayaran + "</Jumlah Pembayaran>");
	gas.WriteToFile("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\LabWork2.xml", "\t<Metode Pembayaran>" + metode_pembayaran + "</Metode Pembayaran>");
	gas.WriteToFile("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\LabWork2.xml", "\t<Date>");
	gas.WriteToFile("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\LabWork2.xml", "\t\t<Tanggal>" + tanggal + "</Tanggal>");
	gas.WriteToFile("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\LabWork2.xml", "\t\t<Bulan>" + bulan + "</Bulan>");
	gas.WriteToFile("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\LabWork2.xml", "\t\t<Tahun>" + tahun + "</Tahun>");
	gas.WriteToFile("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\LabWork2.xml", "\t\t<Jam>" + pukul + "</Jam>");
	gas.WriteToFile("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\LabWork2.xml", "\t<Pembayaran>");
	cout << "Apakah ada input lagi ? [Y/N] ";
	cin >> choice;
	if (choice == 'N' || choice == 'n') {
		kondisi = false;
	}
}

void cashback() {
	OperationFile gas;
	char choice;
	cout << "Jumlah pembayaran : ";
	cin >> jum_pembayaran;
	cout << "Metode Pembayaran : ";
	cin >> metode_pembayaran;
	cout << "Masukkan tanggal : ";
	cin >> tanggal;
	cout << "Masukkan Bulan : ";
	cin >> bulan;
	cout << "Masukkan Tahun : ";
	cin >> tahun;
	cout << "Masukkan Jam : ";
	cin >> pukul;
	gas.WriteToFile("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\LabWork2.xml", "<\tcashback>");
	gas.WriteToFile("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\LabWork2.xml", "\t<Jumlah Pembayaran>" +(string)jum_pembayaran + "</Jumlah Pembayaran>");
	gas.WriteToFile("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\LabWork2.xml", "\t<Metode Pembayaran>" + metode_pembayaran + "</Metode Pembayaran>");
	gas.WriteToFile("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\LabWork2.xml", "\t<Date>");
		gas.WriteToFile("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\LabWork2.xml", "\t\t<Tanggal>" + tanggal + "</Tanggal>");
		gas.WriteToFile("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\LabWork2.xml", "\t\t<Bulan>" + bulan + "</Bulan>");
		gas.WriteToFile("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\LabWork2.xml", "\t\t<Tahun>" + tahun + "</Tahun>");
		gas.WriteToFile("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\LabWork2.xml", "\t\t<Jam>" + pukul + "</Jam>");
	gas.WriteToFile("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\LabWork2.xml", "\t<Date>");
	cout << "Apakah ada input lagi ? [Y/N] ";
	cin >> choice;
	if (choice == 'N' || choice == 'n') {
		kondisi = false;
	}
}

int main() {
	OperationFile gas;
	int pilihan;
	gas.WriteToFile("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\LabWork2.xml", "<Tokopedia>");
	while (kondisi)
	{
		cout << "Masukkan jenis pembayaran : \n1. Pembayaran\n2.Cashback\n3. Baca file XML : ";
		cin >> pilihan;
		if (pilihan == 1) {
			pembayaran();
		}
		else if (pilihan == 2) {
			cashback();
		}
		else if (pilihan == 3) {
			baca();
		}
		else {
			cout << "Maaf masukkan anda tidak ditemukan";
		}
	}
	gas.WriteToFile("E:\\Kuliah\\Tugas\\Algoritma & Struktur Data\\LabWork2.xml", "</Tokopedia>");
}