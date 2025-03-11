#include <algorithm>

class Solution {
public:
   
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int totalTime = 0; 
        int n = tickets.size(); 
      
        for (int i = 0; i < n; ++i) {
            if (i <= k) {
              
                totalTime += min(tickets[k], tickets[i]);
            } else {
                
                totalTime += min(tickets[k] - 1, tickets[i]);
            }
        }
        return totalTime; 
    }
};
