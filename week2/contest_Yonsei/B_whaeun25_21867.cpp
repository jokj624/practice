#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<deque>

using namespace std;

vector<char> ans;

int main(){
    
    int n;
    
    cin >>n;
    
    string str;
    
    cin >> str;
    
    for(int i =0; i<n; i++){
        if(str[i] != 'J' && str[i] != 'A' && str[i] != 'V'){
            ans.push_back(str[i]);
        }
    }
    
    if(ans.size() == 0){
        cout << "nojava";
    }else {
        for(int i =0; i<ans.size(); i++){
            cout << ans[i];
        }
    }
}
