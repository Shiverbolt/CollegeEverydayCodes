def Remove(duplicate):
    final_list = []
    for num in duplicate:
        if num not in final_list:
            final_list.append(num)
    return final_list
     
duplicate = input("Enter a string of numbers separated by comma: ")
data = duplicate.split(",")
print(Remove(duplicate))