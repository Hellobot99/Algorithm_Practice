# Quick Sort

이 프로젝트는 **퀵 정렬(Quick Sort)** 알고리즘을 구현하는 문제입니다. 배열을 오름차순으로 정렬하고, `swap` 연산이 총 몇 번 실행되었는지를 출력하는 작업입니다.

### 문제 설명

배열을 퀵 정렬 알고리즘을 사용하여 오름차순으로 정렬하고, `swap` 연산이 총 몇 번 실행되었는지를 출력합니다. 배열의 인덱스는 **1부터 시작**하며, 정렬된 배열과 `swap` 연산 횟수를 출력하는 문제입니다.

### 입력

- 첫째 줄에 배열의 크기 `N`이 주어집니다.
- 둘째 줄에 `N`개의 정수가 주어집니다.

### 출력

- 첫째 줄에 `N`개의 정수를 오름차순으로 정렬하여 출력합니다. (공백으로 구분하되, 줄 끝에는 공백이 없도록 하시오)
- 둘째 줄에 `swap` 연산이 실행된 총 횟수를 출력합니다.

### 알고리즘

1. **퀵 정렬**: 배열의 기준값(pivot)을 선택하고, 이를 기준으로 배열을 두 부분으로 나눕니다.
2. **재귀적 분할**: 기준값을 기준으로 두 부분 배열에 대해 퀵 정렬을 재귀적으로 적용합니다.
3. **교환 횟수 추적**: `swap` 연산이 발생할 때마다 카운팅합니다.

---

## 📘 Description

주어진 배열을 퀵 정렬 알고리즘을 사용하여 오름차순으로 정렬하고, `swap` 연산이 총 몇 번 실행되었는지 추적합니다. 퀵 정렬은 기준값을 선택하고, 이를 기준으로 두 부분 배열로 나누어 정렬하는 방식입니다.

### 입력

- 첫째 줄에 배열의 크기 `N`이 주어집니다.
- 둘째 줄에 `N`개의 정수가 주어집니다.

### 출력

- 첫째 줄에 `N`개의 정수를 오름차순으로 정렬하여 출력합니다.
- 둘째 줄에 `swap` 연산이 실행된 총 횟수를 출력합니다.
