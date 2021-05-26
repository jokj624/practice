//미완성 !
//BOJ 9376 탈옥
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

struct point{
	int d, x, y;
};
struct cmp {
	bool operator()(const point& a, const point& b){
		return a.d < b.d;
	}
};
int dijkstra(int x, int y, char arr[][101], int w, int h){
	priority_queue<point, vector<point>, cmp> pq;
	int cnt = 0;
	char map[w][101];
	int visit[w][h];
	int d[w][h];
	int x1=-1, x2, y1=-1, y2, ans = INF;
	for(int i=0; i<w; i++){
		for(int j=0; j<h; j++){
			map[i][j] = arr[i][j];
			visit[i][j] = 0;
			d[i][j] = INF;
			if(arr[i][j] == '$'){
				if(x1 == -1 && y1 == -1){
					x1 = i;	y1 = j;
				}	
				else{
					x2 = i; y2 = j;
				}
			}
		} 
	}
	d[x][y] = 1;
	pq.push({d[x][y], x, y});
	while(!pq.empty()){
		point node = pq.top();
		pq.pop();
		if(!visit[node.x][node.y]){
			visit[node.x][node.y] = 1;
			for(int i=0; i<4; i++){
				int nx = node.x + dx[i];
				int ny = node.y + dy[i];
				if(map[nx][ny] == '*')	continue;
				if(nx < 0 || ny < 0 || nx >= w || ny >= h)	continue;
				if(map[nx][ny] == '#'){
					map[nx][ny] = '.';
					if(d[nx][ny] > d[node.x][node.y] + 1){
						if(visit[nx][ny]){
							d[nx][ny] = d[node.x][node.y];
						}
						else	d[nx][ny] = d[node.x][node.y] + 1;
						pq.push({d[nx][ny], nx, ny});
					}
				}
				else if(map[nx][ny] == '.' || map[nx][ny] == '$'){
					if(d[nx][ny] > d[node.x][node.y]){
						d[nx][ny] = d[node.x][node.y];
						pq.push({d[nx][ny], nx, ny});
					}
				}
			}
		}
	}
	cout << d[x1][y1] << " " << d[x2][y2] << endl;
	return min(d[x1][y1], d[x2][y2]);
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int w, h, x=-1, y=-1, ans, x2, y2;
		int res = INF;
		vector<pair<int, int> > cand;
		scanf("%d %d", &w, &h);
		char map[w][101];
		for(int i=0; i<w; i++){
			for(int j=0; j<h; j++){
				cin >> map[i][j];
				if(map[i][j] == '#' || map[i][j] == '.' ){
					if(i == 0 || i == w-1 || j == 0 || j == h-1) {
						cand.push_back({i, j});
					}
				}
			}
		}	
		for(pair<int, int> tmp : cand){
			res = dijkstra(tmp.first, tmp.second, map, w, h );
		}
		printf("%d\n", res);
	}
	return 0;
}
