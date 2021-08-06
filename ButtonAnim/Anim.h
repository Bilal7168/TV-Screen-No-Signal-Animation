#pragma once
#include<windows.h>
#include "Working.h"
#include <string>
#include <msclr\marshal_cppstd.h>

namespace ButtonAnim {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text;

	/// <summary>
	/// Summary for Anim
	/// </summary>
	public ref class Anim : public System::Windows::Forms::Form
	{
	public:
		Anim(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			//putting the button at same position as the button 1
			trackBar1->Maximum = 100; //the maximum right position of the track bar
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Anim()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;

	private: int speed;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Label^ label2;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Black", 14.25F, System::Drawing::FontStyle::Bold));
			this->button1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button1->Location = System::Drawing::Point(113, 134);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(146, 48);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Awaiting...";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Anim::button1_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Felix Titling", 12.25F));
			this->button3->Location = System::Drawing::Point(234, 447);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(91, 30);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Start";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Anim::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Felix Titling", 10.25F, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Location = System::Drawing::Point(155, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(286, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Press \'Start\' to begin animation";
			this->label1->Click += gcnew System::EventHandler(this, &Anim::label1_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(234, 363);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(91, 45);
			this->trackBar1->TabIndex = 5;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &Anim::trackBar1_Scroll);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(260, 395);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(38, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Speed";
			this->label2->Click += gcnew System::EventHandler(this, &Anim::label2_Click);
			// 
			// Anim
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DodgerBlue;
			this->ClientSize = System::Drawing::Size(582, 528);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Name = L"Anim";
			this->Text = L"Anim";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { //the first anim button

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { //the second anim button

	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { //the button click that moves the above two
		this->label2->Hide();
		this->button1->Text = "No Signal";
		this->button1->Refresh();
		this->trackBar1->Hide();
		InitVariables(Convert::ToInt32(trackBar1->Value), ClientSize.Width, ClientSize.Height);
		button3->Hide();
		button1->Refresh();
		ButtonPattern(ClientSize.Width, ClientSize.Height, this->button1,  this->label1);
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) { //the option of speed

}

private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) { //the track bar scroll
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
