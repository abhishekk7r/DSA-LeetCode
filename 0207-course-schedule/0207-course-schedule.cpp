class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        return (ans.size() == numCourses);
    }
};