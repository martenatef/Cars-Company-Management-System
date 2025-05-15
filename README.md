# Cars-Company-Management-System
A console-based C++ Car Management System using OOP. Users can view, add, search, rent, sell, and update cars. All actions are logged to output.txt. Designed with a simple menu and input validation for easy use and extension.
# Car Management System (C++ OOP Project)

## Description

This is a console-based **Car Management System** written in C++ using Object-Oriented Programming (OOP) principles.  
The program simulates a basic car company that allows users to:

- View available cars
- Add new cars
- Search cars by brand
- Rent a car
- Sell a car
- Update car information

All actions and results are saved to a file named `output.txt`.

---

## Features

- Object-Oriented Design using classes  
- Data persistence through `output.txt`  
- Input validation for year and price  
- Simple menu-driven interface  
- Easily extendable code structure  

---

## Classes Overview

- `Vehicle`: Base class with brand, model, and year  
- `Car`: Derived class with price and availability  
- `ViewCars`: Displays all cars  
- `AddCar`: Adds new cars  
- `SearchCar`: Searches cars by brand  
- `RentCar`: Marks a car as rented  
- `SaleCar`: Removes a car from inventory  
- `UpdateCarInfo`: Updates car details  
- `CarCompany`: Manages the system and user interaction  

---

## How to Compile and Run

1. Ensure you have a C++ compiler (like g++ or clang).  
2. Compile the program using:

```bash
g++ -o car_system OOP.cpp
