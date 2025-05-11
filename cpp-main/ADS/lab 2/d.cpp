#include <bits/stdc++.h>

using namespace std;


struct ListNode{
    int val;
    ListNode *next;

    ListNode(int val){
        this->val = val;
        this->next = nullptr;
    }
};

struct LinkedList{
    int size;
    ListNode *head;
    ListNode *tail;

    LinkedList(){
        this->size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    void push_front(int val){
        this->size++;
        ListNode *temp = new ListNode(val);
        if (this->head == nullptr){
            this->head = temp;
            this->tail = temp;
        }else{
            temp->next = this->head;
            this->head = temp;
        }
    }

    void push_back(int val){
        this->size++;
        ListNode *temp = new ListNode(val);
        if (this->head == nullptr){
            this->head = temp;
            this->tail = temp;
        }else{
            this->tail->next = temp;
            this->tail = temp;
        }
    }

    bool empty(){
        return size == 0;
    }

    void print(){
        ListNode *cur = head;
        while (cur){
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << '\n';
    }

    vector<int> maxOccurrence(vector<int> A, int size){
        int mxcount = 0;
        vector<int> res;
        unordered_map<int, int> mp;
        for (int i = 0; i < size; i++) mp[A[i]]++;
        for (auto x1 : mp) if (x1.second > mxcount) mxcount = x1.second;
        for (auto x : mp) if (mxcount == x.second) res.push_back(x.first);
        return res;
    }
};

int main(){
    int n;
    cin >> n;
    LinkedList ll;
    vector<int> v(n);
    while (n--) cin >> v[n - 1];
    sort(v.begin(), v.end());
    vector<int> ans = ll.maxOccurrence(v, v.size());
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    for (auto i : ans) ll.push_back(i);
    ll.print();
}