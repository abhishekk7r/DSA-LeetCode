class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count = 0;
        
        unordered_map<int, int> m; //c1
        
        for(int i=0; i<nums.size(); i++){ //c2
            m[nums[i]]++;
        }        
        
        
        //c3
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
/* 
c1 : Create an unordered map
c2 : Then, set value of each key to 1.

c3 : Run a loop till the size of the array.
     Check if the required difference is !=0 
     If it is equal to zero then,
     check whether the k+nums[i] in map is present 
        
        i.e. >0
        
        if yes, then we increase the count and set its value to zero so that in
        next iteration it is not counted again,
        
        if(k==0)
        
        then we see if the value of k+nums[i] > 1
        which means that the element is present more than once
        then we increase the count and add set the value to zero.
*/      
        


