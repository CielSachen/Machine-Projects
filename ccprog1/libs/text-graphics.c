/**
 * Copyright (C) 2024  Louis Raphael V. Panaligan
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "text-graphics.h"

#include <stdio.h>

#include "console.h"
#include "prompts.h"
#include "trading.h"

/** Prints out a pre-formatted separator line to the console. */
void printSeparator(void) {
  printf("\n\n\n");

  for (int nPrintedDashAmount = 0; nPrintedDashAmount < MAX_PRINT_WIDTH; nPrintedDashAmount++) printf("━");

  printf("\n\n\n\n");
}

/** Prints out the game's start screen, which contains the game's title, to the console. */
void printGameStartScreen(void) {
  printSeparator();

  printf(
    "     ███      ▄█  ████████▄     ▄████████    ▄████████       ▄██████▄     ▄████████        ▄▄▄▄███▄▄▄▄      ▄████████ ███▄▄▄▄    ▄█   ▄█          ▄████████\n"
    " ▀█████████▄ ███  ███   ▀███   ███    ███   ███    ███      ███    ███   ███    ███      ▄██▀▀▀███▀▀▀██▄   ███    ███ ███▀▀▀██▄ ███  ███         ███    ███\n"
    "    ▀███▀▀██ ███▌ ███    ███   ███    █▀    ███    █▀       ███    ███   ███    █▀       ███   ███   ███   ███    ███ ███   ███ ███▌ ███         ███    ███\n"
    "     ███   ▀ ███▌ ███    ███  ▄███▄▄▄       ███             ███    ███  ▄███▄▄▄          ███   ███   ███   ███    ███ ███   ███ ███▌ ███         ███    ███\n"
    "     ███     ███▌ ███    ███ ▀▀███▀▀▀     ▀███████████      ███    ███ ▀▀███▀▀▀          ███   ███   ███ ▀███████████ ███   ███ ███▌ ███       ▀███████████\n"
    "     ███     ███  ███    ███   ███    █▄           ███      ███    ███   ███             ███   ███   ███   ███    ███ ███   ███ ███  ███         ███    ███\n"
    "     ███     ███  ███   ▄███   ███    ███    ▄█    ███      ███    ███   ███             ███   ███   ███   ███    ███ ███   ███ ███  ███▌    ▄   ███    ███\n"
    "    ▄████▀   █▀   ████████▀    ██████████  ▄████████▀        ▀██████▀    ███              ▀█   ███   █▀    ███    █▀   ▀█   █▀  █▀   █████▄▄██   ███    █▀\n"
    "                                                                                                                                     ▀\n");

  printf("\n");

  printf(
    "                                    ▗▄▖     ▗▖  ▗▖▗▄▄▄▖▗▄▄▖  ▗▄▄▖▗▖ ▗▖ ▗▄▖ ▗▖  ▗▖▗▄▄▄▖▗▄▄▖    ▗▄▄▄▖ ▗▖ ▗▖▗▄▄▄▖ ▗▄▄▖▗▄▄▄▖\n"
    "                                   ▐▌ ▐▌    ▐▛▚▞▜▌▐▌   ▐▌ ▐▌▐▌   ▐▌ ▐▌▐▌ ▐▌▐▛▚▖▐▌  █ ▐▌       ▐▌ ▐▌ ▐▌ ▐▌▐▌   ▐▌     █\n"
    "                                   ▐▛▀▜▌    ▐▌  ▐▌▐▛▀▀▘▐▛▀▚▖▐▌   ▐▛▀▜▌▐▛▀▜▌▐▌ ▝▜▌  █  ▝▀▚▖    ▐▌ ▐▌ ▐▌ ▐▌▐▛▀▀▘ ▝▀▚▖  █\n"
    "                                   ▐▌ ▐▌    ▐▌  ▐▌▐▙▄▄▖▐▌ ▐▌▝▚▄▄▖▐▌ ▐▌▐▌ ▐▌▐▌  ▐▌  █ ▗▄▄▞▘    ▐▙▄▟▙▖▝▚▄▞▘▐▙▄▄▖▗▄▄▞▘  █\n");

  printf("\n\n\n\n\n");
}

