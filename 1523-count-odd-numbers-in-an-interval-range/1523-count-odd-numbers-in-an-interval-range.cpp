class Solution {
public:
    int countOdds(int low, int high) {
        
        /*Time Complexity o(n);
        int count = 0;
        while(low<=high){
            if(low%2!=0){
                count++;
            }
            low++;
        }
        return count;*/
        
        //this will give the (total-1) odd number between high and low
        int count = (high-low)/2;
        
        //For last 1 number
        if(high%2!=0 || low%2!=0)
        {
            count+=1;
        }
        
        
        return count;
    }
};