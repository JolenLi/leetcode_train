//
// Created by Jolen on 2021/6/21.
//


#include<iostream>
#include<queue>
#include<vector>

using namespace std;


class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

void connect2Node(Node *l, Node *r) {
    if(l== nullptr||r== nullptr)
        return;
    l->next = r;
    connect2Node(l->left,l->right);
    connect2Node(r->left,r->right);
    connect2Node(l->right,r->left);
}

Node *connect(Node *root) {
    if (root == nullptr||root->left== nullptr)
        return root;
    connect2Node(root->left,root->right);
    return root;
}

