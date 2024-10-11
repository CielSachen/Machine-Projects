#include <gtest/gtest.h>

#include <cstdio>

/**
 *
 * @param reopened_file
 */
void verify_file_reopening(FILE* reopened_file) {
  if (reopened_file == NULL) {
    std::cerr << "[          ] The file that contains the mocked user inputs could not be opened." << std::endl;

    exit(EXIT_FAILURE);
  }
}
