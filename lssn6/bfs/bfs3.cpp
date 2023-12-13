/*
 * BFS поиск в ширину
 * Поиск выхода из лабиринта
 *
 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int bfs(vector<string> &a, int startY, int startX, int finishY, int finishX)
{
    int h = a.size();
    int w = a[0].size();

    vector<vector<int>> dist(h, vector<int>(w, INF));
    queue<pair<int, int>> q; // в очереди будем хранить пары координат

    dist[startY][startX] = 0; // записываем расстояние до стартовой клетки 0
    q.push({startY, startX}); // помещаем начальную клетку в очередь

    // массивы смещений
    vector<int> dy = {-1, 0, 1, 0};
    vector<int> dx = {0, 1, 0, -1};

    // пока очередь не пуста извлекаем координаты клетки
    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();

        // проходим по массивам смещений и вычисляем координаты соседней клетки
        for (int d = 0; d < dy.size(); d++)
        {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < h && 0 <= tx && tx < w &&
                a[ty][tx] != '#' && dist[ty][tx] > dist[y][x] + 1)
            {
                dist[ty][tx] = dist[y][x] + 1;
                q.push({ty, tx});
            }
        }
    }

    return dist[finishY][finishX];
}

int main()
{
    freopen("input3.txt", "r", stdin);
    freopen("output3.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    // прочитаем карту в вектор строк
    vector<string> a(h);
    int startY, startX;
    int finishY, finishX;

    for (int y = 0; y < h; y++)
    {
        cin >> a[y];
        for (int x = 0; x < w; x++)
        {
            if (a[y][x] == 'S')
            {
                startY = y;
                startX = x;
            }
            else if (a[y][x] == 'F')
            {
                finishY = y;
                finishX = x;
            }
        }
    }

    int stepCount = bfs(a, startY, startX, finishY, finishX);

    if (stepCount != INF)
        cout << stepCount;
    else
        cout << "Impossible";
}