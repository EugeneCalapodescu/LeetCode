/*
	You are given an integer numRows, return the first numRows of Pascal's triangle.

	1
    11
	121
	1331
*/

#include "..\tools.h"
using namespace std;

static vector<vector<int>> generate(int numRows) 
{
	if (numRows == 0)
		return {};

	vector<vector<int>> res;
	res.push_back({ 1 });
	if (numRows == 1)
		return res;

	for (int i = 1; i < numRows; i++)
	{
		vector<int>& prev = res[i - 1];
		vector<int> v = vector(i+1, 1);

		for (int j = 1; j < prev.size(); j++)
			v[j] = prev[j] + prev[j - 1];

		res.push_back(v);
	}

	return res;
}

/* pre-allocate the result and just resize the current array at each loop */
vector<vector<int>> generate2(int numRows) {
	vector<vector<int>> res(numRows);

	for (int i = 0; i < numRows; i++) {
		res[i].resize(i + 1, 1);

		for (int j = 1; j < i; j++) {
			res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
		}
	}

	return res;
}

void lc_0118()
{
	auto res = generate(5);

	for (auto& v : res)
		cout << to_string(v) << "\n";
}