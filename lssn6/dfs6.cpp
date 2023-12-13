/*
 * Поиск компонент связности
 * Подсчет колличества островов на карте
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void dfs(vector<string> &a, int y, int x, vector<vector<int>> &visited);

int main()
{
    freopen("input6.txt", "r", stdin);
    freopen("output6.txt", "w", stdout);

    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    vector<vector<int>> visited(h, vector<int>(w));

    int componentCount = 0;

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            if (a[y][x] == '#' && !visited[y][x])
            {
                componentCount++;
                dfs(a, y, x, visited);
            }
        }
    }

    cout << componentCount << endl;
}

void dfs(vector<string> &a, int y, int x, vector<vector<int>> &visited)
{
    visited[y][x] = 1;
    // массивы смещения
    static vector<int> dy = {-1, 0, 1, 0};
    static vector<int> dx = {0, 1, 0, -1};

    // обход соседей
    for (int d = 0; d < dy.size(); d++)
    {
        // координаты соседа
        int ty = y + dy[d];
        int tx = x + dx[d];

        if (0 <= ty && ty < a.size() &&
            0 <= tx && tx < a[ty].size() && // не выходит ли за границы карты
            a[ty][tx] == '#' &&             // является ли 1 (суша)
            !visited[ty][tx])               // не посещенность вершины
            dfs(a, ty, tx, visited);
    }
}