#ifndef LIBRARY_MANAGEMENT_H
#define LIBRARY_MANAGEMENT_H

#include <string>
#include <vector>
#include <stdexcept>

// Clase para representar un libro
class Libro {
public:
    int id;
    std::string titulo;
    std::string autor;
    bool disponible;

    Libro(int id, const std::string& titulo, const std::string& autor, bool disponible = true);
};

// Excepción personalizada para la biblioteca
class BibliotecaException : public std::runtime_error {
public:
    explicit BibliotecaException(const std::string& mensaje);
};

// Clase para manejar la biblioteca
class Biblioteca {
private:
    std::vector<Libro> catalogo;

public:
    Biblioteca() = default;

    // Agregar un libro al catálogo
    void agregarLibro(const Libro& libro);

    // Buscar un libro por ID (lanza excepción si no se encuentra)
    Libro buscarPorId(int id) const;

    // Prestar un libro (marca disponible = false)
    void prestarLibro(int id);

    // Devolver un libro (marca disponible = true)
    void devolverLibro(int id);

    // Mostrar el catálogo completo
    void mostrarCatalogo() const;

    // Contar libros disponibles
    int contarDisponibles() const;
};

#endif // LIBRARY_MANAGEMENT_H
