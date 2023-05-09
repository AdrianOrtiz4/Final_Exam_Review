#include <iostream>
#include <map>
#include <string>
using namespace std;
/*
In C++, a map is a container that stores a set of key-value pairs. 
Each key in the map must be unique, and the values associated with those keys can be accessed and modified using the keys.
To use a map in C++, you must include the <map> header file. Here's an example of how to declare a map:


int main() {
    map<string, int> myMap;
    // code to use the map goes here
    return 0;
}

common methods:
insert(): Inserts a new key-value pair into the map. If the key already exists in the map, its corresponding value is updated.

erase(): Removes an element from the map based on its key.

clear(): Removes all elements from the map.

size(): Returns the number of elements in the map.

find(): Searches the map for a specific key and returns an iterator to the element if found, or an end iterator if not found.

count(): Returns the number of elements in the map with a specific key.

empty(): Returns true if the map is empty, false otherwise.

operator[]: Allows you to access the value associated with a specific key. If the key does not exist in the map, a new key-value pair is created with a default-constructed value.

ietrate with a for loop
  map<string, int>::iterator it;
    for (it = myMap.begin(); it != myMap.end(); ++it) {
        cout << it->first << " has a value of " << it->second << endl;
    }
 In each iteration of the loop, we access the key using it->first and the value using it->second
*/
void countLetters(string str) {
    map<char, int> letterCount;
    for (char c : str) {
        if (isalpha(c)) {
            letterCount[c]++;
        }
    }
    for (auto const& [letter, count] : letterCount) {
        cout << letter << ": " << count << endl;
    }
}

int countPlayersWithRank(std::map<std::string, int>& playerRanks, int targetRank) {
    int count = 0;
    for (auto const& [player, rank] : playerRanks) {
        if (rank >= targetRank) {
            count++;
        }
    }
    return count;
}

int main() {
    string str = "Hello, world!";
    countLetters(str);



    std::map<std::string, int> playerRanks = {
        {"player1", 5},
        {"player2", 10},
        {"player3", 20},
        {"player4", 15}
    };

    int targetRank = 15;
    int numPlayersWithRank = countPlayersWithRank(playerRanks, targetRank);

    std::cout << "Number of players with rank " << targetRank << " or higher: " << numPlayersWithRank << std::endl;
    return 0;
}