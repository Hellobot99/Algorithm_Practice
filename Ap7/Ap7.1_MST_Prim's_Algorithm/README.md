# MST: Prim's Algorithm

## 📌 Description

**Prim's Algorithm**은 그래프에서 최소 신장 트리(MST)를 구하는 알고리즘입니다.  
이 문제에서는 교재/강의자료에 소개된 **Algorithm 4.1 Prim's Algorithm**을 구현하여,  
- `nearest` 테이블의 변화를 출력  
하는 프로그램을 작성합니다.

---

## 🔢 Input

- 첫째 줄에 그래프의 정점의 수 `N`과 간선의 수 `K`가 주어집니다.
- 다음 줄부터 `K`개의 줄에 걸쳐 각 간선의 정보 `u`, `v`, `w`가 주어집니다.  
  (여기서 `u`와 `v`는 간선의 양 끝 정점, `w`는 간선의 가중치입니다.)

---

## 📤 Output

1. `N`개의 줄에 걸쳐 Prim's Algorithm의 **nearest 테이블**의 변화를 출력합니다.  
   (줄 끝 공백 주의!!!)

---

## 🛠️ Algorithm

Prim's Algorithm은 다음과 같은 방식으로 동작합니다:

1. **초기화**: 임의의 정점을 시작 정점으로 선택하고, `nearest` 테이블을 초기화합니다.
2. **최소 비용 간선 선택**: 현재 MST에 포함된 정점과 연결된 간선 중 최소 비용 간선을 선택합니다.
3. **테이블 갱신**: 선택된 간선을 MST에 추가하고, `nearest` 테이블을 갱신합니다.
4. **반복**: 모든 정점이 MST에 포함될 때까지 위 과정을 반복합니다.

---

## 💡 추가사항

- **입력 형식 주의**: 정점 번호는 1부터 시작하며, 간선의 가중치는 양의 정수입니다.
- **출력 형식 주의**: 각 줄 끝에 공백이 포함되지 않도록 주의합니다.