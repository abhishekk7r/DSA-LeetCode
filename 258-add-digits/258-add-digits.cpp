class Solution {
public:
    int addDigits(int num) {
/*        //loop till the number is not a single digit number
        while(num>9){
            int temp = num%10; //store last digit into temp
            num = num/10 + temp; //add the temp into num divided by 10
        }
        return num;
        
*/
        
        //using digital root
        if(num==0){
            return 0;
        }
        if(num%9==0){
            return 9;
        } else {
            return num%9;
        }
    }
};