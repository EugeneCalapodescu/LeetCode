/*

	LC 200 Number of Islands

	Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

	An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

	Example 1:
		Input: grid = [
		  ["1","1","1","1","0"],
		  ["1","1","0","1","0"],
		  ["1","1","0","0","0"],
		  ["0","0","0","0","0"]
		]
		Output: 1

	Example 2:
		Input: grid = [
		  ["1","1","0","0","0"],
		  ["1","1","0","0","0"],
		  ["0","0","1","0","0"],
		  ["0","0","0","1","1"]
		]
		Output: 3

*/

#include "..\tools.h"
using namespace std;

static void bfs(vector<vector<char>>& image, int r, int c, char color)
{
	if (r < 0 || r >= image.size() || c < 0 || c >= image[r].size() || image[r][c] == '0')
		return;

	image[r][c] = '0';

	bfs(image, r - 1, c, color);
	bfs(image, r + 1, c, color);
	bfs(image, r, c - 1, color);
	bfs(image, r, c + 1, color);
}


int numIslands(vector<vector<char>>& grid)
{
	int n = 0;

	for (int r = 0; r < grid.size(); r++)
	{
		for (int c = 0; c < grid[r].size(); c++)
		{
			if (grid[r][c] == '1')
			{
				n++;
				bfs(grid, r, c, '0');
			}
		}
	}
	return n;
}


void lc_0200()
{
	vector<vector<char>> grid = {
		{'1','1','1','1','0'},
		{'1','1','0','1','0'},
		{'1','1','0','0','0'},
		{'0','0','0','0','0'}
	};
	printf("%d\n", numIslands(grid));

	grid = {
		{'1','1','0','0','0'},
		{'1','1','0','0','0'},
		{'0','0','1','0','0'},
		{'0','0','0','1','1'}
	};
	printf("%d\n", numIslands(grid));

	grid = { {'1','1'} };
	printf("%d\n", numIslands(grid));

	grid = {
		{'1','1','1'},
		{ '0','1','0'},
		{ '1','1','1' }
	};
	printf("%d\n", numIslands(grid));


}