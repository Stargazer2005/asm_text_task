#include <assert.h>
#include <ctype.h>
#include <stdbool.h>

// Property:
// Text contains no characters other than numbers and Latin letters.
bool CheckProperty(const char* str) {
  // Check if pointer is valid
  if (!str) return false;

  // Check every symbol
  for (; *str != '\0'; ++str)
    if (!isdigit(*str))
      if (!isalpha(*str)) return false;

  return true;
}

// Rule1:
// Replace each non-zero digit with the corresponding lowercase letter of the
// Latin alphabet (1->a, 2->b, etc.).
void ApplyRule1(char* str) {
  // Check if pointer is valid
  if (!str) return;

  for (; *str != '\0'; ++str)
    if ((isdigit(*str)) && (*str != '0')) *str = (char)(48 + *str);
}

// Rule2:
// Leave only one character in each group of consecutive identical characters.
void ApplyRule2(char* str) {
  // Check if pointer is valid
  if (!str) return;

  char last_unique = '\0';
  char* mod_str = str;

  for (; *str != '\0'; ++str)
    if (*str != last_unique) {
      last_unique = *str;
      *mod_str = *str;
      mod_str++;
    }

  *mod_str = '\0';
  str = mod_str;
}