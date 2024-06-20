#include <fstream>
#include <iostream>
#include "Header.h"
#include <vector>
#include <string>

using namespace std; // Use the standard namespace for convenience

std::vector<string> password; // Declare a global vectors of strings
std::vector<string> names;



int main() {
    setlocale(LC_CTYPE, "ukr"); // Set the locale to Ukrainian (this is for character encoding)

    int choice;
    string filename;

    while (true) {
        display_menu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Please enter the filename (including .txt extension) to load passwords from: ";
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
            cout << "Displaying password:" << endl;
            display_password(password, names);
            break;

        case 8:
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
