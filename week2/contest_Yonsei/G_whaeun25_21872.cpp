#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<deque>

using namespace std;

vector<pair<string, int>> yondol;
vector<pair<string, int>> seson;

int main(){
    
    int game_num;
    
    cin >> game_num;
    
    int block_num, stack_level;
    
    cin >> block_num >> stack_level;
    
    for(int i =0; i < game_num; i++){
        int a, b;
        string str1, str2;
        
        cin >> a >> str1;
        cin >> b >> str2;
        
        yondol.push_back({str1, a});
        seson.push_back({str2, b});
        
        if(block_num == 1){
            cout << "YS\n";
        }
        else if(a < b){
            cout << "Y\n";
        }
        else if (a > b){
            cout << "S\n";
        }
        else{
            cout << "YS\n";
        }
    }
}
