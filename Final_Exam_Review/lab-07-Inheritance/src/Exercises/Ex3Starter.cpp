#include "StarterCode.hpp"

/* Exercise 3A
 * Override the method appraise in Painting by calling the super appraise
 * and determining the new price of the painting based on the following remarks:
 *
 * 1. If it is not a replica and its artist fame score is greater than 8,
 *    the price will be raised by 66%.
 * 2. If it is not a replica and its artist fame score is between 5 and 8 (inclusive),
 *    the price will be raised by 37%.
 * 3. If it is not a replica and its artist fame score is lower than 5,
 *    the price will be raised by 15%.
 * 4. If it is a replica the price will remain the same.
 *
 * Hint: Remember that if you want to override a method you must declare it first on the header file of the subclass.
 * */
int Painting::appraise() {
    if(!isReplica() && getArtist().getFameScore() > 8){
        return Art::appraise() *1.66;
    }
    if(!isReplica() && getArtist().getFameScore() >= 5 && getArtist().getFameScore() <= 8){
        return  Art::appraise() *1.37;
    }
    if(!isReplica() && getArtist().getFameScore() < 5){
        return  Art::appraise() *1.15;
    }
    return  Art::appraise();
    
}

/* Exercise 3B
 * Override the method appraise in Sculpture by calling the super appraise
 * and determining the new price of the painting based on the following remarks:
 *
 * 1. If its material is MARBLE and its artist fame score is greater or equal than 5,
 *    the price will be raised by 69%.
 * 2. If its material is METAL and its artist fame score is greater than 5,
 *    the price will be raised by 45%.
 * 3. If its material is NOT PLASTIC and its fame score is greater than 3,
 *    the price will be raised by 12%.
 * 4. Else the price will remain the same.
 *
 * Hint: Remember that if you want to override a method you must declare it first on the header file of the subclass.
 */
int Sculpture::appraise() {
    if(getMaterial() == MARBLE && getArtist().getFameScore() >= 5){
        return Art::appraise() * 1.69;
    }
    if(getMaterial() == METAL && getArtist().getFameScore() > 5){
        return Art::appraise() * 1.45;
    }
    if(getMaterial() != PLASTIC && getArtist().getFameScore() > 3){
        return Art::appraise() * 1.12;
    }
    return Art::appraise();
    
   