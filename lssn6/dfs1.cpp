#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

// граф задан списками смежности  сложность O(V + E), случай неориентированного графа
void dfs(vector<vector<int>> &graph, int v, vector<int> &visited)
{
    /*
     * v (vertex) - текущая вершина графа
     * visited (vector<int>) - массив, для отметок посещенных вершин графа
     */
    visited[v] = 1; // помечаем как посещенную

    for (int to : graph[v])
        if (!visited[to]) // если вершина не посещена, visited = 0
            dfs(graph, to, visited);
}

// граф задан матрицей смежности, случай ориентированного графа, сложность O(V^2)
void dfs(vector<vector<int>> &graph, int v, vector<int> &visited)
{
    visited[v] = 1; // помечаем как посещенную

    for (int to = 0; to < graph[v].size(); to++)
        if (graph[v][to] && !visited[to])
            dfs(graph, to, visited);
}

int main()
{
    for (int v = 0; v < graph.size(); v++)
    // запускаем пееребор всех вершин графа, если вершина не посещена, то посещаем ее
    {
        if (!visited[v])
            dfs(graph, v, visited);
    }
}