#include <iostream>
#include <string>
#include <vector>

using namespace std;


void readToArray(vector<int> &array); // read from File to Array
void correctInput(int &change, int pointCount); // correct input

int main()
{
    system("cls");

    int answer = 1;
    vector<int> array;

    readToArray(array);

    while (answer != 6)
    {
        printf("\n1 Enter int element");
        printf("\n2 Find element in Array");
        printf("\n3 Enter element to Array");
        printf("\n4 Delete element from Array");
        printf("\n5 End");
        printf("\n Enter your change: ");

        correctInput(answer, 6);


    }
    return 0;
}


void readToArray(vector<int> &array){
}

void correctInput(int &change, int pointCount) //проверрка корректности ввода
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
