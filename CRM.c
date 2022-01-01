#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct acct
{
    char name[50];
    unsigned long long int mobile;
    int age;
    float balance;
} customer;

int a = 1;
float bill, payment;
char buffer[50], s_name[50];

int menu()
{
    int option;
    printf("\n\n====================================================================================\n\n");
    printf("Select an Option:\n");
    printf("1. Add a New Customer\n");
    printf("2. Fetch Customer Details\n");
    printf("3. Create a New Bill\n");
    printf("4. Add Money to Customer's Wallet\n");
    printf("5. Exit Program\n");
    printf(">> ");
    scanf("%d", &option);
    printf("\n");
    return option;
}

void writefile()
{
    FILE *fp;
    sprintf(buffer, "%s.dat", customer.name);
    fp = fopen(buffer, "wb");
    fwrite(&customer, sizeof(customer), 1, fp);
    fclose(fp);
    printf("\nDetails of %s Saved Successfully", customer.name);
}

void search(char name[50])
{
    FILE *fp;
    sprintf(buffer, "%s.dat", name);
    fp = fopen(buffer, "rb");
    fread(&customer, sizeof(customer), 1, fp);
    printf("\nCustomer Details:");
    printf("\nName: %s\n", customer.name);
    printf("Mobile Number: %llu\n", customer.mobile);
    printf("Age: %d\n", customer.age);
    printf("Balance: Rs. %.2f", customer.balance);
    fclose(fp);
}

void readfile(char name[50])
{
    FILE *fp;
    sprintf(buffer, "%s.dat", name);
    fp = fopen(buffer, "rb");
    fread(&customer, sizeof(customer), 1, fp);
    fclose(fp);
}

void main()
{
    while (a > 0)
    {
        int option = menu();
        if (option == 1)
        {
            printf("Enter Customer's Name: ");
            scanf("%s", customer.name);
            printf("Enter Customer's Mobile Number: ");
            scanf("%llu", &customer.mobile);
            printf("Enter Customer's Age: ");
            scanf("%d", &customer.age);
            printf("Enter Customer's Opening Balance: Rs. ");
            scanf("%f", &customer.balance);
            writefile();
            continue;
        }

        else if (option == 2)
        {
            printf("Enter Customer's Name: ");
            scanf("%s", s_name);
            search(s_name);
            continue;
        }

        else if (option == 3)
        {
            printf("Enter Customer's Name: ");
            scanf("%s", s_name);
            readfile(s_name);
            printf("Enter Billing Amount: Rs. ");
            scanf("%f", &bill);
            printf("Enter Amount Payed by the Customer: Rs. ");
            scanf("%f", &payment);
            customer.balance = customer.balance - bill + payment;
            printf("\nUpdated Customer Balance: Rs. %.2f", customer.balance);
            writefile();
            continue;
        }

        else if (option == 4)
        {
            printf("Enter Customer's Name: ");
            scanf("%s", s_name);
            readfile(s_name);
            printf("Enter Amount to be added: Rs. ");
            scanf("%f", &payment);
            customer.balance += payment;
            printf("\nRs. %.2f Added Successfully", payment);
            printf("\nUpdated Customer Balance: Rs. %.2f", customer.balance);
            writefile();
            continue;
        }

        else if (option == 5)
        {
            printf("Program Terminated\n\n");
            printf("====================================================================================");
            break;
        }

        else
        {
            printf("Wrong Input\n\n");
            printf("====================================================================================");
            continue;
        }
    }
}