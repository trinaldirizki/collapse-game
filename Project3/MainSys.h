#pragma once
#include <iostream>
#include <cmath>
#include <Windows.h>
#include <mmsystem.h>
#include <string>
//#include "MyForm.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;

namespace Project3 {
	public ref class MainSys
	{
	#pragma region Variables
	private:
		static Random^ rand = gcnew Random();
		static int colorLevel = 1; // seviye degiskeni
		static bool isGameOver = false; // oyun bitti mi?
	public:
		static int tilesLeft = 20;
		static int x = 0, y = 15, boardSize = 15; // baslangic degeri, bitis degeri, 15x15 lik tas dizisi
		static int startX = 150, startY = 15, buttonSize = 40; // ilk sutun baslangic degeri, ilkk satir baslangic degeri, tas boyutu
		static int score = 0; // skor
		MainSys();
		static int checkNextButtons(int c, int d, Button^ btns, cli::array<Button ^, 2>^ buttons);
		static void giveColor(cli::array<Button ^, 2>^ buttons);
		static Button^ createButtons(Button^ btn, int i, int j);
		static void compactButton(cli::array<Button ^, 2>^ buttons);
		static void quitGame();
		static void pauseGame();
		static void MusicOnOff(Button^ btn);
		static void scoring(int numBalls, Label^ label);
		static int getScore() { return score; }
		static int getColor() { return colorLevel; }
		static void totalScore(int totScore) { score += totScore; }
		static void incrementColor() { colorLevel++; }
		static void decrementTiles() { tilesLeft--; }
		static void setScore(int sco) { score = sco; }
		static void setColor(int cl) { colorLevel = cl; }
		static void gameOver(bool go, cli::array<Button ^, 2>^ buttons);
#pragma endregion
	};
}


