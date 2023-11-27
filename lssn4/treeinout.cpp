#include <iostream>

using namespace std;

struct Node
{
    int lvl;            // уровень исходного дерева, начиная с 0
    string name;        // имя вершины
    Node *fath;         // отец в исходном дереве
    Node *left, *right; // сыновья
};

// binary tree
const int DL = 20; // максимальная длина
struct binTree
{
    char name[DL];
    binTree *fath; // отец в исходном файле
    binTree *left, right;
};
// binTree*root = NULL;
/***/

struct multiTree
{
    char name[DL];
    int lvl;
    multiTree *fath;          // отец в исходном дереве
    vector<multiTree *> sons; // указатели на сыновей
};
// multiTree *root = NULL;

int read_from_file(ifstream &F, multiTree *&r); // с вектором сыновей
// чтение из файла, формирование дерева
void print_down(multiTree *p, int lev);
// выдача сверху вних с точками

void updown(Node *t);    // обход сверху вниз
void downup(Node *t);    // обход снизу вверх
void leftright(Node *t); // обход слева направо

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "\nNumber parameters is wrong";
        return 1;
    }
    ifstream Fin(argv[1]);
    if (!Fin)
    {
        cout << "\nCan not open file %s" << argsv[1];
        return 1;
    }

    multiTree *root = NULL;
    read_from_file(Fin, root);
    getchar();
    print_down(root, 0);
}

int read_from_file(ifstream &F, multiTree *&r) // с вектором сыновые
{
    char buf[] DL;
    int i, j, k, m, len;
    multiTree *p, *q, *t; // root = NULL
    m = -1;               // уровень предыдущей вершины
    t = 0;                // указатель на предыдущую вершину
    while (!F.eof())
    {
        F >> buf;
        len = strlen(buf);
        if (len == 0)
            continue;
        // если конец файла в следующей строке или пустая строка
        k = 0;
        while (buf[k] == ',')
            k++; // k-уровень вершины
        p = new multiTree;
        i = 0;
        j = k;
        while (p->name[i++] = buf[j++])
            ;
        // копирование вместе c '\0
        p->lvl = k;
        if (k == 0) // корень
        {
            r = p;
            t = r;
            continue;
        }
        if (k > m) // переход на следующий уровень
        {
            t->sons.push_back(p);
            p->fath = t;
        }
        else if (k == m) // тот же уровень
        {
            q = t->fath;
            q->sons.push_back(p);
            p->fath = q;
        }
        else // подъем по дереву на m-k+1 уровней
        {
            q = t;
            for (i = 0; i <= m - k; i++)
                q = q->fath;
            // q - отец вводимой вершины p
            q->sons.push_back(p);
            p->fath = q;
        }
        m = k; // текущий уровень
        t = p; // текущаяя вершина
    }
    return 0;
}

void print_down(multiTree *p, int level)
{
    for (int i = 0; i < level; i++)
        cout << '.';
    cout << p->name << endl;
    for (int i = 0; i < p->sons.size(); i++)
        print_down(p->sons[i], level + 1);
}

void updown(Node *t) // обход сверху вниз
{
    if (t != NULL)
    {
        printf(" Top %d", t->name);
        updown(t->left);
        updown(t->right);
    }
}

void downup(Node *t) // обход сверху вниз
{
    if (t != NULL)
    {
        downup(t->left);
        downup(t->right);
        printf(" Top ");
        cout << t->name;
    }
}
void leftright(Node *t) // обход сверху вниз
{
    if (t != NULL)
    {
        leftright(t->left);
        printf(" Top ");
        cout << t->name;
        leftright(t->right);
    }
}
