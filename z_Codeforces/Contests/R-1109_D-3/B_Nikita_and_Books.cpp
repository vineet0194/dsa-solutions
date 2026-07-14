#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<long long>> stacks;

    int m;
    for (int i = 0; i < n; i++){
        cin >> m;

        vector<long long> st;

        for (int j = 0; j < m; j++){
            long long temp;
            cin >> temp;
            st.push_back(temp);
        }

        stacks.push_back(st);
    }

    for (auto& st : stacks){

        bool neat = true;

        long long sum = 0;

        for (int i = 0; i < st.size(); i++){

            sum += st[i];

            long long need = 1LL * (i + 1) * (i + 2) / 2;

            if (sum < need){
                neat = false;
                break;
            }
        }

        if (neat)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}