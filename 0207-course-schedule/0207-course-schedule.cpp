class Solution {
private:
    bool dfs(vector<vector<int>> &graph, set<int> &vis, int course) {
        if (vis.count(course)) return false;
        if (graph[course].empty()) return true;


        vis.emplace(course);
        for (auto c: graph[course]) {
            if (!dfs(graph, vis, c)) return false;
        }
        vis.erase(course);

        graph[course] = {};
        return true;
    }


public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        // prepare the graph
        vector<vector<int>> graph(numCourses);
        for (auto pReq: prerequisites) graph[pReq[0]].emplace_back(pReq[1]);

        set<int> vis;

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(graph, vis, i)) return false;
        }

        return true;
    }
};
