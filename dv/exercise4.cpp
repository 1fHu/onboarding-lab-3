#include <cstdint>
#include <random>
#include <iostream>
#include <iomanip>
#include <bit>
#include <catch2/catch_test_macros.hpp>
#include <VExercise4.h>

TEST_CASE("Decoder") {
  VExercise4 model;
  model.alpha = 0xA5;
  model.beta = 0x3C;
  model.gamma = 0x0F;
  model.cs = 1;

  model.sel = 0;
  model.eval();
  REQUIRE(model.out == model.alpha);

  model.sel = 1;
  model.eval();
  REQUIRE(model.out == model.beta);

  model.sel = 2;
  model.eval();
  REQUIRE(model.out == model.gamma);

  model.sel = 3;
  model.eval();
  REQUIRE(model.out == (model.alpha & (model.beta | model.gamma)));

  model.cs = 0;

  model.sel = 0;
  model.eval();
  REQUIRE(model.out == 0);

  model.sel = 1;
  model.eval();
  REQUIRE(model.out == 0);

  model.sel = 2;
  model.eval();
  REQUIRE(model.out == 0);

  model.sel = 3;
  model.eval();
  REQUIRE(model.out == 0);
}

