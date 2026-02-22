#include <VExercise2.h>
#include <iostream>
#include <iomanip>
#include <bit>
#include <cstdint>
#include <cstdio>

struct LFSR {
  uint16_t value;
  static constexpr uint16_t mask = 0x054A; // taps at 10, 8, 3, 1, binary:0000_0101_0100_1010

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

bool test_initial_value(uint16_t init){
  VExercise2 model;
  model.init = init;
  model.reset = 1;
  step(model);
  model.reset = 0;

  LFSR lfsr{(uint16_t)~init};

  for (uint8_t cycles = 0; cycles < 100; cycles++)
  {
    if (model.out != lfsr.value) {
      printf("  FAIL at cycle %d: model.out=0x%04X, expected=0x%04X\n", 
             cycles, model.out, lfsr.value);
      return false;
    }
    lfsr.step();
    step(model);
  }
  model.reset = 1; 
  step(model);
  if (model.out != (uint16_t)~init) {
    printf("  FAIL after reset: model.out=0x%04X, expected=0x%04X\n", 
           model.out, (uint16_t)~init);
    return false;
  }
  
  return true;
}

int main() {
  int passed = 0;
  int failed = 0;
  
  printf("Testing Exercise2 LFSR...\n\n");
  
  // Test case 1
  printf("Test 1: Initial value 0x0000... ");
  if (test_initial_value(0x0000)) {
    printf("PASS\n");
    passed++;
  } else {
    failed++;
  }
  
  // Test case 2
  printf("Test 2: Initial value 0x00FF... ");
  if (test_initial_value(0x00FF)) {
    printf("PASS\n");
    passed++;
  } else {
    failed++;
  }
  
  // Test case 3
  printf("Test 3: Initial value 0x0055... ");
  if (test_initial_value(0x0055)) {
    printf("PASS\n");
    passed++;
  } else {
    failed++;
  }
  
  // Test case 4
  printf("Test 4: Initial value 0x00AA... ");
  if (test_initial_value(0x00AA)) {
    printf("PASS\n");
    passed++;
  } else {
    failed++;
  }
  
  // Test case 5
  printf("Test 5: Initial value 0x1234... ");
  if (test_initial_value(0x1234)) {
    printf("PASS\n");
    passed++;
  } else {
    failed++;
  }
  
  printf("\n========================================\n");
  printf("Results: %d passed, %d failed\n", passed, failed);
  printf("========================================\n");
  
  return (failed == 0) ? 0 : 1;
}