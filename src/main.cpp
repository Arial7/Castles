#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/glu.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <FTGL/ftgl.h>

#include "renderer.h"
#include "loader.h"
#include "gameObject.h"
#include "character.h"
#include "building.h"
#include "mainTower.h"
#include "errorHandler.h"
#include "cleanup.h"
#include "textures.h"

//the size of the window, defaulted to HD, which should be the minimum size of a monitor nowadays
const int WINDOW_WIDTH(1280);
const int WINDOW_HEIGHT(720);
const char* WINDOW_TITLE("Villages - v0.0.1");

//set to true when the game should exit
bool quit = false;
//set to true if the game should pause
bool paused = false;
//the main window, initialized with nullptr, will be really initialized later
SDL_Window *window(nullptr);

//all the vectors holding the game objects
std::vector <Character*> characters;
//std::vector <Building*> buildings;
MainTower* mainTower;

//important objects, such as the errorHandler and the renderer
ErrorHandler errorHandler;
Renderer renderer(WINDOW_HEIGHT);
Loader loader;
Textures* textures;
HUD* hud;

//function prototypes
short initSDL(void);
void loadup(void);
void gameloop(void);
void getInput(void);
void update(void);
void render(void);
bool initGL(void);
void cleanUp(void);

//TEMP: texture for the characters
GLuint charTex;
GLuint icon_hammer;
GLuint building_mainTower;
GLuint icon_health;
GLuint icon_play;
GLuint icon_pause;

int main(int argc, char *argv[]){
	//This call will initialize SDL and OpenGL
	short initSDLReturn = initSDL();
	if(initSDLReturn != 0) return initSDLReturn;
	//Load everything
	loadup();
	/*Das gameloop starten*/
	gameloop();
	/*Wenn das gameloop beendet wurde, alles aufräumen und dann das Programm beenden*/
	cleanUp();

	SDL_Quit();
	return 0;
}

short initSDL() {

	//Initailize the SDL_VIDEO subsystem, audio will come later
	SDL_Init(SDL_INIT_EVERYTHING);

	//We need OpenGL 2.1
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	//enable double buffering
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	//create the window
	window = SDL_CreateWindow(WINDOW_TITLE, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	/*Falls das Erstellen gescheitert ist, wird das Programm beendet*/
	if (window == nullptr) {
		errorHandler.logSDLError(std::cout, "SDL_CreateWindow");
		SDL_Quit();
		return 1;
	}
	/*Erstellt den OpenGL context*/
	SDL_GLContext context(nullptr);
	context = SDL_GL_CreateContext(window);
	/*Falls das Erstellen gescheitert ist, wird das Programm beendet*/
	if (context == nullptr) {
		cleanUp();
		errorHandler.logSDLError(std::cout, "SDL_GL_CreateContext");
		SDL_Quit();
		return 1;
	}

	/*OpenGL initalisieren*/
	if (!initGL()) {
		cleanUp();
		SDL_Quit();
		return 1;
	}

	return 0;

}

void loadup() {
	//load all the textures
	textures = new Textures(&loader);
	textures->loadTextures();

	//create some objects
	/*mainTower = new MainTower(1024, 256, 100, textures->building_mainTower);

	characters.emplace_back(new Character(-32, 32, textures->character_default));
	characters.emplace_back(new Character(96, 0, textures->character_default));
	characters.emplace_back(new Character(128, 64, textures->character_default));
	characters.emplace_back(new Character(0, 128, textures->character_default));
	characters.emplace_back(new Character(-32, 64, textures->character_default));
	characters.emplace_back(new Character(0, -32, textures->character_default));
	characters.emplace_back(new Character(-32, 64, textures->character_default));
	characters.emplace_back(new Character(0, 64, textures->character_default));
	characters.emplace_back(new Character(32, 64, textures->character_default));
	characters.emplace_back(new Character(64, 64, textures->character_default));


	//TEMP: set the characters destination manually
	for(Character* character : characters) {
		character->moveTo(mainTower->getX(), mainTower->getY() + mainTower->getHeight());
	}
*/	//Create The hud
	hud = new HUD(textures);
	//hud->setHealth(mainTower->getHealth());

}

void gameloop(){

	SDL_Event event;
	while (!quit) {
		/*Alle SDL_Events abfragen und behandeln*/
		while (SDL_PollEvent (&event)) {
			switch (event.type) {
				case SDL_QUIT: //SDL_Quit = Fenster geschlossen
					quit = true;
				    break;
			}
		}
		getInput();
		if(!paused) update();
		render();
		/*Framebuffers tauschen*/
		SDL_GL_SwapWindow(window);
	}
}

void render(){
	glClear(GL_COLOR_BUFFER_BIT);

	//render all the game objects

	renderer.renderObject(mainTower);

	for(Character* ch : characters){
	    renderer.renderCharacter(ch);
	}

	renderer.renderObject(hud);


}

void update(){
	for (Character* character : characters){
		character->update();
		if (character->hasReachedDestiny()){
			mainTower->damage(10);
			hud->setHealth(mainTower->getHealth());
			int positionInVector = std::find(characters.begin(), characters.end(), character) - characters.begin();
			characters.erase(characters.begin() + positionInVector);
			//delete character;
		}
	}

}

void getInput(){
    int mouseX, mouseY;
	const Uint8* currentKeyStates = SDL_GetKeyboardState(nullptr);

	if(currentKeyStates[SDL_SCANCODE_ESCAPE]){
		quit = true;
	}
	if(currentKeyStates[SDL_SCANCODE_P]) {
		paused = !paused;
		hud->changePlayStatus();
	}
	//TODO: improve the following algorithms


	if(SDL_GetMouseState(&mouseX, &mouseY) & SDL_BUTTON(SDL_BUTTON_RIGHT)){

	}

}

bool initGL(){

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (errorHandler.checkGLError()) {
		return false;
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (errorHandler.checkGLError()) {
		return false;
	}

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glOrtho(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0, -1, 1);


	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);

	if (errorHandler.checkGLError()) {
		return false;
	}
	return true;
}

void cleanUp(){
	for(Character* charptr : characters){
		delete charptr;
	}

	delete mainTower;
	delete hud;

	textures->deleteTextures();
	delete textures;

	cleanup(window);
}



