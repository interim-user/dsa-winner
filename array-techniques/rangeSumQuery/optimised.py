class Solution:
    # @param A : list of integers
    # @param B : list of list of integers
     # @return an list of long
    def rangeSum(self, A, B):
        R = []
        for i in range(1,len(A)):
            A[i]+=A[i-1]
        for i in range(len(B)):
            if B[i][0]==0:
                R.append(A[B[i][1]])
            else:
                R.append(A[B[i][1]] - A[B[i][0] - 1])
        return R
