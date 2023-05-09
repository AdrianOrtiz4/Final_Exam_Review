#include <stack>
#include <map>
#include <set>
#include <vector>
#include <functional>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Collections
{
public:

    static void removeElement(stack<int> &s, int element);
    static map<string, int> countOccurrences(vector<string> const &v);
    static set<int> makeUnion(set<int> const &s1, set<int> const &s2);
    static void filter(vector<int> &v, function<bool(int)> f);
    static function<double(double)> generatePolynomial(vector<double> coefficients);
    


    static void print(stack<int> s) {
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }

    static void printMap(map<string, int> m) {
        for (auto it = m.begin(); it != m.end(); it++) {
            cout << "Element: " << it->first << ", " << "Times Found: " << it->second << endl;
        }
    }

    template<class Iterable>
    static void print(Iterable i) {
        for (auto it = i.begin(); it != i.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
};


// Given a stack of integers, write a method that removes every occurrence of a given element.
void Collections::removeElement(stack<int> &s, int element) {
    stack<int> tempStack; // create a temporary stack to store elements that are not equal to the giveen element

    while (!s.empty()) { // loop over the original stack until it is empty
        int curr = s.top(); // get the top element of the original stack
        s.pop(); // remove the top element of the original stack

        if (curr != element) { // if the current element is not equal to the given element
            tempStack.push(curr); // add it to the temporary stack
        }
    }
    while (!tempStack.empty()) { // loop over the temporary stack until it is empty
    
        int curr = tempStack.top(); // get the top element of the temporary stack
        tempStack.pop(); // remove the top element of the temporary stack
        s.push(curr); // add it back to the original stack
    }
}


// Given a vector of strings, return a map of strings to integers where the key is the element and the value 
// is the number of occurrences of the element in the vector.
map<string, int> Collections::countOccurrences(vector<string> const &v) {
    map<string, int> counts; // create an empty map to store the counts of each string

    for (string const &s : v) { // loop over each string in the input vector by reference
        ++counts[s]; // increment the count associated with the current string
    }
    return counts; // return the map containing the counts
}


// Given 2 sets of integers, return a set of integers that is the union of the 2 sets.
set<int> Collections::makeUnion(set<int> const &s1, set<int> const &s2) {
    set<int> unionSet;
    
    unionSet.insert(s1.begin(), s1.end()); // add all elements of s1 to the union set
    unionSet.insert(s2.begin(), s2.end()); // add all elements of s2 to the union set (duplicate elements are automatically discarded)
    return unionSet; // return the union set
}
// Given a vector of integers and a function, filter the vector by the function.
// Remove all elements that return false when passed into the function.
void Collections::filter(vector<int> &v, function<bool(int)> f) {
    int i = 0, j = 0; // i is the index of the first element that should be removed, j is the index of the element being checked
    while (j < v.size()) { // loop over the vector

        if (f(v[j])) { // if the current element satisfies the condition in the function
            v[i++] = v[j]; // move it to the left end of the vector (i.e., don't remove it)
        }
        j++; // move to the next element
    }
    v.erase(v.begin() + i, v.end()); // remove all elements starting from the i-th index to the end of the vector
}


function<double(double)> generatePolynomial(vector<double> coefficients) {
     return [=] (double x) {
        double result = 0.0;
        for (int i = 0; i < coefficients.size(); i++) {
            result += coefficients[i] * pow(x, coefficients.size() - i - 1); //NI idea ChatGPT lo hizo despues de mil intentos
        }
        return result;
    };
}



int main(){
    // TODO: Add test cases
    cout <<"=========== Question 1 Tester ===========" << endl;
    stack<int> s;
    for (int i = 1; i <= 10; i++) {
        s.push(i);
    }
    s.push(5);

    cout << "Stack: ";
    Collections::print(s);
    cout << "Removing element 5" << endl;
    Collections::removeElement(s, 5);
    cout << "Stack: ";
    Collections::print(s);
    
    cout <<"=========== Question 2 Tester ===========" << endl;
    vector<string> v1 = {"CIIC", "ICOM",  "CIIC", "INEL", "INEL", "INEL", "ICOM", "ININ"};
    cout << "Vector v1: ";
    Collections::print(v1);

    cout << "Counting occurrences of each element in v1" << endl;
    map<string, int> m1 = Collections::countOccurrences(v1);
    Collections::printMap(m1);

    cout <<"=========== Question 3 Tester ===========" << endl;
    set<int> s1 = { 1, 2, 3, 4, 5 };
    set<int> s2 = { 3, 4, 5, 6, 7 };

    cout << "Set s1: ";
    Collections::print(s1);
    cout << "Set s2: ";
    Collections::print(s2);

    cout << "Union of s1 and s2: ";
    set<int> s4 = Collections::makeUnion(s1, s2);
    Collections::print(s4);

    cout <<"=========== Question 4 Tester ===========" << endl;
    vector<int> myElements{1,2,3,4,5,6,7,8,9,10};
    cout << "Before Filter: ";
    Collections::print(myElements);
    Collections::filter(myElements, [](int x){return x < 5;});
    cout << "After Filter: ";
    Collections::print(myElements);

    cout <<"=========== Question 5 Tester ===========" << endl;
    vector<double> coefficients{2.0, -4.3, 0, 7};
    cout << "coefficient List: " << endl;
    Collections::print(coefficients);
    function<double(double)> f = generatePolynomial(coefficients);
    cout << "f(5) = " << f(5) << endl; 
}