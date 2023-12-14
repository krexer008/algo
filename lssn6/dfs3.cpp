/*
 * Поиск компонент связности
 * Проверка связности графа
 * Верно ли что в нашем неориентированном графе от каждой вершины
 * можно добраться до всех остальных
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited)
{
    visited[v] = 1;

    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited);
}

int main()
{
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);

    // читаем количество вершин и количество ребер
    int vertexColunt, edgeCount;
    cin >> vertexColunt >> edgeCount;

    // вектор векторов для списска смежности нашего графа
    vector<vector<int>> graph(vertexColunt);

    // считываем концы ребер и добавляем их в граф
    for (int i = 0; i < edgeCount; i++)
    {
        int a, b;
        cin >> a >> b;
        // перевод вершин в 0 индексацию
        a--;
        b--;
        // добавляем ребра в граф, дважды
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> visited(vertexColunt); // определяем массив Visited, где 0 - нет, 1 - есть
    dfs(graph, 0, visited);
    // если граф связанный то в массиве Visited не должно быть 0, если нет так то граф не связанный

    if (find(visited.begin(), visited.end(), 0) == visited.end())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
