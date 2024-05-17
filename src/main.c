#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../includes/Bank.h"

void clear_terminal() {
    printf("\033[H\033[J");
}

void print_title() {
    printf("\033[0;34m"); // Set the text color to blue
    printf("░░░█░█░█▀▀░█░░░█▀▀░█▀█░█▄█░█▀▀░░░░\n");
    printf("░░░█▄█░█▀▀░█░░░█░░░█░█░█░█░█▀▀░░░░\n");
    printf("░░░▀░▀░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀░▀░▀▀▀░░░░\n");
    printf("░░░░░░░░░░░░▀█▀░█▀█░░░░░░░░░░░░░░░\n");
    printf("░░░░░░░░░░░░░█░░█░█░░░░░░░░░░░░░░░\n");
    printf("░░░░░░░░░░░░░▀░░▀▀▀░░░░░░░░░░░░░░░\n");
    printf("░█░█░█▀█░█░█░█▀█░░░█▀▄░█▀█░█▀█░█░█\n");
    printf("░░█░░█░█░█░█░█▀▄░░░█▀▄░█▀█░█░█░█▀▄\n");
    printf("░░▀░░▀▀▀░▀▀▀░▀░▀░░░▀▀░░▀░▀░▀░▀░▀░▀\n");
    printf("\033[0m");
    printf("\n\n");
}

void chose_option(Bank *bank, char option[2])
{
    if (strncmp(option, "1", 1) == 0)
        create_customer(bank);
    else if (strncmp(option, "2", 1) == 0)
        display_customer(bank);
    else if (strncmp(option, "3", 1) == 0)
        display_customers(bank);
    else if (strncmp(option, "4", 1) == 0)
        update_customer(bank);
    else if (strncmp(option, "5", 1) == 0)
        delete_customer(bank);
    else if (strncmp(option, "6", 1) == 0)
        exit(0);
    else
        printf("Invalid option\n");
}

void manager_menu(Bank *bank)
{
    clear_terminal();
    print_title();
    char option[2];
    printf("Welcome to the Manager Menu\n");
    printf("\n");
    printf("1. Create a new customer\n");
    printf("2. Display customer information\n");
    printf("3. List all costumers\n");
    printf("4. Update customer information\n");
    printf("5. Delete customer\n");
    printf("6. Exit\n");
    printf("\n\n");
    printf("Please select an option: ");
    scanf("%s", option);
    chose_option(bank, option);
}

void save_customers_to_file(Bank *bank)
{
    FILE *file = fopen("customers.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < bank->customer_count; i++)
    {
        Customer customer = bank->customers[i];
        fprintf(file, "%d %s %s %s %d %.2f\n", customer.id, customer.name, customer.address, customer.phone, customer.account.id, customer.account.balance);
    }

    fclose(file);
}

void load_customers_from_file(Bank *bank)
{
    FILE *file = fopen("customers.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    while (fscanf(file, "%d %s %s %s %d %lf\n", &bank->customers[bank->customer_count].id, bank->customers[bank->customer_count].name, bank->customers[bank->customer_count].address, bank->customers[bank->customer_count].phone, &bank->customers[bank->customer_count].account.id, &bank->customers[bank->customer_count].account.balance) != EOF)
    {
        bank->customer_count++;
    }

    fclose(file);
}

int main()
{
    Bank bank;
    load_customers_from_file(&bank);
    while (1)
    {
        clear_terminal();
        print_title();
        bank.customer_count = 0;
        manager_menu(&bank);
    }
    return 0;
}