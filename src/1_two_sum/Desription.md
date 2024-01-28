# Two Sum


### Links
[Leetcode task page](https://leetcode.com/problems/two-sum/)


### Problem
Given an array of integers `nums` and an integer `target`, return *indices of the two numbers such that they add up to `target`*.
You may assume that each input would have ***exactly** one solution*, and you may not use the *same* element twice.
You can return the answer in any order.


### Constraints
- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`
- **Only one valid answer exists.**


### Solution

Define complementary number CN for any number N  as a number such that CN + N = target.

While iterating over nums, for each nums[i] we calculate it's CN. 
If our hash map contains CN, we found required pair. Return it.
If not, we store pair [ CN, i ] in hash map and continue iterate.

### Complexity

- Time complexity: `O(N)`, because we have only one array pass.