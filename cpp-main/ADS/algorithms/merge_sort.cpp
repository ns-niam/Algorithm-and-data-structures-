#include <bits/stdc++.h>
using namespace std;

class MergeSort {
    vector<string> vector_to_sort;

public:
    void insert(const vector<string>& vector_in) {
        vector_to_sort.insert(vector_to_sort.end(), vector_in.begin(), vector_in.end());
    }

    vector<string> split(const string& str, char delimiter) {
        vector<string> tokens;
        string token;
        for (char ch : str) {
            if (ch == delimiter) {
                if (!token.empty()) {
                    tokens.push_back(token);
                    token.clear();
                }
            } else {
                token += ch;
            }
        }
        if (!token.empty())
            tokens.push_back(token);
        return tokens;
    }

    void merge(int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<string> L(n1), R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = vector_to_sort[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = vector_to_sort[mid + 1 + j];

        int i = 0, j = 0;
        int k = left;
        while (i < n1 && j < n2) {
            if (getStringSizeInBytes(L[i]) <= getStringSizeInBytes(R[j])) {
                vector_to_sort[k] = L[i];
                i++;
            } else {
                vector_to_sort[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            vector_to_sort[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            vector_to_sort[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSort(int left, int right) {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }

    void printVector() {
        for (const string& s : vector_to_sort)
            cout << s << " ";
        cout << endl;
    }
    size_t getStringSizeInBytes(const std::string& str) {
        return str.size() * sizeof(char);
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        MergeSort Merging;
        string take_for;
        getline(cin, take_for);
        vector<string>vector_in = Merging.split(take_for, ' ');
        Merging.insert(vector_in);
        Merging.mergeSort(0, vector_in.size() - 1);
        Merging.printVector();
    }
    return 0;
}
