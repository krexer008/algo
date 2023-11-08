#include <string.h> // for strcpy_s
#include <iostream>
#include <stdio.h>

struct Stack
{
    std::string name;
    struct Stack *next;
};

Stack *top = NULL;

Stack *push(std::string n)
{
    Stack *ptr = new Stack;

    ptr->name = n;
    ptr->next = top;

    top = ptr;
    return ptr;
}

void pop()
{
    if (top == NULL)
        return;
    Stack *ptr = top->next; // запоминаем указатель на следующий объект
    std::cout << "Stack ";
    std::cout << top->name << " is deleted \n";

    delete top; // удаляем верхний объект стека
    top = ptr;  // перемещаем указатель top вниз на следующий объект
}

void show()
{
    Stack *c = top;
    while (c != NULL)
    {
        std::cout << c->name << " " << std::endl; // вывод текущего объекта
        c = c->next;                              // пер
    }
}

int main()
{

    std::string name = "Ola";
    push(name);

    name = "Bola";
    push(name);

    name = "Rola";
    push(name);

    show();

    while (top != NULL)
        pop();

    return 0;
}