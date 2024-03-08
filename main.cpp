#include <iostream>
#include <string>
#include <cstdlib> // For exit()

using namespace std;

class Library {
public:
    int b_id;
    string b_name; // Use string for names
    string author;
    string s_name;
    int s_id;
    int pages;
};

int main() {
    Library lib[20];
    int input = 0;
    int count = 0;

    while (input != 3) {
        cout << "Enter 1 to Add Book's to LMS" << endl;
        cout << "Enter 2 to display book details in LMS" << endl;
        cout << "Enter 3 to EXIT" << endl;
        cin >> input;
        cin.ignore(); // Ignore newline character left in input buffer

        switch (input) {
            case 1:
                cout << "Enter Book ID: ";
                cin >> lib[count].b_id;
                cout << "Enter Book Name: ";
                cin.ignore(); // Ignore newline character left in input buffer
                getline(cin, lib[count].b_name); // Use getline() for book name
                cout << "Enter Author Name: ";
                getline(cin, lib[count].author);
                cout << "Enter Number of Pages: ";
                cin >> lib[count].pages;
                cout << "Enter Student Name: ";
                cin.ignore(); // Ignore newline character left in input buffer
                getline(cin, lib[count].s_name);
                cout << "Enter Student ID: ";
                cin >> lib[count].s_id;
                count++;
                break;

            case 2:
                for (int i = 0; i < count; i++) {
                    cout << "Book ID is: " << lib[i].b_id << endl;
                    cout << "Book Name is: " << lib[i].b_name << endl;
                    cout << "Author Name is: " << lib[i].author << endl;
                    cout << "Number of Pages: " << lib[i].pages << endl;
                    cout << "Student Name is: " << lib[i].s_name << endl;
                    cout << "Student ID is: " << lib[i].s_id << endl;
                }
                break;

            case 3:
                exit(0);
                break;

            default:
                cout << "You Have Entered Wrong Value!!! Please Provide Correct Value" << endl;
        }
    }

    return 0;
}
