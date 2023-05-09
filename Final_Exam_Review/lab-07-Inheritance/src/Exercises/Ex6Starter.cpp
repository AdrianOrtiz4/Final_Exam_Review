#include "StarterCode.hpp"

/* Collectable Interface */
class Collectable{
public:
  virtual int getCentury() = 0;

  virtual bool isSuccessful() = 0;

  virtual bool isLegit() = 0;
};

/* Exercise 6A
 * YOU MUST CHANGE THIS BELOW WITH YOUR CURRENT PAINTING CLASS
 * AND IMPLEMENT THE COLLECTABLE METHODS IN PAINTING AFTER THE
 * INHERITING
 */
class Painting : public Art, public Collectable{
private:
  bool replica;

public:
  // Null Constructor
  Painting(){};

  // Parameterized Constructor
  Painting(string name, Artist artist, Style style, int year, bool replica) : Art(name, artist, style, year)
  {

    this->replica = replica;
  }

  // Getters
  int getCentury() { return (year / 100) + 1; }

  bool isReplica() const { return replica; }

  bool isLegit(){
    if (!isReplica()){
      return true;
    }
    return false;
  }
  bool isSuccessful(){
    if (getArtist().getFameScore() > 7 && this->year >= getStyle().getDominantEra().first && this->year <= getStyle().getDominantEra().second){
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
  static int countPaintings(const vector<Painting *> &collection, Style style, int start, int end);
};

/* Exercise 6B
 * YOU MUST CHANGE THIS BELOW WITH YOUR CURRENT SCULPTURE CLASS
 * AND IMPLEMENT THE COLLECTABLE METHODS IN SCULPTURE AFTER THE
 * INHERITING
 */
class Sculpture : public Art, public Collectable{
private:
  Material material;

public:
  // Null Constructor
  Sculpture(){};

  // Parameterized Constructor
  Sculpture(string name, Artist artist, Style style, int year, Material material) : Art(name, artist, style, year){
    this->material = material;
  }

  // Getters
  int getCentury() { return (year / 100) + 1; }

  bool isSuccessful(){
    if (getArtist().getFameScore() > 5 && this->year >= getStyle().getDominantEra().first && this->year <= getStyle().getDominantEra().second){
      return true;
    }

    return false;
  }
  bool isLegit(){
    if (getMaterial() == MARBLE || getMaterial() == WAX || getMaterial() == METAL){
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
  static vector<Sculpture *> segregateSculptures(const vector<Art *> &collection);
};