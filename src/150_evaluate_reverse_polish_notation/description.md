# Evaluate Reverse Polish Notation


### Links
[Leetcode task page](https://leetcode.com/problems/evaluate-reverse-polish-notation/)
[Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation)


### Problem
Given an `m x n` integer matrix `matrix`, if an element is `0`, set its entire row and column to `0`'s.

You must do it [in-place](https://en.wikipedia.org/wiki/In-place_algorithm).


You are given an array of strings `tokens` that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return *an integer that represents the value of the expression*.

**Note** that:
- The valid operators are `'+'`, `'-'`, `'*'`, and `'/'`.
- Each operand may be an integer or another expression.
- The division between two integers always **truncates toward zero**.
- There will not be any division by zero.
- The input represents a valid arithmetic expression in a reverse polish notation.
- The answer and all the intermediate calculations can be represented in a **32-bit** integer.




### Examples
 
##### Example 1:

Input: tokens = ["2","1","+","3","*"]

Output: 9


##### Example 2:

Input: tokens = ["4","13","5","/","+"]

Output: 6


##### Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]

Output: 22


### Constraints
- `1 <= tokens.length <= 104`
- `tokens[i]` is either an operator: `"+"`, `"-"`, `"*"`, or `"/"`, or an integer in the range `[-200, 200]`.




### Solution

A nice description is in Wiki already, but I describe it with mmy own words. 

We should do simple algorithm: for each token, it's a number or an operation. If it's a number, put it on a stack. If it's an operation, remove the top two numbers from the stack, perform that operation and put result on the stack.

In the end, there's should be only one number in the stack, that's the answer.