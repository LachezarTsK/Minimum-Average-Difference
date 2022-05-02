
#include <numeric>
#include <vector>
using namespace std;

class Solution {
    
public:
    int minimumAverageDifference(const vector<int>& nums) {
        long totalSum = accumulate(nums.begin(), nums.end(), static_cast<long long> (0));
        long sumFirstPart = 0;
        int minAverageDifference = INT_MAX;
        int indexMinAverageDifference = 0;
        const size_t size = nums.size();

        for (int i = 0; i < size; ++i) {
            sumFirstPart += nums[i];
            int avarageFirstPart = sumFirstPart / (i + 1);
            int avarageSecondPart = (size - 1 - i) > 0 ? (totalSum - sumFirstPart) / (size - 1 - i) : 0;

            if (abs(avarageFirstPart - avarageSecondPart) < minAverageDifference) {
                indexMinAverageDifference = i;
                minAverageDifference = abs(avarageFirstPart - avarageSecondPart);
            }
        }
        return indexMinAverageDifference;
    }
};
