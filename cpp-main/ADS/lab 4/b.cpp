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
    ~node(){ 
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

node *exists(node *root, int val){
    if(root == nullptr) 
        return nullptr;
    if(root->x == val)
        return root;
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
        root->left = insert(root->left, val);
    if(val > root->x)
        root->right = insert(root->right, val);
    return root;
}

int size(node *root){
    if(root == nullptr)
        return 0;
    return size(root->left) + size(root->right) + 1;
}

int main(){
    int size_of_BT;
    cin >> size_of_BT;
    node *root = nullptr;
    
    for(int i = 0; i < size_of_BT; i++){
        int num;
        cin >> num;
        root = insert(root, num);
    }
    int find_num;
    cin >> find_num;
    root = exists(root, find_num);
    cout << size(root);
    delete root;
    return 0;
}
