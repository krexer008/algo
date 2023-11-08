#include <iostream>
#include <cstring>
using namespace std;

struct St
{
    char ch;
    St *next;
};

void push(St *&p, char ch);         // включение в стек (p меняется)
void pop(St *&p, char *pr, char ch); // удаление из стека (p меняется)

int main()
{
    system("cls");
    string s;

    char a;
    char r = 'o';
    char *pr {&r};
    cout << "Enter some formula" << endl;
    cin >> s;

    char formula[s.length()];

    strcpy(formula, s.c_str());

    St *top = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        a = formula[i];
        switch (a)
        {
        case '(':;
        case '[':;
        case '{':
            push(top, a);
            break;
        case ')':;
        case ']':;
        case '}':            
            pop(top, pr, a);
            if (*pr == 'e')
            {
                cout << "closed brackets" << endl;
                cout << a << endl;
                cout << "Error in position ";
                cout << i+1 << endl;
                return 0;
            }
            break;
        }
    }
    if (top != 0)
    {
        cout << "Need close bracket" << endl;
    }
    else
    {
        cout << "All correct" << endl;
    }
    system("pause");
    return 0;
}

void push(St *&p, char ch)
{
    St *t = new St;
    t->ch = ch;
    t->next = p;
    p = t;
}

void pop(St *&p, char *pr, char ch)
{
    // pr = 'e' признак ошибки
    *pr = 'o';
    if (p == 0)
    {
        *pr = 'e';
    }
    else
    {
        switch (ch)
        {
        case ')':
            if (p->ch != '(')
                *pr = 'e';
            break;
        case ']':
            if (p->ch != '[')
                *pr = 'e';
            break;
        case '}':
            if (p->ch != '{')
                *pr = 'e';
            break;
        default:
            break;
        }
    }
    if (*pr != 'e')
    {
        St *t = p;
        p = p->next;
        delete t;
    }
}