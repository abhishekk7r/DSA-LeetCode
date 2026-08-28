class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n%groupSize != 0) return false;

        map<int, int> mp;

        for(auto &i:hand) mp[i]++;

        while(!mp.empty()){

            auto [k, value] = *mp.begin();
            int key = k; // Take the first key
            int count = 0;
            while(count < groupSize){  //try to start seq from that key 
                if(mp[key]) mp[key]--; //if key is present, reduce it
                else return false;

                if(mp[key] == 0) mp.erase(key);
                key++;
                count++;
            }   

            
        }

        return true;
    }
};