#include <iostream>
#include <vector>

using namespace std;

class KiwiJuiceEasy {
public:
    vector<int> thePouring(vector<int> capacities, vector<int> bottles, vector<int> fromId, vector<int> toId) {
        for (int i = 0; i < fromId.size(); i++) {
            int sum = bottles[fromId[i]] + bottles[toId[i]];
            bottles[toId[i]] = min(sum, capacities[toId[i]]);
            bottles[fromId[i]] = sum - bottles[toId[i]];
        }

        return bottles;
    }
};
