#include <cmath>
#include <fstream>
#include <iostream>
#include "Header.h"
#include <vector>
#include <string>

using namespace std;      // Use the standard namespace for convenience

std::vector<string> password;   // Declare a global vector of strings named 'password'

int main() {
    setlocale(LC_CTYPE, "ukr");  // Set the locale to Ukrainian (this is for character encoding)

    password = password_input("passwords_default.txt");  // Call a function 'password_input' to read passwords from "passwords_default.txt". !!!!IMPORTANT FILE MUST BE WITH ANSI ENCODING FOR CYRILLIC LETTERS!!!!

    // Uncommenting the lines below would likely show the original passwords and their encoded versions
    //for (int i = 0; i < password.size(); i++)
    //    cout << password[i] << endl;
    cout << "Encoding data" << endl;
    Encoder(password);  
    // Uncommenting the line below might print the encoded passwords
    //for (int i = 0; i < password.size(); i++)
    //    cout << password[i] << endl;

    cout << "Data Encoded" << endl << endl;


    save_encoded(password);
    password.clear();
    read_encoded(password);  
    for (int i = 0; i < password.size(); i++)
        cout << password[i] << endl;  // Print the decoded passwords
    //for (int i = 0; i < password.size(); i++)
    //    cout << password[i] << endl;
    cout << endl << endl;
    Decoder(password);  

    for (int i = 0; i < password.size(); i++)
        cout << password[i] << endl;  // Print the decoded passwords

    return 0;  // Return 0 to indicate successful completion of the program
}
