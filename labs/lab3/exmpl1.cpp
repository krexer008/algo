/*
* Ямолкин Ф.В. ИПС-2023
* Лабораторная 3

8. Имеется  информация о торговых связях предпринимателей в
виде множества пар (A,B),  где A - продавец, а B - покупатель.
Покупатели  сами являются продавцами и перепродают закупленный
товар в соответствии со своими связями с  наценкой 20 %. Задан
список    предпринимателей,    получивших   некоторый   товар.
Поиском в ширину определить такой способ получения этого товара
указанным предпринимателем, чтобы наценка была минимальной (8).
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
    vector<int> prod(vertexCount, 0);
    for (int i = 0; i < edgeCount; i++)
    {
        int a;
        cin >> a;
        prod.push_back(a);
    }

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