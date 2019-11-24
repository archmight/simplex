//
// Created by gerdon on 23.11.2019.
//

#include "MyStrategies.h"

double MyStrategies::for_B_Strategy(int k, int size) {
    double max = strategies_B.at(k)[0];
    for(int i = 1; i < size; ++i){
        if (comp(max, strategies_B.at(k)[i])){
            max = strategies_B.at(k)[i];
        }
    }
    return max;
}

double MyStrategies::for_A_Strategy(int k, int size) {
    double max = strategies_A.at(k)[0];
    for(int i = 1; i < size; ++i){
        if (!comp(max, strategies_A.at(k)[i])){
            max = strategies_A.at(k)[i];
        }
    }
    return max;
}


double MyStrategies::max(double* a, int size){
    double max = a[0];
    for(int i = 1; i < size; ++i){
        if (!comp(max,a[i])){
            max = a[i];
        }
    }
    return max;
}

double MyStrategies::min(double* a, int size){
    double min = a[0];
    for(int i = 1; i < size; ++i){
        if (comp(min,a[i])){
            min = a[i];
        }
    }
    return min;
}


std::vector<std::shared_ptr<double[]>>& MyStrategies::toStrategy_A() {

    if(!strategies_A.empty()){
        strategies_A.clear();
    }
    for (int j = 0; j < Size_B; ++j) {
        double* a = new double[Size_A];
        for (int i = 0; i < Size_A; ++i) {
            a[i] = strategies_B.at(i)[j];
        }
        strategies_A.push_back(std::shared_ptr<double[]> (a));
    }
}

 std::vector<std::vector<double>> MyStrategies::StrategiesB_to_vector()  {

    std::vector<std::vector<double >> a (Size_A,std::vector<double> (Size_B));


    for (int j = 0; j < Size_A; ++j){
        for (int i = 0; i < Size_B; ++i) {
            a.at(j).at(i) = strategies_B.at(j)[i];
        }
    }

    return a;
}

std::vector<std::vector<double>> MyStrategies::StrategiesA_to_vector() {

    std::vector<std::vector<double >> a (Size_B,std::vector<double> (Size_A));


    for (int j = 0; j < Size_B; ++j){
        for (int i = 0; i < Size_A; ++i) {
            a.at(j).at(i) = strategies_A.at(j)[i];
        }
    }

    return a;
}


const std::vector<std::shared_ptr<double[]>> &MyStrategies::getStrategiesA() const {
    return strategies_A;
}

bool MyStrategies::is_equal(double a, double b) {
    if(a == b) {
        std::cout <<"\nequal\n";
        return true;
    }
    else {
        std::cout << "\nnot equal\n";
        return false;
    }
}