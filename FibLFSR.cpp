/*Copyright 2022  Mandar Kapadia */
/**
 * 
 * Mandar Kapadia, comp4 , prof daly
 * 2/7/22
 * 
 * in this program we make a linear feedback shift Register file and we use the boost to check if it worked or not
 *
 * 
 * */

#include "FibLFSR.h"//NOLINT

FibLFSR::FibLFSR(std::string seed) {
    for (int i = 0; i<static_cast<int>(seed.size()); i++) {
        num_seeds.push_back(seed.at(i));
    }
}
int FibLFSR::step() {
    int fifteenth_term = static_cast<int>(num_seeds.at(0)-'0');
    int thirteenth_term = static_cast<int>(num_seeds.at(2)-'0');
    int twelfth_term = static_cast<int>(num_seeds.at(3)-'0');
    int tenth_term = static_cast<int>(num_seeds.at(5)-'0');


    int num_xor = (((fifteenth_term^ thirteenth_term)^twelfth_term)^tenth_term);
    num_seeds.erase(num_seeds.begin());

    char char_xor = static_cast<char>(num_xor +'0');
    num_seeds.push_back(char_xor);

    return(num_xor);
}
int FibLFSR::generate(int k) {
    int counter = 0;
    int amount = 0;
    std::vector<int>step_ret;
    for (int i = 0; i < k; i++) {
        step_ret.push_back(this->step());
    }
    for (auto it = step_ret.rbegin(); it != step_ret.rend(); it++) {
        amount += (*it)*pow(2, counter);
        counter++;
    }
    return amount;
}
std::ostream& operator <<(std::ostream& out, const FibLFSR& temp) {
    for (auto& it : temp.num_seeds) {
        out << it;
    }
    return out;
}

std::string FibLFSR::getSeed() {
    std::string ret = "";
    for (auto& it : num_seeds) {
        ret += it;
    }
    return(ret);
}
FibLFSR::~FibLFSR() {
    num_seeds.empty();
}
