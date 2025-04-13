MOD_VAL = 1000000009

class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return a list of integers
    def solve(self, A, B):
        A_rotated = [0]*len(A)

        for i in range(len(A)):
            A_rotated[((i % MOD_VAL + B % MOD_VAL) % MOD_VAL) % len(A)] = A[i]
        
        return A_rotated
