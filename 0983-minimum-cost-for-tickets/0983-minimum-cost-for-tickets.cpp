class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(367, INT_MAX);
        dp[0] = 0;
        set<int> st;
        st.insert(days.begin(), days.end());

        for(int i=1; i<=365; i++){
            if(st.contains(i)){
                dp[i] = min({dp[i-1] + costs[0],
                         dp[max(0, i-7)] + costs[1],
                         dp[max(0, i-30)] + costs[2]});
            } else{
                dp[i] = dp[i-1];
            }
        }

        return dp[365];
    }
};