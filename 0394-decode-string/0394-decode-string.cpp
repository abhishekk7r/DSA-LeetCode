class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;
        int num = 0;
        string curr = "";
        for(auto &c:s){
            if(isdigit(c)){
                num = num * 10 + (c - '0'); //Create the String
            } else if(c == '['){
                st.push({curr, num});
                curr = "";
                num = 0;
            } else if(c == ']'){
                auto [prevStr, mul] = st.top();
                st.pop();
                string repeated = "";
                for(int i=0; i<mul; i++) repeated += curr;
                curr = prevStr + repeated; 
            } else {
                curr += c;
            }
        }

        return curr;
    }
};