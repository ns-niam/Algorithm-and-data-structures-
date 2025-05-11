#include <bits/stdc++.h>

using namespace std;
 
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

int ans, sum = 0, min_sum = 0;

int findMaxSum(int n, ListNode *head)
{
    while (head != NULL)
    {
        sum += head->val;
        ans = max(ans, sum - min_sum);
        min_sum = min(min_sum, sum);
        head = head->next;
    }
    return ans;
}
struct Linkedlist
{
    int size;
    ListNode *head, *tail;
    Linkedlist()
    {
        this->size = 0;
        this->tail = NULL;
        this->head = NULL;
    }
    void push_back(int val)
    {
        this->size++;
        ListNode *temp = new ListNode(val);
        if (head == NULL)
        {
            this->head = this->tail = temp;
        }
        else
        {
            this->tail->next = temp;
            this->tail = temp;
        }
    }
};
int main()
{
    Linkedlist ll;
    int n;
    cin >> n;
    int y = n;
    while (n--)
    {
        int x;
        cin >> x;
        ll.push_back(x);
    }
    ans = ll.head->val;
    cout << findMaxSum(y, ll.head) << "\n";
    return 0;
}
