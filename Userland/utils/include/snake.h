/******************************************************************************
 *
 * @file    snake.h
 *
 * @brief   Snake, the game.
 *
 * @author  Luca Pugliese                           <lpugliese@itba.edu.ar>
 * @author  Felipes Venturino                        <fventurino@itba.edu.ar>
 * @author  Uriel Sosa Vazquez                      <usosavazquez@itba.edu.ar>
 *
 ******************************************************************************/

#ifndef SNAKE_H
#define SNAKE_H

#include <stdint.h>
#include <colors.h>

#define BOARD_SIZE 32



typedef struct player * player_t;
typedef struct controller controller_t;
typedef struct snake_body snake_body_t;
typedef struct snake snake_t;
typedef struct food food_t;
typedef struct block block_t;

/*
 * LOGIC FUNCTIONS
 */
void snake();
void game(player_t player1, player_t player2);
void init_player(player_t player, color_t color, controller_t controller);
void main_menu();
void gameover_menu();
void move_player(player_t player1, player_t player2);
void update_position(player_t player, uint8_t dir);
void food();
void check_collision(player_t player);
void increment_length(player_t player);

void update_points(player_t player);
void delete_snake(player_t player);

/* 
 * UI FUNCTIONS
 */
void draw_game(player_t player1, player_t player2);
void draw_board(color_t color, uint16_t size, uint64_t x, uint64_t y);
void hud(player_t player1, player_t player2);
void kill_snake(player_t player);

#endif
