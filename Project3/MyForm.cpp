#include <iostream>
#include <cmath>
#include <Windows.h>
#include <mmsystem.h>
#include <string>
#include "MyForm.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace System::IO;
using namespace std;

namespace Project3 {
	[STAThread]
	void main()
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		Project3::MyForm form;
		Application::Run(%form);
	}
	
	// yeni oyun fonk
	void MyForm::startNewGame() {
		if (timer1->Enabled) timer1->Stop();
		resetBoard(); // taslari resetle
		//global degiskenler resetle
		MainSys::x = 0; MainSys::y = 15; MainSys::boardSize = 15;
		MainSys::startX = 150, MainSys::startY = 15, MainSys::buttonSize = 40;
		MainSys::tilesLeft = 20;
		if (isLevelUp) { // seviye yukselince
			MainSys::getColor() == 5 ? 5 : MainSys::incrementColor(); // renk sayisi arttir
		}
		else
		{
			MainSys::setColor(1); MainSys::setScore(0); // skor resetle ve 1. seviyede baslasin
		}
		label6->Text = Convert::ToString(MainSys::getScore()); // skor goster
		label4->Text = Convert::ToString(MainSys::getColor()); // level goster
		timer1->Start(); // timer baslat
		MainSys::giveColor(buttons); // taslara renk ver
	}

	// taslari resetle fonk
	void MyForm::resetBoard() {
		for (int i = 0; i < MainSys::boardSize; i++)
			for (int j = 0; j < MainSys::boardSize; j++)
				this->Controls->Remove(buttons[i, j]); // taslari kaldir
		createBoard(); // taslari tekrardan olustur
	}

	// level yukseldi fonk
	void MyForm::levelUp(bool lvl) {
		if (lvl && MainSys::getColor() == 5) { // en ust level a gelince
			if (MessageBox::Show("Tebrikler!!! Kazandiniz.\nDevam etmek istiyor musunuz?", "Seviye Tamamlandi",
				MessageBoxButtons::YesNo, MessageBoxIcon::Question,
				MessageBoxDefaultButton::Button3) == ::DialogResult::Yes) {
				startNewGame(); isLevelUp = false; // yeni oyun yap
			}
		}
		else if (lvl) { // level yukselince
			if (MessageBox::Show("Tebrikler!!!\nYeni seviye icin 'YES' tusuna basin.", "Seviye Tamamlandi",
				MessageBoxButtons::YesNo, MessageBoxIcon::Question,
				MessageBoxDefaultButton::Button3) == ::DialogResult::Yes) {
				startNewGame(); isLevelUp = false; // yeni oyun yap
			}
			else {
				MainSys::gameOver(true, buttons); // oyun bitti
				saveScore();
				
			}
		}
	}

	// bo? ta?lar? olustur fonk
	void MyForm::createBoard() {
		for (int i = 0; i < MainSys::boardSize; i++)
		{
			for (int j = 0; j < MainSys::boardSize + 1; j++)
			{
				// taslari olustur ve forma ekle
				buttons[i,j] = MainSys::createButtons(buttons[i, j], i, j);
				buttons[i,j]->Click += gcnew EventHandler(this, &MyForm::clickButton); //ta?lara t?klama özelli?i kazand?r?ld?
				this->Controls->Add(buttons[i, j]);
				this->buttons[i, j]->BringToFront();
			}
		}
	}

	// tas tiklama fonk
	void MyForm::clickButton(System::Object^  sender, System::EventArgs^  e)
	{
		Button^ clicked = safe_cast<Button^>(sender); // tiklanan tas clicked degiskene ata
		Point^ pos = safe_cast<Point>(clicked->Location); // tiklanan tasin konumu pos degiskene ata

		int ex = (pos->X - MainSys::startX) / MainSys::buttonSize; // tas kacinci satir = tiklanan tasin konumu - ilk sutunun baslangic degeri / tasin boyutu
		int ey = (pos->Y - MainSys::startY) / MainSys::buttonSize; // tas kacinci sutun = tiklanan tasin konumu - ilk satirin baslangic degeri / tasin boyutu

		int px = (ex == 0 ? 0 : ex - 1); // soldaki tas. en soldaki ise sifir yap, degilse bir sola bak
		int nx = (ex == MainSys::boardSize - 1 ? MainSys::boardSize - 1 : ex + 1); // sagdaki tas. en sagdaki ise sifir yap, degilse bir saga bak
		int py = (ey == 0 ? 0 : ey - 1); // ustteki tas. en ustteki ise sifir yap, degilse bir uste bak
		int ny = (ey == MainSys::boardSize - 1 ? MainSys::boardSize - 1 : ey + 1); // alttaki tas. en alttaki ise sifir yap, degilse bir alta bak

		// tas var ve arkaplan renginden farkli ise. arkaplan rengi = color::cornsilk
		if (buttons[ex, ey]->Visible && buttons[ex, ey]->BackColor != Color::Cornsilk)
		{
			// tasin sol, sag, alt, ust tarafinin rengi ayni mi? kendisinden farkli mi? tiklanan tas formda var mi?
			if ((buttons[px, ey]->BackColor == clicked->BackColor) && (px != ex) && (buttons[px, ey]->Visible)//sol
				|| (buttons[nx, ey]->BackColor == clicked->BackColor) && (nx != ex) && (buttons[nx, ey]->Visible)//sag
				|| (buttons[ex, py]->BackColor == clicked->BackColor) && (py != ey) && (buttons[ex, py]->Visible)//ust
				|| (buttons[ex, ny]->BackColor == clicked->BackColor) && (ny != ey) && (buttons[ex, ny]->Visible))//alt
			{
				checkedButton(ex, ey, clicked); // tas kontrol edilmis ve yandakini kontrol et 
			}
		}
	}

	// tas kontrol edilmis fonk
	void MyForm::checkedButton(int a, int b, Button^ btn) {
		buttons[a, b]->Visible = false; // tiklanan tasi yok et
		int ret = 0; // kac tane taslar ayni renkte, ret degiskene ata
		ret += MainSys::checkNextButtons(a, b, btn, buttons); // tekrarlanmali olarak yandaki taslari kontrol et
		MainSys::compactButton(buttons); // taslari s?k??t?r
		MainSys::scoring(ret, label6); // puanlama
	}

	void MyForm::saveScore() {
		StreamReader^ sr = gcnew StreamReader("scorelist.txt");
		int bestScore = Convert::ToInt32(sr->ReadLine());
		sr->Close();
		if (MainSys::score > bestScore)
		{
			StreamWriter^ sw = gcnew StreamWriter("scorelist.txt");
			sw->WriteLine(MainSys::score);
			sw->Close();
		}
		
	}
}


