class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int n = nums.length;

        for(var i:nums){
            mp.put(i, mp.getOrDefault(i, 0) + 1);
        }

        var bucket = new ArrayList<List<Integer>>();

        for(int i=0; i<=n; i++){
            bucket.add(new ArrayList<>());
        }

        for(var i : mp.entrySet()){
            bucket.get(i.getValue()).add(i.getKey());
        }
        
        int [] ans = new int[k];
        var idx = 0;
        for(int i = n; i>0; i--){
            for(var num : bucket.get(i)){
                if(idx == k) return ans;
                ans[idx++] = num;
            }
        }


        return ans;

    }
}