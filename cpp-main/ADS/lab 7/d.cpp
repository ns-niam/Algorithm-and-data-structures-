#include <bits/stdc++.h>
using namespace std;

class MergeSort {
private:
    map<string, double> gpa = {
        {"A+", 4.00}, {"A", 3.75}, {"B+", 3.50}, {"B", 3.00},
        {"C+", 2.50}, {"C", 2.00}, {"D+", 1.50}, {"D", 1.00},
        {"F", 0.00}
    };
    vector<string> surnames, names;
    vector<double> grades;
public:
    void insert(const string& n, const string& surn, const vector<int>& credits, const vector<string>& alpha_grades) {
        surnames.push_back(surn);
        names.push_back(n);

        double upper_sum = 0, down_sum = 0;
        for (int i = 0; i < credits.size(); i++) {
            upper_sum += gpa[alpha_grades[i]] * credits[i];
            down_sum += credits[i];
        }

        double gpa_result = upper_sum / down_sum;
        grades.push_back(gpa_result);
    }

    void mergeSort(int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }

    void merge(int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<string> leftNames(n1), rightNames(n2);
        vector<string> leftSurnames(n1), rightSurnames(n2);
        vector<double> leftGrades(n1), rightGrades(n2);

        for (int i = 0; i < n1; i++) {
            leftNames[i] = names[left + i];
            leftSurnames[i] = surnames[left + i];
            leftGrades[i] = grades[left + i];
        }
        for (int i = 0; i < n2; i++) {
            rightNames[i] = names[mid + 1 + i];
            rightSurnames[i] = surnames[mid + 1 + i];
            rightGrades[i] = grades[mid + 1 + i];
        }

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftGrades[i] < rightGrades[j]) { 
                names[k] = leftNames[i];
                surnames[k] = leftSurnames[i];
                grades[k] = leftGrades[i];
                i++;
            } else if (leftGrades[i] > rightGrades[j]) {
                names[k] = rightNames[j];
                surnames[k] = rightSurnames[j];
                grades[k] = rightGrades[j];
                j++;
            } else {
                if (leftSurnames[i] < rightSurnames[j] || (leftSurnames[i] == rightSurnames[j] && leftNames[i] < rightNames[j])) {
                    names[k] = leftNames[i];
                    surnames[k] = leftSurnames[i];
                    grades[k] = leftGrades[i];
                    i++;
                } else {
                    names[k] = rightNames[j];
                    surnames[k] = rightSurnames[j];
                    grades[k] = rightGrades[j];
                    j++;
                }
            }
            k++;
        }

        while (i < n1) {
            names[k] = leftNames[i];
            surnames[k] = leftSurnames[i];
            grades[k] = leftGrades[i];
            i++;
            k++;
        }

        while (j < n2) {
            names[k] = rightNames[j];
            surnames[k] = rightSurnames[j];
            grades[k] = rightGrades[j];
            j++;
            k++;
        }
    }

    void printResults() {
        for (int i = 0; i < names.size(); i++)
            cout << surnames[i] << " " << names[i] << " " << fixed << setprecision(3) << grades[i] << endl;
    }
};

int main() {
    int size;
    cin >> size;
    MergeSort mergeSort;

    for (int i = 0; i < size; i++) {
        string name, surname;
        int num_courses;
        cin >> surname >> name >> num_courses;

        vector<int> credits(num_courses);
        vector<string> alpha_grades(num_courses);

        for (int j = 0; j < num_courses; j++)
            cin >> alpha_grades[j] >> credits[j];

        mergeSort.insert(name, surname, credits, alpha_grades);
    }

    mergeSort.mergeSort(0, size - 1);
    mergeSort.printResults();

    return 0;
}
