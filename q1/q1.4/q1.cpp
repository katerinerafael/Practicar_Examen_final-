#include "q1.h"
#include <iostream>
#include <stdexcept>

SalesDepartment::SalesDepartment(const std::string& name, int maxEmployees)
    : departmentName(name), maxEmployees(maxEmployees){
    if (maxEmployees < 0 ) {
        throw std::invalid_argument("No puede ser menor de 0");
    }
}
void SalesDepartment::addEmployeeSales(double sales){
    if(sales <= 0){
        throw std::invalid_argument("No se pueden agregar una cantidad de empleados si es menor a 0 o igual");
    }
    if(employeeSales.size() >= static_cast<size_t>(maxEmployees)){
        throw std::invalid_argument("No se puede agregar mas ventas que empleados");
    }
    employeeSales.push_back(sales);
}

std::string SalesDepartment::getDepartmentName() const{
    return departmentName;
}

double SalesDepartment::calculateAverageSales() const{
    if(employeeSales.empty()){
        return 0.0;
    }
    double index = 0.0;
    for(double sales : employeeSales){
        index += sales;
    }
    return index / employeeSales.size();

}

bool SalesDepartment::meetsPerformanceThreshold(double threshold) const{
    return calculateAverageSales() >= threshold;
}

int SalesDepartment::findTopPerformingEmployeeIndex() const{
    if(employeeSales.empty()){
        throw std::runtime_error("No hay ventas");
    }
    int bestindex = 0;
    double maxperforming = employeeSales[0];
    for(size_t i = 1; i < employeeSales.size(); ++i){
        if(employeeSales[i] > maxperforming){
            maxperforming = employeeSales[i];
            bestindex = static_cast<int>(i);
        }
    }
    return bestindex;
    }
