/*
Problem: Swap the Numbers
Link: https://www.geeksforgeeks.org/problems/swap-the-numbers/1
Difficulty: Easy
Approach: Bit Manipulation
Time Complexity: O(1)
Note:
    1. a = a^b
    2. b = a^b = (a^b)^b => a
    3. a = a^b = (a^b)^a => b

    hence, swapped!
*/

void swap(int &a, int &b) {
    a = a^b;
    b = a^b;
    a = a^b;
}
