// Multiple Inheritance
//  #include <iostream>
//  using namespace std;
//  class M
//  {
//  protected:
//      int m;

// public:
//     void get_M(int no);
// };
// void M::get_M(int no)
// {
//     m = no;
// }
// class N
// {
// protected:
//     int n;

// public:
//     void get_N(int no);
// };
// void N::get_N(int no)
// {
//     n = no;
// }
// class P : public M, public N
// {
// public:
//     void display();
// };
// void P::display()
// {
//     cout << "Value of m: " << m << endl;
//     cout << "Value of n: " << n << endl;
//     cout << "Product m*n: " << m * n << endl;
// }
// int main()
// {
//     P obj;
//     obj.get_M(10);
//     obj.get_N(20);
//     obj.display();
//     return 0;
// }

// 2. Multilevel Inheritance (Grandparent ➔ Parent ➔ Child)
#include <iostream>
#include <string>
using namespace std;
class Vehicle
{
protected:
    string registrationNumber;
    string ownerName;

public:
    void display();
    string getRegister()
    {
        return registrationNumber;
    }
};
void Vehicle::display()
{
    cout << "Reg# : " << registrationNumber << endl;
    cout << "Owner: " << ownerName << endl;
}
class Car : public Vehicle
{
protected:
    string fuelType;
    int seatingCapacity;

public:
    void display();
};
void Car::display()
{
    Vehicle::display();
    cout << "Fuel type: " << fuelType << endl;
    cout << "Seats: " << seatingCapacity << endl;
}
class ElectricCar : public Car
{
    double batteryCapacity;
    double chargingTime;

public:
    ElectricCar(string reg = "", string owner = "", string fuel = "", int seats = 0, double battery = 0.0, double time = 0)
    {
        registrationNumber = reg;
        ownerName = owner;
        fuelType = fuel;
        seatingCapacity = seats;
        batteryCapacity = battery;
        chargingTime = time;
    };
    void display();
    void setBattery(int b)
    {
        batteryCapacity = b;
    }
    double getChargeTime()
    {
        return chargingTime;
    }
};
void ElectricCar::display()
{
    Car::display();
    cout << "Battery Capacity: " << batteryCapacity << endl;
    cout << "Charging Time: " << chargingTime << endl;
}
int main()
{
    ElectricCar obj[10];
    int userChoice, carCount = 0;
    do
    {
        system("cls");
        cout << "\n****** Vehicle Registration System ******\n\n1.Add new ELectric Car\n2.Display All Cars\n3.Update Battery Capacity\n4.Find Car with Lowest Charging Time\n5.Exit" << endl;
        cin >> userChoice;
        while (cin.fail() || (userChoice < 1 && userChoice > 5))
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid Input! Try again: ";
            cin >> userChoice;
        };
        switch (userChoice)
        {
        case 1:
        {
            system("cls");
            string reg, owner, fuel;
            int seats;
            double battery, time;
            cout << "Reg#: ";
            cin.ignore();
            getline(cin, reg);
            while (reg.empty())
            {
                cout << "Reg# cannot be empty!\nEnter again: ";
                getline(cin, reg);
            }
            cout << "owner: ";
            getline(cin, owner);
            while (owner.empty())
            {
                cout << "Owner name cannot be empty!\nEnter again: ";
                getline(cin, owner);
            }
            cout << "Fuel Type: ";
            getline(cin, fuel);
            while (fuel.empty())
            {
                cout << "Fuel type cannot be empty!\nEnter again: ";
                getline(cin, fuel);
            }
            cout << "Seats capacity: ";
            cin >> seats;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid! Enter again: ";
                cin >> seats;
            }
            cout << "Battery Capacity: ";
            cin >> battery;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid! Enter again: ";
                cin >> battery;
            }
            cout << "Charging Time: ";
            cin >> time;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid! Enter again: ";
                cin >> time;
            }
            obj[carCount] = ElectricCar(reg, owner, fuel, seats, battery, time);
            carCount++;
            system("pause");
            break;
        }
        case 2:
        {
            if (carCount < 1)
            {
                cout << "No cars added" << endl;
                break;
            }
            for (int i = 0; i < carCount; i++)
            {
                cout << "Car " << i + 1 << " data: \n";
                obj[i].display();
                cout << endl;
            }
            system("pause");
            break;
        }
        case 3:
        {
            string reg;
            cin.ignore();
            cout << "Enter registration Num to update: ";
            getline(cin, reg);
            int foundIdx = -1;
            for (int i = 0; i < carCount; i++)
            {
                if (reg == obj[i].getRegister())
                {
                    foundIdx = i;
                }
            }
            if (foundIdx == -1)
            {
                cout << "No car found" << endl;
            }
            else
            {
                int newBattery;
                obj[foundIdx].display();
                cout << "\nEnter new battery capacity: ";
                cin >> newBattery;
                while (cin.fail())
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Invalid battery! Enter again: ";
                    cin >> newBattery;
                }
                obj[foundIdx].setBattery(newBattery);
                cout << "\nBattery capacity Updated Successfully\n";
            }
            system("pause");
            break;
        }
        case 4:
        {
            ElectricCar lowChargeCar = obj[0];
            for (int i = 1; i < carCount; i++)
            {
                if (obj[i].getChargeTime() < lowChargeCar.getChargeTime())
                {
                    lowChargeCar = obj[i];
                }
            }
            cout << "\nThe car with lowest charging time is:\n";
            lowChargeCar.display();
            system("pause");
            break;
        }
        }
    } while (userChoice != 5);
    return 0;
}