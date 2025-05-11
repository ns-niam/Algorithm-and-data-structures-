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
        root->left = insert(root->left, val);
    if(val > root->x)
        root->right = insert(root->right, val);
    return root;
}

bool go_route(string route, node *root) {
    for(char dir : route) {
        if(root == nullptr) 
            return false; 
        if(dir == 'L') 
            root = root->left; 
        else if(dir == 'R') 
            root = root->right;
        else 
            return false; 
    }
    return root != nullptr;
}

int main(){
    int size_of_BT, size_of_route;
    cin >> size_of_BT >> size_of_route;
    node *root = nullptr;
    
    for(int i = 0; i < size_of_BT; i++){
        int num;
        cin >> num;
        root = insert(root, num);
    }

    for(int i = 0; i < size_of_route; i++){
        string route;
        cin >> route;
        if(go_route(route, root)) 
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
    delete root;
    return 0;
}
