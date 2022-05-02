
import java.util.Arrays;

public class Solution {

    public int minimumAverageDifference(int[] nums) {
        long totalSum = Arrays.stream(nums).asLongStream().sum();
        long sumFirstPart = 0;
        int minAverageDifference = Integer.MAX_VALUE;
        int indexMinAverageDifference = 0;
        final int size = nums.length;

        for (int i = 0; i < size; ++i) {
            sumFirstPart += nums[i];
            int avarageFirstPart = (int) (sumFirstPart / (i + 1));
            int avarageSecondPart = (size - 1 - i) > 0 ? (int) ((totalSum - sumFirstPart) / (size - 1 - i)) : 0;

            if (Math.abs(avarageFirstPart - avarageSecondPart) < minAverageDifference) {
                indexMinAverageDifference = i;
                minAverageDifference = Math.abs(avarageFirstPart - avarageSecondPart);
            }
        }
        return indexMinAverageDifference;
    }
}
