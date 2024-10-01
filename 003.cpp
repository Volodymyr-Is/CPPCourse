#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main()
{
    /*setlocale(LC_ALL, "Ukr");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char str[] = "See from the text the words that represent the same number of letters.";
    char str2[255];
    strcpy(str2, str);
    cout << "Sentence: " << str << endl;
    char del[] = " ,.";
    char* ptr = strtok(str2, del);
    cout << "Enter number of letters to capture: ";
    int num = 0;
    cin >> num;
    while (ptr != NULL)
    {
        if (strlen(ptr) == num)
            cout << "\"" << ptr << "\"";
        ptr = strtok(NULL, del);
    }*/



    //Видалити із тексту слова, що закінчуються на "а".

    char str[] = "Hello World Test C++ AAA BBB aaa ccc";
    char strCopy[sizeof(str)];
    strcpy(strCopy, str);
    char seps[] = " :?!;,.\t\n";
    cout << "Original text: " << str << endl;

    char* token = strtok(str, seps);
    int lenResult = 0;
    int countWord = 0;

    
    while (token != NULL)
    {
        int last = strlen(token) - 1;
        if (!(token[last] == 'a' || token[last] == 'A')) // якщо слово НЕ закінчується на "а" або "А"
        {
            lenResult += (strlen(token) + 1);
            ++countWord;
        }
        token = strtok(NULL, seps);
    }

    char* resString = new char[lenResult];
    resString[0] = '\0';

    strcpy(str, strCopy);
    token = strtok(str, seps);

    int currentNumberWord = 0;

    while (token != NULL)
    {
        int last = strlen(token) - 1;
        if (!(token[last] == 'a' || token[last] == 'A')) // якщо слово НЕ закінчується на "а" або "А"
        {
            strcat(resString, token);
            ++currentNumberWord;
            if (countWord != currentNumberWord)
            {
                strcat(resString, " ");
            }
        }
        token = strtok(NULL, seps);
    }

    cout << "\nResult:\n" << resString << endl;

    delete[] resString;
    _getch();

    return 0;
}