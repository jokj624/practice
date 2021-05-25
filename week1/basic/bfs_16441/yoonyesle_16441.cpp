// 빙판에서 산에 부딪힌 경우 모든 방향 가능. Line15 수정. 현재 빙판인 경우 다음이 산인지 체크

#include <iostream>
#include <queue>
using namespace std;

int n, m, d[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
char in[101][101], cp[101][101];

void find(int x, int y, int dir) {
	if (x >= n || y >= m || x < 0 || y < 0)
		return;
	if (in[x][y] == '#' || cp[x][y] == 'X')
		return;
	if (in[x][y] == '+' && in[x + d[dir][0]][y + d[dir][1]] != '#') {
		find(x + d[dir][0], y + d[dir][1], dir);
		return;
	}
	cp[x][y] = 'X';
	find(x - 1, y, 0);
	find(x, y + 1, 1);
	find(x + 1, y, 2);
	find(x, y - 1, 3);
}

int main() {
	queue<pair<int, int>> w;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", in[i]);
		for (int j = 0; j < m; ++j) {
			cp[i][j] = in[i][j];
			if (in[i][j] == 'W')
				w.push(make_pair(i, j));
		}
	}
	while (!w.empty()) {
		find(w.front().first, w.front().second, 0);
		w.pop();
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (cp[i][j] == '.')
				printf("P");
			else
				printf("%c", in[i][j]);
		}
		printf("\n");
	}
	return 0;
}
