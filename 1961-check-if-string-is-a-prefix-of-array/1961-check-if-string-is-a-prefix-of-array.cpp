class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string ans = "";
        // for(int i=0; i<words.size(); i++){
        //     ans += words[i];
        // }
        // if(ans.find(s)==0 && s.size()<=ans.size() ){
        //     return 1;
        // }
        // return 0;
        for(int i=0; i<words.size(); i++){
            ans += words[i];
            if(ans == s)
                return 1;
        }
        return 0;
    }
};