/**
 * Prints out the game's main menu screen, which contains statistics about the player and their ship and the port's
 * cargo market prices, to the console.
 * @param nPlayerTurns The number of turns the player has exhausted.
 * @pre @p nPlayerTurns must have a positive integer value less than or equal to `29`.
 * @param cPortId The port's ID.
 * @pre @p cPortId must have a character value of either `'T'`, `'M'`, `'P'`, or `'S'`.
 * @param nPlayerId The player's merchant ID.
 * @param nPlayerBalance The player's gold coin balance.
 * @param nPlayerProfit The player's profit percentage.
 * @param nPlayerProfitTarget The player's target profit percentage.
 * @param nShipTotalCargoAmount The total amount of cargo carried by the ship.
 * @param nShipCargoLimit The maximum amount of cargo that the ship can carry.
 * @param nShipCoconutCargoAmount The amount of coconut cargo carried by the ship.
 * @param nShipRiceCargoAmount The amount of rice cargo carried by the ship.
 * @param nShipSilkCargoAmount The amount of silk cargo carried by the ship.
 * @param nShipGunCargoAmount The amount of gun cargo carried by the ship.
 * @param nCoconutMarketPrice The market price of coconuts.
 * @param nRiceMarketPrice The market price of rice.
 * @param nSilkMarketPrice The market price of silk.
 * @param nGunMarketPrice The market price of guns.
 */
