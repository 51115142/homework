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
