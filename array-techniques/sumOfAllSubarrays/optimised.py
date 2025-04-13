# contribution technique based approach

class Solution:
    # @param A : list of integers
     # @return an long
    def subarraySum(self, A):
        total = 0
        for i in range(len(A)):
            # count the number of subarrays that contain
            # the ith index element

            # no. of ways to choose starting point
            s = (i) - (0) + 1 

            # no. of ways to choose ending point
            e = (len(A) - 1) - (i) + 1

            occ_count = s * e 

            cur_contrib = occ_count * A[i]

            total += cur_contrib
        
        return total
