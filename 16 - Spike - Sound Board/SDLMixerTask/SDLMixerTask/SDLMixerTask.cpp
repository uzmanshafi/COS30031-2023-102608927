#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("SDL Soundboard", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, 0);
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

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "Error initializing SDL_mixer: " << Mix_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    Mix_Chunk* sound1 = Mix_LoadWAV("1.wav");
    Mix_Chunk* sound2 = Mix_LoadWAV("2.wav");
    Mix_Chunk* sound3 = Mix_LoadWAV("3.wav");
    Mix_Music* bgMusic = Mix_LoadMUS("4.mp3");

    if (!sound1 || !sound2 || !sound3 || !bgMusic) {
        std::cerr << "Error loading audio files: " << Mix_GetError() << std::endl;
        Mix_CloseAudio();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }

            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                case SDLK_1:
                    Mix_PlayChannel(-1, sound1, 0);
                    break;
                case SDLK_2:
                    Mix_PlayChannel(-1, sound2, 0);
                    break;
                case SDLK_3:
                    Mix_PlayChannel(-1, sound3, 0);
                    break;
                case SDLK_0:
                    if (Mix_PlayingMusic() == 0) {
                        Mix_PlayMusic(bgMusic, -1); // Plays music indefinitely
                    }
                    else {
                        if (Mix_PausedMusic() == 1) {
                            Mix_ResumeMusic();
                        }
                        else {
                            Mix_PauseMusic();
                        }
                    }
                    break;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    Mix_FreeChunk(sound1);
    Mix_FreeChunk(sound2);
    Mix_FreeChunk(sound3);
    Mix_FreeMusic(bgMusic);
    Mix_CloseAudio();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
