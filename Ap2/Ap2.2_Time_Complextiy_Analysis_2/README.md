# 🧮 Algorithm Analysis: Time Complexity of `fun(n, m, p)`

이 프로젝트는 주어진 C++ 코드에서 **시간 복잡도**를 분석하고,  
이를 기반으로 **수학적으로 계산된 결과**를 출력하는 문제입니다.

## 📘 Description

다음과 같은 함수가 주어졌을 때:

```cpp
long_t fun(long_t n, long_t m, long_t p) {
    long_t i, j, k, cnt = 0;
    for (i = 1; i <= 2 * n; i += 4)
        for (j = 1; j <= 2 * m; j *= 2)
            for (k = 4 * p; k >= 1; k /= 2)
                cnt++;
    return cnt;
}
## 📥 Input

- 첫째 줄: 정수 n, m, p가 주어집니다.

## 📤 Output

- 첫째 줄에 fun(n, m, p)의 리턴 값을 출력합니다.