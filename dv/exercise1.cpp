#include <VExercise1.h>
#include <cstdio>

int main() {
  VExercise1 model;
  
  int test_count = 0;
  
  // Test all 4 operations
  for (int op = 0; op < 4; op++) {
    // Test all possible values of a and b (0-255)
    for (int a = 0; a < 256; a++) {
      for (int b = 0; b < 256; b++) {
        // Set inputs
        model.op = op;
        model.a = a;
        model.b = b;
        
        // Evaluate the model
        model.eval();
        
        // Calculate expected output
        uint8_t expected;
        bool skip_test = false;
        
        switch(op) {
          case 0: // a ^ b (XOR)
            expected = a ^ b;
            break;
            
          case 1: // a << b (left shift)
            // Mask shift amount to prevent undefined behavior
            expected = (b >= 8) ? 0 : (a << (b & 0x7));
            break;
            
          case 2: // a % b (modulo)
            if (b == 0) {
              // Division by zero - skip this test case
              skip_test = true;
            } else {
              expected = a % b;
            }
            break;
            
          case 3: // ~(a & b) (NAND)
            expected = ~(a & b);
            break;
            
          default:
            expected = 0;
        }
        
        if (skip_test) {
          continue;
        }
        
        // Check if output matches expected
        if (model.out != expected) {
          printf("FAIL: op=%d, a=%d, b=%d, expected=%d, got=%d\n", 
                 op, a, b, expected, model.out);
          return 1; // Return non-zero to indicate test failure
        }
        
        test_count++;
      }
    }
  }
  
  printf("PASS: All %d tests passed successfully!\n", test_count);
  return 0; // Return 0 to indicate test success
}

