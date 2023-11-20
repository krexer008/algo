#include <iostream>
using namespace std;

void push(char stck[], int t, char a)
{
    t++;
    stck[t] = a;
}

void pop(char stck[], int t, char *&pr, char ch)
{
    *pr = 'o';
    if (t == 0)
    {
        *pr = 'e';
    }
    else
    {
        switch (ch)
        {
        case ')':
            if (stck[t] != '(')
                *pr = 'e';
            break;
        case ']':
            if (stck[t] != '[')
                *pr = 'e';
            break;
        case '}':
            if (stck[t] != '{')
                *pr = 'e';
            break;
        default:
            break;
        }
    }
    if (*pr != 'e')
    {
        t--;
    }
}

int main()
{
    char stek[80];
    int i, n, top, kon;
    char a, b;
    system("cls");
    string s;

    top = 0;

    char a;
    char r = 'o';
    char *pr {&r};
    cout << "Enter some formula" << endl;
    cin >> s;
    char formula[s.length()];

    strcpy(formula, s.c_str());

    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        a = formula[i];
        switch (a)
        {
        case '(':;
        case '[':;
        case '{':
            push(stek, top, a);
            break;
        case ')':;
        case ']':;
        case '}':            
            pop(stek, top, pr, a);
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