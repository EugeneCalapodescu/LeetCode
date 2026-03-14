/*

	LC-79 Word Search

	Given an m x n grid of characters board and a string word, return true if word exists in the grid.

	The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
	The same letter cell may not be used more than once.

	Example 1:
		Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
		Output: true

*/

#include "..\tools.h"

using namespace std;

static bool exist(vector<vector<char>>& board, string& word, int r, int c, int start)
{
	static std::vector<std::pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

	if (word.size() == start)
		return true;

	if (board[r][c] != word[start])
		return false;

	if (word.size() == start + 1)
		return true;

	bool result = false;
	board[r][c] = ' ';

	for (int d = 0; d < 4; d++)
	{
		int rr = r + directions[d].first;
		int cc = c + directions[d].second;

		if (rr >= 0 && rr < board.size() && cc >= 0 && cc < board[r].size())
		{
			if (exist(board, word, rr, cc, start + 1))
				result = true;
		}
	}

	board[r][c] = word[start];

	return result;
}

static bool exist(vector<vector<char>>& board, string word)
{
	for (int r = 0; r < board.size(); r++)
	{
		for (int c = 0; c < board[r].size(); c++)
		{
			if (exist(board, word, r, c, 0))
				return true;
		}
	}
	return false;
}


void lc_0079()
{
	vector <vector<char>> board1 = {
		{'A','B','C','E'},
		{'S','F','C','S'},
		{'A','D','E','E'}
	};

	printf("exists %d:\n", exist(board1, "ABCCED"));

	vector<vector<char>> board2 = {
		{'A','A','A','A','A','A'},
		{'A','A','A','A','A','A'},
		{'A','A','A','A','A','A'},
		{'A','A','A','A','A','A'},
		{'A','A','A','A','A','A'},
		{'A','A','A','A','A','A'}
	};

	printf("exists %d:\n", exist(board2, "AAAAAAAAAAAAAAB"));

}