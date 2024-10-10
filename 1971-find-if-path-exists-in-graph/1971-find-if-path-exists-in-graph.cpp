class Solution {
public:

    vector<vector<int>> graph = vector<vector<int>>();

    bool dfs(int source, int destination, vector<bool> &visited) {
        if (source == destination) {
            return true;
        }
        visited[source] = true;
        for (int i = 0; i < graph[source].size(); i++) {
            if (!visited[graph[source][i]]) {
                if (dfs(graph[source][i], destination, visited)) {
                    return true;
                }
            }
        }
        return false;
    }


    bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
        graph = vector<vector<int>>(n);
        for (auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited = vector<bool>(n, false);
        return dfs(source, destination, visited);

    }
};
