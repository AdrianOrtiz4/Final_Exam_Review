#include <iostream>
#include <stack>
#include <vector>

using namespace std;


/*

In C++, a stack is a container that operates on a last-in, first-out (LIFO) principle. 
It is a data structure that allows you to store and retrieve data in a specific order. 
The stack is a dynamic data structure, which means that its size can be changed during runtime.

A stack is essentially an abstract data type that supports two main operations:

Push: Adds an element to the top of the stack.
Pop: Removes the top element from the stack.
In addition to these fundamental operations, a stack may also provide other methods to access and manipulate its elements, such as:

Top: Returns the top element of the stack without removing it.
Size: Returns the number of elements currently in the stack.
Empty: Returns a boolean value indicating whether the stack is empty or not.
In C++, the stack container is part of the Standard Template Library (STL). To use a stack, you need to include the <stack> header file. Here's an example of how to declare and use a stack in C++: of how to declare and use a stack in C++:
*/

bool checkIfVectorExistsInStack(std::stack<std::vector<int>>& Playlist, std::vector<int>& target) {
    std::stack<std::vector<int>> copyPlaylist = Playlist; // Make a copy of the original stack
    while (!copyPlaylist.empty()) {
        if (copyPlaylist.top() == target) {
            return true;
        }
        copyPlaylist.pop();
    }
    return false;
}
int main()
{
    stack<int> myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Size of stack: " << myStack.size() << endl;
    cout << "Top element: " << myStack.top() << endl;

    myStack.pop();

    cout << "Size of stack after pop: " << myStack.size() << endl;
    cout << "Top element after pop: " << myStack.top() << endl;

    std::stack<std::vector<int>> Playlist;

    // Push some vectors onto the stack
    Playlist.push({1, 2, 3});
    Playlist.push({4, 5, 6});
    Playlist.push({7, 8, 9});

    // Define the target vector
    std::vector<int> target = {4, 5, 6};

    // Check if the target vector exists in the stack
    bool found = checkIfVectorExistsInStack(Playlist, target);

    if (found) {
        std::cout << "Target vector found in the playlist!" << std::endl;
    } else {
        std::cout << "Target vector not found in the playlist." << std::endl;
    }

    return 0;
}
