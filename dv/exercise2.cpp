#include <VExercise2.h>
#include <iostream>
#include <iomanip>
#include <bit>
#include <cstdint>
#include <catch2/catch_test_macros.hpp>

struct LFSR {
  uint16_t value;
  static constexpr uint16_t mask = 0x050A; // taps at 10, 8, 3, 1, binary:0000_0101_0000_1010

  void step() {
    uint16_t bits = value & mask;
    value = (value << 1) | (std::popcount(bits) & 1); // feedback bit is parity of tapped bits
  }
};

void step(VExercise2& model) {
  model.clk = 1;
  model.eval();
  model.clk = 0;
  model.eval();
}

void test_initial_value(uint16_t init){
  VExercise2 model;
  
  // Initialize all signals
  model.clk = 0;
  model.init = init;
  model.reset = 1;
  model.eval();  // Apply initial values
  
  // Apply reset (on negedge)
  step(model);
  model.reset = 0;
  model.eval();  // Apply reset = 0
  
  LFSR lfsr{(uint16_t)~init};

  for (uint8_t cycles = 0; cycles < 100; cycles++)
  {
    REQUIRE(model.out == lfsr.value);
    lfsr.step();
    step(model);
  }
  
  // Test reset again
  model.reset = 1; 
  step(model);
  REQUIRE(model.out == (uint16_t)~init);
}

TEST_CASE("Initial value 0x00") {
  test_initial_value(0x00);
}

TEST_CASE("Initial value 0xFF") {
  test_initial_value(0xFF);
}

TEST_CASE("Initial value 0x55") {
  test_initial_value(0x55);
}

TEST_CASE("Initial value 0xAA") {
  test_initial_value(0xAA);
}



