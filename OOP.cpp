#include <iostream>
#include <vector>
#include <string>
#include <fstream> 
using namespace std;

class Vehicle {
public:
    string brand;
    string model;
    int year;

    Vehicle(string b, string m, int y) : brand(b), model(m), year(y) {}
};

class Car : public Vehicle {
public:
    double price;
    bool available;

    Car(string b, string m, int y, double p, bool a = true)
        : Vehicle(b, m, y), price(p), available(a) {
    }
};

class ViewCars {
public:
    void displayCars(const vector<Car>& cars) {
        ofstream outFile("output.txt", ios::app); 
        if (cars.empty()) {
            outFile << "\nNo cars available.\n";
            outFile.close();
            return;
        }
        outFile << "\nAvailable Cars:\n";
        outFile << "------------------------------------------------------------\n";
        outFile << "| Brand     | Model      | Year | Price    | Available |\n";
        outFile << "------------------------------------------------------------\n";
        for (const auto& car : cars) {
            outFile << "| " << car.brand << string(10 - car.brand.length(), ' ')
                << "| " << car.model << string(10 - car.model.length(), ' ')
                << "| " << car.year << " | $" << car.price << string(7 - to_string((int)car.price).length(), ' ')
                << "| " << (car.available ? "Yes" : "No ") << string(9 - (car.available ? 3 : 2), ' ') << "|\n";
        }
        outFile << "------------------------------------------------------------\n";
        outFile.close();
    }
};

class AddCar {
public:
    void addCar(vector<Car>& cars) {
        string brand, model;
        int year;
        double price;

        ofstream outFile("output.txt", ios::app);
        outFile << "\n--- Add New Car ---\n";
        outFile.close();

        cout << "\n--- Add New Car ---\n";
        cout << "Enter car brand: ";
        getline(cin >> ws, brand);
        cout << "Enter car model: ";
        getline(cin >> ws, model);

        while (true) {
            cout << "Enter car year (1900-2023): ";
            if (cin >> year) {
                if (year >= 1900 && year <= 2023) break;
            }
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid year. Please try again.\n";
        }

        while (true) {
            cout << "Enter car price: ";
            if (cin >> price) break;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid price. Please enter a number.\n";
        }

        cars.emplace_back(brand, model, year, price);

        outFile.open("output.txt", ios::app);
        outFile << "\nCar added successfully!\n";
        outFile.close();
        cout << "\nCar added successfully!\n";
    }
};

class SearchCar {
public:
    void searchCar(const vector<Car>& cars) {
        string brand;
        ofstream outFile("output.txt", ios::app);
        outFile << "\n--- Search Cars ---\n";
        outFile << "Enter brand to search: ";
        outFile.close();

        cout << "\n--- Search Cars ---\n";
        cout << "Enter brand to search: ";
        getline(cin >> ws, brand);

        bool found = false;
        outFile.open("output.txt", ios::app);
        outFile << "\nSearch Results:\n";
        outFile << "------------------------------------------------------------\n";
        for (const auto& car : cars) {
            if (car.brand == brand) {
                outFile << "| " << car.brand << string(10 - car.brand.length(), ' ')
                    << "| " << car.model << string(10 - car.model.length(), ' ')
                    << "| " << car.year << " | $" << car.price << string(7 - to_string((int)car.price).length(), ' ')
                    << "| " << (car.available ? "Yes" : "No ") << "|\n";
                found = true;
            }
        }
        outFile << "------------------------------------------------------------\n";

        if (!found) {
            outFile << "No cars found for brand '" << brand << "'\n";
        }
        outFile.close();
    }
};

class RentCar {
public:
    void rentCar(vector<Car>& cars) {
        ofstream outFile("output.txt", ios::app);
        if (cars.empty()) {
            outFile << "\nNo cars available for rent.\n";
            outFile.close();
            return;
        }

        string model;
        outFile << "\n--- Rent a Car ---\n";
        outFile << "Enter car model to rent: ";
        outFile.close();

        cout << "\n--- Rent a Car ---\n";
        cout << "Enter car model to rent: ";
        getline(cin >> ws, model);

        for (auto& car : cars) {
            if (car.model == model) {
                if (car.available) {
                    car.available = false;
                    outFile.open("output.txt", ios::app);
                    outFile << "\nYou have successfully rented:\n";
                    outFile << car.brand << " " << car.model << " (" << car.year << ")\n";
                    outFile << "Price: $" << car.price << " per day\n";
                    outFile.close();
                    return;
                }
                else {
                    outFile.open("output.txt", ios::app);
                    outFile << "\nThis car is already rented.\n";
                    outFile.close();
                    return;
                }
            }
        }
        outFile.open("output.txt", ios::app);
        outFile << "\nCar model '" << model << "' not found.\n";
        outFile.close();
    }
};

