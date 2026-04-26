class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto i:s){
            if(!st.empty()){
                char top = st.top();

                if((top == '(' && i == ')')  ||
                    (top == '{' && i == '}') ||
                    (top == '[' && i == ']') ){

                        st.pop();
                        continue;
                    }
            }

            st.push(i);
        }

        return st.empty();
    }
};