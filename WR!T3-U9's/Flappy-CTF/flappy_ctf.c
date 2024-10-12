#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define ROWS 24
#define COLS 80
#define BIRD_COL 20
#define PIPE_WIDTH 5
#define GAP_HEIGHT 6
#define FLAG_LENGTH 30
#define PIPE_SPACING 30

void setup_terminal();
void reset_terminal();
void clear_screen();
void draw_start_screen();
void draw_game_state();
void draw_game_over_screen();
void show_completion_message();
void init_game();
void update_game();
int check_collision();

char game[ROWS][COLS];
float bird_y = ROWS / 2;
float bird_velocity = 0;
int score = 0;
int pipes[3][2];

int flag[FLAG_LENGTH + 1] = {40,46,35,41,15,52,35,43,38,93,40,78,22,82,82,91,65,36,19,84,70,65,47,22,85,86,21,84,3,95,-30};

char revealed_flag[FLAG_LENGTH + 1] = {0};
int game_started = 0;

void add_30_to_flag(int flag[], int length) {
    for (int i = 0; i < length; i++) {
        flag[i] += 30;
    }
}

void setup_terminal() {
}

void reset_terminal() {
}

void clear_screen() {
    system("cls");
}

void draw_start_screen() {
    clear_screen();
    printf("\n\n");
    printf("           FFFFFF LL        AAAAAAA   PPPPPPP  PPPPPPP  YY    YY\n");
    printf("           FF     LL       AA     AA  PP    PP PP    PP  YY  YY \n");
    printf("           FFFFFF LL       AAAAAAAAA  PPPPPPP  PPPPPPP    YYYY  \n");
    printf("           FF     LL       AA     AA  PP       PP          YY   \n");
    printf("           FF     LLLLLLL  AA     AA  PP       PP          YY   \n");
    printf("\n");
    printf("                   BBBBBBB  IIIIII RRRRRR  DDDDDDD\n");
    printf("                   BB    BB   II   RR   RR DD    DD\n");
    printf("                   BBBBBBB    II   RRRRRR  DD    DD\n");
    printf("                   BB    BB   II   RR  RR  DD    DD\n");
    printf("                   BBBBBBB  IIIIII RR   RR DDDDDDD\n");
    printf("\n\n");
    printf("                     Press SPACE to start the game!\n");
    printf("\n");
    printf("                 Controls: SPACE to jump, 'q' to quit\n");
    printf("\n");
    printf("    Collect the flag characters by passing through the gaps in the pipes.\n");
    printf("                 Reveal the entire flag to win the game!\n");
}

void draw_game_state() {
    char buffer[ROWS][COLS + 1];
    memset(buffer, ' ', sizeof(buffer));
    for (int i = 0; i < 3; i++) {
        if (pipes[i][0] >= 0 && pipes[i][0] < COLS) {
            for (int j = 0; j < ROWS; j++) {
                if (j < pipes[i][1] - GAP_HEIGHT/2 || j > pipes[i][1] + GAP_HEIGHT/2) {
                    for (int k = 0; k < PIPE_WIDTH; k++) {
                        if (pipes[i][0] + k < COLS) buffer[j][pipes[i][0] + k] = '#';
                    }
                }
            }
            if (pipes[i][0] + PIPE_WIDTH/2 < COLS) {
                buffer[pipes[i][1]][pipes[i][0] + PIPE_WIDTH/2] = flag[score % FLAG_LENGTH];
            }
        }
    }
    int bird_row = (int)bird_y;
    if (bird_row >= 0 && bird_row < ROWS) buffer[bird_row][BIRD_COL] = '>';
    clear_screen();
    for (int i = 0; i < ROWS; i++) {
        buffer[i][COLS] = '\0';
        printf("%s\n", buffer[i]);
    }
    printf("Score: %d | Flag: %s\n", score, revealed_flag);
}

void draw_game_over_screen() {
    draw_game_state();
    printf("\n");
    printf("    +----------------------------+\n");
    printf("    |         GAME OVER!         |\n");
    printf("    |      Final Score: %-3d      |\n", score);
    printf("    |    Press 'r' to restart    |\n");
    printf("    |     Press 'q' to quit      |\n");
    printf("    +----------------------------+\n");
    fflush(stdout);
}

void show_completion_message() {
    draw_game_state();
    printf("\n");
    printf("    ===============================================\n");
    printf("     Congratulations! You've revealed the entire flag\n");
    printf("          %s\n", flag);
    printf("         You are a true Flappy Bird Master!\n");
    printf("        Press 'r' to restart or 'q' to quit.\n");
    printf("    ===============================================\n");
    fflush(stdout);
}

void init_game() {
    bird_y = ROWS / 2;
    bird_velocity = 0;
    score = 0;
    memset(revealed_flag, 0, sizeof(revealed_flag));
    for (int i = 0; i < 3; i++) {
        pipes[i][0] = COLS + i * PIPE_SPACING;
        pipes[i][1] = rand() % (ROWS - GAP_HEIGHT - 4) + GAP_HEIGHT/2 + 2;
    }
}

void update_game() {
    bird_velocity += 0.5;
    bird_y += bird_velocity * 0.5;
    for (int i = 0; i < 3; i++) {
        pipes[i][0]--;
        if (pipes[i][0] + PIPE_WIDTH < 0) {
            int rightmost = pipes[0][0];
            for (int j = 1; j < 3; j++) {
                if (pipes[j][0] > rightmost) rightmost = pipes[j][0];
            }
            pipes[i][0] = rightmost + PIPE_SPACING;
            pipes[i][1] = rand() % (ROWS - GAP_HEIGHT - 4) + GAP_HEIGHT/2 + 2;
        }
        if (pipes[i][0] == BIRD_COL) {
            score++;
            if (score <= FLAG_LENGTH) revealed_flag[score-1] = flag[score-1];
        }
    }
}

int check_collision() {
    int bird_row = (int)bird_y;
    if (bird_row < 0 || bird_row >= ROWS) return 1;
    for (int i = 0; i < 3; i++) {
        if (pipes[i][0] <= BIRD_COL && BIRD_COL < pipes[i][0] + PIPE_WIDTH) {
            if (bird_row < pipes[i][1] - GAP_HEIGHT/2 || bird_row > pipes[i][1] + GAP_HEIGHT/2) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    add_30_to_flag(flag, FLAG_LENGTH);
    setup_terminal();
    srand(time(NULL));
    while (1) {
        init_game();
        game_started = 0;
        draw_start_screen();
        while (!game_started) {
            if (_kbhit()) {
                char c = _getch();
                if (c == ' ') game_started = 1;
                if (c == 'q') {
                    reset_terminal();
                    return 0;
                }
            }
            Sleep(50);
        }
        while (1) {
            draw_game_state();
            update_game();
            if (check_collision()) {
                break;  
            }
            Sleep(90);
            if (_kbhit()) {
                char c = _getch();
                if (c == ' ') bird_velocity = -3.0;
                if (c == 'q') {
                    reset_terminal();
                    return 0;
                }
            }
        }
        draw_game_over_screen();
        if (score >= FLAG_LENGTH) {
            show_completion_message();
        }
        while (1) {
            if (_kbhit()) {
                char c = _getch();
                if (c == 'r') break;  
                if (c == 'q') {
                    reset_terminal();
                    return 0;
                }
            }
            Sleep(50);
        }
    }
    reset_terminal();
    return 0;
}