/*
 * BFS поиск в ширину
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;

vector < int bfs(vector<vector<int>> &graph, int start)
{
    vector<int> visited(graph.size());
    vector<int> dist(graph.size(), INF); // массив растояний
    queue<int> q;

    visited[start] = 1;
    dist[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        // извлекаем вершину которую будем обрабатывать
        int v = q.front();
        q.pop();

        // просматриваем всех соседей этой вершины
        for (int to : graph[v])
        {
            // if (visited[to] == 0)
            // {
            //     visited[to] = 1;        // помечаем как посещенную, сразу когда складываем в очередь
            //     dist[to] = dist[v] + 1; // обновляем растояние на единицу блольше до вершины
            //     q.push(to);             // добавляем его в очередь
            // }

            if (dist[to] > dist[v] + 1)
            // if (dist[to] == INF)
            {
                dist[to] = dist[v] + 1; // обновляем растояние на единицу блольше до вершины
                q.push(to);             // добавляем его в очередь
            }
        }
    }
    return dist;
}

int main()
{
}