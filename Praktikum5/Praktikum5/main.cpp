#include <stdio.h>
#include <string>
#include <windows.h>
#include <iostream>
#include <stack>//library untuk operasi stack
#include <queue> //library untuk operasi queue
using namespace std;

struct peta { //inisiasi peta 
	int peta[7][7]; //inisiasi peta, dilebihkan 1 untuk NULL
	stack<int> atribut; //inisiasi stack
	stack<int> posX;
	stack<int> posY;
	queue<int> atribute; //inisiasi queue
};

int track[7][7];

void movRat() {
	//inisiasi karakter tiap node dalam peta
	//0 = bawah, 1 = atas, 2 = kiri, 3 = kanan
	//4 = atas kiri, 5 = bawah kiri, 6 = bawah kanan, 7 = atas kiri
	//8 = halangan
	peta *init;
	bool failed = false;
	init = new peta;
	init->peta[0][0] = 0;
	init->peta[0][1] = 8;
	init->peta[0][2] = 4;
	init->peta[0][3] = 4;
	init->peta[0][4] = 0;
	init->peta[0][5] = 8;

	init->peta[1][0] = 6;
	init->peta[1][1] = 6;
	init->peta[1][2] = 6;
	init->peta[1][3] = 4;
	init->peta[1][4] = 6;
	init->peta[1][5] = 0;

	init->peta[2][0] = 0;
	init->peta[2][1] = 8;
	init->peta[2][2] = 0;
	init->peta[2][3] = 6;
	init->peta[2][4] = 4;
	init->peta[2][5] = 8;

	init->peta[3][0] = 5;
	init->peta[3][1] = 5;
	init->peta[3][2] = 5;
	init->peta[3][3] = 6;
	init->peta[3][4] = 6;
	init->peta[3][5] = 0;

	init->peta[4][0] = 0;
	init->peta[4][1] = 7;
	init->peta[4][2] = 6;
	init->peta[4][3] = 7;
	init->peta[4][4] = 7;
	init->peta[4][5] = 5;

	init->peta[5][0] = 7;
	init->peta[5][1] = 5;
	init->peta[5][2] = 6;
	init->peta[5][3] = 6;
	init->peta[5][4] = 6;
	init->peta[5][5] = 9;

	int ratX = 0, ratY = 0;
	int borderX = 0, borderY = 0;
	int finishX = 5, finishY = 5;
	while (failed != true) {
		if ((ratX >= 0 && ratY >= 0) && (ratX < 6 && ratY < 6)) {
			if (init->peta[ratY][ratX] == 0) { //going down
				ratY++;
			}
			else if (init->peta[ratY][ratX] == 1) { //going up
				ratY--;
			}
			else if (init->peta[ratY][ratX] == 2) { //going left
				ratX--;
			}
			else if (init->peta[ratY][ratX] == 3) { //going right
				ratX++;
			}
			else if (init->peta[ratY][ratX] == 4) { //going up left
				ratY--;
				if (init->peta[ratY][ratX] == 8) { //stopped
					ratY++;
					init->peta[ratY][ratX] = 2; //going left
				}
			}
			else if (init->peta[ratY][ratX] == 5) { //going down left
				ratY++;
				if (init->peta[ratY][ratX] == 8) { //stopped
					ratY--;
					init->peta[ratY][ratX] = 2; //going left
				}
			}
			else if (init->peta[ratY][ratX] == 6) { //going down right
				ratX++;
				if (init->peta[ratY][ratX] == 8) { //stopped
					ratX--;
					init->peta[ratY][ratX] = 0; //going down
				}
			}
			else if (init->peta[ratY][ratX] == 7) { //going up left
				ratX--;
				if (init->peta[ratY][ratX] == 8) { //stopped
					ratX++;
					init->peta[ratY][ratX] = 1; //going up
				}
			}
			else if (ratX == finishX && ratY == finishY) {
				failed = false;
			}
		}
		else {
			if (ratX < 0)ratX++;
			if (ratX > 5)ratX--;
			if (ratY > 0)ratY--;
			if (ratY < 0)ratY++;
		}
		cout << "Koordinat mouse = " << ratX << " " << ratY << endl;
		Sleep(1000);

	}

	cout << "Mouse mencapai finish";
}

void printsolution()
{
	int i, j;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			printf("%d\t", track[i][j]);
		}
		printf("\n\n");
	}
}

int solvemaze(int r, int c) {
	if ((r == 6) && (c == 6)) {
		track[r][c] = 1;
		return 1;
	}

	if (r >= 0 && c >= 0 && r < 7 && c < 7 && track[r][c] == 0 && movRat[r][c] == 0)
	{
		//if safe to visit then visit the cell
		track[r][c] = 1;
		//going down
		if (solvemaze(r + 1, c))
			return 1;
		//going right
		if (solvemaze(r, c + 1))
			return 1;
		//going up
		if (solvemaze(r - 1, c))
			return 1;
		//going left
		if (solvemaze(r, c - 1))
			return 1;
		//backtracking
		track[r][c] = 0;
		return 0;
	}
	return 0;

}

void Queue() {
	peta* init;
	init = new peta; //memori dinamis untuk pembuatan queue
	system("cls");
	int input;
	cout << "Masukkan input : " << endl;
	for (int i = 0; i <= 3; i++) {
		cin >> input;
		init->atribute.push(input); //push ke dalam queue
	}
	cout << "Output : " << init->atribute.front() << endl; //cetak elemen terdepan
	movRat();
}

void Stack() {
	//memori dinamis untuk pembuatan queue
	peta* init;
	init = new peta;
	system("cls");
	int input;
	cout << "Masukkan input : " << endl;
	for (int i = 0; i <= 3; i++) {
		cin >> input;
		init->atribut.push(input); //push ke dalam stack
	}
	cout << "Output : " << init->atribut.top(); //cetak elemen teratas

	//movRat();

}


void main() {
	peta init;
	int pilihan;
	cout << "======================" << endl;
	cout << "Pilih Cara Penyelesaian Maze Solver" << endl;
	cout << "======================" << endl;
	cout << "1. Stack" << endl << "2. Queue" << endl;
	cin >> pilihan;
	switch (pilihan)
	{
	case 1:
		Stack();
		break;
	case 2:
		Queue();
		break;
	default:
		cout << "Masukkan anda kurang benar";
		break;
	}

	int i, j;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			track[i][j] = 0;
		}
	}
	if (solvemaze(0, 0))
		printsolution();
	else
		printf("No solution\n");
	system("pause");
}
