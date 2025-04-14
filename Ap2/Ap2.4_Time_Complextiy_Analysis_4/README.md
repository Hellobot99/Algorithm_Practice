# 🧮 Algorithm Analysis: Time Complexity of `fun(n)`

이 프로젝트는 주어진 C++ 코드에서 **재귀적 시간 복잡도**를 분석하고,  
이를 기반으로 **수학적으로 계산된 결과**를 출력하는 문제입니다.

## 📘 Description

다음과 같은 함수가 주어졌을 때:

```cpp
long_t fun(long_t n) {
    if (n == 0)
        return 1;
    else {
        long_t s = 0;
        for (int i = 1; i <= 8; i++)
            s += fun(n / 4);
        return s;
    }
}

## 📥 Input

- 첫째 줄: 정수 n (0 ≤ n ≤ 10⁹)

## 📤 Output

- 첫째 줄에 fun(n)의 리턴 값을 출력합니다.