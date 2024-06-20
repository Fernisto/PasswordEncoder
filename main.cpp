#include <cmath>
#include <fstream>
#include <iostream>
#include "Header.h"
#include <vector>
#include <string>

using namespace std; // Use the standard namespace for convenience

std::vector<string> password; // Declare a global vector of strings named 'password'
std::vector<string> names;

void display_menu() {
    cout << "Password Manager Menu:" << endl;
    cout << "1. Input passwords from file" << endl;
    cout << "2. Encode passwords" << endl;
    cout << "3. Decode passwords" << endl;
    cout << "4. Save encoded passwords to file" << endl;
    cout << "5. Read encoded passwords from file" << endl;
    cout << "6. Display passwords" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}

void display_passwords(const std::vector<std::string>& passwords) {
    for (size_t i = 0; i < passwords.size(); ++i) {
        cout << passwords[i] << endl;
    }
}

int main() {
    setlocale(LC_CTYPE, "ukr"); // Set the locale to Ukrainian (this is for character encoding)

    int choice;
    string filename;

    while (true) {
        display_menu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter filename to input passwords from: ";
            cin >> filename;
            password = password_input(filename);
            cout << "Passwords loaded." << endl;
            break;

        case 2:
            cout << "Encoding passwords..." << endl;
            Encoder(password);
            cout << "Passwords encoded." << endl;
            break;

        case 3:
            cout << "Decoding passwords..." << endl;
            Decoder(password);
            cout << "Passwords decoded." << endl;
            break;

        case 4:
            cout << "Saving encoded passwords to file..." << endl;
            save_encoded(password);
            cout << "Passwords saved." << endl;
            break;

        case 5:
            cout << "Reading encoded passwords from file..." << endl;
            read_encoded(password, names);
            cout << "Encoded passwords read." << endl;
            break;

        case 6:
            cout << "Displaying passwords:" << endl;
            display_passwords(password);
            break;

        case 7:
            cout << "Exiting program." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

        cout << endl;
    }

    return 0;
}
