#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int dp[60][60];
int score[60] = {0, };

int n;

int solve(int node_num, int edge_num){
    
    if(node_num <= 0){
        return 0;
    }
    
    if(dp[node_num][edge_num] != -1){
        return dp[node_num][edge_num];
    }
    
    //cout << "node_num: " << node_num << "edge_num: " << edge_num << "\n";
    
    for(int i = 1; i < node_num; i++){
        dp[node_num][edge_num] = max(dp[node_num][edge_num], solve(i, 1) + solve(node_num - i, edge_num + 1));
    }
    
    return dp[node_num][edge_num];
}

int main(){
    
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    for(int i =0; i<60; i++){
        for(int j = 0; j < 60; j++){
            dp[i][j] = -1;
        }
    }
    
    cin >> n;
    
    for(int i = 1; i <= n-1; i++){
        int a;
        
        cin >> a;
        
        score[i] = a;
        dp[1][i] = score[i];
    }
     
    int answer = solve(n, 0);
    
    cout << answer;
}
