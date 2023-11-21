#include <iostream>
using namespace std;

// узел очереди
struct Node
{
    int data;   // info
    Node *next; // след.элемент
};

// указатели на начало и конец очереди
struct Queue
{
    int size;    // счетчик размера очереди
    Node *first; // указатель на начало
    Node *last;  // указатель на конец очереди
};

void creation(Queue *Q); // создание очереди
bool isEmpty(Queue *Q);  // проверка очереди на пустоту
int top(Queue *Q);       // вывод начального элемента
void add(Queue *Q);      // добавление элемента
void deleteEl(Queue *Q); // удаление элемента
void clearQ(Queue &Q);   // очистка очереди
int sizeQ(Queue *Q);     // размер очереди
void outputQ(Queue *Q);  // печать очереди

int main()
{

    system("cls");
    Queue Q;
    creation(&Q);
    int answer = 1;

    while (answer != 7)
    {
        system("cls");
        printf("\n1 Add to Queue");
        printf("\n2 Show Queue first Element");
        printf("\n3 Show Queue Elements");
        printf("\n4 Queue size");
        printf("\n5 Delete from Queue");
        printf("\n6 Delete all elements from Queue"); // доделать
        printf("\n7 End");
        printf("\n Enter your change: ");
        cin >> answer;
        switch (answer)
        {
        case 1:
            add(&Q);
            break;
        case 2:
            if (isEmpty(&Q))
                cout << endl
                     << "Queue is empty";
            else
            {
                cout << "\n First Element: " << top(&Q) << "\n\n";
            }
            system("pause");
            break;
        case 3:
            if (isEmpty(&Q))
                cout << endl
                     << "Queue is empty";
            else
                outputQ(&Q);
            system("pause");
            break;
        case 4:
            if (isEmpty(&Q))
                cout << endl
                     << "Queue is empty";
            else
                cout << "\nQueue size: " << sizeQ(&Q) << "\n\n";
            system("pause");
            break;
        case 5:
            if (isEmpty(&Q))
                cout << endl
                     << "Queue is empty";
            else
                deleteEl(&Q);
            break;
        case 6: // Delete all elements
            clearQ(&Q);
            break;
        case 7:
            break;
        default:
            cout << endl
                 << "Command not changed\n\n";
            system("pause");
            break;
        }
    }
    return 0;
}

void creation(Queue *Q) // создание очереди
{
    Q->first = new Node;
    Q->first->next = NULL;
    Q->last = Q->first;
    Q->size = 0;
};

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
    cout << "\nValue is planted\n\n";
};

void deleteEl(Queue *Q) // удаление элемента
{
    Q->first = Q->first->next; // смещение указателя
    Q->size--;
    cout << "\nElement deleted\n\n";
};

void clearQ(Queue &Q) // очистка очереди
    {};

int sizeQ(Queue *Q) // размер очереди
{
    return Q->size;
}

void outputQ(Queue *Q) // выдача элементов очереди
{
    Queue *temp = Q;
    int siz = sizeQ(Q);
    while (temp->last != 0)
    {
        cout << top(temp);
        temp->first = temp->first->next;
    }

    cout << "\n";
}