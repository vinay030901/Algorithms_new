def find_number(arr):
    arr = list(set(arr))  # Remove duplicates from the array

    squares = set()

    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):
            num = arr[i] ** 2 + arr[j] ** 2
            if num in squares:
                return num
            squares.add(num)

    return False


# Input length of the array
n = int(input())

# Input the array elements
arr = list(map(int, input().split()))

result = find_number(arr)
print(result)
