X = [[65,71,23],
    [14 ,51,46],
    [72 ,58,90]]

Y = [[15,18,11],
    [26,73,31],
    [47,57,79]]
sum = [[0,0,0],
         [0,0,0],
         [0,0,0]]
for i in range(len(X)):
   
   for j in range(len(X[0])):
       sum[i][j] = X[i][j] + Y[i][j]

for a in sum:
   print(a)