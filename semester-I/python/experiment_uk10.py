students = {
    "Sanchit" : 99,
    "Aman" : 97,
    "Rahul" : 55,
    "MarKE": 66
}

for i in students.keys():
    if students[i] > 75:
        print(f"{i} has passed")