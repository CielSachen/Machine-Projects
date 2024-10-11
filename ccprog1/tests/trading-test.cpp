extern "C" {
#include "trading.h"
}

#include <gtest/gtest.h>

#include <cstdlib>

const int kPlayerBalance = 100;
const char kCargoId = 'C';
const int kCargoAmount = 1;
const int kCargoPrice = 25;
const int kShipCargoLimit = 5;
const int kUpgradedShipCargoLimit = 10;
const int kShipUpgradeCost = 50;

// generateRandomPrice()
TEST(GenerateRandomPriceTest, ReturnsGreaterThanOrEqualToMinimum) {
  // Seed the pseudorandom number generation.
  srand(0);

  int random_price = generateRandomPrice(0, 100);

  EXPECT_GE(random_price, 0);
}

TEST(GenerateRandomPriceTest, ReturnsLessThanOrEqualToMaximum) {
  // Seed the pseudorandom number generation.
  srand(0);

  int random_price = generateRandomPrice(0, 100);

  EXPECT_LE(random_price, 100);
}

TEST(GenerateRandomPriceTest, HandlesNegativeIntegers) {
  // Seed the pseudorandom number generation.
  srand(0);

  int random_price = generateRandomPrice(-100, 0);

  EXPECT_LE(random_price, 0);
}

// tradeCargo()
TEST(TradeCargoTest, SubtractsCostFromBalance) {
  int player_balance = kPlayerBalance;
  int ship_cargo_amount = 0;
  const char transaction_type = 'B';

  tradeCargo(transaction_type, kCargoId, &player_balance, kCargoPrice, kCargoAmount, &ship_cargo_amount);

  EXPECT_EQ(player_balance, kPlayerBalance - kCargoPrice);
}

TEST(TradeCargoTest, AddsProfitToBalance) {
  int player_balance = kPlayerBalance;
  int ship_cargo_amount = 1;
  const char transaction_type = 'S';

  tradeCargo(transaction_type, kCargoId, &player_balance, kCargoPrice, kCargoAmount, &ship_cargo_amount);

  EXPECT_EQ(player_balance, kPlayerBalance + kCargoPrice);
}

TEST(TradeCargoTest, AddsCargoToStorage) {
  int player_balance = kPlayerBalance;
  const int ship_cargo_amount = 0;
  int current_ship_cargo_amount = ship_cargo_amount;
  const char transaction_type = 'B';

  tradeCargo(transaction_type, kCargoId, &player_balance, kCargoPrice, kCargoAmount, &current_ship_cargo_amount);

  EXPECT_EQ(current_ship_cargo_amount, ship_cargo_amount + kCargoAmount);
}

TEST(TradeCargoTest, SubtractsCargoFromStorage) {
  int player_balance = kPlayerBalance;
  int ship_cargo_amount = 1;
  int current_ship_cargo_amount = ship_cargo_amount;
  const char transaction_type = 'S';

  tradeCargo(transaction_type, kCargoId, &player_balance, kCargoPrice, kCargoAmount, &current_ship_cargo_amount);

  EXPECT_EQ(current_ship_cargo_amount, ship_cargo_amount - kCargoAmount);
}

// upgradeShip()
TEST(UpgradeShipTest, SubtractsCostFromBalance) {
  int player_balance = kPlayerBalance;
  int ship_cargo_limit = kShipCargoLimit;

  upgradeShip(&player_balance, kShipUpgradeCost, &ship_cargo_limit, kUpgradedShipCargoLimit);

  EXPECT_EQ(player_balance, kPlayerBalance - kShipUpgradeCost);
}

TEST(UpgradeShipTest, IncreasesCargoLimit) {
  int player_balance = kPlayerBalance;
  int ship_cargo_limit = kShipCargoLimit;

  upgradeShip(&player_balance, kShipUpgradeCost, &ship_cargo_limit, kUpgradedShipCargoLimit);

  EXPECT_EQ(ship_cargo_limit, kUpgradedShipCargoLimit);
}

TEST(UpgradeShipTest, DecreasesCargoLimit) {
  int player_balance = kPlayerBalance;
  int ship_cargo_limit = kShipCargoLimit;
  const int decreased_ship_cargo_limit = 1;

  upgradeShip(&player_balance, kShipUpgradeCost, &ship_cargo_limit, decreased_ship_cargo_limit);

  EXPECT_EQ(ship_cargo_limit, decreased_ship_cargo_limit);
}
