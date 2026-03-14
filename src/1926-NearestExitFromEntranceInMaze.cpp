
/*

 LC-1926

	You are given an m x n matrix maze(0 - indexed) with empty cells(represented as '.') and walls(represented as '+').
	You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes
	the row and column of the cell you are initially standing at.

	In one step, you can move one cell up, down, left, or right.
	You cannot step into a cell with a wall, and you cannot step outside the maze.
	Your goal is to find the nearest exit from the entrance.
	An exit is defined as an empty cell that is at the border of the maze.
	The entrance does not count as an exit.

	Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.

	Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
	Output: 1
	Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
	Initially, you are at the entrance cell [1,2].
		- You can reach [1,0] by moving 2 steps left.
		- You can reach [0,2] by moving 1 step up.
	It is impossible to reach [2,3] from the entrance.
	Thus, the nearest exit is [0,2], which is 1 step away.



	Breath First Search algo

*/



#include "..\tools.h"


int nearestExit(std::vector<std::vector<char>>& maze, std::vector<int>& entrance);

void lc_1926()
{

#if 0
	std::vector<std::vector<char>> m;
	std::vector<int> e;

	m = {
		{'+','.','+','+','+','+','+'},
		{'+','.','+','.','.','.','+'},
		{'+','.','+','.','+','.','+'},
		{'+','.','.','.','+','.','+'},
		{'+','+','+','+','+','+','.'}
	};

	e = { 0, 1 };

	int d = nearestExit(m, e);
	printf("Distance: %d\n", d);

	m = {
		{'+','+','+'},
		{'.','.','.'},
		{'+','+','+'}
	};

	e = { 1, 0 };

	d = nearestExit(m, e);
	printf("Distance: %d\n", d);

	m = {
	{'+','+','+','+','+'},
	{'+','.','.','.','+'},
	{'+','.','.','.','+'},
	{'+','.','.','.','+'},
	{'+','.','.','.','+'},
	{'+','.','.','.','+'},
	{'+','+','+','+','+'},
	};

	e = { 2, 2 };

	d = nearestExit(m, e);
	printf("Distance: %d\n", d);

	m = {
		{'+', '+', '.', '+'},
		{'.', '.', '.', '+'},
		{'+', '+', '+', '.'}
	};

	e = { 1, 2 };

	d = nearestExit(m, e);
	printf("Distance: %d\n", d);

#endif

	std::string line;

	std::cout << "Enter the maze, one row at a time, e.g +++.++\n";
	std::cout << "An empty line at the end\n";

	std::vector<std::vector<char>> maze;
	while (1)
	{
		printf("> ");
		std::getline(std::cin, line);
		if (line.size() == 0)
			break;

		std::vector<char> row;
		for (int i = 0; i < line.size(); i++)
			row.push_back(line[i]);

		maze.push_back(row);
	}


	printf("Enter the Row and Column of the entrance e.g 1 0\n> ");
	std::getline(std::cin, line);

	std::vector<std::string> tokens;
	boost::split(tokens, line, boost::is_any_of(" "));
	if (tokens.size() != 2)
	{
		printf("Wrong answer ...\n");
		exit(1);
	}

	std::vector<int> entrance;
	entrance.push_back(boost::lexical_cast<int>(tokens[0]));
	entrance.push_back(boost::lexical_cast<int>(tokens[1]));

	maze[entrance[0]][entrance[1]] = 'E';

	int distance = nearestExit(maze, entrance);

	printf("Min distance: %d", distance);
}

struct cell
{
	int r;
	int c;
	int d;
};

int nearestExit(std::vector<std::vector<char>>& maze, std::vector<int>& entrance)
{
	std::queue<cell> queue;

	if (maze.size() == 0 || maze[0].size() == 0)
		return -1;

	int R = (int)maze.size();
	int C = (int)maze[0].size();

	queue.push({ entrance[0], entrance[1], 0 });
	maze[entrance[0]][entrance[1]] = 'x';

	std::vector<std::pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

	while (queue.size() > 0)
	{
		cell c = queue.front();
		queue.pop();

		for (auto direction : directions)
		{
			cell n;

			n.r = c.r + direction.first;
			n.c = c.c + direction.second;
			n.d = c.d + 1;

			if (n.c >= 0 && n.c < C && n.r >= 0 && n.r < R && maze[n.r][n.c] == '.')
			{
				if (n.r == 0 || n.c == 0 || n.r == (R - 1) || n.c == (C - 1))
					return n.d;

				maze[n.r][n.c] = 'x';
				queue.push(n);
			}
		}
	}

	return -1;
}


