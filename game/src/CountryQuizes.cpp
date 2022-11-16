#include "Main.h"
#include "OpenCountry.h"
#include "GameInCountry.h"

void OpenBulgariaQuiz(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened, bool* openQuiz, bool* openGame,
	bool* isAnswered, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundBulgaria, 0, 0, WHITE);

	const char* questions[10] = {
			"    The northernmost city of \n           Bulgaria is:",
			" The Maritsa River flows from:",
			"   Which valley is famous for \n         growing roses:",
			"   Which is the highest peak \n             in Pirin?",
			"   In which part of Bulgaria is \n     Kozarnika Cave located?",
			"   In which part of Bulgaria is \n       Sandanski located?",
			" How many provinces are there \n            in Bulgaria?",
			"    Which is the oldest town \n           in Bulgaria?",
			"  Which is the biggest country \n       bordering Bulgaria?",
			"   Which is the biggest island \n           in Bulgaria?"
	};

	const char* answers[10][4] = {
		{"      Vidin", "    Tutrakan", "    Silistra", "    Bregovo"},
		{"     Rodopi", "       Rila", "      Pirin", "    Balkans"},
		{"  Sofia Valley", " Pernik Valley", "Kazanlak Valley", " Sliven Valley"},
		{"  Vihren Peak", "  Botev Peak", "  Musala Peak", "   Black Peak"},
		{"     South", "    Central", "   Northwest", "   Southwest"},
		{"   Southwest", "   Northwest", "     North", "   Northeast"},
		{"       28", "       30", "       27", "       25"},
		{"     Varna", "     Sofia", "    Sozopol", "     Plovdiv"},
		{"    Romania", "     Greece", "    Turkey", "     Serbia"},
		{"    St. Ivan", " Belene Island", " St. Anastasia", " Snake Island"}
	};

	int answersPos[10] = { 4, 2, 3, 1, 3, 1, 1, 4, 3, 2 };


	OpenQuiz(questions, answers, answersPos, money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered,
		isQuizOpened, textures, font);

	if (!*isQuizOpened)
	{
		DrawRectangle(1300, 400, 100, 100, WHITE);
		if (IsMouseInRange(1300, 1300 + 100, 400, 400 + 100))
		{
			DrawRectangle(1300, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				*openQuiz = false;
				*openGame = true;
			}
		}
	}
}

void OpenSpainQuiz(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened, bool* openQuiz, bool* openGame,
	bool* isAnswered, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundSpain, 0, 0, WHITE);

	const char* questions[10] = {
				"1",
				"2",
				"3",
				"4",
				"5",
				"6",
				"7",
				"8",
				"9",
				"10"
	};

	const char* answers[10][4] = {
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"}
	};

	int answersPos[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	OpenQuiz(questions, answers, answersPos, money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered,
		isQuizOpened, textures, font);

	if (!*isQuizOpened)
	{
		DrawRectangle(1300, 400, 100, 100, WHITE);
		if (IsMouseInRange(1300, 1300 + 100, 400, 400 + 100))
		{
			DrawRectangle(1300, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				*openQuiz = false;
				*openGame = true;
			}
		}
	}
}

void OpenFranceQuiz(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened, bool* openQuiz, bool* openGame,
	bool* isAnswered, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundFrance, 0, 0, WHITE);

	const char* questions[10] = {
			"1",
			"2",
			"3",
			"4",
			"5",
			"6",
			"7",
			"8",
			"9",
			"10"
	};

	const char* answers[10][4] = {
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"}
	};

	int answersPos[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

	OpenQuiz(questions, answers, answersPos, money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered,
		isQuizOpened, textures, font);

	if (!*isQuizOpened)
	{
		DrawRectangle(1300, 400, 100, 100, WHITE);
		if (IsMouseInRange(1300, 1300 + 100, 400, 400 + 100))
		{
			DrawRectangle(1300, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				*openQuiz = false;
				*openGame = true;
			}
		}
	}
}


void OpenItalyQuiz(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened, bool* openQuiz, bool* openGame,
	bool* isAnswered, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundItaly, 0, 0, WHITE);

	const char* questions[10] = {
				"1",
				"2",
				"3",
				"4",
				"5",
				"6",
				"7",
				"8",
				"9",
				"10"
	};

	const char* answers[10][4] = {
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"}
	};

	int answersPos[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

	OpenQuiz(questions, answers, answersPos, money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered,
		isQuizOpened, textures, font);

	if (!*isQuizOpened)
	{
		DrawRectangle(1300, 400, 100, 100, WHITE);
		if (IsMouseInRange(1300, 1300 + 100, 400, 400 + 100))
		{
			DrawRectangle(1300, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				*openQuiz = false;
				*openGame = true;
			}
		}
	}
}


