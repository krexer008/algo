#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited,
         vector<int> &order)
{
    // vector<int> &order - сохраняем топологическую сортировку
    visited[v] = 1;

    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited, order);

    order.push_back(v);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<string> vertexName(vertexCount);
    for (string &name : vertexName)
        cin >> name;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
    }

    vector<int> visited(vertexCount);
    vector<int> order;

    for (int v = 0; v < vertexCount; v++)
        if (!visited[v])
            dfs(graph, v, visited, order);

    reverse(order.begin(), order.end());

    for (int v : order)
        cout << vertexName[v] << endl;
}