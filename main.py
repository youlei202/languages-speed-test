# O(n^2) algorithm
class Solution(object):
    def numSubarrayBoundedMax(self, A, L, R):
        """
        :type A: List[int]
        :type L: int
        :type R: int
        :rtype: int
        """
        i = 0
        count = 0
        while i<len(A):
            j = i
            ij_max = A[i]
            while j<len(A):
                if ij_max < A[j]:
                    ij_max = A[j]
                if ij_max >= L and ij_max <= R:
                    count += 1
                j += 1
            if j < len(A): i = j + 1
            else: i += 1

        return count

def main():
    # my code here

    read = []
    with open('input.txt', 'r') as f:
        for line in f:
            for x in line.split(' '):
                if len(x) > 0:
                    read.append(int(x))

    A = read[1:read[0]]
    L = read[-2]
    R = read[-1]



    print Solution().numSubarrayBoundedMax(A,L,R)


if __name__ == "__main__":
    main()
