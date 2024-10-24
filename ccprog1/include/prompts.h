/**
 * Copyright (C) 2024  Louis Raphael V. Panaligan
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

// Prevent duplicate declarations of this header file's content. ...
#ifndef CCPROG1_PROMPTS_H_
#define CCPROG1_PROMPTS_H_

#define MINIMUM_PLAYER_ID_VALUE 0
#define MAXIMUM_PLAYER_ID_VALUE 999

#define MINIMUM_INITIAL_BALANCE 1

#define MINIMUM_TARGET_PROFIT 20

#define YES_ID 'Y'
#define NO_ID 'N'

#define BUY_ACTION_ID 'B'
#define SELL_ACTION_ID 'S'
#define UPGRADE_ACTION_ID 'U'
#define NAVIGATE_ACTION_ID 'N'
#define QUIT_ACTION_ID 'Q'
#define CANCEL_ACTION_ID 'X'

#define COCONUT_CARGO_ID 'C'
#define RICE_CARGO_ID 'R'
#define SILK_CARGO_ID 'S'
#define GUN_CARGO_ID 'G'

#define TONDO_PORT_ID 'T'
#define MANILA_PORT_ID 'M'
#define PANDAKAN_PORT_ID 'P'
#define SAPA_PORT_ID 'S'

/**
 * Prompts the player to input their preferred merchant ID.
 * @returns An integer value within the range of `0` and `999`.
 * @bug Inputting a character or a string, or even just a long integer or float, as a response will result in an
 * infinite loop because the buffer cannot be cleared with any of the prescribed functions.
 */
int promptForPlayerId(void);

/**
 * Prompts the player to input the number of gold coins they want to start with.
 * @returns An integer value greater than `0`.
 * @bug Inputting a character or a string, or even just a long integer or float, as a response will result in an
 * infinite loop because the buffer cannot be cleared with any of the prescribed functions.
 */
int promptForInitialBalance(void);

/**
 * Prompts the player to input their desired profit target.
 * @returns An integer value greater than `20`.
 * @bug Inputting a character or a string, or even just a long integer or float, as a response will result in an
 * infinite loop because the buffer cannot be cleared with any of the prescribed functions.
 */
int promptForProfitTarget(void);

/**
 * Prompts the player to input a confirmation of their prior decision.
 * @returns `1` if the player confirms or `0` if they do not.
 * @bug Inputting a character or a string, or even just a long integer or float, as a response will result in an
 * infinite loop because the buffer cannot be cleared with any of the prescribed functions.
 */
int promptForConfirmation(void);

/** Prompts the player to press the enter or return key to continue the game. */
void promptForContinuation(void);

/**
 * Prompts the player to input the ID of the action they want to do.
 * @param nShipTotalCargoAmount The total amount of cargo carried by the ship.
 * @param nShipCargoLimit The maximum amount of cargo that the ship can carry.
 * @param nPlayerBalance The player's gold coin balance.
 * @param nCoconutMarketPrice The market price of coconuts.
 * @param nRiceMarketPrice The market price of rice.
 * @param nSilkMarketPrice The market price of silk.
 * @param nGunMarketPrice The market price of guns.
 * @returns A character value of `'B'` for the buy screen, `'S'` for the sell screen, `'U'` for the ship upgrade screen,
 * `'N'` for the navigation screen, or `'Q'` for quitting the game.
 */
char promptForActionId(int nShipTotalCargoAmount, int nShipCargoLimit, int nPlayerBalance, int nCoconutMarketPrice,
                       int nRiceMarketPrice, int nSilkMarketPrice, int nGunMarketPrice);

