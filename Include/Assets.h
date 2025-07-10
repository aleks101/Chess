#pragma once

#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

struct Texture {
	std::string imageFile;
	SDL_Texture* texture;
	Texture(std::string _imageFile, SDL_Texture* _texture) : imageFile(_imageFile), texture(_texture) {}
};
struct Font {
	std::string fontFile;
	TTF_Font* font;
	Font(std::string _fontFile, TTF_Font* _font) : fontFile(_fontFile), font(_font) {}
};
struct AudioSound {
	std::string audioFile;
	Mix_Chunk* chunk;
	AudioSound(std::string _audioFile, Mix_Chunk* _chunk) : audioFile(_audioFile), chunk(_chunk) {}
};
struct AudioMusic {
	std::string audioFile;
	Mix_Music* music;
	AudioMusic(std::string _audioFile, Mix_Music* _music) : audioFile(_audioFile), music(_music) {}
};

class Assets
{
private:
	static std::vector<Texture> textures;
	static std::vector<Font> fonts;

	static std::vector<AudioSound> sounds;
	static std::vector<AudioMusic> musics;
public:
	static void AddTexture(SDL_Renderer* ren, std::string imageFile, int flag);
	static SDL_Texture* GetTexture(std::string imageFile);
	static void CleanTextures();

	static void AddFont(std::string fontFile, int size);
	static TTF_Font* GetFont(std::string fontFile);
	static void CleanFonts();

	static void AddSound(std::string soundFile);
	static Mix_Chunk* GetSound(std::string soundFile);
	static void CleanSounds();
	static void AddMusic(std::string musicFile);
	static Mix_Music* GetMusic(std::string musicFile);
	static void CleanMusic();
};