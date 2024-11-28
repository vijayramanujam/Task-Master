# TaskMaster - CLI To-Do List

TaskMaster is a simple command-line to-do list application developed in C++ to help users manage tasks. The project was built with the purpose of gaining a deeper understanding of how linked lists work and how to implement them in practice.

## Features

- **Push**: Add a new task to the to-do list.
- **Pop**: Remove the most recent task from the list.
- **Display**: View all tasks currently in the to-do list.
- **Exit**: Exit the application.

The program operates in a continuous loop, prompting the user to select one of the above options. The to-do list is managed using a linked list, with each task being a node in the list.

## How It Works

The application runs in a simple `while` loop, repeatedly asking the user for input until they choose to exit. The core functionality includes:
- **Push**: Adds a task to the list.
- **Pop**: Removes the most recent task (LIFO order).
- **Display**: Displays all tasks currently in the list.
- **Exit**: Exits the program.

At present, there is **no data persistence** (tasks will not be saved after exiting the program). However, future plans include implementing data persistence to store tasks across sessions.

## Why I Built This Project

The main goal of this project was to develop a better understanding of how **linked lists** work in C++. By implementing a basic to-do list, I was able to explore the concepts of dynamically allocated memory, pointers, and the structure of a linked list.

## Future Enhancements

- **Data Persistence**: Saving tasks to a file so they persist between sessions.
- **Task Editing**: Ability to edit or update existing tasks.
- **Improved User Interface**: Enhanced user interaction with error handling and input validation.

## Getting Started

To run the project, simply clone this repository and compile the C++ code using any standard C++ compiler. For example:

```bash
git@github.com:vijayramanujam/Task-Master.git
cd Task-Master
g++ -o taskmaster main.cpp
./taskmaster

