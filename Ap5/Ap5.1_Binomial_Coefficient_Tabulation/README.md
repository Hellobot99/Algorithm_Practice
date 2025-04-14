# Binomial Coefficient: Tabulation

## 📌 Description

교재/강의자료에서 소개된 **Algorithm 3.2 - Binomial Coefficient** 알고리즘을 **동적 계획법 (Tabulation)** 으로 구현합니다.

여기서 이항 계수 \( B(n, k) \)는 **모듈러 연산**을 포함한 다음과 같은 점화식을 따릅니다:

B(n, k) = 1, if k == 0 or k == n
B(n, k) = (B(n - 1, k - 1) + B(n - 1, k)) % 10007


---

## 🔢 Input

- 첫째 줄에 정수 `n`과 `k`가 주어집니다. (`0 ≤ k ≤ n ≤ 1,000`)

---

## 📤 Output

- 첫째 줄에 이항 계수 \( B(n, k) \)를 출력합니다.
