#include <iostream>
#include <cmath>    // for pow()
#include <string>   // for string[]
#include <cstdio>   // for printf()

using namespace std;

void printSet(int subset[], int size) {
    cout << "{ ";
    for (int i = 0; i < size; i++) {
        cout << subset[i] << " ";
    }
    cout << "}" << endl;
}

int main() {
    // 請在此自訂集合內容
    int set[] = {1, 2, 3, 4};
    int n = sizeof(set) / sizeof(set[0]);

    int total = pow(2, n); // 總共 2^n 個子集合

    cout << "Power Set of { ";
    for (int i = 0; i < n; i++) cout << set[i] << " ";
    cout << "} is:\n\n";

    // 每個數字代表一個子集合（bit mask）
    for (int i = 0; i < total; i++) {
        int subset[32]; // 預設最多支援 32 個元素
        int index = 0;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subset[index++] = set[j];
            }
        }

        printSet(subset, index);
    }

    return 0;
}
