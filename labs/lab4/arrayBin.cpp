#include <iostream>
#include <string>
#include <vector>

using namespace std;

void readToArray(vector<int> &array);                      // read from File to Array
void correctInput(int &change, int pointCount);            // correct input
void enterElement(int &elem);                              // enter new element
int indexFind(vector<int> array, int elem);                // Search element in array
void pushElementToArray(vector<int> &array, int elem);     // Push element to array
void deleteElementfromArray(vector<int> &array, int elem); // Delete element from array
void printArray(vector<int> array);
void saveArray(vector<int> array);

int main()
{
    system("cls");
    int answer = 1;
    vector<int> array;
    readToArray(array);
    int elem = -1;
    int index = -1;

    while (answer != 7)
    {
        printf("\n1 Enter int element");
        printf("\n2 Find element in Array");
        printf("\n3 Push element to Array");
        printf("\n4 Delete element from Array");
        printf("\n5 Print Array");
        printf("\n6 Save Array to file");
        printf("\n7 End");
        printf("\n Enter your change: ");

        correctInput(answer, 6);

        switch (answer)
        {
        case 1: // Ввести элемент
            printf("\n1 Enter integer element: ");
            enterElement(elem);
            index = -1;
            break;
        case 2: //
            printf("\n2 Searching element in Array");
            if (index < 0)
            {
                index = indexFind(array, elem);
                if (index < 0)
                    printf("\n2 Element is not exist in Array");
                else
                    printf("\n2 Elements Index: d%", index);
            }
            else
                printf("\n2 Elements Index: d%", index);
            break;
        case 3:
            printf("\n3 Pushing element to Array");
            pushElementToArray(array, elem);
        case 4:
            printf("\n4 Deleting element from Array");
            deleteElementfromArray(array, elem);
            break;
        case 5:
            printf("\n5 Printing Array");
            printArray(array);
            break;
        case 6:
            printf("\n6 Save Array to file");
            saveArray(array);
            break;
        case 7:
            printf("\n6 End program");
            answer = 7;
            break;
        }
    }
    system("pause");
    return 0;
}

void saveArray(vector<int> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        freopen();
    }
}

void printArray(vector<int> array)
{
    freopen("output.txt", "w", stdout);
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i];
    }
}

void deleteElementfromArray(vector<int> &array, int elem) // Delete element from array
{
    int ind = indexFind(array, elem);
    if (ind < 0)
    {
        printf("\n2 Element is not exist in Array");
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

    vector<int> temp;
    for (int i = 0; i < array.size(); i++)
    {
        if (i == middle)
        {
            temp.push_back(elem);
        }
        temp.push_back(array[i]);
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
    freopen("input.txt", "r", stdin);
    string a;
    while (cin >> a)
    {
        if (is_number(a))
        {
            array.push_back(stoi(a));
        }
    }
    freopen("CON", "r", stdin);
}

bool is_number(const string s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}

void correctInput(int &change, int pointCount) // проверрка корректности ввода
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
            cout << "- Enter correct change" << endl;
        }
    }
}
