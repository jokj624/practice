#include <iostream>
using namespace std;

#define max(a, b) (a > b ? a : b)

int n, m, ans, visited[51][51], dp[51][51], dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
char in[51][51];

int dfs(int x, int y) {
	if (x >= n || y >= m || x < 0 || y < 0 || in[x][y] == 'H') {
		return 0;
	}
	if (visited[x][y]) {
		printf("-1");
		exit(0);
	}
	if (dp[x][y])
		return dp[x][y];
	visited[x][y] = 1;
	int X = in[x][y] - '0';
	for (int i = 0; i < 4; ++i) {
		dp[x][y] = max(dp[x][y], dfs(x + dir[i][0] * X, y + dir[i][1] * X) + 1);
	}
	visited[x][y] = 0;
	return dp[x][y];
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", in[i]);
	}
	dfs(0, 0);
	printf("%d", dp[0][0]);
	return 0;
}
