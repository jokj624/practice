#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

char mapp[51][51] ={0, };
int visited[51][51] ={0, };
int dp[51][51] = {0, };

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int n, m;
//int max_degree = 0;

int dfs(int x, int y){
    
    if(x < 0 || y < 0 || x >= m || y >= n || mapp[y][x] == 'H'){
        return 0;
    }
    
    if(visited[y][x] == 1){
        cout << "-1";
        exit(0);
    }
    
    if(dp[y][x] != 0){
        return dp[y][x];
    }
    
    visited[y][x] = 1;
    
    for(int i = 0; i<4; i++){
        int a = x + dx[i]*(mapp[y][x] - '0');
        int b = y + dy[i]*(mapp[y][x] - '0');
        //cout << degree;
        dp[y][x] = max(dp[y][x], dfs(a, b) + 1 );
    }
    visited[y][x] = 0;
    
    return dp[y][x];
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        //string a;
        
        cin >> mapp[i];
        
        //mapp[i] = a;
        /*
        for(int j = 0; j < m; j++){
            char a;
            
            cin >> a;
            
            mapp[i][j] = a;
        }
         */
    }
    
    cout << dfs(0, 0);
    
}
