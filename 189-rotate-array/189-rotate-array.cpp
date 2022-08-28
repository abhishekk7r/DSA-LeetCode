class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        
        /*
        vector <int> v1;
        vector <int> v2;
        for(int i=n-k; i<n; i++){
            v1.push_back(nums[i]);
        }   
        for(int i=0; i<n-k; i++){
            v2.push_back(nums[i]);
        }
        nums = v1;
        for(int i=0; i<v2.size(); i++){
            nums.push_back(v2[i]);
        }*/
        
        vector <int> temp(n);
        for(int i=0; i<n; i++){
            temp[(k+i)%n] = nums[i];
        }
        
        nums = temp;
    }
};