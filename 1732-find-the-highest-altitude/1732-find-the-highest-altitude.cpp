class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int maxi = INT_MIN;
        for(int i=0; i<gain.size(); i++){
            ans += gain[i];
            if(ans>maxi)
                maxi=ans;
        }
        if(maxi>0)
            return maxi;
        else 
            return 0;
    }
};