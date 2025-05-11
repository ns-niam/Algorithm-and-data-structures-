#include <bits/stdc++.h>
using namespace std;

struct Date
{
	string day, month, year;
	Date(string day, string month, string year)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
};

bool comp(vector<string> v1, vector<string> v2)
{
	string day1 = v1[0];
	string month1 = v1[1];
	string year1 = v1[2];

	string day2 = v2[0];
	string month2 = v2[1];
	string year2 = v2[2];

	if (year1 < year2)
		return true;
	if (year1 > year2)
		return false;

	if (month1 < month2)
		return true;
	if (month1 > month2)
		return false;

	if (day1 < day2)
		return true;
	if (day1 > day2)
		return false;
	return false;
}

int partition(vector<vector<string>> &ar, int left, int right){
	vector<string> pivot = ar[right];
	int index = left;
	for (int i = left; i < right; i++){
		if (comp(ar[i], pivot)){
			swap(ar[i], ar[index]);
			index++;
		}
	}
	swap(ar[index], ar[right]);
	return index;
}

void quick_sort(vector<vector<string>> &ar, int left, int right)
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
	vector<string> dates;
	vector<vector<string>> v;
	int n;
	cin >> n;
	string day = "", month = "", year = "";
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		day = day + s[0] + s[1];
		month = month + s[3] + s[4];
		year = year + s[6] + s[7] + s[8] + s[9];
		dates.push_back(day);
		dates.push_back(month);
		dates.push_back(year);
		v.push_back(dates);
		dates.clear();
		day = "", month = "", year = "";
	}
	quick_sort(v, 0, v.size() - 1);
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[0].size(); j++)
		{
			if (j == v[0].size() - 1)
				cout << v[i][j];
			else
				cout << v[i][j] << '-';
		}
		cout << endl;
	}

	return 0;
}