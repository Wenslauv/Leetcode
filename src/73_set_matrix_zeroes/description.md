# Set Matrix Zeroes


### Links
[Leetcode task page](https://leetcode.com/problems/set-matrix-zeroes/)


### Problem
Given an `m x n` integer matrix `matrix`, if an element is `0`, set its entire row and column to `0`'s.

You must do it [in-place](https://en.wikipedia.org/wiki/In-place_algorithm).



### Examples
 
##### Example 1:

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]

Output: [[1,0,1],[0,0,0],[1,0,1]]


##### Example 2:

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]

Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]


### Constraints
- `m == matrix.length`
- `n == matrix[0].length`
- `1 <= m, n <= 200`
- `-231 <= matrix[i][j] <= 231 - 1`



### Solution

To solve this with O(1) space, we use first row and first column values as a flags that indicate this row/column has zero anywhere in it or not.
So:
1. Memorize if first row has zeroes in it (we need to keep this info, because some of row's values will be changed to zero lately).
2. Memorize if first column has zeroes for the same reasons.
3. Iterate over entire matrix to find zero cells and set their first column/row elements to zero.
4. Iterate over entire matrix again to change cell value to zero ONLY IF their first column/first row value is zero.
5. If first row had zeroes, set all first row to zeroes.
6. The same should be made also for first column.