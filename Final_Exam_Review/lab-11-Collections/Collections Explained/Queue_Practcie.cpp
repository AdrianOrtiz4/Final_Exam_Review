#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Person {
private:
    string name;

public:
    Person(string n) {
        name = n;
    }

    string getName() const {
        return name;
    }
};



/*
In C++, a queue is a data structure that follows the First-In-First-Out (FIFO) principle. 
It is similar to a real-life queue or line, where the first person to arrive is the first person to leave.

The queue class provides a set of methods to interact with the queue, some of which are:

push(element) - adds an element to the back of the queue
pop() - removes the element from the front of the queue
front() - returns the element at the front of the queue without removing it
back() - returns the element at the back of the queue without removing it
empty() - checks if the queue is empty and returns a Boolean value
size() - returns the number of elements in the queue

In C++, the standard library provides the queue container class that implements the queue data structure. The queue class is defined in the <queue> header file.

Here's an example of how to use queues in C++:


*/
int findPersonPosition(queue<Person> q, const Person& p) {
    /*
    find a persons positon in a queue based on their name
    supposed duplicate names are impossible and the first position in the queue is 1*/
}

int main() {
    queue<Person> q;

    // add some people to the queue
    q.push(Person("John"));
    q.push(Person("Alice"));
    q.push(Person("Bob"));

    // find the position of Alice in the queue
    Person alice("Alice");
    int pos = findPersonPosition(q, alice);
    if (pos == -1) {
        cout << alice.getName() << " not found in the queue" << endl;
    } else {
        cout << alice.getName() << " is at position " << pos << " in the queue" << endl;
    }

    return 0;
}




