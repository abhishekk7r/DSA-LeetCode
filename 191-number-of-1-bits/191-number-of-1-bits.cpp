class Solution {
public:
    int hammingWeight(uint32_t n) {
       int count = 0;
        // Run the loop till the number is not equal to zero
        
        while(n!=0){
            //We check if the last digit is eqaul to 1
            if(n&1){
                //If Yes, We increase the counter
                count++;
            }
            //We Shift the last digit by 1 position from left and continue checking
            n=n>>1;
        }
        return count;
    }
};