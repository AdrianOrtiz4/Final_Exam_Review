#include <iostream>
#include <string>
#include <vector>

using namespace std;

//////////////////////////////////////////////////////////////////////////
///////////////////////////*Helper Classes*///////////////////////////////
//////////////////////////////////////////////////////////////////////////

/* Collectable Interface */
class Collectable {
  public:
    virtual int getCentury() = 0;

    virtual bool isSuccessful() = 0;

    virtual bool isLegit() = 0;
};

/* Style Class*/
class Style {
  private:
    string name;
    pair<int, int> dominantEra;

  public:
    // Null Constructor
    Style(){};

    // Parameterized Constructor
    Style(string name, int startOfEra, int endOfEra) {
        this->name = name;
        dominantEra = {startOfEra, endOfEra};
    }

    // Getters
    string getName() const { return this->name; }
    pair<int, int> getDominantEra() const { return this->dominantEra; }

    // Methods
    bool equals(Style style) const {
        return this->getName().compare(style.getName()) == 0;
    }
};

/* Artist Class */
class Artist {
  private:
    string name;
    bool deceased;
    int fameScore; // This Score goes on a scale from 0 to 10
    Style primaryStyle;

  public:
    // Null Constructor
    Artist(){};

    // Parameterized Constructor
    Artist(string name, bool deceased, int fameScore, Style primaryStyle) {
        this->name = name;
        this->deceased = deceased;
        this->fameScore = fameScore;
        this->primaryStyle = primaryStyle;
    }

    // Getters
    string getName() const { return name; }
    bool isDeceased() const { return deceased; }
    int getFameScore() const { return fameScore; }
    Style getPrimaryStyle() const { return primaryStyle; }

    // Setters
    void setName(string name) { this->name = name; }
    void setDeceased(bool deceased) { this->deceased = deceased; }
    void setFameScore(int fameScore) { this->fameScore = fameScore; }
    void setPrimaryStyle(Style style) { this->primaryStyle = style; }

    // Methods
    void printArtist() {
        cout << boolalpha;
        cout << "[ Name: " << this->getName() << ", Fame Score: " << this->getFameScore() << ", Primarly Style: " << this->getPrimaryStyle().getName() << ", Is Deceased: " << this->isDeceased() << " ]" << endl;
    }
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////*Art Class*/////////////////////////////////
//////////////////////////////////////////////////////////////////////////
class Art {
  protected:
    string name;
    Artist artist;
    Style style;
    int year;

  public:
    // Null Constructor
    Art(){};

    // Parameterized Constructor
    Art(string name, Artist artist, Style style, int year) {
        this->name = name;
        this->artist = artist;
        this->style = style;
        this->year = year;
    }

    // Getters
    string getName() const { return name; }
    Artist getArtist() const { return artist; }
    Style getStyle() const { return style; }
    int getYear() const { return year; }

    // Setters
    void setName(string name) { this->name = name; }
    void setArtist(Artist artist) { this->artist = artist; }
    void setStyle(Style style) { this->style = style; }
    void setYear(int year) { this->year = year; }

    // Methods
    virtual int appraise() { return 1500; }

    /*
     * Given a vector of Art pieces, return a vector containing only the
     * pieces that are of the given Style
     */
    static vector<Art *> filterCollectionByStyle(const vector<Art *> &personalCollection, Style selected);
};

//////////////////////////////////////////////////////////////////////////
///////////////////////////*Painting Class*///////////////////////////////
//////////////////////////////////////////////////////////////////////////
class Painting: public Art, public Collectable{
  private:
    bool replica;

  public:
    // Null Constructor
    Painting(){};

    // Parameterized Constructor
    Painting(string name, Artist artist, Style style, int year, bool replica): Art(name,  artist, style, year) {
 
        this->replica = replica;
    }

    // Getters
    int getCentury(){return (year/100) +1;}
    
    bool isReplica() const { return replica;}
 
 
    
    bool isLegit(){
        if(!isReplica()){
        return true;
    }
    return false;
    }

    // Setters
    void setReplica(bool isReplica) { this->replica = isReplica; }

    // Methods
    /*
     * Given a vector of Paintings, return the count of how many paintings
     * qualify with the given style and its year is between the given start
     * and end (inclusive).
     */
    int appraise();
    static int countPaintings(const vector<Painting *> &collection, Style style, int start, int end);
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////*Sculpture Class*///////////////////////////////
//////////////////////////////////////////////////////////////////////////
enum Material {
    WOOD,
    MARBLE,
    WAX,
    PLASTIC,
    METAL
};

class Sculpture: public Art, public Collectable{
  private:
    Material material;

  public:
    // Null Constructor
    Sculpture(){};

    // Parameterized Constructor
    Sculpture(string name, Artist artist, Style style, int year, Material material):  Art(name, artist,style, year)  {
        this->material = material;
    }

    // Getters
    int getCentury(){return (year/100) +1;}
    bool isSuccessful(){
        if(getArtist().getFameScore() > 5 && this->year >= getStyle().getDominantEra().first && this->year <=  getStyle().getDominantEra().second){
            return true;
        }
        
        return false;
        
    }
    bool isLegit(){
        if(getMaterial() == MARBLE || getMaterial() == WAX ||getMaterial() == METAL ){
            return true;
        }
        return false;
    }
    Material getMaterial() const { return material; }

    // Setters
    void setMaterial(Material material) { this->material = material; }

    // Methods
    /*
     * Given a vector of Art pieces, return a vector containing only the
     * Sculptures in the original vector. You must use dynamic casting to
     * determine whether an Art piece is a Sculpture or not .
     */
    int appraise();
    static vector<Sculpture *> segregateSculptures(const vector<Art *> &collection);
};