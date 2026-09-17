#include <iostream>
#include <vector>
using namespace std;

/*
    Circular Parking Queue System
    --------------------------------
    This program implements a parking system
    using a Circular Queue.

    Operations:
    1. Arrive      - Add a vehicle
    2. Leave       - Remove the first vehicle
    3. Next        - Show the next vehicle to leave
    4. Count       - Show number of vehicles
    5. Full        - Check whether parking is full
    6. Empty       - Check whether parking is empty
*/

class ParkingQueue
{
private:
    int capacity;
    vector<int> parking;

    int front;
    int rear;
    int currentSize;

public:

    // Constructor
    ParkingQueue(int n)
    {
        capacity = n;
        parking.resize(n);

        front = -1;
        rear = -1;
        currentSize = 0;
    }

   
    void arrive(int vehicleId)
    {
        if (currentSize == capacity)
        {
            cout << "Parking is Full!\n";
            return;
        }

        if (currentSize == 0)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % capacity;
        }

        parking[rear] = vehicleId;
        currentSize++;

        cout << "Vehicle " << vehicleId << " entered successfully.\n";
    }

    void leave()
    {
        if (currentSize == 0)
        {
            cout << "Parking is Empty!\n";
            return;
        }

        int vehicleId = parking[front];

        if (currentSize == 1)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }

        currentSize--;

        cout << "Vehicle " << vehicleId << " left the parking.\n";
    }

    void nextVehicle()
    {
        if (currentSize == 0)
        {
            cout << "Parking is Empty!\n";
            return;
        }

        cout << "Next vehicle to leave: "
             << parking[front] << "\n";
    }

    void countVehicles()
    {
        cout << "Vehicles currently parked: "
             << currentSize << "\n";
    }

    void checkFull()
    {
        if (currentSize == capacity)
            cout << "Parking is Full.\n";
        else
            cout << "Parking is not Full.\n";
    }

    void checkEmpty()
    {
        if (currentSize == 0)
            cout << "Parking is Empty.\n";
        else
            cout << "Parking is not Empty.\n";
    }
};

int main()
{
    int capacity;

    cout << "Enter parking capacity: ";
    cin >> capacity;

    ParkingQueue parking(capacity);

    int choice;

    while (true)
    {
        cout << "\n========== PARKING SYSTEM ==========\n";
        cout << "1. Vehicle Arrival\n";
        cout << "2. Vehicle Leave\n";
        cout << "3. Next Vehicle\n";
        cout << "4. Count Vehicles\n";
        cout << "5. Check Full\n";
        cout << "6. Check Empty\n";
        cout << "7. Exit\n";
        cout << "====================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int vehicleId;

                cout << "Enter Vehicle ID: ";
                cin >> vehicleId;

                parking.arrive(vehicleId);
                break;
            }

            case 2:
                parking.leave();
                break;

            case 3:
                parking.nextVehicle();
                break;

            case 4:
                parking.countVehicles();
                break;

            case 5:
                parking.checkFull();
                break;

            case 6:
                parking.checkEmpty();
                break;

            case 7:
                cout << "Exiting Parking System...\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}