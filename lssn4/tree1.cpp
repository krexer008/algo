#include <iostream>

using namespace std;

struct Node
{
    char key;
    int lvl;            // уровень исходного дерева, начиная с 0
    string name;        // имя вершины
    Node *fath;         // отец в исходном дереве
    Node *left, *right; // сыновья
};

void updown(Node *t);    // обход сверху вниз
void downup(Node *t);    // обход снизу вверх
void leftright(Node *t); // обход слева направо

int main()
{
    Node *root, *kon;
}

void updown(Node *t) // обход сверху вниз
{
    if (t != NULL)
    {
        printf(" Top %d", t->key);
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
        printf(" Top %d", t->key);
    }
}
void leftright(Node *t) // обход сверху вниз
{
    if (t != NULL)
    {
        leftright(t->left);
        printf(" Top %d", t->key);
        leftright(t->right);
    }
}
