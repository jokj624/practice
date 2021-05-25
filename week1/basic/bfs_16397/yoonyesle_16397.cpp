#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, T, G;
	cin >> N >> T >> G;
	queue<pair<int, int>> q;
	q.push({N, 0});
	bool visited[100000] = {false};
	visited[N] = true;
	while (!q.empty()) {
		int current = q.front().first, cnt = q.front().second;
		q.pop();
		if (cnt > T) break;
		if (current == G) {
			cout << cnt; return 0;
		}
		if (current + 1 < 100000 && !visited[current + 1]) {
			q.push({current + 1, cnt + 1});
			visited[current + 1];
		}
		if (current * 2 < 100000) {
			int btn2 = current * 2, digit = 1;
			if (btn2) {
				while (btn2 / 10) {
					digit *= 10; btn2 /= 10;
				}
				if (!visited[current * 2 - digit]) {
					q.push({current * 2 - digit, cnt + 1});
					visited[current * 2 - digit] = true;
				}
			}
			else {
				if (!visited[0]) {
					q.push({0, cnt + 1}); visited[0] = true;
				}
			}
		}
	}
	cout << "ANG";
	return 0;
}
