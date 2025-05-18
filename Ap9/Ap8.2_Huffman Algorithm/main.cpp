#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
using namespace std;

typedef struct node* node_ptr;
typedef struct node {
	char symbol; // the value of a character.
	int frequency; // the number of times the character is in the file.
	node_ptr left;
	node_ptr right;
} node_t;
struct compare {
	bool operator()(node_ptr p, node_ptr q) {
		return p->frequency > q->frequency;
	}
};
typedef priority_queue<node_ptr, vector<node_ptr>, compare> PriorityQueue;

void huffman(int n, PriorityQueue& PQ);
node_ptr create_node(char plus, int f);
void decode(node_ptr root, node_ptr node, string s, int i);
void preorder(node_ptr root);
void inorder(node_ptr root);
void incode(node_ptr root, map<char, string>& map, string s);

bool first = true;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	PriorityQueue pq;

	cin >> N;
	vector<char> c(N);
	vector<int> f(N);

	for (int i = 0; i < N; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> f[i];
	}

	for (int i = 0; i < N; i++) {
		node_ptr p = create_node(c[i],f[i]);
		pq.push(p);
	}

	huffman(N, pq);
	//전위순회
	node_ptr root = pq.top();
	if (root) {
		cout << root->symbol << ":" << root->frequency;
		preorder(root->left);
		preorder(root->right);
	}
	cout << endl;
	// 중위순회

	inorder(root);
	cout << endl;

	int TC;
	cin >> TC;
	string s,ss;
	//인코딩
	vector<char> temp;
	map<char, string>map;

	incode(root, map, ss);
	
	for (int i = 0; i < TC; i++) {
		cin >> s;
		for (int k = 0; k < s.size(); k++) {
			cout << map[s[k]];
		}
		cout << endl;
	}
	
	//디코딩
	cin >> TC;

	for (int i = 0; i < TC; i++) {
		cin >> s;
		decode(root, root, s, 0);
		cout << endl;
	}

	return 0;
}

void huffman(int n, PriorityQueue& PQ)
{
	for (int i = 1; i <= n - 1; i++) {
		node_ptr p = PQ.top(); PQ.pop();
		node_ptr q = PQ.top(); PQ.pop();
		node_ptr r = create_node('+', p->frequency + q->frequency);
		r->left = p;
		r->right = q;
		PQ.push(r);
	}
}

node_ptr create_node(char plus, int f) {
	node_ptr r = new(node_t);
	r->frequency = f;
	r->symbol = plus;
	r->left = NULL;
	r->right = NULL;
	return r;
}

void incode(node_ptr root, map<char, string> &map, string s) {
	if (!root) return;
	if (root->symbol != '+') map[root->symbol] = s;
	else {
		incode(root->left, map, s + "0");
		incode(root->right, map, s + "1");
	}	
}

void decode(node_ptr root, node_ptr node, string s, int i) {
	if (i <= s.length()) {
		if (node->symbol != '+') { // leaf node
			cout << node->symbol;
			decode(root, root, s, i);
		}
		else { // internal node
			if (s[i] == '0')
				decode(root, node->left, s, i + 1);
			else // s[i] == '1'
				decode(root, node->right, s, i + 1);
		}
	}
}

void preorder(node_ptr root) {
	if (root) {
		cout << " " << root->symbol << ":" << root->frequency;
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(node_ptr root) {
	if (root) {
		inorder(root->left);
		if (first) {
			cout << root->symbol << ":" << root->frequency;
			first = false;
		}
		else cout << " " << root->symbol << ":" << root->frequency;
		inorder(root->right);
	}
}