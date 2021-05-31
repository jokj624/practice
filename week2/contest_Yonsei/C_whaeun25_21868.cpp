#include<iostream>
#include<cmath>

using namespace std;

int main() {
    
    int bunmo, bunza, a, b, x0;
    
    cin >> bunza >> bunmo;
    cin >> a >> b;
    cin >> x0;
    
    int l = a * x0 + b;
    
    cout << l << "\n";
    
    int answer;
    
    if(a == 0){
        cout << "0 0";
        exit(0);
    }
    
    answer = abs(a) * bunmo;
    int answer2;
    answer2 = bunza;
    cout << answer2 << " " << answer;
    
}
