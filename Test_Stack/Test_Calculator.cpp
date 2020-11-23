#include "gtest.h"
#include "../Calculator/Calculator.h"
#include "../Calculator/Calculator.cpp"

TEST(Calculator, can_create_a_calculator)
{
    ASSERT_NO_THROW(Calculator calc);
}
TEST(Calculator, can_pass_a_string_to_the_calculator)
{
    Calculator calc;
    std::string str = "1+9*2";
    ASSERT_NO_THROW(calc.SetFormula(str));
}
TEST(Calculator, can_pass_the_correct_string_with_parentheses_to_the_calculator)
{
    Calculator calc;
    std::string str = "(1+9)*2";
    ASSERT_NO_THROW(calc.SetFormula(str));
}

TEST(Calculator, passing_a_formula_with_incorrectly_placed_parentheses_to_the_calculator_will_cause_an_exception)
{
    Calculator calc;
    std::string str = "(1+9*2";
    ASSERT_ANY_THROW(calc.SetFormula(str));
}
TEST(Calculator, can_calculate_the_result_of_an_arithmetic_expression)
{
    Calculator calc;
    calc.SetFormula("1+4*3");
    ASSERT_NO_THROW(calc.res());
}
TEST(Calculator, evaluating_an_expression_with_incorrect_operations_will_throw_an_exception)
{
    Calculator calc;
    calc.SetFormula("1+4*");
    ASSERT_ANY_THROW(calc.res());
}
TEST(Calculator, evaluating_an_expression_without_operations_will_throw_an_exception)
{
    Calculator calc;
    calc.SetFormula("1 4");
    ASSERT_ANY_THROW(calc.res());
}

TEST(Calculator, the_calculator_adds_integers_correctly)
{
    Calculator calc;
    calc.SetFormula("1+4");
    double a = 1.0 + 4.0;
    EXPECT_EQ(a, calc.res());
}
TEST(Calculator, the_calculator_adds_real_numbers_correctly)
{
    Calculator calc;
    calc.SetFormula("1.44+4.128");
    double a = 1.44 + 4.128;
    EXPECT_EQ(a, calc.res());
}
TEST(Calculator, the_calculator_correctly_adds_up_real_and_integers)
{
    Calculator calc;
    calc.SetFormula("1+4.128");
    double a = 1.0 + 4.128;
    EXPECT_EQ(a, calc.res());
}
TEST(Calculator, the_calculator_subtracts_integers_correctly)
{
    Calculator calc;
    calc.SetFormula("1-4");
    double a = 1.0 - 4.0;
    EXPECT_EQ(a, calc.res());
}
TEST(Calculator, the_calculator_subtracts_real_numbers_correctly)
{
    Calculator calc;
    calc.SetFormula("1.44-4.128");
    double a = 1.44 - 4.128;
    EXPECT_EQ(a, calc.res());
}
TEST(Calculator, the_calculator_correctly_subtracts_up_real_and_integers)
{
    Calculator calc;
    calc.SetFormula("1-4.128");
    double a = 1.0 - 4.128;
    EXPECT_EQ(a, calc.res());
}
TEST(Calculator, the_calculator_multiplies_integers_correctly)
{
    Calculator calc;
    calc.SetFormula("2*4");
    double a = 2.0*4.0;
    EXPECT_EQ(a, calc.res());
}
TEST(Calculator, the_calculator_multiplies_real_numbers_correctly)
{
    Calculator calc;
    calc.SetFormula("2.44*4.128");
    double a = 2.44 * 4.128;
    EXPECT_EQ(a, calc.res());
}
TEST(Calculator, the_calculator_correctly_multiplies_up_real_and_integers)
{
    Calculator calc;
    calc.SetFormula("2*4.128");
    double a = 2.0 * 4.128;
    EXPECT_EQ(a, calc.res());
}
TEST(Calculator, the_calculator_divides_integers_correctly)
{
    Calculator calc;
    calc.SetFormula("7/4");
    double a = 7.0/4.0;
    EXPECT_EQ(a, calc.res());
}
TEST(Calculator, the_calculator_divides_real_numbers_correctly)
{
    Calculator calc;
    calc.SetFormula("1.44/4.128");
    double a = 1.44 / 4.128;
    EXPECT_EQ(a, calc.res());
}
TEST(Calculator, the_calculator_correctly_divides_up_real_and_integers)
{
    Calculator calc;
    calc.SetFormula("7/4.128");
    double a = 7.0 / 4.128;
    EXPECT_EQ(a, calc.res());
}
TEST(Calculator, the_calculator_raise_to_a_degree_integers_correctly)
{
    Calculator calc;
    calc.SetFormula("4^7");
    double a = pow(4.0, 7.0);
    EXPECT_EQ(a, calc.res());
}
TEST(Calculator, the_calculator_raise_to_a_degree_real_numbers_correctly)
{
    Calculator calc;
    calc.SetFormula("1.44^4.128");
    double a = pow(1.44, 4.128);
    EXPECT_EQ(a, calc.res());
}
TEST(Calculator, the_calculator_correctly_raise_to_a_degree_up_real_and_integers)
{
    Calculator calc;
    calc.SetFormula("4.128^7");
    double a = pow(4.128,7.0);
    EXPECT_EQ(a, calc.res());
}
TEST(Calculator, the_calculator_correctly_counts_complex_arithmetic_expressions)
{
    Calculator calc;
    calc.SetFormula("(16-7*2)^3-10/4*(4*2-20/4)");
    EXPECT_EQ(0.5, calc.res());
}