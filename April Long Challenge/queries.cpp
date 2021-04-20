#include <iostream>
#include <vector>
#include <utility>
#include <fstream>

using namespace std;

int main() {

  int N, M, Q;
  cin >> N >> M;
  int A[N][M];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      cin >> A[i][j];
  cin >> Q;

  int pref[N][M];
  for (int i = 0; i < N ; i++){
    for (int j = 0; j < M; j++) {
      pref[i][j] = A[i][j];
      if (i > 0) pref[i][j] += pref[i-1][j];
      if (j > 0) pref[i][j] += pref[i][j-1];
      if (i > 0 && j > 0) pref[i][j] -= pref[i-1][j-1];
    }
  }

  while (Q--) {
    int x1, y1, x2, y2 ;
    cin >> x1 >> y1 >> x2 >> y2;
    //x1 --; y1--; x2--; y2--;

    int sum = pref[x2][y2];
    if (y1 > 0) sum -= pref[x2][y1-1];
    if (x1 > 0) sum -= pref[x1-1][y2];
    if (x1 > 0 and y1 > 0) sum += pref[x1-1][y1-1];
    
    cout << sum << "\n";
  }

  return 0;
}

/*
3 3 
2 2 3
3 4 5
4 5 5
4
0 0 1 1
0 1 1 2
0 1 2 1
1 1 2 2
 */ 