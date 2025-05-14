#include <iostream>
#include <fstream>
using namespace std;

class BookManager {
    string id, name, author, searchId;
    fstream file;

public:
    void addBook();
    void showAll();
    void extractBook();
};

void BookManager::addBook() {
    cin.ignore();  // Clear input buffer
    cout << "\nEnter Book ID :: ";
    getline(cin, id);
    cout << "Enter Book Name :: ";
    getline(cin, name);
    cout << "Enter Book's Author Name :: ";
    getline(cin, author);

    file.open("bookData.txt", ios::out | ios::app);
    if (file.is_open()) {
        file << id << "" << name << "" << author << "\n";
        file.close();
        cout << "Book added successfully!\n";
    } else {
        cout << "Unable to open file!\n";
    }
}

void BookManager::showAll() {
    file.open("bookData.txt", ios::in);
    if (!file) {
        cout << "No data found!\n";
        return;
    }

    cout << "\n\n";
    cout << "Book ID\t\tBook Name\t\tAuthor Name\n";
    cout << "-----------------------------------------------------\n";

    while (getline(file, id, '*') &&
           getline(file, name, '*') &&
           getline(file, author)) {
        cout << id << "\t\t" << name << "\t\t" << author << "\n";
    }

    file.close();
}

void BookManager::extractBook() {
    cin.ignore();  // Clear input buffer
    cout << "Enter Book ID to extract :: ";
    getline(cin, searchId);

    file.open("bookData.txt", ios::in);
    bool found = false;

    cout << "\nSearching...\n";
    while (getline(file, id, '*') &&
           getline(file, name, '*') &&
           getline(file, author)) {
        if (searchId == id) {
            cout << "\nBook Found!\n";
            cout << "Book ID: " << id << "\n";
            cout << "Book Name: " << name << "\n";
            cout << "Author: " << author << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book ID not found.\n";
    }

    file.close();
}

int main() {
    BookManager obj;
    char choice;

    do {
        cout << "\n------------------------\n";
        cout << "1 - Show All Books\n";
        cout << "2 - Extract Book\n";
        cout << "3 - Add Book (ADMIN)\n";
        cout << "4 - Exit\n";
        cout << "------------------------\n";
        cout << "Enter Your Choice :: ";
        cin >> choice;

        switch (choice) {
            case '1':
                obj.showAll();
                break;
            case '2':
                obj.extractBook();
                break;
            case '3':
                obj.addBook();
                break;
            case '4':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != '4');

    return 0;
}