void printMainScreen(int nPlayerTurns, char cPortId, int nPlayerId, int nPlayerBalance, int nPlayerProfit,
                     int nPlayerProfitTarget, int nShipTotalCargoAmount, int nShipCargoLimit,
                     int nShipCoconutCargoAmount, int nShipRiceCargoAmount, int nShipSilkCargoAmount,
                     int nShipGunCargoAmount, int nCoconutMarketPrice, int nRiceMarketPrice, int nSilkMarketPrice,
                     int nGunMarketPrice) {
  printSeparator();

  switch (cPortId) {
    case 'T': {
      printf(
        "                                                        ████████  ██████  ███    ██ ██████   ██████\n"
        "                                                           ██    ██    ██ ████   ██ ██   ██ ██    ██\n"
        "                                                           ██    ██    ██ ██ ██  ██ ██   ██ ██    ██\n"
        "                                                           ██    ██    ██ ██  ██ ██ ██   ██ ██    ██\n"
        "                                                           ██     ██████  ██   ████ ██████   ██████\n");

      break;
    }
    case 'M': {
      printf(
        "                                                      ███    ███  █████  ███    ██ ██ ██       █████\n"
        "                                                      ████  ████ ██   ██ ████   ██ ██ ██      ██   ██\n"
        "                                                      ██ ████ ██ ███████ ██ ██  ██ ██ ██      ███████\n"
        "                                                      ██  ██  ██ ██   ██ ██  ██ ██ ██ ██      ██   ██\n"
        "                                                      ██      ██ ██   ██ ██   ████ ██ ███████ ██   ██\n");

      break;
    }
    case 'P': {
      printf(
        "                                            ██████   █████  ███    ██ ██████   █████  ██   ██  █████  ███    ██\n"
        "                                            ██   ██ ██   ██ ████   ██ ██   ██ ██   ██ ██  ██  ██   ██ ████   ██\n"
        "                                            ██████  ███████ ██ ██  ██ ██   ██ ███████ █████   ███████ ██ ██  ██\n"
        "                                            ██      ██   ██ ██  ██ ██ ██   ██ ██   ██ ██  ██  ██   ██ ██  ██ ██\n"
        "                                            ██      ██   ██ ██   ████ ██████  ██   ██ ██   ██ ██   ██ ██   ████\n");

      break;
    }
    case 'S': {
      printf(
        "                                                                   ███████  █████  ██████   █████\n"
        "                                                                   ██      ██   ██ ██   ██ ██   ██\n"
        "                                                                   ███████ ███████ ██████  ███████\n"
        "                                                                        ██ ██   ██ ██      ██   ██\n"
        "                                                                   ███████ ██   ██ ██      ██   ██\n");

      break;
    }
  }

  printf("\n\n");

  printf(
    "   • Merchant ID: %3d                                                                                              • Balance: %d Gold Coins\n"
    "   • Profit:",
    nPlayerId, nPlayerBalance);

  if (nPlayerProfit >= nPlayerProfitTarget) {
    setConsoleColorToGreen();
  } else {
    setConsoleColorToRed();
  }

  printf(" %d%%\n", nPlayerProfit);
  resetConsoleColor();

  printf("   • Target Profit %d%%\n", nPlayerProfitTarget);

  printf("\n\n");

  if (nShipCargoLimit <= TIER_ONE_SHIP_CARGO_LIMIT) {
    printf(
      "                                                               ~~~\n"
      "                                                          ~~~~     ~~~~        |\n"
      "                                                               ~~~            /|\n"
      "                                                                             / |\\\n"
      "                                                                            /  | \\\n"
      "                                                                           /   |  \\\n"
      "                                                                          /    |   \\\n"
      "                                                                         /     |____\\\n"
      "                                                                   _____/______|_________\n"
      "                                                                    \\__________________/\n"
      "                                                            ~~..             ...~~~.           ....~~~...\n");
  } else if (nShipCargoLimit <= TIER_TWO_SHIP_CARGO_LIMIT) {
    printf(
      "                                                          ~~~\n"
      "                                                     ~~~~     ~~~~       |\n"
      "                                                          ~~~          -----        |\n"
      "                                                                       )___(        |\\\n"
      "                                                                         |          | \\\n"
      "                                                                      -------       |  \\\n"
      "                                                                     /       \\      |   \\\n"
      "                                                                    /_________\\     |____\\\n"
      "                                                              ___________|__________|_________\n"
      "                                                               \\____________________________/\n"
      "                                                       ~~..             ...~~~.           ....~~~...     ..~\n");
  } else if (nShipCargoLimit <= TIER_THREE_SHIP_CARGO_LIMIT) {
    printf(
      "                                                      ~~~             |\n"
      "                                                 ~~~~     ~~~~      -----              |\n"
      "                                                      ~~~           )___(            -----\n"
      "                                                                      |              )___(\n"
      "                                                                  ---------            |\n"
      "                                                                 /         \\        -------\n"
      "                                                                /           \\      /       \\\n"
      "                                                               /_____________\\    /_________\\\n"
      "                                                          ____________|________________|__________\n"
      "                                                           \\_                                  _/\n"
      "                                                             \\________________________________/\n"
      "                                                   ~~..             ...~~~.           ....~~~...     ..~\n");
  } else {
    printf(
      "                                                   ~~~             |\n"
      "                                              ~~~~     ~~~~      -----                    |\n"
      "                                                   ~~~           )___(                  -----\n"
      "                                                                   |                    )___(\n"
      "                                                               ---------                  |\n"
      "                                                              /         \\              -------\n"
      "                                                             /___________\\            /       \\\n"
      "                                                                   |                 /_________\\\n"
      "                                                            ---------------               |\n"
      "                                                           /               \\        -------------\n"
      "                                                          /                 \\      /             \\\n"
      "                                                         /___________________\\    /_______________\\\n"
      "                                                       ____________|______________________|__________\n"
      "                                                        \\_                                        _/\n"
      "                                                          \\______________________________________/\n"
      "                                                   ~~..             ...~~~.           ....~~~...     ..~\n");
  }

  printf("\n\n");

  printf(
    "   ║                                    ║                                                                          ║                                    ║\n"
    " ==X====================================X==                                                                      ==X====================================X==\n"
    "   ║    Total Cargo    |   %3d of %3d   ║                                                                          ║   Market Prices   |  Day %2d of 29  ║\n"
    "   ║----------- ------- -------- -------║                                                                          ║------------------- ----------------║\n"
    "   ║  Coconut  |  %3d  |  Silk  |  %3d  ║                                                                          ║  Coconut  |  %3d  |  Silk  |  %3d  ║\n"
    "   ║  Rice     |  %3d  |  Gun   |  %3d  ║                                                                          ║  Rice     |  %3d  |  Gun   |  %3d  ║\n"
    " ==X====================================X==                                                                      ==X====================================X==\n"
    "   ║                                    ║                                                                          ║                                    ║\n",
    nShipTotalCargoAmount, nShipCargoLimit, nPlayerTurns, nShipCoconutCargoAmount, nShipSilkCargoAmount,
    nCoconutMarketPrice, nSilkMarketPrice, nShipRiceCargoAmount, nShipGunCargoAmount, nRiceMarketPrice,
    nGunMarketPrice);

  printf("\n\n\n");
}

