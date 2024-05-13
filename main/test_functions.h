#include <iostream>

extern "C" bool CheckProperty(const char* str);

extern "C" void ApplyRule1(char* str);

extern "C" void ApplyRule2(char* str);

// For CheckProperty function tests
void RunTests(const PropertyUnitTest& test) {
  const auto& [s, ans] = test;
  std::cout << s << " " << ans << " " << std::endl;

  bool res = CheckProperty(&s[0]);

  std::cout << "[" << (res == ans ? "OK" : "FAILED") << "]" << std::endl;
}

// For ApplyRule() function tests
void RunTests(RuleUnitTest test, std::size_t rule_number) {
  char* s = &test.first[0];
  char* ans = &test.second[0];

  std::cout << s << " " << ans << " " << std::endl;

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
      break;
  }

  bool result = true;
  for (; *s != 0; ++s, ++ans) {
    if (*s == *ans) continue;
    result = false;
  }

  std::cout << "[" << (result ? "OK" : "FAILED") << "]" << std::endl;
}
