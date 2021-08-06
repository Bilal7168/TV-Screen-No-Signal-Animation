#pragma once
#include<windows.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

int s; //the speed variable 's'
int w; //the width of client
int h; //the height of client


//the movement helper functions----------------------------------------
void Up(System::Windows::Forms::Button^ button) { // '|'
	while (button->Top > 0) {
		button->Top--;
		Sleep(100 - s);
	}
}

void UpRight(System::Windows::Forms::Button^ button) { // '/'
	while (button->Top > 0 && (w-button->Right) > 0) {
		button->Top--;
		button->Left++;
		Sleep(100 - s);
	}
}

void UpLeft(System::Windows::Forms::Button^ button) { // '/'
	while (button->Top > 0 && button->Left > 0) {
		button->Top--;
		button->Left--;
		Sleep(100 - s);
	}
}

void Left(System::Windows::Forms::Button^ button) { // '|'
	while (button->Left > 0) {
		button->Left--;
		Sleep(100 - s);
	}
}

void Right(System::Windows::Forms::Button^ button) { // '|'
	while ((w-button->Right) > 0) {
		button->Left++;
		Sleep(100 - s);
	}
}

void Down(System::Windows::Forms::Button^ button) { // '|'
	while ((h-button->Bottom) > 0) {
		button->Top++;
		Sleep(100 - s);
	}
}

void DownLeft(System::Windows::Forms::Button^ button) { // '/'
	while ((h-button->Bottom) > 0 && button->Left > 0) {
		button->Top++;
		button->Left--;
		Sleep(100 - s);
	}
}

void DownRight(System::Windows::Forms::Button^ button) { // '/'
	while ((h-button->Bottom) > 0 && (w-button->Right) > 0) {
		button->Top++;
		button->Left++;
		Sleep(100 - s);
	}
}
//the movement helper functions------------------------------------------------

//the button movement algorithm------------------------------------------------

void Movement(System::Windows::Forms::Button^ button) {
	if (button->Left != 0 && (w - button->Right) != 0 && button->Top != 0 && (h - button->Bottom) != 0)
		DownLeft(button); 
	else if (button->Left == 0 && button->Top == (h-button->Bottom))
		Right(button);
	else if ((w-button->Right) == 0 && button->Top == (h-button->Bottom))
		Left(button);
	else if (button->Top == 0 && (w-button->Right) == button->Left)
		Down(button);
	else if ((h-button->Bottom) ==0 && (w-button->Right) == button->Left)
		Up(button);
	else if (button->Top == 0 && button->Left == 0 || button->Top == 0 && button->Left > (w-button->Right) || button->Left==0 && (h-button->Bottom) > button->Top)
		DownRight(button);
	else if (button->Top == 0 && (w-button->Right) == 0 || button->Top == 0 && (w-button->Right) > button->Left || (w-button->Right)==0 && (h-button->Bottom) > button->Top)
		DownLeft(button);
	else if ((h-button->Bottom) == 0 && button->Left == 0 || (h-button->Bottom) == 0 && button->Left > (w-button->Right) || button->Left == 0 && button->Top > (h-button->Bottom))
		UpRight(button);
	else if ((h-button->Bottom) == 0 && (w-button->Right) == 0 || (h-button->Bottom) == 0 && (w-button->Right) > button->Left || (w-button->Right) == 0 && button->Top > (h-button->Bottom))
		UpLeft(button);
}

//the button movement algorithm------------------------------------------------

//the randomness algorithm--------------------------------------------
void RandomMove(System::Windows::Forms::Button^ button) {
	switch (rand() % 8) {
	case 0: Up(button); break;
	case 1: UpRight(button); break;
	case 2: UpLeft(button); break;
	case 3: Left(button); break;
	case 4: Right(button); break;
	case 5: Down(button); break;
	case 6: DownLeft(button); break;
	case 7: DownRight(button); break;
	}
}

//the randomness algorithm--------------------------------------------

void InitVariables(int speed, int width, int height) {
	s = speed; w = width; h = height;
}

void ButtonPattern(int Width, int Height, System::Windows::Forms::Button^ button1, System::Windows::Forms::Label^ label1) {
	label1->Text = "Begin Pattern";
	label1->Refresh();
	label1->Hide();
	int randomIndex = 0;
	while (1) {
		Movement(button1);
		if (randomIndex % 5 == 0)
			RandomMove(button1);
		randomIndex++;
	}
}
