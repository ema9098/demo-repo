#include <iostream>

class House {
public:
    // Method to get the number of rooms
    int numberOfRooms() const {
        return 4;  // Replace this with your actual logic to get the number of rooms
    }

    // Method to calculate the number of windows based on the number of rooms
    int numberOfWindows() const {
        return numberOfRooms() * 2;
    }
};

int main() {
    House myHouse;

    // Accessing the methods
    std::cout << "Number of rooms: " << myHouse.numberOfRooms() << std::endl;
    std::cout << "Number of windows: " << myHouse.numberOfWindows() << std::endl;

    return 0;
}