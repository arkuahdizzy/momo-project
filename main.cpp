#include <iostream>
#include <string>

using namespace std;

const int MAX_PIN_TRIES = 3;
const int DEFAULT_PIN = 0000;
const float DEFAULT_BALANCE = 1000.0;

// User account data
struct Account {
    string name;
    int pin;
    float balance;
};

// Function to initialize a new account
void initAccount(Account& account, string name) {
    account.name = name;
    account.pin = DEFAULT_PIN;
    account.balance = DEFAULT_BALANCE;
}

// Function to authenticate the user with a PIN
bool authenticate(Account& account) {
    int tries = 0;
    int pin;

    do {
        cout << "Enter your PIN: ";
        cin >> pin;
        tries++;
    } while (tries < MAX_PIN_TRIES && pin != account.pin);

    if (pin == account.pin) {
        cout << "Authentication successful!" << endl;
        return true;
    } else {
        cout << "Too many failed attempts. Program will now exit." << endl;
        exit(0);
    }
}

// Function to reset the account PIN
void resetPin(Account& account) {
    int newPin;

    cout << "Enter your new PIN: ";
    cin >> newPin;
    account.pin = newPin;

    cout << "PIN reset successful!" << endl;
}

// Function to display the account balance
void checkBalance(Account& account) {
    cout << "Your current balance is $" << account.balance << endl;
}

// Function to send money to another account
void sendMoney(Account& sender, Account& receiver) {
    float amount;

    cout << "Enter the amount to send: $";
    cin >> amount;

    if (amount > sender.balance) {
        cout << "Insufficient funds." << endl;
    } else {
        sender.balance -= amount;
        receiver.balance += amount;
        cout << "Money sent successfully!" << endl;
    }
}

int main() {
    Account account;
    initAccount(account, "John Doe");

    int option;

    cout << "Welcome to Mobile Money Service!" << endl;

    do {
        cout << "\nPlease select an option:" << endl;
        cout << "1. Authenticate" << endl;
        cout << "2. Reset PIN" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Send Money" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                if (authenticate(account)) {
                    // Authentication successful, do something else
                    cout << "Authentication successful!" << endl;
                }
                break;
            case 2:
                resetPin(account);
                break;
            case 3:
                checkBalance(account);
                break;
            case 4:
                // Authenticate the sender account
                if (authenticate(account)) {
                    // Find the receiver account and authenticate it
                    Account receiver;
                    initAccount(receiver, "Jane Doe");

                    if (authenticate(receiver)) {
                        sendMoney(account, receiver);
                    }
                }
                break;
            case 5:
                cout << "Thank you for using Mobile Money Service!" << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    } while (option != 5);

    return 0;
}