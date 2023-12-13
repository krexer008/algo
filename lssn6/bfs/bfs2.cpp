/*
 * BFS поиск в ширину
 * оценка сложности О(V + E) - списки смежности
 * оценка слажности О(^2) - матрица смежности
 * Восстановление путей
 * Нахождение кратчайшеого пути
 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

// возвращаем пару массивов
pair<vector<int>, vector<int>> bfs(vector<vector<int>> &graph, int start)
{
    vector<int> dist(graph.size(), INF); // массив растояний
    vector<int> from(graph.size(), -1);  // массив from отношений
    queue<int> q;

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
            if (dist[to] > dist[v] + 1)
            {
                dist[to] = dist[v] + 1; // обновляем растояние на единицу блольше до вершины
                from[to] = v;
                q.push(to); // добавляем его в очередь
            }
        }
    }
    return {dist, from};
}

// функция восстанавливающая путь
vector<int> getPath(vector<int> &from, int finish)
{
    // finish - вершина, путь до которой нас интересует
    vector<int> path; // ответ складываем в этот массив
    // встаем на вершину и перемещаемся пока не встретим -1
    for (int v = finish; v != -1; v = from[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
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

    // выведем кратчайший путь до вершины 4
    for (int v : getPath(from, 4))
        cout << v << " ";
}