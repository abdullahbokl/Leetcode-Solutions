class Solution {
public:

    vector<vector<int>> graph = vector<vector<int>>();
    vector<bool> visited =  vector<bool>();

    bool dfs(int source, int destination) {
        if (source == destination) {
            return true;
        }
        visited[source] = true;
        for (int i: graph[source]) {
            if (!visited[i]) {
                if (dfs(i, destination)) {
                    return true;
                }
            }
        }
        return false;
    }


    bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
        graph = vector<vector<int>>(n);
        visited = vector<bool>(n, false);
        for (auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return dfs(source, destination);

    }
};
