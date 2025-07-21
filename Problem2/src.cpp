#include <iostream>
#include <vector>
#include <cmath> // 使用 pow 計算 2^n

using namespace std;

// 函數：印出集合內容
void printSet(const vector<int>& subset) {
    cout << "{ ";
    for (size_t val = 0; val < subset.size(); val++) {
        cout << subset[val] << " ";
    }
    cout << "}" << endl;
}

// 主程式
int main() {
    // 定義原始集合，使用 C++11 初始化方式
    vector<int> set = {1, 2,3,4};  // 可自由更改內容
    int n = set.size(); // 集合大小

    // 共有 2^n 種子集合
    int powerSetSize = pow(2, n);

    cout << "Power Set of { ";
    for (size_t x = 0; x < set.size(); x++) cout << set[x] << " ";
    cout << "} is:\n" << endl;

    // 使用位元法產生所有子集合
    for (int i = 0; i < powerSetSize; i++) {
        vector<int> subset;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {  // 若第 j 個 bit 是 1，表示取用 set[j]
                subset.push_back(set[j]);
            }
        }
        printSet(subset); // 印出子集合
    }

    return 0;
}
