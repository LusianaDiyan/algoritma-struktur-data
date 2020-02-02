#include <stdio.h>
#include <iostream>

// Maze size 
#define N 6 

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);

//menampilkan hasil/solusi dari sol[N][N]
void printSolution(int sol[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf(" %d ", sol[i][j]);
		printf("\n");
	}
}

// fungsi utk check jika x, y memiliki index yg valid utk N*N maze 
bool isSafe(int maze[N][N], int x, int y)
{
	// if (x, y outside maze) return false ```
	if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
		return true;

	return false;
}

bool solveMaze(int maze[N][N])
{
	//maze matrix
	int sol[N][N] = { { 0, 0, 0, 0, 0, 0 },
					  { 0, 0, 0, 0, 0, 0 },
					  { 0, 0, 0, 0, 0, 0 },
					  { 0, 0, 0, 0, 0, 0 },
					  { 0, 0, 0, 0, 0, 0 },
					  { 0, 0, 0, 0, 0, 0} };

	if (solveMazeUtil(maze, 0, 0, sol) == false) {
		printf("Solution doesn't exist\n");
		return false;
	}

	printSolution(sol);
	return true;
}

/* A recursive utility function to solve Maze problem */
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
	// jika (x, y = tujuan) return true 
	if (x == N - 1 && y == N - 1) {
		sol[x][y] = 1;
		return true;
	}

	// Check jika maze[x][y]  valid 
	if (isSafe(maze, x, y) == true) {
		// menandai x, y sbg bagian dari jalur solusi 
		sol[x][y] = 1;
		
		//maju ke arah x
		if (solveMazeUtil(maze, x + 1, y, sol) == true)
			return true;

		//jika pindah pd arah x tdk menemukan solusi maka mundur ke arah y
		if (solveMazeUtil(maze, x, y + 1, sol) == true)
			return true;

		//jika kondisi diatas tidak terpenuhi maka backtrack dg menandai x, y sbg bagian dari solusi jalan
		//BACKTRACK
		sol[x][y] = 0;
		return false;
	}

	return false;
}

// menjalankan fungsi diatas
int main()
{
	//maze problem
	int maze[N][N] = { { 1, 1, 0, 0, 0, 1 },
					   { 1, 1, 1, 1, 1, 0 },
					   { 0, 0, 1, 0, 1, 1 },
					   { 0, 1, 1, 1, 1, 1 },
					   { 0, 1, 0, 0, 1, 1 },
					   { 1, 1, 1, 1, 1, 1 } };

	solveMaze(maze);
	system("pause");
}