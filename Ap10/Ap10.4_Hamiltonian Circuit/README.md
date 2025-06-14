# 🔁 Hamiltonian Circuit

## 📚 Description

교재 및 강의자료를 참고하여 **Algorithm 5.6: Hamiltonian Circuit (해밀턴 순환 회로)** 알고리즘을 구현한다.
그래프에서 **모든 정점을 정확히 한 번씩 방문한 후**, 시작 정점으로 다시 돌아오는 **순환 경로**의 개수를 찾는다.

---

## 📥 Input

* 첫째 줄: 정점의 수 $N$, 간선의 수 $M$
* 다음 $M$개의 줄: 간선 정보 $(u, v)$ (무방향 그래프, 정점 번호는 1부터 시작)

### 예시 입력

```
4 6
1 2
2 3
3 4
4 1
1 3
2 4
```

---

## 📤 Output

* 첫째 줄: 해밀턴 회로(순환 경로)의 개수 출력

> 동일한 경로를 시작 위치만 바꿔 중복 카운트하지 않도록 주의 (즉, 시작 정점을 고정하여 한 방향 순환만 고려)

### 예시 출력

```
2
```

---

## 🧠 Notes

* 해밀턴 순환 회로는 **모든 정점을 한 번씩 방문**하고, 다시 시작 정점으로 돌아오는 경로이다.
* 백트래킹으로 가능한 모든 순열 경로를 탐색하되, 인접하지 않거나 이미 방문한 정점은 제외한다.
* 시작 정점을 1번으로 고정하여 중복 경로 제거

---

## ✅ 구현 팁

* 인접 행렬 또는 인접 리스트로 그래프 구현
* 시작 정점(예: 1)을 고정하여 중복 제거
* `visited[]` 배열로 방문 체크
* 마지막 정점에서 시작 정점으로의 간선이 존재해야 순환 가능

---
