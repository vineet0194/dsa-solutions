/*
Problem: 901. Online Stock Span
Link: https://leetcode.com/problems/online-stock-span/description/
Difficulty: Medium
Approach: Monotonic Stack
Time Complexity: O(n)
Note:
    
*/

// Brute Force

class StockSpanner {
public:
    vector<int> stocks;

    StockSpanner() {}
    
    int next(int price) {
        stocks.emplace_back(price);
        int count = 0;
        
        for (int i=stocks.size()-1; i>=0; i--){
            if (stocks[i] <= price)
                count++;
            else
                break;
        }
            
        return count;
    }
};

// OPTIMAL

class StockSpanner {
public:
    stack<pair<int, int>> st;

    StockSpanner() {}
    
    int next(int price) {
        int span = 1;

        while (!st.empty() && st.top().first <= price){
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */