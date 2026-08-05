class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;

        //Edge Case Empty Array
        // if(prerequisites.size() == 0) return ans;

        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        //create adjacency list
        
        for(auto &i:prerequisites){
            int u = i[0];
            int v = i[1];

            graph[v].push_back(u);
            indegree[u]++; //[2, 1, 1, 0];
        }

        queue<int> q;

        //push nodes having indegree is 0
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        } 

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto &i:graph[node]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }

        }

        if(numCourses != ans.size()) return {};
        return ans;
    }
};


/*
[[1,0]]
numCourses = 2

[[1,0],[2,0],[3,1],[3,2]]
numCourses = 4

arr[1] -> arr[0]
0 -> 1, 2 ---> Indgree = 2
1 -> 3 ----> Indegree = 1
2 -> 3 ----> Indegree = 1
*/