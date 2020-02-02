#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
int main()
{
	ifstream in_file;
	in_file.open("data matriks sisi.txt");
	int n_sisi, n_titik;
	in_file >> n_sisi >> n_titik;
	int matriks_sisi[n_sisi][4], matriks_sisiAsli[n_sisi][4];
	
	for (int i = 0; i < n_sisi; i++)
	{
		for (int j = 0; j <= 3; j++)
			in_file >> matriks_sisi[i][j];
	}
	
	for (int i = 0; i < n_sisi; i++)
	{
		for (int j = 0; j <= 3; j++)
			cout << matriks_sisi[i][j] << " ";
			cout << endl;
	}
	
	for (int i = 1; i <= n_sisi; i++)
	{
		matriks_sisiAsli[i - 1][0] = matriks_sisi[i - 1][0];
		matriks_sisiAsli[i - 1][1] = matriks_sisi[i - 1][1];
		matriks_sisiAsli[i - 1][2] = matriks_sisi[i - 1][2];
		matriks_sisiAsli[i - 1][3] = matriks_sisi[i - 1][3];
	}
	system("CLS");
	
	int banyak_TKemacetan;
	cout << "Melalui penelitian yang dilakukan, titik kemacetan sebanyak : ";
	cin >> banyak_TKemacetan;
	system("CLS");
	
	int titikKemacetan[banyak_TKemacetan];

	cout << "Input titik - titik kemacetan : ";
	for (int i = 1; i <= banyak_TKemacetan; i++)
		cin >> titikKemacetan[i - 1];
	system("CLS");
	
	//Input titik sumber
	int titik_sumber;
	cout << "Input titik sumber : ";
	cin >> titik_sumber;
	system("CLS");
	int titik_Tujuan;
	cout << "Input titik yang ingin dicari lintasan terpendeknya : ";
	cin >> titik_Tujuan;
	system("PAUSE");
	system("CLS");
	
	//DEKLARASI VARIABEL TOTAL LINTASAN TERPENDEK
	int Ltp[n_titik];
	
	//DEKLARASI VARIABEL TITIK YANG SUDAH DIJADIKAN TITIK TINJAU DAN DEKLARASI VARIABEL TITIK TERDEKAT KE SEBUAH TIITK 
	int titik_terminal[n_titik], titik_terdekat[n_titik];
	
	//DEKLARASI VARIABEL INDEKS TITIK_TERMINAL
	int indeks_arrayTerminal;
	
	//DEKLARASI VARIABEL TITIK TINJAU YANG MENYIMPAN NILAI TITIK TINJAU DI SETIAP TAHAP 
		int titik_tinjau;
	
		//variabel macet_terhindarkan digunakan sebagai acuan
	//apakah titik kemacetan dapat dihindari (bernilai 1) atau tidak (0)
	int macet_terhindarkan = 1;
ulang:
	if (macet_terhindarkan == 0)
	{
		for (int i = 1; i <= n_sisi; i++)
		{
			matriks_sisi[i - 1][0] = matriks_sisiAsli[i - 1][0];
			matriks_sisi[i - 1][1] = matriks_sisiAsli[i - 1][1];
			matriks_sisi[i - 1][2] = matriks_sisiAsli[i - 1][2];
			matriks_sisi[i - 1][3] = matriks_sisiAsli[i - 1][3];
		}
	}
	for (int i = 1; i <= n_titik; i++)
	{
		if (i - 1 == titik_sumber - 1)
			Ltp[i - 1] = 0;
		else
			Ltp[i - 1] = 9999;
	}
	
	//INISIALISASI NILAI AWAL VARIABEL TITIK TERMINAL DAN TITIK TERDEKAT
		for (int i = 0; i < n_titik; i++)
			titik_terminal[i] = 0, titik_terdekat[i] = 0;
	
	//INISIALISASI NILAI AWAL VARIABEL TITIK TINJAU DAN INDEKSNYA
		titik_tinjau = titik_sumber;
		indeks_arrayTerminal = 0;
	
		for (int stop_Dijkstra = 0; stop_Dijkstra < n_titik; stop_Dijkstra++)
		{
			titik_terminal[indeks_arrayTerminal++] = titik_tinjau;
			//PERULANGAN INI UNTUK MENCARI SETIAP TITIK YANG ADJACENT DENGAN TITIK TINJAU DAN
			//MENYIMPAN NILAI TITIK TERDEKAT, LINTASAN TERPENDEKNYA 
			for (int i = 0; i < n_sisi; i++)
			{
				int bobot_sisi;
				if (matriks_sisi[i][3] == 0)
				{
					//program ini mencari titik tinjau di kolom 1st matriks sisi
					if (matriks_sisi[i][0] == titik_tinjau)
					{
						int titik_adjacent = matriks_sisi[i][1];
						bobot_sisi = matriks_sisi[i][2];
						if (Ltp[titik_adjacent - 1] > Ltp[titik_tinjau - 1] + bobot_sisi)
						{
							Ltp[titik_adjacent - 1] = Ltp[titik_tinjau - 1] + bobot_sisi;
							titik_terdekat[titik_adjacent - 1] = titik_tinjau;
						}
					}
					//program ini mencari titik tinjau di kolom 2nd matriks sisi
					if (matriks_sisi[i][1] == titik_tinjau)
					{
						int titik_adjacent = matriks_sisi[i][0];
						bobot_sisi = matriks_sisi[i][2];
						if (Ltp[titik_adjacent - 1] > Ltp[titik_tinjau - 1] + bobot_sisi)
						{
							Ltp[titik_adjacent - 1] = Ltp[titik_tinjau - 1] + bobot_sisi;
							titik_terdekat[titik_adjacent - 1] = titik_tinjau;
						}
					}
				}
				else if (matriks_sisi[i][3] == 1)
				{
					//program ini mencari titik tinjau di kolom 1st matriks sisi
					if (matriks_sisi[i][0] == titik_tinjau)
					{
						int titik_adjacent = matriks_sisi[i][1];
						bobot_sisi = matriks_sisi[i][2];
						if (Ltp[titik_adjacent - 1] > Ltp[titik_tinjau - 1] + bobot_sisi)
						{
							Ltp[titik_adjacent - 1] = Ltp[titik_tinjau - 1] + bobot_sisi;
							titik_terdekat[titik_adjacent - 1] = titik_tinjau;
						}
					}
				}
			}
		
/*untuk menentukan titik tinjau berikutnya, program ini merujuk ke array
titik_terminal dan array lintasan terpendek
idenya adalah :
1. meninjau titik yang belum terlist di array titik terminal,
2. jika ada, maka nilai lintasan terpendek titik tersebut (yang terdapat pada
array lintasan terpendek)
dijadikan nilai lintasan terpendek sementara,
3. nilai lintasan terpendek sementara tersebut dibandingkan dengan nilai
lintasan terpendek lainnya (yang terdapat pada
array lintasan terpendek),
4. dihasilkan lintasan terpendek terkecil (dalam array lintasan terpendek)
5. titik yang menjadi perhentian dari lintasan terpendek tersebut (titik inisial)
dijadikan sebagai titik
terminal selanjutnya/titik tinjau selanjutnya*/

		int lintasan_terpendek = 9999, titik_terminalSelanjutnya;
		for (int i = 1; i <= n_titik; i++)
		{ //variabel tinjau_titikTerminal merupakan variabel yang menunjukkan
			//apakah titik tersebut ada atau tidak di array titik terminal
				//lintasan terpendekN merupakan variabel lintasan terpendek sementara,
				//yang harus dibandingkan dengan nilai lintasan terpendek lain, hingga didapatkan nilai lintasan terpendek 
			final int tinjau_titikTerminal = 0;
			for (int j = 0; j < n_titik; j++)
				if (titik_terminal[j] == i)
					tinjau_titikTerminal = 1;
			if (tinjau_titikTerminal != 1)
				if (lintasan_terpendek > Ltp[i - 1])
					lintasan_terpendek = Ltp[i - 1], titik_terminalSelanjutnya = i;
		}
		titik_tinjau = titik_terminalSelanjutnya;
	}
	//PROGRAM MENGURUTKAN LINTASAN DARI TITIK SUMBER KE TITIK TUJUAN 
	int titik, titikSort[150], i = 0;
	titik = titik_Tujuan;
	int banyakTitikDilalui = 0;
	if (Ltp[titik_Tujuan - 1] != 9999)
	{
		while (titik != 0)
		{
			titikSort[i++] = titik;
			titik = titik_terdekat[titik - 1];
			banyakTitikDilalui++;
		}
		int temp1 = 0, temp2 = banyakTitikDilalui - 1, temp3;
		while (temp1 < banyakTitikDilalui / 2)
		{
			temp3 = titikSort[temp1];
			titikSort[temp1++] = titikSort[temp2];
			titikSort[temp2] = temp3;
			temp2--;
		}
		//MENAMPILKAN LINTASAN DARI TITIK SUMBER MENUJU TITIK TUJUAN
		cout << "Rute efektif menuju titik " << titik_Tujuan;
		cout << " adalah sebagai berikut : \n";
		for (int i = 0; i < banyakTitikDilalui; i++)
		{
			cout << titikSort[i];
			if (i != banyakTitikDilalui - 1)
				cout << " - ";
		}
		cout << endl;
		cout << "\bPanjang rute tersebut adalah sejauh " << Ltp[titik_Tujuan - 1];
		cout << " m";
	}
	else
	{
		cout << "Jika kemacetan dihindari maka, tidak terdapat rute menuju titik tujuan";
		cout << endl;
		cout << "(titik kemacetan harus dilalui untuk sampai ke tujuan). ";
		cout << endl;
		cout << "\nGraf yang dijadikan sebagai solusi akhir adalah graf Dijkstra,";
		cout << "dimana walaupun ";
		cout << "\nmasih memiliki titik kemacetan,";
		cout << " namun memiliki lintasan terpendek dari \nyang lainnya." << endl;
		cout << endl;
		system("PAUSE");
		system("CLS");
	}
	if (Ltp[titik_Tujuan - 1] != 9999 && macet_terhindarkan == 1)
	{
		for (int i = 0; i < banyakTitikDilalui; i++)
		{
			for (int j = 0; j < banyak_TKemacetan; j++)
			{
				int temp;
				if (titikSort[i] == titikKemacetan[j])
				{
					cout << ", namun dalam rute ini terdapat titik kemacetan yaitu titik ";
					for (int i = 0; i < banyakTitikDilalui; i++)
					{
						for (int j = 0; j < banyak_TKemacetan; j++)
							if (titikSort[i] == titikKemacetan[j])
								cout << titikKemacetan[j] << " ";
					}
					cout << "\b." << endl;
					cout << endl;
					system("PAUSE");
					system("CLS");
					for (int k = 0; k < n_sisi; k++)
					{
						if (matriks_sisi[k][0] == titikKemacetan[j])
							matriks_sisi[k][3] = -1;
						else if (matriks_sisi[k][1] == titikKemacetan[j])
							matriks_sisi[k][3] = -1;
					}
					goto ulang;
				}
			}
		}
	}
	else if (Ltp[titik_Tujuan - 1] == 9999 && macet_terhindarkan == 1)
	{
		macet_terhindarkan = 0;
		goto ulang;
	}
	int banyak_Kemacetan = 0;
	for (int i = 0; i < banyakTitikDilalui; i++)
	{
		for (int j = 0; j < banyak_TKemacetan; j++)
		{
			if (titikSort[i] == titikKemacetan[j])
				banyak_Kemacetan += 1;
		}
	}
	if (banyak_Kemacetan == 0)
	{
		cout << ".\n\nTidak terdapat titik kemacetan pada rute ini, sehingga merupakan rute terpendek ";
		cout << "dan berhasil menghindari titik-titik kemacetan." << endl;
		cout << endl;
	}
	else
		cout << ".\nBanyak titik kemacetan dalam rute ini sebanyak " << banyak_Kemacetan << endl;
	cout << endl
		cout << "Array Panjang Lintasan Terpendek : \n";
	for (int m = 0; m < n_titik; m++)
		cout << Ltp[m] << " ";
	return 0;
}