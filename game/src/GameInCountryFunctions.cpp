#include "Main.h"
#include "GameInCountry.h"
#include "OpenCountry.h"

void OpenCountry(int& countryNumber, GameS& game, AllTextures textures, Font font)
{
	switch (countryNumber)
	{
	case 1:
		if (game.openQuiz)
		{
			OpenBulgariaQuiz(game, textures, font);
		}
		if (game.openGame)
		{
			OpenBulgariaGame(game, textures, font);
		}
		break;
	case 2:
		if (game.openQuiz)
		{
			OpenSpainQuiz(game, textures, font);
		}
		if (game.openGame)
		{
			OpenSpainGame(game, textures, font);
		}
		break;
	case 3:
		if (game.openQuiz)
		{
			OpenFranceQuiz(game, textures, font);
		}
		if (game.openGame)
		{
			OpenFranceGame(game, textures, font);
		}
		break;
	case 4:
		if (game.openQuiz)
		{
			OpenItalyQuiz(game, textures, font);
		}
		if (game.openGame)
		{
			OpenItalyGame(game, textures, font);
		}
		break;
	case 5:
		if (game.openQuiz)
		{
			OpenGermanyQuiz(game, textures, font);
		}
		if (game.openGame)
		{
			OpenGermanyGame(game, textures, font);
		}
		break;
	case 6:
		if (game.openQuiz)
		{
			OpenTurkeyQuiz(game, textures, font);
		}
		if (game.openGame)
		{
			OpenTurkeyGame(game, textures, font);
		}
		break;
	case 7:
		if (game.openQuiz)
		{
			OpenGreeceQuiz(game, textures, font);
		}
		if (game.openGame)
		{
			OpenGreeceGame(game, textures, font);
		}
		break;
	case 8:
		if (game.openQuiz)
		{
			OpenEnglandQuiz(game, textures, font);
		}
		if (game.openGame)
		{
			OpenEnglandGame(game, textures, font);
		}
		break;
	case 9:
		if (game.openQuiz)
		{
			OpenNorwayQuiz(game, textures, font);
		}
		if (game.openGame)
		{
			OpenNorwayGame(game, textures, font);
		}
		break;
	default:
		countryNumber = 0;
	}
}

void OpenQuiz(const char** questions, const char* answers[10][4], int* tPos, GameS& game, AllTextures textures, Font font)
{
	static vector<int> usedNums;
	DrawTexture(textures.quizBox, 0, 0, WHITE);
	if (!game.isQuizOpened)
	{
		DrawTextEx(font, "Quiz", VecPos(660, 280), 300, 12, BLACK);
		DrawTextEx(font, "Price - 10", VecPos(826, 620), 40, 6, BLACK);
		DrawTexture(textures.wheatIcon, 1050, 620, WHITE);
		if (IsMouseInRange(660, 660 + 570, 280, 280 + 280))
		{
			DrawTextEx(font, "Quiz", VecPos(664, 274), 300, 12, BLACK);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.isQuizOpened = true;
				game.money -= 10;
				game.questionsNumberCounter = 0;
				usedNums.clear();
			}
		}
	}

	if (game.questionsNumberCounter == 5 && game.isQuizOpened)
	{
		DrawTextEx(font, "Result", VecPos(760, 230), 140, 10, BLACK);

		DrawTextEx(font, TextFormat("     You answered correctly   -   %2i/5", game.trueQuestionCounter), VecPos(540, 400), 40, 4, BLACK);

		if (game.trueQuestionCounter != 0)
		{
			DrawTextEx(font, TextFormat("     From this Quiz you gain   -   %2i ", game.trueQuestionCounter * 20), VecPos(540, 500), 40, 4, BLACK);
			DrawTexture(textures.wheatIcon, 1300, 500, WHITE);
		}
		else
		{
			DrawTextEx(font, "     From this Quiz you gain    -    0 ", VecPos(540, 500), 40, 4, BLACK);
			DrawTexture(textures.wheatIcon, 1300, 500, WHITE);
		}
		

		DrawTexture(textures.answerBlock, 800, 560, WHITE);
		DrawTextEx(font, "Done", VecPos(800 + 70, 560 + 30), 60, 6, BLACK);
		if (IsMouseInRange(800, 800 + 300, 560, 560 + 120))
		{
			DrawTextEx(font, "Done", VecPos(800 + 72, 560 + 26), 60, 6, BLACK);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.isQuizOpened = false;
				game.money += game.trueQuestionCounter * 20;
				game.trueQuestionCounter = 0;
			}
		}
	}

	if (game.questionsNumberCounter < 5 && game.isQuizOpened)
	{
		if (game.isAnswered)
		{
			game.randomQuestion = 1 + (rand() % 10);
			while (find(usedNums.begin(), usedNums.end(), game.randomQuestion) != usedNums.end())
			{
				game.randomQuestion = 1 + (rand() % 10);
			}
			usedNums.push_back(game.randomQuestion);
			game.isAnswered = false;
		}

		switch (game.randomQuestion)
		{
		case 1:
			AnswerPosition(tPos[0], questions[0], answers[0], game, textures, font);
			break;
		case 2:
			AnswerPosition(tPos[1], questions[1], answers[1], game, textures, font);
			break;
		case 3:
			AnswerPosition(tPos[2], questions[2], answers[2], game, textures, font);
			break;
		case 4:
			AnswerPosition(tPos[3], questions[3], answers[3], game, textures, font);
			break;
		case 5:
			AnswerPosition(tPos[4], questions[4], answers[4], game, textures, font);
			break;
		case 6:
			AnswerPosition(tPos[5], questions[5], answers[5], game, textures, font);
			break;
		case 7:
			AnswerPosition(tPos[6], questions[6], answers[6], game, textures, font);
			break;
		case 8:
			AnswerPosition(tPos[7], questions[7], answers[7], game, textures, font);
			break;
		case 9:
			AnswerPosition(tPos[8], questions[8], answers[8], game, textures, font);
			break;
		case 10:
			AnswerPosition(tPos[9], questions[9], answers[9], game, textures, font);
			break;
		}
	}
}

