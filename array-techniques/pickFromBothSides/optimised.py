class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def solve(self, A, B):
        n = len(A)
        prefix_A = [0] * n
        prefix_A[0] = A[0]

        for i in range(1, n):
            prefix_A[i] = prefix_A[i - 1] + A[i]

        max_sum = float('-inf')
        
        for i in range(0, B + 1):
            left = i
            right = B - i

            # Left sum: first 'left' elements
            left_sum = prefix_A[left - 1] if left > 0 else 0

            # Right sum: last 'right' elements
            if right == 0:
                right_sum = 0
            else:
                total_sum = prefix_A[n - 1]
                exclude_left = prefix_A[n - right - 1] if n - right - 1 >= 0 else 0
                right_sum = total_sum - exclude_left

            cur_sum = left_sum + right_sum
            max_sum = max(max_sum, cur_sum)

        return max_sum
