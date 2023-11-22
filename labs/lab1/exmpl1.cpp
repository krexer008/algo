#include <iostream>
using namespace std;

// узел очереди
struct Node
{
    int data;   // info
    Node *next; // след.элемент
};

struct St
{
    int size;    // счетчик размера очереди
    Node *first; // указатель на начало
    Node *last;  // указатель на конец очереди
    St *next;
};

void push(St *&p);
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
        printf("\n1 Push Queue to stck");
        printf("\n2 Delete from stck");
        printf("\n3 Print all stck");
        printf("\n4 Push to stck");
        printf("\n5 End");
        printf("\n Enter your change: ");
        cin >> answer;

        switch (answer)
        {
        case 1:
            printf("Input new Queue to stack\n");
            push(top);
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
        case 4:
            if (top)
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

void push(St *&p) // создание очереди в стеке
{
    St *t = new St;
    t->first = new Node;
    t->first->next = NULL;
    t->last = t->first;
    t->size = 0;
}

bool isEmpty(Queue *Q) // проверка очереди на пустоту
{
    if (Q->first == Q->last)
        return true;
    else
        return false;
};

int top(Queue *Q) // вывод начального элемента
{
    return Q->first->next->data;
};

void add(Queue *Q) // добавление элемента
{
    int value;
    cout << "\nValue: ";
    cin >> value;
    Q->last->next = new Node;
    Q->last = Q->last->next;
    Q->last->data = value; // добавление элемента в конец
    Q->last->next == NULL; // обнуление указателя на следующий элемент
    Q->size++;
    cout << "\nValue is planted\n";
};

void deleteEl(Queue *Q) // удаление элемента
{
    Q->first = Q->first->next; // смещение указателя
    Q->size--;
};

void clearQ(Queue *Q) // очистка очереди
{
    while (Q->size > 0)
        deleteEl(Q);
};

int sizeQ(Queue *Q) // размер очереди
{
    return Q->size;
}

void showQ(Queue *Q) // выдача элементов очереди
{
    Queue *temp = new Queue();
    temp->first = Q->first;
    temp->last = Q->last;
    temp->size = Q->size;
    while (temp->size > 0)
    {
        cout << top(temp);
        temp->size--; // = temp->size - 1;
        temp->first = temp->first->next;
    }
    cout << "\n END\n";
    delete (temp);
}
