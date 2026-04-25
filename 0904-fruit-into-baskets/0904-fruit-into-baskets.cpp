class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        if(n == 1) return 1;

        int maxLen = 2;
        unordered_map<int, int> mp;

        mp[fruits[0]]++;
        mp[fruits[1]]++;

        int start = 0, end = 2;
        while(end < n){
            //Add end element to the map
            mp[fruits[end]]++;

            //Check If It is a Valid Window
            while(mp.size() > 2){
                mp[fruits[start]]--;
                if(mp[fruits[start]] == 0) mp.erase(fruits[start]);
                start++;
            }

            maxLen = max(maxLen, end - start + 1);

            end++;
        }

        return maxLen;
    }
};