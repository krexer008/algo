#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void readToArray(vector<int> &array);           // read from File to Array
void correctInput(int &change, int pointCount); // correct input
bool is_number(const string s);
void enterElement(int &elem);                              // enter new element
int indexFind(vector<int> array, int elem);                // Search element in array
void pushElementToArray(vector<int> &array, int elem);     // Push element to array
void deleteElementfromArray(vector<int> &array, int elem); // Delete element from array
void printArray(vector<int> array);
void saveArray(vector<int> array);

int main()
{
    system("cls");

    int answer = 0;

    vector<int> array;

    readToArray(array);

    system("pause");
    int elem = -1;
    int index = -2;

    while (answer != 7)
    {
        cout << "\n1 Enter int element";
        cout << "\n2 Find element in Array";
        cout << "\n3 Push element to Array";
        cout << "\n4 Delete element from Array";
        cout << "\n5 Print Array" << endl;
        cout << "\n6 Save Array to file";
        cout << "\n7 End";
        cout << "\n Enter your change: ";

        correctInput(answer, 8);

        switch (answer)
        {
        case 1: // Ввести элемент
            printf("\n1 Enter integer element: ");
            enterElement(elem);
            index = -1;
            system("pause");
            break;
        case 2: //
            printf("\n2 Searching element in Array\n");
            if (index != -2)
            {
                index = indexFind(array, elem);
                if (index == -1)
                    printf("\nElement is not exist in Array\n");
                else
                    printf("\nElements Index: %d", index);
                printf("\n");
            }
            else
            {
                printf("\n New element is not Entered, please enter element\n");
                index = -2;
            }
            system("pause");
            break;
        case 3:
            if (index != -2)
            {
                printf("\n3 Pushing element to Array\n");
                pushElementToArray(array, elem);
            }
            else
                printf("\n New element is not Entered, please enter element\n");
            system("pause");
            break;
        case 4:
            printf("\n4 Deleting element from Array\n");
            if (index > -2)
                deleteElementfromArray(array, elem);
            index = -2;
            system("pause");
            break;
        case 5:
            printf("\n5 Printing Array\n");
            printArray(array);
            system("pause");
            break;
        case 6:
            printf("\n6 Save Array to file\n");
            saveArray(array);
            system("pause");
            break;
        case 7:
            printf("\n6 End program\n");
            answer = 7;
            break;
        }
    }
    system("pause");
    return 0;
}

void saveArray(vector<int> array)
{
    if (array.size() > 0)
    {
        ofstream out("out.txt", ios::out);
        for (int i = 0; i < array.size(); i++)
        {
            if (out.is_open())
            {
                out << array[i] << ", ";
            }
        }
        out.close();
    }
    else
        printf("Array is empty");
    void printArray(vector<int> array);
}

void printArray(vector<int> array)
{
    if (array.size() > 0)
        for (int i = 0; i < array.size(); i++)
        {
            cout << array[i] << ", ";
        }
    else
        printf("Array is empty");
}

void deleteElementfromArray(vector<int> &array, int elem) // Delete element from array
{
    int ind = indexFind(array, elem);
    if (ind < 0)
    {
        printf("\n2 Element is not exist in Array \n");
    }
    else
    {
        vector<int> temp;
        for (int i = 0; i < array.size(); i++)
        {
            if (i != ind)
            {
                temp.push_back(array[i]);
            }
            continue;
        }
        array = temp;
    }
}

void pushElementToArray(vector<int> &array, int elem) // Push element to array
{

    vector<int> temp;
    bool found = false;
    int high = array.size() - 1;
    int low = 0;
    int middle = (high + low) / 2;
    while (!found && high >= low)
    {
        if (elem == array[middle])
            found = true;
        else if (elem < array[middle])
            high = middle - 1;
        else
            low = middle + 1;
        middle = (high + low) / 2;
    };

    if (elem <= array[middle])
        for (int i = 0; i < array.size(); i++)
        {
            if (i == middle)
            {
                temp.push_back(elem);
            }
            temp.push_back(array[i]);
        }
    else
        for (int i = 0; i < array.size(); i++)
        {
            temp.push_back(array[i]);
            if (i == middle)
            {
                temp.push_back(elem);
            }
        }
    array = temp;
}

int indexFind(vector<int> array, int elem) // Find element in Array
{
    bool found = false;
    int high = array.size() - 1;
    int low = 0;
    int middle = (high + low) / 2;
    while (!found && high >= low)
    {
        if (elem == array[middle])
            found = true;
        else if (elem < array[middle])
            high = middle - 1;
        else
            low = middle + 1;
        middle = (high + low) / 2;
    }
    return found ? middle : -1;
}

void enterElement(int &elem) // enter new element
{
    string s;
    cin >> s;
    while (!is_number(s) && stoi(s) < 0)
    {
        system("cls");
        printf("\nEnter integer element: ");
        cin >> s;
    };
    elem = stoi(s);
}

void readToArray(vector<int> &array) // read to array
{
    ifstream in("input.txt", ios::in); // окрываем файл для чтения
    string a;
    if (in.is_open())
    {
        string a;
        while (in >> a)
        {
            if (is_number(a))
            {
                array.push_back(stoi(a));
            }
        }
    }
    in.close();
}

bool is_number(const string s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}

void correctInput(int &change, int pointCount)
{
    string inp;
    char pC = '0' + pointCount;

    bool isCypher = false;
    while (!isCypher)
    {
        cin >> inp;
        if ((inp.length() == 1) && ((inp[0] > '0') && (inp[0] < pC)))
        {
            isCypher = true;
            change = stoi(inp);
        }
        else
        {
            cout << "- Enter correct change \n"
                 << endl;
        }
    }
}
