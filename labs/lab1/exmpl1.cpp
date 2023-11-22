#include <iostream>
#include <string>

using namespace std;

// узел очереди
struct Node
{
    int data;   // info
    Node *next; // след.элемент
};

struct St
{
    string name;
    int size;    // счетчик размера очереди
    Node *first; // указатель на начало
    Node *last;  // указатель на конец очереди
    St *next;
};

void push(St *&p, string name); // добавление очереди в стек
void pop(St *&p);               // удаление очереди из стека
void show(St *p);               // вывод всего стека
void clear(St *p);              // очистка всего стека

void deleteEl(St *p); // удаление элемента из очереди
void clearQ(St *p);   // очистка очереди
bool isEmpty(St *p);  // проверка очереди на пустоту
void showQ(St *Q);    // вывод всей очереди
int top(St *Q);       // получение начального элемента очереди
void add(St *Q);      // добавление в очередь
int sizeQ(St *Q);     // получение размера очереди

void queuMenu(St *p); // menu очереди

int main()
{
    system("cls");
    St *top = 0;

    int answer = 1;
    string name = "S";
    int nameId = 0;
    string queName = "";

    while (answer != 6)
    {
        printf("\n1 Push New Queue to stck");
        printf("\n2 Delete Queue from stck");
        printf("\n3 Print all stck");
        printf("\n4 Clear all stck");
        printf("\n5 Queue menu");
        printf("\n6 End");
        printf("\n Enter your change: ");
        cin >> answer;

        switch (answer)
        {
        case 1: // Добавить очередь в стек
            printf("Input new Queue to stack\n");
            queName = name + to_string(++nameId);
            push(top, queName);
            break;
        case 2: // Удалить очередь из стека
            if (top)
            {
                pop(top);
            }
            else
            {
                printf("Stack is empty\n");
            }
            break;
        case 3: // Показать все элементы стека
            if (top)
            {
                printf("Show all stack\n");
                show(top);
            }
            else
            {
                printf("Stack is empty\n");
            }
            break;
        case 4: // Очистить стек
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
            queuMenu(top);
            break;
        case 6: // Выход
            clear(top);
            top = 0;
            break;
        default:
            printf("\n Enter correct change");
            break;
        }
    }
    return 0;
}

void push(St *&p, string name) // создание очереди в стеке
{
    St *t = new St;
    t->first = new Node;
    t->first->next = NULL;
    t->last = t->first;
    t->size = 0;
    t->name = name;
    t->next = p;
    p = t;
}

void pop(St *&p) // удаление очереди из стека
{
    St *t = p;
    p = p->next;
    if (!(isEmpty(t)))
    {
        clearQ(t);
    };
    delete t;
}

bool isEmpty(St *p) // проверка очереди на пустоту
{
    if (p->first == p->last)
        return true;
    else
        return false;
};

void deleteEl(St *p) // удаление элемента из очереди
{
    Node *t = p->first;
    p->first = p->first->next; // смещение указателя
    p->size--;
    delete (t);
};

void clearQ(St *p) // очистка очереди
{
    while (p->size > 0)
        deleteEl(p);
};

void show(St *p) // Вывод всего стека
{
    St *t = p;
    while (t)
    {
        cout << t->name << ":" << endl;
        showQ(t);
        cout << endl;
        t = t->next;
    }
    printf("\n");
}

void showQ(St *Q) // выдача элементов очереди
{
    St *temp = new St();
    temp->first = Q->first;
    temp->last = Q->last;
    temp->size = Q->size;
    while (temp->size > 0)
    {
        cout << top(temp);
        temp->size--;
        temp->first = temp->first->next;
    }
    cout << "\n END\n";
    delete (temp);
}

int top(St *Q) // вывод начального элемента
{
    return Q->first->next->data;
};

void add(St *Q) // добавление элемента
{
    int value;
    cout << "\nValue: ";
    cin >> value;
    Q->last->next = new Node;
    Q->last = Q->last->next;
    Q->last->data = value; // добавление элемента в конец
    Q->last->next == NULL; // обнуление указателя на следующий элемент
    Q->size++;
    cout << "\nValue is planted еto Queue\n";
};

int sizeQ(St *Q) // размер очереди
{
    return Q->size;
}

void queuMenu(St *p) // работа с очередью
{
    int answer = 1;
    while (answer != 7)
    {
        system("cls");
        printf("\n1 Add to Queue");
        printf("\n2 Show Queue first Element");
        printf("\n3 Show Queue Elements");
        printf("\n4 Queue size");
        printf("\n5 Delete from Queue");
        printf("\n6 Clear Queue");
        printf("\n7 End");
        printf("\n Enter your change: ");
        cin >> answer;
        switch (answer)
        {
        case 1: // добавление элемента
            add(p);
            break;
        case 2: // вывод начального элемента
            if (isEmpty(p))
                cout << "\nQueue is empty\n";
            else
            {
                cout << "\n First Element: " << top(p) << "\n";
            }
            break;
        case 3: // печать всей очереди
            if (isEmpty(p))
                cout << "\nQueue is empty\n";
            else
                showQ(p);
            break;
        case 4: // размер очереди
            if (isEmpty(p))
                cout << "\nQueue is empty\n";
            else
                cout << "\nQueue size: " << sizeQ(p) << "\n";
            break;
        case 5: // удаление элемента
            if (isEmpty(p))
                cout << "\nQueue is empty\n";
            else
                deleteEl(p);
            cout << "\nElement deleted\n";
            break;
        case 6: // очистка очереди
            if (isEmpty(p))
                cout << "\nQueue is empty\n";
            else
            {
                clearQ(p);
                cout << "\nQueue cleared\n";
            }
            break;
        case 7:
            break;
        default:
            cout << "\nCommand not changed\n";
            break;
        }
        system("pause");
    }
    cout << "\nProgram is end\n";
}