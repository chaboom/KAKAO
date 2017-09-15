# TEST 6
include <vector>
using namespace std;
int dp[100000][2];
int solution(vector<int> sticker) {
	int answer = 0;
	int size = sticker.size();
	if (size == 1) return sticker[0];
	if (size == 2) return max(sticker[0], sticker[1]);

	dp[0][0] = sticker[0];
  dp[1][0] = dp[0][0];
  
	for (int N = 2; N < size - 1; N++) {
		dp[N][0] = max(dp[N - 1][0], dp[N - 2][0] + sticker[N]);
	}
	dp[size - 1][0] = dp[size - 2][0];
    
   dp[0][1] = 0;
	dp[1][1] = sticker[1];
    
	for (int N = 2; N < size; N++) {
		  dp[N][1] = max(dp[N - 1][1], dp[N - 2][1] + sticker[N]);
	}
    
	answer = max(dp[size - 1][0], dp[size - 1][1]);

	return answer;
}
