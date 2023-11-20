#include <iostream>
using namespace std;

struct QueElem
{
    int key;
    QueElem *prev;
    QueElem *next;
};

void push();
void pop();
void show();

int main()
{

    system("cls");
    QueElem *que = NULL;
    int answer = 1;

    while (answer != 4)
    {
        printf("\n1 Push to Queue");
        printf("\n2 Pop from Queue");
        printf("\n3 Show Queue");
        printf("\n4 End");
        printf("\n Enter your change: ");
        cin >> answer;
        switch (answer)
        {
        case 1:
            int k;
            cin >> k;
            push(que, k);
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        }
    }

    return 0;
}

void push(QueElem *&que, int el){
    QueElem *t = que;
};
void pop(){};
void show(){};