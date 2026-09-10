class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int &i:asteroids){
            bool alive = true;

            while(alive && !st.empty() && i < 0 && st.top() > 0){
                if(st.top() < abs(i)){
                    st.pop();
                } else if(st.top() == abs(i)) {
                    st.pop();
                    alive = false;
                } else {
                    alive = false;
                }
            }


            if(alive) st.push(i);
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};