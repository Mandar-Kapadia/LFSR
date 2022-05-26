/*Copyright 2022  Mandar Kapadia */
#include<iostream> //NOLINT
#include<math.h> //NOLINT
#include<string> //NOLINT
#include<vector> //NOLINT
/**
 * 
 * Mandar Kapadia, comp4 , prof daly
 * 2/7/22
 * 
 * in this program we make a linear feedback shift Register file and we use the boost to check if it worked or not
 *
 * 
 * */
class FibLFSR{
 public:
     explicit FibLFSR(std::string seed);
     int step();
     int generate(int k);
     friend std::ostream& operator <<(std::ostream& out, const FibLFSR& print);
     std::string getSeed();
     ~FibLFSR();
 private:
    std::vector<char> num_seeds;
};

