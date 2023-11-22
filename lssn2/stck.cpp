#include <iostream>
using namespace std;

struct St
{
    int data;
    St *next;
};

void push(St *&p, int elem);
void pop(St *&p);
void show(St *p);
void clear(St *p);

int main()
{

    system("cls");
    St *top = 0;
    int answer = 1;

    while (answer != 5)
    {
        printf("\n1 Push to stck");
        printf("\n2 Delete from stck");
        printf("\n3 Print all stck");
        printf("\n4 Clear all stck");
        printf("\n5 End");
        printf("\n Enter your change: ");
        cin >> answer;

        switch (answer)
        {
        case 1:
            int k;
            printf("Input string to stack\n");
            cin >> k;
            push(top, k);
            break;
        case 2:
            if (top)
            {
                pop(top);
            }
            else
            {
                printf("Stack is empty\n");
            }
            break;
        case 3:
            if (top)
            {
                printf("show\n");
                show(top);
            }
            else
            {
                printf("Stack is empty\n");
            }
            break;
        case 4: // Очистка стека
            if (top)
            {
                clear(top);
            }
            else
            {
                printf("Stack is empty\n");
            }
            top = 0;
            break;
        case 5:
            clear(top);
            top = 0;
            break;
        }
    }
    return 0;
}

void push(St *&p, int elem)
{
    St *t = new St;
    t->data = elem;
    t->next = p;
    p = t;
}

void pop(St *&p)
{
    St *t = p;
    p = p->next;
    delete t;
}

void show(St *p)
{
    St *t = p;
    while (t)
    {
        printf("%d", t->data);
        t = t->next;
    }
    printf("\n");
}

void clear(St *p)
{
    while (p)
    {
        St *t = p;
        p = p->next;
        delete t;
    }
}
