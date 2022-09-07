class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};
        for(int i=0; i<s.size(); i++)
        {
            char ch = s[i];
            int index = ch - 'a';
            arr[index]++;
        }
        
        
        for(int i =0; i<s.size(); i++){
            int index = s[i] - 'a';
            if(arr[index]==1){
                return i;
            }
        }
        return -1;
    }
};