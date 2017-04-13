#include "MainSys.h"
#include "MyForm.h"
#include <iostream>
#include <cmath>
#include <Windows.h>
#include <mmsystem.h>
#include <string>


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
namespace Project3 {
	MainSys::MainSys()
	{
	}

	// oyun bitti fonk
	void MainSys::gameOver(bool go, cli::array<Button ^, 2>^ buttons) {
		MyForm::timer1->Enabled = false; // timer i durdur
		for (int s = 0; s < MainSys::boardSize; s++) {
			for (int t = 0; t < MainSys::boardSize; t++) {
				buttons[s, t]->Enabled = false; // taslari etkisiz hale getir
			}
		}
	}

	// yandaki taslari kontrol eden fonk
	int MainSys::checkNextButtons(int c, int d, Button^ btns, cli::array<Button ^, 2>^ buttons) {
		int px = (c == 0 ? 0 : c - 1); // en soldaki degilse soldaki tasa git
		int nx = (c == boardSize - 1 ? boardSize - 1 : c + 1); // en sagdaki deg
		int py = (d == 0 ? 0 : d - 1);
		int ny = (d == boardSize - 1 ? boardSize - 1 : d + 1);

		int ret = 1; // ilk tas kontrol edildi ve yandakini kontrol ediyor
		if ((buttons[px, d]->BackColor == btns->BackColor) && (px != c) && (buttons[px, d]->Visible))
		{
			buttons[px, d]->Visible = false;
			ret += checkNextButtons(px, d, btns,buttons);
		}
		if ((buttons[nx, d]->BackColor == btns->BackColor) && (nx != c) && (buttons[nx, d]->Visible))
		{
			buttons[nx, d]->Visible = false;
			ret += checkNextButtons(nx, d, btns,buttons);
		}

		if ((buttons[c, py]->BackColor == btns->BackColor) && (py != d) && (buttons[c, py]->Visible))
		{
			buttons[c, py]->Visible = false;
			ret += checkNextButtons(c, py, btns,buttons);
		}
		if ((buttons[c, ny]->BackColor == btns->BackColor) && (ny != d) && (buttons[c, ny]->Visible))
		{
			buttons[c, ny]->Visible = false;
			ret += checkNextButtons(c, ny, btns,buttons);
		}
		return ret;
	}

	void MainSys::giveColor(cli::array<Button ^, 2>^ buttons) {
		if (x == boardSize) {
			for (int i = 0; i < x; i++)
			{
				for (int k = boardSize - 1; k >= 0; k--)
				{
					if (buttons[i, 0]->Visible)
						gameOver(true, buttons);
					if (buttons[i, boardSize - k]->BackColor != Color::Cornsilk)
					{
						buttons[i, boardSize - k - 1]->BackColor = buttons[i, boardSize - k]->BackColor;
						buttons[i, boardSize - k - 1]->Visible = buttons[i, boardSize - k]->Visible;
					}
				}
			}
			for (int j = 0; j < x; j++) buttons[j, boardSize]->BackColor = Color::Cornsilk;
			x = 0;
		}
		else
		{
			switch (rand->Next(getColor() + 2))
			{
			case 0: buttons[x++, boardSize]->BackColor = Color::OrangeRed; break;
			case 1: buttons[x++, boardSize]->BackColor = Color::ForestGreen; break;
			case 2: buttons[x++, boardSize]->BackColor = Color::Gold; break;
			case 3: buttons[x++, boardSize]->BackColor = Color::SteelBlue; break;
			case 4: buttons[x++, boardSize]->BackColor = Color::Fuchsia; break;
			case 5: buttons[x++, boardSize]->BackColor = Color::LawnGreen; break;
			case 6: buttons[x++, boardSize]->BackColor = Color::Crimson; break;
			}
			if (buttons[boardSize - 1, boardSize]->BackColor != Color::Cornsilk) decrementTiles();
		}

	}

	void MainSys::quitGame() {
	
		if (MyForm::timer1->Enabled) MyForm::timer1->Enabled = false;
		if (MessageBox::Show("Exit now?", "Exit Game",
			MessageBoxButtons::YesNo, MessageBoxIcon::Stop,
			MessageBoxDefaultButton::Button3) == ::DialogResult::Yes)
			Environment::Exit(0);
		else MyForm::timer1->Enabled = true;
	}

	void MainSys::pauseGame() {
		if (MyForm::timer1->Enabled) MyForm::timer1->Enabled = false;
		if (MessageBox::Show("Click OK to resume your game.", "Game Paused",
			MessageBoxButtons::OK, MessageBoxIcon::Information,
			MessageBoxDefaultButton::Button3) == ::DialogResult::OK)
			MyForm::timer1->Enabled = true;
	}

	void MainSys::MusicOnOff(Button^ btn) {
		if (btn->Text == "&Music: On")
		{
			PlaySound(NULL, NULL, 0);
			btn->Text = "&Music: Off";
		}
		else if (btn->Text == "&Music: Off") {
			PlaySound(TEXT("back.wav"), NULL, SND_LOOP | SND_ASYNC);
			btn->Text = "&Music: On";
		}
	}

	void MainSys::scoring(int numBalls, Label^ label) {
		int moveScore = (numBalls - 1)*(numBalls);
		score += moveScore;
		label->Text = Convert::ToString(score);
	}

	Button^ MainSys::createButtons(Button^ btn, int i, int j) {
		btn = gcnew System::Windows::Forms::Button();
		btn->Location = System::Drawing::Point(buttonSize * i + startX, buttonSize * j + startY);
		btn->Size = System::Drawing::Size(buttonSize, buttonSize);
	
		btn->BackColor = Color::Gainsboro;
		btn->FlatStyle = FlatStyle::Flat;
		btn->FlatAppearance->BorderColor = Color::Cornsilk;
		btn->Visible = false;
		if (j == boardSize) {
			btn->FlatAppearance->BorderSize = 6;
			btn->FlatAppearance->BorderColor = Color::DimGray;
			btn->BackColor = Color::Cornsilk;
			btn->Visible = true;
			btn->Enabled = false;
		}
		return btn;
	}

	void MainSys::compactButton(cli::array<Button ^, 2>^ buttons) {
		for (int i = 0; i < boardSize; i++)
		{
			for (int j = 0; j < boardSize; j++)
			{
				if (!buttons[i, j]->Visible)
				{
					for (int r = j; r >= 0; r--)
					{
						if (r > 0) {
							buttons[i, r]->BackColor = buttons[i, r - 1]->BackColor;
							buttons[i, r]->Visible = buttons[i, r - 1]->Visible;
						}
						else buttons[i, r]->Visible = false;
					}
				}
			}
		}

		for (int i = boardSize - 1; i >= 0; i--)
		{
			if ((!buttons[i, boardSize - 1]->Visible))
			{
				for (int sx = i; sx < boardSize; sx++)
				{
					for (int sj = 0; sj < boardSize; sj++)
					{
						if (sx < boardSize - 1) {
							buttons[sx, sj]->BackColor = buttons[sx + 1, sj]->BackColor;
							buttons[sx, sj]->Visible = buttons[sx + 1, sj]->Visible;
						}
						else buttons[sx, sj]->Visible = false;
					}
				}
			}
		}
	}


}

