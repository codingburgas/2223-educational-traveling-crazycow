#include "Main.h"
#include "OpenCountry.h"
#include "GameInCountry.h"


void OpenBulgariaGame(GameS& game, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundBulgaria, 0, 0, WHITE);

	Texture2D landmarks[4] = {
		textures.BulgariaLandmark,
		textures.SpainLandmark,
		textures.FranceLandmark,
		textures.ItalyLandmark
	};

	OpenGame(game.gameCounter[0], 1, landmarks, textures.armStageOne, textures.armStageTwo, game, textures, font);

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

	Texture2D landmarks[4] = {
		textures.SpainLandmark,
		textures.GreeceLandmark,
		textures.GermanyLandmark,
		textures.TurkeyLandmark
	};

	OpenGame(game.gameCounter[1], 1, landmarks, textures.armStageOne, textures.armStageTwo, game, textures, font);

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

	Texture2D landmarks[4] = {
		textures.FranceLandmark,
		textures.ItalyLandmark,
		textures.NorwayLandmark,
		textures.SpainLandmark
	};

	OpenGame(game.gameCounter[2], 1, landmarks, textures.armStageOne, textures.armStageTwo, game, textures, font);

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

	Texture2D landmarks[4] = {
		textures.ItalyLandmark,
		textures.GermanyLandmark,
		textures.BulgariaLandmark,
		textures.TurkeyLandmark
	};

	OpenGame(game.gameCounter[3], 1, landmarks, textures.armStageOne, textures.armStageTwo, game, textures, font);

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

	Texture2D landmarks[4] = {
		textures.GermanyLandmark,
		textures.GreeceLandmark,
		textures.EnglandLandmark,
		textures.TurkeyLandmark
	};

	OpenGame(game.gameCounter[4], 1, landmarks, textures.armStageOne, textures.armStageTwo, game, textures, font);

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
	DrawTexture(textures.quizBackgroundTurkey, 0, 0, WHITE);

	Texture2D landmarks[4] = {
		textures.TurkeyLandmark,
		textures.BulgariaLandmark,
		textures.ItalyLandmark,
		textures.FranceLandmark,
	};

	OpenGame(game.gameCounter[5], 1, landmarks, textures.armStageOne, textures.armStageTwo, game, textures, font);

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

	Texture2D landmarks[4] = {
		textures.GreeceLandmark,
		textures.GermanyLandmark,
		textures.SpainLandmark,
		textures.BulgariaLandmark,
	};

	OpenGame(game.gameCounter[6], 1, landmarks, textures.armStageOne, textures.armStageTwo, game, textures, font);

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
	DrawTexture(textures.quizBackgroundEngland, 0, 0, WHITE);

	Texture2D landmarks[4] = {
		textures.EnglandLandmark,
		textures.NorwayLandmark,
		textures.ItalyLandmark,
		textures.BulgariaLandmark
	};

	OpenGame(game.gameCounter[7], 1, landmarks, textures.armStageOne, textures.armStageTwo, game, textures, font);

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
	DrawTexture(textures.quizBackgroundNorway, 0, 0, WHITE);

	Texture2D landmarks[4] = {
		textures.NorwayLandmark,
		textures.FranceLandmark,
		textures.GreeceLandmark,
		textures.GermanyLandmark
	};

	OpenGame(game.gameCounter[8], 1, landmarks, textures.norwayArmS1, textures.norwayArmS2, game, textures, font);

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