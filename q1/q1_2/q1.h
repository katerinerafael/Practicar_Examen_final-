#ifndef LIBRARY_MANAGEMENT_H
#define LIBRARY_MANAGEMENT_H

#include <string>
#include <vector>

class LibraryCollection {
private:
    std::string name;
    int totalBooks;
    std::vector<int> booksByCategory;

public:
    // Constructor
    LibraryCollection(const std::string& name, int totalBooks);

    // Agregar libros a una categoría (se asumirá una nueva categoría cada vez que se llama)
    void addBooksByCategory(int books);

    // Obtener nombre de la colección
    std::string getCollectionName() const;

    // Calcular ratio de diversidad: total libros por categoría / total libros
    double calculateCategoryDiversityRatio() const;

    // Verificar si cumple con el umbral de diversidad (default 0.5)
    bool meetsDiversityThreshold(double threshold = 0.5) const;

    // Encontrar índice de la categoría más popular (más libros)
    int findMostPopularCategoryIndex() const;
};

#endif // LIBRARY_MANAGEMENT_H
