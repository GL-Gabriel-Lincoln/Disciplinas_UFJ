typedef struct {
    int accountNumber;
    char nameHolder[50];
    float balance;
} BankAccount;

void startAccount(BankAccount *account, int num, char *name, float openingBalance);
void depositValue(BankAccount *account, float value);
void withdrawValue(BankAccount *account, float value);
void printBalance(BankAccount *account);