/**
 * Prints out the game's transaction screen, which contains the name of the cargo that the player traded and the number
 * of gold coins the player has spent or earned, to the console.
 * @param cTransactionType The type of transaction made.
 * @pre @p cTransactionType must have a character value of either `'B'` or `'S'`.
 * @param cCargoId The ID of the traded cargo.
 * @pre @p cCargoId must have a character value of either `'C'`, `'R'`, `'S'`, or `'G'`.
 * @param nCargoAmount The amount of cargo to trade.
 * @param nCargoPrice The price of the cargo.
 */
void printTransactionScreen(char cTransactionType, char cCargoId, int nCargoAmount, int nCargoPrice) {
  printSeparator();

  int nLeftPaddingSize;

  setConsoleColorToGreen();

  switch (cCargoId) {
    case 'C': {
      if (cTransactionType == BUY_ACTION_ID) {
        printf(
          "                                         ▗▄▄▖ ▗▄▖  ▗▄▄▖ ▗▄▖ ▗▖  ▗▖▗▖ ▗▖▗▄▄▄▖ ▗▄▄▖    ▗▄▄▖  ▗▄▖ ▗▖ ▗▖ ▗▄▄▖▗▖ ▗▖▗▄▄▄▖\n"
          "                                        ▐▌   ▐▌ ▐▌▐▌   ▐▌ ▐▌▐▛▚▖▐▌▐▌ ▐▌  █  ▐▌       ▐▌ ▐▌▐▌ ▐▌▐▌ ▐▌▐▌   ▐▌ ▐▌  █\n"
          "                                        ▐▌   ▐▌ ▐▌▐▌   ▐▌ ▐▌▐▌ ▝▜▌▐▌ ▐▌  █   ▝▀▚▖    ▐▛▀▚▖▐▌ ▐▌▐▌ ▐▌▐▌▝▜▌▐▛▀▜▌  █\n"
          "                                        ▝▚▄▄▖▝▚▄▞▘▝▚▄▄▖▝▚▄▞▘▐▌  ▐▌▝▚▄▞▘  █  ▗▄▄▞▘    ▐▙▄▞▘▝▚▄▞▘▝▚▄▞▘▝▚▄▞▘▐▌ ▐▌  █\n");
        resetConsoleColor();

        printf("\n\n");

        nLeftPaddingSize = 40;

        setConsoleColorToGreen();
        printf("%*c• You added %d coconuts to the ship's storage!\n", nLeftPaddingSize, ' ', nCargoAmount);
        resetConsoleColor();
      } else {
        printf(
          "                                              ▗▄▄▖ ▗▄▖  ▗▄▄▖ ▗▄▖ ▗▖  ▗▖▗▖ ▗▖▗▄▄▄▖ ▗▄▄▖     ▗▄▄▖ ▗▄▖ ▗▖   ▗▄▄▄ \n"
          "                                             ▐▌   ▐▌ ▐▌▐▌   ▐▌ ▐▌▐▛▚▖▐▌▐▌ ▐▌  █  ▐▌       ▐▌   ▐▌ ▐▌▐▌   ▐▌  █\n"
          "                                             ▐▌   ▐▌ ▐▌▐▌   ▐▌ ▐▌▐▌ ▝▜▌▐▌ ▐▌  █   ▝▀▚▖     ▝▀▚▖▐▌ ▐▌▐▌   ▐▌  █\n"
          "                                             ▝▚▄▄▖▝▚▄▞▘▝▚▄▄▖▝▚▄▞▘▐▌  ▐▌▝▚▄▞▘  █  ▗▄▄▞▘    ▗▄▄▞▘▝▚▄▞▘▐▙▄▄▖▐▙▄▄▀\n");
        resetConsoleColor();

        printf("\n\n");

        nLeftPaddingSize = 45;

        setConsoleColorToRed();
        printf("%*c• You removed %d coconuts from the ship's storage!\n", nLeftPaddingSize, ' ', nCargoAmount);
        resetConsoleColor();
      }

      break;
    }
    case 'R': {
      if (cTransactionType == BUY_ACTION_ID) {
        printf(
          "                                                   ▗▄▄▖ ▗▄▄▄▖ ▗▄▄▖▗▄▄▄▖    ▗▄▄▖  ▗▄▖ ▗▖ ▗▖ ▗▄▄▖▗▖ ▗▖▗▄▄▄▖\n"
          "                                                   ▐▌ ▐▌  █  ▐▌   ▐▌       ▐▌ ▐▌▐▌ ▐▌▐▌ ▐▌▐▌   ▐▌ ▐▌  █\n"
          "                                                   ▐▛▀▚▖  █  ▐▌   ▐▛▀▀▘    ▐▛▀▚▖▐▌ ▐▌▐▌ ▐▌▐▌▝▜▌▐▛▀▜▌  █\n"
          "                                                   ▐▌ ▐▌▗▄█▄▖▝▚▄▄▖▐▙▄▄▖    ▐▙▄▞▘▝▚▄▞▘▝▚▄▞▘▝▚▄▞▘▐▌ ▐▌  █\n");
        resetConsoleColor();

        printf("\n\n");

        nLeftPaddingSize = 51;

        setConsoleColorToGreen();
        printf("%*c• You added %d rice to the ship's storage!\n", nLeftPaddingSize, ' ', nCargoAmount);
        resetConsoleColor();
      } else {
        printf(
          "                                                        ▗▄▄▖ ▗▄▄▄▖ ▗▄▄▖▗▄▄▄▖     ▗▄▄▖ ▗▄▖ ▗▖   ▗▄▄▄ \n"
          "                                                        ▐▌ ▐▌  █  ▐▌   ▐▌       ▐▌   ▐▌ ▐▌▐▌   ▐▌  █\n"
          "                                                        ▐▛▀▚▖  █  ▐▌   ▐▛▀▀▘     ▝▀▚▖▐▌ ▐▌▐▌   ▐▌  █\n"
          "                                                        ▐▌ ▐▌▗▄█▄▖▝▚▄▄▖▐▙▄▄▖    ▗▄▄▞▘▝▚▄▞▘▐▙▄▄▖▐▙▄▄▀\n");
        resetConsoleColor();

        printf("\n\n");

        nLeftPaddingSize = 56;

        setConsoleColorToRed();
        printf("%*c• You removed %d rice from the ship's storage!\n", nLeftPaddingSize, ' ', nCargoAmount);
        resetConsoleColor();
      }

      break;
    }
    case 'S': {
      if (cTransactionType == BUY_ACTION_ID) {
        printf(
          "                                                    ▗▄▄▖▗▄▄▄▖▗▖   ▗▖ ▗▖    ▗▄▄▖  ▗▄▖ ▗▖ ▗▖ ▗▄▄▖▗▖ ▗▖▗▄▄▄▖\n"
          "                                                   ▐▌     █  ▐▌   ▐▌▗▞▘    ▐▌ ▐▌▐▌ ▐▌▐▌ ▐▌▐▌   ▐▌ ▐▌  █\n"
          "                                                    ▝▀▚▖  █  ▐▌   ▐▛▚▖     ▐▛▀▚▖▐▌ ▐▌▐▌ ▐▌▐▌▝▜▌▐▛▀▜▌  █\n"
          "                                                   ▗▄▄▞▘▗▄█▄▖▐▙▄▄▖▐▌ ▐▌    ▐▙▄▞▘▝▚▄▞▘▝▚▄▞▘▝▚▄▞▘▐▌ ▐▌  █\n");
        resetConsoleColor();

        printf("\n\n");

        nLeftPaddingSize = 51;

        setConsoleColorToGreen();
        printf("%*c• You added %d silk to the ship's storage!\n", nLeftPaddingSize, ' ', nCargoAmount);
        resetConsoleColor();
      } else {
        printf(
          "                                                         ▗▄▄▖▗▄▄▄▖▗▖   ▗▖ ▗▖     ▗▄▄▖ ▗▄▖ ▗▖   ▗▄▄▄ \n"
          "                                                        ▐▌     █  ▐▌   ▐▌▗▞▘    ▐▌   ▐▌ ▐▌▐▌   ▐▌  █\n"
          "                                                         ▝▀▚▖  █  ▐▌   ▐▛▚▖      ▝▀▚▖▐▌ ▐▌▐▌   ▐▌  █\n"
          "                                                        ▗▄▄▞▘▗▄█▄▖▐▙▄▄▖▐▌ ▐▌    ▗▄▄▞▘▝▚▄▞▘▐▙▄▄▖▐▙▄▄▀\n");
        resetConsoleColor();

        printf("\n\n");

        nLeftPaddingSize = 56;

        setConsoleColorToRed();
        printf("%*c• You removed %d silk from the ship's storage!\n", nLeftPaddingSize, ' ', nCargoAmount);
        resetConsoleColor();
      }

      break;
    }
    // Set to default instead of 'G' to satisfy the compiler
    default: {
      if (cTransactionType == BUY_ACTION_ID) {
        printf(
          "                                                   ▗▄▄▖▗▖ ▗▖▗▖  ▗▖ ▗▄▄▖    ▗▄▄▖  ▗▄▖ ▗▖ ▗▖ ▗▄▄▖▗▖ ▗▖▗▄▄▄▖\n"
          "                                                  ▐▌   ▐▌ ▐▌▐▛▚▖▐▌▐▌       ▐▌ ▐▌▐▌ ▐▌▐▌ ▐▌▐▌   ▐▌ ▐▌  █\n"
          "                                                  ▐▌▝▜▌▐▌ ▐▌▐▌ ▝▜▌ ▝▀▚▖    ▐▛▀▚▖▐▌ ▐▌▐▌ ▐▌▐▌▝▜▌▐▛▀▜▌  █\n"
          "                                                  ▝▚▄▞▘▝▚▄▞▘▐▌  ▐▌▗▄▄▞▘    ▐▙▄▞▘▝▚▄▞▘▝▚▄▞▘▝▚▄▞▘▐▌ ▐▌  █\n");
        resetConsoleColor();

        printf("\n\n");

        nLeftPaddingSize = 50;

        setConsoleColorToGreen();
        printf("%*c• You added %d guns to the ship's storage!\n", nLeftPaddingSize, ' ', nCargoAmount);
        resetConsoleColor();
      } else {
        printf(
          "                                                        ▗▄▄▖▗▖ ▗▖▗▖  ▗▖ ▗▄▄▖     ▗▄▄▖ ▗▄▖ ▗▖   ▗▄▄▄ \n"
          "                                                       ▐▌   ▐▌ ▐▌▐▛▚▖▐▌▐▌       ▐▌   ▐▌ ▐▌▐▌   ▐▌  █\n"
          "                                                       ▐▌▝▜▌▐▌ ▐▌▐▌ ▝▜▌ ▝▀▚▖     ▝▀▚▖▐▌ ▐▌▐▌   ▐▌  █\n"
          "                                                       ▝▚▄▞▘▝▚▄▞▘▐▌  ▐▌▗▄▄▞▘    ▗▄▄▞▘▝▚▄▞▘▐▙▄▄▖▐▙▄▄▀\n");
        resetConsoleColor();

        printf("\n\n");

        nLeftPaddingSize = 55;

        setConsoleColorToRed();
        printf("%*c• You removed %d guns from the ship's storage!\n", nLeftPaddingSize, ' ', nCargoAmount);
        resetConsoleColor();
      }

      break;
    }
  }

  if (cTransactionType == BUY_ACTION_ID) {
    setConsoleColorToRed();
    printf("%*c• You spent %d gold coins!\n", nLeftPaddingSize, ' ', nCargoPrice * nCargoAmount);
    resetConsoleColor();
  } else {
    setConsoleColorToGreen();
    printf("%*c• You earned %d gold coins!\n", nLeftPaddingSize, ' ', nCargoPrice * nCargoAmount);
    resetConsoleColor();
  }

  printf("\n\n\n\n\n");
}

