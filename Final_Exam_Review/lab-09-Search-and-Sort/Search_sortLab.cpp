#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Book {
    private:
        string name;
        string author;
        int yearPublished;
        int numberOfPages;
        int id;

    public:
        Book(int id, string name, string author, int yearPublished, int numberOfPages) {
            this->id = id;
            this->name = name;
            this->author = author;
            this->yearPublished = yearPublished;
            this->numberOfPages = numberOfPages;
        }

        string getName() {
            return name;
        }

        string getAuthor() {
            return author;
        }

        int getYearPublished() {
            return yearPublished;
        }

        int getId() {
            return id;
        }

        int getNumberOfPages() {
            return numberOfPages;
        }

        void toString() {
            cout << "Book [name=" << name << ", author=" << author << ", yearPublished=" << yearPublished << ", numberofPages=" << numberOfPages << ", id="
            << id << "]" << endl;
        }

        /*
         * Compares the target book with b to determine order and returns:
		 * positive number:  if target > b
		 * 0: if they're equal
		 * negative number: if target < b
         */
        int compareTo(Book book) {
            return this->getId() - book.getId();
        }

        /*
         * Compares the target book with the parameter obj to determine if they are the same object.
         */
        bool equals(Book obj) {
            return this->getId() == obj.getId() && this->getName().compare(obj.getName()) == 0 && this->getAuthor().compare(obj.getAuthor()) == 0 && this->yearPublished == obj.getYearPublished()
            && this->getNumberOfPages() == obj.getNumberOfPages();
        }
};

class BookComparator{
    public:
        int operator()(Book a, Book b) {
            if(a.getId() != b.getId()) return a.getId() - (b.getId());
            return 0; // TEMP RETURN
    }
};

class Library {
    private:
        vector<Book> bookshelf;

    public:
        Library(vector<Book> bookshelf) {
            this->bookshelf = bookshelf;
        }

        vector<Book> getBookshelf() {
            return bookshelf;
        }

        /*
        * Helper method to swap the position of two objects in a given array
        *
        * @param bookshelf - vector we're going to work in
        * @param a - index of the first object to swap
        * @param b - index of the second object to swap
        */
        static void swap(vector<Book> &v, int a, int b){
            iter_swap(v.begin() + a, v.begin() + b);
        }

        /*
         * Linear Algorithm to find the index of a given target.
         *
         * @param bookshelf - Array where search takes place
         * @param target - Book to be searched for
         * @return Index of the target book (-1 if not found)
         */
        int interativeLinearSearch(vector<Book> bookshelf, Book target){
            for (int i = 0; i < bookshelf.size(); ++i) {
                if(bookshelf[i].equals(target)) return i; // Book was found
            }
            return -1; // Book was not found
        }

        /*
         * Linear Algorithm to find the index of a given target.
         * Iterates though the whole array having a complexity of O<img class="icon emoticon" alt="No" title="No" src="https://online.upr.edu/theme/image.php/fordson/core/1680272937/s/no" /> in the worst case scenario
         *
         * @param bookshelf - Target array
         * @param target - Target object
         * @return - Index of the target book (-1 if not found)
         */
        int recursiveLinearSearch(vector<Book> bookshelf, Book target) {
            return linearHelper(bookshelf,0, target); // Start at the beginning of the vector, index 0
        }

        /*
         * Linear search helper
         *
         * @param bookshelf -  Vector where the search takes place
         * @param index - Index of the current object we are comparing the target with
         * @param target - Book to be searched for
         * @return Index of what was found (-1 if not found)
         */
        int linearHelper(vector<Book>, int index, Book target) {
            if(index >= bookshelf.size()) return -1; // Book was never found, exiting recursion
            if(target.equals(bookshelf[index])) return index; // Book was found
            return linearHelper(bookshelf, index+1, target); // Increase index to "iterate" through the vector
        }

