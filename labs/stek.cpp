#include <iostream>
using namespace std;

struct St
{
    int key;
    St *next;
};

void push(St *&p, int elem); //включение в стек (p меняется)
void pop(St *&p);            //удаление из стека (p меняется)
void vivod(St *p);           // вывод содержимого стека (p не меняется)
void clear(St *p);           // очистка стека (p не меняется)



int main()
{
    setlocale(LC_ALL, "1251");
    system("cls");
    St *top = 0; // признак пустого стека
    int answer = 1;

    while (answer != 5)
    {
        printf("\n1 Push to stack");
        printf("\n2 Delete from stack");
        printf("\n3 Print stack");
        printf("\n4 Delete all stack");
        printf("\n5 End");
        printf("\nYour change?\n");
        cin >> answer;

        switch (answer)
        {
        case 1: //Включение в стек
            int k;
            printf("Input integer\n");
            cin >> k;
            push(top, k);
            break;
        case 2: //Удаление из стека
            if (top)
            {
                pop(top);
            }
            else
                printf("Stack is empty\n");
            break;
        case 3: //Вывод стека на экран
            if (top)
            {
                vivod(top);
            }
            else
                printf("Stack is empty\n");
            break;
        case 4: //Удаление всего стека
            if (top)
            {
                clear(top);
            }
            else
                printf("Stack is empty\n");
            top = 0; // функция clear() не возвращает top!
            break;
        case 5:         //Конец
            clear(top); // Сначала очистка стека
            top = 0;    // функция clear() не возвращает top!
            break;
        }
    }
    return 0;
}

void push(St *&p, int elem) //включение в стек (p меняется)
{
    St *t = new St;
    t->key = elem;
    t->next = p;
    p = t;
}

void pop(St *&p) //удаление из стека (p меняется)
{
    St *t = p;
    p = p->next;
    delete t;
}

void vivod(St *p) // вывод содержимого стека (p не меняется)
{
    St *t = p;
    while (t)
    {
        printf("%d ", t->key);
        t = t->next;
    }
    printf("\n");
}
void clear(St *p) // очистка стека (p не меняется)
{
    while (p)
    {
        St *t = p;
        p = p->next;
        delete t;
    }
}