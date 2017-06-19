/*
 *       Filename:  hr_swapnodes.cpp
 *    Description:  https://www.hackerrank.com/challenges/swap-nodes-algo
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct NODE {
    int data;
    struct NODE *left;
    struct NODE *right;
}node;

node *newNode(int data)
{
    node *n = new node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void createTree(node **root)
{
    int N;
    cin >> N;
    *root = newNode(1);
    queue<node *>q;
    q.push(*root);
    for(int i = 1; i <= N; i++){
        node *n = q.front();
        q.pop();
        int a, b;
        cin >> a >> b;
        if(a != -1){
            n->left = newNode(a);
            q.push(n->left);
        }
        if(b != -1){
            n->right = newNode(b);
            q.push(n->right);
        }
    }
}

void printInorder(node *root)
{
    if(root){
        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
    }
}

void swapNodes(node *root, int K)
{
    if(root == NULL) return;
    queue<pair<node *, int> >q;
    q.push(make_pair(root, 1));
    while(!q.empty()){
        pair<node *, int> p = q.front();
        q.pop();
        node *n = p.first;
        int val = p.second;
        if(val % K == 0){
            node *t = n->left;
            n->left = n->right;
            n->right = t;
        }
        if(n->left)
            q.push(make_pair(n->left, val+1));
        if(n->right)
            q.push(make_pair(n->right, val+1));
    }
}

int main() {
    node *troot = NULL;
    createTree(&troot);
    int T;
    cin >> T;
    while(T--){
        int K;
        cin >> K;
        swapNodes(troot, K);
        printInorder(troot);
        cout << "\n";
    }
    return 0;
}

