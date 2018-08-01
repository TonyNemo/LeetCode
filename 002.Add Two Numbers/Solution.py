# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# beats 75%
class Solution:
    def add_re(self, l, l1, l2, up):
        if l1!=None and l2!=None:
            l.next = ListNode((l1.val+l2.val+up)%10)
            self.add_re(l.next, l1.next, l2.next, 1 if (l1.val+l2.val + up)/10>=1 else 0)
        if l1==None and l2!= None:
            l.next = ListNode((l2.val+up)%10)
            self.add_re(l.next, None, l2.next, 1 if (l2.val+up)/10>=1 else 0)
        if l1!=None and l2==None:
            l.next = ListNode((l1.val+up)%10)
            self.add_re(l.next, l1.next, None, 1 if (l1.val+up)/10>=1 else 0)
        if l1==None and l2==None:
            if up!=0:
                l.next = ListNode(up)
                
                
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        l = ListNode((l1.val+l2.val)%10)
        self.add_re(l, l1.next, l2.next, 1 if (l1.val+l2.val)/10>=1 else 0)
        return l
        
    
            
        