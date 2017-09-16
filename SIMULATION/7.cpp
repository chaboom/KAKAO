# TEST 7
include <iostream>
include <string>
include <vector>
define min(a,b) ((a>b)?(b):(a))
using namespace std;

int solution(vector<string> strs, string t)
{
	int answer = 0;
	int maximum = t.size(); // 찾고자 하는 문자열의 길이

	int i, j, p, q;
	int result[20000];

	for (i = 0; i < maximum; i++)
	{
		// 디폴트 값으로 최대값 + 1 을 설정하여 불가능한 값으로 설정
		result[i] = maximum + 1;

		for (j = 0; j < strs.size(); j++)
		{
			// 현재 위치부터 역으로 탐색하여 부분문자열이 맞는지 확인
			p = strs[j].size() - 1;
			for (q = 0; q < strs[j].size(); q++)
			{
				if (!(p - q < 0 || i - q < 0) && strs[j][p - q] == t[i - q])
					continue;
				else
					break;
			}

			// 해당 부분문자열이 모두 포함된다면, 결과값 계산
			if (q == strs[j].size())
			{
				// 부분문자열로 완성시키전의 최소값 + 1
				if (i - q >= 0)
				{
					result[i] = min(result[i], 1 + result[i - q]);
				}
				// 처음 부분문자열을 완성한 것이라면 1로 설정
				else
				{
					result[i] = 1;
				}
			}
		}
	}

	// 전체 정답은 문자열의 마지막 원소의 Result값
	answer = result[maximum - 1];

	// 만약 불가능한 값(디폴트값)이 정답이라면 불가능한 경우이므로 -1 리턴
	if (answer == maximum + 1) answer = -1;

	return answer;
}
