#include<iostream>
using namespace std;

int main() {
	cout << "Enter the row and coloumn numbers: ";
	int row, col; cin >> row >> col;
	
	long long grid[row+1][col+1]={};
	grid[1][1] = 1;
	for(int r=1; r<=row; r++) {
		for(int c=1; c<=col; c++) {
			if(r+1<=row) grid[r+1][c] += grid[r][c];
			if(c+1<=col) grid[r][c+1] += grid[r][c];
		}
	}
	cout << "Total ways are: " << grid[row][col] << endl;
}
