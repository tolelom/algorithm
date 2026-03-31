#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class InterestingParty {
public:
	int bestInvitation(vector <string> first, vector <string> second) {
		map <string, int> dic;


		for (int i = 0; i < first.size(); i++) {
			dic[first[i]] = 0;
			dic[second[i]] = 0;
		}
		for (int i = 0; i < first.size(); i++) {
			dic[first[i]]++;
			dic[second[i]]++;
		}

		int ans = 0;
		map <string, int> ::iterator it;

		for (it = dic.begin(); it != dic.end(); it++) {
			ans = max(ans, it->second);
		}

		return ans;
	}
};