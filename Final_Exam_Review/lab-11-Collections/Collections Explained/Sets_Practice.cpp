#include <iostream>
#include <set>
/* 
In C++, a set is an ordered container that stores unique elements in a sorted manner. 
The elements in a set are always sorted in ascending order by default, and duplicate values are not allowed. 
The elements of a set are accessed using an iterator, which can be used to traverse the elements of the set in either a forward or a reverse direction.

Here are some methods for sets in C++:
insert(): Inserts an element into the set.

erase(): Removes an element from the set.

clear(): Removes all elements from the set.

empty(): Checks if the set is empty.

size(): Returns the number of elements in the set.

count(): Returns the number of occurrences of a specified element in the set.

find(): Searches the set for a specified element and returns an iterator to it if found, otherwise returns an iterator to the end of the set.

ents that are equal to a specified value.

begin(): Returns an iterator to the beginning of the set.

end(): Returns an iterator to the end of the set.

rbegin(): Returns a reverse iterator to the beginning of the set.

rend(): Returns a reverse iterator to the end of the set.

emplace(): Inserts a new element into the set using its constructor.

emplace_hint(): Inserts a new element into the set using a hint for its position.

*/
int main() {
    std::set<int> mySet = {4, 2, 1, 3, 5};

    // Iterating through the set using an iterator
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";//use -> for methods
    }
    std::cout << std::endl;
    
    std::set<int> mySet = {4, 2, 1, 3, 5};

    // Reverse iterating through the set using a reverse iterator
    for (auto it = mySet.rbegin(); it != mySet.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}


void removeOddNumbers(std::set<int>& mySet) {
  /*
  iterate over a set and remove all the odd numebrs 
  */
}

void removeStringsStartingWithChar(std::set<std::string>& mySet, char targetChar) {
  /*
  iterate over a set and remove all the strings that have the target char
  */
}

void removeString(std::set<std::string>& mySet, const std::string& targetString) {
   /*
  iterate over a set and remove all the strings that have the target string
  */
}

std::set<int> uniteSets(const std::set<int>& set1, const std::set<int>& set2) {
  /*
 untie two sets
  */
}
