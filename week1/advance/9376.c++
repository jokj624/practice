#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<pair<int, int>> prisoner_location;

char jail[110][110];
int dist[110][110];
int visited[110][110];
int visited2[110][110];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int h, w;

void bfs1(int node_y, int node_x){
    
    queue <pair<pair<int, int>, pair<int,int>>> q;
    
    visited[node_y][node_x] = 1;
    visited[prisoner_location[1].first][prisoner_location[1].second] = 2;
    
    q.push({{node_y, node_x}, {0,1}});
    q.push({{prisoner_location[1].first, prisoner_location[1].second}, {0,2}});
    
    while(!q.empty()){
        int fy = q.front().first.first;
        int fx = q.front().first.second;
        
        int door_num = q.front().second.first;
        int pri_num = q.front().second.second;
        
        q.pop();
        
        for(int i =0; i <4; i++){
            int xx = fx + dx[i];
            int xy = fy + dy[i];
            
            if((visited[xy][xx] == 1 && pri_num == 1) || xy < 0 || xx < 0 || xy >= h || xx >= w || (visited[xy][xx] == 2 && pri_num == 2) || (visited[xy][xx] == 3 )){
                continue;
            }
            
            if(jail[xy][xx] == '*'){
                continue;
            }
            else if(jail[xy][xx] == '#'){
                if(visited[xy][xx] == 0){
                    visited[xy][xx] = pri_num;
                    door_num++;
                    dist[xy][xx] = door_num;
                    q.push({{xy, xx}, {door_num, pri_num}});
                    door_num--;
                }
                else if(visited[xy][xx] == 1 || visited[xy][xx] == 2){
                    visited[xy][xx] = pri_num;
                    dist[xy][xx] += door_num;
                    q.push({{xy, xx}, {door_num, 3}});
                }
                else if(pri_num == 3){
                    visited[xy][xx] = pri_num;
                    door_num++;
                    dist[xy][xx] += door_num;
                    q.push({{xy, xx}, {door_num, pri_num}});
                    door_num--;
                }
            }
            else{
                if(visited[xy][xx] == 0){
                    visited[xy][xx] = pri_num;
                    dist[xy][xx] = door_num;
                    q.push({{xy, xx}, {door_num, pri_num}});
                }
                else if(visited[xy][xx] == 1 || visited[xy][xx] == 2){
                    visited[xy][xx] = pri_num;
                    dist[xy][xx] += door_num;
                    q.push({{xy, xx}, {door_num, 3}});
                }
            }
        }
    }
    
}

int bfs2(int node_y, int node_x){
    queue <pair<pair<int, int>, int>> q;
    
    int door_num = 0;
    
    visited2[node_y][node_x] = 1;
    q.push({{node_y, node_x}, 0});
    
    while(!q.empty()){
        int fy = q.front().first.first;
        int fx = q.front().first.second;
        
        door_num = q.front().second;
        
        q.pop();
        
        for(int i =0; i <4; i++){
            int xx = fx + dx[i];
            int xy = fy + dy[i];
            
            if(visited2[xy][xx] == 1){
                continue;
            }
            
            if(xy < 0 || xx < 0 || xy >= h || xx >= w){
                return door_num;
            }
            
            if(jail[xy][xx] == '*'){
                continue;
            }
            else if(jail[xy][xx] == '#'){
                visited2[xy][xx] = 1;
                door_num++;
                q.push({{xy, xx}, door_num});
                door_num--;
            }
            else{
                visited2[xy][xx] = 1;
                q.push({{xy, xx}, door_num});
            }
        }
    }
    return door_num;
}

int main(){
    int testcase;
    
    cin >> testcase;
    prisoner_location.push_back({0, 0});
    prisoner_location.push_back({0, 0});
    
    for(int t = 0; t < testcase; t++){
        int pri = 0;
        cin >> h >> w;
        
        for(int i = 0; i < h; i++){
            for(int j =0; j < w; j++){
                jail[i][j] = 0;
                visited[i][j] = 0;
                visited2[i][j] = 0;
                dist[i][j] = 100000000;
            }
        }
        
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                char a;
                
                cin >> a;
                
                if(a == '$'){
                    prisoner_location[pri] = {i, j};
                    pri++;
                }
                
                jail[i][j] = a;
            }
        }
        
        int answer = 0;
        int method1 = 10000000, method2, method3;
        
        bfs1(prisoner_location[0].first, prisoner_location[0].second);
        cout << "\n\n\n\n\n\n";
        for(int i =0; i< h; i++){
            for(int j = 0; j <w; j++){
                cout << dist[i][j];
            }
            cout << "\n";
        }
        
        method2 = bfs2(prisoner_location[0].first, prisoner_location[0].second);
        method3 = bfs2(prisoner_location[1].first, prisoner_location[1].second);
        
        //cout << "method2: " << method2 << "\n";
        
        
        for(int i = 0; i < h; i++ ){
            for(int j =0; j <w; j++){
                if(i == 0 || i == h-1 || j == 0 || j == w-1){
                    if(visited[i][j] == 3){
                        if(method1 > dist[i][j]){
                            method1 = dist[i][j];
                        }
                    }
                }
            }
        }
        
        //method2 = bfs3(prisoner_location[0].first, prisoner_location[0].second) + bfs3(prisoner_location[1].first, prisoner_location[1].second);
        
        answer = method1 < method2 + method3 ? method1 : method2 + method3;
        
        cout << answer << "\n";
        
        
    }
    
}