/**
 * Prints out the game's ship upgrade screen, which contains the number of additional cargo spaces the ship has received
 * and gold coins the player has spent, to the console.
 * @param nShipCargoLimitIncrease The amount of additional cargo space the ship has gotten.
 * @param nShipUpgradeCost The price of the ship upgrade.
 */
void printShipUpgradeScreen(int nShipCargoLimitIncrease, int nShipUpgradeCost) {
  printSeparator();

  setConsoleColorToGreen();
  printf(
    "                                               ▗▄▄▖▗▖ ▗▖▗▄▄▄▖▗▄▄▖     ▗▖ ▗▖▗▄▄▖  ▗▄▄▖▗▄▄▖  ▗▄▖ ▗▄▄▄ ▗▄▄▄▖▗▄▄▄\n"
    "                                              ▐▌   ▐▌ ▐▌  █  ▐▌ ▐▌    ▐▌ ▐▌▐▌ ▐▌▐▌   ▐▌ ▐▌▐▌ ▐▌▐▌  █▐▌   ▐▌  █\n"
    "                                               ▝▀▚▖▐▛▀▜▌  █  ▐▛▀▘     ▐▌ ▐▌▐▛▀▘ ▐▌▝▜▌▐▛▀▚▖▐▛▀▜▌▐▌  █▐▛▀▀▘▐▌  █\n"
    "                                              ▗▄▄▞▘▐▌ ▐▌▗▄█▄▖▐▌       ▝▚▄▞▘▐▌   ▝▚▄▞▘▐▌ ▐▌▐▌ ▐▌▐▙▄▄▀▐▙▄▄▖▐▙▄▄▀\n");
  resetConsoleColor();

  printf("\n\n");

  int nLeftPaddingSize = 46;

  setConsoleColorToGreen();
  printf("%*c• You gained %d additional cargo spaces!\n", nLeftPaddingSize, ' ', nShipCargoLimitIncrease);
  resetConsoleColor();

  setConsoleColorToRed();
  printf("%*c• You spent %d gold coins!\n", nLeftPaddingSize, ' ', nShipUpgradeCost);
  resetConsoleColor();

  printf("\n\n\n\n\n");
}

