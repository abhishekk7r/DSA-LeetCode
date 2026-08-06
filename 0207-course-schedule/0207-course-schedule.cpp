class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);

        //Create edges to a node & find indegree of every node
        for(auto &i:prerequisites){
            graph[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }

        //Create Queue
        //Add those elements whoes indegree is 0
        queue<int> q;
        
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        //Create answer array
        int count = 0;


        //Process those nodes whose indegree is 0,
        //redeuce the indegree of those node who are connected to current node.
        //as we are removing one edge
        //If indegree becomes 0, add them
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(int curr:graph[node]){
                indegree[curr]--;
                if(indegree[curr] == 0) q.push(curr);
            }
        }

        //if size of answer == numsCourses this means we can take all course
        return count == numCourses;
    }
};