class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans (s.size(),' ');
       //  vector<char> v(s.size(),'0');
       //  for(int i=0; i<s.size(); i++){
       //      int index = indices[i];
       //      char c=s[i];
       //      v[index]=c;
       //  }
       // for(int i=0;i<v.size();i++){
       //     ans+=v[i];
       // }
        for(int i=0;i<s.size();i++)
        {
            ans[indices[i]]=s[i];
        }
        return ans;
    }
};