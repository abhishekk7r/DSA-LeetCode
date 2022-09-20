class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int ans = 0;
        int maxi = 0;
        for(int i=0; i<gain.size(); i++){
            ans += gain[i];
            if(ans>maxi)
                maxi=ans;
        }
        return maxi;
    }
};