/**
 * Prompts the player to input the ID of the cargo they want to trade.
 * @param cTransactionType The type of transaction to make.
 * @pre @p cTransactionType must have a character value of either `'B'` or `'S'`.
 * @param nPlayerBalance The player's gold coin balance.
 * @param nCoconutMarketPrice The market price of coconuts.
 * @param nRiceMarketPrice The market price of rice.
 * @param nSilkMarketPrice The market price of silk.
 * @param nGunMarketPrice The market price of guns.
 * @param nShipCoconutCargoAmount The amount of coconut cargo carried by the ship.
 * @param nShipRiceCargoAmount The amount of rice cargo carried by the ship.
 * @param nShipSilkCargoAmount The amount of silk cargo carried by the ship.
 * @param nShipGunCargoAmount The amount of gun cargo carried by the ship.
 * @returns A character value of `'C'` for coconut, `'R'` for rice, `'S'` for silk, `'G'` for gun, or `'X'` for
 * returning to the main menu.
 */
char promptForCargoId(char cTransactionType, int nPlayerBalance, int nCoconutMarketPrice, int nRiceMarketPrice,
                      int nSilkMarketPrice, int nGunMarketPrice, int nShipCoconutCargoAmount, int nShipRiceCargoAmount,
                      int nShipSilkCargoAmount, int nShipGunCargoAmount);

/**
 * Prompts the player to input the amount of cargo they want to trade.
 * @param cTransactionType The type of transaction to make.
 * @pre @p cTransactionType must have a character value of either `'B'` or `'S'`.
 * @param nShipCargoLimit The maximum amount of cargo that the ship can carry.
 * @param cCargoId The ID of the traded cargo.
 * @pre @p cCargoId must have a character value of `'C'`, `'R'`, `'S'`, or `'G'`.
 * @param nPlayerBalance The player's gold coin balance.
 * @param nCoconutMarketPrice The market price of coconuts.
 * @param nRiceMarketPrice The market price of rice.
 * @param nSilkMarketPrice The market price of silk.
 * @param nGunMarketPrice The market price of guns.
 * @param nShipCoconutCargoAmount The amount of coconut cargo carried by the ship.
 * @param nShipRiceCargoAmount The amount of rice cargo carried by the ship.
 * @param nShipSilkCargoAmount The amount of silk cargo carried by the ship.
 * @param nShipGunCargoAmount The amount of gun cargo carried by the ship.
 * @returns An integer value greater than `0`.
 * @bug Inputting a character or a string, or even just a long integer or float, as a response will result in an
 * infinite loop because the buffer cannot be cleared with any of the prescribed functions.
 */
int promptForCargoAmount(char cTransactionType, int nShipCargoLimit, char cCargoId, int nPlayerBalance,
                         int nCoconutMarketPrice, int nRiceMarketPrice, int nSilkMarketPrice, int nGunMarketPrice,
                         int nShipCoconutCargoAmount, int nShipRiceCargoAmount, int nShipSilkCargoAmount,
                         int nShipGunCargoAmount);

/**
 * Prompts the player to input a confirmation on whether they want to upgrade their ship or not.
 * @param nShipCurrentCargoLimit The current maximum amount of cargo that the ship can carry.
 * @param nPlayerBalance The player's gold coin balance.
 * @returns `1` if the player wants to upgrade or `0` if they do not.
 * @bug Inputting a character or a string, or even just a long integer or float, as a response will result in an
 * infinite loop because the buffer cannot be cleared with any of the prescribed functions.
 */
int promptForShipUpgrade(int nShipCurrentCargoLimit, int nPlayerBalance);

/**
 * Prompts the player to input the ID of the port they want to navigate to.
 * @param cCurrentPortId The current port's ID.
 * @pre @p cCurrentPortId must have a character value of `'T'`, `'M'`, `'P'`, or `'S'`.
 * @returns A character value of `'T'` for Tondo, `'M'` for Manila, `'P'` for Pandakan, `'S'` for Sapa, or `'X'` for
 * returning to the main menu.
 */
char promptForPortId(char cCurrentPortId);

// ... Prevent duplicate declarations of this header file's content.
#endif  // CCPROG1_PROMPTS_H_
