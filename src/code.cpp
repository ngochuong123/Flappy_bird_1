#include "toancuc.h"
#include "cacham.h"
#include "code.h"

void nhap_du_lieu(){
    window = initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    renderer = createRenderer(window);

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer Error: %s\n", Mix_GetError());
        exit(1);
    }
    if (TTF_Init() == -1) {
        SDL_Log("Không thể khởi tạo SDL_ttf: %s", TTF_GetError());
        exit(1);
    }
    diemso = TTF_OpenFont("C:/Users/User/Desktop/game/src/chu/Washington.ttf", 24);
    nhay = Mix_LoadWAV("C:/Users/User/Desktop/game/src/amthanh/nhay.wav");
    va   = Mix_LoadWAV("C:/Users/User/Desktop/game/src/amthanh/va.wav");
    nen_nhac = Mix_LoadMUS("C:/Users/User/Desktop/game/src/amthanh/nen.mp3");
    background = loadTexture("C:/Users/User/Desktop/game/src/image/backround1.png", renderer);
    SDL_QueryTexture(background, NULL, NULL, &backgroundWidth, &backgroundHeight);
    menu = loadTexture("C:/Users/User/Desktop/game/src/image/22.png", renderer);
    start = loadTexture("C:/Users/User/Desktop/game/src/image/start.png", renderer);

    hinh_anh_player("C:/Users/User/Desktop/game/src/image/cot1.png" , &cotTop , 129, 193, 212);
    hinh_anh_player("C:/Users/User/Desktop/game/src/image/cot1.png" , &cotBot , 129, 193, 212);
    hinh_anh_player("C:/Users/User/Desktop/game/src/image/player1.png" , &player1 , Red, Green, Blue);
    hinh_anh_player("C:/Users/User/Desktop/game/src/image/player2.png" , &player2 , Red, Green, Blue);

    hinh_anh_player("C:/Users/User/Desktop/game/src/image/gameover.png", &gameover, Red1, Green1, Blue1 );
    restart = loadTexture("C:/Users/User/Desktop/game/src/image/restart.png", renderer);

    player = player1;
    startRect = {startX , startY, startW, startH };
    restartRect = {restartX, restartY, restartW, restartH};
    chuyen_canh = menu;
    return;
}