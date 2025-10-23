#include <stdio.h>
#include <string.h>

#define MAX_PHONE_LENGTH 10

/**
 * Write a program to create a structure named company which has name, address, phone no of employees as member variables.
 * Read the name of the company, its address, phone no of employees.
 * Finally, display these memeber's values.
 */

struct Company
{
    char name[50];
    char address[100];
    int employeeCount;
    char **phoneNumbers; // array of string pointers
    
};

int main()
{
    int noOfCompanies = 0;
    int numPhoneNumbers;

    printf("Enter the number of companies you want to register: ");
    scanf("%d", &noOfCompanies);

    while (getchar() != '\n') ; // clear newline

    struct Company companies[noOfCompanies];

    // Take in input all companies
    for (int i = 0; i < noOfCompanies; i++)
    {
        struct Company newCompany;

        printf("Please enter the following details for Company %d: \n", i + 1);
        printf("Name => ");
        fgets(newCompany.name, sizeof(newCompany.name), stdin);
        newCompany.name[strcspn(newCompany.name, "\n")] = '\0'; // Remove trailing newline

        printf("Address => ");
        fgets(newCompany.address, sizeof(newCompany.address), stdin);
        newCompany.address[strcspn(newCompany.address, "\n")] = '\0'; // Remove trailing newline

        printf("Employee Count => ");
        scanf("%d", &newCompany.employeeCount);

        while (getchar() != '\n')
            ; // discard leftover newline

        printf("How many phone numbers? ");
        scanf("%d", &numPhoneNumbers);
        while (getchar() != '\n')
            ; // clear leftover newline

        // Create space for phone numbers
        newCompany.phoneNumbers = malloc(numPhoneNumbers * sizeof(char *)); // array of n pointers

        for (int j = 0; j < numPhoneNumbers; j++)
        {
            newCompany.phoneNumbers[j] = malloc((MAX_PHONE_LENGTH + 1) * sizeof(char)); // each string
        }

        for (int j = 0; j < numPhoneNumbers; j++)
        {
            printf("Enter phone number %d: ", i + 1);
            fgets(newCompany.phoneNumbers[i], MAX_PHONE_LENGTH + 1, stdin);
            newCompany.phoneNumbers[j][strcspn(newCompany.phoneNumbers[j], "\n")] = '\0';
        }

        companies[i] = newCompany;
    }

    // Print all the companies
    printf("\n\n===SUMMARY===\n");
    printf("Here is a summary of the details you entered\n");
    for (int i = 0; i < noOfCompanies; i++)
    {
        printf("Company - \"%s\" with the address %s and employee count of %d\n\n", companies[i].name, companies[i].address, companies[i].employeeCount);
        printf("The phone numbers of employees are:\n");
        for (int j = 0; j < numPhoneNumbers; j++)
        {
            printf("Phone number %s: \n", companies[i].phoneNumbers[j]);
        }
    }
    return 0;
}