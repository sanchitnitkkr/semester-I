# Q1 Program to calculate compound interest


def findCompoundInterest(interest, principal, tenure, timePeriod="annually"):
    # Formula: A = P(1+r/n) ^ (nt)
    r = interest # Rate of interest 
    n = 1 # No of times compounded
    t = tenure # Duration or time period
    p = principal # Principal

    match timePeriod:
        case "annually":
           n = 1
        case "monthly":
            n = 12
        case "quarterly":
            n = 3
        case "half-yearly":
            n = 6

    compoundedAmount = p * ((1 + (r/(n*100))) ** (n*t))

    return round(compoundedAmount)


def takeInput():
    interest = float(input("What is the interest percentage => "))
    principal = float(input("What is the principal amount => "))
    tenure = float(input("What is the tenure (in years) => "))

    return {"principal": principal, "tenure": tenure, "interest": interest}


inputData = takeInput()

compoundedAmount = findCompoundInterest(
    interest=inputData["interest"],
    principal=inputData["principal"],
    tenure=inputData["tenure"],
)

print("Compounded Amount =>", compoundedAmount)
