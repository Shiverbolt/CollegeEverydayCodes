print("-----Program for Cricket Scoreboard-----")
  
Cricket=dict()
  
n = int(input('How many players?? '))
  

for i in range(0,n):
    x = input("Enter the name of player: ")
    y = input("Enter score: ")
    Cricket[x] = (y)
def score(fname):
    ls = list()
      
    for sname,score in Cricket.items():
        
        tup=(sname,score)
        ls.append(tup)
          
    for i in ls: 
        if i[0][0] == fname:
            print(i[1][0])
    return 
           
player = input('Enter first name of student: ')
score(player)

