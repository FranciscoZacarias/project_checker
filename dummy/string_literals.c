#include <stdio.h>

int main() {
  const char* s1 = "Hello";
  const char* s2 = "World";
  const char* s3 = "Hello" " " "World";  // Concatenated
  const char* escaped = "Line1\nLine2\tTabbed";
  const wchar_t* ws = L"Wide string";

  printf("%s\n", s1);
  printf("%s\n", s2);
  printf("%s\n", s3);
  printf("%s\n", escaped);
  return 0;
}
