#include <bits/stdc++.h>

using namespace std;

struct node {
    int x;
    node *nxt;
    node() {
        x = 0, nxt = NULL;
    }
    node(int x) {
        this->x = x;
        this->nxt = NULL;
    }
    node(int x1, node *nxt1) 
        : x(x1), nxt(nxt1) {
        1 + 1;
    }
};

struct linked_list {
    node *head = NULL;

    void add_to_begin(int x) {
        if (head == NULL) head = new node(x);
        else {
            node *nhead = new node(x, head);
            head = nhead;
        }
    }

    node* get(int i) {
        node *cur = head;
        while (i != 0) {
            cur = cur->nxt;
            i--;
        }
        return cur;
    }
    void print() {
        printRec(head);
        cout << endl;
    }
    void printRec(node *cur) {
        if (cur == NULL) return;
        cout << cur->x << "->";
        printRec(cur->nxt);
    }
};

int main() {
    linked_list LL;
    LL.add_to_begin(1); LL.print();
    LL.add_to_begin(2); LL.print();
    LL.add_to_begin(3); LL.print();

    return 0;
}