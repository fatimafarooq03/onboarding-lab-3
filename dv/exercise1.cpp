#include <VExercise1.h>
#include <cstdint>

int main() {
 // VExercise1 model;

  void test_op(uint8_t code, uint8_t(op)(uint8_t, uint8_t)) {
  VExercise1 model;
  model.op = code;
  model.a = 0;
  model.b = 0;

  do {
    do {
      model.eval();
      uint8_t result {op(model.a, model.b)};
      REQUIRE(result == model.out);
    } while(++model.b);
  } while(++model.a);
}


TEST_CASE("Opcode 0, bitwise XOR") {
  test_op(0, [](uint8_t a, uint8_t b) -> uint8_t { return a ^ b; });
}

TEST_CASE("Opcode 1, left shift") {
  test_op(1, [](uint8_t a, uint8_t b) -> uint8_t { return a << b; });
}

TEST_CASE("Opcode 2, modulus") {
  test_op(2, [](uint8_t a, uint8_t b) -> uint8_t { return a % b; });
}

TEST_CASE("Opcode 3, Or") {
  test_op(3, [](uint8_t a, uint8_t b) -> uint8_t { return ~(a & b); });
}



};

