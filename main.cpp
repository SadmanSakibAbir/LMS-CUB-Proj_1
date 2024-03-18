#include <iostream>
#include <fstream> // Include the header file for file stream operations
#include <string>
#include <cstdlib>
#include <limits> // Include the header file for numeric limits

using namespace std;

class Library {
public:
    int b_id;
    string b_name;
    string author;
    int pages;
    string s_name;
    int s_id;
};

// Function to save book details to a text file
void saveBooksToFile(Library lib[], int count) {
    // Open file for appending (to add new records without deleting previous ones)
    ofstream file("book_list.txt", ios::app); // Open file in append mode

    if (file.is_open()) {
        // Write book details to the file
        for (int i = 0; i < count; i++) {
            file << "Book ID: " << lib[i].b_id << endl;
            file << "Book Name: " << lib[i].b_name << endl;
            file << "Author Name: " << lib[i].author << endl;
            file << "Number of Pages: " << lib[i].pages << endl;
            file << "Student Name: " << lib[i].s_name << endl;
            file << "Student ID: " << lib[i].s_id << endl;
            file << endl; // Add an empty line between each book
        }
        file.close(); // Close the file
        cout << "Book list saved to 'book_list.txt'." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}

// Function to display book details from file
void displayBooksFromFile() {
    ifstream file("book_list.txt"); // Open file for reading

    if (file.is_open()) {
        string line;
        // Read each line from the file and display it
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close(); // Close the file
    } else {
        cout << "Unable to open file." << endl;
    }
}

int main() {
    Library lib[20]; // Array to store library objects
    int input = 0; // Variable to store user input
    int count = 0; // Variable to keep track of number of books

    // Main menu loop
    while (input != 5) {
        // Display menu options
        cout << "Enter 1 to Add Book's to LMS" << endl;
        cout << "Enter 2 to display book details in LMS or from file" << endl;
        cout << "Enter 3 to Save Book List to File" << endl;
        cout << "Enter 4 to EXIT" << endl;
        cin >> input; // Read user input
        cin.ignore(); // Ignore newline character left in input buffer

        switch (input) {
            case 1:
                // Add book details
                cout << "Enter Book ID: ";
                cin >> lib[count].b_id;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                cout << "Enter Book Name: ";
                getline(cin, lib[count].b_name); // Use getline() for book name
                cout << "Enter Author Name: ";
                getline(cin, lib[count].author);
                cout << "Enter Number of Pages: ";
                cin >> lib[count].pages;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                cout << "Enter Student Name: ";
                getline(cin, lib[count].s_name);
                cout << "Enter Student ID: ";
                cin >> lib[count].s_id;
                count++; // Increment count for next book
                break;

            case 2:
                // Display book details
                cout << "Enter 1 to display book details from LMS" << endl;
                cout << "Enter 2 to display book details from file" << endl;
                int choice;
                cin >> choice;
                cin.ignore(); // Ignore newline character left in input buffer
                if (choice == 1) {
                    // Display book details from memory
                    for (int i = 0; i < count; i++) {
                        cout << "Book ID is: " << lib[i].b_id << endl;
                        cout << "Book Name is: " << lib[i].b_name << endl;
                        cout << "Author Name is: " << lib[i].author << endl;
                        cout << "Number of Pages: " << lib[i].pages << endl;
                        cout << "Student Name is: " << lib[i].s_name << endl;
                        cout << "Student ID is: " << lib[i].s_id << endl;
                    }
                } else if (choice == 2) {
                    // Display book details from file
                    displayBooksFromFile();
                } else {
                    cout << "Invalid choice!" << endl;
                }
                break;

            case 3:
                // Save books to file
                saveBooksToFile(lib, count);
                break;

            case 4:
                // Save books to file before exiting
                saveBooksToFile(lib, count);
                exit(0); // Exit the program
                break;

            default:
                cout << "You Have Entered Wrong Value!!! Please Provide Correct Value" << endl;
        }
    }

    return 0;
}
