#include <iostream>
#include <algorithm>

using namespace std;


void insertInArr(int arr[], int& size, int num, int count) {

    for (int i = 0; i < count; i++) {
        int* it = lower_bound(arr, arr + size, num);
        int index = it - arr;

        for (int j = size; j > index; j--) {
            arr[j] = arr[j - 1];
        }
        arr[index] = num;
        size++;
    }
}

int main()
{
    int arr[100] = { 1, 2, 4, 8, 9, 10 };
    int size = 6;
    int num, count;

    cout << "Enter number to add: ";
    cin >> num;

    cout << "Enter count to insert: ";
    cin >> count;

    insertInArr(arr, size, num, count);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << endl;
}
