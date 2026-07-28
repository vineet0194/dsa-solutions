/*
Problem: Bit Manipulation - Introduction
Link: https://takeuforward.org/data-structure/introduction-to-bit-manipulation-theory
Difficulty: Easy
Approach: -
Time Complexity: -
Note:
    
*/

#include<bits/stdc++.h>
using namespace std;

// O(logN) for while loop
// O(k) for reversing where k => number of bits
string decimalToBinary(int n){
    if (n==0) return 0;

    string ans = "";
    
    while (n != 0){
        int rem = n%2;
        ans += rem + '0';
        n /= 2;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int binaryToDecimal(string n){
    int ans = 0;

    int size = n.size();

    for (int i=size-1; i>=0; i--)
        ans += (n[i]-'0') * (1<<(size-1-i));
    
    return ans;
}

bool findBit(int num, int i){
    return 1 & (num >> i);
}

int setBit(int num, int i){
    return num + (1 << i);
}

int clearBit(int num, int i){
    return num & (!(1<<i));
}

int toggleBit(int num, int i){
    return num ^ (1<<i);
}

int removeLastSetBit(int num){
    return num & num-1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 13;
    cout << "Binary of " << n << " = " << decimalToBinary(n) << endl;

    string s = "1101";
    cout << "Decimal of " << s << " = " << binaryToDecimal(s) << endl;

    // int t1 = INT_MIN;
    // int t2 = INT_MAX;
    // cout << !t1;

    int p = 23;     // 10111        // i value => 43210
    int i = 3;
    cout << "(LSB) Bit " << i << " of " << p << " = " << findBit(p, i) << endl;

    // set p's bit 3
    // similarly you can do clear bit
    cout << "After seting = " << setBit(p, i) << endl;
    
    return 0;
}