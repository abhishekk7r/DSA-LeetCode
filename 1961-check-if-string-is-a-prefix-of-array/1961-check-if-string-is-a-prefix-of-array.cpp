class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string ans = "";
        /*for(int i=0; i<words.size(); i++){
            ans += words[i];
        }
        if(ans.find(s)==0 && s.size()<=ans.size() ){
            return 1;
        }
        return 0;*/
        
        //jab ans == s ho jayega tabhi return 1 hoga nahi to add hote jayega ans me words[i]
        //add karne k baad bhi equal nahi aya to return 0 ho jayega
        for(int i=0; i<words.size(); i++){
            ans += words[i];
            if(ans == s)
                return 1;
        }
        return 0;
    }
};