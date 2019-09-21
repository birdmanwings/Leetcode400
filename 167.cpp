#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        int n;
        while (left < right) {
            n = numbers[left] + numbers[right];
            if (n == target) {
                return {left + 1, right + 1};
            } else if (n < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};

int main() {

    return 0;
}