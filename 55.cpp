#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int len = nums.size() - 1;

    }
};

/**
 * class Solution {
 * public:
 *     bool canJump(vector<int>& nums) {
 *     int k = 0;
 *  	       for (int i = 0; i < nums.size(); i++){
 *		        if (i > k) return false;
 * 		        k = max(k, i + nums[i]);
 *	        }
 *	    return true;
 *      }
 * };
 * @return
 */

int main() {

    return 0;
}