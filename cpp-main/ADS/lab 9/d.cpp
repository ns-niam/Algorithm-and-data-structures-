#include <iostream>
#include <vector>
using namespace std;


// prefixFunction
// Эта функция вычисляет массив pi — префикс-функцию строки. 
// Префикс-функция pi[i] для символа s[i] — это длина наибольшего суффикса, 
// который также является префиксом подстроки s[0:i].
vector<int> prefixFunction(string s){
    vector<int> pi(s.size());
    pi[0] = 0;
    // Создается вектор pi размера s.size() для хранения длины наибольшего префикс-суффикса.
    for (int i = 1; i < s.size(); i++){
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i])
            j = pi[j - 1];
// Для каждого символа s[i] проверяется, можно ли его включить в префикс-суффикс предыдущего символа. Если нет, то j уменьшается до длины предыдущего префикс-суффикса.
        if (s[j] == s[i])
// Если s[j] == s[i], то длина префикс-суффикса увеличивается на 1.
            pi[i] = j + 1;
        else
            pi[i] = 0;
    }

    return pi;
}
// Эта функция использует KMP для поиска вхождений подстроки t в строку s. 
// Строка s расширяется добавлением строки t, разделенной символом #, чтобы исключить совпадения.
vector<int> kmp(string s, string t){
    s = t + '#' + s;
    vector<int> res;
    vector<int> pi = prefixFunction(s);
    for (int i = 0; i < s.size(); i++)
        if (pi[i] == t.size())
            res.push_back(i - 2 * t.size());
// Создается объединенная строка t + '#' + s.
// Вычисляется префикс-функция объединенной строки.
// Если элемент pi[i] равен длине t, это значит, что найдено полное вхождение t в s, 
// и в res добавляется смещение, соответствующее началу вхождения.
    return res;
}

// Эта функция проверяет, какие из городов в input_of_towns имеют наибольший суффикс, совпадающий с префиксом s.
vector<string> checkSuffixOfPrefix(vector<string> input_of_towns, string s, int n){
    vector<pair<string, int>> to_check;
    vector<string> ans;
    int maxi = 1;
    for (int i = 0; i < n; i++){
        vector<int> pi = prefixFunction(input_of_towns[i] + "#" + s);
        if (pi[pi.size() - 1] > maxi){
            maxi = pi[pi.size() - 1];
            to_check.clear();
            to_check.push_back({input_of_towns[i], pi[pi.size() - 1]});
        }
        else if (pi[pi.size() - 1] == maxi)
            to_check.push_back({input_of_towns[i], pi[pi.size() - 1]});
    }
    for (auto i : to_check)
        if (i.second == maxi)
            ans.push_back(i.first);
// Перебирает каждый город и проверяет длину наибольшего суффикса, совпадающего с префиксом строки s.
// Для каждого города input_of_towns[i] вычисляется префикс-функция объединенной строки input_of_towns[i] + "#" + s.
// Если текущая длина совпадения больше максимальной maxi, то список возможных городов очищается, добавляется новый город с текущей максимальной длиной совпадения.
// Если длина совпадает с текущим maxi, город добавляется в список.
// Результат возвращается как список городов, удовлетворяющих условиям задачи.
    return ans;
}
int main(){
    string to_check;
    vector<string> input_of_towns, ans;
    cin >> to_check;
    int n;
    cin >> n;
    to_check[0] = tolower(to_check[0]);
    for (int i = 0; i < n; i++){
        string towns;
        cin >> towns;
        towns[0] = tolower(towns[0]);
        input_of_towns.push_back(towns);
    }
    ans = checkSuffixOfPrefix(input_of_towns, to_check, n);
    cout << ans.size() << endl;

    for (int i = 0; i < ans.size(); i++){
        ans[i][0] = toupper(ans[i][0]);
        cout << ans[i] << endl;
    }

    return 0;
}