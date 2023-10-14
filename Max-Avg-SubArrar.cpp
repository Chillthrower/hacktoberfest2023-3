#include <iostream>
#include <vector>

//Maximum average of subarray

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        double avg = -1000 * k;
        double count(0);

        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (i >= k) {
                count -= nums[i - k];
            }

            if ((i + 1) >= k) {
                avg = std::max(avg, count);
            }
        }

        return avg / k;
    }
};

int main() {
    Solution solution;

    // Example usage:
    std::vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    double maxAvg = solution.findMaxAverage(nums, k);

    std::cout << "Maximum average of subarray of size " << k << " is: " << maxAvg << std::endl;

    return 0;
}
