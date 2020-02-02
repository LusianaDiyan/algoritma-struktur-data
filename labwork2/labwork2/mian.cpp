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
//#include <libxml/parser.h>


using namespace std;
/*
struct transaksi {
	char *id;
	char *jenis_transaksi;
	char *metode_pembayaran;
	int *harga;
	char *tanggal;
};
*/
int main() {
	string id, jenis_trans, metode_pembayaran, tgl;
	string harga;
	string lokasi = "D:\\ASDAT\\transaksi.xml";
	printf_s("Masukkan ID : ");
	cin >> id;
	printf_s("Masukkan Jenis Transaksi(Pembayaran/Penerimaan/Pengembalian) : ");
	cin >> jenis_trans;
	printf_s("Masukkan Metode Pembayaran (Cash/Ovo) : ");
	cin >> metode_pembayaran;
	printf_s("Masukkan Harga : ");
	cin >> harga;
	printf_s("Masukkan tanggal(dd-mm-yyyy) : ");
	cin >> tgl;

	OperationFile op;
	string file = op.getFile(lokasi);

	op.WriteToFile(lokasi, "\t<transaksi>\n\t\t<id_trans>" + id + "</id_trans>\n\t\t<jenis_trans>" + jenis_trans + "</jenis_trans>\n\t\t<metode_pembayaran>" + metode_pembayaran + "</metode_pembayaran>\n\t\t<harga>" + harga + "</harga>\n\t\t<tanggal>" + id + "</tanggal>\n\t</transaksi>");

	op.printToScreen("D:\\ASDAT\\transaksi.xml");
	
	system("pause");
}