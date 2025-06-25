#ifndef GRADES_H
#define GRADES_H

#include <string>
#include <vector>
#include <map>
#include <stdexcept>

class CalificacionesException : public std::runtime_error {
public:
    explicit CalificacionesException(const std::string& mensaje)
        : std::runtime_error(mensaje) {}
};

class Estudiante {
public:
    int id;
    std::string nombre;
    std::string apellido;

    Estudiante(int id, const std::string& nombre, const std::string& apellido);
};

class SistemaCalificaciones {
private:
    std::vector<Estudiante> estudiantes;
    // Mapa: estudiante_id -> (asignatura -> lista de calificaciones)
    std::map<int, std::map<std::string, std::vector<double>>> calificaciones;
    // Mapa para llevar las asignaturas por estudiante
    std::map<int, std::vector<std::string>> asignaturasPorEstudiante;

public:
    void agregarEstudiante(const Estudiante& estudiante);
    void eliminarEstudiante(int id);
    Estudiante buscarEstudiante(int id) const;

    void agregarAsignatura(int idEstudiante, const std::string& asignatura);
    void agregarCalificacion(int idEstudiante, const std::string& asignatura, double calificacion);

    void mostrarTodosLosEstudiantes() const;
    void mostrarCalificacionesEstudiante(int idEstudiante) const;
    void mostrarPromedioGeneral(int idEstudiante) const;
    void mostrarMejoresEstudiantes() const;
};

#endif // GRADES_H
