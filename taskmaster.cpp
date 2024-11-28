

#include <iostream>
#include <string>
#include <limits>

#ifdef _WIN32
#include <windows.h>
#endif

struct Node {

    std::string data;
    Node *next;
};

enum MenuOption {
    PUSH = 1,
    POP,
    DISPLAY,
    EXIT
};
// Function to clear the screen based on OS
void clearScreen() {
#ifdef _WIN32
    system("cls");  // Windows
#else
    system("clear");  // Unix/Linux/Mac
#endif
}


void clearInputBuffer() {
    // Ignore all characters in the input buffer until a newline is encountered
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void push(Node* head) {

    clearScreen();
    std::string todo;
    std::cout << "Enter a todo: ";
    std::getline(std::cin, todo);

    Node* temp = new Node; // we have a todo now
    temp->data = todo;
    temp->next = nullptr;

    Node* current = head; // to track the nodes as we need need to push the new node to the list

    while (current->next != nullptr) { // to traverse to the last but one node

        current = current->next;
    }

    current->next = temp;

}

void display(Node* head) {

    clearScreen();

    int i = 1;
    int choice = 1;

    Node* current = head;

    while (current != nullptr && current->next != nullptr) { // to traverse to the last but one node
        current = current->next;
        std::cout << " [" << i << "]" << " " << current->data << std::endl;
        i++;
    }

    while (choice != 0) {

        std::cout << "Press 0 to exit: " ;
        std::cin >> choice;
        if (std::cin.fail()) {                                                                  // Check if input failed
            clearScreen();
            std::cout << "Invalid input. Please enter a valid integer.\n";
            std::cin.clear();                                                                // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');             // Ignore any remaining invalid input in the buffer
            choice = 1;
        }
    }
}

void pop(Node* head) { // removes the first node from the linkedlist

    Node* current = head ->next;
    head->next = current->next;
    delete current;
    current = nullptr;
    clearScreen();
    std::cout << "Todo has been popped!" << std::endl;

}



void print() {


    std::cout << "+--------------------------------------------------+" << std::endl;
    std::cout << "|                   TO-DO LIST                     |" << std::endl;
    std::cout << "+--------------------------------------------------+" << std::endl;
    std::cout << "| [1] push                                         |" << std::endl;
    std::cout << "| [2] pop                                          |"<< std::endl;
    std::cout << "| [3] display                                      |"<< std::endl;
    std::cout << "| [4] exit                                         |"<< std::endl;
    std::cout << "+--------------------------------------------------+"<< std::endl;
}

int main() {

    Node* head = new Node;
    head->next = nullptr;
    int choice {};

        // Display the menu options

    while (choice != 4) {

        print();
        // std::cout << "\nSelect an option:\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {                                                                  // Check if input failed
            clearScreen();
            std::cout << "Invalid input. Please enter a valid integer.\n";
            std::cin.clear();                                                                // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');             // Ignore any remaining invalid input in the buffer

        } else {

            switch (static_cast<MenuOption>(choice)) {

            case PUSH:
                // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the remaining newline
                clearInputBuffer();
                push(head);
                break;

            case POP:
                pop(head);
                break;

            case DISPLAY:
                display(head);
                clearScreen();
                break;

            case EXIT:
                clearScreen();
                std::cout << "Exiting program: Goodbye!" << std::endl;
                break;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }
    }

    return 0;
}
