#include "../includes/Bank.h"

void set_customer(Bank *bank)
{
    printf("Enter ID: ");
    scanf("%d", &bank->customers[bank->customer_count].id);
    printf("Enter customer name: ");
    scanf("%s", bank->customers[bank->customer_count].name);
    printf("Enter customer address: ");
    scanf("%s", bank->customers[bank->customer_count].address);
    printf("Enter customer phone: ");
    scanf("%s", bank->customers[bank->customer_count].phone);
    printf("Enter account ID: ");
    scanf("%d", &bank->customers[bank->customer_count].account.id);
    printf("Enter account balance: ");
    scanf("%lf", &bank->customers[bank->customer_count].account.balance);
    
    printf("Customer created successfully\n");
    printf("Costumer data:\n");
    printf("ID: %d\n", bank->customers[bank->customer_count].id);
    printf("Name: %s\n", bank->customers[bank->customer_count].name);
    printf("Address: %s\n", bank->customers[bank->customer_count].address);
    printf("Phone: %s\n", bank->customers[bank->customer_count].phone);
    printf("Account ID: %d\n", bank->customers[bank->customer_count].account.id);
    printf("Balance: %.2f\n", bank->customers[bank->customer_count].account.balance);
    
    bank->customer_count++;
    printf ("Press any key to continue...\n");
    getchar();
    getchar();
    save_customers_to_file(bank);
}

void create_customer(Bank *bank)
{
    clear_terminal();
    printf("Enter customer ID: ");
    scanf("%d", &bank->customer_count);
    if (bank->customers[bank->customer_count].name[0] == '\0')
    {
        set_customer(bank);
    }
    else if (bank->customers[bank->customer_count].name[0] != '\0')
    {
        printf("Customer ID already exists\n");
        printf("Press any key to continue...\n");
        getchar();
        getchar();
    }
}

void update_customer(Bank *bank)
{
    clear_terminal();
    printf("Enter customer ID: ");
    scanf("%d", &bank->customer_count);
    if (bank->customers[bank->customer_count].name[0] != '\0')
    {
        set_customer(bank);
    }
    else if (bank->customers[bank->customer_count].name[0] == '\0')
    {
        printf("Customer ID doesn't exists\n");
        printf("Press any key to continue...\n");
        getchar();
        getchar();
    }
}

void delete_customer(Bank *bank)
{
    clear_terminal();
    printf("Enter customer ID: ");
    scanf("%d", &bank->customer_count);
    bank->customers[bank->customer_count].id = 0;
    bank->customers[bank->customer_count].name[0] = '\0';
    bank->customers[bank->customer_count].address[0] = '\0';
    bank->customers[bank->customer_count].phone[0] = '\0';
    bank->customers[bank->customer_count].account.id = 0;
    bank->customers[bank->customer_count].account.balance = 0;
    printf("Customer deleted successfully\n");
    printf("Press any key to continue...\n");
    getchar();
    getchar();
}

void display_customer(Bank *bank)
{
    clear_terminal();
    printf("Enter customer ID: ");
    scanf("%d", &bank->customer_count);
    printf ("Customer ID: %d\n", bank->customers[bank->customer_count].id);
    Customer* customer = &bank->customers[bank->customer_count];
    printf("Customer ID: %d\n", customer->id);
    printf("Name: %s\n", customer->name);
    printf("Address: %s\n", customer->address);
    printf("Phone: %s\n", customer->phone);
    printf("Account ID: %d\n", customer->account.id);
    printf("Balance: %.2f\n", customer->account.balance);
    save_customers_to_file(bank);
    printf("Press any key to continue...\n");
    getchar();
    getchar();
}

void display_customers(Bank *bank)
{
    clear_terminal();
    for (int i = 0; i <= bank->customer_count; i++)
    {
        Customer* customer = &bank->customers[i];
        printf("Customer ID: %d\n", customer->id);
        printf("Name: %s\n", customer->name);
        printf("Address: %s\n", customer->address);
        printf("Phone: %s\n", customer->phone);
        printf("Account ID: %d\n", customer->account.id);
        printf("Balance: %.2f\n", customer->account.balance);
        printf("\n");
    }
    printf("Press any key to continue...\n");
    getchar();
    getchar();
}