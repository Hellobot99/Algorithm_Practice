# ⏱️ Algorithm Analysis: Time Complexity Function

이 프로젝트는 주어진 C++ 코드의 실행 결과를 **직접 시뮬레이션 없이**,  
**시간 복잡도 분석을 통해 계산**하여 출력하는 예제입니다.

## 📘 Description

다음과 같은 함수가 주어졌을 때:

```cpp
long_t fun(long_t n) {
    long_t i, j, cnt = 0;
    for (i=1; i<=4*n; i+=2)
        for (j=n; j>=1; j--)
            cnt++;
    return cnt;
}

## 📥 Input

- 첫째 줄: 정수 N (1 ≤ N ≤ 10⁹)

## 📤 Output

- 첫째 줄: fun(N)의 리턴 값 (계산된 반복 횟수)