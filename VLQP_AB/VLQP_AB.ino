/*
  VIRUS LQP-79: http://www.team-arg.org/zmbt-manual.html

  Arduboy version 0.8:  http://www.team-arg.org/zmbt-downloads.html

  MADE by TEAM a.r.g. : http://www.team-arg.org/more-about.html

  2016 - FUOPY - JO3RI - STG - CASTPIXEL - JUSTIN CRY

  Game License: MIT : https://opensource.org/licenses/MIT

*/

//determine the game
#define GAME_ID 40

#include "Arglib.h"
#include "globals.h"
#include "menu.h"
#include "player.h"
#include "enemies.h"
#include "game.h"
#include "elements.h"
#include "bitmaps.h"
#include "level.h"


typedef void (*FunctionPointer) ();
const FunctionPointer PROGMEM mainGameLoop[] =
{
  stateMenuIntro,
  stateMenuMain,
  stateMenuHelp,
  stateMenuPlay,
  stateMenuInfo,
  stateMenuSoundfx,
  stateGamePrepareLevel,
  stateGameNextLevel,
  stateGamePlaying,
  stateGameOver,
};

void setup()
{
  arduboy.start();
  arduboy.setFrameRate(60);
  if (EEPROM.read(EEPROM_AUDIO_ON_OFF)) soundYesNo = true;
}

void loop() {
  if (!(arduboy.nextFrame())) return;
  buttons.poll();
  arduboy.clearDisplay();
  ((FunctionPointer) pgm_read_word (&mainGameLoop[gameState]))();
  arduboy.display();
  if (soundYesNo == true) arduboy.audio.on();
  else arduboy.audio.off();
}

