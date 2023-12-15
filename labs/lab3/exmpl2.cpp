#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

vector<int> bfs(vector<vector<int>> &graph, int start)
{
    vector<int> dist(graph.size(), INF);
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
                q.push(to);
            }
        }
    }

    return dist;
}

int main()
{
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);

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

    int start, finish;
    cin >> start >> finish;

    vector<int> distFromStart = bfs(graph, start);
    vector<int> distFromFinish = bfs(graph, finish);

    // вывод вершин которые могут быть вершинами кратчайших путей
    /*
    for (int v = 0; v < vertexCount; v++)
        if (distFromStart[v] + distFromFinish[v] == distFromStart[finish])
            cout << v << " ";
            */

    // Переберем ребра графа и проверим что сумма расстояний от концов до единицы равна длине кратчайшего пути
    for (int v = 0; v < vertexCount; v++)
        for (int to : graph[v])
            if (distFromStart[v] + 1 + distFromFinish[to] == distFromStart[finish])
                cout << v << " "
                     << "\n"
}