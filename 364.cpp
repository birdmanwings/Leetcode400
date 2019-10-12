#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int res=0;
        vector<int> v;
        for (auto a:nestedList) {
            helper(a, 0, v);
        }
        for (int i = v.size() - 1; i >= 0; i--) {
            res += (v.size() - i) * v[i];
        }
        return res;
    }

    void helper(NestedInteger a, int depth, vector<int> &v){
        if (depth >= v.size()) v.resize(depth + 1); //逐步扩容
        if (a.isInteger()) {
            v[depth] += a.getInteger();
        } else {
            for (auto a : a.getList()) {
                helper(a, depth + 1, v);
            }
        }
    }
};

int main() {

    return 0;
}