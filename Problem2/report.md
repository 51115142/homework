# 51115142

作業一

## Problem2 解題說明

### 問題描述

Power Set（冪集合）指的是一個集合所有子集合的集合。若原始集合有 n 個元素，則 Power Set 共有 2^n 個子集合（包含空集合與本身集合）。

### 解題策略

若集合為 {1, 2}，其 Power Set 為：
→ {}, {1}, {2}, {1, 2}

我們可使用「**位元法（Bitmasking）」**來實作，將集合中每個元素的出現與否對應為 0 或 1，逐一生成所有可能組合。
 
## 程式實作

以下為主要程式碼：

```cpp
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

```

## 效能分析

時間複雜度：
1. 外層迴圈跑 2^n 
2. 每次最多處理 n 個元素
3. 總時間複雜度：O(n × 2^n)

空間複雜度：
1. 輸出時會動態建立子集合：每次最多大小為 n
2. 空間複雜度：O(n)（不含輸出）

## 測試與驗證

### 測試案例

|    測試一    |    測試二    |    測試三    |
|--------------|--------------|--------------|
| $S=(1,2,3,4) |  $S=(1,2,3)  |   $S=(1,2)   |  
|{ }           |{ }           |{ }|
{ 1 }          |{ 1 }         |{ 1 }|
{ 2 }          |{ 2 }         |{ 2 }|
{ 1 2 }        |{ 1 2 }       |{ 1 2 }|
{ 3 }          |{ 3 }|
{ 1 3 }        |{ 1 3 }|  
{ 2 3 }        |{ 2 3 }| 
{ 1 2 3 }      |{ 1 2 3 }| 
{ 4 }
{ 1 4 }
{ 2 4 }
{ 1 2 4 }
{ 3 4 }
{ 1 3 4 }
{ 2 3 4 }
{ 1 2 3 4 }|


### 驗證方式:

1. 確認輸出子集合數量為 2^n
2. 每個子集合元素均為原集合成員

### 結論

對於一個包含 n 個元素的集合，冪集合總共有 2ⁿ 個子集合。程式會逐一產生所有子集合，因此隨著 n 增加，處理時間呈指數成長。
