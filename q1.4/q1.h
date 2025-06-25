#ifndef SALES_ANALYSIS_H
#define SALES_ANALYSIS_H

#include <string>
#include <vector>

class SalesDepartment {
private:
    std::string departmentName;
    int maxEmployees;
    std::vector<double> employeeSales;

public:
    // Constructor
    SalesDepartment(const std::string& name, int maxEmployees);

    // Agrega ventas de un empleado
    void addEmployeeSales(double sales);

    // Devuelve el nombre del departamento
    std::string getDepartmentName() const;

    // Calcula el promedio de ventas del departamento
    double calculateAverageSales() const;

    // Verifica si el promedio de ventas supera un umbral fijo (por ejemplo, $50,000)
    bool meetsPerformanceThreshold(double threshold = 50000.0) const;

    // Encuentra el índice del empleado con mayores ventas
    int findTopPerformingEmployeeIndex() const;
};

#endif // SALES_ANALYSIS_H
