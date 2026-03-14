/*

	LC 733 Flood Fill

	An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

	You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].
	To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally
	to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally
	to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

	Return the modified image after performing the flood fill.

	Example 1:
		Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
		Output: [[2,2,2],[2,2,0],[2,0,1]]
		Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.

		Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

*/

#include "..\tools.h"
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color, std::set<std::pair<int, int>>& visited)
{
	static vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	int old_color = image[sr][sc];

	image[sr][sc] = color;

	for (auto d : directions)
	{
		int r = sr + d.first;
		int c = sc + d.second;

		if (r >= 0 && r < image.size() && c >= 0 && c < image[0].size())
		{
			if (visited.find({ r, c }) == visited.end())
			{
				visited.insert({ r, c });
				if (image[r][c] == old_color)
					floodFill(image, r, c, color, visited);

			}
		}
	}

	return image;
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
{
	std::set<std::pair<int, int>> v;
	return floodFill(image, sr, sc, color, v);

}

void lc_0733()
{
	{
		vector<vector<int>> image = { {1,1,1}, {1,1,0}, {1,0,1} };
		floodFill(image, 1, 1, 2);

		image = { {0, 0, 0}, { 0, 0, 0 } };
		floodFill(image, 0, 0, 0);

	}
}