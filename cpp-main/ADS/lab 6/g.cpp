
#include <bits/stdc++.h>
using namespace std;

bool comp(pair<string, string> &p1, pair<string, string> &p2)
{
    return p1.first < p2.first;
}

int partition(vector<pair<string, string>> &ar, int left, int right)
{
    pair<string, string> pivot = ar[right];
    int index = left;
    for (int i = left; i < right; i++)
    {
        if (comp(ar[i], pivot))
        {
            swap(ar[i], ar[index]);
            index++;
        }
    }
    swap(ar[index], ar[right]);
    return index;
}

void quick_sort(vector<pair<string, string>> &ar, int left, int right)
{
    if (left < right)
    {
        int p = partition(ar, left, right);
        quick_sort(ar, left, p - 1);
        quick_sort(ar, p + 1, right);
    }
}
int main()
{
    int n;
    map<string, string> mp;
    vector<pair<string, string>> v;
    bool flag = false;
    cin >> n;
    string oldName, newName;
    while (n--)
    {
        cin >> oldName >> newName;
        for (int i = 0; i < v.size(); i++)
            if (oldName == v[i].second)
            {
                v[i].second = newName;
                flag = true;
                break;
            }
        if (!flag)
            v.push_back({oldName, newName});
        flag = false;
    }
    quick_sort(v, 0, v.size() - 1);
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
}