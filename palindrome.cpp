#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int> d(s.length());
    int max_len = 0, pos;
    for (int j = 0; j < 2; j++) {
        d.assign(s.length(), 1 - j);
        for (int i = 0, l = 0, r = -1; i < s.length(); ++i) {
            if (i <= r) {
                d[i] = min(r - i + j, d[l + r - i + j]);
            }
            while (i + d[i] < s.length() && i - d[i] - j >= 0 && s[i + d[i]] == s[i - d[i] - j]) {
                ++d[i];
            }
            if (i + d[i] - 1 > r)
                l = i - d[i] + 1 - j,  r = i + d[i] - 1;
            if (d[i] * 2 - 1 + j > max_len) {
                max_len = d[i] * 2 - 1 + j;
                pos = i;
            }
        }
    }
    cout << s.substr(pos - max_len / 2, max_len);
    return 0;
}
