def main():
    Birthdays ={"Albert Einstein": "14/3/1889",
                "Bill Gates": "28/10/1955",
                "Steve Jobs": "24/2/1955"}
    print('Welcome to the birthday dictionary.')
    query = input("Who's birthday do you want to look up?")
    result = Birthdays[query] if query in Birthdays else None
    if result == None:
        print('No Data')
    else:
        print("{}'s birthday is {}".format(query, Birthdays[query]))
    
        
if __name__ == "__main__":
    main()