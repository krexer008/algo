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
#include <math.h>
using namespace std;

const int INF = 1e9;

pair<vector<int>, vector<int>> bfs(vector<vector<int>> &graph, int start)
{
    vector<int> dist(graph.size(), INF); // массив растояний
    vector<int> from(graph.size(), -1);  // массив отношений
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

// функция восстанавливающая путь
vector<int> getPath(vector<int> &from, int finish)
{
    // finish - вершина, путь до которой нас интересует
    vector<int> path; // ответ складываем в этот массив
    // встаем на вершину и перемещаемся пока не встретим -1
    for (int v = finish; v != -1; v = from[v])
        path.push_back(v);
    // reverse(path.begin(), path.end());
    return path;
}

int main()
{
    freopen("inputC.txt", "r", stdin);
    freopen("outputC.txt", "w", stdout);

    int vertexCount; // количество вершин в графе
    int edgeCount;   // количество ребер в графе
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount);

    for (int i = 0; i < edgeCount; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        // graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int start;
    cin >> start;
    start--;

    freopen("prodlistC.txt", "r", stdin);
    vector<int> prod(vertexCount, 0);

    int a;
    while (cin >> a)
    {
        a--;
        prod[a] = 1;
    }

    auto [dist, from] = bfs(graph, start);

    int min = INF;
    int indMin = -1;

    // распечатаем вершину
    for (int i = 0; i < dist.size(); i++)
    {
        if ((dist[i] < min) && prod[i])
        {
            indMin = i;
            min = dist[indMin];
        }
    }

    int mult = (pow(1.2, min) - 1) * 100;

    cout << "Near seller number is " << indMin + 1 << "." << endl;
    cout << "Minimum trades count: " << min << "." << endl;
    cout << "Min price in this market = (price + "
         << mult << "%)" << endl;
    cout << "Buy path is : ";
    for (int v : getPath(from, indMin))
        cout << v + 1 << " ";
}