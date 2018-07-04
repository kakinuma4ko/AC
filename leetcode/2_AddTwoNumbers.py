# # Definition for singly-linked list.
# # class ListNode(object):
# #     def __init__(self, x):
# #         self.val = x
# #         self.next = None

# class Solution(object):
#     def addTwoNumbers(self, l1, l2):
#         """
#         :type l1: ListNode
#         :type l2: ListNode
#         :rtype: ListNode
#         """
#         result = ListNode(l1.val + l2.val)
#         temp = result
#         while True:
#             l1 = l1.next
#             l2 = l2.next
#             if l1 == None or l2 == None:
#                 break
#             result.next = ListNode(l1.val + l2.val)
#             result = result.next
#         if l1 == None and l2 == None:
#             pass
#         elif l1 == None:
#             while l2 != None:
#                 result.next = ListNode(l2.val)
#                 result = result.next
#                 l2 = l2.next
#         elif l2 == None:
#             while l1 != None:
#                 result.next = ListNode(l1.val)
#                 result = result.next
#                 l1 = l1.next
        
#         result = temp
#         while True:
#             if temp.val > 9:
#                 if temp.next == None:
#                     temp.next = ListNode(temp.val/10)
#                     temp.val = temp.val%10
#                     return result
#                 else:
#                     temp.next.val += temp.val/10
#                     temp.val = temp.val%10
#             if temp.next == None:
#                 return result
#             temp = temp.next

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        result = ListNode(l1.val + l2.val)
        temp = result
        while True:
            l1 = l1.next
            l2 = l2.next
            if l1 == None or l2 == None:
                break
            result.next = ListNode(l1.val + l2.val)
            result = result.next
        if l1 == None and l2 == None:
            pass
        elif l1 == None:
            while l2 != None:
                result.next = ListNode(l2.val)
                result = result.next
                l2 = l2.next
        elif l2 == None:
            while l1 != None:
                result.next = ListNode(l1.val)
                result = result.next
                l1 = l1.next
        
        result = temp
        while True:
            if temp.val > 9:
                if temp.next == None:
                    temp.next = ListNode(temp.val/10)
                    temp.val = temp.val%10
                    return result
                else:
                    temp.next.val += temp.val/10
                    temp.val = temp.val%10
            if temp.next == None:
                return result
            temp = temp.next
