class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /*for(int i=0; i<m; i++){
            nums1[i+m]=nums2[i];
        }
        sort(nums1.begin(), nums1.end());*/
        int i=0;
        int j=0;
        vector <int> v1;
        while(i<m && j<n){
             if(nums1[i]<nums2[j]){
                 v1.push_back(nums1[i]);
                 i++;
             } else {
                 v1.push_back(nums2[j]);
                 j++;
             }
         }
       while(i<m){
           v1.push_back(nums1[i]);
           i++;
       } 
        while(j<n){
            v1.push_back(nums2[j]);
            j++;
        }
        nums1 = v1;
    }
};