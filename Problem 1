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
    cin >> m >> n;

    // 計時開始
    clock_t start_time = clock();

    // 呼叫 Ackermann 函數
    int result = A(m, n);

    // 計時結束
    clock_t end_time = clock();

    // 計算執行時間（秒）
    double duration = double(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "A(" << m << ", " << n << ") = " << result << endl;
    cout << "執行時間為: " << duration << " 秒" << endl;

    return 0;
}