/**
 * Prints out the game's navigation screen, which contains the new port the player navigated to and the new day count,
 * to the console.
 * @param cPortId The port's ID.
 * @pre @p cPortId must have a character value of either `'T'`, `'M'`, `'P'`, or `'S'`.
 * @param nPlayerTurns The number of turns the player has exhausted.
 * @pre @p nPlayerTurns must have a a 2-digit positive integer value.
 */
void printNavigationScreen(char cPortID, int nPlayerTurns) {
  printSeparator();

  setConsoleColorToGreen();
  printf(
    "                                               ▗▄▄▖▗▖ ▗▖ ▗▄▖ ▗▖  ▗▖ ▗▄▄▖▗▄▄▄▖▗▄▄▄     ▗▄▄▖  ▗▄▖ ▗▄▄▖▗▄▄▄▖▗▄▄▖\n"
    "                                              ▐▌   ▐▌ ▐▌▐▌ ▐▌▐▛▚▖▐▌▐▌   ▐▌   ▐▌  █    ▐▌ ▐▌▐▌ ▐▌▐▌ ▐▌ █ ▐▌\n"
    "                                              ▐▌   ▐▛▀▜▌▐▛▀▜▌▐▌ ▝▜▌▐▌▝▜▌▐▛▀▀▘▐▌  █    ▐▛▀▘ ▐▌ ▐▌▐▛▀▚▖ █  ▝▀▚▖\n"
    "                                              ▝▚▄▄▖▐▌ ▐▌▐▌ ▐▌▐▌  ▐▌▝▚▄▞▘▐▙▄▄▖▐▙▄▄▀    ▐▌   ▝▚▄▞▘▐▌ ▐▌ █ ▗▄▄▞▘\n");
  resetConsoleColor();

  printf("\n\n");

  if (cPortID == 'T') {
    printf("%*cYou have navigated to the port of Tondo!\n", 58, ' ');
  } else if (cPortID == 'M') {
    printf("%*cYou have navigated to the port of Manila!\n", 57, ' ');
  } else if (cPortID == 'P') {
    printf("%*cYou have navigated to the port of Pandakan!\n", 56, ' ');
  } else {
    printf("%*cYou have navigated to the port of Sapa!\n", 58, ' ');
  }

  printf("\n");

  printf("%*cDay %2d → Day %2d", 70, ' ', nPlayerTurns, nPlayerTurns + 1);

  printf("\n\n\n\n\n");
}

