/*
поиск кратчайших путей в графе
Восстановление пути
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

pair<vector<int>, vector<int>> bfs(vector<vector<int>> &graph, int start)
{
    vector<int> dist(graph.size(), INF);
    vector<int> from(graph.size(), -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (int to : graph[v])
        {
            if (dist[to] > dist[v] + 1)
            {
                dist[to] = dist[v] + 1;
                from[to] = v;
                q.push(to);
            }
        }
    }

    return {dist, from};
}

vector<int> getPath(vector<int> &from, int finish)
{
    vector<int> path;
    for (int v = finish; v != -1; v = from[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount; // количество вершин в графе
    int edgeCount;   // количество ребер в графе
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount);

    for (int i = 0; i < edgeCount; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int start;
    cin >> start;

    auto [dist, from] = bfs(graph, start);

    // распечатаем полученное расстояние

    for (int v : getPath(from, 4))
        cout << v << " ";
}