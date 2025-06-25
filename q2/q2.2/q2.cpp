#include "q2.h"
#include <iostream>
#include <stdexcept>

Producto::Producto(int id, const std::string& nombre, double precio, int cantidad, Categoria categoria)
    :id(id), nombre(nombre), precio(precio), cantidad(cantidad), categoria(categoria){}

InventarioException::InventarioException(const std::string& mensaje)
    :std::runtime_error(mensaje){}

int Inventario::encontrarIndicePorId(int id) const{
    for(size_t i = 0; i < productos.size(); ++i){
        if(productos[i].id == id){
            return i;
        }
    }throw std::invalid_argument("Ese producto no se encuentra");
}

void Inventario::agregarProducto(const Producto& producto){
    for(size_t i = 0; i < productos.size(); ++i){
        if(productos[i].id == producto.id){
            throw std::invalid_argument("Ya se encuentra el producto");
        }
    }
    productos.push_back(producto);
}

void Inventario::eliminarProducto(int id){
    for(size_t i=0; i<productos.size(); ++i){
        if(productos[i].id == id){
            productos.erase(producto.begin() + i);
            return;
        }
    }
    throw InventarioException("No existe este producto entonces no se pues eliminar");
}

Producto Inventario::buscarPorId(int id) const{
    for(size_t i = 0; i<productos.size(); ++i){
        if(productos[i].id == id){
            return productos[i];
        }
    }
    throw InventarioException("No se encuentra ese producto");
}

void Inventario::actualizarCantidad(int id, int nuevaCantidad){
    for(size_t i = 0; i <productos.size(); ++i){
        if(productos[i].id == id){
            productos[i].cantidad = nuevaCantidad;
            return;
        }
    }
    throw InventarioException("No se encuentra ese producto");
}

void Inventario::actualizarPrecio(int id, double nuevoPrecio){
    for(size_t i=0; i<productos.size(); ++i ){
        if(productos[i].id == id){
            productos[i].precio = nuevoPrecio;
            return;
        }
    }
    throw InventarioException("No se encuentra el producto");
}

void Inventario::mostrarInventario() const{
    for(const auto& producto : productos){
        std::cout<<"ID: " << producto.id
                 <<", Nombre:  " <<producto.nombre
                 <<", Precio:  " <<producto.precio
                 <<", cantidad: "<<producto.cantidad
                 <<", categoria: ";

        switch(producto.categoria){
            case Categoria::ELECTRONICA:
            std::cout << "Electronica";
            break;
            case Categoria::ROPA:
            std::cout<< "Ropa";
            break;
            case Categoria::ALIMENTOS:
            std::cout<<"alimentos";
            break;
            case Categoria::HOGAR:
            std::cout<<"hogar";
            break;
        }

        std::cout<<std::endl;
    }
}

void Inventario::mostrarPorCategoria() const{

    std::vector<Categoria> categorias ={
        Categoria::ELECTRONICA, Categoria::ROPA, Categoria::ALIMENTOS, Categoria::HOGAR
    };
    for(Categoria cat : categorias){
        switch(cat){
            case Categoria::ELECTRONICA:
            std::cout << "Electronica";
            break;
            case Categoria::ROPA:
            std::cout<< "Ropa";
            break;
            case Categoria::ALIMENTOS:
            std::cout<<"alimentos";
            break;
            case Categoria::HOGAR:
            std::cout<<"hogar";
            break;
        }
   
    for(const auto& producto : productos){
        if(producto.categoria == cat){
            std::cout << "ID: " << producto.id
                  << "Nombre: " << producto.nombre
                  << "precio: " << producto.precio
                  << "cantidad: "<< producto.cantidad;
        }
       }  
    }
}

