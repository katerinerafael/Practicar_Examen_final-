#include "q2.h"
#include <iostream>
#include <stdexcept>

CalificacionesException::CalificacionesException(const std::string& mensaje)
    : std::runtime_error(mensaje){}


Estudiante::Estudiante(int id, const std::string& nombre, const std::string& apellido)
    : id(id), nombre(nombre), apellido(apellido){}

void SistemaCalificaciones::agregarEstudiante(const Estudiante& Estudiante){
    if(Estudiante.id < 0){
        throw CalificacionesException("NO hay estudiante para agregar");
    }
    estudiantes.push_back(Estudiante.id);
}

void SistemaCalificaciones::eliminarEstudiante(int id){
    for(size_t i = 0; i < estudiantes.size(); ++i){
            if(estudiantes[i].id == id ){
            estudiantes.erase(estudiante.begin() + i);
        }
        throw CalificacionesException("No se encuentra el id");
    }
}

Estudiante SistemaCalificaciones::buscarEstudiante(int id) const{
    for(size_t i = 0; i < estudiantes.size(); ++i){
        if(estudiantes[i].id == id){
            return estudiantes[i];
        }
    }throw CalificacionesException("No se encuentra el id del estudiante");
}

void SistemaCalificaciones::agregarAsignatura(int idEstudiante, const std::string& asignatura){

    for(const auto& est : estudiantes){
        if(est.id == idEstudiante){
            auto& asignaturas = asignaturasPorEstudiante[idEstudiante];
            if(std::find(asignaturas.begin(), asignaturas.end(), asignatura) != asignaturas.end()))
        }
    }
    for(size_t i = 0; i < asignaturasPorEstudiante.size(); ++i){
        if(estudiantes[i].id == idEstudiante){
            asignaturasPorEstudiante.push_back(asignatura);
        }
    }
    throw CalificacionesException("No se encuentra el estudiante para agregarle la asignatura");
}
