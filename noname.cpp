#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;
char change(char c) {
	const int diff = 'a' - 'A'; //32
	if (c >= 'A' && c <= 'Z')
		c += diff;
	return c;
}
int solution(string str1, string str2) {
	int answer = 0;
	vector<string> A;
	vector<string> B;

	for (int i = 0; i < str1.length() - 1; i++) {
		string temp = "";
		if ((str1[i] >= 'a' && str1[i] <= 'z') || (str1[i] >= 'A' && str1[i] <= 'Z')) {			
			temp = change(str1[i]);;
		}
		for (int j = i + 1; j < str1.length(); j++) {
			if ((str1[j] >= 'a' && str1[j] <= 'z') || (str1[j] >= 'A' && str1[j] <= 'Z')) {				
				temp += change(str1[j]);;
				A.push_back(temp);
				break;
			}
		}
	}
	for (int i = 0; i < str2.length() - 1; i++) {
		string temp = "";
		if ((str2[i] >= 'a' && str2[i] <= 'z') || (str2[i] >= 'A' && str2[i] <= 'Z')) {
			temp = change(str2[i]);;
		}
		for (int j = i + 1; j < str2.length(); j++) {
			if ((str2[j] >= 'a' && str2[j] <= 'z') || (str2[j] >= 'A' && str2[j] <= 'Z')) {
				temp += change(str2[j]);;
				B.push_back(temp);
				break;
			}
		}
	}
	double kyo = 0;
	//for (int i = 0; i < A.size(); i++) {
	//	cout << A[i] << endl;
	//}
	//for (int i = 0; i < B.size(); i++) {
	//	cout << B[i] << endl;
	//}
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B.size(); j++) {
			if (A[i] == B[j]) kyo++;
		}
	}
	double hap = A.size() + B.size() - kyo;
	double jakad = kyo / hap;
	answer = jakad * 65536;
	return answer;
}
int main()
{
	string str1 = "FRANCE";
	string str2 = "french";
	//vector<int> arr2 = { 30,1,21,17,28 };
	int ans;
	ans = solution(str1,str2);
	cout << ans;
	return 0;
}
