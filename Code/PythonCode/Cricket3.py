cricket = dict()
n = int(input('How many players?: '))
for i in range(0,n):
    x = input("Name of player: ")
    y = input("Score of player: ")
    cricket[x] = (y)
name=input("Enter player name to be searched: ")
if name in cricket:
    print("Score of ", x ,"is",cricket[x])
else:
    print("-1")

