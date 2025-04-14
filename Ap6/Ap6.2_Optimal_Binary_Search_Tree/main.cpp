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

#define INF INT_MAX;
#define matrix_t vector<vector<int>>



typedef struct node {
    int value;
    node* left;
    node* right;
} node;

typedef node* node_ptr;

void optsearchtree(int n, vector<int>& p, matrix_t& A, matrix_t& R);
int minimum(int i, int j, int& k, vector<int>& p, matrix_t& A);
node_ptr tree(int i, int j, vector<int>& keys, matrix_t& R);
node_ptr create_node(int a);
void print_matrix(int n, matrix_t a);
void preorder(node_ptr root);
void inorder(node_ptr root);

map<int, int> mmaapp;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a;
    cin >> n;

    vector<int> t(n + 1, 0);
    vector<int> p(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    matrix_t A(n + 2, vector<int>(n + 1, 0));
    matrix_t R(n + 2, vector<int>(n + 1, 0));


    optsearchtree(n, p, A, R);

    print_matrix(n, A);
    print_matrix(n, R);

    cout << A[1][n] << endl;

    node_ptr root = tree(1, n, t, R);

    preorder(root);
    cout << endl;
    inorder(root);

    return 0;
}

void optsearchtree(int n, vector<int>& p, matrix_t& A, matrix_t& R)
{
    int k;
    for (int i = 1; i <= n; i++) {
        A[i][i - 1] = 0; A[i][i] = p[i];
        R[i][i - 1] = 0; R[i][i] = i;
    }
    A[n + 1][n] = R[n + 1][n] = 0;
    for (int diagonal = 1; diagonal <= n - 1; diagonal++)
        for (int i = 1; i <= n - diagonal; i++) {
            int j = i + diagonal;
            A[i][j] = minimum(i, j, k, p, A);
            R[i][j] = k;
        }
}

int minimum(int i, int j, int& k, vector<int>& p, matrix_t& A)
{

    int temp = k;
    int minValue = INF;
    int value;
    int sum = 0;

    for (int k = i; k <= j; k++) {
        value = A[i][k - 1] + A[k + 1][j];
        if (minValue > value) {
            minValue = value;
            temp = k;
        }
    }
    k = temp;

    for (int x = i; x <= j; x++)
        sum += p[x];

    return minValue + sum;

}

node_ptr tree(int i, int j, vector<int>& keys, matrix_t& R)
{
    int k = R[i][j];
    if (k == 0)
        return NULL;
    else {
        node_ptr node = create_node(keys[k]);
        node->left = tree(i, k - 1, keys, R);
        node->right = tree(k + 1, j, keys, R);
        return node;
    }
}

node_ptr create_node(int a)
{
    node_ptr new_node = new node;
    new_node->value = a;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void preorder(node_ptr root)
{
    cout << root->value;
    if (root->left) {
        cout << " ";
        preorder(root->left);
    }
    if (root->right) {
        cout << " ";
        preorder(root->right);
    }
}

void inorder(node_ptr root)
{
    if (root->left) {
        inorder(root->left);
        cout << " ";
    }
    cout << root->value;
    if (root->right) {
        cout << " ";
        inorder(root->right);
    }
}

void print_matrix(int n, matrix_t a)
{
    for (int i = 1; i <= n + 1; i++) {
        for (int k = i - 1; k <= n; k++) {
            if (k == n) cout << a[i][k] << endl;
            else cout << a[i][k] << " ";
        }
    }
}