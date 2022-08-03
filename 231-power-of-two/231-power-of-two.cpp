class Solution {
public:
    bool isPowerOfTwo(int n) {
        
    //we run this loop till 30 because integer can store value till 2 to power 30.
       for(int i=0; i<=30; i++){
           int ans=pow(2, i);
           if(n==ans)
               return true;
       } 
        return false;
    }
};