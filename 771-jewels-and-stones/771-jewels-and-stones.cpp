class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int Jwls[26] = {0};
        int jwls[26] = {0};
        int count = 0;
        
        for(int i=0; i<jewels.size(); i++)
        {
            if(jewels[i]>='a' && jewels[i]<='z')
            {
                int index = jewels[i] - 'a';
                jwls[index]++;
            } else {
                int index = jewels[i] - 'A';
                Jwls[index]++;
            }
        }
        
        for(int i=0; i<stones.size(); i++)
        {
            if(stones[i]>= 'a' && stones[i]<= 'z')
            {
                int index = stones[i] - 'a';
                if(jwls[index]==1)
                    count++;
            } else {
                int index = stones[i] - 'A';
                if(Jwls[index]==1)
                    count++;
            }
            
        }
        return count;
        
    }
};