class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ans = -1; 
        
        long long totalSum = 0;
        int leftSum = 0, rightSum = 0;
        
        int n = nums.size();
        
        //first we store the total sum in total sum variable
        for(int i =0; i<n; i++)
        {
            totalSum += nums[i];
        }
        
        /*Just for refrencing we calculate the totalSum and then assign it to rightSum 
        variable */
        rightSum = totalSum;
        
        
        /*For each i we subtract nums[i] element from the totalSum and check whether
        it is equal to the leftSum. If it is not equal we add nums[i] to the 
        leftSum and Check Again*/
        for(int i=0 ; i<n; i++)
        {
            rightSum = rightSum - nums[i]; 
            
            if(rightSum == leftSum){
                ans = i;
                break;
            } else {
                leftSum += nums[i];
            }
        }
        
        return ans;
    }
};
