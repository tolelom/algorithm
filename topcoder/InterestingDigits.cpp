#include <vector>
using namespace std;

class InterestingDigits {
public:
	vector<int> digits(int base) {
		//base 주어지고 4자리수 까지 확인 
		vector <int> ans;

		for (int i = 2; i < base; i++) {
			if (((base - 1) % i) == 0)
				ans.push_back(i);  
		}
		return ans;
	}
};