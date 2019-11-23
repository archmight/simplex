//
// Created by gerdon on 23.11.2019.
//

#ifndef CORRECT_SIMPLEXMETHOD_H
#define CORRECT_SIMPLEXMETHOD_H


#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class SimplexMethod {
    // строка таблицы
    struct Row {
        vector<double> a; // коэффициенты при x
        double b; // правая часть
    };

    int n; // число переменных
    int m; // число ограничений
    vector<Row> table; // симплекс таблица
    vector<double> c; // коэффициенты оптимизируемой функции
    vector<int> variables; // все переменные
    vector<int> basis; // базисные переменные
    vector<double> deltas; // дельты

    void CalculateDeltas(); // вычисление дельт
    int GetArgMaxDelta(); // вычисление номера минимальной дельты

public:
    SimplexMethod(int n, int m);

    void Read(); // ввод значений
    void Read(vector<vector<double>> a);



    void Print(); // вывод таблицы

    void Solve(); // решение ОЗЛП
};





#endif //CORRECT_SIMPLEXMETHOD_H
