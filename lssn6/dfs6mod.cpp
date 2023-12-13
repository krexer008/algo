/*
 * Поиск компонент связности
 * Подсчет колличества островов на карте
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void dfs(vector<string> &a, int y, int x, int component); // раскрасим острова

int main()
{
    freopen("input6.txt", "r", stdin);
    freopen("output6.txt", "w", stdout);

    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    int componentCount = 0;

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            if (a[y][x] == '#')
            {
                componentCount++;
                dfs(a, y, x, componentCount);
            }
        }
    }

    for (string &row : a)
    {
        cout << row << endl;
    }
}

void dfs(vector<string> &a, int y, int x, int component)
{
    a[y][x] = 'A' + component - 1; // во всех клетках соответствующих 1 компоненте связности записываем 'A', для 2 - 'B', 3 - 'C'
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
            0 <= tx && tx < a[ty].size() &&
            a[ty][tx] == '#')

            // не выходит ли за границы карты      // является ли 1 (суша) и не посещали
            dfs(a, ty, tx, component); // раскрасим острова
    }
}
