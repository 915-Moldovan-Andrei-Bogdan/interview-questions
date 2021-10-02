
"""
facebook interview question->Starting at index 0, for an element n at index i, you are allowed to jump at most n indexes ahead.
Given a list of numbers, find the minimum number of jumps to reach the end of the list.
Input: [3, 2, 5, 1, 1, 9, 3, 4]
Output: 2
"""


def find_local_best(arr,sp,init,final):
    if sp>final:
        return final
    maxx=0
    i=0
    while sp!=init:
        if sp+arr[sp]>maxx:
            maxx=sp+arr[sp]
            i=sp
        sp-=1
    if sp+arr[sp]>maxx:
        maxx=sp+arr[sp]
        i=sp
    return i

def jumptoend(nums):
    end=len(nums)-1
    current=0
    jumps=0
    while current<end:
        if current+nums[current]>=end:
            jumps+=1
            return jumps
        else:
            var=find_local_best(nums,current+nums[current],current,end)
            if var==current:
                current+=nums[current]
                jumps+=1
            else:
                current=var
                jumps+=1
    return jumps


if __name__=="__main__":
    print(jumptoend([1,11,1,3,1,1,1]))
