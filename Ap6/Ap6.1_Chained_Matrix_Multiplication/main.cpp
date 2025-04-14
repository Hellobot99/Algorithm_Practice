#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
using namespace std;

#define INF INT_MAX;
#define matrix_t vector<vector<int>>

int minimum(int i, int j, int& mink, vector<int>& d, matrix_t& M);

void minmult(int n, vector<int>& d, matrix_t& M, matrix_t& P)
{
	for (int i = 1; i <= n; i++)
		M[i][i] = 0;
	for (int diagonal = 1; diagonal <= n - 1; diagonal++)
		for (int i = 1; i <= n - diagonal; i++) {
			int j = i + diagonal, k;
			M[i][j] = minimum(i, j, k, d, M);
			P[i][j] = k;
		}
}

int minimum(int i, int j, int& mink, vector<int>& d, matrix_t& M)
{
	int minValue = INF;
	int value;
	for (int k = i; k <= j - 1; k++) {
		value = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
		if (minValue > value) {
			minValue = value;
			mink = k;
		}
	}
	return minValue;
}

void order(int i, int j, matrix_t& P, string& s)
{
	if (i == j)
		s += string("(A") + to_string(i) + ")";
	else {
		int k = P[i][j];
		s += string("(");
		order(i, k, P, s);
		order(k + 1, j, P, s);
		s += string(")");
	}
}

void print_matrix(int n, matrix_t a) {
	for (int i = 1; i <= n; i++) {
		for (int k = i; k <= n; k++) {
			if (k == n) cout << a[i][k] << endl;
			else cout << a[i][k] << " ";
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, a;
	string s;
	cin >> N;
	matrix_t M(N + 1, vector<int>(N + 1, 0));
	matrix_t P(N + 1, vector<int>(N + 1, 0));
	vector<int> arr;

	for (int i = 0; i <= N; i++) {
		cin >> a;
		arr.push_back(a);
	}

	minmult(N, arr, M, P);

	print_matrix(N, M);
	print_matrix(N, P);

	order(1, N, P, s);
	cout << M[1][N] << endl << s;

	return 0;
}