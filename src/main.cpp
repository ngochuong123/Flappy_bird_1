#include "toancuc.h"
#include "cacham.h"
#include "code.h"

int main (int argc, char*argv[])
{
    nhap_du_lieu();
    srand(std::time(0));
    //Điều khiển
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX = e.button.x;
                int mouseY = e.button.y;
                if (chuot(mouseX, mouseY, startRect)) {
                    if (chuyen_canh == menu) {
                        chuyen_canh = background;
                        Col_H = Min + rand() % Max/2;
                        Col_H1 = Min + rand() % Max/2;
                        Mix_PlayMusic(nen_nhac, -1);
                    }
                }
                if (chuot(mouseX, mouseY, restartRect) && xoa) {
                    again = true;
                    reset(&playerX, &playerY, &Col_X, &Col_X1, &backgroundX);
                    xoa = false;
                    va_amthanh = true;
                    Col_H = Min + rand() % Max/2;
                    Col_H1 = Min + rand() % Max/2;
                    Mix_PlayMusic(nen_nhac, -1);
                    if(score > scoreMax) scoreMax = score;
                    score = 0 ;
                }
                if (again && chuyen_canh == background) {
                    playerVelocity = jumpForce;
                    Mix_PlayChannel(-1, nhay, 0);
                }
            } else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) {
                if (chuyen_canh == menu) {
                    chuyen_canh = background;
                    Col_H = Min + rand() % Max/2;
                    Col_H1 = Min + rand() % Max/2;
                    Mix_PlayMusic(nen_nhac, -1);
                }
                if (again)
                    playerVelocity = jumpForce;
                    if(va_amthanh)
                    Mix_PlayChannel(-1, nhay, 0);
            }
        }
        if (vacham(&playerX, &playerY, &Col_X, &Col_H, &Col_X1, &Col_H1)) {
            if(va_amthanh){
                Mix_PlayChannel(-1, va, 0);
            }
            va_amthanh = false;
            again = false;
            xoa = true;
            Mix_HaltMusic();
        }
        if(playerX + playerW >= Col_X && playerX <= Col_X + Col_W){
            if(!vacham(&playerX, &playerY, &Col_X, &Col_H, &Col_X1, &Col_H1) && cd1 )
                score++;
                cd1 = false;
        }else cd1 = true;
        if(playerX + playerW >= Col_X1 && playerX <= Col_X1 + Col_W){
            if(!vacham(&playerX, &playerY, &Col_X, &Col_H, &Col_X1, &Col_H1) && cd2)
                score++;
                cd2 = false;
        }else cd2 = true;
        SDL_RenderClear(renderer);
        if (chuyen_canh == menu) {
            hien_menu( menu, start, startRect);
        }
        if (chuyen_canh == background) {
            if (!again) {
                background_dung(renderer, background, backgroundWidth, &backgroundX);
                cot_dung(renderer, cotTop, cotBot, &Col_X, &Col_H, &Col_H1, &Col_X1, col_H_duoi, gap);
                player_in(renderer, player, playerX, playerY, playerW, playerH);
                hien_gameover(renderer, gameover, restart, restartRect);
                hien_diemso(score, textTexture , scoreX, scoreY, scoreW, scoreH);
                hien_diemso(scoreMax, textTexture1, scoreMX, scoreMY, scoreMW, scoreMH);
            } else {
                hanh_dong(&playerVelocity, gravity, &playerY, playerH, SCREEN_HEIGHT);
                hoat_anh(playerVelocity, &player, player1, player2);
                renderScrollingBackground(renderer, background, backgroundWidth, &backgroundX);
                player_in(renderer, player, playerX, playerY, playerW, playerH);
                cot_troi(renderer, cotTop, cotBot, &Col_X, &Col_H, &Col_H1, &Col_X1, col_H_duoi, gap);
                hien_diemso(score, textTexture, scoreX, scoreY, scoreW, scoreH);
                hien_diemso(scoreMax, textTexture1, scoreMX, scoreMY, scoreMW, scoreMH);
                SDL_Delay(delay);
            }
        }
        SDL_RenderPresent(renderer);
    }
    
    void exit();
    return 0;
}