#ifndef ENVIRONMENTAL_MONITORING_H
#define ENVIRONMENTAL_MONITORING_H

#include <string>
#include <vector>

class EnvironmentalZone {
private:
    std::string name;
    int maxMeasurements;
    std::vector<double> pollutionMeasurements;

public:
    // Constructor
    EnvironmentalZone(const std::string& name, int maxMeasurements);

    // Agregar una medición de contaminación
    void addPollutionMeasurement(double measurement);

    // Obtener el nombre de la zona
    std::string getZoneName() const;

    // Calcular el promedio de contaminación
    double calculateAveragePollutionLevel() const;

    // Verificar si supera el umbral (por defecto 6.5)
    bool exceedsPollutionThreshold(double threshold = 6.5) const;

    // Encontrar el nivel máximo de contaminación registrado
    double findMaximumPollutionLevel() const;
};

#endif // ENVIRONMENTAL_MONITORING_H