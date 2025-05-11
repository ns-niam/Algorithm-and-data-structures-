#include <bits/stdc++.h>

using namespace std;

struct node {
    int x;
    node *left, *right;
    node(int key){
        x = key;
        left = nullptr;
        right = nullptr;
    }
    node(){
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

bool exists(node *root, int val){
    if(root == nullptr) 
        return false;
    if(root->x == val)
        return true;
    if(val < root->x)
        return exists(root->left, val);
    return exists(root->right, val);
}

node *insert(node *root, int val){
    if(exists(root, val))
        return root;
    if(root == nullptr) 
        return new node(val);
    if(val < root->x)
        root->left = insert(root, val);
    if(val > root->x)
        root->right = insert(root, val);
    return root;
}

int depth(node *root){
    if(root == nullptr)
        return 0;
    return max(depth(root->right), depth(root->left)) + 1;
}

void print(node *root){
    if(root == nullptr)
        return;
    if(root->left == nullptr and root->right == nullptr)
        cout << root->x << endl;
    else{
        print(root->left);
        print(root->right);
    }
}

int main(){
}