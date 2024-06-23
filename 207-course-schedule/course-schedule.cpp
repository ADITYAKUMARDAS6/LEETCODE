class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses);
        queue<int> q;
        int count = 0;

        for(auto course: prerequisites) {
            int a = course[0];
            int b = course[1];
            adj[b].push_back(a);
            inDegree[a]++;
        }

        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()) {

            int node = q.front();
            q.pop();
            count++;

            for(int child: adj[node]) {
                inDegree[child]--;
                if(inDegree[child] == 0)
                    q.push(child);
            }
        }

        return count == numCourses;
    }
};