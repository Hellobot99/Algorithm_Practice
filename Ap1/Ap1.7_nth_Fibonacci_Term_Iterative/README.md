# 🔁 Algorithm 1.7 (Iterative): nth Fibonacci Term

이 프로젝트는 교재 및 강의자료를 참고하여 **Algorithm 1.7 - Iterative Fibonacci**를 구현한 예제입니다.

## 📘 Description

주어진 `N`에 대해 **반복문(iteration)** 을 사용하여 `N`번째 피보나치 수를 계산합니다.

> ⚠️ 계산 도중 오버플로우 방지를 위해 다음과 같이 **모듈러 연산**을 적용합니다:  
> `F(n) = [F(n - 1) + F(n - 2)] % 1,000,000`

## 📥 Input

- 첫째 줄: 음이 아닌 정수 `N` (0 ≤ N ≤ 적절한 범위)

## 📤 Output

- 첫째 줄: `N`번째 피보나치 수 `F(N)`