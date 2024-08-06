#arrange the elements in half increasing and half decresing order

def arrange(arr):
    arr.sort()
    mid=len(arr)//2
    first_half=arr[:mid]
    last_half=arr[mid:]
    last_half.reverse()

    result=first_half+last_half
    return result

arr=[2,4,5,1,7,9,10,34,22,6,77,88]

print(arrange(arr))
