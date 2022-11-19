#include "Main.h"
#include "OpenCountry.h"
#include "GameInCountry.h"


void OpenBulgariaGame(GameS& game, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundBulgaria, 0, 0, WHITE);

	OpenGame(game, textures, font);

	if (!game.isGameOpened)
	{
		DrawTexture(textures.gameLeft, 500, 300, WHITE);
		if (IsMouseInRange(500, 500 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameLeft, 496, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
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
		DrawTexture(textures.gameLeft, 500, 300, WHITE);
		if (IsMouseInRange(500, 500 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameLeft, 496, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
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
		DrawTexture(textures.gameLeft, 500, 300, WHITE);
		if (IsMouseInRange(500, 500 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameLeft, 496, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
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
		DrawTexture(textures.gameLeft, 500, 300, WHITE);
		if (IsMouseInRange(500, 500 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameLeft, 496, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.openQuiz = true;
				game.openGame = false;
			}
		}
	}
}

void OpenGermanyGame(GameS& game, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundGermany, 0, 0, WHITE);

	OpenGame(game, textures, font);

	if (!game.isGameOpened)
	{
		DrawTexture(textures.gameLeft, 500, 300, WHITE);
		if (IsMouseInRange(500, 500 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameLeft, 496, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
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
		DrawTexture(textures.gameLeft, 500, 300, WHITE);
		if (IsMouseInRange(500, 500 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameLeft, 496, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.openQuiz = true;
				game.openGame = false;
			}
		}
	}
}

void OpenGreeceGame(GameS& game, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundGreece, 0, 0, WHITE);

	OpenGame(game, textures, font);

	if (!game.isGameOpened)
	{
		DrawTexture(textures.gameLeft, 500, 300, WHITE);
		if (IsMouseInRange(500, 500 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameLeft, 496, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
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
		DrawTexture(textures.gameLeft, 500, 300, WHITE);
		if (IsMouseInRange(500, 500 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameLeft, 496, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
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
		DrawTexture(textures.gameLeft, 500, 300, WHITE);
		if (IsMouseInRange(500, 500 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameLeft, 496, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.openQuiz = true;
				game.openGame = false;
			}
		}
	}
}