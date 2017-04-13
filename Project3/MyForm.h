#pragma once
#include <iostream>
#include <cmath>
#include <Windows.h>
#include <mmsystem.h>
#include <string>
#include "MainSys.h"

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
	public ref class MyForm : public System::Windows::Forms::Form
	{

	#pragma region Variables
	
	public:
		void createBoard(); // bos taslar uretiyor
		void clickButton(System::Object^  sender, System::EventArgs^  e); 
		void checkedButton(int a, int b, Button^ btn); // secilen button
		void levelUp(bool lvl);
		void startNewGame();
		void resetBoard();
		void saveScore();
#pragma endregion

#pragma region Controls
	private:
	static bool isLevelUp;


	static cli::array<Button ^, 2>^ buttons = gcnew cli::array<Button^, 2>(MainSys::boardSize, MainSys::boardSize + 1);
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	public: static System::Windows::Forms::Timer^  timer1;
	private:

	private:

	private:

	private:

	private:

	private:

	private:

	private: System::ComponentModel::IContainer^  components;
#pragma endregion

	
	public:
		MyForm(void)
		{
			InitializeComponent();
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:
	
	protected:
	protected:
	protected:
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 200;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DarkGray;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::LightGray;
			this->button1->FlatAppearance->BorderSize = 4;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Goldenrod;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Location = System::Drawing::Point(25, 30);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 50);
			this->button1->TabIndex = 0;
			this->button1->Text = L"&New Game";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::DarkGray;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::LightGray;
			this->button2->FlatAppearance->BorderSize = 4;
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Goldenrod;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(25, 170);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 50);
			this->button2->TabIndex = 1;
			this->button2->Text = L"High &Score";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->MouseEnter += gcnew System::EventHandler(this, &MyForm::hs_mouseEnter);
			this->button2->MouseLeave += gcnew System::EventHandler(this, &MyForm::hs_mouseLeave);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::DarkGray;
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::LightGray;
			this->button3->FlatAppearance->BorderSize = 4;
			this->button3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Goldenrod;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(25, 570);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 50);
			this->button3->TabIndex = 2;
			this->button3->Text = L"&Quit Game";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::DarkGray;
			this->button5->FlatAppearance->BorderColor = System::Drawing::Color::LightGray;
			this->button5->FlatAppearance->BorderSize = 4;
			this->button5->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Goldenrod;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::Black;
			this->button5->Location = System::Drawing::Point(25, 100);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(100, 50);
			this->button5->TabIndex = 4;
			this->button5->Text = L"&Pause Game";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Maiandra GD", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(30, 252);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 22);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Level";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Maiandra GD", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(30, 402);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 24);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Score";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Maiandra GD", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(30, 325);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 22);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Tiles Left";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Maiandra GD", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(30, 281);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(27, 32);
			this->label4->TabIndex = 10;
			this->label4->Text = L"1";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Maiandra GD", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(30, 357);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(43, 32);
			this->label5->TabIndex = 11;
			this->label5->Text = L"19";
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Maiandra GD", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(30, 436);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(32, 32);
			this->label6->TabIndex = 12;
			this->label6->Text = L"0";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::DarkGray;
			this->button4->FlatAppearance->BorderColor = System::Drawing::Color::LightGray;
			this->button4->FlatAppearance->BorderSize = 4;
			this->button4->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Goldenrod;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::Black;
			this->button4->Location = System::Drawing::Point(25, 500);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(100, 50);
			this->button4->TabIndex = 13;
			this->button4->Text = L"&Music: On";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::Cornsilk;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(522, 660);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimumSize = System::Drawing::Size(500, 39);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	// en alttaki taslara renk vermek ve kalan taslari kontrol etmek icin kullanilan timer
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		label5->Text = Convert::ToString(MainSys::tilesLeft); // kalan taslari ekrana gosteriyor
		MainSys::giveColor(buttons); // en alttaki taslara renk ver
		if (MainSys::tilesLeft == 0) { // kalan taslar 0 ise
			MainSys::giveColor(buttons); // bir kere daha yap
			label5->Text = Convert::ToString(MainSys::tilesLeft);
			timer1->Enabled = false; // timer durdur
			for (int s = 0; s < MainSys::boardSize; s++)
			{
				for (int t = 0; t < MainSys::boardSize; t++)
				{
					buttons[s, t]->Enabled = false; // taslari etkisiz hale getir
				}
			}
			isLevelUp = true;
			levelUp(isLevelUp);
		}
	}

	// yeni oyun butonu
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (timer1->Enabled) timer1->Enabled = false; // timer calisiyorsa durdur
		if (MessageBox::Show("Yeni oyun acmak istedigine emin misin?", "Yeni Oyun",
			MessageBoxButtons::YesNo, MessageBoxIcon::Question,
			MessageBoxDefaultButton::Button3) == ::DialogResult::Yes) {
			startNewGame(); timer1->Enabled = true; // yeni oyun olustur ve timer baslat
		}
		else {
			for (int i = 0; i < MainSys::boardSize; i++)
			{
				if (buttons[i, 0]->Visible) timer1->Enabled = false;
				else timer1->Enabled = true;
			}
		}
	}

	// oyundan cik butonu
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		MainSys::quitGame();
	}

	// oyun duraklat butonu
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		MainSys::pauseGame();
	}
	
	// muzik ac/kapa butonu
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		MainSys::MusicOnOff(button4);
	}

	// skor kaydet butonu
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		
	}

	// ana form calistigi zaman
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		createBoard(); // bos taslar olustur
		timer1->Enabled = true; // timer baslat
		label4->Text = Convert::ToString(MainSys::getColor()); // seviye goster
		PlaySound(TEXT("back.wav"), NULL, SND_LOOP | SND_ASYNC); // muzik ac
	}

private: System::Void hs_mouseEnter(System::Object^  sender, System::EventArgs^  e) {
	StreamReader^ sr = gcnew StreamReader("scorelist.txt");
	button2->Text = sr->ReadLine();
	sr->Close();
}
private: System::Void hs_mouseLeave(System::Object^  sender, System::EventArgs^  e) {
	button2->Text = "High &Score";
}
};
}
