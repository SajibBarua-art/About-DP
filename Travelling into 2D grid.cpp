/* Q: There is a 2D grid. 
 * You begin in the top-left corner and your goal is to travel to the bottom-right corner. 
 * How many ways can fulfill this task? */
#include<iostream>
using namespace std;

long long grid_traveler(long long row, long long col, long long path_cnt[][25]) {
	if(row == 0 || col == 0) return 0;
	if(row == 1 && col == 1) return 1;
	// memoization
	if(path_cnt[row][col] != -1) return path_cnt[row][col];
	
	path_cnt[row][col] = grid_traveler(row-1, col, path_cnt) + grid_traveler(row, col-1, path_cnt);
	
	// grig_traveler(n, m) = grid_traveler(m, n)
	// that's why when we find grid_traveler(n, m) then we update the grid_traveler(m, n) with it.
	// it's help to perform memoization
	path_cnt[col][row] = path_cnt[row][col];
	
	return path_cnt[row][col];
}

int main() {
	int t; cin >> t;
	long long path_cnt[25][25];
	for(int i=0; i<=20; i++)
		for(int r=0; r<=20; r++)
			path_cnt[i][r] = -1;
			
	grid_traveler(20, 20, path_cnt);
	
	while(t--) {
		int row, col; cin >> row >> col;
		cout << path_cnt[row][col] << endl;
	}
}
