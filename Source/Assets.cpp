#include "Assets.h"

std::vector<Texture> Assets::textures;
std::vector<Font> Assets::fonts;

std::vector<AudioMusic> Assets::musics;
std::vector<AudioSound> Assets::sounds;

void Assets::AddTexture(SDL_Renderer* ren, std::string imageFile, int flag) {
	IMG_Init(flag);
	SDL_Surface* surf = IMG_Load(imageFile.c_str());
	if (surf == NULL)
		std::cout << "SURF ERROR";
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, surf);
	if (tex == NULL)
		std::cout << "TEX ERROR";
	SDL_FreeSurface(surf);

	textures.push_back(Texture(imageFile, tex));
}
SDL_Texture* Assets::GetTexture(std::string imageFile) {
	for (auto texture : textures)
		if (texture.imageFile == imageFile)
			return texture.texture;
}
void Assets::CleanTextures() {
	for (auto& texture : textures)
		SDL_DestroyTexture(texture.texture);
	textures.clear();
	IMG_Quit();
}
void Assets::AddFont(std::string fontFile, int size) {
	if (TTF_Init() < 0) {
		std::cout << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
	}

	TTF_Font* font = TTF_OpenFont(fontFile.c_str(), size);
	if (!font) {
		std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
	}
	
	fonts.push_back(Font(fontFile, font));
}
TTF_Font* Assets::GetFont(std::string fontFile) {
	for (auto font : fonts)
		if (font.fontFile == fontFile)
			return font.font;
}
void Assets::CleanFonts() {
	for (auto& font : fonts)
		TTF_CloseFont(font.font);
	fonts.clear();
	TTF_Quit();
}

void Assets::AddSound(std::string soundFile) {
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
	}
	Mix_Chunk* chunk = Mix_LoadWAV(soundFile.c_str());
	if (chunk == NULL) {
		printf("Failed to load beat chunk! SDL_mixer Error: %s\n", Mix_GetError());
	}
	sounds.push_back(AudioSound(soundFile, chunk));
}
Mix_Chunk* Assets::GetSound(std::string soundFile) {
	for (auto audio : sounds)
		if (audio.audioFile == soundFile)
			return audio.chunk;
}
void Assets::CleanSounds() {
	for (auto& audio : sounds)
		Mix_FreeChunk(audio.chunk);
	sounds.clear();
	Mix_Quit();
}
void Assets::AddMusic(std::string musicFile) {
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
	}
	Mix_Music* music=Mix_LoadMUS(musicFile.c_str());
	if (music == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
	}
	musics.push_back(AudioMusic(musicFile, music));
}
Mix_Music* Assets::GetMusic(std::string musicFile) {
	for (auto audio : musics)
		if (audio.audioFile == musicFile)
			return audio.music;
}
void Assets::CleanMusic() {
	for (auto& audio : musics)
		Mix_FreeMusic(audio.music);
	musics.clear();
	Mix_Quit();
}