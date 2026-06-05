// recursion - function calls itself
// backtracking - at a certain basecase, function revert backs changes (comes back to prev iteration)

#include<bits/stdc++.h>
using namespace std;

int factorial(int num){
    if (num < 0)
        return -1;
    else if (num == 0 || num == 1)
        return 1;
    else
        return num*factorial(num-1);
}

int sum(int n){
    if (n==0)
        return 0;
    //else
    return n+sum(n-1);
}

void nTo1(int n){
    if (n == 1){
        cout << 1 << endl;
        return;
    }
    cout << n << " ";
    nTo1(n-1);
}

void oneToN(int i, int n){
    if (i == n){
        cout << n << endl;
        return;
    }
    cout << i << " ";
    oneToN(i+1, n);
}

void printNameNTimes(int n){
    if (n==0)
        return;
    
    cout << "Vineet ";
    printNameNTimes(n-1);
}

int main(){
    // int fac = factorial(5);
    // if (fac == -1)
    //     cout << "neg number!";
    // else
    //     cout << fac;

    // cout << sum(5) << endl;

    // nTo1(5);
    // oneToN(1, 10);

    printNameNTimes(3);

    return 0;
}