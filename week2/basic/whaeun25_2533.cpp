#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>>tree;
vector<int>v;

int visited[1000100] = {0, };
int tree_dp[1000100][2];

void dfs(int node){
    visited[node] = 1;
    
    tree_dp[node][0] = 1;
    
    for(int i = 0; i < tree[node].size(); i++){
        int next = tree[node][i];
        
        if(visited[next] == 1){
            continue;
        }
        
        dfs(next);
        
        tree_dp[node][1] += tree_dp[next][0];
        tree_dp[node][0] += min(tree_dp[next][1], tree_dp[next][0]);
        
    }
    
}

int main(){
    int n;
    
    cin >> n;
    
    for(int i =0; i<=n; i++){
        tree.push_back(v);
    }
    
    for(int i =0; i<n-1; i++){
        int a, b;
        
        cin >> a>>b;
        
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    dfs(1);
    
    int answer = tree_dp[1][0] < tree_dp[1][1] ? tree_dp[1][0] : tree_dp[1][1];
    
    cout << answer;
    
}
