#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const int maxCapacity = 100;
int booksCount = 0;
struct Borrower
{
    string borrowerName;
    string issueDate;
    string returnDueDate;
};
struct Purchase
{
    int price;
    bool isAvailable;
};
struct Book
{
    string title;
    string author;
    string genre;
    int bookID;
    Borrower *borrowerInfo;
    Purchase *purchaseInfo;
};
bool dateValidation(const string &date)
{
    const int dateSize = 10;
    if (date[2] != '/' || date[5] != '/')
    {
        return false;
    }

    for (int i = 0; i < dateSize; i++)
    {
        if (i != 2 && i != 5 && !isdigit(date[i]))
        {
            return false;
        }
    }
    return true;
}
int getIntInput(int min, int max, const string &msg)
{
    int x;
    cout << msg;
    cin >> x;
    while (x < min || x > max || cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid! " << msg;
        cin >> x;
    }
    return x;
}

void addBooks(Book *list)
{
    int booksNo;
    cout << "Enter number of books you want to add: ";
    cin >> booksNo;
    while (booksNo > maxCapacity || booksNo > (maxCapacity - booksCount))
    {
        if (booksNo > maxCapacity)
        {
            cout << "You cannot add more than 100 books! Max Capacity = 100" << endl;
        }
        else
        {
            cout << "You can add only " << maxCapacity - booksCount << " books more" << endl;
        }
        cout << "Enter a valid number: ";
        cin >> booksNo;
    }
    int totalBooks = booksCount + booksNo;
    cout << booksCount << " are already added. Adding more\n";
    for (int i = booksCount; i < totalBooks; i++)
    {
        list[i].borrowerInfo = new Borrower;
        list[i].purchaseInfo = new Purchase;
        cin.ignore();
        cout << "Book " << i + 1 << " details:\n";
        cout << "Enter Book title: ";
        getline(cin, list[i].title);
        while (list[i].title.empty())
        {
            cout << "Title cannot be empty!Please enter a title: ";
            getline(cin, list[i].title);
        }
        cout << "Enter Author: ";
        getline(cin, list[i].author);
        cout << "Enter Genre: ";
        getline(cin, list[i].genre);

        bool duplicate;
        do
        {
            duplicate = false;
            list[i].bookID = getIntInput(1, 100, "Enter Book ID (1-100): ");

            for (int j = 0; j < booksCount; j++)
            {
                if (list[j].bookID == list[i].bookID)
                {
                    cout << "Book ID already exists. Choose another.\n";
                    duplicate = true;
                    break;
                }
            }

        } while (duplicate);
        cin.ignore();
        cout << "Enter Borrower Name: ";
        getline(cin, list[i].borrowerInfo->borrowerName);
        cout << "Enter Issue date (DD/MM/YYYY): ";
        getline(cin, list[i].borrowerInfo->issueDate);
        while (!dateValidation(list[i].borrowerInfo->issueDate))
        {
            cout << "Invalid Format! Enter again (DD/MM/YYYY): ";
            getline(cin, list[i].borrowerInfo->issueDate);
        }
        cout << "Enter Return Due Date (DD/MM/YYYY): ";
        getline(cin, list[i].borrowerInfo->returnDueDate);
        while (!dateValidation(list[i].borrowerInfo->returnDueDate))
        {
            cout << "Invalid Format! Enter again (DD/MM/YYYY): ";
            getline(cin, list[i].borrowerInfo->returnDueDate);
        }

        list[i].purchaseInfo->price = getIntInput(100, 20000, "Enter Price (100 to 20000): ");

        int availInput;
        cout << "Is Available (1 = Yes, 0 = No): ";
        cin >> availInput;
        while (cin.fail() || (availInput != 0 && availInput != 1))
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid Input! Try Again!\nIs Available (1 = Yes, 0 = No):";
            cin >> availInput;
        }
        list[i].purchaseInfo->isAvailable = availInput;
        booksCount++;
        cout << "Book added Successfully\n";
    }
}
void displayBooks(Book *list)
{
    if (booksCount == 0)
    {
        cout << "No books available" << endl;
        return;
    }
    cout << "\n===== Books Details =====\n\n";

    cout << left
         << setw(12) << "Issue Date"
         << setw(14) << "Return Date"
         << setw(18) << "Book Title"
         << setw(6) << "ID"
         << setw(16) << "Author"
         << setw(10) << "Price"
         << setw(14) << "Genre"
         << setw(20) << "Borrower Name"
         << endl;

    cout << string(110, '-') << endl;

    for (int i = 0; i < booksCount; i++)
    {
        cout << left
             << setw(12) << list[i].borrowerInfo->issueDate
             << setw(14) << list[i].borrowerInfo->returnDueDate
             << setw(18) << list[i].title
             << setw(6) << list[i].bookID
             << setw(16) << list[i].author
             << setw(10) << list[i].purchaseInfo->price
             << setw(14) << list[i].genre
             << setw(20) << list[i].borrowerInfo->borrowerName
             << endl;
    }
}
void releaseMemory(Book *&list)
{
    for (int i = 0; i < booksCount; i++)
    {
        delete list[i].borrowerInfo;
        delete list[i].purchaseInfo;
        list[i].borrowerInfo = nullptr;
        list[i].purchaseInfo = nullptr;
    }
    delete[] list;
    list = nullptr;
}
int main()
{
    Book *bookList = new Book[maxCapacity];
    int userChoice;
    do
    {
        cout << "===== Library Management System =====";
        cout << "\n1. Add Book\n2. Display Books\n3. Exit\nEnter your choice: ";
        cin >> userChoice;
        while (userChoice != 1 && userChoice != 2 && userChoice != 3)
        {
            cout << "Invalid Input! Try again: ";
            cin >> userChoice;
        }
        switch (userChoice)
        {
        case 1:
            addBooks(bookList);
            break;
        case 2:
            displayBooks(bookList);
            break;
        case 3:
            releaseMemory(bookList);
            cout << "Exiting System" << endl;
            break;
        }
    } while (userChoice != 3);
    return 0;
}