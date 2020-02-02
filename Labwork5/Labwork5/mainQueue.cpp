#include <iostream>

const int maxqueue = 36;

using namespace std;

struct Queue { 
	int count; //utk menghitung jumlah elemen dlm queue
	int head; //menunjuk elemen paling depan
	int tail; //menunjuk elemen paling belakang
	int data[maxqueue]; //array yg utk menyimpan info dari queue
};

//utk mengatur queue dlm keadaan kosong
void Initialize(Queue* Q) { 
	Q->count = 0; 
	Q->tail = 0; 
	Q->head = 0; 
}

//mengecek queue dlm kondisi penuh
int isFull(Queue *Q) { 
	return (Q->count == maxqueue) ? 1 : 0; //mengembalikan nilai 1 jika count = maxqueue
}

//mengecek queue dlm kondisi kosong
int isEmpty(Queue *Q) { 
	return (Q->count == 0) ? 1 : 0; 
}

//menambahkan elemen baru ke queue
void Enqueue(int x, Queue *Q) { 
	if (isFull(Q) == 1) //mengecek kondisi queue penuh
		cout << "Maaf queue penuh" << endl; 
	else { 
		Q->data[Q->tail] = x; 
		Q->tail = (Q->tail + 1) % maxqueue; 
		++Q->count; 
	} 
}

//mengambil elemen dari queue
int Dequeue(Queue *Q) { 
	int temp = 0; 
	if (isEmpty(Q) == 1) {
		cout << "Maaf queue masih kosong" << endl;
	} else {
		temp = Q->data[Q->head];
		Q->head = (Q->head + 1) % maxqueue; 
		--Q->count; 
		return (temp); 
	} 
}

int main() {
	Queue *Q;
	Q = new Queue();
	Initialize(Q);
	Q->head = 0;
	Q->tail = 0;

	int cek = Dequeue(Q);

	system("pause");
}