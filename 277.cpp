#include <iostream>
#include <vector>

using namespace std;

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int i;
        int j;
        for (i = 0, j = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                if (i != j && (knows(i, j) || !knows(j, i))) {
                    break;
                }
            }
            if (j == n) return i;
        }
        return -1;
    }
};

int main() {

    return 0;
}