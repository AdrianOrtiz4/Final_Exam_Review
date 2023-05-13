#include <iostream>
#include <vector>

using namespace std;

void removeTargetStringRecursiveHelper(vector<string>& v, const string& target, int index) {
    if (index >= v.size()) {
        return;
    }

    if (v[index] == target) {
        v.erase(v.begin() + index);
        removeTargetStringRecursiveHelper(v, target, index);
    } else {
        removeTargetStringRecursiveHelper(v, target, index + 1);
    }
}

void removeTargetStringRecursive(vector<string>& v, const string& target) {
    removeTargetStringRecursiveHelper(v, target, 0);
}