/**
 * Prints out the game's end screen, which contains the player's final statistics, to the console.
 * @param nPlayerFinalProfit The player's final profit percentage.
 * @param nPlayerProfitTarget The player's target profit percentage.
 * @param nPlayerFinalBalance The player's final gold coin balance.
 * @param nPlayerInitialBalance The player's inital gold coin balance.
 * @param nPlayerFinalTurns The number of turns the player has exhausted.
 */
void printGameEndScreen(int nPlayerFinalProfit, int nPlayerProfitTarget, int nPlayerFinalBalance,
                        int nPlayerInitialBalance, int nPlayerFinalTurns) {
  printSeparator();

  int nLeftPaddingSize;

  if (nPlayerFinalProfit >= nPlayerProfitTarget) {
    setConsoleColorToYellow();
    printf(
      "                                              ██╗   ██╗ ██████╗ ██╗   ██╗    ██╗    ██╗ ██████╗ ███╗   ██╗██╗\n"
      "                                              ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║    ██║██╔═══██╗████╗  ██║██║\n"
      "                                               ╚████╔╝ ██║   ██║██║   ██║    ██║ █╗ ██║██║   ██║██╔██╗ ██║██║\n"
      "                                                ╚██╔╝  ██║   ██║██║   ██║    ██║███╗██║██║   ██║██║╚██╗██║╚═╝\n"
      "                                                 ██║   ╚██████╔╝╚██████╔╝    ╚███╔███╔╝╚██████╔╝██║ ╚████║██╗\n"
      "                                                 ╚═╝    ╚═════╝  ╚═════╝      ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═══╝╚═╝\n");

    printf("\n");

    printf(
      "                                                                       ___________\n"
      "                                                                      '._==_==_=_.'\n"
      "                                                                      .-\\:      /-.\n"
      "                                                                      | (|:.    ) |\n"
      "                                                                      '-|:.     |-'\n"
      "                                                                        \\::.    /\n"
      "                                                                         '::. .'\n"
      "                                                                           ) (\n"
      "                                                                         _.' '._\n"
      "                                                                        `\"\"\"\"\"\"\"`\n");
    resetConsoleColor();

    printf("\n\n");

    nLeftPaddingSize = 46;
  } else {
    setConsoleColorToRed();
    printf(
      "                                            ██╗   ██╗ ██████╗ ██╗   ██╗    ██╗      ██████╗ ███████╗████████╗██╗\n"
      "                                            ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║     ██╔═══██╗██╔════╝╚══██╔══╝██║\n"
      "                                             ╚████╔╝ ██║   ██║██║   ██║    ██║     ██║   ██║███████╗   ██║   ██║\n"
      "                                              ╚██╔╝  ██║   ██║██║   ██║    ██║     ██║   ██║╚════██║   ██║   ╚═╝\n"
      "                                               ██║   ╚██████╔╝╚██████╔╝    ███████╗╚██████╔╝███████║   ██║   ██╗\n"
      "                                               ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝ ╚═════╝ ╚══════╝   ╚═╝   ╚═╝\n");
    resetConsoleColor();

    printf("\n\n");

    nLeftPaddingSize = 44;
  }

  printf("%*c• Final profit made:", nLeftPaddingSize, ' ');

  if (nPlayerFinalProfit >= nPlayerProfitTarget) {
    setConsoleColorToGreen();
  } else {
    setConsoleColorToRed();
  }

  printf(" %d%% (%d gold coins)\n", nPlayerFinalProfit, nPlayerFinalBalance - nPlayerInitialBalance);
  resetConsoleColor();

  printf("%*c• Number of turns (days) exhausted: %d\n", nLeftPaddingSize, ' ', nPlayerFinalTurns);

  printf("\n\n\n");
}
