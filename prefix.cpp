#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int p;
char s[400000];

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%s", s);
    p = strlen(s);
    s[strlen(s)] = '#';
    ++p;
    scanf("%s", s + p);

    vector<int> prefix(p);
    int j = 0;
    for (int i = 1; s[i] != 0; ++i) {
        while (j > 0 && s[i] != s[j]) {
            j = prefix[j - 1];
        }
        if (s[i] == s[j])
            ++j;
        if (i < p)
            prefix[i] = j;
        if (j >= p - 1) {
            printf("%d ", i - p * 2 + 2);
        }
    }
    return 0;
}
