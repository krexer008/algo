// Для нового справочника: если бинарный файл "sprav" не существует, он не открывается на запись.
// Тогда создается текстовый файл "sprav" с "bbb" в первой строке, который открывается как бинарный
#include <fstream>
#include <iostream>
#include <io.h>
#include <windows.h>

const int MAXT = 999; // максимальный номер телефона
const int MAXN = 20;  // максимальная длина имени

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    FILE *spr;
    const char noname[MAXN] = "Unknown";
    char buf[MAXN];
    int k, answer = 0;
    char otv;

    while (answer != 4)
    {
        cout << "\n1 New phonebook";
        cout << "\n2 Phonebook addition";
        cout << "\n3 Help by number";
        cout << "\n4 End";
        cout << "\nYour change?";
        cin >> answer;
        if (answer == 1)
        {
            spr = fopen("Sprav", "w");
            fprintf(spr, "bbb");
            fclose(spr);
        }
        fstream inout("Sprav", ios::in | ios::out | ios::binary);
        if (!inout)
        {
            cout << "Cannot open file \n";
            return 1;
        }
        switch (answer)
        {
        case 1: // Новый справочник
            for (int i = 0; i <= MAXT; i++)
            {
                inout.seekp((sizeof noname) * i, ios::beg);
                inout.write(noname, sizeof noname);
            }
            cout << "\nPhonebook is empty, go to addition please";
            break;
        case 2: // дополнение справочника
            otv = 'y';
            while (otv != 'n')
            {
                cout << "\nEnter phonenumber lenth from 3 cipher ";
                cin >> k;
                cout << "\nEnter phone holder name ";
                cin >> buf;
                int len = strlen(buf);
                for (int i = len; i < MAXN; i++)
                    buf[i] = ' ';
                buf[len] = '\0';
                inout.seekp((sizeof noname) * k, ios::beg);
                inout.write(buf, sizeof buf);
                cout << "\nContinue(y/n)? ";
                cin >> otv;
            }
            break;
        case 3: // справка
            otv = 'y';
            while (otv != 'n')
            {
                cout << "Enter phonenumber lenth from 3 cipher  ";
                cin >> k;
                inout.seekg((sizeof buf) * k, ios::beg);
                inout.read(buf, sizeof buf);
                cout << buf;
                cout << "\nContinue(y/n)? ";
                cin >> otv;
            }
            break;
            inout.close();
        } // switch
    }     // while
    return 0;
}