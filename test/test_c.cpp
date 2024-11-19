#include <iostream>

#include "test_cases.h"

extern "C" bool CheckProperty(const char* str);
extern "C" void ApplyRule1(char* str);
extern "C" void ApplyRule2(char* str);

// For CheckProperty function tests
void RunTests(const PropertyUnitTest& test, int& count, int& pass_count) {
  const auto& [s, ans] = test;

  std::cout << "[ TEST #" << count << " ]" << std::endl;

  bool res = CheckProperty(&s[0]);

  count++;
  pass_count += (res == ans);  // Increment if result matches expected
  std::cout << "[ " << (res == ans ? "PASSED" : "FAILED") << " ]" << std::endl;
  std::cout << std::endl;
}

// For ApplyRule() function tests
void RunTests(RuleUnitTest test, std::size_t rule_number, int& count,
              int& pass_count) {
  char* s = &test.first[0];
  char* ans = &test.second[0];

  std::cout << "[ TEST #" << count << "]" << std::endl;

  switch (rule_number) {
    case (1): {
      ApplyRule1(s);
      break;
    }
    case (2): {
      ApplyRule2(s);
      break;
    }
    default:
      return;
  }

  bool result = true;
  for (; *s != 0; ++s, ++ans) {
    if (*s == *ans) continue;
    result = false;
  }

  count++;
  pass_count += result;
  std::cout << "[ " << (result ? "PASSED" : "FAILED") << " ]" << std::endl;
  std::cout << std::endl;
}

int main() {
  int pass_count, count = 0;

  std::cout << "[ PROPERTY TESTS ]" << std::endl;
  for (auto& t : property_tests) RunTests(t, count, pass_count);

  std::cout << "[ RULE #1 TESTS ]" << std::endl;
  for (auto& t : rule1_tests) RunTests(t, 1, count, pass_count);

  std::cout << "[ RULE #2 TESTS ]" << std::endl;
  for (auto& t : rule2_tests) RunTests(t, 2, count, pass_count);

  std::cout << "[ " << pass_count << " TESTS OUT OF " << count << " PASSED ]"
            << std::endl;

  return 0;
}