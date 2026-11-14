class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[] inDegree = new int[numCourses];
        var adj = new ArrayList<List<Integer>>();
        for (var i = 0; i < numCourses; i++) adj.add(new ArrayList<>());
        for(var i : prerequisites){
            adj.get(i[1]).add(i[0]);
            inDegree[i[0]]++;
        }


        var q = new ArrayDeque<Integer>();

        for(int i = 0; i<numCourses; i++){
            if(inDegree[i] == 0) q.offer(i);
        }

        var order = new int[numCourses];
        var idx = 0;

        while(!q.isEmpty()){
            int curr = q.poll();
            order[idx++] = curr;
            for(var node : adj.get(curr)){
                inDegree[node]--;
                if(inDegree[node] == 0){
                    q.offer(node);
                } 
            }
        }


        return idx == numCourses ? order : new int[0];
    }
}