class Solution {
public:
    int lengthOfLastWord(string s) {
        /*int end = s.size()-1;
        string ans = "";
        for(int i=end; i>=0; i--){
            if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')){
                ans+=s[i];
            }
            if(s[i]==' ')
                    break;
        }
        return ans.size();*/
        int finalCount = 0;
        int count = 0;
        
        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){
                if(count!=0){
                    finalCount = count;
                }
                count=0;
            } else {
                count++;
            }
        }
        if(count == 0){
          return  finalCount;
        } 
        return count;
        
        
        
        
        
    }
};