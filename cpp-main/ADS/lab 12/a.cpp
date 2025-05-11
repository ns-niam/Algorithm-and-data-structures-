#include <bits/stdc++.h>

using namespace std;

class MatrixProcessor {
private:
    static const int MAXN = 501;
    int n;                        // Размерность матрицы
    int matrix[MAXN][MAXN];       // Матрица весов
    int x[MAXN];                  // Порядок обработки вершин
    bool used[MAXN];              // Флаги использования вершин
    vector<int> ans;              // Ответы для каждого шага

public:
    void readInput() {
        cin >> n;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> matrix[i][j];
            }
        }

        for (int i = 1; i <= n; i++) {
            cin >> x[i];
        }
    }

    void process() {
        fill(used, used + MAXN, false); 

        for (int k = 1; k <= n; k++) {
            used[x[k]] = true;
            int temp = 0;

            updateMatrix(x[k]);

            temp = calculateMax();

            ans.push_back(temp);
        }
    }

    void printResults() const {
        for (int result : ans) {
            cout << result << endl;
        }
    }

private:
    void updateMatrix(int k) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    int calculateMax() const {
        int temp = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (used[i] && used[j]) {
                    temp = max(matrix[i][j], temp);
                }
            }
        }

        return temp;
    }
};

int main() {
    MatrixProcessor processor;
    processor.readInput();
    processor.process();
    processor.printResults();

    return 0;
}
