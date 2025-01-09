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

After running the program, you'll see a menu with the following options:

1. Encrypting: Choose an encryption algorithm (Caesar Cipher or Rail Fence Cipher), provide the required inputs, and view the encrypted data. You can save or append the result to a file.
2. Decrypting: Similar to encryption, but reverses the operation to retrieve the original data.
3. Delete a file: Allows you to remove an existing file.
4. Quit program: Exits the application.

---
