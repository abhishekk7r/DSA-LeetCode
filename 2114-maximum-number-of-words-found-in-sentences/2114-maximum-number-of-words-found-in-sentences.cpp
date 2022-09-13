class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int count = INT_MIN;
        int ans = 0;
        for(int i =0; i<sentences.size(); i++){
            string temp = sentences[i];
            int tempCount = 1;
            for(int j=0; j<temp.size(); j++){
                
                if(temp[j]==' '){
                    tempCount++;
                }
            }
             ans = max(tempCount, ans);
                count = tempCount;
        }
        return ans;
    }
};