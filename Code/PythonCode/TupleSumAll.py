def test(lst):
    result =  map(sum, lst)
    return list(result)

nums = [(1,2), (2,3), (3,4)]
print("\nSum of all the elements of each tuple stored inside the said list of tuples:")
print(test(nums))
