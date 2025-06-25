// q1.h
#ifndef Q1_H
#define Q1_H

#include <string>
#include <vector>

class ElectoralDistrict {
private:
    std::string name;
    int totalVoters;
    std::vector<int> candidateVotes;

public:
    ElectoralDistrict(const std::string& name, int totalVoters);

    void addCandidateVotes(int votes);

    std::string getDistrictName() const;

    double calculateParticipationRate() const;

    bool meetsParticipationThreshold(double threshold = 0.5) const;

    int findWinningCandidateIndex() const;
};

#endif // Q1_H
