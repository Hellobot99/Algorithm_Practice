# LCS (Longest Common Subsequence)

## 📌 Description

**Longest Common Subsequence (최장 공통 부분 수열)** 문제는  
두 개의 문자열이 주어졌을 때, **순서를 유지하면서 공통으로 등장하는 부분 수열 중 가장 긴 것**을 찾는 고전적인 **동적 계획법(DP)** 문제입니다.

예시:
- X = `ABCBDAB`
- Y = `BDCABA`

최장 공통 부분 수열의 길이는 `4`이며, 가능한 수열 중 하나는 `"BCBA"`입니다.

---

## 🔢 Input

- 첫째 줄에 문자열 `X`가 주어진다. (알파벳 대문자로 구성)
- 둘째 줄에 문자열 `Y`가 주어진다. (알파벳 대문자로 구성)

예시 입력: ABCBDAB BDCABA

---

## 📤 Output

1. 첫째 줄에 **최장 공통 부분 수열의 길이** (optimal value)를 출력한다.
2. 둘째 줄에 **최장 공통 부분 수열 문자열** (optimal solution)을 출력한다.

> 여러 개의 최장 수열이 존재할 경우, 출력 방식은 주어진 참고 영상을 따를 것.

예시 출력: 4 BCBA