#include <iostream>
#include<algorithm>
using namespace std;
int k[3][3] = {{ -1, -1, -1}, { -1, -1 , -1}, { -1, -1, -1}};
int result(int** a, int x, int i, int n)

{
	if (k[n][i] != -1)
		return k[n][i];
	int ans;
	int o = (i + 1) % 3;
	int p = (i + 2) % 3;

	if (n == 0)
	{
		k[n][i] = x; return x;
	}
	ans = x + max(result(a, a[n - 1][o], o, n - 1), result(a, a[n - 1][p], p, n - 1));
	k[n][i] = ans;
	// cout << ans << endl;
	return ans;

}


int main() {

	int n; cin >> n;
	int** a = new int*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[3];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{cin >> a[i][j];}
	}


	int ans = max({result(a, a[n - 1][0], 0, n - 1), result(a, a[n - 1][1], 1, n - 1), result(a, a[n - 1][2], 2, n - 1)});
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{cout << k[i][j] << " ";}
		cout << endl;
	}


	cout << ans;

	return 0;
}