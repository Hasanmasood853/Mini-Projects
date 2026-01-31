#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
// There are 5 book genre for this library: Fantasy/ Science Fiction/ Mystery/Thriller/Romance
const int maxBooks = 100;
int bookCount = 0;
class Library
{
private:
    string title, author;
    int pages, genreChoice;
    float rating;
    bool isAvailable;
    string bookType = "Simple";

public:
    void addBook(void);
    void updateBook(void);
    void displayBooks(void);
    Library()
    {
        title = "";
        author = "";
        genreChoice = 0;
        pages = 0;
        rating = 0.0;
        isAvailable = true;
        bookType = "Standard";
    }
    Library(string t, string a, int g, int p, float r)
    {
        title = t;
        author = a;
        genreChoice = g;
        pages = p;
        rating = r;
        isAvailable = true;

        if (pages > 300)
        {
            bookType = "Long Read";
        }
        else
        {
            bookType = "Simple";
        }
        if (rating > 4.5 && bookType == "Simple")
        {
            bookType = "Highly Rated!";
        }
        else if (rating > 4.5 && bookType == "Long Read!")
        {
            bookType = "Highly Recommended!";
        }
    }
    string getTitle()
    {
        return title;
    }
    string getAuthor()
    {
        return author;
    }
};
void Library::addBook()
{
    cout << "Enter title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter author: ";
    getline(cin, author);
    cout << "\n===Genre Selection===\n1.Fantasy\n2.Science Fiction\n3.Mystery\n4.Thriller\n5.Romance\nSelect genre (1-5): ";
    cin >> genreChoice;
    while (cin.fail() || (genreChoice < 1 || genreChoice > 5))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid Choice! Enter again: ";
        cin >> genreChoice;
    }
    cout << "Enter pages: ";
    cin >> pages;
    if (pages > 300)
    {
        bookType = "Long Read";
    }
    cout << "Enter rating (0-5): ";
    cin >> rating;
    while (rating < 0.0 || rating > 5.0)
    {
        cout << "Invalid Input! Enter again: ";
        cin >> rating;
    }
    if ((rating > 4.5) && (bookType == "Simple"))
    {
        bookType = "Highly Rated!";
    }
    else if ((rating > 4.5) && (bookType == "Long Read"))
    {
        bookType = " Highly Recommended!";
    }
    isAvailable = true;
    bookCount++;
    cout << "\nBook added Successfully\n";
}
void Library::updateBook()
{
    int updateChoice;
    cout << "\n1.Pages\n2.Rating\n3.Availability\nWhat you want to change: ";
    cin >> updateChoice;
    switch (updateChoice)
    {
    case 1:
    {
        cout << "Update pages: ";
        cin >> pages;
        while (cin.fail() || pages < 0)
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid Input! Enter again: ";
            cin >> pages;
        }
        if (pages > 300)
        {
            bookType += "Long Read";
        }
        break;
    }
    case 2:
    {
        cout << "Update Rating (0-5): ";
        cin >> rating;
        while (cin.fail() || (rating < 0.0 || rating > 5.0))
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid Input! Enter again: ";
            cin >> rating;
        }
    }
    case 3:
    {
        char availability;
        cout << "Update availability (y/n): ";
        cin >> availability;
        while (availability != 'y' && availability != 'n' && availability != 'Y' && availability != 'N')
        {
            cout << "Invalid Input! Enter again (y/n): ";
            cin >> availability;
        }
        break;
    }
    }
    cout << "Book Updated Successfully" << endl;
};
void Library::displayBooks()
{
    cout << left << setw(25) << title
         << setw(20) << author
         << setw(10) << pages
         << setw(10) << rating
         << setw(25) << bookType
         << setw(15) << (isAvailable ? "Available" : "Borrowed");
    switch (genreChoice)
    {
    case 1:
        cout << setw(15) << "Fantasy" << endl;
        break;

    case 2:
        cout << setw(15) << "Science Fiction" << endl;
        break;
    case 3:
        cout << setw(15) << "Mystery" << endl;
        break;
    case 4:
        cout << setw(15) << "Thriller" << endl;
        break;
    case 5:
        cout << setw(15) << "Romance" << endl;
        break;
    }
}
int main()
{
    Library Books[maxBooks] = {
        Library("The Hobbit", "J.R.R. Tolkien", 1, 310, 4.8),
        Library("Project Hail Mary", "Andy Weir", 2, 473, 4.9),
        Library("The Silent Patient", "Alex Michaelides", 3, 336, 4.1),
        Library("Gone Girl", "Gillian Flynn", 4, 432, 4.0),
        Library("Pride & Prejudice", "Jane Austen", 5, 279, 4.7)};
    bookCount = 5;
    int userChoice;
    do
    {
        cout << "\n======= Library Management =======\n";
        cout << "1.Add Books\n2.Update Book\n3.Display Books\n4.Exit\nEnter your choice: ";
        cin >> userChoice;
        while (userChoice < 1 || userChoice > 4)
        {
            cout << "Invalid Choice! Enter again: ";
            cin >> userChoice;
        }
        switch (userChoice)
        {
        case 1:
        {
            int booksNo;
            cout << "Enter No of books to add: ";
            cin >> booksNo;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                cin >> booksNo;
            }
            for (int i = 0; i < booksNo; i++)
            {
                Books[i].addBook();
            }
            break;
        }
        case 2:
        {
            int searchChoice;
            cout << "\n1.Search by Title\t2.Search by author\nEnter your choice: ";
            cin >> searchChoice;
            while (searchChoice != 1 && searchChoice != 2)
            {
                cout << "Invalid Choice! Enter again: ";
                cin >> userChoice;
            }
            if (searchChoice == 1)
            {
                cout << "\nEnter title to search: ";
            }
            else
            {
                cout << "\nEnter author to search: ";
            }
            string findBook;
            cin.ignore();
            getline(cin, findBook);
            int foundIdx = -1;
            for (int i = 0; i < bookCount; i++)
            {
                if (searchChoice == 1)
                {
                    if (Books[i].getTitle() == findBook)
                    {
                        foundIdx = i;
                        break;
                    }
                }
                else if (searchChoice == 2)
                {
                    if (Books[i].getAuthor() == findBook)
                    {
                        foundIdx = i;
                        break;
                    }
                }
            }
            Books[foundIdx].updateBook();
            break;
        }
        case 3:
        {
            if (bookCount < 1)
            {
                cout << "No books Available" << endl;
                break;
            }
            cout << "\n"
                 << left << setw(25) << "Title" << setw(20) << "Author" << setw(10) << "Pages"
                 << setw(10) << "Rating" << setw(25) << "Book Type" << setw(15) << "Status" << setw(15) << "Genre" << endl;
            cout << string(120, '-') << endl;

            for (int i = 0; i < bookCount; i++)
            {
                Books[i].displayBooks();
            }
            break;
        }
        }
    } while (userChoice != 4);
    return 0;
}