        /*
         * EXERCISE A(20 pts):
  
         * Binary Algorithm to find the index of a given target. Requires array to be sorted.
         * Divides the array in half and only checks for the half containing the value while discarding the rest.
         * The value is either the middle of the sub-array or in one of the two halves.
         *
         * By divding the vector in half each iteration, the complexity is at the most O(log<img class="icon emoticon" alt="No" title="No" src="https://online.upr.edu/theme/image.php/fordson/core/1680272937/s/no" />)
         * which beats the linear search at O<img class="icon emoticon" alt="No" title="No" src="https://online.upr.edu/theme/image.php/fordson/core/1680272937/s/no" />
         *
         * @param bookshelf = Target vector
         * @param target - Target Element
         * @return - Index of Target Element (-1 if not found)
         */
int Library::binarySearch(vector<Book> bookshelf, Book target) {
 
    return binarySearchHelper(bookshelf, target, 0, bookshelf.size() - 1); // TEMP RETURN
}

/*
 * Helper method for Binary Search
*/
int Library::binarySearchHelper(vector<Book> bookshelf, Book target, int left, int right) {
    if(right >= left){
        int mid = left + (right - left)/2;
        if(bookshelf[mid].compareTo(target) == 0){
            return mid;
        }
        if(bookshelf[mid].compareTo(target) > 0){
            return binarySearchHelper(bookshelf,target,left,mid -1);
        }
        else{
            return binarySearchHelper(bookshelf,target,mid + 1,right);
        }
        
    }
    return -1;
  
}
        /*
         * EXERCISE B(20 points):
  
         * Implement a iterative Bubble Sort for a vector books
         *
         * @param bookshelf - Vector to be sorted
         * @return A sorted copy fo the bookshelf array
         */
vector<Book> Library::bubbleSort(vector<Book> bookshelf) {
    vector<Book> unsortedBookshelf = bookshelf;
    // bool swap = true;
    for(int i = 0; i < unsortedBookshelf.size(); i++){
        for(int j = 0; j < unsortedBookshelf.size()-i-1;j++ ){
            if(unsortedBookshelf[j].compareTo(unsortedBookshelf[j +1]) > 0 ){
                swap(unsortedBookshelf,j,j +1);
                
            }
        }
    }
    
    // ADD YOUR CODE
    
    return unsortedBookshelf;
}
        /*
         * EXERCISE C(20 points):
  
         * Implement a recursive Insertion Sort for the vector of books using a helper method
         * HINT: USE A HELPER METHOD
         * @param bookshelf - Vector to be sorted
         * @return A sorted copy of the bookshelf vector
         */

vector<Book> Library::insertionSort(vector<Book> bookshelf) {
    return insertionSortHelper(bookshelf, 1);
}

vector<Book> Library::insertionSortHelper(vector<Book> bookshelf, int insertIndex) {
    
    if(insertIndex == bookshelf.size()){
        return bookshelf;
    }
    for(int i = insertIndex; i > 0;i--){
        if(bookshelf[i].getId() < bookshelf[i -1].getId()){
            swap(bookshelf,i,i-1);
        }
        else{
        break;}
        
    }
    
    return insertionSortHelper(bookshelf,insertIndex + 1);
}      /*
     *  Recursive Merge Sort for an array
     *
     *  @param bookshelf - vector to be sorted
     *  @param comp - comparator object to compare cars
     */
    static void mergeSort(BookComparator comp, vector<Book> &bookshelf) {
        int n = bookshelf.size();
        if(n < 2) return;
        int mid = n / 2;
        vector<Book> B1;
        vector<Book> B2;
        for(int i = 0; i < mid; i++) {
            B1.push_back(bookshelf[i]);
        }
        for(int i = mid; i < n; i++){
            B2.push_back(bookshelf[i]);
        }
        mergeSort(comp, B1);
        mergeSort(comp, B2);
        merge(comp, B1, B2, bookshelf);
    }

