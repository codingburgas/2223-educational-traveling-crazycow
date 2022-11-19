#include "Main.h"
#include "OpenCountry.h"
#include "GameInCountry.h"

void OpenBulgariaQuiz(GameS& game, AllTextures textures, Font font)
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


	OpenQuiz(questions, answers, answersPos, game.quizCounter[0], game, textures, font);

	if (!game.isQuizOpened)
	{
		DrawTexture(textures.gameRight, 1300, 300, WHITE);
		if (IsMouseInRange(1300, 1300 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameRight, 1304, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.isArrowPressed = true;
				game.openQuiz = false;
				game.openGame = true;
			}
		}
	}
}

void OpenSpainQuiz(GameS& game, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundSpain, 0, 0, WHITE);

	const char* questions[10] = {
				"Which is to Spain's west from \n most of the Iberian Peninsula?",
				"Which is the highest mountain \n            in Spain?",
				"    Which city is the capital \n             of Spain",
				"      Which is a Spanish \n  territory in mainland Africa?",
				"     Which isn't one of the \n       Balearic Islands?",
				"       Which sea borders \n       Spain on the north?",
				"     How much is the total \n       land area of Spain?",
				"   Which is the longest river \n            in Spain?",
				" Which Spanish island has the \n       largest population?",
				"  Which Spanish city has the \n       largest population?"
	};

	const char* answers[10][4] = {
		{"   Portugal", "   Belgium", "   Morocco", "     Italy"},
		{"     Aneto", "     Chullo", "     Teide", "    Moncayo"},
		{"   Bracelona", "    Madrid", "     Sevill", "   Valencia"},
		{"     Melilla", "     Rabat", "    Tangier", "   Algeciras"},
		{"    Majorca", "  Formentera", "     Ibiza", "    Tenerife"},
		{"   Black Sea", "Tyrrhenian Sea", " Bay of Biscay", "  Balearic Sea"},
		{"    999,234", "    211,500", "    505,000", "    101,000"},
		{"     Tagus", "     Minho", "   Llobregat", "    Bidasoa"},
		{"     Ibiza", "    Tenerife", " Gran Canaria", "    Majorca"},
		{"   Barcelona", "    Murcia", "     Palma", "    Madrid"}
	};

	

	int answersPos[10] = { 1, 3, 2, 1, 4, 3, 3, 1, 2, 4};

	OpenQuiz(questions, answers, answersPos, game.quizCounter[1], game, textures, font);

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

	OpenQuiz(questions, answers, answersPos, game.quizCounter[2], game, textures, font);

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

	OpenQuiz(questions, answers, answersPos, game.quizCounter[3], game, textures, font);

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
	DrawTexture(textures.quizBackgroundGermany, 0, 0, WHITE);

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

	OpenQuiz(questions, answers, answersPos, game.quizCounter[4], game, textures, font);

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

	OpenQuiz(questions, answers, answersPos, game.quizCounter[5], game, textures, font);

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
	DrawTexture(textures.quizBackgroundGreece, 0, 0, WHITE);

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

	OpenQuiz(questions, answers, answersPos, game.quizCounter[6], game, textures, font);

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

	OpenQuiz(questions, answers, answersPos, game.quizCounter[7], game, textures, font);

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

	OpenQuiz(questions, answers, answersPos, game.quizCounter[8], game, textures, font);

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