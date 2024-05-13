#include "./test_cases.h"
#include "./test_functions.h"

int main() {
  for (const auto& t : property_tests) RunTests(t);

  for (auto& t : rule1_tests) RunTests(t, 1);

  for (auto& t : rule2_tests) RunTests(t, 2);

  return 0;
}