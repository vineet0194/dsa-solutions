/*
Problem: 1386. Cinema Seat Allocation
Link: https://leetcode.com/problems/cinema-seat-allocation/description/?envType=daily-question&envId=2026-08-19
Difficulty: Medium
Approach: Greedy Pick using Map
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp; //row -> seats in each row booked

        for(auto& reservedSeat : reservedSeats) {
            int row  = reservedSeat[0];
            int seat = reservedSeat[1];

            mp[row].insert(seat);
        }

        int result = (n - mp.size()) * 2;

        for(auto& [row, bookedSeats] : mp) {

            auto isAvailable = [&](int seat) {
                return bookedSeats.find(seat) == bookedSeats.end();
            };

            bool graupA = isAvailable(2) && isAvailable(3) && isAvailable(4) & isAvailable(5);
            bool graupB = isAvailable(4) && isAvailable(5) && isAvailable(6) & isAvailable(7);
            bool graupC = isAvailable(6) && isAvailable(7) && isAvailable(8) & isAvailable(9);

            if(graupA && graupC)
                result += 2;
            else if(graupA || graupB || graupC)
                result += 1;

        }

        return result;
    }
};
