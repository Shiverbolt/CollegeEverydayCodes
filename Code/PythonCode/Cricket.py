# main module/function
def main():

    namesScoresList = []
    max = None
    min = None
    print("Hi, Welcome to Golf Score Program")
    print("_________________________________")
    print()
# Enter input, leave blank to quit program
    while True:
        name = input("Player's name(leave blank for quit):").title()
        if name == "":
            break
        score = input("Player's score:")
        if name != "" and score != "":
            namesScoresList.append("{} {}".format(name, score))
        try:
            num = float(score)
        except:
            print("Invalid Input")
# Program that reads each player's name and golf score as input
# and Save them to golf.txt
    with open('golf.txt', 'w') as outfile:
        outfile.write("\n".join(namesScoresList))

# opens the "golf.txt" file created in the Golf Player Input python
# read lines one by one, splits them and print
    with open('golf.txt', 'r') as infile:
        for line in infile:
            # strip newline from field
            name, score = line.strip().split(" ")
            # prints the names and scores
            print(name, " scored ",  score)
# Display the lowest score 
    if min is None or num < min:
        min = num
    print('The lowest score is ', int(min))

# calls main function
main()