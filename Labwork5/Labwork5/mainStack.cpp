#include <string>
#include <string.h>
#include <cstdio>
#include <iostream>
#include "main.h"

const int maxstack = 36;

using namespace std;

struct MazeStack
{
	int count; //menghitung jumlah elemen di dalam stack
	int X, Y, down, left, right;
	int data[maxstack]; //menunjukkan array yang digunakan utk menyimpan data
};

//untuk mengatur stack agar kosong
void Initialize(MazeStack* S) {
	S->count = 0; //stack belum terisi
}

//mengecek apakah stack penuh
int isFull(MazeStack *S) { 
	return (S->count == maxstack) ? 1 : 0; //mengembalikan nilai 1 jika nilai variabel count = maxstack
}

//mengecek apakah stack kosong
int isEmpty(MazeStack *S) { 
	return (S->count == 0) ? 1 : 0; //mengembalikan nilai 1 jika count = 0
}

//menambahkan elemen baru ke stack
void Push(int x, MazeStack *S) { 
	if (isFull(S) == 1) //mebgecek apakah stack penuh
		cout << "Maaf stack penuh" << endl; 
	else { S->data[S->count] = x; 
		++S->count; //elemen akan ditambahkan ke dala stack dan count +1
	} 
}

//mengambil elemen paling atas dari stack
int Pop(MazeStack *S) { 
	if (isEmpty(S) == 1) { // jika stack kosong
		cout << "Maaf stack masih kosong" << endl;
	} else {
		--S->count; //stack tidak kosong, mengurangi count dan mengembalikan nilai elemen teratas
		return (S->data[S->count]); 
	} 
}

void main() {
	MazeStack *M;
	M = new MazeStack();
	Initialize(M);
	M->X=0;
	M->Y = 0;

	int cek = Pop(M);

	system("pause");
}