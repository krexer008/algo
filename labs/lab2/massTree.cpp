/*
Ямолкин Ф.В.
ИПС-2023

2 лабораторная
4. В    листьях    дерева,    соответствующего    некоторой
конструкции,  указаны  значения  массы.  Масса  сборного  узла
определяется как сумма масс  составляющих  деталей.  Требуется
определить  значение  массы  для каждого узла конструкции,  не
превосходящего заданного уровня от вершины дерева (9).

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

const int DL = 35; // максимальная длина

// Binary Tree
/*
struct Tree{
    char name[DL];
    Tree *fath;     //отец в исходном дереве
    Tree *left, *right;
};
*/

// MultiBranches Tree
struct Tree
{
    int mass = 0;
    char name[DL];
    int urov;
    Tree *fath;          // отец в исходном дереве
    vector<Tree *> sons; // указатели на сыыновей
};

int read_from_file(ifstream &F, Tree *&r);
// чтениеиз файла, формирование дерева
void print_down(Tree *p, int lev);
// выдача сверху вниз

int main(int argc, char *argv[])
{
    Tree *root = NULL;
    if (argc != 2)
    {
        cout << "\nNumber parameters is wrong";
        return 1;
    }
    ifstream Fin(argv[1]);
    if (!Fin)
    {
        cout << "\nCan not open file %s" << argv[1];
        return 1;
    }
    read_from_file(Fin, root);
    getchar();
    print_down(root, 0);
}

int read_from_file(ifstream &F, Tree *&r) // с вектором сыновей
{
    char buf[DL];
    int i, j, k, m, len;
    Tree *p, *q, *t; // *root = NULL
    m = -1;          // уровень предыдущей вершины
    t = 0;           // указатель на предыдущую вершину
    while (!F.eof())
    {
        F >> buf;
        len = strlen(buf);
        if (len == 0)
            continue;
        // если конец файла в следующей строке или пустая строка
        k = 0;
        while (buf[k] == '.')
            k++; // k-уровень вершины
        p = new Tree;
        i = 0;
        j = k;
        for (i = 0; i < len; i++, j++)
        {
            if (buf[j] != '-')
            {
                p->name[i] = buf[j];
            }
            else if (buf[j] == '-')
            {
                j++;
                int z = len - j - 1;
                char mas[z];
                z = 0;
                while (mas[z++] = buf[j++])
                    ;
                p->mass = std::atoi(mas);
                p->name[i] = '\0';
                break;
            }
        }
        // копирование вместе с '\0’
        p->urov = k; // запись уровня
        if (k == 0)  // корень запишется в root
        {
            r = p;
            t = r;
            m = 0;
            continue;
        }
        if (k > m) // переход на следующий уровень
        {
            t->sons.push_back(p);
            p->fath = t;
            t->mass += p->mass;
        }
        else if (k == m) // тот же уровень
        {
            q = t->fath;
            q->sons.push_back(p);
            p->fath = q;
            q->mass += p->mass;
        }
        else // подъем по дереву на m-k+1 уровней
        {
            q = t;
            for (i = 0; i <= m - k; i++)
                q = q->fath;
            // q - отец вводимой вершины p
            q->sons.push_back(p);
            q->mass += p->mass;
            p->fath = q;
        }
        m = k; // текущий уровень
        t = p; // текущая вершина
    }
    return 0;
}

void print_down(Tree *p, int level)
{
    for (int i = 0; i < level; i++)
        cout << '.';
    cout << p->name << " " << p->mass << endl;
    for (int i = 0; i < p->sons.size(); i++)
        print_down(p->sons[i], level + 1);
}
