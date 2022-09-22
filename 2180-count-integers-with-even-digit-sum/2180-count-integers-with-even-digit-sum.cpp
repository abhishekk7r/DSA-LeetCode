class Solution {
    int digitSum(int n){
        int sum=0;
        while(n!=0){
            int digit=n%10;
            sum+=digit;
            n=n/10;
            
        }
        return sum;
    }
public:
    int countEven(int num) {
//        // int a = log10(num)+1;
//        // int b = num/(pow(10, a-1));
        
        
//         int ans = (num/10 * 5) + (num%10)/2;
//         int a=num%10;
//         //int b = num/(pow(10, a-1));
//         int d;
//         while(num>0)
//         {
//             d+=num%10;
//             num/=10;
//         }
//         if(d%2==0)
//             return ans;
        
        
//         return ans+a/2;
        int count=0;
        for(int i=1;i<=num;i++){
            int b=digitSum(i);
            if(b%2==0){
                count++;
            }
            
        }
        return count;
    }
};