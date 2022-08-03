class Solution {
public:
    int bitwiseComplement(int n) {
        
        int m=n;
        int mask=0;
        
        //Edge Case
        if(n==0)
            return 1;
        
        //create a mask that will contain 1 at the end bits = no. of actual bits in n
        while(m!=0){
            mask= (mask<<1) | 1;
            
            //this will make sure it only inserts 1 till the number of actual bits in n
            m=m>>1; 
        }
        
        //we invert n and use `&` operation qith mask to get the number.
        int ans = (~n) & mask ;
        
        return ans;
    }
    
    
};