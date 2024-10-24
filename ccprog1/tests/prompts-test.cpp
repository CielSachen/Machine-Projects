extern "C" {
#include "prompts.h"
}

#include <gtest/gtest.h>

#include "utils.cpp"

const int kTotalShipCargoAmount = 0;
const int kShipCargoLimit = 1000;
const int kPlayerBalance = 1000;
const int kCargoPrice = 1;
const char kTransactionType = 'B';
const int kShipCargoAmount = 1;
const char kCargoId = 'C';
const char kPortId = 'T';

// promptForPlayerId()
TEST(PromptForPlayerIdTest, ReturnsGivenInteger) {
  // Mock a user inputting an integer response of 100.
  FILE* mock_inputs_file = freopen("mocks/integer.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  int given_player_id = promptForPlayerId();

  fclose(mock_inputs_file);

  EXPECT_EQ(given_player_id, 100);
}

TEST(PromptForPlayerIdTest, RetriesWhenIntegerIsNegative) {
  // Mock a user inputting an integer response of -1, then 100.
  FILE* mock_inputs_file = freopen("mocks/integer.negative.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  int given_player_id = promptForPlayerId();

  fclose(mock_inputs_file);

  EXPECT_EQ(given_player_id, 100);
}

TEST(PromptForPlayerIdTest, RetriesWhenIntegerIsTooBig) {
  // Mock a user inputting an integer response of 1000, then 100.
  FILE* mock_inputs_file = freopen("mocks/integer.big.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  int given_player_id = promptForPlayerId();

  fclose(mock_inputs_file);

  EXPECT_EQ(given_player_id, 100);
}

// promptForInitialBalance()
TEST(PromptForInitialBalanceTest, ReturnsGivenInteger) {
  // Mock a user inputting an integer response of 100.
  FILE* mock_inputs_file = freopen("mocks/integer.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  int given_initial_balance = promptForInitialBalance();

  fclose(mock_inputs_file);

  EXPECT_EQ(given_initial_balance, 100);
}

TEST(PromptForInitialBalanceTest, ReturnsGivenBigInteger) {
  // Mock a user inputting an integer response of 1000.
  FILE* mock_inputs_file = freopen("mocks/integer.big.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  int given_initial_balance = promptForInitialBalance();

  fclose(mock_inputs_file);

  EXPECT_EQ(given_initial_balance, 1000);
}

TEST(PromptForInitialBalanceTest, RetriesWhenIntegerIsNegative) {
  // Mock a user inputting an integer response of -1, then 100.
  FILE* mock_inputs_file = freopen("mocks/integer.negative.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  int given_initial_balance = promptForInitialBalance();

  fclose(mock_inputs_file);

  EXPECT_EQ(given_initial_balance, 100);
}

// promptForProfitTarget()
TEST(PromptForPlayerProfitTargetTest, ReturnsGivenInteger) {
  // Mock a user inputting an integer response of 100.
  FILE* mock_inputs_file = freopen("mocks/integer.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  int given_profit_target = promptForProfitTarget();

  fclose(mock_inputs_file);

  EXPECT_EQ(given_profit_target, 100);
}

TEST(PromptForPlayerProfitTargetTest, ReturnsGivenBigInteger) {
  // Mock a user inputting an integer response of 1000.
  FILE* mock_inputs_file = freopen("mocks/integer.big.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  int given_profit_target = promptForProfitTarget();

  fclose(mock_inputs_file);

  EXPECT_EQ(given_profit_target, 1000);
}

TEST(PromptForPlayerProfitTargetTest, RetriesWhenIntegerIsLessThanTheMinimum) {
  // Mock a user inputting an integer response of 1, then 100.
  FILE* mock_inputs_file = freopen("mocks/integer.small.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  int given_profit_target = promptForProfitTarget();

  fclose(mock_inputs_file);

  EXPECT_EQ(given_profit_target, 100);
}

// promptForConfirmation
TEST(PromptForConfirmationTest, ReturnsTrue) {
  // Mock a user inputting a character response of 'Y.'
  FILE* mock_inputs_file = freopen("mocks/bool.true.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  bool is_confirmed = promptForConfirmation();

  fclose(mock_inputs_file);

  EXPECT_EQ(is_confirmed, true);
}

TEST(PromptForConfirmationTest, ReturnsFalse) {
  // Mock a user inputting a character response of 'N.'
  FILE* mock_inputs_file = freopen("mocks/bool.false.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  bool is_confirmed = promptForConfirmation();

  fclose(mock_inputs_file);

  EXPECT_EQ(is_confirmed, false);
}

TEST(PromptForConfirmationTest, RetriesWhenResponseIsAnInvalidCharacter) {
  // Mock a user inputting multiple character responses, then 'Y.'
  FILE* mock_inputs_file = freopen("mocks/bool.invalid.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  bool is_confirmed = promptForConfirmation();

  fclose(mock_inputs_file);

  EXPECT_EQ(is_confirmed, true);
}

// promptForActionId
TEST(PromptForActionIdTest, ReturnsGivenCharacter) {
  // Mock a user inputting a character response of 'B.'
  FILE* mock_inputs_file = freopen("mocks/action-id.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  char given_action_id = promptForActionId(kTotalShipCargoAmount, kShipCargoLimit, kPlayerBalance, kCargoPrice,
                                           kCargoPrice, kCargoPrice, kCargoPrice);

  fclose(mock_inputs_file);

  EXPECT_EQ(given_action_id, 'B');
}

TEST(PromptForActionIdTest, RetriesWhenResponseIsAnInvalidCharacter) {
  // Mock a user inputting multiple character responses, then 'B.'
  FILE* mock_inputs_file = freopen("mocks/action-id.invalid.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  char given_action_id = promptForActionId(kTotalShipCargoAmount, kShipCargoLimit, kPlayerBalance, kCargoPrice,
                                           kCargoPrice, kCargoPrice, kCargoPrice);

  fclose(mock_inputs_file);

  EXPECT_EQ(given_action_id, 'B');
}

TEST(PromptForActionIdTest, RetriesWhenResponseIsAnInteger) {
  // Mock a user inputting a character response of '1', then 'B.'
  FILE* mock_inputs_file = freopen("mocks/action-id.integer.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  char given_action_id = promptForActionId(kTotalShipCargoAmount, kShipCargoLimit, kPlayerBalance, kCargoPrice,
                                           kCargoPrice, kCargoPrice, kCargoPrice);

  fclose(mock_inputs_file);

  EXPECT_EQ(given_action_id, 'B');
}

// promptForCargoId
TEST(PromptForCargoIdTest, ReturnsGivenCharacter) {
  // Mock a user inputting a character response of 'C.'
  FILE* mock_inputs_file = freopen("mocks/cargo-id.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  char given_cargo_id =
    promptForCargoId(kTransactionType, kPlayerBalance, kCargoPrice, kCargoPrice, kCargoPrice, kCargoPrice,
                     kShipCargoAmount, kShipCargoAmount, kShipCargoAmount, kShipCargoAmount);

  fclose(mock_inputs_file);

  EXPECT_EQ(given_cargo_id, 'C');
}

TEST(PromptForCargoIdTest, RetriesWhenResponseIsAnInvalidCharacter) {
  // Mock a user inputting multiple character responses, then 'C.'
  FILE* mock_inputs_file = freopen("mocks/cargo-id.invalid.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  char given_cargo_id =
    promptForCargoId(kTransactionType, kPlayerBalance, kCargoPrice, kCargoPrice, kCargoPrice, kCargoPrice,
                     kShipCargoAmount, kShipCargoAmount, kShipCargoAmount, kShipCargoAmount);

  fclose(mock_inputs_file);

  EXPECT_EQ(given_cargo_id, 'C');
}

TEST(PromptForCargoIdTest, RetriesWhenResponseIsAnInteger) {
  // Mock a user inputting a character response of '1', then 'C.'
  FILE* mock_inputs_file = freopen("mocks/cargo-id.integer.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  char given_cargo_id =
    promptForCargoId(kTransactionType, kPlayerBalance, kCargoPrice, kCargoPrice, kCargoPrice, kCargoPrice,
                     kShipCargoAmount, kShipCargoAmount, kShipCargoAmount, kShipCargoAmount);

  fclose(mock_inputs_file);

  EXPECT_EQ(given_cargo_id, 'C');
}

// promptForCargoAmount
TEST(PromptForCargoAmountTest, ReturnsGivenInteger) {
  // Mock a user inputting an integer response of 100.
  FILE* mock_inputs_file = freopen("mocks/integer.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  int given_cargo_amount = promptForCargoAmount(kTransactionType, kShipCargoLimit, kCargoId, kPlayerBalance,
                                                kCargoPrice, kCargoPrice, kCargoPrice, kCargoPrice, kShipCargoAmount,
                                                kShipCargoAmount, kShipCargoAmount, kShipCargoAmount);

  fclose(mock_inputs_file);

  EXPECT_EQ(given_cargo_amount, 100);
}

TEST(PromptForCargoAmountTest, ReturnsGivenBigInteger) {
  // Mock a user inputting an integer response of 1000, then 100.
  FILE* mock_inputs_file = freopen("mocks/integer.big.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  int given_cargo_amount = promptForCargoAmount(kTransactionType, kShipCargoLimit, kCargoId, kPlayerBalance,
                                                kCargoPrice, kCargoPrice, kCargoPrice, kCargoPrice, kShipCargoAmount,
                                                kShipCargoAmount, kShipCargoAmount, kShipCargoAmount);

  fclose(mock_inputs_file);

  EXPECT_EQ(given_cargo_amount, 1000);
}

TEST(PromptForCargoAmountTest, RetriesWhenIntegerIsNegative) {
  // Mock a user inputting an integer response of -1, then 100.
  FILE* mock_inputs_file = freopen("mocks/integer.negative.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  int given_cargo_amount = promptForCargoAmount(kTransactionType, kShipCargoLimit, kCargoId, kPlayerBalance,
                                                kCargoPrice, kCargoPrice, kCargoPrice, kCargoPrice, kShipCargoAmount,
                                                kShipCargoAmount, kShipCargoAmount, kShipCargoAmount);

  fclose(mock_inputs_file);

  EXPECT_EQ(given_cargo_amount, 100);
}

// promptForShipUpgrade
TEST(PromptForShipUpgradeTest, ReturnsTrue) {
  // Mock a user inputting a character response of 'Y.'
  FILE* mock_inputs_file = freopen("mocks/bool.true.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  bool is_upgrading = promptForShipUpgrade(kShipCargoLimit, kPlayerBalance);

  fclose(mock_inputs_file);

  EXPECT_EQ(is_upgrading, true);
}

TEST(PromptForShipUpgradeTest, ReturnsFalse) {
  // Mock a user inputting a character response of 'N.'
  FILE* mock_inputs_file = freopen("mocks/bool.false.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  bool is_upgrading = promptForShipUpgrade(kShipCargoLimit, kPlayerBalance);

  fclose(mock_inputs_file);

  EXPECT_EQ(is_upgrading, false);
}

TEST(PromptForShipUpgradeTest, RetriesWhenResponseIsAnInvalidCharacter) {
  // Mock a user inputting multiple character responses, then 'Y.'
  FILE* mock_inputs_file = freopen("mocks/bool.invalid.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  bool is_upgrading = promptForShipUpgrade(kShipCargoLimit, kPlayerBalance);

  fclose(mock_inputs_file);

  EXPECT_EQ(is_upgrading, true);
}

// promptForPortId
TEST(PromptForPortIdTest, ReturnsGivenCharacter) {
  // Mock a user inputting a character response of 'M.'
  FILE* mock_inputs_file = freopen("mocks/port-id.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  char given_port_id = promptForPortId(kPortId);

  fclose(mock_inputs_file);

  EXPECT_EQ(given_port_id, 'M');
}

TEST(PromptForPortIdTest, RetriesWhenResponseIsAnInvalidCharacter) {
  // Mock a user inputting multiple character responses, then 'M.'
  FILE* mock_inputs_file = freopen("mocks/port-id.invalid.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  char given_port_id = promptForPortId(kPortId);

  fclose(mock_inputs_file);

  EXPECT_EQ(given_port_id, 'M');
}

TEST(PromptForPortIdTest, RetriesWhenResponseIsAnInteger) {
  // Mock a user inputting a character response of '1', then 'M.'
  FILE* mock_inputs_file = freopen("mocks/port-id.integer.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  char given_port_id = promptForPortId(kPortId);

  fclose(mock_inputs_file);

  EXPECT_EQ(given_port_id, 'M');
}
