# Airline Management System 

Welcome to the NUCES Airline Flight System (NAFS), a comprehensive airline management system implemented using C++ and Object-Oriented Programming (OOP) concepts designed for handling passenger bookings, flight schedules, and administrative tasks efficiently.

## Introduction

NUCES Airline Flight System is an OOP project developed for managing various aspects of an airline's operations. It allows passengers to register, login, book flights, and manage their bookings. Admins can manage flight schedules, view bookings, and perform administrative tasks.

This project was developed using C++ and includes concepts such as classes, inheritance, dynamic memory allocation, file handling, and basic console-based user interfaces.

## Features

### For Passengers

- **Registration and Login**: Passengers can register with the system using their CNIC, age, username, and password. Existing users can log in securely to manage their bookings.
  
- **Flight Booking**: Passengers can view available flights, select seats, and book flights. Booking details include flight information, seat numbers, and payment details.

- **Financial Details**: Passengers can securely store and manage their financial information for payments.

- **Passport Details**: Passengers can store and manage passport information, including passport number, expiry date, and issue date.

### For Admins

- **Login**: Admins can securely log in to the system to manage flights and passenger bookings.

- **Flight Management**: Admins can add, edit, and delete flight schedules. Each flight includes details such as flight number, departure/arrival times, seat availability, and pricing.

- **Booking Management**: Admins can view all bookings, including passenger details, flight details, and payment information.

### General

- **Security**: Passwords and sensitive information are securely managed using C++ features (like masking passwords during input) to ensure data privacy.

- **File Handling**: The system uses file handling to store and retrieve user data, flight schedules, and booking information. 

- **User Interface**: Console-based interface for ease of use and practical demonstration of OOP principles in a real-world scenario.

## Usage

1. **Main Menu**: Upon running the program, you'll be presented with a main menu where you can choose to log in/register as a passenger, log in/register as an admin, view flight schedules without logging in, or exit the program.

2. **Passenger Features**: After logging in as a passenger, you can view flight schedules, book flights by entering flight numbers and seat preferences, add financial details securely, add passport details, and log out.

3. **Admin Features**: Logging in as an admin allows you to manage flight schedules (add, edit, delete), view all bookings with detailed information, and log out.

## Dependencies

### Libraries

- `<iostream>`: For input and output operations.
- `<string>`: For handling strings.
- `<windows.h>`: For using Windows-specific functions like `Sleep()`.
- `<conio.h>`: For console input functions like `_getch()`.
- `<stdlib.h>`: For using system functions like `system("cls")`.
- `<ctime>`: For using time functions.
- `<cmath>`: For using mathematical functions like `pow()`.
- `<cstdlib>`: For using functions like `rand()`.

## Installation

To run this project locally, ensure you have a C++ compiler installed on your system.

1. Clone the repository: `git clone https://github.com/NoorUlBaseer/airline-management-system.git`

2. Compile the `Q1.cpp` file using your preferred C++ compiler.

3. Run the executable file generated after compilation.

