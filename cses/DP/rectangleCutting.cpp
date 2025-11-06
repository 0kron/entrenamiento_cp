// Given an a X b rectangle, your task is to cut it into squares.
// On each move you can select a rectangle and cut it into two rectangles
// in such a way that all side lengths remain integers.
// What is the minimum possible number of moves?
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int main() {
	// Read input
	int rows, columns;
	cin >> rows >> columns;
	if (rows > columns)
		swap(rows, columns); // We will consider the rectangles vertical

	// Build the dp table
	// rows * columns grid, each element is initialized to 1 billion
	vector<vector<int>> grid(rows, vector<int>(columns, INF));

	for (int row = 0; row < rows; row++){
		for (int col = 0; col < columns; col++){
			if (row > col)
				// We always compute first the col, row. As we are iterating over the columns first
				grid[row][col] = grid[col][row];
			else if (row == col)
				grid[row][col] = 0; // already zero
			else {
				// we make horizontal cuts
				for (int i = 0; i < row; i++){
					int cut = 1 + grid[i][col] + grid[row - i - 1][col];
					grid[row][col] = min(grid[row][col], cut);
				}
				// we make vertical cuts
				for (int i = 0; i < col; i++){
					int cut = 1 + grid[row][i] + grid[row][col - i - 1];
					grid[row][col] = min(grid[row][col], cut);
				}

			}
		}
	}
	cout << grid[rows-1][columns-1]<< endl;
	return 0;
}


