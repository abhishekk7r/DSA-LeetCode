class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.back();
        set<int> st(days.begin(), days.end());

        vector<int> dp(n+1, 0);

        for(int i=1; i<=n; i++){
            if(!st.count(i)){
                dp[i] = dp[i-1];
            } else {
                dp[i] = min({dp[i-1] + costs[0],
                         dp[max(0, i-7)] + costs[1],
                         dp[max(0, i-30)] + costs[2]});
            }
        }

        return dp[n];
    }
};