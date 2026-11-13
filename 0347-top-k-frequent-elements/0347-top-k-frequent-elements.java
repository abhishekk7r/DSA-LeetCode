class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> mp = new HashMap<>();

        for(var i:nums){
            mp.put(i, mp.getOrDefault(i, 0) + 1);
        }

        //Min heap
        PriorityQueue<int []> pq = new PriorityQueue<>((a , b) -> Integer.compare(a[0], b[0]));

        for(var i : mp.entrySet()){
            pq.offer(new int[]{i.getValue(), i.getKey()});
            if(pq.size() > k) pq.poll();
        }

        int [] ans = new int[k];
        int i = 0;
        while(!pq.isEmpty()){
           ans[i] = pq.poll()[1];
           i++;
        }

        return ans;

    }
}