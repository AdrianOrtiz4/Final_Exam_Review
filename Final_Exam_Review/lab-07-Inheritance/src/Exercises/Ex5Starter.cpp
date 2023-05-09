#include "StarterCode.hpp"

/* Exercise 5
 * Given a vector of Art pieces, return a vector containing only the
 * Sculptures in the original vector. You must use dynamic casting to
 * determine whether an Art piece is a Sculpture or not .
 */
vector<Sculpture *> Sculpture::segregateSculptures(const vector<Art *> &collection){
    vector<Sculpture *> sculptures;
    for (Art *artwork : collection){
        Sculpture *sculpture = dynamic_cast<Sculpture *>(artwork);
        if (sculpture != nullptr) {
            sculptures.push_back(sculpture);
        }
    }
    return sculptures;
}