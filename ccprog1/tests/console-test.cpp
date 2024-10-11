extern "C" {
#include "console.h"
}

#include <gtest/gtest.h>

#include "utils.cpp"

const int left_padding_size = 1;

// getIntegerInput()
TEST(GetIntegerInputTest, ReturnsGivenInteger) {
  // Mock a user inputting an integer response of 100.
  FILE* mock_inputs_file = freopen("mocks/integer.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  int given_integer = getIntegerInput(left_padding_size);

  fclose(mock_inputs_file);

  EXPECT_EQ(given_integer, 100);
}

TEST(GetIntegerInputTest, HandlesNegativeIntegers) {
  // Mock a user inputting an integer response of -1.
  FILE* mock_inputs_file = freopen("mocks/integer.negative.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  int given_integer = getIntegerInput(left_padding_size);

  fclose(mock_inputs_file);

  EXPECT_EQ(given_integer, -1);
}

TEST(GetIntegerInputTest, TruncatesFloatsIntoIntegers) {
  // Mock a user inputting an integer response of 99.99.
  FILE* mock_inputs_file = freopen("mocks/float.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  int given_integer = getIntegerInput(left_padding_size);

  fclose(mock_inputs_file);

  EXPECT_EQ(given_integer, 99);
}

// getCharacterInput()
TEST(GetCharacterInputTest, ReturnsGivenCharacter) {
  // Mock a user inputting a character response of 'A.'
  FILE* mock_inputs_file = freopen("mocks/character.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  int given_character = getCharacterInput(left_padding_size);

  fclose(mock_inputs_file);

  EXPECT_EQ(given_character, 'A');
}

TEST(GetCharacterInputTest, HandlesIntegerCharacters) {
  // Mock a user inputting a character response of '1.'
  FILE* mock_inputs_file = freopen("mocks/integer.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  int given_character = getCharacterInput(left_padding_size);

  fclose(mock_inputs_file);

  EXPECT_EQ(given_character, '1');
}

TEST(GetCharacterInputTest, TruncatesStringsIntoCharacters) {
  // Mock a user inputting a character response of "ABCD."
  FILE* mock_inputs_file = freopen("mocks/string.txt", "r", stdin);

  verify_file_reopening(mock_inputs_file);

  int given_character = getCharacterInput(left_padding_size);

  fclose(mock_inputs_file);

  EXPECT_EQ(given_character, 'A');
}