void AnswerPosition(int tPos, const char* question, const char** answers, GameS& game, AllTextures textures, Font font)
{
	DrawTextEx(font, question, VecPos(560, 260), 50, 5, BLACK);

	DrawTexture(textures.answerBlock, 540, 440, WHITE);
	DrawTextEx(font, answers[0], VecPos(540 + 20, 440 + 50), 34, 4, BLACK);

	DrawTexture(textures.answerBlock, 540 + 500, 440, WHITE);
	DrawTextEx(font, answers[1], VecPos(540 + 500 + 20, 440 + 50), 34, 4, BLACK);

	DrawTexture(textures.answerBlock, 540, 440 + 140, WHITE);
	DrawTextEx(font, answers[2], VecPos(540 + 20, 440 + 140 + 50), 34, 4, BLACK);

	DrawTexture(textures.answerBlock, 540 + 500, 440 + 140, WHITE);
	DrawTextEx(font, answers[3], VecPos(540 + 500 + 20, 440 + 140 + 50), 34, 4, BLACK);

	Answer(tPos, 1, 540, 440, answers, game, textures, font);
	Answer(tPos, 2, 540 + 500, 440, answers, game, textures, font);
	Answer(tPos, 3, 540, 440 + 140, answers, game, textures, font);
	Answer(tPos, 4, 540 + 500, 440 + 140, answers, game, textures, font);
}

void Answer(int tPos, int tPosVal, int x1, int y1, const char** answers, GameS& game, AllTextures textures, Font font)
{
	if (IsMouseInRange(x1, x1 + 300, y1, y1 + 120))
	{
		DrawTextEx(font, answers[tPosVal - 1], VecPos(x1 + 22, y1 + 47), 34, 4, BLACK);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			if (tPos == tPosVal)
			{
				PlaySoundMulti(textures.clickSound);
				game.questionsNumberCounter += 1;
				game.trueQuestionCounter += 1;
				game.isAnswered = true;
			}
			else
			{
				PlaySoundMulti(textures.clickSound);
				game.questionsNumberCounter += 1;
				game.isAnswered = true;
			}
		}
	}
}

void OpenGame(GameS& game, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBox, 0, 0, WHITE);
	if (!game.isGameOpened)
	{
		DrawTextEx(font, "Game", VecPos(630, 280), 300, 12, BLACK);
		DrawTextEx(font, "Price - 10", VecPos(826, 620), 40, 6, BLACK);
		DrawTexture(textures.wheatIcon, 1050, 620, WHITE);
		if (IsMouseInRange(630, 630 + 690, 300, 300 + 250))
		{
			DrawTextEx(font, "Game", VecPos(634, 274), 300, 12, BLACK);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.isGameOpened = true;
				game.money -= 10;
			}
		}
	}
}