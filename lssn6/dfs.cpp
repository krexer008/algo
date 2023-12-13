#include <iostream>

using namespace std;

// Функция поиска в глубину dfs
void Depth_First_Search(int n, int **Graph, bool *Visited, int Node)
{
    Visited[Node] = true;
    cout << Node << endl;
    for (int i = 0; i < n; i++)
    {
        if (Graph[Node][i] && Visited[i] == false)
        {
            Depth_First_Search(n, Graph, Visited, i);
        }
    }
}