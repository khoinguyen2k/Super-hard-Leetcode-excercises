#include <iostream>
#include <string.h>

using namespace std;

int LCS(char* s1, char* s2, int len1, int len2){
  int lengths[len1+1][len2+1];
  
  int longest = 0;

  for (int i = 0; i <= len1; i++){
    for (int j = 0; j <= len2; j++){
      if (i == 0 && j == 0) lengths[0][0] = 0;
      else if (s1[i-1] == s2[j-1]){
        lengths[i][j] = lengths[i-1][j-1] + 1;
        longest = max(longest, lengths[i][j]);
      }
      else {
        lengths[i][j] = 0;
      }
    }
  }
  return longest;
}

int main() {
  freopen("LCS2.inp", "r", stdin);
  freopen("LCS2.out", "w", stdout);
  char x[3000],y[3000];
  cin >> x;
  cin >> y;
  cout << LCS(x, y, strlen(x), strlen(y)) << endl;
}