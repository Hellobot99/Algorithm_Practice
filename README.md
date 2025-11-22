# Algorithm Practice

경북대학교 컴퓨터학부 **알고리즘(Algorithm)** 강의 실습 과제 저장소입니다.
다양한 알고리즘 설계 기법(Divide & Conquer, Dynamic Programming, Greedy, Backtracking 등)을 C++로 구현하고 시간 복잡도를 분석한 코드가 포함되어 있습니다.

## 📂 Repository Structure

이 저장소는 과제 번호(Ap: Algorithm Practice)별로 디렉토리가 구분되어 있으며, 각 주차별 핵심 주제는 다음과 같습니다.

| Assignment | Topic | Description | Key Algorithms |
|:---:|:---:|:---|:---|
| **Ap 1** | **Fundamentals** | 알고리즘 기초 및 재귀/반복문 비교 | Sequential/Binary Search, Fibonacci |
| **Ap 2** | **Complexity & Recursion** | 시간 복잡도 분석 및 재귀적 문제 해결 | Time Complexity Analysis, Tower of Hanoi |
| **Ap 3** | **Divide & Conquer I** | 분할 정복을 이용한 정렬 및 퍼즐 해결 | Merge Sort, Quick Sort, Tromino Puzzle |
| **Ap 4** | **Divide & Conquer II** | 심화 분할 정복 (행렬/정수 곱셈, 압축) | Strassen, Karatsuba, Quadtree |
| **Ap 5** | **Dynamic Programming I** | 동적 계획법 기초 및 최단 경로 탐색 | Binomial Coeff, Floyd-Warshall, Triangle Path |
| **Ap 6** | **Dynamic Programming II** | 동적 계획법 심화 (최적화 문제) | Chained Matrix Mult, OBST, LCS |
| **Ap 7** | **Greedy I** | 탐욕 알고리즘을 이용한 그래프/스케줄링 | MST (Prim/Kruskal), Dijkstra, Activity Selection |
| **Ap 9** | **Greedy II** | 탐욕 알고리즘 응용 | Deadline Scheduling, Huffman Coding |
| **Ap 10** | **Backtracking** | 백트래킹을 이용한 상태 공간 트리 탐색 | n-Queens, Sum of Subsets, m-Coloring |

> **Note**: `Ap8` 관련 내용은 `Ap9` 폴더 내에 포함되어 있습니다.

## 🛠 Environment

- **Language**: C++
- **Compiler**: g++ (MinGW or Linux GCC) / MSVC
- **IDE**: Visual Studio / Visual Studio Code

## 🚀 How to Run

각 하위 폴더(`ApX.X_...`)에 있는 `main.cpp`를 컴파일하여 실행합니다.

**Linux/Mac (Terminal)**
```bash
# 예시: Ap 3.3 Quick Sort 실행
cd Ap3/Ap3.3_Quick_Sort
g++ -o quick_sort main.cpp
./quick_sort
