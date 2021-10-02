class Solution {
    public int search(int[] nums, int target) {
        int index = findPivotIndex(nums, 0, nums.length - 1);

        int ans = binarySearch(nums, 0, index, target);

        if (ans != -1)
            return ans;
        return binarySearch(nums, index + 1, nums.length - 1, target);
    }

    public int findPivotIndex(int[] arr, int start, int end) {
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (mid < end && arr[mid] > arr[mid + 1])
                return mid;
            if (mid > start && arr[mid] < arr[mid - 1])
                return mid - 1;
            if (arr[mid] <= arr[start])
                end = mid - 1;
            else
                start = mid + 1;
        }
        return -1;
    }

    private int binarySearch(int[] nums, int start, int end, int target) {
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1;
    }
}
