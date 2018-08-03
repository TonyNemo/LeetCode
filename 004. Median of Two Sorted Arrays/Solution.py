# merge then get median, does not fit 
class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        
        # O(m+n)
        n, m = len(nums1), len(nums2)
        if n==0:
            return (nums2[int(m/2)]+nums2[int(m/2 -1)])/2 if m%2==0 else nums2[int((m-1)/2)]
        if m==0:
            return (nums1[int(n/2)]+nums1[int(n/2 - 1)])/2 if n%2==0 else nums1[int((n-1)/2)]
        # merge
        merge = []
        i, j =0,0
        while i<n and j<m:
            if nums1[i]<nums2[j]:
                merge.append(nums1[i])
                i+=1
            elif nums1[i] > nums2[j]:
                merge.append(nums2[j])
                j+=1
            else: 
                merge.append(nums1[i])
                merge.append(nums2[j])
                i+=1
                j+=1
        while i==n and j<m:
            merge.append(nums2[j])
            j+=1
        while i<n and j<m:
            merge.append(nums1[i])
            i+=1
        
        return (merge[int((n+m)/2)] + merge[int((n+m)/2-1)])/2 if (n+m)%2==0 else merge[int((n+m-1)/2)]
    

class Solution:
    def findMedianSortedArrays(self, A, B):
        l = len(A) + len(B)
        if l % 2 == 1:
            return self.kth(A, B, l // 2)
        else:
            return (self.kth(A, B, l // 2) + self.kth(A, B, l // 2 - 1)) / 2.   
    
    def kth(self, a, b, k):
        if not a:
            return b[k]
        if not b:
            return a[k]
        ia, ib = len(a) // 2 , len(b) // 2
        ma, mb = a[ia], b[ib]

        # when k is bigger than the sum of a and b's median indices 
        if ia + ib < k:
            # if a's median is bigger than b's, b's first half doesn't include k
            if ma > mb:
                return self.kth(a, b[ib + 1:], k - ib - 1)
            else:
                return self.kth(a[ia + 1:], b, k - ia - 1)
        # when k is smaller than the sum of a and b's indices
        else:
            # if a's median is bigger than b's, a's second half doesn't include k
            if ma > mb:
                return self.kth(a[:ia], b, k)
            else:
                return self.kth(a, b[:ib], k)
        