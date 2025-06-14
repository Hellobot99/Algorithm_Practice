# ➗ Sum-of-Subsets

## 📚 Description

교재 및 강의자료를 참고하여 **Algorithm 5.4: Sum-of-Subsets 알고리즘**을 구현한다.
주어진 집합의 원소 중 일부를 선택하여, 그 합이 정확히 **W**가 되는 **모든 부분집합**을 찾는 것이 목적이다.

이 알고리즘은 **백트래킹(Backtracking)** 기법을 활용하여 구현된다.

---

## 📥 Input

* 첫째 줄: 집합의 크기 $n$과 원하는 총합 $W$
* 둘째 줄: 집합의 원소 $n$개 (양의 정수, 오름차순 정렬 보장)

### 예시 입력

```
4 15
5 10 12 13
```

---

## 📤 Output

* 첫째 줄: 총합이 $W$가 되는 부분집합의 개수 $T$
* 둘째 줄부터: 각 부분집합의 원소들을 한 줄에 출력 (오름차순)

  * 출력 순서는 **교과서 알고리즘의 탐색 순서**를 따른다 (즉, 백트래킹의 순서)

### 예시 출력

```
1
2 13
```

---

## 🧠 Notes

* 탐색 시 pruning 조건:

  * 현재까지의 합 + 다음 원소의 값 > W 이면 더 이상 탐색 X
  * 현재까지의 합 + 나머지 원소를 모두 더해도 W에 도달 못하면 탐색 X