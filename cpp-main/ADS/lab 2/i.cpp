#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    string val;
    ListNode *next;
    ListNode *prev;
    ListNode(){
        this->val = "";
        this->next = NULL;
        this->prev = NULL;
    }
    ListNode(string val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
    ListNode(string val, ListNode *next, ListNode *prev){
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};
struct DoubleLinkedList{
    int size;
    ListNode *head, *tail;
    DoubleLinkedList(){
        this->size = 0;
        this->head = NULL;
        this->tail = NULL;
    }
    void add_front(string val){

        ListNode *temp = new ListNode(val);
        if (this->head == NULL){
            this->head = temp;
            this->tail = temp;
        }
        else{
            temp->next = this->head;
            this->head->prev = temp;
            this->head = temp;
        }
        cout << "ok" << endl;
        this->size++;
    }
    void add_back(string val){
        this->size++;
        ListNode *temp = new ListNode(val);
        if (this->head == NULL){
            this->head = temp;
            this->tail = temp;
        }
        else{
            this->tail->next = temp;
            temp->prev = this->tail;
            this->tail = temp;
        }
        cout << "ok" << endl;
    }
    void erase_front(){
        if (this->size != 0){
            cout << this->head->val << "\n";
            if (size != 1){
                this->head = this->head->next;
                this->head->prev = NULL;
            }
            else{
                clear();
                return;
            }
            this->size--;
        }
        else{
            cout << "error" << endl;
        }
    }
    void erase_back(){
        if (this->size != 0){
            cout << this->tail->val << "\n";
            if (this->size != 1){
                this->tail = this->tail->prev;
                this->tail->next = NULL;
            }
            else{
                clear();
                return;
            }
            this->size--;
        }
        else{
            cout << "error" << endl;
        }
    }
    void clear(){
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }
};

int main(){
    DoubleLinkedList dll;
    string book;
    while (true){
        string command;
        cin >> command;
        if (command == "add_front"){
            cin >> book;
            dll.add_front(book);
        }
        else if (command == "add_back"){
            cin >> book;
            dll.add_back(book);
        }
        else if (command == "erase_front"){
            dll.erase_front();
        }
        else if (command == "erase_back"){
            dll.erase_back();
        }
        else if (command == "front"){
            if (dll.size != 0)
                cout << dll.head->val << "\n";
            else
                cout << "error\n";
        }
        else if (command == "back"){
            if (dll.size != 0)
                cout << dll.tail->val << "\n";
            else
                cout << "error\n";
        }
        else if (command == "clear"){
            dll.clear();
            cout << "ok" << endl;
        }
        else if (command == "exit"){
            cout << "goodbye" << endl;
            return 0;
        }
    }
}