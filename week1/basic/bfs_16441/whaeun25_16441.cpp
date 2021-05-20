#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<vector<char>>mapp;
vector<vector<int>>visited;
vector<char>v;
vector<int>v2;

vector<pair<int, int>> wolf;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int n, m;

void bfs(int x, int y){
    
    for(int i =0; i<4; i++){
        int a, b;

        a = x + dx[i];
        b = y + dy[i];
        
        if (a >= 0 && b >= 0 && a < m && b < n && !visited[b][a] && mapp[b][a] != '#') {
            int check = 1;
            
            if(mapp[b][a] == '+'){
                while(1){
                    a += dx[i];
                    b += dy[i];
                    if(mapp[b][a] == '#'){
                        a -= dx[i];
                        b -= dy[i];
                        check = 0;
                        break;
                    }
                    else if(mapp[b][a] == '.'){
                        check = 0;
                        break;
                    }
                    if(a < 0 && b < 0 && a >= m && b >= n){
                        a -= dx[i];
                        b -= dy[i];
                        check = 0;
                        break;
                    }
                }
            }
            
            //cout << "a: " << a << "b: " << b << "\n" ;
            if(!visited[b][a] && check == 0){
                visited[b][a] = 1;
                bfs(a, b);
            }
            else if(check == 1){
                visited[b][a] = 1;
                bfs(a, b);
            }
        }
    }
    
}

int main(){
    
    cin >> n >> m;
    
    for(int i =0; i<n; i++){
        mapp.push_back(v);
        visited.push_back(v2);
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char a;
            
            cin >>a;
            
            if(a == 'W'){
                wolf.push_back(make_pair(i, j));
            }
            
            mapp[i].push_back(a);
            visited[i].push_back(0);
        }
    }
    
    for(int i =0; i< wolf.size(); i++){
        bfs(wolf[i].second, wolf[i].first);
    }
    /*
    cout << "\n";
    
    for(int i =0; i<n; i++){
        for(int j =0; j < m; j++){
            cout << visited[i][j];
        }
        cout << "\n";
    }
    
    cout << "\n";
    */
    for(int i =0; i<n; i++){
        for(int j =0; j < m; j++){
            if(mapp[i][j] == '.' && visited[i][j] == 0){
                cout << "P";
                continue;
            }
            cout << mapp[i][j];
        }
        cout << "\n";
    }
    
}
