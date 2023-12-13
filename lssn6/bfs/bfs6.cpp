/*
 * BFS поиск в ширину
 * Поиск выхода из лабиринта c несколькими выходами
 * Нарисуем кратчайший путь
 * Выбираем ближайший выход
 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int bfs(vector<string> &a, vector<pair<int, int>> &startCells, vector<pair<int, int>> &finishCells)
{
    int h = a.size();
    int w = a[0].size();

    vector<vector<int>> dist(h, vector<int>(w, INF));
    // массив from для пары координат
    vector<vector<pair<int, int>>> from(h, vector<pair<int, int>>(w, {-1, -1}));
    queue<pair<int, int>> q; // в очереди будем хранить пары координат

    // пробегаем по всем стартовым клеткам
    for (auto &[startY, startX] : startCells)
    {
        // записываем для них расстояние 0
        dist[startY][startX] = 0;
        // складываем в очередь
        q.push({startY, startX});
    }

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
                from[ty][tx] = {y, x};
                q.push({ty, tx});
            }
        }
    }
    // Определим сначала координаты выхода
    // расстояние до которого является наименьшим

    auto [finishY, finishX] = finishCells[0];
    for (auto &[y, x] : finishCells)
    {
        finishY = y;
        finishX = x;
    }

    // Рисуем кратчайший путь
    if (dist[finishY][finishX] != INF)
    {
        int y = finishY;
        int x = finishX;

        while (y != -1 && x != -1)
        {
            a[y][x] = '*';
            auto [py, px] = from[y][x];
            y = py;
            x = px;
        }
    }

    return dist[finishY][finishX];
}

int main()
{
    freopen("input5.txt", "r", stdin);
    freopen("output5.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    // прочитаем карту в вектор строк
    vector<string> a(h);
    // массив входов, для стартовых клеток
    vector<pair<int, int>> startCells;
    int startY, startX;
    // массив выходов, для финишных клеток
    vector<pair<int, int>> finishCells;

    for (int y = 0; y < h; y++)
    {
        cin >> a[y];
        for (int x = 0; x < w; x++)
        {
            if (a[y][x] == 'S')
            {
                startCells.push_back({y, x});
            }
            else if (a[y][x] == 'F')
            {
                finishCells.push_back({y, x});
            }
        }
    }

    int stepCount = bfs(a, startCells, finishCells);

    if (stepCount != INF)
    {
        cout << stepCount << endl;
        for (string &row : a)
            cout << row << endl;
    }
    else
        cout << "Impossible";
}