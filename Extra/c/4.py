# frequency of elements in the array

def count_freq(arr):
    freq={}

    for element in arr:
        if element in freq:
            freq[element]+=1
        else:
            freq[element]=1
    
    for element,count in freq.items():
        print(f"Element {element} occurs {count} times.")

arr=[1,1,5,3,3,6,6,7,8,8,8,8]
count_freq(arr)
