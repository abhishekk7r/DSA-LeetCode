class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count = 0;

        unordered_map<int, int> m;
        
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }        
        
        for(int i=0; i<nums.size(); i++)
        {    
            if(k!=0){
                if(m[k+nums[i]]>0)
                    count++;
                m[k+nums[i]] =0;
            }else{
                if(m[k+nums[i]]>1)
                    count++;
                m[k+nums[i]] =0;
            }
        }   
         return count;   
        
    }
};