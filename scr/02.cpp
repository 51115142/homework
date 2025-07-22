#include <iostream>
#include <cmath>    
#include <string>  
#include <cstdio>   

using namespace std;

void printSet(int subset[], int size) {
    cout << "{ ";
    for (int i = 0; i < size; i++) {
        cout << subset[i] << " ";    // 輸出子集合中的每個元素，並以空格為間隔
    }
    cout << "}" << endl;
}

int main() {
    // 在這裡輸入需要的數值
    int set[] = {1, 2, 3, 4};    
    int n = sizeof(set) / sizeof(set[0]);    // 計算集合中的元素個數

    int total = pow(2, n); // 總共 2^n 個子集合

    cout << "Power Set of { ";
    for (int i = 0; i < n; i++) cout << set[i] << " ";
    cout << "} is:\n\n";

    // 每個數字代表一個子集合（bit mask）
    for (int i = 0; i < total; i++) {
        int subset[32];    // 定義一個陣列來儲存當前的子集合，設定最多可以支援 32 個元素
        int index = 0;     // 追蹤子集合中元素的索引，並從 0 開始

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subset[index++] = set[j];
            }
        }

        printSet(subset, index);    // 呼叫函數列印當前子集合
    }

    return 0;
}
