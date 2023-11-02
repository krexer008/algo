#include <iostream>
#include <stdlib.h>

struct Stack
{
    std::string name;
    struct Stack *next;
};
/*
void sozdDob(struct Stack *top, struct Stack *kon, std::string &rname)
{
    bool b = true;
    while (b)
    {
        std::cout << "enter next elem";
        std::cin >> rname;
        b = (rname != "end");
        if (b)
        {
            kon.next = top;
            kon.name = rname;
            top = kon;
        }
    }
};

/*
void udal()
{
    if (top == null)
    {
        std::cout << "del from empty stsck" << std::endl;
    }
    else
    {
        kon = top;
        top = top.next;
        // dispose (kon)
    }
};

void pech()
{
    if (top = null)
    {
        std::cout << "Stack is empty" << std::endl;
    }
    else
    {
        kon = top;
        std::cout << "Stack condition" << std::endl;

        while (kon != null)
        {
            std::cout << kon.name << std::endl;
            kon = kon.next;
        }
    }
};
*/
int main()
{
    struct Stack *top;
    Stack stack;
    struct Stack *kon = &stack;
    std::string rname;
    bool b;
    std::string nn;
    int n;
    top = nullptr;
    b = true;
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
            n = atoi(&nn[0]);
            switch (n)
            {
            case 1:
                //sozdDob();
                //std::cout << " 1 - sozdDob()" << std::endl;
                //
                b = true;
                while (b)
                {
                    std::cout << "enter next elem" << std::endl;
                    std::cin >> rname;
                    b = (rname != "end");
                    if (b)
                    {
                        (*kon).name = rname;
                        (*kon).next = top;
                        top = kon;
                    };
                };
                b = true;
                break;
            case 2:
                //udal();
                //std::cout << " 2 - udal()" << std::endl;
                if (top == nullptr)
                {
                    std::cout << "del from empty stsck" << std::endl;
                }
                else
                {
                    kon = top;
                    top = (*top).next;
                    kon = nullptr;
                }
                break;
            case 3:
                //pech();
                //std::cout << " 3 - pech()" << std::endl;
                if (top = nullptr)
                {
                    std::cout << "Stack is empty" << std::endl;
                }
                else
                {
                    kon = top;
                    std::cout << "Stack condition" << std::endl;
                    while (kon != nullptr)
                    {
                        std::cout << (*kon).name << std::endl;
                        kon = (*kon).next;
                    }
                };
                break;
            case 4:
                b = false;
                std::cout << " 4 - b = false" << std::endl;
                break;
            default:
                n = 0;
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