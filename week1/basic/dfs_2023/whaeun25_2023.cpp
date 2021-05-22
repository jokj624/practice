#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>answer;

bool prime(int num){
    if(num<2) {
        return false;
    }
    for(int i=2; i*i<=num; i++){
        if(num%i == 0){
            return false;
        }
    }
    return true;
}

void dfs(int a, int cnt){
    
    if(cnt == 0){
        answer.push_back(a);
    }
    
    int odd_num[5] = {1, 3, 5, 7, 9};
    
    for(int i =0; i<5; i++){
        int temp = a * 10 + odd_num[i];
        //cout << a << "\n";
        if(prime(temp)){
            dfs(temp, cnt-1);
        }
    }
}

int main(){
    int n;
    
    cin >> n;
    
    int prime_arr[4] = {2, 3, 5, 7};
    
    for(int i =0; i < 4; i++){
        dfs(prime_arr[i], n - 1);
    }
    
    for(int i =0; i< answer.size(); i++){
        cout << answer[i] << "\n";
    }
    
}
