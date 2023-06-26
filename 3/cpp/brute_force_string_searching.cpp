#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int brute_force(const string &text, const string &pattern) {
    size_t pat_l = pattern.length();
    size_t txt_l = text.length();
    if (pat_l <= txt_l)
        for (size_t i = 0; i < txt_l - pat_l + 1; i++)
            if (text.substr(i, pat_l) == pattern)
                return i
    return -1;
}
int main() {
    const vector<vector<string>> test_set = {
        // {text, pattern, expected output}
        {"a", "aa", "-1"},  {"a", "a", "0"},    {"ba", "b", "0"},
        {"bba", "bb", "0"}, {"bbca", "c", "2"}, {"ab", "b", "1"}
    };
    for (const auto &i : test_set) {
        int output = brute_force(i[0], i[1]);
        cout << (to_string(output) == i[2] ? "success\n":"failure\n");
    }
    return 0;
}
