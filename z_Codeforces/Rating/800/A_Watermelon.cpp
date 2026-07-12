#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    if (n<3)
        cout << "NO";
    else{
        if (n%2==0)
            cout << "YES";
        else
            cout << "NO";
    }
        
    return 0;
}