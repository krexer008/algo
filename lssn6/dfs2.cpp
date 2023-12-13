/*
 * Поиск компонент связности
 * Проверка достижимости
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfsM(vector<vector<int>> &graph, int v, vector<int> &visited, int component);

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited);

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

    int start, finish;
    cin >> start >> finish;
    start--;
    finish--;

    vector<int> visited(vertexColunt); // определяем массив Visited, где 0 - нет, 1 - есть
    dfs(graph, start, visited);

    if (visited[finish] == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

void dfsM(vector<vector<int>> &graph, int v, vector<int> &visited, int component)
{
    visited[v] = component;
    for (int to : graph[v])
        if (!visited[to])
            dfsM(graph, to, visited, component);
}

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited)
{
    visited[v] = 1;

    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited);
}