void OpenGermanyQuiz(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened, bool* openQuiz, bool* openGame,
	bool* isAnswered, AllTextures textures, Font font)
{
	const char* questions[10] = {
				"1",
				"2",
				"3",
				"4",
				"5",
				"6",
				"7",
				"8",
				"9",
				"10"
	};

	const char* answers[10][4] = {
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"}
	};

	int answersPos[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

	OpenQuiz(questions, answers, answersPos, money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered,
		isQuizOpened, textures, font);

	if (!*isQuizOpened)
	{
		DrawRectangle(1300, 400, 100, 100, WHITE);
		if (IsMouseInRange(1300, 1300 + 100, 400, 400 + 100))
		{
			DrawRectangle(1300, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				*openQuiz = false;
				*openGame = true;
			}
		}
	}
}

void OpenTurkeyQuiz(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened, bool* openQuiz, bool* openGame,
	bool* isAnswered, AllTextures textures, Font font)
{
	const char* questions[10] = {
				"1",
				"2",
				"3",
				"4",
				"5",
				"6",
				"7",
				"8",
				"9",
				"10"
	};

	const char* answers[10][4] = {
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"}
	};

	int answersPos[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

	OpenQuiz(questions, answers, answersPos, money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered,
		isQuizOpened, textures, font);

	if (!*isQuizOpened)
	{
		DrawRectangle(1300, 400, 100, 100, WHITE);
		if (IsMouseInRange(1300, 1300 + 100, 400, 400 + 100))
		{
			DrawRectangle(1300, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				*openQuiz = false;
				*openGame = true;
			}
		}
	}
}

void OpenGreeceQuiz(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened, bool* openQuiz, bool* openGame,
	bool* isAnswered, AllTextures textures, Font font)
{
	const char* questions[10] = {
				"1",
				"2",
				"3",
				"4",
				"5",
				"6",
				"7",
				"8",
				"9",
				"10"
	};

	const char* answers[10][4] = {
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"}
	};

	int answersPos[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

	OpenQuiz(questions, answers, answersPos, money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered,
		isQuizOpened, textures, font);

	if (!*isQuizOpened)
	{
		DrawRectangle(1300, 400, 100, 100, WHITE);
		if (IsMouseInRange(1300, 1300 + 100, 400, 400 + 100))
		{
			DrawRectangle(1300, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				*openQuiz = false;
				*openGame = true;
			}
		}
	}
}

void OpenEnglandQuiz(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened, bool* openQuiz, bool* openGame,
	bool* isAnswered, AllTextures textures, Font font)
{
	const char* questions[10] = {
				"1",
				"2",
				"3",
				"4",
				"5",
				"6",
				"7",
				"8",
				"9",
				"10"
	};

	const char* answers[10][4] = {
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"}
	};

	int answersPos[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

	OpenQuiz(questions, answers, answersPos, money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered,
		isQuizOpened, textures, font);

	if (!*isQuizOpened)
	{
		DrawRectangle(1300, 400, 100, 100, WHITE);
		if (IsMouseInRange(1300, 1300 + 100, 400, 400 + 100))
		{
			DrawRectangle(1300, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				*openQuiz = false;
				*openGame = true;
			}
		}
	}
}

void OpenNorwayQuiz(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened, bool* openQuiz, bool* openGame,
	bool* isAnswered, AllTextures textures, Font font)
{
	const char* questions[10] = {
				"1",
				"2",
				"3",
				"4",
				"5",
				"6",
				"7",
				"8",
				"9",
				"10"
	};

	const char* answers[10][4] = {
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"},
		{"1", "2", "3", "4"}
	};

	int answersPos[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

	OpenQuiz(questions, answers, answersPos, money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered,
		isQuizOpened, textures, font);

	if (!*isQuizOpened)
	{
		DrawRectangle(1300, 400, 100, 100, WHITE);
		if (IsMouseInRange(1300, 1300 + 100, 400, 400 + 100))
		{
			DrawRectangle(1300, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				*openQuiz = false;
				*openGame = true;
			}
		}
	}
}