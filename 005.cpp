#include <iostream>
#include <vector>

using namespace std;


void insertInArr(vector<int>& arr, int num, int count) {
    for (int i = 0; i < count; i++) {
        auto it = lower_bound(arr.begin(), arr.end(), num);
        arr.insert(it, num);
    }
}

int main()
{
    vector<int> arr = { 1, 2, 4, 8, 9, 10 };
    int num, count;

    cout << "Enter number to enter: ";
    cin >> num;

    cout << "Enter count of insert: ";
    cin >> count;

    insertInArr(arr, num, count);

    for (int item : arr) {
        cout << item << " ";
    }

    cout << endl;
}
