//
// Created by gerdon on 23.11.2019.
//



#include <vector>
#include <memory>
#include <iostream>


class MyStrategies {

    bool comp(double a, double b){return a >= b;}
    double for_B_Strategy(int k, int size);



private:
    std::vector<std::shared_ptr<double[]>> strategies_B;
    std::vector<std::shared_ptr<double[]>> strategies_A;
    int Size_A, Size_B;
    double *all_a_max;
    double *all_b_min;


public:

    MyStrategies(std::vector<std::array<double, 4>> tactics, int A, int B) {
        Size_A = A;
        Size_B = B;

        if(!strategies_B.empty()){
            strategies_B.clear();
        }
        for (auto & it : tactics) {
            strategies_B.push_back(std::shared_ptr<double[]> (new double[4]{it.at(0), it.at(1), it.at(2), it.at(3)}));
        }

        toStrategy_A();
    }

    const std::vector<std::shared_ptr<double[]>> &getStrategies() const {
        return strategies_B;
    }

    void print(){

        double* a_max = new double[Size_A];
        double* b_min = new double[Size_B];


        for (int i = 0; i < Size_A; ++i) {
            std::cout << "+-------+-------+-------+-------+-------+\n";
            for (int j = 0; j < Size_B; ++j) {
                std::cout << "|  " << strategies_B.at(i)[j] << "\t";
            }
            a_max[i] = for_B_Strategy(i, Size_B);
            std::cout << "|  " << a_max[i]  << "\t|\n";
        }
        std::cout << "+-------+-------+-------+-------+-------+\n";




        b_min[0] = for_A_Strategy(0, Size_A);
        b_min[1] = for_A_Strategy(1, Size_A);
        b_min[2] = for_A_Strategy(2, Size_A);
        b_min[3] = for_A_Strategy(3, Size_A);
        std::cout << "|  " << b_min[0] << "\t|  " <<b_min[1] << "\t|  "<<b_min[2] << "\t|  "<<b_min[3]<< "\t|";
        std::cout << "\n+-------+-------+-------+-------+\n";


        std::cout << "\nMax of bottom bound " << (max(a_max,Size_A));
        std::cout << "\nMin of top bound " << (min(b_min,Size_B));
        is_equal(max(a_max,Size_A), min(b_min,Size_B));



        std::cout << "\n\n" << "Matrix with no dominant rows/columns";
        std::cout  << "\n=========================\n";
        all_a_max = a_max;
        all_b_min = b_min;
    }


    void print_B(){
        if(!strategies_A.empty()) {
            for (int i = 0; i < Size_B; ++i) {
                for (int j = 0; j < Size_A; ++j) {
                    std::cout << strategies_A.at(i)[j] << "\t";
                }
                std::cout << "\n";
            }
            std::cout  << "=========================\n";
        }
    }

private:
    std::vector<std::shared_ptr<double[]>> &toStrategy_A();


    double for_A_Strategy(int k, int size);


    double max(double *a, int size);

    double min(double *a, int size);

    bool is_equal (double a, double b);

public:
    std::vector<std::vector<double>> StrategiesB_to_vector() ;
    std::vector<std::vector<double>> StrategiesA_to_vector() ;
    const std::vector<std::shared_ptr<double[]>> &getStrategiesA() const;

};

