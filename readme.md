# User Registration and Authentication System in C

This project implements a simple user registration and login system in C. The program allows users to sign up with a unique username and password, which is then stored securely by hashing the password and saving it in a `pass.csv` file. The login functionality validates the user's credentials by checking against the hashed password stored in `pass.csv`.

## Features

- **User Registration**: Users can register with a unique username and password.
- **Password Hashing**: Passwords are hashed before storing them in `pass.csv` to enhance security.
- **User Login**: Users can log in by entering a valid username and password, which are then verified.
- **Error Handling**: Checks for file access errors and duplicate usernames to prevent issues during registration.

## Code Structure

The main functionality is implemented in functions that handle password hashing, registration, login, and user credential verification.

### Key Functions

- **`hashPass`**: Takes a password as input and returns a hashed version of it for secure storage.
- **`signup`**: Allows a new user to register. It checks for duplicate usernames, hashes the password, and writes the username and hashed password to `pass.csv`.
- **`checkUsername`**: Checks if a username already exists in the `pass.csv` file.
- **`checkPassword`**: Compares the hashed input password with the stored hashed password for a given username.
- **`login`**: Allows a user to log in by verifying the entered username and password.



## Set Up

### Prerequisites

- Ensure you have a C compiler installed (e.g., GCC).
- If you are using Windows, you may want to install an IDE like Code::Blocks or MinGW for easier compilation.

### Installation Steps

1. **Clone the Repository** (if applicable):
   ```bash
   git clone https://github.com/yourusername/user-authentication-system.git
   cd user-authentication-system

