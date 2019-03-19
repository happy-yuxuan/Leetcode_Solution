/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (42.66%)
 * Total Accepted:    327.6K
 * Total Submissions: 763.1K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 * 
 * 
 * 
 * 
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49. 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * 
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;   // [l, r]
        int maxArea = -1;
        while ( l < r ) {
            int tmp = containValue(r-l, height[l], height[r]);
            maxArea = max(maxArea, tmp);
            if (height[l] < height[r]) {
                ++l;
            } else if (height[l] > height[r]) {
                --r;
            } else {    // height[l] == height[r]
                if (r - l >= 2) {
                    int left = containValue(r-l, height[l], height[r-1]);
                    int right = containValue(r-l, height[l+1], height[r]);
                    tmp = max(left, right);
                    maxArea = max(tmp, maxArea);
                }
                ++l;
                --r;     
            }
        }
        return maxArea;
    }
private:
    int containValue(int x, int lh, int rh) {
        int height = lh < rh ? lh : rh;
        return height * x;
    }
};

