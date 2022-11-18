#include "Main.h"
#include "OpenCountry.h"
#include "GameInCountry.h"


void OpenBulgariaGame(GameS& game, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundBulgaria, 0, 0, WHITE);

	OpenGame(game, textures, font);

	if (!game.isGameOpened)
	{
		DrawRectangle(500, 400, 100, 100, WHITE);
		if (IsMouseInRange(500, 500 + 100, 400, 400 + 100))
		{
			DrawRectangle(500, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				game.openQuiz = true;
				game.openGame = false;
			}
		}
	}
}

void OpenSpainGame(GameS& game, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundSpain, 0, 0, WHITE);

	OpenGame(game, textures, font);

	if (!game.isGameOpened)
	{
		DrawRectangle(500, 400, 100, 100, WHITE);
		if (IsMouseInRange(500, 500 + 100, 400, 400 + 100))
		{
			DrawRectangle(500, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				game.openQuiz = true;
				game.openGame = false;
			}
		}
	}
}

void OpenFranceGame(GameS& game, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundFrance, 0, 0, WHITE);

	OpenGame(game, textures, font);

	if (!game.isGameOpened)
	{
		DrawRectangle(500, 400, 100, 100, WHITE);
		if (IsMouseInRange(500, 500 + 100, 400, 400 + 100))
		{
			DrawRectangle(500, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				game.openQuiz = true;
				game.openGame = false;
			}
		}
	}
}

void OpenItalyGame(GameS& game, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundItaly, 0, 0, WHITE);

	OpenGame(game, textures, font);

	if (!game.isGameOpened)
	{
		DrawRectangle(500, 400, 100, 100, WHITE);
		if (IsMouseInRange(500, 500 + 100, 400, 400 + 100))
		{
			DrawRectangle(500, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				game.openQuiz = true;
				game.openGame = false;
			}
		}
	}
}

void OpenGermanyGame(GameS& game, AllTextures textures, Font font)
{
	OpenGame(game, textures, font);

	if (!game.isGameOpened)
	{
		DrawRectangle(500, 400, 100, 100, WHITE);
		if (IsMouseInRange(500, 500 + 100, 400, 400 + 100))
		{
			DrawRectangle(500, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				game.openQuiz = true;
				game.openGame = false;
			}
		}
	}
}

void OpenTurkeyGame(GameS& game, AllTextures textures, Font font)
{
	OpenGame(game, textures, font);

	if (!game.isGameOpened)
	{
		DrawRectangle(500, 400, 100, 100, WHITE);
		if (IsMouseInRange(500, 500 + 100, 400, 400 + 100))
		{
			DrawRectangle(500, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				game.openQuiz = true;
				game.openGame = false;
			}
		}
	}
}

void OpenGreeceGame(GameS& game, AllTextures textures, Font font)
{
	OpenGame(game, textures, font);

	if (!game.isGameOpened)
	{
		DrawRectangle(500, 400, 100, 100, WHITE);
		if (IsMouseInRange(500, 500 + 100, 400, 400 + 100))
		{
			DrawRectangle(500, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				game.openQuiz = true;
				game.openGame = false;
			}
		}
	}
}

void OpenEnglandGame(GameS& game, AllTextures textures, Font font)
{
	OpenGame(game, textures, font);

	if (!game.isGameOpened)
	{
		DrawRectangle(500, 400, 100, 100, WHITE);
		if (IsMouseInRange(500, 500 + 100, 400, 400 + 100))
		{
			DrawRectangle(500, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				game.openQuiz = true;
				game.openGame = false;
			}
		}
	}
}

void OpenNorwayGame(GameS& game, AllTextures textures, Font font)
{
	OpenGame(game, textures, font);

	if (!game.isGameOpened)
	{
		DrawRectangle(500, 400, 100, 100, WHITE);
		if (IsMouseInRange(500, 500 + 100, 400, 400 + 100))
		{
			DrawRectangle(500, 400, 100, 100, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				game.openQuiz = true;
				game.openGame = false;
			}
		}
	}
}