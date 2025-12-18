#include <iostream>
using namespace std;

string bookName[50];
string author[50];
int status[50];
int countBook = 0;

void addBook()
{
    cout << "Enter book name: ";
    cin >> bookName[countBook];

    cout << "Enter author name: ";
    cin >> author[countBook];

    status[countBook] = 1;
    countBook++;

    cout << "Book added\n";
}

void searchBook()
{
    string name;
    bool found = false;

    cout << "Enter book name: ";
    cin >> name;

    for (int i = 0; i < countBook; i++)
    {
        if (bookName[i] == name)
        {
            cout << bookName[i] << " - " << author[i] << " - ";
            cout << (status[i] == 1 ? "Available\n" : "Borrowed\n");
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Book not found\n";
}

void borrowBook()
{
    string name;
    cout << "Enter book name: ";
    cin >> name;

    for (int i = 0; i < countBook; i++)
    {
        if (bookName[i] == name)
        {
            if (status[i] == 1)
            {
                status[i] = 0;
                cout << "Book borrowed\n";
            }
            else
                cout << "Book already borrowed\n";
            return;
        }
    }
    cout << "Book not found\n";
}

void returnBook()
{
    string name;
    cout << "Enter book name: ";
    cin >> name;

    for (int i = 0; i < countBook; i++)
    {
        if (bookName[i] == name)
        {
            if (status[i] == 0)
            {
                status[i] = 1;
                cout << "Book returned\n";
            }
            else
                cout << "Book already available\n";
            return;
        }
    }
    cout << "Book not found\n";
}

void displayBooks()
{
    for (int i = 0; i < countBook; i++)
    {
        cout << i + 1 << ". "
             << bookName[i] << " - "
             << author[i] << " - "
             << (status[i] == 1 ? "Available\n" : "Borrowed\n");
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Display Books\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: addBook(); break;
        case 2: searchBook(); break;
        case 3: borrowBook(); break;
        case 4: returnBook(); break;
        case 5: displayBooks(); break;
        case 6: cout << "Exit\n"; break;
        default: cout << "Invalid choice\n";
        }

    } while (choice != 6);

    return 0;
}