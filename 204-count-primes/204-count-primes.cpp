class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        
        //using steve of eratostene
        
        //Mark all numbers as prime number
        vector<bool> prime(n+1, true);
        
        //mark 0 and 1 as non prime
        prime[0] = prime[1] = 0;
        
        //check whether i is prime or not
        for(int i=2; i<n; i++)
        {
            if(prime[i])
                count++;
            
            //if prime then mark all number in it's table as non prime
            for(int j=2*i; j<n; j=j+i)
            {
                prime[j]=0;
            }
        }
        return count;
    }
};