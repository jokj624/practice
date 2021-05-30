#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>in_order;
//vector<int>in_visited;
vector<int>post_order;
vector<int>post_visited;

vector<int>pre_order;

vector<int>answer;
/*
int find_root_in_order(int r){
    int count = 0;
    for(int i = (int)in_order.size()-1; i >= 0; i-- ){
        if(in_order[i] == r){
            return count;
        }
        else{
            count++;
        }
    }
    return 0;
}*/

void solve(int in_start, int in_end, int post_start, int post_end ){
    if(in_start > in_end || post_start > post_end){
        return;
    }
    
    int root = post_order[post_end];
    
    answer.push_back(root);
    
    solve(in_start, pre_order[root] - 1, post_start, post_start + (pre_order[root] - in_start) - 1);

    solve(pre_order[root] + 1, in_end, post_start + (pre_order[root] - in_start), post_end - 1);

}

int main(){
    
    int n;
    
    cin >> n;
    
    for(int i =0; i < n; i++){
        int a;
        
        cin >> a;
        
        pre_order.push_back(0);
        in_order.push_back(a);
        //in_visited.push_back(0);
    }
    
    for(int i =0; i < n; i++){
        int a;
        
        cin >> a;
        
        post_order.push_back(a);
        post_visited.push_back(0);
    }
    
    for(int i =0; i < n; i++){
        pre_order[in_order[i]] = i;
    }
    
    solve(0, n-1, 0, n-1);
    
    for(int i =0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    
}
