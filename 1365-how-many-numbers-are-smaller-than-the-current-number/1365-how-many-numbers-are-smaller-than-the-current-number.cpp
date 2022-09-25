class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {        
        /*vector <int> v; 
            for(int i=0; i<nums.size(); i++){
            for(int j = 0; j<nums.size(); j++){
                int ans = nums[i];
                if(ans>nums[j])
                    v[i]++;   
            }
        }*/
        
        vector <int> ans = nums;
        int n = nums.size();
        map <int, int> m;
        
        sort(ans.begin(), ans.end());
        
        //map me chala gaya 
        // T.C o(n)
        for(int i=n-1; i>=0; i--)
        {
            m[ans[i]] = i;
        }
        
        
        //map me find karege ki kaha pe hai mera element and uska value kya hai
        for(int i=0; i<n; i++)
        {
            nums[i] = m[nums[i]];
        }
        
        return nums;
        
        
        
        
        
    }
};