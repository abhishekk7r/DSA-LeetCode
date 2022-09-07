class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int arr[26] = {0};
        for(int i=0; i<magazine.size(); i++)
        {
            char ch = magazine[i];
            int index = ch -'a';
            arr[index]++;
        }
        
        int arr2[26] ={0};
        for(int i =0; i<ransomNote.size(); i++)
        {
            char ch = ransomNote[i];
            int index= ch-'a';
            arr2[index]++;
        }
        
        for(int i=0; i<26; i++){
            if(arr2[i]>arr[i]){
                return 0;
            }
        }
        return 1;
    }
};