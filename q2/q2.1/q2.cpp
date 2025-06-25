#include <q2.h>
#include <iostream>
#include <stdexcept>

Libro::Libro(int id, const std::string& titulo, const std::string& autor, bool disponible)
    :id(id), titulo(titulo), autor(autor), disponible(disponible){}

explicit BibliotecaException::BibliotecaException(const std::string& mensaje)
    :std::runtime_error(mensaje){}

void Biblioteca::agregarLibro(const Libro& libro){
    if(libro.id < 0){
        throw std::invalid_argument("No se pueden agregar libros si es menos que 0");
    }
    for (const libro& 1 : catalogo){
        if(1.id == libro.id){
            throw std::invalid_argument("No se puede agregar un libro que ya existe");
        }

    }
    catalogo.push_back(libro);
}

Libro Biblioteca::buscarPorId(int id) const{
    for(const Libro$ libro : catelogo){
        if(libro.id == id){
            return libro;
        }
    }
    throw BibliotecaException("No se encuentra el id");
}

void Biblioteca::prestarLibro(int id){
    for(const Libro$ libro : catalogo){
        if(libro.id==id){
            if(libro.disponible){
                libro.disponible = false;
                return;
            }else{
            throw BibliotecaException("Ya se presto el libro, no esta diponible");
    }
}throw BibliotecaException("No se encuentra el id del libro");
}
}

void Biblioteca::devolverLibro(int id){
    for( Libro& libro : catalogo){
        if(libro.id == id){
            if(libro.disponible == false){
                libro.disponible = true;
                return;
            }else{
                throw BibliotecaException("Este libro no se ha tomado prestado por ende no se puede devolver");
            }
        }
    }throw BibliotecaException("No se encuentra el libro");
}

void Biblioteca::mostrarCatalogo() const{
    for(const Libro& libro : catalogo){
        std::cout<< "ID: " << libro.id
                 << "Titulo: " << libro.titulo
                 << "autor: "<< libro.autor
                 << "Esta disponible? : "<< (libro.disponible? "SI": "NO")
                 << std::endl;
    }
}

int biblioteca::contarDisponibles() const{
    int librosdisponibles = 0;
    for(const Libro& libro : catalogo){
        if(libro.id == id){
            if(libro.diponible == true){
                librosdisponibles++;
            }
        }throw BibliotecaException("No se encuentra el libro");
}return librosdisponibles;
}