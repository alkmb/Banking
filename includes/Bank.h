#ifndef BANK_H
#define BANK_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct
{
    int id;
    double balance;
} Account;

typedef struct
{
    int   id;
    char name[100];
    char address[100];
    char phone[15];
    Account account;
} Customer;

typedef struct
{
    Customer customers[100];
    int customer_count;
} Bank;



//------------------COSTUMER------------------
void display_customer(Bank *bank);
void display_customers(Bank *bank);
void set_customer(Bank *bank);
void create_customer(Bank *bank);
void update_customer(Bank *bank);
void delete_customer(Bank *bank);

//------------------ACCOUNT------------------
void deposit(Account* account, double amount);
void withdraw(Account* account, double amount);

//------------------BANK------------------
void print_title();
void clear_terminal();
void manager_menu(Bank *bank);
void save_customers_to_file(Bank *bank);
void chose_option(Bank *bank, char option[2]);


#endif