#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

enum Suit {
    CLUBS = 0,
    DIAMONDS,
    HEARTS,
    SPADES
};

enum Rank {
    TWO = 2,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    A,
    JOKER
};

class Card {

  private:
    Suit suit;
    Rank rank;

  public:
    Card(Rank r, Suit s) {
        suit = s;
        rank = r;
    }

    Card(const Card &c2){
        suit = c2.getSuit();
        rank = c2.getRank();
    }

    Suit getSuit() const { return suit; }
    Rank getRank() const { return rank; }

    bool equals(const Card &c2) const { return this->getSuit() == c2.getSuit() && this->getRank() == c2.getRank(); }

    string toString(Rank r) const {
        switch (r) {
        case JACK:
            return "J";
        case QUEEN:
            return "Q";
        case KING:
            return "K";
        case A:
            return "A";
        case JOKER:
            return "JOKER";
        default:
            return to_string(r);
        }
    }

    string toString(Suit s) const {
        switch (s) {
        case CLUBS:
            return "C";
        case DIAMONDS:
            return "D";
        case HEARTS:
            return "H";
        case SPADES:
            return "S";
        }
    }

    string toString() const {
        return ("Card[" + toString(this->getRank()) + "," + toString(this->getSuit()) + "]");
    }

    template <class Iterable>
    static string toString(const Iterable &deck) {
        string result = "[";
        for_each(deck.begin(), deck.end(), [&result](Card c) { result += c.toString() + ","; });
        if (result.size() > 1) result.pop_back();
        result += "]";
        return result;
    }

    bool operator<(const Card &c2) const;
    bool sameRankAs(const Card &c2) const;
    bool sameRank(const vector<Card> &deck) const;
    static Card maxRankCard(const vector<Card> &deck);
    static vector<Card> sortBySuit(const vector<Card> &deck);
    static bool isFourOfAKind(const vector<Card> &hand);
    int countRankLargerThan(const vector<Card> &deck) const;
    static set<Card> getIntersection(const set<Card> &deck1, const set<Card> &deck2);
    static vector<Card> allOfSuit(const vector<Card> &, Suit s);
};

bool Card::operator<(const Card &c2) const {
    return this->getSuit() < c2.getSuit() || (this->getSuit() == c2.getSuit() && this->getRank() < c2.getRank());
}

/** 
 * EXERCISE 1
 * Returns true if and only if Card c2 has the same rank as the target Card.
 */
bool Card::sameRankAs(const Card &c2) const {
     return this->getRank() == c2.getRank();
    // YOUR CODE HERE
}

/** 
 * EXERCISE 2
 * Returns true if and only if ALL the Card's in the given deck have the same
 * rank as the target Card. Returns true if deck is empty.
 */
bool Card::sameRank(const vector<Card> &deck) const {
    
    for(int i = 0; i < deck.size(); i++){
        if( this->getRank() != deck[i].getRank()){
            return false;
        }
    }

    return true; // Dummy return 
}

/** 
 * EXERCISE 3
 * Returns the Card with the maximum rank within the given deck.
 * If the deck is empty returns a Joker of spades Card(JOKER, SPADES)
 */
Card Card::maxRankCard(const vector<Card> &deck) {
    if(deck.empty()){
        return Card(JOKER, SPADES);
    }
    auto max = deck[0];
     for(int i = 1; i < deck.size(); i++){
        if(deck[i].getRank() > max.getRank()){
            max = deck[i];
        }

     }

    // YOUR CODE HERE

    return max; // Dummy return 

}

/** 
 * EXERCISE 4
 * Returns a new deck with all the Card's in the parameter deck
 * sorted ascendingly by suit. Assume the ascending order among the
 * Suit's is as follows:  CLUBS < DIAMONDS < HEARTS < SPADES
 * 
 * REQUIREMENT: YOU MUST USE the sort function from algorithm.h WITH A
 * LAMDA EXPRESSION TO GET ANY CREDIT.
 */
vector<Card> Card::sortBySuit(const vector<Card> &deck) {
    // Use std::sort to sort the deck by suit
    auto cmp = [](const Card &c1, const Card &c2) {
        return c1.getSuit() < c2.getSuit();
    };
    vector<Card> sortedDeck = deck;
    std::sort(sortedDeck.begin(), sortedDeck.end(), cmp);

    return sortedDeck;

}

/** 
 * EXERCISE 5
 * Returns true if and only if the given hand of five cards has a Four-Of-A-Kind.
 * A Four-Of-A-Kind includes four cards of the same rank and another card of any other rank
 * IN ANY ORDER.  If the hand does not contain 5 cards returns false.
 * 
 * REQUIREMENT: YOU MUST USE a map CONTAINER TO COUNT THE CARDS OF EACH RANK TO GET ANY CREDIT.
 *
 */
