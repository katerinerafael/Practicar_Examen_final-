#include "q1.h"
#include <iostream>
#include <stdexcept>

EnvironmentalZone::EnvironmentalZone(const std::string& name, int maxMeasurements)
    : name(name), maxMeasurements(maxMeasurements)
    if (maxMeasurements < 0 ){
        throw std::invalid_argument("No hay");
    }

void EnvironmentalZone::addPollutionMeasurement(double measurement){
    if (measurement <= 0){
        throw std::invalid_argument("No puede ser numero negativos");
    }
    pollutionMeasurements.push_back(measurement);
}

std::string EnvironmentalZone::getZoneName() const{
    return name;
}

double EnvironmentalZone::calculateAveragePollutionLevel() const{
    double index = 0.0;
    for(double measurement : pollutionMeasurements){
        index += measurement;
    }
    if (pollutionMeasurements.empty()){
        return 0.0;
    }
    return index / pollutionMeasurements.size();
}

bool EnvironmentalZone::exceedsPollutionThreshold(double threshold) const{
    return calculateAveragePollutiionLevel() >= threshold;
}

double EnvironmentalZone::findMaximumPollutionLevel() const{
    if(pollutionMeasurements.empty()){
        throw std::runtime_error("No hay contaminacion registradas");
    }

    double maxPollution = pollutionMeasurements[0];

    for (double measurement : pollutionMeasurements){
        if(measurement > maxPollution){
            maxPollution = measurement;
        }
    }
    return maxPollution;
}