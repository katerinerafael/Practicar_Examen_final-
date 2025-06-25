#include "q1.h"
#include <iostream>


ElectoralDistrict::ElectoralDistrict(const std::string& name, int totalVoters)
    : totalVoters(totalVoters), name(name){
    if (totalVoters < 0){
        throw std::invalid_argument ("Los votos no pueden ser negativos");
    }
}

void ElectoralDistrict::addCandidateVotes(int votes){
    if(votes <= 0){
        throw std::invalid_argument ("Los votos no pueden ser negativos");
    }
    candidateVotes.push_back(votes);
}

std::string ElectoralDistrict::getDistrictName() const{
    return name;
}

double ElectoralDistrict::calculateParticipationRate() const{
    int index = 0;
    for(int votes : candidateVotes){
        index += votes;
    }
    if (totalVoters == 0){
        return 0.0;
    }

    return static_cast<double>(index) / totalVoters;
}

bool ElectoralDistrict::meetsParticipationThreshold(double threshold) const{
    return calculateParticipationRate() >= threshold;
}

int ElectoralDistrict::findWinningCandidateIndex() const{
    if(candidateVotes.empty()){
        throw std::runtime_error("No hay candidatos registrados");
    }
    int winning_index = 0;
    int maxvotes = candidateVotes[0];

    for (size_t i = 1; i < candidateVotes.size(); ++i ){
        if(candidateVotes[i] > maxvotes){
            maxvotes = candidateVotes[i];
            winning_index = static_cast<int>(i);

        }
    }
    return winning_index;
}