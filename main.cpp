#include <iostream>
#include <cmath>

void help_screen() {
  std::cout << "Add: Adds two numbers\n";
  std::cout << "     Example: a 2.5 8.0\n";
  std::cout << "Subtract: Subtracts two numbers\n";
  std::cout << "     Example: s 10.5 8.0\n";
  std::cout << "Print: Displays the result of the latest operation\n";
  std::cout << "     Example: p\n";
  std::cout << "Help: Displays this help screen\n";
  std::cout << "     Example: h\n";
  std::cout << "Quit: Exits the program\n";
  std::cout << "     Example: q\n";
}

char menu() {
  std::cout << "=== A)dd S)ubtract P)rint H)elp Q)uit===\n";
  char ch;
  std::cin >> ch;
  return ch;
}

double result = 0.0;
double arg1;
double arg2;

void get_input() {
  std::cin >> arg1 >> arg2;
}

void report() {
  std::cout << result << '\n';
}

void add() {
  result = arg1 + arg2;
}

void subtract() {
  result = arg1 - arg2;
}

int main() {
  bool done = false;
  do {
    switch (menu()) {
      case 'A':
      case 'a':
        get_input();
        add();
        report();
      case 'S':
      case 's':
        get_input();
        subtract();
        report();
      case 'P':
      case 'p':
        report();
        break;
      case 'H':
      case 'h':
        help_screen();
        break;
      case 'Q':
      case 'q':
        done = true;
        break;
    }
  } while (!done);

}
