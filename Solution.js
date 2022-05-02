
/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumAverageDifference = function (nums) {
    let totalSum = nums.reduce((x, y) => x + y);
    let sumFirstPart = 0;
    let minAverageDifference = Number.MAX_SAFE_INTEGER;
    let indexMinAverageDifference = 0;
    const size = nums.length;

    for (let i = 0; i < size; ++i) {
        sumFirstPart += nums[i];
        let avarageFirstPart = Math.trunc(sumFirstPart / (i + 1));
        let avarageSecondPart = (size - 1 - i) > 0 ? Math.trunc((totalSum - sumFirstPart) / (size - 1 - i)) : 0;

        if (Math.abs(avarageFirstPart - avarageSecondPart) < minAverageDifference) {
            indexMinAverageDifference = i;
            minAverageDifference = Math.abs(avarageFirstPart - avarageSecondPart);
        }
    }
    return indexMinAverageDifference;
};
