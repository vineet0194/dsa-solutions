class Solution {
public:
    bool checkDivisibility(int realN) {
        int n = realN;
        int sum = 0, prod = 1;
        
        while (n>0){
            int digit = n%10;
            sum += digit;
            prod *= digit;
            n /= 10;
        }
        
        cout << sum << " ";
        cout << prod;
        
        return (realN%(sum+prod))==0;
    }
};