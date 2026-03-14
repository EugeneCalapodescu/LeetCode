/*

	LC 279 Perfect Squares

	Given an integer n, return the least number of perfect square numbers that sum to n.

	A perfect square is an integer that is the square of an integer;
	in other words, it is the product of some integer with itself.
	For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.


	Example 1:

	Input: n = 12
	Output: 3
	Explanation: 12 = 4 + 4 + 4.

	Example 2:

	Input: n = 13
	Output: 2
	Explanation: 13 = 4 + 9.

*/


#include "..\tools.h"

int numSquares(int n);


void lc_0279()
{
	std::string line;
	while (1)
	{
		printf("> ");
		std::getline(std::cin, line);

		if (line.empty())
			break;

		int n = boost::lexical_cast<int>(line);

		printf("%d\n", numSquares(n));
	}
}


int numSquares(int n)
{
	std::vector<int> results(n + 1, 0);

	for (int i = 0; i <= n; i++)
		results[i] = i;

	for (int target = 1; target <= n; target++)
	{
		for (int s = 1; s <= target; s++)
		{
			int square = s * s;
			if (square > target)
				break;

			int temp = 1 + results[target - square];

			if (temp < results[target])
				results[target] = temp;

		}
	}

	return results[n];
}
