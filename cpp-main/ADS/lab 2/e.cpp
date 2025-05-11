#include <bits/stdc++.h>

using namespace std;

struct Node {
    string data;  
    Node* next; 
};

class LinkedList {
    public:
    Node* head;
    int size = 0;
    LinkedList() : head(NULL) {}

    void insertAtBeginning(string value) {
        Node* newNode = new Node(); 
        newNode->data = value;      
        newNode->next = head;      
        head = newNode;        
        size++;    
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(); 
        newNode->data = value;      
        newNode->next = NULL;       

        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void insertAtPosition(string value, int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }

        if (position == 1) {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node(); 
        newNode->data = value;     

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Position out of range." << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head; 
        head = head->next; 
        delete temp;      
    }

    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        if (!head->next) {
            delete head;   
            head = NULL;   
            return;
        }

        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        
        delete temp->next; 
        temp->next = NULL; 
    }

    void deleteFromPosition(int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }

        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            cout << "Position out of range." << endl;
            return;
        }
        Node* nodeToDelete = temp->next; 
        temp->next = temp->next->next;   
        delete nodeToDelete;            
    }

    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp) {
            cout << temp->data << "\n"; 
            temp = temp->next;
        }
    }
};


int main(){
    LinkedList ll;
    int n; cin >> n;
    while(n--){
        string s; cin >> s;
        if(ll.size == 0) ll.insertAtBeginning(s);
        else if(ll.head->data != s) ll.insertAtBeginning(s);
    }
    cout << "All in all: " << ll.size << "\n" << "Students:\n";
    ll.display();
}