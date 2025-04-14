# 🧮 Algorithm Analysis: Time Complexity of `fun(n)`

이 프로젝트는 주어진 C++ 코드에서 **재귀적 시간 복잡도**를 분석하고,  
중복된 계산을 효율적으로 처리할 수 있는 방법을 찾아 **재귀적 관계**를 기반으로 결과를 계산하는 문제입니다.

## 📘 Description

다음과 같은 함수가 주어졌을 때:

```cpp
long_t fun(long_t n) {
    if (n == 0)
        return 1;
    else
        return fun(n / 2) + fun(n / 2) + fun(n / 2) + fun(n / 2);
}

## 📥 Input

- 첫째 줄: 정수 n (0 ≤ n ≤ 10⁹)

## 📤 Output

- 첫째 줄에 fun(n)의 리턴 값을 출력합니다.