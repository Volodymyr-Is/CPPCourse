/* Lab 7 Task 7 */

#include <iostream>
#include "Header.h"

using namespace std;

int main() {
    const int N = 10;

    int mas[N];
    INPUTMAS(mas, N);
    OUTMAS(mas, N);
    FINDMAX(mas, N, indexMax);
    MULTBETWEENZEROS(mas, N, mult);
    ARRAYREBUILD(mas, N);
    return 0;
}
