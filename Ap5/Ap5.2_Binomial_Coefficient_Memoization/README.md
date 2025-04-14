# Binomial Coefficient: Memoization

## 📌 Description

이 문제는 **메모이제이션(Memoization)** 기법을 활용하여 이항 계수 \( B(n, k) \)를 효율적으로 계산하는 문제입니다.

**이항 계수**는 다음과 같은 점화식으로 정의됩니다:

B(n, k) = 1 if k == 0 or k == n
B(n, k) = (B(n - 1, k - 1) + B(n - 1, k)) % 10007

또한, 이미 계산된 값은 **저장(memoization)** 해두고, 재사용하여 불필요한 중복 계산을 방지해야 합니다.

---

## 🔢 Input

- 첫째 줄에 정수 n과 k가 주어집니다. (0 ≤ k ≤ n ≤ 2000)

---

## 📤 Output

- 첫째 줄에 계산된 이항 계수 B(n,k)를 출력합니다.
- 둘째 줄에 binom() 함수가 호출된 총 횟수를 출력합니다.