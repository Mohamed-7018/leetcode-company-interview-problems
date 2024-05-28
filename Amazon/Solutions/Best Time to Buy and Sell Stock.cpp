class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int ans = 0;

        for(auto &it : prices) {
            if(it == buy) continue;
            if(buy > it) buy = it;

            ans = max(ans, it - buy );
        }


        return ans;
    }
};