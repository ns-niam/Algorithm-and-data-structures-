#include <bits/stdc++.h>
using namespace std;
map<string, double> mp = {
    {"A+", 4.00}, {"A", 3.75}, {"B+", 3.50}, {"B", 3.00}, {"C+", 2.50}, {"C", 2.00}, {"D+", 1.50}, {"D", 1.00}, {"F", 0}};

bool comp(pair<pair<string, string>, double> v1, pair<pair<string, string>, double> v2)
{
    if (v1.second < v2.second)
        return true;
    if (v1.second > v2.second)
        return false;
    if (v1.second == v2.second)
    {
        if (v1.first.first < v2.first.first)
            return true;
        if (v1.first.first > v2.first.first)
            return false;
        if (v1.first.second < v2.first.second)
            return true;
        if (v1.first.second > v2.first.second)
            return false;
    }

    return false;
}

int partition(vector<pair<pair<string, string>, double>> &ar, int left, int right)
{
    pair<pair<string, string>, double> pivot = ar[right];
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

void quick_sort(vector<pair<pair<string, string>, double>> &ar, int left, int right)
{
    if (left < right)
    {
        int p = partition(ar, left, right);
        quick_sort(ar, left, p - 1);
        quick_sort(ar, p + 1, right);
    }
}
double sumgpa(int subjects)
{
    string mark;
    int credit;
    double sum_credit = 0;
    double sum_mark = 0;
    for (int i = 0; i < subjects; i++)
    {
        cin >> mark >> credit;
        sum_mark += mp[mark] * credit;
        sum_credit += credit;
    }
    return sum_mark / sum_credit;
}

int main()
{
    vector<pair<pair<string, string>, double>> students;
    double sum;
    int n, subjects;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string last_name, first_name;
        cin >> last_name >> first_name;
        cin >> subjects;
        sum = sumgpa(subjects);
        students.push_back({{last_name, first_name}, sum});
    }
    quick_sort(students, 0, students.size() - 1);

    for (int i = 0; i < students.size(); i++)
        cout << students[i].first.first << ' ' << students[i].first.second << ' ' << fixed << setprecision(3) << students[i].second << endl;
    return 0;
}