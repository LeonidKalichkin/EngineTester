#include <iostream>
#include <vector>
#include "environment/Environment.h"
#include "engine/InternalCombustionEngine.h"
#include "testbed/OverheatTestbed.h"


int main()
{
    double t;
    std::cout << "Enter the ambient temperature:" << std::endl;
    std::cin >> t;

    if (std::cin.fail())
    {
        std::cout << "Wrong number input." << std::endl;
        return 1;
    }

    Environment env = Environment(t);

    double i = 10; //момент инерции
    std::vector<double> m = { 20, 75, 100, 105, 75, 0 }; //значения крутящего момента в кусочно-линейной зависимости
    std::vector<double> v = { 0, 75, 150, 200, 250, 300 }; //значения скорости коленвала в кусочно-линейной зависимости
    double to = 110; //температура перегрева
    double nm = 0.01; //коэффициент зависимости скорости нагрева от крутящего момента
    double nv = 0.0001; //коэффициент зависимости скорости нагрева от скорости вращения коленвала
    double c = 0.1; //коэффициент зависимости скорости охлаждения от температуры двигателя и окружающей среды

    InternalCombustionEngine engine = InternalCombustionEngine(env, i, m, v, nm, nv, c);

    double tl = 600; //ограничение на время симуляции в секундах (10 минут)
    double ts = 0.01; //шаг времени для симуляции в секундах

    OverheatTestbed testbed = OverheatTestbed(to, tl, ts);
    int result = testbed.run(engine);

    if (result == 0)
    {
        std::cout << "Seconds passed until overheating: " << testbed.getTimePassed() << std::endl;
    }
    else if (result == 1)
    {
        std::cout << "Time limit passed without overheating." << std::endl;
    }
}