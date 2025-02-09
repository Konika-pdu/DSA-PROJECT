#include <iostream>
#include <string>
using namespace std;

// Node structure for the doubly linked list
class Node {
public:
    string name;
    string phoneNumber;
    Node* next;
    Node* prev;

    Node(string n, string p) : name(n), phoneNumber(p), next(nullptr), prev(nullptr) {}
};

// Class for the Phone Directory
class PhoneDirectory {
private:
    Node* head;

public:
    PhoneDirectory() : head(nullptr) {}

    // Function to add a new contact
    void addContact(string name, string phoneNumber) {
        Node* newNode = new Node(name, phoneNumber);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << "Contact added: " << name << " - " << phoneNumber << endl;
    }

    // Function to display all contacts
    void displayContacts() const {
        if (!head) {
            cout << "No contacts available." << endl;
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << "Name: " << temp->name << ", Phone Number: " << temp->phoneNumber << endl;
            temp = temp->next;
        }
    }

    // Function to search for a contact
    void searchContact(string name)  {
        Node* temp = head;
        while (temp) {
            if (temp->name == name) {
                cout << "Contact found: " << temp->name << " - " << temp->phoneNumber << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Contact not found." << endl;
    }

    // Function to delete a contact
    void deleteContact(string name) {
        Node* temp = head;
        while (temp) {
            if (temp->name == name) {
                if (temp->prev) {
                    temp->prev->next = temp->next;
                } else {
                    head = temp->next; // Update head if it's the first node
                }
                if (temp->next) {
                    temp->next->prev = temp->prev;
                }
                delete temp;
                cout << "Contact deleted: " << name << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Contact not found." << endl;
    }

    // Destructor to free memory
    ~PhoneDirectory() {
        Node* temp = head;
        while (temp) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

// Main function for the Phone Directory
int main() {
    PhoneDirectory directory;
    int choice;
    string name, phoneNumber;

    do {
        cout << "\nPhone Directory Menu:\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter phone number: ";
                cin >> phoneNumber;
                directory.addContact(name, phoneNumber);
                break;
            case 2:
                directory.displayContacts();
                break;
            case 3:
                cout << "Enter name to search: ";
                cin >> name;
                directory.searchContact(name);
                break;
            case 4:
                cout << "Enter name to delete: ";
                cin >> name;
                directory.deleteContact(name);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 5);

    return 0;
}