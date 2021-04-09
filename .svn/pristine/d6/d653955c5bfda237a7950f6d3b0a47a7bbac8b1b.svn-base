#include "linq.hpp"
#include <math.h>
#include <assert.h>
#include <vector>
#include <sstream>
#include <iterator>

using linq::from;

void example1() {
  int xs[] = { 1, 2, 3, 4, 5, 4, 5 };

  std::vector<int> res =
    from(xs, xs + 7)
    .select([](int x) { return x * x; })
    .where_neq(16)
    .to_vector();

  std::vector<int> expected = { 1, 4, 9, 25, 25 };
  assert(res == expected);
}

void example2() {
    int xs[] = { 1, 2, 3, 4, 5, 4, 5 };

    std::vector<int> res =
            from(xs, xs + 7)
            .select([](int x) { return x * x; })
            .until_eq(16)
            .to_vector();

    std::vector<int> expected = { 1, 4, 9 };
    assert(res == expected);
}

void example3() {
    int xs[] = { 1 };

    std::vector<int> res =
            from(xs, xs)
            .select([](int x) { return x * x; })
            .until_eq(16)
            .to_vector();

    std::vector<int> expected = { };
    assert(res == expected);
}

void example4() {
    int xs[] = { 1, 2, 3};

    std::vector<int> res =
            from(xs, xs)
            .drop(10)
            .to_vector();

    std::vector<int> expected = { };
    assert(res == expected);
}

void example5() {
    int xs[] = { 1, 2, 3, 4, 5, 4, 5 };

    std::vector<int> res =
            from(xs, xs + 7)
                    .take(6)
                    .to_vector();

    std::vector<int> expected = { 1, 2, 3, 4, 5, 4 };
    assert(res == expected);
}

void example6() {
    int xs[] = { 1, 2, 3, 4, 5, 4, 5 };

    std::vector<int> res =
            from(xs, xs + 7)
                    .take(8)
                    .to_vector();

    std::vector<int> expected = { 1, 2, 3, 4, 5, 4, 5};
    assert(res == expected);
}

int main() {
  example1();
  example2();
  example3();
  example4();
  example5();
  example6();
  return 0;
}
