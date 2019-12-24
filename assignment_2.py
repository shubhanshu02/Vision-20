import numpy as np

n = int(input("Enter the order of square matrix: "))
a = np.empty((n, n), dtype='int')

print("Enter the square matrix. \nEnter one element at a time row-wise.")
for i in range(n):
    for j in range(n):
        a[i, j] = int(input())

print("You entered:\n", a, '\n')

# sum of rows
hsum = np.sum(a, axis=0)
# sum of columns
vsum = np.sum(a, axis=1)
# sum of diagonals
d1 = np.diag(a)
sum1 = np.sum(d1)
d2 = np.diag(np.fliplr(a))
sum2 = np.sum(d2)


if (sum1 != sum2):
    print('No') #Diagonal sum not equal
else:
    #Check if sum of all rows is equal
    hvalue = hsum[0]
    for i in range(0, hsum.size - 1):
        if (hsum[i + 1] != hsum[i]):
            hvalue = False
            break

    #Check if sum of all columns is equal
    vvalue = vsum[0]
    for i in range(0, vsum.size - 1):
        if (vsum[i + 1] != vsum[i]):
            vvalue = False
            break

    if ((hvalue == False) or (vvalue == False)):
        print('No') #Sum of Rows/Columns not equal
    else:
        if (hvalue == vvalue == sum1):
            print('Yes') #Sum of rows, columns and diagonals is equal

        else:
            print('No')