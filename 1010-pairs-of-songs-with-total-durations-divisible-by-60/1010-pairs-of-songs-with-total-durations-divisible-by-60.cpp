class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        // (X + Y) % 60 == 0
        // (y % 60) -> remainder, if that remainder is present in the map, then we have answer

        unordered_map<int, int> freq;

        if((time[0]%60) == 0) freq[0]++;
        else freq[time[0]%60]++;
        int count = 0;

        for(int i=1; i<time.size(); ++i){

            int rem = time[i]%60;
            int needed = (60 - rem)%60;
            //check if rem is present in the map
            if(freq.count(needed)){
                count += freq[needed]; 
            }

            //We add the ele in the map
            freq[rem]++;
        }

        return count;

        //TC = O(N), SC = O(N);
    }
};