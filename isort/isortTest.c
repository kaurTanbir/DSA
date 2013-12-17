#include "testUtils.h"
#include "isort.h"
#include <stdio.h>
#include <memory.h>

typedef struct {
	int accountNumber;
	int balance;
} Account;
int areAccountsEqual(Account* expected,Account* actual){
	int result = expected->accountNumber == actual->accountNumber && 
					expected->balance == actual->balance  ;
    return result;
}

int compareAccountsByAccountNumber(void* first, void* second) {
	Account* firstAccount = (Account*)first;
	Account* secondAccount = (Account*)second;
	return firstAccount->accountNumber - secondAccount->accountNumber;
}

int compareAccountsByBalance(void* first, void* second) {
	Account* firstAccount = (Account*)first;
	Account* secondAccount = (Account*)second;
	return firstAccount->balance - secondAccount->balance;
}
int compareInt ( void* a,  void* b){
    return (*(int*)a - *(int*)b);
}

int compareDouble( void* a,  void* b){
    return (*(double*)a - *(double*)b);
}


void test_sorting_accounts_by_account_number(){
	Account expected[] = {{12, 10},{33, 10000}, {40, 3},{100, 100}};
	Account accounts[] = {{100, 100}, {12, 10}, {33, 10000}, {40, 3}};
	isort(accounts, 4, sizeof(Account), compareAccountsByAccountNumber);
	ASSERT(1 == areAccountsEqual(expected, accounts));

}
void test_sorting_accounts_by_balance(){
	Account expected[] = {{40, 3},{12, 10},{100, 100},{33, 10000} };
	Account accounts[] = {{100, 100}, {12, 10}, {33, 10000}, {40, 3}};
	isort(accounts, 4, sizeof(Account), compareAccountsByBalance);
	ASSERT(1 == areAccountsEqual(expected, accounts));

}

void test_sorting_an_array_of_integers(){
	int expected[] = {1,2,3,4};
	int actual[] = {4,3,1,2};
	isort(actual, 4, sizeof(int), compareInt);
	ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}
void test_sorting_an_array_of_double(){
	int expected[] = {1.0,2.0,3.0,4.0};
	int actual[] = {4.0,3.0,1.0,2.0};
	isort(actual, 4, sizeof(int), compareInt);
	ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}