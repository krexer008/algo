#include <iostream>
#include <conio.h>
int getch();
using namespace std;

struct Node
{
    string key;
    Node *left;
    Node *right;
};

void makeT(Node *t);
void todown(Node *t);
void toup(Node *t);
void toright(Node *t);

int main()
{
    system("cls");
    Node *root = new Node;
    makeT(root);
    cout << "Tree is maked!" << endl;
    getch();
    cout << endl;

    todown(root);
    cout << "Print to down";
    getch();
    cout << endl;
    cout << endl;

    toup(root);
    cout << "Print to up";
    getch();
    cout << endl;
    cout << endl;

    toright(root);
    cout << "Print up to right";
    getch();
}

void todown(Node *t)
{
    if (t != NULL)
    {
        //cout << "Top is " << t->key << " ";
        cout << t->key << " - ";
        todown(t->left);
        todown(t->right);
    }
}

void toup(Node *t)
{
    if (t != NULL)
    {
        toup(t->left);
        toup(t->right);
        //cout << "Top is " << t->key << " ";
        cout << t->key << " - ";
    }
}

void toright(Node *t)
{
    if (t != NULL)
    {
        toright(t->left);
        //cout << "Top is " << t->key << " ";
        cout << t->key << " - ";
        toright(t->right);
    }
}

void makeT(Node *t)
{
    char pr;
    if (t != NULL)
    {
        cout << "Enter top value ";
        cin >> t->key;
        cout << "\nDoes top " << t->key << " have left son, y/n? - ";
        cin >> pr;
        cout << endl;
        if (pr == 'n')
        {
            t->left = NULL;
        }
        else
        {
            cout << "Move to the left son of top: " << t->key<< " " << endl;
            Node *kon = new Node;
            t->left = kon;
        };
        makeT(t->left);
        cout << "\nDoes top " << t->key << " have right son, y/n? - ";
        cin >> pr;
        cout << endl;
        if (pr == 'n')
        {
            t->right = NULL;
        }
        else
        {
            cout << "Move to the right son of top: " << t->key<< " " << endl;
            Node *kon = new Node;
            t->right = kon;
        };
        makeT(t->right);
    }
}