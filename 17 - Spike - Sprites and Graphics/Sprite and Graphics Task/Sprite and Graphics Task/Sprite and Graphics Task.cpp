#include <SDL.h>
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("SDL Sprites and Graphics", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    if (!window) {
        std::cerr << "Error creating SDL window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_DestroyWindow(window);
        std::cerr << "Error creating SDL renderer: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Surface* bgSurface = SDL_LoadBMP("background.bmp");
    if (!bgSurface) {
        std::cerr << "Error loading background.bmp: " << SDL_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    SDL_Texture* bgTexture = SDL_CreateTextureFromSurface(renderer, bgSurface);
    SDL_FreeSurface(bgSurface);

    SDL_Surface* tilesSurface = SDL_LoadBMP("tiles.bmp");
    if (!tilesSurface) {
        std::cerr << "Error loading tiles.bmp: " << SDL_GetError() << std::endl;
        SDL_DestroyTexture(bgTexture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    SDL_Texture* tilesTexture = SDL_CreateTextureFromSurface(renderer, tilesSurface);
    SDL_FreeSurface(tilesSurface);

    // Assuming each tile is of size 50x50 for this example
    SDL_Rect tileRects[3] = {
        {0, 0, 50, 50},
        {50, 0, 50, 50},
        {100, 0, 50, 50},
    };

    bool displayBg = true;
    bool displayTiles[3] = { false, false, false };

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }

            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                case SDLK_0:
                    displayBg = !displayBg;
                    break;
                case SDLK_1:
                case SDLK_2:
                case SDLK_3:
                    int tileIndex = event.key.keysym.sym - SDLK_1;
                    displayTiles[tileIndex] = !displayTiles[tileIndex];
                    break;
                }
            }
        }

        SDL_RenderClear(renderer);

        if (displayBg) {
            SDL_RenderCopy(renderer, bgTexture, NULL, NULL);
        }

        for (int i = 0; i < 3; i++) {
            if (displayTiles[i]) {
                SDL_Rect destRect = { rand() % 750, rand() % 550, 50, 50 }; // Random location
                SDL_RenderCopy(renderer, tilesTexture, &tileRects[i], &destRect);
            }
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(bgTexture);
    SDL_DestroyTexture(tilesTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
