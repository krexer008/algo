#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Tree
{
    string name;
    int urov;
    int w;             // вес
    Tree *fath;        // отец в исходном файле
    vector<Tree> sons; // указатели на сыновей
};

int read_from_file(ifstream &F, Tree *&r);
// чтение из файла, формирование дерева

void count_wn(Tree *p); // расчет сумм

void print_down(ofstream &F, Tree *p, int lev);
// выдача сверху вниз

void print_up(ofstream &F, Tree *p, int lev);
// выдача снизу вверх

void free_tree(Tree *&p);
// освобождение памяти

int main()
{
}

// Суммирование во время прохода снизу вверх
void count_wn(Tree *p)
{
    for (int i = 0; i < p->sons.size(); i++)
    {
        count_wn(p->sons[i]);
        p->w += p->sons[i]->w;
    }
}

void print_down(ofstream &F, Tree *p, int level) // сверху вниз с точками
{
    for (int i = 0; i < level; i++)
        F << '.';
    F << p->name;
    if (p->w)
        F << ' ' << p->w;
    F << endl;
    for (int i = 0; i < p->sons.size(); i++)
        print_down(F, p->sons[i], level + 1);
}

void print_up(ofstream &F, Tree *p, int level) // снизу вверх с точками
{
    for (int i = 0; i < p->sons.size(); i++)
        print_up(F, p->sons[i], level + 1);
    for (int i = 0; i < level; i++)
        F << '.';
    F << p->name;
    if (p->w)
        F << ' ' << p->w;
    F << endl;
}

void free_tree(Tree *&p) // освобождение ОП
{
    for (int i = 0; i < p->sons.size(); i++)
        free_tree(p->sons[i]);
    delete p;
    p = nullptr;
}
