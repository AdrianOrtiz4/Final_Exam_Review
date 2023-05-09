#include "StarterCode.hpp"

using namespace std;

int main() {
    // Styles
    Style cubism("Cubism", 1910, 1920);
    Style realism("Realism", 1700, 1810);
    Style abstract("Abstract", 1900, 2010);
    Style trippy("Trippy", 1870, 2020);
    Style renaissance("Renaissance", 1300, 1600);

    // Trippy Artists
    Artist vincent("Vincent van Gogh", true, 10, trippy);
    Artist joe("Joe Martin", false, 9, trippy);
    Artist carla("Carla Mitchell", false, 2, trippy);

    // Realism Artists
    Artist pepe("Pepe Cruz", false, 6, realism);
    Artist josefa("Josefa", false, 4, realism);
    Artist gustave("Gustave Courbet", true, 10, realism);

    // Cubism Artists
    Artist alex("Alexandro Riverini", true, 10, cubism);
    Artist rudolph("Rudolph Saint", true, 5, cubism);
    Artist paula("Paula A", false, 7, cubism);

    // Abstract Artists
    Artist pablo("Pablo Picasso", true, 10, abstract);
    Artist maria("Maria Pinta", false, 8, abstract);
    Artist sutano("Sutano Mengano", true, 1, cubism);

    // Renaissance Artists
    Artist leo("Leonardo Da Vinci", true, 10, renaissance);
    Artist michael("Michelangelo Buonarroti", true, 10, renaissance);

    // Paintings
    Painting *monaLisa = new Painting("Mona Lisa", leo, renaissance, 1503, false);
    Painting *belleza = new Painting("Belleza", maria, abstract, 2010, true);
    Painting *reloj = new Painting("Reloj", sutano, cubism, 1703, false);
    Painting *butterfly = new Painting("Butterfly", josefa, cubism, 1903, true);
    Painting *aquella = new Painting("Aquella", josefa, realism, 2003, true);
    Painting *flor = new Painting("Flor", paula, trippy, 2006, false);

    // Sculptures
    Sculpture *laPieta = new Sculpture("La Pietà", michael, cubism, 1499, Material::MARBLE);
    Sculpture *cosa = new Sculpture("Cosa", leo, realism, 1800, Material::WAX);
    Sculpture *hombre = new Sculpture("Hombre", joe, abstract, 2005, Material::METAL);
    Sculpture *truth = new Sculpture("Truth", sutano, trippy, 1870, Material::PLASTIC);
    Sculpture *inspiration = new Sculpture("Inspiration", rudolph, renaissance, 1600, Material::WOOD);

    vector<Art *> personalCollection;
    vector<Painting *> paintingCollection;

    cout << boolalpha << endl;
    cout << "************** Exercise 1 **************" << endl;
    // Art *art = dynamic_cast<Art *>(monaLisa);
    // cout << monaLisa->getName() << " is Art: " << (art != NULL) << endl;

    cout << "************** Exercise 2 **************" << endl;
    // Art *art2 = dynamic_cast<Art *>(laPieta);
    // cout << laPieta->getName() << " is Art: " << (art2 != NULL) << endl;

    cout << "************** Exercise 3A **************" << endl;
    // cout << butterfly->getName() << " appraise: " << butterfly->appraise() << endl;
    // cout << reloj->getName() << " appraise: " << reloj->appraise() << endl;
    // cout << flor->getName() << " appraise: " << flor->appraise() << endl;
    // cout << monaLisa->getName() << " appraise: " << monaLisa->appraise() << endl;

    cout << "************** Exercise 3B **************" << endl;
    // cout << truth->getName() << " appraise: " << truth->appraise() << endl;
    // cout << inspiration->getName() << " appraise: " << inspiration->appraise() << endl;
    // cout << hombre->getName() << " appraise: " << hombre->appraise() << endl;
    // cout << laPieta->getName() << " appraise: " << laPieta->appraise() << endl;

    cout << "************** Exercise 4 **************" << endl;
    // personalCollection = {monaLisa, laPieta, hombre, butterfly, inspiration, aquella};
    // cout << "Quantity before filter: " << personalCollection.size() << endl;
    // cout << "Quantity after filter: " << Art::filterCollectionByStyle(personalCollection, cubism).size() << endl;
    // cout << "Quantity before filter: " << personalCollection.size() << endl;
    // cout << "Quantity after filter: " << Art::filterCollectionByStyle(personalCollection, trippy).size() << endl;
    // personalCollection = {monaLisa, inspiration, inspiration};
    // cout << "Quantity before filter: " << personalCollection.size() << endl;
    // cout << "Quantity after filter: " << Art::filterCollectionByStyle(personalCollection, renaissance).size() << endl;
    // personalCollection = {};
    // cout << "Quantity before filter: " << personalCollection.size() << endl;
    // cout << "Quantity after filter: " << Art::filterCollectionByStyle(personalCollection, realism).size() << endl;

    cout << "************** Exercise 5 **************" << endl;
    // personalCollection = {reloj, butterfly, aquella};
    // cout << "Quantity before segregation: " << personalCollection.size() << endl;
    // cout << "Quantity after segregation: " << Sculpture::segregateSculptures(personalCollection).size() << endl;
    // personalCollection = {cosa, hombre, truth};
    // cout << "Quantity before segregation: " << personalCollection.size() << endl;
    // cout << "Quantity after segregation: " << Sculpture::segregateSculptures(personalCollection).size() << endl;
    // personalCollection = {flor, cosa, belleza, hombre, truth};
    // cout << "Quantity before segregation: " << personalCollection.size() << endl;
    // cout << "Quantity after segregation: " << Sculpture::segregateSculptures(personalCollection).size() << endl;
    // personalCollection = {};
    // cout << "Quantity before segregation: " << personalCollection.size() << endl;
    // cout << "Quantity after segregation: " << Sculpture::segregateSculptures(personalCollection).size() << endl;

    cout << "************** Exercise 6A **************" << endl;
    // Collectable *collectable1 = dynamic_cast<Collectable *>(monaLisa);
    // cout << monaLisa->getName() << " is Collectable: " << (collectable1 != NULL) << endl;
    // Art *art3 = dynamic_cast<Art *>(monaLisa);
    // cout << monaLisa->getName() << " is Art: " << (art3 != NULL) << endl;
    // cout << monaLisa->getName() << " Century: " << monaLisa->getCentury() << endl;
    // cout << monaLisa->getName() << " is Successful: " << monaLisa->isSuccessful() << endl;
    // cout << monaLisa->getName() << " is Legit: " << monaLisa->isLegit() << endl;

    // Collectable *collectable2 = dynamic_cast<Collectable *>(aquella);
    // cout << aquella->getName() << " is Collectable: " << (collectable2 != NULL) << endl;
    // Art *art4 = dynamic_cast<Art *>(aquella);
    // cout << aquella->getName() << " is Art: " << (art4 != NULL) << endl;
    // cout << aquella->getName() << " Century: " << aquella->getCentury() << endl;
    // cout << aquella->getName() << " is Successful: " << aquella->isSuccessful() << endl;
    // cout << aquella->getName() << " is Legit: " << aquella->isLegit() << endl;

    cout << "************** Exercise 6B **************" << endl;
    // Collectable *collectable3 = dynamic_cast<Collectable *>(cosa);
    // cout << cosa->getName() << " is Collectable: " << (collectable3 != NULL) << endl;
    // Art *art5 = dynamic_cast<Art *>(cosa);
    // cout << cosa->getName() << " is Art: " << (art5 != NULL) << endl;
    // cout << cosa->getName() << " Century: " << cosa->getCentury() << endl;
    // cout << cosa->getName() << " is Successful: " << cosa->isSuccessful() << endl;
    // cout << cosa->getName() << " is Legit: " << cosa->isLegit() << endl;

    // Collectable *collectable4 = dynamic_cast<Collectable *>(truth);
    // cout << truth->getName() << " is Collectable: " << (collectable4 != NULL) << endl;
    // Art *art6 = dynamic_cast<Art *>(truth);
    // cout << truth->getName() << " is Art: " << (art6 != NULL) << endl;
    // cout << truth->getName() << " Century: " << truth->getCentury() << endl;
    // cout << truth->getName() << " is Successful: " << truth->isSuccessful() << endl;
    // cout << truth->getName() << " is Legit: " << truth->isLegit() << endl;

    cout << "************** Exercise 7 **************" << endl;
    // paintingCollection = {monaLisa, reloj, belleza, aquella, flor, butterfly};
    // cout << "Collection size before: " << paintingCollection.size() << endl;
    // cout << "Paintings of " << cubism.getName() << " style between 1700 and 1800: ";
    // cout << Painting::countPaintings(paintingCollection, cubism, 1700, 1800) << endl;
    // cout << "Collection size after: " << paintingCollection.size() << endl;

    // cout << "Collection size before: " << paintingCollection.size() << endl;
    // cout << "Paintings of " << trippy.getName() << " style between 1990 and 2005: ";
    // cout << Painting::countPaintings(paintingCollection, trippy, 1900, 2005) << endl;
    // cout << "Collection size after: " << paintingCollection.size() << endl;

    // paintingCollection = {};
    // cout << "Collection size before: " << paintingCollection.size() << endl;
    // cout << "Paintings of " << realism.getName() << " style between 1890 and 2205: ";
    // cout << Painting::countPaintings(paintingCollection, realism, 1890, 2205) << endl;
    // cout << "Collection size after: " << paintingCollection.size() << endl;
}
