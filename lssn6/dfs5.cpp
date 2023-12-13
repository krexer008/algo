/*
 * Поиск компонент связности
 * Расскраска компонент связности в разные цвета
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, int component);

int main()
{
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);

    // читаем количество вершин и количество ребер
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    // вектор векторов для списска смежности нашего графа
    vector<vector<int>> graph(vertexCount);

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

    // vector<int> visited(vertexCount); // определяем массив Visited, где 0 - не посещена, 1 - посещена
    vector<int> visited(vertexCount, -1); // определяем массив Visited, где -1 - не посещена

    // чтобы определить компонент создаем счетчик который мы будем увеличивать при каждом запуске dfs
    int componentCount = 0;

    // запускаем dfs в цикле, от каждой непосещенной вершины
    // каждый запуск будет обрабатывать отдельный компонент связности
    for (int v = 0; v < vertexCount; v++)
        if (visited[v] == -1)
        {
            // componentCount++;
            // dfs(graph, v, visited, componentCount - 1);

            dfs(graph, v, visited, componentCount);
            componentCount++;

            // если граф связанный то в массиве Visited не должно быть -1, если нет так то граф не связанный
        }

    for (int color : visited)
        cout << color << " " << endl;
    // выведем получившееся значение  счетчика
}

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, int component)
{
    visited[v] = component;

    for (int to : graph[v])
        if (visited[to] == -1)
            dfs(graph, to, visited, component);
}