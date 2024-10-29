# Voting System in C

This project implements a basic voting system in C, where candidates can be added dynamically, and votes are recorded for each candidate. A registration process also creates a `pass.csv` file to store hashed passwords securely.

## Features

- **Dynamic candidate addition**: Use linked lists to manage candidates, allowing flexible additions.
- **Vote counter**: Each candidate has a vote counter that can be updated when a vote is cast.
- **Secure Registration**: A `pass.csv` file is generated during registration, storing hashed passwords.

## Code Structure

The main code uses a `Node` struct to represent each candidate in the voting system, with fields for the candidate's name, vote count, and a pointer to the next candidate.

### Functions

- **`insert`**: Adds a new candidate to the voting system with an initial vote count of 0. If this is the first candidate, it is set as the head of the linked list.

### Set Up

- Place both files in same folder
- Run follwing commands
- gcc file.c
- ./a.exe or ./aout (as per OS)
