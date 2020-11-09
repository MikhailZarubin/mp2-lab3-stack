/*#include "../Test_Stack/gtest.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}*/
#include"../Stack/Calculator.h"
#include<iostream>
void main()
{
    Calculator calc;
    calc.SetFormula("1 2 +");
    double resul = calc.res();
    std::cout << resul;
}
