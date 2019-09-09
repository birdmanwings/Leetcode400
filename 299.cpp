#include <iostream>
#include <vector>

using namespace std;

/*
 *  第一次循环先遍历两个字符串，找到bulls，当不是bulls建立两个数组进行记录数字出现次数，最后循环累加更小的交集为cows
 *  时间复杂度两次遍历为O(2N),空间复杂度为O(2N)
 */
class Solution {
public:
    string getHint(string secret, string guess) {
        int count = secret.size();
        int hash1[10] = {0}, hash2[10] = {0};
        int bulls = 0, cows = 0;
        for (int i = 0; i < count; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                hash1[secret[i] - '0']++;
                hash2[guess[i] - '0']++;
            }
        }
        for (int i = 0; i < 10; i++) {
            cows += min(hash1[i], hash2[i]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

int main() {
    string A = "1807", B = "7810";
    Solution S;
    cout << S.getHint(A, B) << endl;
    return 0;
}