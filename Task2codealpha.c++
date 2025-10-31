#include <iostream>
#include <fstream>
#include <string>
#include <limits> // Required for input validation utilities
#include <cctype> // Required for character handling in password validation

using namespace std;

// Function to validate the strength of a password
bool isValidPassword(const string& password) {
    // Password must be at least 8 characters long
    if (password.length() < 8) {
        return false;
    }

    bool hasLower = false, hasUpper = false, hasDigit = false;
    for (char ch : password) {
        if (islower(ch)) hasLower = true;
        if (isupper(ch)) hasUpper = true;
        if (isdigit(ch)) hasDigit = true;
    }
 // Password must contain a mix of uppercase, lowercase, and a digit
    return hasLower && hasUpper && hasDigit;
}

// Function to check if a username already exists in the "users.txt" file
bool isUsernameTaken(const string& username) {
    ifstream file("users.txt");
    string line;
    while (getline(file, line)) {
        // The file stores data as "username password"
        size_t space_pos = line.find(' ');
        if (space_pos != string::npos) {
            string existing_username = line.substr(0, space_pos);
            if (existing_username == username) {
                file.close();
                return true; // Username found
            }
        }
    }
    file.close();
    return false; // Username not found
}

// Registration function that takes username and password as input
void registerUser() {
    string username, password;

    // Input validation loop for username
    do {
        cout << "Enter a username: ";
        cin >> username;

        if (isUsernameTaken(username)) {
            cout << "This username has already been taken. Please try another one." << endl;
        } else if (username.length() < 4) {
            cout << "Username must be at least 4 characters long. Please try again." << endl;
        } else {
            break; // Valid username
        }
    } while (true);
// Input validation loop for password
    do {
        cout << "Enter a password (min 8 chars, including uppercase, lowercase, and a digit): ";
        cin >> password;

        if (!isValidPassword(password)) {
            cout << "Invalid password format. Please meet the requirements." << endl;
        } else {
            break; // Valid password
        }
    } while (true);

    // Store the new user credentials in the "users.txt" file
    ofstream file("users.txt", ios::app); // Open in append mode
    if (file.is_open()) {
        file << username << " " << password << endl; // Store username and password separated by a space
        file.close();
        cout << "Registration successful for user: " << username << endl;
    } else {
        cout << "Error: Could not open the user database file." << endl;
    }
    int main() {
    cout << "Welcome to the Registration System" << endl;
    registerUser();
    return 0;
}