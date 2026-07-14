#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    int strSize;
    string str;

    vector<string> arr;

    for (int i=0; i<n; i++){
        cin >> strSize;
        cin >> str;
        arr.push_back(str);
    }
    
    int count=0;
    for (int i=0; i<arr.size(); i++){

        int longest=0, curr=0;
        for (int j=0; j<arr[i].size(); j++){
            if (arr[i][j] == '#')
                curr++;
            else
                curr = 0;
            
            if (longest < curr)
                longest = curr;
        }

        if (longest%2 != 0)
            longest++;
        
        cout << longest/2 << endl;
    }

    return 0;
}