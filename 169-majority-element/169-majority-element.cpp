class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();
        
        //Put elements in hashmap
        for(int i=0; i<n; i++)
        {
            m[nums[i]]++;
        }
        
        
        int maxVal = nums[0];
        
        //traverse the map and return the frequency of the 
        //most occuring element
        for(auto i:m){
            if(i.second > m[maxVal])
                maxVal = i.first;
        }
        return maxVal;
    }
};