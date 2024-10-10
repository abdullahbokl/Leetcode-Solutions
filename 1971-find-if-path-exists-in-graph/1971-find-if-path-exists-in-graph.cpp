class Solution {
public:


    bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for (auto &edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (node == destination) {
                return true;
            }
            for (int &neighbour: graph[node]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        return false;

    }
};