# TEST 5
#include<vector>
using namespace std;
int D[100000][4];

int Max(int a, int b, int c){
    if(a > b)
        if( a > c) return a;
        else return c;
    else
        if(b > c) return b;
        else return c;
}

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int line = 0;
    D[0][0] = land[0][0];
    D[0][1] = land[0][1];
    D[0][2] = land[0][2];
    D[0][3] = land[0][3];
    for (vector<int>::size_type N = 1; N != land.size(); N++) {
        D[N][0] = land[N][0] + Max(D[N - 1][1], D[N - 1][2], D[N - 1][3]);
        D[N][1] = land[N][1] + Max(D[N - 1][0], D[N - 1][2], D[N - 1][3]);
        D[N][2] = land[N][2] + Max(D[N - 1][1], D[N - 1][0], D[N - 1][3]);
        D[N][3] = land[N][3] + Max(D[N - 1][1], D[N - 1][2], D[N - 1][0]);
        line++;
    }
    for (int i = 0; i < 4; i++) {
      if (answer < D[line][i]) answer = D[line][i];
    }
    return answer;
}
