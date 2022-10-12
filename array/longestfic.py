arr=[0,2,5,8,100,2,3,5,8,11,5,8,13,21,34,2,3,5,8,13]
mx=arr
n=len(arr)
for i in range(4,n-1):
    v=[]
    if (arr[i]==(arr[i-1]+arr[i-2])):
        v.append(arr[i-2])
        v.append(arr[i-1]);
        print("hello\n")
        while(arr[i]==(arr[i-1]+arr[i-2])):
            v.append(arr[i])
            if(i+1<n):
                i=i+1
            else:
                break
        if len(v)<len(mx):
            mx=v
        print(i,": ",v)

print("ans: ",mx)
print(v)