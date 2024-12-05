/*  Algorithm : Floyd-Warshall
*   Tag : Graph, Shortest path problem, Floyd-Warshall
*   Problem : Baekjoon, No. 11404
*   URL : https://www.acmicpc.net/problem/11404
*/

#include <iostream>
#include <vector>

using namespace std;

int n, m, INF = 987654321;

int main()
{
    	ios::sync_with_stdio(0);
    	cin.tie(0);
    	cout.tie(0);

	cin >> n >> m;

	vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i != j)
			{
				arr[i][j] = INF;
			}
		}
	}

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (arr[a][b] > c)
		{
			arr[a][b] = c;
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 1; k <= n; ++k)
			{
                		arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
            		cout << ((arr[i][j] == INF) ? 0 : arr[i][j]) << ' ';
		}
		cout << '\n';
	}
}
