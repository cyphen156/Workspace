#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int turn, game_over = 0, state;
    char board[][];

    welcome_message();
    init_board(board);
    turn = who_first();
    while (!game_over){
        if (turn == 1) {
            human_move(board);
            state = check(board);
        }
        else {
            computer_move(board);
            state = check(board);
        }
        draw_board(board);
        respond(state);
        toggle_turn(turn);
    }
    return 0;
}