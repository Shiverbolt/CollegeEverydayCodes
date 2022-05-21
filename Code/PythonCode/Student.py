n = int(input("Please enter number of students:"))

all_students = []

for i in range(0, n):
    stud_name = input('Enter the name of student: ')
    print (stud_name)

    stud_rollno = input('Enter the roll number of student: ')
    print (stud_rollno)

    mark1 = input('Enter the marks in subject 1: ')
    print (mark1)

    mark2 = input('Enter the marks in subject 2: ')
    print (mark2)

    mark3 = input('Enter the marks in subject 3: ')
    print (mark3)

    total = (mark1 + mark2 + mark3)
    print("Total is: ", total)

    average = total / 3
    print ("Average is :", average)

    all_students.append({
                            'Name': stud_name,
                            'Rollno': stud_rollno,
                            'Mark1': mark1,
                            'Mark2': mark2,
                            'Mark3': mark3,
                            'Total': total,
                            'Average': average
                            })

for student in all_students:
    print ('\n')
    for key, value in student.items():
        print ('{0}: {1}'.format(key, value))