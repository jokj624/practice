#include<iostream>

using namespace std;

int main(){
    
    int n;
    
    cin >> n;
    
    if(n>=2){
        cout << n + (n-2) << "\n";
    }
    else if(n == 1){
        cout << 1 << "\n";
    }
    
    for(int i =1; i<=n; i++){
        cout << i << " 1" << "\n";
    }
    
    for(int i = 2; i<=n-1; i++){
        cout << i << " " << n << "\n";
    }
    
}

