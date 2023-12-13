#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// struct Edge
// {
//     int to, weight;
// };

int main()
{
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;
    // vector<vector<Edge>> graph(vertexCount);
    vector < vector<pair<int, int>> graph(vertexCount);
    // pair <номер вершины в которое ведет ребро, число вес ребра>
    for (int i = 0; i < edgeCount; i++)
    {
        int a, b, weight;
        cin >> a >> b >> weight;
        // a--;
        // b--;
        graph[a].push_back({b, weight}); // при ориентированном графе добавляем каждое ребро один раз
        graph[b].push_back({a, weight});
    }

    int start; // начальная вершина
    cin >> start;
    // start--; // начальная вершина в графе с индексами от 0
}

1.38