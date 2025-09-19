#include <iostream>
#include <string>
#include <stdexcept>

void printUMLDiagram() {
    std::cout <<
        "+-------------------------------+\n"
        "|             Hotel             |\n"
        "+-------------------------------+\n"
        "| - name: std::string           |\n"
        "| - totalRooms: int             |\n"
        "| - occupiedRooms: int          |\n"
        "| - pricePerDay: double         |\n"
        "+-------------------------------+\n"
        "| + getName() : std::string     |\n"
        "| + getTotalRooms() : int       |\n"
        "| + getOccupiedRooms() : int    |\n"
        "| + setPricePerDay(double)      |\n"
        "| + getPricePerDay() : double   |\n"
        "| + totalRevenue() : double     |\n"
        "+-------------------------------+\n";
}

class Hotel {
private:
    std::string name;
    int totalRooms;
    int occupiedRooms;
    double pricePerDay;

public:
    Hotel(const std::string& name, int totalRooms, int occupiedRooms, double pricePerDay)
        : name(name), totalRooms(totalRooms), occupiedRooms(occupiedRooms), pricePerDay(pricePerDay)
    {
        if (totalRooms < 0 || occupiedRooms < 0 || pricePerDay < 0) {
            throw std::invalid_argument("Values cannot be negative");
        }
        if (occupiedRooms > totalRooms) {
            throw std::invalid_argument("Occupied rooms cannot exceed total rooms");
        }
    }

    std::string getName() const {
        return name;
    }

    int getTotalRooms() const {
        return totalRooms;
    }

    int getOccupiedRooms() const {
        return occupiedRooms;
    }

    void setPricePerDay(double price) {
        if (price < 0) {
            throw std::invalid_argument("Price per day cannot be negative");
        }
        pricePerDay = price;
    }

    double getPricePerDay() const {
        return pricePerDay;
    }

    double totalRevenue() const {
        return occupiedRooms * pricePerDay;
    }
};

int main() {
    try {
        printUMLDiagram();

        Hotel hotel("Sunrise", 100, 75, 1500.0);

        std::cout << "Hotel name: " << hotel.getName() << std::endl;
        std::cout << "Total rooms: " << hotel.getTotalRooms() << std::endl;
        std::cout << "Occupied rooms: " << hotel.getOccupiedRooms() << std::endl;
        std::cout << "Price per day: " << hotel.getPricePerDay() << std::endl;

        std::cout << "Total revenue: " << hotel.totalRevenue() << std::endl;

        hotel.setPricePerDay(1600.0);
        std::cout << "New price per day: " << hotel.getPricePerDay() << std::endl;
        std::cout << "Total revenue after price change: " << hotel.totalRevenue() << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
