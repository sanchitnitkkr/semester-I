# Q3) Program to check if a year is a leap year or not


def isLeapYear(year):
    if year % 100 == 0:
        if year % 400 == 0:
            return True
    elif year % 4 == 0:
        return True

    return False


def takeInput():
    year = int(input("Enter the year => "))
    return year


year = takeInput()
leapYear = isLeapYear(year)
print("The year", year, "is a" if leapYear else "is not a", "leap year")
