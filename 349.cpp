#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s(nums1.begin(),nums1.end()),res;
        for (auto a:nums2) {
            if (s.count(a))
                res.insert(a);
        }
        return vector<int>(res.begin(), res.end());
    }
};

int main() {

    return 0;
}