/*
 * BFS поиск в ширину
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;

vector<int> bfs(vector<vector<int>> &graph, int start)
{
    vector<int> dist(graph.size(), INF); // массив расстояний
    queue<int> q;                        // очередь

    dist[start] = 0;
    q.push(start);

    // в цикле извлекаем вершину для обработки
    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        // перебираем соседние вершины
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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount);

    // читаем граф в списки смежности
    for (int i = 0; i < edgeCount; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int start;
    cin >> start;

    vector<int> dist = bfs(graph, start);

    // распечатаем полученное расстояние
    for (int d : dist)
    {
        if (d != INF)
            cout << d << " ";
        else
            cout << "X";
    }
}