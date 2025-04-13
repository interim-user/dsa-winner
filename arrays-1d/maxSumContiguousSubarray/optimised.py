# KADANE's Algo

class Solution:
    # @param A : tuple of integers
    # @return an integer
    def maxSubArray(self, A):
        max_sum = int('-inf')

        cur_sum = 0
        for i in range(len(A)):
            cur_sum += A[i]

            if cur_sum < 0:
                cur_sum = 0
            
            max_sum = max(cur_sum,max_sum)
        
        return max_sum
