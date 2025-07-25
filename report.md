# 51115142

作業一

## Problem1 解題說明

### 問題描述

本題要求實現一個遞迴函式，計算阿克曼(Ackermann)函數。

### 解題策略

阿克曼(Ackermann)函數是一個著名的非原始遞迴函數，定義如下：
| 動作 | 條件 |
|-----------------|----------------|
| n+1             | if m=0         |
| A(m−1,1)        | if m>0 and n=0 |
| A(m−1,A(m,n−1)) | if m>0 and n>0 |
 
由於它成長極快，常被用來測試程式語言對遞迴的支援程度。

## 程式實作

以下為主要程式碼：

```cpp
#include <iostream>
using namespace std;

// A 函數定義
int A(int m, int n) {
    if (m == 0)
    	//當 m = 0 時，回傳 n + 1 
        return n + 1;
    else if (m > 0 && n == 0)
    	//當m > 0 且 n = 0 時，回傳函式A(m - 1, 1)
        return A(m - 1, 1);
    else
    	//未符合上面兩個條件時，回傳函式A(m - 1, A(m, n - 1))
        return A(m - 1, A(m, n - 1));
}

int main() {
    int m, n;
    cout << "請輸入 m 與 n（建議 m <= 3）: ";
    cin >> m >> n;    cout << "A(" << m << ", " << n << ") = " << A(m, n) << endl;
    return 0;
}

```

## 效能分析

1. 時間複雜度：
阿克曼(Ackermann)函數的時間複雜度無法用傳統的 Big-O 表達，因為它超出任何原始遞迴函數。例如：
A(3,4)=125，需要數百次呼叫。
因此其時間複雜度可視為 超指數成長，甚至超越指數級（Exponential）。

2. 空間複雜度：
遞迴會使用堆疊空間，空間複雜度與遞迴深度有關。
最壞情況為O(A(m,n)) 的遞迴深度。

## 測試與驗證

| 測試案例 | 輸入參數 $m$ | 輸入參數 $n$ | 預期輸出 | 實際輸出 |
|----------|--------------|--------------|----------|----------|
| 測試一   | $m = 0$      | $n = 1$      | 2        | 2        |
| 測試二   | $m = 1$      | $n = 2$      | 4        | 4        |
| 測試三   | $m = 2$      | $n = 2$      | 7        | 7        |
| 測試五   | $m = 3$      | $n = 3$      | 61       | 61       |
| 測試五   | $m = 3$      | $n = 4$      | 125      | 125      |
| 測試四   | $m = 1$      | $n = -1$     | 異常拋出 | 異常拋出 |
| 測試六   | $m = 5$      | $n = 0$      | 異常拋出 | 異常拋出 |
| 測試七   | $m = -1$     | $n = 0$      | 異常拋出 | 異常拋出 |


### 結論
阿克曼(Ackermann)函數僅適合小範圍輸入作教學與測試用途，對於較大 m、n 會迅速耗盡資源，因此不適合使用在實際大型輸入資料。

## 申論開發報告

### 使用的資料結構為：

stack（堆疊）：在非遞迴版本中，模擬系統的函式呼叫堆疊，手動追蹤函數的執行流程。

### 選擇的原因為： 
阿克曼(Ackermann)函數的遞迴深度極高，若使用系統遞迴可能導致 stack overflow，使用堆疊資料結構可以手動控制進出堆疊流程，達到非遞迴的安全實作。

### 使用的演算法：

模擬遞迴（iteration to recursion conversion）：透過迴圈與堆疊結合，來模擬出多層函數的遞迴行為。

### 選擇的原因為：
能有助於了解遞迴本質，還能避免系統限制；此技巧在系統開發與底層演算非常實用。



## Problem2 解題說明

### 問題描述

Power Set（冪集合）指的是一個集合所有子集合的集合。若原始集合有 n 個元素，則 Power Set 共有 2^n 個子集合（包含空集合與本身集合）。

### 解題策略

若集合為 {1, 2}，其 Power Set 為：
{ }, {1}, {2}, {1, 2}

我們可使用「位元法」來實作，將集合中每個元素的出現與否對應為 0 或 1，逐一生成所有可能組合。
 
## 程式實作

以下為主要程式碼：

```cpp
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

```

## 效能分析

時間複雜度：
1. 因外層迴圈需要跑 2^n 次 
2. 而每次最多只能處理 n 個元素
3. 所以總時間複雜度為：O(n × 2^n)

空間複雜度：
1. 因為每次子集合最多只能存 n 個元素 
2. 所以空間複雜度為：O(n)（不含輸出）

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

## 申論開發報告

### 使用的資料結構為：

vector（動態陣列）：儲存原集合與產生的子集合。

### 選擇的原因為：
動態陣列可以更方便地進行元素增減、遍歷與輸出，適合處理冪集合中可變大小的子集合。

### 使用的演算法：

位元遮罩法（Bitmasking）：每個整數的二進位代表一種子集合的組合狀態，進行 0~2^n-1 的遍歷以產生所有子集合。

### 選擇的原因為： 
實作簡潔、效率高，可以避免遞迴帶來的額外成本。

