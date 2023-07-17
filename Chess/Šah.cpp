// Šah.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SDL.h>
#include <vector>
#include <ctime>
#include <filesystem>
#include <string>

#include "App.h"
#include "Assets.h"
#include "Board.h"
#include "Replay.h"
#include "Data.h"


#include "HumanPlayer.h"

using namespace std;
namespace fs = std::filesystem;

void Setup();
void Clean();

SDL_Event* ev;
bool isRunning = false;

struct GameFile {
    Button button;
    string fileName;
    GameFile(Button _button, string _filename) : button(_button), fileName(_filename) { }
};


int main(int argc, char* argv[1])
{
    //problem z kraljom ko poje figuro na polju ki je hkrati pod napadom
    
    // current date/time based on current system
    time_t now = time(0);

    // convert now to string form
    char* dt = ctime(&now);

    cout << "The local date and time is: " << dt << endl;

    Setup();

    Assets::AddTexture(App::renderer, "Files/Images/white.jpg", 0);
    Assets::AddTexture(App::renderer, "Files/Images/black.jpg", 0);
    Assets::AddTexture(App::renderer, "Files/Images/green.jpg", 0);
    Assets::AddTexture(App::renderer, "Files/Images/pieces.png", 1);
    Assets::AddTexture(App::renderer, "Files/Images/flag.png", 1);
    Assets::AddFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf", 20);
    Assets::AddSound("Files/Audio/capture.mp3");
    Assets::AddSound("Files/Audio/castle.mp3");
    Assets::AddSound("Files/Audio/move-check.mp3");
    Assets::AddSound("Files/Audio/move-self.mp3");
    Assets::AddSound("Files/Audio/promote.mp3");

    Board* chessboard=NULL;
    Replay* replay=NULL;

    Button startPlaying(App::renderer, ev, Text(App::renderer, 100, 150, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "Igraj", { 255, 255, 255 }));
    Button viewGames(App::renderer, ev, Text(App::renderer, 100, 300, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "Pregled iger", { 255, 255, 255 }));
    Button back(App::renderer, ev, Text(App::renderer, 1000, 600, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), "Nazaj", { 255, 255, 255 }));

    Button _back = back;

    vector<GameFile> gameFiles;

    string path = "Files/Save/";

    int y = 1;
    for (const auto& entry : fs::directory_iterator(path)) {
        gameFiles.push_back(GameFile(Button(App::renderer, ev, Text(App::renderer, 100, 600 - 50 * y, Assets::GetFont("Files/Fonts/8-bit-operator/8bitOperatorPlus8-Regular.ttf"), entry.path().string() + " : " + dt, {255, 255, 255})), entry.path().string()));
        std::cout << entry.path() << std::endl;
        y++;
    }
    string fileName = "igra" + to_string(y) + ".save";

    bool play = false;
    bool viewGame = false;
    bool isGameViewed = false;

    while (isRunning) {
        //SDL_WaitEvent(ev);
        SDL_PollEvent(ev);
        //if (SDL_PollEvent(ev)) {
            isRunning = App::ApplicationCheckQuit(*ev);

            if (play) {
                if (chessboard != NULL) {
                    chessboard->Update();
                    if (chessboard->gameOver && chessboard->gameQuit) {
                        play = false;
                        delete chessboard;
                        Data::CreateFile(fileName);
                        Data::WriteToFile(fileName, History::GetMoves());
                        Data::ReadFromFile(fileName);
                    }
                }
            }
            else if (!viewGame) {
                startPlaying.Update();
                viewGames.Update();
                if (startPlaying.CheckMouseClick()) {
                    play = true;
                    chessboard = new Board(App::renderer, ev);
                    cout << "GAME PLAY" << endl;
                }
                if (viewGames.CheckMouseClick()) {
                    cout << "VIEW GAME" << endl;
                    viewGame = true;
                }
            }
            else {
                _back.Update();
                if (_back.CheckMouseClick()) {
                    viewGame = false;
                    isGameViewed = false;
                }
                if (!isGameViewed) {
                    for (auto& file : gameFiles) {
                        file.button.Update();
                        if (file.button.CheckMouseClick()) {
                            isGameViewed = true;
                            cout << file.fileName << endl;
                            replay = new Replay(App::renderer, ev, Data::ReadFromFile(file.fileName));
                        }
                    }
                }
                else {
                    replay->Update();
                }
            }
            App::ApplicationRender();
        //}
    }
    Clean();
    
    return 0;
}

void Setup() {
    ev = new SDL_Event();
    App::ApplicationStart();
    isRunning = true;
}
void Clean() {
    Assets::CleanTextures();
    Assets::CleanFonts();
    Assets::CleanSounds();
    Assets::CleanMusic();
    App::ApplicationQuit();
    delete ev;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
