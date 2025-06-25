#ifndef STOCKTAKING_H
#define STOCKTAKING_H

#include <string>
#include <vector>
#include <stdexcept>

enum class Categoria {
    ELECTRONICA,
    ROPA,
    ALIMENTOS,
    HOGAR
};

struct Producto {
    int id;
    std::string nombre;
    double precio;
    int cantidad;
    Categoria categoria;

    Producto(int id, const std::string& nombre, double precio, int cantidad, Categoria categoria);
};

class InventarioException : public std::runtime_error {
public:
    explicit InventarioException(const std::string& mensaje);
};

class Inventario {
private:
    std::vector<Producto> productos;

    int encontrarIndicePorId(int id) const;

public:
    void agregarProducto(const Producto& producto);
    void eliminarProducto(int id);
    Producto buscarPorId(int id) const;
    void actualizarCantidad(int id, int nuevaCantidad);
    void actualizarPrecio(int id, double nuevoPrecio);
    void mostrarInventario() const;
    void mostrarPorCategoria(Categoria categoria) const;
    double calcularValorTotal() const;
};

#endif
