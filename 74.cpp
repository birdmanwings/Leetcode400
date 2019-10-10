#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        if (target < matrix[0][0] || target > matrix.back().back()) {
            return false;
        }
        int left = 0, right = matrix.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target < matrix[mid][0]) {
                right = mid - 1;
            } else if (target > matrix[mid][0]) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        int tmp = right;
        left = 0;
        right = matrix[0].size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[tmp][mid] == target) {
                return true;
            } else if (matrix[tmp][mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};

int main() {

    return 0;
}