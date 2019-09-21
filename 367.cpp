#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int i=1;
        while (num > 0) {
            num -= i;
            i+=2;
        }
        return num == 0;
    }
};

/*
class Solution {
public:
    bool isPerfectSquare(int num) {
        for (int i = 1; i * i <= num; i++) {
            if (i * i == num) {
                return true;
            }
        }
        return false;
    }
};
*/
int main() {

    return 0;
}