#include <bits/stdc++.h>

using namespace std;

struct Listnode{
    pair<char,bool> val;
    Listnode *next = NULL;
    Listnode *prev = NULL;
    Listnode() {
        val.first = '0';
        val.second = false;
    }
    Listnode(pair<char,bool> _val,Listnode * _next,Listnode *_prev){
        val = _val;
        next = _next;
        prev = _prev;
    }
};
struct LinkedList{
    Listnode *head,*tail;
    LinkedList(){
        head = new Listnode(make_pair('0',false),NULL,NULL);
        tail = new Listnode(make_pair('0',false),NULL,NULL);
    }
    void insert_end(char data){
        if(head->val.first == '0'){
            head->val.first = data;
            tail = head;
        }else{
            Listnode *new_node = new Listnode(make_pair(data,false),NULL,NULL);
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node; 
        }
    }
    void check(){
        Listnode *cur = tail->prev;
        Listnode *run = head;
        while(cur != NULL){
            if(cur->val.first == tail->val.first){
                tail->val.second = true;
                cur->val.second = true;
            }
            cur = cur->prev;
        }
        while(run != NULL){
            if(run->val.second == false){
                cout << run->val.first << " ";
                return;
            }
            run = run->next;
        }
        cout << -1 << " ";
    }  
    void clear(){
        head = new Listnode(make_pair('0',false),NULL,NULL);
        tail = new Listnode(make_pair('0',false),NULL,NULL);     
    } 
};
LinkedList ll;
int main(){
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        while(n--){
            char c; cin >> c;
            ll.insert_end(c);
            ll.check();
        }
        ll.clear();
        cout << "\n";
    }
}