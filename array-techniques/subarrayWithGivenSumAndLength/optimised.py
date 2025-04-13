class Solution:
    # @param A : list of integers
    # @param B : integer
    # @param C : integer
    # @return an integer
    def solve(self, A, B, C):
        # this stores the running sum for the
        # sliding window of fixed length B

        window_sum = sum(A[:B])

        if window_sum == C:
            return 1
        
        for i in range(1,len(A)-B):
            window_sum = window_sum - A[i-1] + A[i+B-1]
            if window_sum == C:
                return 1

        return 0
        
