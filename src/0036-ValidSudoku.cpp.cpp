/*

	LC 36 Valid Sudoku

	Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

	Each row must contain the digits 1-9 without repetition.
	Each column must contain the digits 1-9 without repetition.
	Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Could be done with sets, to detect the duplicates
Maybe less code, but less efficient

*/


#include <iostream>
#include <vector>
#include <map>
#include <string>

#include <boost/algorithm/algorithm.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/lexical_cast.hpp>

bool isValidSudoku(std::vector<std::vector<char>>& board);



static bool check(std::vector<std::vector<char>>& board, int r, int c, int R, int C)
{
	char test[10] = "000000000";

	for (int i = r; i < r + R; i++)
	{
		for (int j = c; j < c + C; j++)
		{
			if (isdigit(board[i][j]))
			{
				if (test[board[i][j] - '1'] != '0')
					return false;

				test[board[i][j] - '1'] = board[i][j];
			}
		}
	}

	return true;
}

bool isValidSudoku(std::vector<std::vector<char>>& board)
{
	for (int i = 0; i < 9; i++)
	{
		if (!check(board, i, 0, 1, 9))
			return false;
		else
			printf("Row %d: Ok\n", i);

		if (!check(board, 0, i, 9, 1))
			return false;
		else
			printf("Col %d: Ok\n", i);
	}

	for (int r = 0; r < 9; r += 3)
	{
		for (int c = 0; c < 9; c += 3)
		{
			if (!check(board, r, c, 3, 3))
				return false;
			else
				printf("Square %d,%d: Ok\n", r, c);

		}
	}


	return true;
}



void lc_0036()
{
	std::vector<std::vector<char>> board1 = {
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};

	// printf("%s\n", isValidSudoku(board1) ? "True": "False");

	std::vector<std::vector<char>> board2 = {
		{'.','.','4','.','.','.','6','3', '.'},
		{'.','.','.','.','.','.','.','.','.'},
		{'5','.','.','.','.','.','.','9','.'},
		{'.','.','.','5','6','.','.','.','.'},
		{'4','.','3','.','.','.','.','.','1'},
		{'.','.','.','7','.','.','.','.','.'},
		{'.','.','.','5','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.'}
	};
	printf("%s\n", isValidSudoku(board2) ? "True" : "False");


}