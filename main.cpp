#include <iostream>
#include <vector>
#include "simplex/SimplexMethod.h"

int main() {


    std::vector<std::vector<double>> strategy_a;

    strategy_a.push_back({{6,18,6,15}});
    strategy_a.push_back({{17,8,13,14}});
    strategy_a.push_back({{16,16,18,2}});
    strategy_a.push_back({{18,8,4,18}});
    strategy_a.push_back({{15,8,3,19}});









    int n = 4;
    int m = 5;
    SimplexMethod method(n, m); // создаём метод
    method.Print();

    method.Read(strategy_a); // считыааем данные
    method.Solve();
    method.Print();






    return 0;
}