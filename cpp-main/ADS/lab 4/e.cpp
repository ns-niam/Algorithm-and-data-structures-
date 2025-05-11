#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

struct BST
{
private:
    Node *root;

    void _inorder(Node *node)
    {
        if (!node)
            return;
        _inorder(node->left);
        cout << node->val << " ";
        _inorder(node->right);
    }

    void _preorder(Node *node)
    {
        if (!node)
            return;
        cout << node->val << " ";
        _preorder(node->left);
        _preorder(node->right);
    }

    void _postorder(Node *node)
    {
        if (!node)
            return;
        _postorder(node->left);
        _postorder(node->right);
        cout << node->val << " ";
    }

    Node *_insert(Node *cur, int val)
    {
        if (!cur)
        {
            return new Node(val);
        }
        if (val > cur->val)
        {
            cur->right = _insert(cur->right, val);
        }
        else if (val < cur->val)
        {
            cur->left = _insert(cur->left, val);
        }
        return cur;
    }

    int _rightmost(Node *cur)
    {
        if (!cur)
            return -1;
        if (!cur->right)
            return cur->val;
        return _rightmost(cur->right);
    }

    int _leftmost(Node *cur)
    {
        if (!cur)
            return -1;
        if (!cur->left)
            return cur->val;
        return _leftmost(cur->left);
    }

    Node *_remove(Node *cur, int target)
    {
        if (!cur)
            return nullptr;
        if (cur->val == target)
        {
            if (!cur->right && !cur->left)
            {
                delete cur;
                return nullptr;
            }
            else if (cur->left && !cur->right)
            {
                Node *temp = cur->left;
                delete cur;
                return temp;
            }
            else if (cur->right && !cur->left)
            {
                Node *temp = cur->right;
                delete cur;
                return temp;
            }
            else if (cur->right && cur->left)
            {
                cur->val = _rightmost(cur->left);
                cur->left = _remove(cur->left, cur->val);
                // cur->val = _leftmost(cur->right);
                // cur->right = _remove(cur->right, cur->val);
            }
        }
        else if (cur->val < target)
        {
            cur->right = _remove(cur->right, target);
            return cur;
        }
        else if (cur->val > target)
        {
            cur->left = _remove(cur->left, target);
            return cur;
        }
        return cur;
    }

    int _getSize(Node *node)
    {
        if (!node)
            return 0;
        return _getSize(node->left) + _getSize(node->right) + 1;
    }

    Node *_search(Node *cur, int target)
    {
        if (cur == NULL)
            return 0;

        if (cur->val == target)
            return cur;

        /* then recur on left subtree */
        Node *res1 = _search(cur->left, target);
        // node found, no need to look further
        if (res1)
            return res1;

        /* node is not found in left,
        so recur on right subtree */
        Node *res2 = _search(cur->right, target);

        return res2;
    }
    int _getHeight(Node *node)
    {
        if (!node->left && !node->right)
            return 0;
        int left = 0;
        if (node->left)
            left = _getHeight(node->left);
        int right = 0;
        if (node->right)
            right = _getHeight(node->right);
        return (max(left, right) + 1);
    }
        int maxNodeLevel(Node *root)
    {
        if (root == NULL)
            return -1;

        queue<Node *> q;
        q.push(root);

        // Current level
        int level = 0;

        // Maximum Nodes at same level
        int max = INT_MIN;

        // Level having maximum Nodes
        int level_no = 0;

        while (1)
        {
            // Count Nodes in a level
            int NodeCount = q.size();

            if (NodeCount == 0)
                break;

            // If it is maximum till now
            // Update level_no to current level
            if (NodeCount > max)
            {
                max = NodeCount;
                level_no = level;
            }

            // Pop complete current level
            while (NodeCount > 0)
            {
                Node *Node = q.front();
                q.pop();
                if (Node->left != NULL)
                    q.push(Node->left);
                if (Node->right != NULL)
                    q.push(Node->right);
                NodeCount--;
            }

            // Increment for next level
            level++;
        }

        return max;
    }

public:
    BST()
    {
        this->root = nullptr;
    }

    void inorder()
    {
        _inorder(root);
        cout << endl;
    }

    void preorder()
    {
        _preorder(root);
        cout << endl;
    }

    void postorder()
    {
        _postorder(root);
        cout << endl;
    }

    void insert(int val)
    {
        Node *newNode = _insert(root, val);
        if (!root)
            root = newNode;
    }

    void remove(int target)
    {
        _remove(root, target);
    }

    Node *search(int target)
    {
        return _search(root, target);
    }

    void getSize()
    {
        cout << _getSize(root) << endl;
    }
    int getHeight()
    {
        return _getHeight(root);
    }
    void SetRoot(Node *node)
    {
        root = node;
    }
    void _maxNodeLevel(){
        cout << maxNodeLevel(root);
    }

};

int main()
{
    BST bst;
    int n;
    int x, y, z;
    cin >> n;
    n--;
    bst.SetRoot(new Node(1));
    while (n--)
    {
        cin >> x >> y >> z;
        Node *cur = bst.search(x);
        if (z == 1)
            cur->right = new Node(y);
        else
            cur->left = new Node(y);
    }
    bst._maxNodeLevel();
    return 0;
}