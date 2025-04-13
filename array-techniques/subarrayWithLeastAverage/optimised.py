class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def solve(self, A, B):
        min_sliding_window_start = 0
        sliding_window_sum = sum(A[:B])
        # print(sliding_window_sum," :: ",end=", ")

        # least average ~~ least sum (since, number of elements is constant, i.e. B)
        min_sum = sliding_window_sum
        for i in range(1,len(A)-B+1):
            sliding_window_sum = sliding_window_sum - A[i-1] + A[i+B-1]
            # print(sliding_window_sum,end=", ")
            if sliding_window_sum < min_sum:
                min_sum = sliding_window_sum
                min_sliding_window_start = i
        
        return min_sliding_window_start
