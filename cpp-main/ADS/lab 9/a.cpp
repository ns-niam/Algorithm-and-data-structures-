#include <iostream>
#include <string>

using namespace std;

class StringRepeater {
private:
    string A, B;

    bool isSubstring(const string& repeatedA) {
        return repeatedA.find(B) != string::npos;
    }

public:
    StringRepeater(const string& a, const string& b) : A(a), B(b) {}

    int minRepetitionsToContain() {
        int minRepeats = B.size() / A.size() + (B.size() % A.size() != 0 ? 1 : 0);
        string repeatedA = "";
        for(int i = 0; i < minRepeats; i++)
            repeatedA += A;
        
        if (isSubstring(repeatedA)) {
            return minRepeats;
        } else if (isSubstring(repeatedA + A)) {
            return minRepeats + 1;
        } else if (isSubstring(repeatedA + A + A)) {
            return minRepeats + 2;
        }
        
        return -1;
    }
};

int main() {
    string A, B;
    cin >> A >> B;

    StringRepeater repeater(A, B);
    int result = repeater.minRepetitionsToContain();

    cout << result << endl;
    
    return 0;
}