    /*
     * BONUS PROBLEM (10PTS): Finish the merge algorithm for the Merge Sort
     *
     * A helper method that distributes the items with a pivot and returns the index of where it stopped
     * @param bookshelf - array to be sorted
	 * @param B1 - left section of to be sorted
	 * @param B2 - right section to be sorted
	 * @param comp - comparator object to compare cars
	 * @return the index of the partition
     */
      void merge(BookComparator comp, vector<Book> &B1, vector<Book> &B2, vector<Book> &bookshelf){
        int s1index = 0;
        int s2index = 0;
        int bookshelfIndex = 0;
        while(s1index < B1.size() && s2index < B2.size()){
            Book c1 = B1[s1index++];
            Book c2 = B1[s2index++];
            
            if(comp(c1,c2) <= 0){
                bookshelf[bookshelfIndex++] = B1[s1index++];
                s1index++;
                
            }
            else{
                bookshelf[ bookshelfIndex++] = B2[s2index++];
                s2index++;
            }
         }
         while(s1index < B1.size()){
              bookshelf[bookshelfIndex++] = B1[s1index++];
               s1index++;
             
         }
         while(s2index < B2.size()){
              bookshelf[bookshelfIndex++] = B2[s2index++];
              s2index++;
        }
    }
    
  

};



void printShelf(vector<Book> bookshelf){
    for(int i = 0; i < bookshelf.size(); i++) {
        cout << bookshelf[i].getId() << endl;
    }
};

int main(){
    Book b0(0, "Somebody once told me", "Shrek", 2001, 1000);
    Book b1(1, "the world is gonna roll me", "Donkey", 2001, 1000);
    Book b2(2, "I ain't the sharpest tool in the shed", "Fiona", 2001, 1000);
    Book b3(3, "She was looking kind of dumb", "Puss in boots", 2001, 1000);
    Book b10(10, "So much to do, so much to see", "Princess Charming", 2001, 1000);
    Book b14(14, "Hey, now, you're an all-star, get your game on, go play", "Three Blind Mice", 2001, 1000);
    Book b15(15, "Hey, now, you're a rock star, get the show on, get paid", "Magic Mirror", 2001, 1000);
    Book b17(17, "And all that glitters is gold", "Cookie", 2001, 1000);
    vector<Book> sortedBookshelf = {b0,b1,b2,b3, b10,b14,b15,b17};
    
    int pos = Library::binarySearch(sortedBookshelf, Book(17, "And all that glitters is gold", "Cookie", 2001, 1000));
    cout << "BinarySearch looking for ID = 17, found at " << pos << endl;
    pos = Library::binarySearch(sortedBookshelf, Book(8, "Didn't make sense not to live for fun", "Lord Farquaad", 2001, 1000));
    cout << "BinarySearch looking for ID = 8, found at " << pos << endl;

    vector<Book> unsortedList1 = {  Book(0, "Somebody once told me", "Shrek", 2001, 1000),
                                    Book(14, "Hey, now, you're an all-star, get your game on, go play", "Sadly no Bee Movie reference", 2001, 1000),
                                    Book(1, "the world is gonna roll me", "Donkey", 2001, 1000),
                                    Book(3, "She was looking kind of dumb", "Puss in boots", 2001, 1000),
                                    Book(4, "with her finger and her thumb", "Dragon", 2001, 1000),
                                    Book(10, "So much to do, so much to see", "Princess Charming", 2001, 1000),
                                    Book(6, "Well, the years start coming and they don't stop coming", "Pinocchio", 2001, 1000),
                                    Book(7, "Fed to the rules and I hit the ground running", "Doris", 2001, 1000),
                                    Book(17, "And all that glitters is gold", "Cookie", 2001, 1000),
                                    Book(8, "Didn't make sense not to live for fun", "Lord Farquaad", 2001, 1000),
                                    Book(9, "Your brain gets smart but your head gets dumb", "Fairy Godmother", 2001, 1000),
                                    Book(11, "So what's wrong with taking the back streets?", "Captain Hook", 2001, 1000)};

    cout << "======================= Bubble Sort ===================" << endl;
    vector<Book> bookshelf2 = Library::bubbleSort(unsortedList1);
    printShelf(bookshelf2);
    cout << "======================= Insertion Sort ===================" << endl;
    vector<Book> bookshelf3 = Library::insertionSort(unsortedList1);
    printShelf(bookshelf3);
    cout << "======================= Merge Sort ===================" << endl;
    BookComparator comp;
    Library::mergeSort(comp, unsortedList1);
    printShelf(unsortedList1);

};
  
