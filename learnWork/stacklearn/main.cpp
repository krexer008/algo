#include <string.h> // for strcpy_s
#include <iostream>
#include <stdio.h>

struct Stack
{
    std::string name;
    struct Stack *next;
};

Stack *top = NULL;

Stack *push()
{
    std::cout << "1 - push(top)" << std::endl;
    bool b = true;
    Stack *ptr = new Stack;

    std::string rname;

    while (b)
    {
        std::cout << "enter next elem" << std::endl;
        std::cin >> rname;
        if (rname == "end")
        {
            b = false;
        }
        else
        {
            ptr->name = rname;
            ptr->next = top;

            top = ptr;
        };
    };
    return ptr;
};

void pop()
{
    if (top == NULL)
        return;
    Stack *ptr = top->next; // запоминаем указатель на следующий объект
    std::cout << "Stack ";
    std::cout << top->name << " is deleted \n";

    delete top; // удаляем верхний объект стека
    top = ptr;  // перемещаем указатель top вниз на следующий объект
};

void show()
{
    Stack *c = top;
    while (c != NULL)
    {
        std::cout << c->name << " " << std::endl; // вывод текущего объекта
        c = c->next;                              // пер
    }
};

int main()
{
    bool b = true;
    std::string nn;

    while (b)
    {
        system("cls");
        std::cout << " Change mode" << std::endl;
        std::cout << " 1 - add to stck" << std::endl;
        std::cout << " 2 - del from stck" << std::endl;
        std::cout << " 3 - print to screen" << std::endl;
        std::cout << " 4 - end" << std::endl;
        std::cin >> nn;

        if ((nn.length() == 1) && (nn[0] > '0' && nn[0] < '5'))
        {
            int n = atoi(&nn[0]);
            switch (n)
            {
            case 1:

                push();
                break;
            case 2:
                while (top != NULL)
                    pop();
                break;
            case 3:
                show();
                break;
            case 4:
                b = false;
                std::cout << " 4 - b = false" << std::endl;
                break;
            default:
                break;
            }
        }
        else
        {
            std::cout << " enter correct number pls" << std::endl;
        }
        system("pause");
    }
}