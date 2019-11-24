#include <iostream>
#include <vector>
#include "simplex/SimplexMethod.h"
#include "strategy/MyStrategies.h"

int main() {

    std::vector<std::array<double,4>> strategy_a1;

    strategy_a1.push_back({{6,18,6,15}});
    strategy_a1.push_back({{17,8,13,14}});
    strategy_a1.push_back({{16,16,18,2}});
    strategy_a1.push_back({{18,8,4,18}});
    strategy_a1.push_back({{15,8,3,19}});

    MyStrategies myStrategies(strategy_a1,5,4);
    myStrategies.print();

    vector<vector <double >> a (myStrategies.StrategiesB_to_vector());



    int n = 4;
    int m = 5;
    SimplexMethod method(n, m); // создаём метод
    method.Print();

    method.Read(a); // считываем данные
    method.Solve();
    method.Print();
    std::cout << "*******************************************************\n";
    SimplexMethod method1(m,n);
    method1.Read(myStrategies.StrategiesA_to_vector());
    method1.Solve();
    method1.Print();

    return 0;
}