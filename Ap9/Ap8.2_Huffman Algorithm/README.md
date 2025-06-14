# 📦 Huffman Algorithm

## 📚 Description

교재 및 강의자료를 참고하여 **Huffman Algorithm**, **허프만 인코더**, **허프만 디코더**를 구현한다.

주어진 문자들의 빈도를 기반으로 **최적의 이진 트리(허프만 트리)** 를 구성하고, 해당 트리를 통해 인코딩/디코딩 기능을 수행한다.

---

## 📥 Input

1. 첫째 줄: 문서에 포함된 문자 개수 **N** (1 ≤ N ≤ 100)
2. 둘째 줄: N개의 문자 (알파벳 문자, 대소문자 구분)
3. 셋째 줄: N개의 각 문자에 대응하는 출현 빈도
4. 넷째 줄: 인코딩할 문자열의 개수 **M**
5. 다섯째 줄부터 M개의 문자열 (각 문자열은 알파벳 문자로만 구성)
6. 이후 줄: 디코딩할 허프만 코드의 개수 **K**
7. 그 다음 K개의 허프만 코드 (0과 1의 문자열)

> ✅ 출현 빈도는 정렬되어 있지 않으며, 트리 생성을 위해 **정렬이 필요**하다.

### 예시 입력

```
5
A B C D E
5 9 12 13 16
3
ABC
EDC
AE
2
1100
1001011
```

---

## 📤 Output

1. 첫째 줄: 허프만 트리의 **전위 순회 결과 (preorder traversal)**

2. 둘째 줄: 허프만 트리의 **중위 순회 결과 (inorder traversal)**

   * 노드 표현: `문자:빈도`
   * 내부 노드는 문자 대신 `'+'` 사용
   * 줄 끝 공백 없음

3. 다음 M줄: 각 입력 문자열의 **허프만 인코딩 결과**

4. 다음 K줄: 각 입력 코드의 **허프만 디코딩 결과**

### 예시 출력

```
+:55 +:25 E:16 +:12 A:5 B:9 +:30 C:12 D:13
A:5 +:12 B:9 +:25 C:12 D:13 +:30 E:16 +:55
01101100
10111100
0110
CAB
DA
```

---

## 🧠 Notes

* 트리 구성 시 최소 힙(Min Heap) 또는 우선순위 큐 사용 권장
* 트리 순회는 재귀로 구현할 수 있음
* 인코딩 시: 문자 → 코드 매핑 테이블 필요
* 디코딩 시: 허프만 트리 루트부터 탐색하며 복원

---

## 💡 구현 팁

* 구조체 또는 클래스를 이용해 트리 노드 정의 (문자, 빈도, 왼쪽/오른쪽 자식)
* 문자열 인코딩 시 map\<char, string> 사용
* 코드 디코딩 시 허프만 트리를 따라가며 복원
* 입출력 시 공백/줄 끝 처리에 유의
