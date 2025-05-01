#include <vector>
#include <iostream>
#include <map>

using namespace std;

bool dfs(int i, int j, map<vector<int>, vector<vector<int>>>& graph, vector<vector<bool>>& vis, vector<vector<int>>& path) {
    path.push_back({i, j});
    vis[i][j] = true;
    if (path.size() == 16) return true;
    for (auto& nei : graph[{i, j}]) {
        if (!vis[nei[0]][nei[1]]) {
            if (dfs(nei[0], nei[1], graph, vis, path)) {
                return true;
            }
        }
    }
    path.pop_back();
    vis[i][j] = false;
    return false;
}

int main() {
    map<vector<int>, vector<vector<int>>> graph;
    graph[{0, 0}] = {{0, 1}};
    graph[{0, 1}] = {{1, 0}};
    graph[{0, 2}] = {{0, 1}, {0, 3}};
    graph[{0, 3}] = {{1, 2}};
    graph[{1, 0}] = {{2, 1}};
    graph[{1, 1}] = {{0, 0}};
    graph[{1, 2}] = {{1, 1}, {1, 3}};
    graph[{1, 3}] = {{0, 2}};
    graph[{2, 0}] = {{1, 0}, {3, 0}};
    graph[{2, 1}] = {{2, 0}, {2, 2}};
    graph[{2, 2}] = {{1, 1}};
    graph[{2, 3}] = {{1, 3}, {3, 3}};
    graph[{3, 0}] = {{3, 1}};
    graph[{3, 1}] = {{2, 2}};
    graph[{3, 2}] = {{2, 3}};
    graph[{3, 3}] = {{3, 2}};
    vector<vector<bool>> vis(4, vector<bool>(4));
    vector<vector<int>> path;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (dfs(i, j, graph, vis, path)) {
                for (auto& ele : path) {
                    cout << ele[0] << " " << ele[1] << endl;
                }
            }
        }
    }
    return 0;
}
