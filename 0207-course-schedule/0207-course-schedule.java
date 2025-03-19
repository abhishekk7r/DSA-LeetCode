// import javafx.util.Pair;

class Solution {
    public boolean dfs(int i, int[] visited, int[] pathVis, List<List<Integer>> adj){
        visited[i] = 1;
        pathVis[i] = 1;

        for(int e : adj.get(i)){
            if(visited[e] == 0){
               if(dfs(e, visited, pathVis, adj) == true) return true;
            } else if (pathVis[e] == 1){
                return true;
            }
        }


        pathVis[i] = 0;
        return false;
    }

    // public boolean isCyclic(int n, int[][] prerequisites){
       
    // }
    public boolean canFinish(int numCourses, int[][] prerequisites) {

        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < numCourses; i++) {
            adj.add(new ArrayList<>());
        }

        for (int[] edge : prerequisites) {
            adj.get(edge[0]).add(edge[1]);
        }

        int n = prerequisites.length;
        int[] visited = new int[2000];
        int[] pathVisited = new int[2000];

        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                if(dfs(i, visited, pathVisited, adj) == true) return false;
            }
        }

        return true;

    }
}