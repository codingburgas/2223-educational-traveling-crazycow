#include "Main.h"
#include "OpenCountry.h"
#include "GameInCountry.h"


void OpenBulgariaGame(int* money, bool* isGameOpened, bool* openQuiz, bool* openGame, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundBulgaria, 0, 0, WHITE);

	OpenGame(isGameOpened, money, textures, font);

	if (!*isGameOpened)
	{
		DrawRectangle(500, 400, 100, 100, WHITE);
		if (IsMouseInRange(500, 500 + 100, 400, 400 + 100))
		{
			DrawRectangle(500, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				*openQuiz = true;
				*openGame = false;
			}
		}
	}
}

void OpenSpainGame(int* money, bool* isGameOpened, bool* openQuiz, bool* openGame, AllTextures textures, Font font)
{
	OpenGame(isGameOpened, money, textures, font);

	if (!*isGameOpened)
	{
		DrawRectangle(500, 400, 100, 100, WHITE);
		if (IsMouseInRange(500, 500 + 100, 400, 400 + 100))
		{
			DrawRectangle(500, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				*openQuiz = true;
				*openGame = false;
			}
		}
	}
}

void OpenFranceGame(int* money, bool* isGameOpened, bool* openQuiz, bool* openGame, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundFrance, 0, 0, WHITE);

	OpenGame(isGameOpened, money, textures, font);

	if (!*isGameOpened)
	{
		DrawRectangle(500, 400, 100, 100, WHITE);
		if (IsMouseInRange(500, 500 + 100, 400, 400 + 100))
		{
			DrawRectangle(500, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				*openQuiz = true;
				*openGame = false;
			}
		}
	}
}

void OpenItalyGame(int* money, bool* isGameOpened, bool* openQuiz, bool* openGame, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundItaly, 0, 0, WHITE);

	OpenGame(isGameOpened, money, textures, font);

	if (!*isGameOpened)
	{
		DrawRectangle(500, 400, 100, 100, WHITE);
		if (IsMouseInRange(500, 500 + 100, 400, 400 + 100))
		{
			DrawRectangle(500, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				*openQuiz = true;
				*openGame = false;
			}
		}
	}
}

void OpenGermanyGame(int* money, bool* isGameOpened, bool* openQuiz, bool* openGame, AllTextures textures, Font font)
{
	OpenGame(isGameOpened, money, textures, font);

	if (!*isGameOpened)
	{
		DrawRectangle(500, 400, 100, 100, WHITE);
		if (IsMouseInRange(500, 500 + 100, 400, 400 + 100))
		{
			DrawRectangle(500, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				*openQuiz = true;
				*openGame = false;
			}
		}
	}
}

void OpenTurkeyGame(int* money, bool* isGameOpened, bool* openQuiz, bool* openGame, AllTextures textures, Font font)
{
	OpenGame(isGameOpened, money, textures, font);

	if (!*isGameOpened)
	{
		DrawRectangle(500, 400, 100, 100, WHITE);
		if (IsMouseInRange(500, 500 + 100, 400, 400 + 100))
		{
			DrawRectangle(500, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				*openQuiz = true;
				*openGame = false;
			}
		}
	}
}

void OpenGreeceGame(int* money, bool* isGameOpened, bool* openQuiz, bool* openGame, AllTextures textures, Font font)
{
	OpenGame(isGameOpened, money, textures, font);

	if (!*isGameOpened)
	{
		DrawRectangle(500, 400, 100, 100, WHITE);
		if (IsMouseInRange(500, 500 + 100, 400, 400 + 100))
		{
			DrawRectangle(500, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				*openQuiz = true;
				*openGame = false;
			}
		}
	}
}

void OpenEnglandGame(int* money, bool* isGameOpened, bool* openQuiz, bool* openGame, AllTextures textures, Font font)
{
	OpenGame(isGameOpened, money, textures, font);

	if (!*isGameOpened)
	{
		DrawRectangle(500, 400, 100, 100, WHITE);
		if (IsMouseInRange(500, 500 + 100, 400, 400 + 100))
		{
			DrawRectangle(500, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				*openQuiz = true;
				*openGame = false;
			}
		}
	}
}

void OpenNorwayGame(int* money, bool* isGameOpened, bool* openQuiz, bool* openGame, AllTextures textures, Font font)
{
	OpenGame(isGameOpened, money, textures, font);

	if (!*isGameOpened)
	{
		DrawRectangle(500, 400, 100, 100, WHITE);
		if (IsMouseInRange(500, 500 + 100, 400, 400 + 100))
		{
			DrawRectangle(500, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				*openQuiz = true;
				*openGame = false;
			}
		}
	}
}