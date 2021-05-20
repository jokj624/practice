#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int visited[100000] = {0, };
queue<pair<int,int>> num;

int n, t, g;

int button_b(int x){
    int result = 0;
    
    int alpha = 10000;
    
    result = x * 2;
    
    if(result > 99999){
        return -1;
    }
    
    for(int i =0; i < 5; i++){
        if(result / alpha != 0){
            result -= alpha;
            return result;
        }
        alpha /= 10;
    }
    
    return result;
}

int bfs(int node){
    
    num.push({node, 0});
    
    visited[node] = 1;
    
    while(!num.empty()){
        
        int num1 = num.front().first;
        int num1_cnt = num.front().second;
        
        if(num1_cnt > t){
            return -1;
        }
        
        num.pop();
        
        if(num1 == g){
            return num1_cnt;
        }
        
        int b_result = button_b(num1);
        
        if(num1 + 1 <= 99999 && visited[num1+1] == 0){
            visited[num1+1] = 1;
            num.push({num1+1, num1_cnt + 1});
        }
        if(b_result <= 99999 && visited[b_result] == 0 && b_result != -1){
            visited[b_result] = 1;
            num.push({b_result, num1_cnt + 1});
        }
    }
    return -1;
}

int main(){
    
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n >> t >> g;
    
    int answer = bfs(n);
    
    if(answer == -1){
        cout << "ANG";
    }
    else{
        cout << answer;
    }
    
}