bool Card::isFourOfAKind(const vector<Card>& hand) {
    if (hand.size() != 5) {
        return false;
    }

    map<Rank, int> rankCount;
    for (const Card& card : hand) {
        rankCount[card.getRank()]++;
    }

    bool foundFourOfAKind = false;
    for (const auto& [rank, count] : rankCount) {
        if (count == 4) {
            foundFourOfAKind = true;
        } else if (count != 1) {
            // If there is any rank with count different from 1 or 4, it cannot be a Four-Of-A-Kind.
            return false;
        }
    }

    return foundFourOfAKind;
}


/** 
 * EXERCISE 6
 * Returns the count of Card's in the given deck with rank larger than
 * the Rank of the targed Card.
 * 
 * REQUIREMENT: MUST USE count_if from algorithm.h with LAMBDA expression for ANY credit
 */
int Card::countRankLargerThan(const vector<Card>& deck) const {
    int count = count_if(deck.begin(), deck.end(), [this](const Card& c) {
        return c.getRank() > this->getRank();
    });
    return count;
}

/** 
 * EXERCISE 7
 * Returns a new deck as a Set representing the intersection of two given decks (sets).
 * The intersecton of two sets includes those elements who appear in BOTH sets.
 */
set<Card> getIntersection(const set<Card> &deck1, const set<Card> &deck2) {
    set<Card> intersection;
    set_intersection(deck1.begin(), deck1.end(), deck2.begin(), deck2.end(),
                     inserter(intersection, intersection.begin()));
    return intersection;
}


/** 
 * Exercise 8
 * Returns a new vector<Card> containing all the Card's in the given deck
 * that have the given Suit. Should return an empty vector if not such Card's
 * exist.
 * 
 * REQUIREMENT: MUST BE RECURSIVE
 */


vector<Card> allOfSuitHelper(const vector<Card>& deck, Suit s, vector<Card> newDeck, int index) {
    if (index >= deck.size()) {
        return newDeck;
    }
    if (deck[index].getSuit() == s) {
        newDeck.push_back(deck[index]);
    }
    return allOfSuitHelper(deck, s, newDeck, index + 1);
}

vector<Card> Card::allOfSuit(const vector<Card> &deck, Suit s) {
    vector<Card> newDeck;
    return allOfSuitHelper(deck, s, newDeck, 0);
}


