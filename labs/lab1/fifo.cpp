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
void clearQ(Queue *Q);   // очистка очереди
int sizeQ(Queue *Q);     // размер очереди
void showQ(Queue *Q);    // печать очереди

int main()
{

    system("cls");
    Queue Q;

    creation(&Q); // создание очереди
    int answer = 1;

    while (answer != 7)
    {
        system("cls");
        printf("\n1 Add to Queue");
        printf("\n2 Show Queue first Element");
        printf("\n3 Show Queue Elements");
        printf("\n4 Queue size");
        printf("\n5 Delete from Queue");
        printf("\n6 Clear Queue"); // доделать
        printf("\n7 End");
        printf("\n Enter your change: ");
        cin >> answer;
        switch (answer)
        {
        case 1: // добавление элемента
            add(&Q);
            break;
        case 2: // вывод начального элемента
            if (isEmpty(&Q))
                cout << "\nQueue is empty\n";
            else
            {
                cout << "\n First Element: " << top(&Q) << "\n";
            }
            break;
        case 3: // печать всей очереди
            if (isEmpty(&Q))
                cout << "\nQueue is empty\n";
            else
                showQ(&Q);
            break;
        case 4: // размер очереди
            if (isEmpty(&Q))
                cout << "\nQueue is empty\n";
            else
                cout << "\nQueue size: " << sizeQ(&Q) << "\n";
            break;
        case 5: // удаление элемента
            if (isEmpty(&Q))
                cout << "\nQueue is empty\n";
            else
                deleteEl(&Q);
            cout << "\nElement deleted\n";
            break;
        case 6: // очистка очереди
            if (isEmpty(&Q))
                cout << "\nQueue is empty\n";
            else
            {
                clearQ(&Q);
                cout << "\nQueue cleared\n";
            }
            break;
        case 7:
            clearQ(&Q);
            break;
        default:
            cout << "\nCommand not changed\n";
            break;
        }
        system("pause");
    }
    cout << "\nProgram is end\n";
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