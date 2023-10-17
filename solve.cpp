#include <iostream>
using namespace std;

bool isSafe(int grid[9][9], int row, int col, int num) {
	// Check if num exists in current row
	for (int i = 0; i < 9; i++) {
		if (grid[row][i] == num) {
			return false;
		}
	}

	// Check if num exists in current column
	for (int i = 0; i < 9; i++) {
		if (grid[i][col] == num) {
			return false;
		}
	}

	// Check if num exists in current 3x3 subgrid
	int startRow = row - row % 3;
	int startCol = col - col % 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid[i + startRow][j + startCol] == num) {
				return false;
			}
		}
	}

	return true;
}

bool findUnassignedLocation(int grid[9][9], int& row, int& col) {
	for (row = 0; row < 9; row++) {
		for (col = 0; col < 9; col++) {
			if (grid[row][col] == 0) {
				return true;
			}
		}
	}
	return false;
}

bool solveSudoku(int grid[9][9]) {
	int row, col;

	if (!findUnassignedLocation(grid, row, col)) {
		return true;
	}

	for (int num = 1; num <= 9; num++) {
		if (isSafe(grid, row, col, num)) {
			grid[row][col] = num;

			if (solveSudoku(grid)) {
				return true;
			}

			grid[row][col] = 0;
		}
	}

	return false;
}

void displayGrid(int grid[9][9]) {
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			cout << grid[row][col] << " ";
		}
		cout << endl;
	}
}

int main() {
	int grid[9][9];

	cout << "Enter the Sudoku grid (9x9):" << endl;
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			cin >> grid[row][col];
		}
	}

	if (solveSudoku(grid)) {
		cout << "Solution:" << endl;
		displayGrid(grid);
	} else {
		cout << "No solution exists." << endl;
	}

	return 0;
}