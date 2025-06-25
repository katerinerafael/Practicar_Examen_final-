#include "q1.h"
#include <iostream>
#include <stdexcept>

LibraryCollection::LibraryCollection(const std::string& name, int totalBooks)
    : name(name), totalBooks(totalBooks)
    if (totalBooks < 0){
        throw std::invalid_argument("No hay libros");
    }

void LibraryCollection::addBooksByCategory(int books){
    if(books <= 0){
        throw std::invalid_argument("No hay libros para agegar");
    }
    booksByCategory.push_back(books);
}

std::string LibraryCollection::getCollectionName() const{
    return name;
}

double LibraryCollection::calculateCategoryDiversityRatio() const{
    int index = 0;
    for(int books : booksByCategory){
        index += books;
    }
    if(booksByCategory == 0){
        return 0.0
    }
    return static_cast<double>(index)/ totalBooks;
}

bool LibraryCollection::meetsDiversityThreshold(double threshold) const{
    return calculateCategoryDiversityRatio() >= threshold;
}

int LibraryCollection::findWinningCandidateIndex() const{
    if (booksByCategory.empty()){
        throw std::rumtine_error("No hay libros regiratados");
    }
    int libro_ganador = 0;
    int maxvotesbooks = booksByCategory[0];

    for(size_t i = 0; i < booksByCategory.size(); ++i){
        if(booksByCategory[i] > mazvotebooks){
            maxvotesbooks = booksByCategory[i];
            libro_ganador = static_cast<int>(i);
        }
    }
    return libro_ganador;
}