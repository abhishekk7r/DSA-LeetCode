 class Solution {
private: 
    bool checkEqual(int arr1[], int arr2[]){
    for(int i=0; i<26; i++){
        if(arr1[i]!=arr2[i])
            return 0;
    }
    return 1;
}
    
public:
    bool checkInclusion(string s1, string s2) {
        
        //Character Count Array
        int count1[26] = {0};
        
        for(int i=0; i<s1.length(); i++)
        {
            int index = s1[i] - 'a';
            count1[index]++;
        }
        
        //For First Window
        int count2[26] = {0};
        int i = 0;
        int k = s1.length();
        
        while(i<k && i<s2.length()){
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }
        
        //checking if the window and the string s1 is equal or not
        if (checkEqual(count1, count2))
            return 1;
        
        //aage wali windows kelia
        while(i<s2.length()){
            char newChar = s2[i];
            int index = newChar - 'a';
            count2[index]++;
            
            char oldChar = s2[i-k];
            index = oldChar - 'a';
            count2[index]--;
            
            i++;
            if (checkEqual(count1, count2))
                return 1;
        }
        
    return 0;
    }
};