class SaleCar {
public:
    void sellCar(vector<Car>& cars) {
        ofstream outFile("output.txt", ios::app);
        if (cars.empty()) {
            outFile << "\nNo cars available for sale.\n";
            outFile.close();
            return;
        }

        string model;
        outFile << "\n--- Sell a Car ---\n";
        outFile << "Enter car model to sell: ";
        outFile.close();

        cout << "\n--- Sell a Car ---\n";
        cout << "Enter car model to sell: ";
        getline(cin >> ws, model);

        for (auto it = cars.begin(); it != cars.end(); ++it) {
            if (it->model == model) {
                outFile.open("output.txt", ios::app);
                outFile << "\nYou have sold:\n";
                outFile << it->brand << " " << it->model << " (" << it->year << ")\n";
                outFile << "Final price: $" << it->price << "\n";
                outFile.close();
                cars.erase(it);
                return;
            }
        }
        outFile.open("output.txt", ios::app);
        outFile << "\nCar model '" << model << "' not found.\n";
        outFile.close();
    }
};

class UpdateCarInfo {
public:
    void updateCar(vector<Car>& cars) {
        ofstream outFile("output.txt", ios::app);
        if (cars.empty()) {
            outFile << "\nNo cars available to update.\n";
            outFile.close();
            return;
        }

        string model;
        outFile << "\n--- Update Car Information ---\n";
        outFile << "Enter car model to update: ";
        outFile.close();

        cout << "\n--- Update Car Information ---\n";
        cout << "Enter car model to update: ";
        getline(cin >> ws, model);

        for (auto& car : cars) {
            if (car.model == model) {
                outFile.open("output.txt", ios::app);
                outFile << "\nCurrent information:\n";
                outFile << car.brand << " " << car.model << " (" << car.year << ")\n";
                outFile << "Price: $" << car.price << "\n";
                outFile << "Available: " << (car.available ? "Yes" : "No") << "\n\n";
                outFile.close();

                double newPrice;
                while (true) {
                    cout << "Enter new price (current: $" << car.price << "): ";
                    if (cin >> newPrice) break;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid price. Please enter a number.\n";
                }

                char availability;
                while (true) {
                    cout << "Update availability? (y/n): ";
                    cin >> availability;
                    if (availability == 'y' || availability == 'Y' ||
                        availability == 'n' || availability == 'N') break;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Please enter 'y' or 'n'.\n";
                }

                car.price = newPrice;
                if (availability == 'y' || availability == 'Y') {
                    car.available = !car.available;
                }

                outFile.open("output.txt", ios::app);
                outFile << "\nCar information updated successfully!\n";
                outFile.close();
                return;
            }
        }
        outFile.open("output.txt", ios::app);
        outFile << "\nCar model '" << model << "' not found.\n";
        outFile.close();
    }
};

class CarCompany {
private:
    vector<Car> cars;
    ViewCars viewer;
    AddCar adder;
    SearchCar searcher;
    RentCar renter;
    SaleCar seller;
    UpdateCarInfo updater;

    void displayMenu() {
        cout << "\n===== Car Management System =====\n";
        cout << "1. View All Cars\n";
        cout << "2. Add New Car\n";
        cout << "3. Search Cars\n";
        cout << "4. Rent a Car\n";
        cout << "5. Sell a Car\n";
        cout << "6. Update Car Information\n";
        cout << "7. Exit\n";
        cout << "=================================\n";
        cout << "Enter your choice (1-7): ";
    }

public:
    CarCompany() {
        cars.push_back(Car("Toyota", "Camry", 2020, 25000));
        cars.push_back(Car("Honda", "Civic", 2021, 23000));
        cars.push_back(Car("Ford", "F-150", 2019, 35000));
        cars.push_back(Car("Chevrolet", "Malibu", 2022, 27000));
        cars.push_back(Car("Nissan", "Altima", 2021, 24000));
    }

    void run() {
        int choice;
        do {
            displayMenu();
            while (!(cin >> choice) || choice < 1 || choice > 7) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid choice. Please enter a number between 1 and 7: ";
            }
            cin.ignore();

            switch (choice) {
            case 1: viewer.displayCars(cars); break;
            case 2: adder.addCar(cars); break;
            case 3: searcher.searchCar(cars); break;
            case 4: renter.rentCar(cars); break;
            case 5: seller.sellCar(cars); break;
            case 6: updater.updateCar(cars); break;
            case 7:
                ofstream outFile("output.txt", ios::app);
                outFile << "\nThank you for using the system. Goodbye!\n";
                outFile.close();
                cout << "\nThank you for using the system. Goodbye!\n";
                break;
            }
        } while (choice != 7);
    }
};

int main() {
 
    ofstream outFile("output.txt", ios::trunc);
    outFile.close();

    CarCompany company;
    company.run();
    return 0;
}