int main() {
    cout << boolalpha;
    cout << "------Final Exam Tester------" << endl;

    Card c1(THREE, CLUBS);
    Card c2(A, HEARTS);
    Card c3(TWO, DIAMONDS);
    Card c4(NINE, SPADES);
    Card c5(THREE, HEARTS);
    Card c6(SIX, DIAMONDS);
    Card c7(SEVEN, CLUBS);
    Card c8(EIGHT, SPADES);
    Card c9(NINE, SPADES);
    Card c10(JOKER, CLUBS);
    Card c11(JACK, DIAMONDS);
    Card c12(THREE, HEARTS);
    Card c13(TEN, SPADES);
    Card c14(QUEEN, CLUBS);
    Card c15(KING, CLUBS);
    Card c16(THREE, HEARTS);
    Card c17(FOUR, DIAMONDS);
    Card c18(THREE, SPADES);

    vector<Card> deck1{c1, c2, c3, c4, c5, c6};
    vector<Card> deck2{c7, c5, c2, c4, c17, c18};
    vector<Card> deck3{c4, c5, c9};
    vector<Card> deck4{c14, c15, c16};
    vector<Card> deck5{c1, c12, c18};
    vector<Card> deck6{c4, c9, c18};
    vector<Card> deck7{c4, c9};
    vector<Card> deck8{c1, c12, c18, c16};
    vector<Card> deck9{c1, c12, c18, c15, c16};
    vector<Card> deck10{c1, c12, c4, c18, c16};
    vector<Card> foak1{Card(FOUR, SPADES), Card(FOUR, SPADES), Card(FOUR, SPADES), Card(FOUR, SPADES)};
    vector<Card> foak2{Card(TWO, HEARTS), Card(A, SPADES), Card(A, HEARTS), Card(A, CLUBS), Card(A, DIAMONDS)};
    vector<Card> foak3{Card(A, SPADES), Card(A, HEARTS), Card(TWO, HEARTS), Card(A, CLUBS), Card(A, DIAMONDS)};
    vector<Card> foak4{Card(A, SPADES), Card(A, HEARTS), Card(A, CLUBS), Card(A, DIAMONDS), Card(TWO, HEARTS)};
    vector<Card> foak5{Card(A, SPADES), Card(A, HEARTS), Card(A, CLUBS), Card(A, DIAMONDS), Card(A, HEARTS)};
    vector<Card> foak6{Card(FOUR, SPADES), Card(A, SPADES)};
    vector<Card> emptyDeck{};

    set<Card> deckSet1{c1, c2, c3, c4, c5, c6};
    set<Card> deckSet2{c7, c5, c2, c4, c17, c18};
    set<Card> deckSet3{c4, c5, c9};
    set<Card> deckSet4{c14, c15, c16, c18};
    set<Card> deckSetEmpty{};

    cout << "------EX 1------" << endl;
    cout << c1.sameRankAs(c1) << endl;
    cout << c1.sameRankAs(c2) << endl;
    cout << c2.sameRankAs(c1) << endl;
    cout << c1.sameRankAs(c12) << endl;
    cout << c12.sameRankAs(c1) << endl;

    // Expected:
    // ------EX 1------
    // true
    // false
    // false
    // true
    // true
    //

    cout << endl;

    cout << "------EX 2------" << endl;
    cout << c16.sameRank(deck1) << endl;
    cout << c18.sameRank(deck5) << endl;
    cout << c16.sameRank(deck6) << endl;
    cout << c16.sameRank(emptyDeck) << endl;
    cout << endl;

    //
    // Expected:
    // ------EX 2------
    // false
    // true
    // false
    // true
    //

    cout << endl;

    cout << "------EX 3------" << endl;
    cout << Card::maxRankCard(deck1).toString() << endl;
    cout << Card::maxRankCard(deck2).toString() << endl;
    cout << Card::maxRankCard(deck3).toString() << endl;
    cout << Card::maxRankCard(emptyDeck).toString() << endl;
    cout << endl;

    //
    // Expected:
    // ------EX 3------
    // Card[A,H]
    // Card[A,H]
    // Card[9,S]
    // Card[JOKER,S]
    //

    cout << "------EX 4------" << endl;
    cout << Card::toString(Card::sortBySuit(deck1)) << endl;
    cout << Card::toString(Card::sortBySuit(deck5)) << endl;
    cout << Card::toString(Card::sortBySuit(emptyDeck)) << endl;
    cout << endl;

    //
    // Expected:
    // ------EX 4------
    // [Card[3,C],Card[2,D],Card[6,D],Card[A,H],Card[3,H],Card[9,S]]
    // [Card[3,C],Card[3,H],Card[3,S]]
    // []
    //

    cout << "------EX 5------" << endl;
    cout << Card::isFourOfAKind(deck1) << endl;
    cout << Card::isFourOfAKind(foak1) << endl;
    cout << Card::isFourOfAKind(foak2) << endl;
    cout << Card::isFourOfAKind(foak3) << endl;
    cout << Card::isFourOfAKind(foak4) << endl;
    cout << Card::isFourOfAKind(foak5) << endl;
    cout << Card::isFourOfAKind(foak6) << endl;
    cout << endl;

    //
    // Expected:
    // ------EX 5------
    // false
    // false
    // true
    // true
    // true
    // false
    // false
    //

    cout << "------EX 6------" << endl;
    cout << c1.countRankLargerThan(deck4) << endl;
    cout << c4.countRankLargerThan(deck3) << endl;
    cout << c2.countRankLargerThan(deck5) << endl;
    cout << c1.countRankLargerThan(deck1) << endl;
    cout << endl;

    //
    // Expected:
    // ------EX 6------
    // 2
    // 0
    // 0
    // 3
    //

    cout << "------EX 7------" << endl;
    cout << Card::toString(getIntersection(deckSet1, deckSet1)) << endl;
    cout << Card::toString(getIntersection(deckSet1, deckSet2)) << endl;
    cout << Card::toString(getIntersection(deckSet2, deckSet1)) << endl;
    cout << Card::toString(getIntersection(deckSet1, deckSet4)) << endl;
    cout << Card::toString(getIntersection(deckSetEmpty, deckSet1)) << endl;
    cout << Card::toString(getIntersection(deckSet1, deckSetEmpty)) << endl;
    cout << Card::toString(getIntersection(deckSetEmpty, deckSetEmpty)) << endl;
    cout << endl;

    //
    // Expected:
    // [Card[3,C],Card[2,D],Card[6,D],Card[3,H],Card[A,H],Card[9,S]]
    // [Card[3,H],Card[A,H],Card[9,S]]
    // [Card[3,H],Card[A,H],Card[9,S]]
    // [Card[3,H]]
    // []
    // []
    // []
    //

    cout << "------EX 8------" << endl;
    cout << "SPADES Cards: " << Card::toString(Card::allOfSuit(deck1, SPADES)) << endl;
    cout << "DIAMONDS Cards: " << Card::toString(Card::allOfSuit(deck1, DIAMONDS)) << endl;
    cout << "HEARTS Cards: " << Card::toString(Card::allOfSuit(deck1, HEARTS)) << endl;
    cout << "CLUBS Cards: " << Card::toString(Card::allOfSuit(deck4, CLUBS)) << endl;
    cout << endl;

    //
    // Expected:
    // ------EX 8------
    // SPADES Cards: [Card[9,S]]
    // DIAMONDS Cards: [Card[2,D],Card[6,D]]
    // HEARTS Cards: [Card[A,H],Card[3,H]]
    // CLUBS Cards: [Card[Q,C],Card[K,C]]
    //
}

