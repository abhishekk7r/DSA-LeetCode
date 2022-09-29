class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*unordered_map<int, int> m;
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
        return maxVal;*/
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
        
        /*given the fact that a majority element always exists
        and its existence is always > n/2. 
        -> We can say that after sorting the element will 
        always be present at n/2 index.*/
    }
};