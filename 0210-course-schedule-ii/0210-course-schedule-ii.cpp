class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        vector<int> indegree(numCourses);

        for(auto i:prerequisites){
            mp[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto &i:mp[node]){
                indegree[i]--;

                if(indegree[i] == 0){
                    q.push(i);
                }
            }

            ans.push_back(node);
        }

        if(ans.size() != numCourses) return {};
        
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