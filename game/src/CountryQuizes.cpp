#include "Main.h"
#include "OpenCountry.h"
#include "GameInCountry.h"

void OpenBulgariaQuiz(GameS& game, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundBulgaria, 0, 0, WHITE);

	static int counter = 0;

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


	OpenQuiz(questions, answers, answersPos, counter, game, textures, font);

	if (!game.isQuizOpened)
	{
		DrawTexture(textures.gameRight, 1300, 300, WHITE);
		if (IsMouseInRange(1300, 1300 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameRight, 1304, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.openQuiz = false;
				game.openGame = true;
			}
		}
	}
}

void OpenSpainQuiz(GameS& game, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundSpain, 0, 0, WHITE);

	static int counter = 0;

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

	OpenQuiz(questions, answers, answersPos, counter, game, textures, font);

	if (!game.isQuizOpened)
	{
		DrawTexture(textures.gameRight, 1300, 300, WHITE);
		if (IsMouseInRange(1300, 1300 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameRight, 1304, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.openQuiz = false;
				game.openGame = true;
			}
		}
	}
}

void OpenFranceQuiz(GameS& game, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundFrance, 0, 0, WHITE);

	static int counter = 0;

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

	OpenQuiz(questions, answers, answersPos, counter, game, textures, font);

	if (!game.isQuizOpened)
	{
		DrawTexture(textures.gameRight, 1300, 300, WHITE);
		if (IsMouseInRange(1300, 1300 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameRight, 1304, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.openQuiz = false;
				game.openGame = true;
			}
		}
	}
}


void OpenItalyQuiz(GameS& game, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundItaly, 0, 0, WHITE);

	static int counter = 0;

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

	OpenQuiz(questions, answers, answersPos, counter, game, textures, font);

	if (!game.isQuizOpened)
	{
		DrawTexture(textures.gameRight, 1300, 300, WHITE);
		if (IsMouseInRange(1300, 1300 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameRight, 1304, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.openQuiz = false;
				game.openGame = true;
			}
		}
	}
}


void OpenGermanyQuiz(GameS& game, AllTextures textures, Font font)
{
	static int counter = 0;

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

	OpenQuiz(questions, answers, answersPos, counter, game, textures, font);

	if (!game.isQuizOpened)
	{
		DrawTexture(textures.gameRight, 1300, 300, WHITE);
		if (IsMouseInRange(1300, 1300 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameRight, 1304, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.openQuiz = false;
				game.openGame = true;
			}
		}
	}
}

void OpenTurkeyQuiz(GameS& game, AllTextures textures, Font font)
{
	static int counter = 0;

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

	OpenQuiz(questions, answers, answersPos, counter, game, textures, font);

	if (!game.isQuizOpened)
	{
		DrawTexture(textures.gameRight, 1300, 300, WHITE);
		if (IsMouseInRange(1300, 1300 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameRight, 1304, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.openQuiz = false;
				game.openGame = true;
			}
		}
	}
}

void OpenGreeceQuiz(GameS& game, AllTextures textures, Font font)
{
	static int counter = 0;

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

	OpenQuiz(questions, answers, answersPos, counter, game, textures, font);

	if (!game.isQuizOpened)
	{
		DrawTexture(textures.gameRight, 1300, 300, WHITE);
		if (IsMouseInRange(1300, 1300 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameRight, 1304, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.openQuiz = false;
				game.openGame = true;
			}
		}
	}
}

void OpenEnglandQuiz(GameS& game, AllTextures textures, Font font)
{
	static int counter = 0;

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

	OpenQuiz(questions, answers, answersPos, counter, game, textures, font);

	if (!game.isQuizOpened)
	{
		DrawTexture(textures.gameRight, 1300, 300, WHITE);
		if (IsMouseInRange(1300, 1300 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameRight, 1304, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.openQuiz = false;
				game.openGame = true;
			}
		}
	}
}

void OpenNorwayQuiz(GameS& game, AllTextures textures, Font font)
{
	static int counter = 0;

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

	OpenQuiz(questions, answers, answersPos, counter, game, textures, font);

	if (!game.isQuizOpened)
	{
		DrawTexture(textures.gameRight, 1300, 300, WHITE);
		if (IsMouseInRange(1300, 1300 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameRight, 1304, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.openQuiz = false;
				game.openGame = true;
			}
		}
	}
}