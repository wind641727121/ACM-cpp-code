#include <cstdio>
#include <cstring>
const int N = 1010;
char a[N], b[N];
int next[N];
int lena, lenb;

void getFail() {
    next[0] = -1;
    int i = 0, j = -1;
    while (i < lenb) {
        if (j == -1 || b[i] == b[j]) {
            i++; j++;
            next[i] = j;
        }
        else j = next[j];
    }
}

void init() {
    lena = strlen(a);
    lenb = strlen(b);
    getFail();

}

void solve() {
    int i = 0, j = 0, ans = 0;
    while (i < lena) {
        if (j == -1 || a[i] == b[j]) {
            i++; j++;
            if (j == lenb) {
                ans++;
                j = 0;
            }
        }
        else j = next[j];
    }
    printf("%d\n", ans);
}

int main() {
    while (scanf("%s", a) != EOF && a[0] != '#') {
        scanf("%s", b);
        init();
        solve();
    }
    return 0;
}
