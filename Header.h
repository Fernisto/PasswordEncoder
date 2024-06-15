#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#pragma once  // Header guard to ensure this header is included only once

// Arrays for different character sets
char Upper_Letters[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
char Lower_Letters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
char KUpper_Letters[] = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�' };
char KLower_Letters[] = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�' };
char Numbers[] = { '0','1','2','3','4','5','6','7','8','9' };
char huj[] = {
    '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '-', '=', '\\',
    '{', '}', '[', ']', '\'', '"', ';', ':', '|', ',', '.', '/', '<', '>', '?', '`', '~'
};

// Function to encode passwords using rotation cipher
void Encoder(std::vector<std::string>& password) {
    for (size_t j = 0; j < password.size(); ++j) {
        size_t length = password[j].length();
        for (size_t i = 0; i < length; ++i) {
            char& ch = password[j][i];
            // Check and rotate characters within respective arrays
            char* ptr = strchr(Upper_Letters, ch);
            if (ptr) {
                ch = Upper_Letters[(ptr - Upper_Letters + 2) % 26];
                continue;
            }
            ptr = strchr(Lower_Letters, ch);
            if (ptr) {
                ch = Lower_Letters[(ptr - Lower_Letters + 2) % 26];
                continue;
            }
            ptr = strchr(Numbers, ch);
            if (ptr) {
                ch = Numbers[(ptr - Numbers + 2) % 10];
                continue;
            }
            ptr = strchr(huj, ch);
            if (ptr) {
                ch = huj[(ptr - huj + 2) % 32];
                continue;
            }
            ptr = strchr(KUpper_Letters, ch);
            if (ptr) {
                ch = KUpper_Letters[(ptr - KUpper_Letters + 2) % 33];
                continue;
            }
            ptr = strchr(KLower_Letters, ch);
            if (ptr) {
                ch = KLower_Letters[(ptr - KLower_Letters + 2) % 33];
                continue;
            }
        }
    }
}

// Function to decode passwords back from the encoded form
void Decoder(std::vector<std::string>& password) {
    for (size_t j = 0; j < password.size(); ++j) {
        size_t length = password[j].length();
        for (size_t i = 0; i < length; ++i) {
            char& ch = password[j][i];
            // Reverse the rotation for decoding
            char* ptr = strchr(Upper_Letters, ch);
            if (ptr) {
                ch = Upper_Letters[(ptr - Upper_Letters - 2 + 26) % 26];
                continue;
            }
            ptr = strchr(Lower_Letters, ch);
            if (ptr) {
                ch = Lower_Letters[(ptr - Lower_Letters - 2 + 26) % 26];
                continue;
            }
            ptr = strchr(Numbers, ch);
            if (ptr) {
                ch = Numbers[(ptr - Numbers - 2 + 10) % 10];
                continue;
            }
            ptr = strchr(huj, ch);
            if (ptr) {
                ch = huj[(ptr - huj - 2 + 32) % 32];
                continue;
            }
            ptr = strchr(KUpper_Letters, ch);
            if (ptr) {
                ch = KUpper_Letters[(ptr - KUpper_Letters - 2 + 33) % 33];
                continue;
            }
            ptr = strchr(KLower_Letters, ch);
            if (ptr) {
                ch = KLower_Letters[(ptr - KLower_Letters - 2 + 33) % 33];
                continue;
            }
        }
    }
}

// Function to save encoded passwords to a file
void save_encoded(std::vector<std::string>& password) {
    std::ofstream data;
    data.open("passwords_encoded.txt");
    if (data.is_open()) {
        std::cout << "Saving data" << std::endl;
        // Write each password string to the file
        for (size_t i = 0; i < password.size(); ++i) {
            data << password[i] << std::endl;
        }
        data.close();
        std::cout << "Data saved successfully" << std::endl << std::endl;
    }
    else {
        std::cout << "Error: Unable to open file for saving" << std::endl;
    }
}

// Function to read encoded passwords from a file
void read_encoded(std::vector<std::string>& password) {
    std::ifstream data;
    data.open("passwords_encoded.txt");
    if (data.is_open()) {
        std::cout << "Reading data" << std::endl;
        std::string str;
        // Read each line from the file into the password vector
        while (std::getline(data, str)) {
            password.push_back(str);
        }
        data.close();
        std::cout << "Data read successfully" << std::endl << std::endl;
    }
    else {
        std::cout << "Error: Unable to open file for reading" << std::endl;
    }
}

// Function to read passwords from a specified file into a vector
std::vector<std::string> password_input(const std::string& filename) {
    std::vector<std::string> text;
    std::ifstream data(filename);
    if (data.is_open()) {
        std::cout << "Reading raw data" << std::endl;
        std::string str;
        // Read each line from the file into the text vector
        while (std::getline(data, str)) {
            text.push_back(str);
        }
        data.close();
        std::cout << "Data read successfully" << std::endl << std::endl;
    }
    else {
        std::cerr << "Error opening file for reading" << std::endl;
    }
    return text;
}