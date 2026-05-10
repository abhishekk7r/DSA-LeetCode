class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        
        //Pop While top is smaller than i, and when moving add i
        for(int i = n - 1; i >= 0; i--){
            
            while(!s.empty() && temperatures[s.top()] <= temperatures[i]){
                s.pop();
            }

            if(!s.empty()) ans[i] = s.top() - i;
            s.push(i);
        }

        return ans;
    }
};