#include <stdio.h>
#define max(x,y) x>y?x:y

char s1[5001], s2[5001];
int i, j, d[5001][5001];

int main() {
  scanf("%s%s", s1, s2);
  for (; s1[i]; ++i)
    for (j = 0; s2[j]; ++j)
      if (s1[i] == s2[j])
        d[i + 1][j + 1] = d[i][j] + 1;
      else
        d[i + 1][j + 1] = max(d[i + 1][j], d[i][j + 1]);
  printf("%d", d[i][j]);
  return 0;
}
