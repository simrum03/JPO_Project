# Data Encryption and Decryption Library

## Table of Contents
1. [Introduction](#introduction)
2. [How to Run](#how-to-run)
3. [Example Usage](#example-usage)

---

## Introduction

This project is a simple, interactive console-based menu application that allows users to encrypt and decrypt data using two algorithms:
- Caesar Cipher
- Rail Fence Cipher

The program provides an intuitive interface for managing encryption and decryption operations, including saving the results to a file.

---

## How to Run

### Prerequisites
Make sure you have the following tools installed:
- [CMake](https://cmake.org/)
- [MinGW](https://www.mingw-w64.org/)

### Steps
1. Clone the repository:
   ```
   git clone https://github.com/simrum03/JPO_Project.git
   ```
2. Navigate to the project directory:
   ```
   cd JPO_Project
   ```
3. Create a build directory:
   ```
   mkdir build
   cd build
   ```
4. Configure the project using CMake:
   ```
   cmake -G "MinGW Makefiles" ..
   ```
5. Build the project:
   ```
   mingw32-make
   ```
6. Run the application:
   ```
   ./main
   ```

---

## Example Usage

```
---------------------
Menu:
1 - Encrypting       
2 - Decrypting       
3 - Delete a file    
4 - Quit program
---------------------
Enter your choice: 1
Encrypting selected. Choose an algorithm:
c - Caesar cipher
r - Rail fence cipher
b - Back to main menu
Enter your algorithm choice: c
Enter shift: 4
Enter data you would like to encrypt (type 'stop' to finish):
hello world
stop
Encrypted data: lipps asvph
What do you want to do with your encrypted data?
1 - Save data to a new file
2 - Append data to an existing file
3 - Do nothing
Enter your choice: 1
Enter filename: test.txt
Data has been saved to test.txt
Do you want to continue encrypting? (y/n): n

---------------------
Menu:
1 - Encrypting
2 - Decrypting
3 - Delete a file
4 - Quit program
---------------------
Enter your choice: 4
Quitting...
```
