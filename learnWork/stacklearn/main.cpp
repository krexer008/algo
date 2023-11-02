#include <iostream>
#include <stdlib.h>

struct Stack
{
    std::string name;
    struct Stack *next;
};
/*
void sozdDob(std::string &rname, )
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
    struct Stack *top, *kon;
    std::string rname;
    bool b;
    int n;

    std::system("clear");
    top = nullptr;
    b = true;
    while (b)
    {
        std::cout << " Change mode" << std::endl;
        std::cout << " 1 - add to stck" << std::endl;
        std::cout << " 2 - del from stck" << std::endl;
        std::cout << " 3 - print to screen" << std::endl;
        std::cout << " 4 - end" << std::endl;
        std::cin >> n;
        switch (n)
        {
        case 1:
            //sozdDob();
            std::cout << " 1 - sozdDob()" << std::endl;
            break;
        case 2:
            //udal();
            std::cout << " 2 - udal()" << std::endl;
            break;
        case 3:
            //pech();
            std::cout << " 3 - pech()" << std::endl;
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
}