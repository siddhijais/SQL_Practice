class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax)
                    leftMax = height[left];        // Update left max
                else
                    water += leftMax - height[left]; // Trap water on left side
                left++;
            } else {
                if (height[right] >= rightMax)
                    rightMax = height[right];      // Update right max
                else
                    water += rightMax - height[right]; // Trap water on right side
                right--;
            }
        }

        return water;
    }
};
