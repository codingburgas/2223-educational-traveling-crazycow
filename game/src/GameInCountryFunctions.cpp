#include "Include.h"
#include "GameInCountry.h"
#include "OpenCountry.h"

//After country is chosen country game and quiz section is opened. Draws mini game and quiz background. Displays questions, answers and game textures randomly.

void OpenCountry(int& countryNumber, GameS& game, AllTextures textures, Font font)
{
	switch (countryNumber)
	{
	case 1:
		if (game.openQuiz)
		{
			// Bulgaria Quiz
			OpenBulgariaQuiz(game, textures, font);
		}
		if (game.openGame)
		{
			// Bulgaria Game
			OpenBulgariaGame(game, textures, font);
		}
		break;
	case 2:
		if (game.openQuiz)
		{
			// Spain Quiz
			OpenSpainQuiz(game, textures, font);
		}
		if (game.openGame)
		{
			//Spain Game
			OpenSpainGame(game, textures, font);
		}
		break;
	case 3:
		if (game.openQuiz)
		{
			// France Quiz
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
			// Italy Quiz
			OpenItalyQuiz(game, textures, font);
		}
		if (game.openGame)
		{
			// Italy Game
			OpenItalyGame(game, textures, font);
		}
		break;
	case 5:
		if (game.openQuiz)
		{
			// Germany Quiz
			OpenGermanyQuiz(game, textures, font);
		}
		if (game.openGame)
		{
			// Germany Game
			OpenGermanyGame(game, textures, font);
		}
		break;
	case 6:
		if (game.openQuiz)
		{
			// Turkey Quiz
			OpenTurkeyQuiz(game, textures, font);
		}
		if (game.openGame)
		{
			// Turkey Game
			OpenTurkeyGame(game, textures, font);
		}
		break;
	case 7:
		if (game.openQuiz)
		{
			// Greece Quiz
			OpenGreeceQuiz(game, textures, font);
		}
		if (game.openGame)
		{
			// Greece Game
			OpenGreeceGame(game, textures, font);
		}
		break;
	case 8:
		if (game.openQuiz)
		{
			// England Quiz
			OpenEnglandQuiz(game, textures, font);
		}
		if (game.openGame)
		{
			// England Game
			OpenEnglandGame(game, textures, font);
		}
		break;
	case 9:
		if (game.openQuiz)
		{
			// Norway Quiz
			OpenNorwayQuiz(game, textures, font);
		}
		if (game.openGame)
		{
			// Norway Game
			OpenNorwayGame(game, textures, font);
		}
		break;
	default:
		countryNumber = 0;
	}
}

//Draws quiz background. Displays questions and answers randomly. Takes you hay to start your attempt. After you finish your attempt it gives you hay based on how many right answers you have. After the third attempt closes the quiz.

void OpenQuiz(const char** questions, const char* answers[10][4], int* tPos, int& quizCounter, GameS& game, AllTextures textures, Font font)
{
	if (!game.gameWarning)
	{
		if (quizCounter < 3)
		{
			static vector<int> usedNums;
			if (game.questionsNumberCounter == 5 && game.isQuizOpened)
			{
				DrawTextEx(font, "Result", VecPos(760, 230), 140, 10, BLACK);

				DrawTextEx(font, TextFormat("     You answered correctly   -   %2i/5", game.trueQuestionCounter), VecPos(540, 400), 40, 4, BLACK);

				if (game.trueQuestionCounter != 0)
				{
					DrawTextEx(font, TextFormat("     From this Quiz you gain   -   %2i ", game.trueQuestionCounter * 25), VecPos(540, 500), 40, 4, BLACK);
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
						quizCounter++;
						game.isQuizOpened = false;
						game.money += game.trueQuestionCounter * 25;
						game.trueQuestionCounter = 0;
						game.isDonePressed = true;
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

			
			if (!game.isQuizOpened)
			{
				DrawTexture(textures.quizBox, 0, 0, WHITE);
				DrawTextEx(font, "Quiz", VecPos(660, 280), 300, 12, BLACK);
				DrawTextEx(font, "Price - 50", VecPos(830, 604), 40, 6, BLACK);
				DrawTexture(textures.wheatIcon, 1050, 608, WHITE);
				DrawTextEx(font, TextFormat("Attempts - %2i/3", quizCounter), VecPos(816, 660), 30, 5, BLACK);
				if (IsMouseInRange(660, 660 + 570, 280, 280 + 280))
				{
					DrawTextEx(font, "Quiz", VecPos(664, 274), 300, 12, BLACK);
					if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
					{
						PlaySoundMulti(textures.clickSound);
						if (game.money >= 50)
						{
							game.isQuizOpened = true;
							game.money -= 50;
							game.questionsNumberCounter = 0;
							usedNums.clear();
						}
						else
						{
							game.gameWarning = true;
						}
					}
				}
			}
		}
		else
		{
			DrawTextEx(font, "Over", VecPos(660, 280), 300, 12, BLACK);
			DrawTextEx(font, TextFormat("Attempts - %2i/3", quizCounter), VecPos(816, 660), 30, 5, BLACK);
		}
	}
	else
	{
		DrawTexture(textures.quizBox, 0, 0, WHITE);
		DrawTextEx(font, "Not enough", VecPos(680, 300), 100, 8, BLACK);
		DrawTextEx(font, "money!", VecPos(790, 400), 100, 8, BLACK);

		DrawTexture(textures.answerBlock, 800, 560, WHITE);
		DrawTextEx(font, "Ok", VecPos(800 + 100, 560 + 30), 60, 6, BLACK);
		if (IsMouseInRange(800, 800 + 300, 560, 560 + 120))
		{
			DrawTextEx(font, "Ok", VecPos(800 + 102, 560 + 26), 60, 6, BLACK);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.gameWarning = false;
			}
		}
	}
}

//Sets randomly answer position

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

// Checks if you answered correctly

void Answer(int tPos, int tPosVal, int x1, int y1, const char** answers, GameS& game, AllTextures textures, Font font)
{
	if (IsMouseInRange(x1, x1 + 300, y1, y1 + 120))
	{
		DrawTextEx(font, answers[tPosVal - 1], VecPos((float)(x1 + 22), (float)(y1 + 47)), 34, 4, BLACK);
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

// Draws mini game background. Displays mini game frames randomly. Takes you hay to start your attempt.
// After you finish your attempt it gives you hay if you choose the right frame. After the third attempt closes the mini game.

void OpenGame(int& gameCounter, int landmarkPos, Texture2D landmarks[4], Texture2D background, Texture2D armOne, Texture2D armTwo,
			  GameS& game, AllTextures textures, Font font)
{
	static vector<int> usedNums;
	static int randomNums[4] = { 0, 0, 0, 0 };
	if (!game.gameWarning)
	{
		if (gameCounter < 3)
		{
			DrawTexture(textures.quizBox, 0, 0, WHITE);
			if (!game.isGameOpened)
			{
				DrawTextEx(font, "Game", VecPos(650, 300), 300, 12, BLACK);
				DrawTextEx(font, TextFormat("Attempts - %2i/3", gameCounter), VecPos(816, 660), 30, 5, BLACK);
				DrawTextEx(font, "Price - 25", VecPos(830, 604), 40, 6, BLACK);
				DrawTexture(textures.wheatIcon, 1050, 608, WHITE);
				if (!game.isArrowPressed)
				{
					if (IsMouseInRange(650, 650 + 690, 320, 320 + 250))
					{
						DrawTextEx(font, "Game", VecPos(654, 294), 300, 12, BLACK);
						if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
						{
							PlaySoundMulti(textures.clickSound);
							if (game.money >= 25)
							{
								game.isGameOpened = true;
								game.money -= 25;

								for (int i = 0; i < 4; i++)
								{
									randomNums[i] = 1 + (rand() % 4);
									while (find(usedNums.begin(), usedNums.end(), randomNums[i]) != usedNums.end())
									{
										randomNums[i] = 1 + (rand() % 4);
									}
									usedNums.push_back(randomNums[i]);
								}
								usedNums.clear();
							}
							else
							{
								game.gameWarning = true;
							}
						}
					}
				}
				else
				{
					game.isArrowPressed = false;
				}
			}
			else
			{
				if (!game.gameWin && !game.gameLoose)
				{
					DrawTexture(background, 0, 0, WHITE);
					
					DrawTexture(landmarks[randomNums[0] - 1], 470, 200, WHITE);
					DrawTexture(landmarks[randomNums[1] - 1], 740, 200, WHITE);
					DrawTexture(landmarks[randomNums[2] - 1], 1010, 200, WHITE);
					DrawTexture(landmarks[randomNums[3] - 1], 1280, 200, WHITE);

					if (!game.flyingDart)
					{
						DrawTexture(armOne, game.armX, game.armY, WHITE);
					}
					else
					{
						DrawTexture(armTwo, game.armX, game.armY, WHITE);
					}

					DrawTexture(textures.dart, game.dartX, game.dartY, WHITE);

					if (!game.flyingDart)
					{
						MoveArm(game);

						if (IsKeyPressed(KEY_SPACE))
						{
							if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_SPACE))
							{
								game.flyingDart = true;
							}
						}
					}

					int currentFPS = GetFPS();
					int dartMove = 0;

					if (currentFPS <= 30)
					{
						dartMove = 16;
					}
					else if (currentFPS > 30 && currentFPS <= 60)
					{
						dartMove = 8;
					}
					else
					{
						dartMove = 4;
					}

					if (game.flyingDart)
					{
						if (game.dartX >= 400 && game.dartX >= game.armX + 300 - 250)
						{
							game.dartX -= dartMove;
						}
					}

					if (game.flyingDart)
					{
						if (!IsMissed(randomNums, landmarkPos, game))
						{
							DrawTexture(textures.answerBlock, 5, 876, WHITE);
							DrawTextEx(font, "Ok", VecPos(5 + 100, 876 + 30), 60, 6, BLACK);
							if (IsMouseInRange(5, 5 + 300, 876, 876 + 120))
							{
								DrawTextEx(font, "Ok", VecPos(5 + 102, 876 + 26), 60, 6, BLACK);
								if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
								{
									PlaySoundMulti(textures.clickSound);
									game.flyingDart = false;
									game.armX = 600;
									game.armY = 700;
									game.dartX = game.armX + 294;
									game.dartY = game.armY - 4;
									game.gameWin = true;
								}
							}
						}
						else
						{
							DrawTexture(textures.answerBlock, 5, 876, WHITE);
							DrawTextEx(font, "Ok", VecPos(5 + 100, 876 + 30), 60, 6, BLACK);
							if (IsMouseInRange(5, 5 + 300, 876, 876 + 120))
							{
								DrawTextEx(font, "Ok", VecPos(5 + 102, 876 + 26), 60, 6, BLACK);
								if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
								{
									PlaySoundMulti(textures.clickSound);
									game.flyingDart = false;
									game.armX = 600;
									game.armY = 700;
									game.dartX = game.armX + 294;
									game.dartY = game.armY - 4;
									game.gameLoose = true;
								}
							}
						}
					}
				}
				else if (game.gameWin)
				{
					DrawTextEx(font, "You hit!", VecPos(650, 300), 200, 12, BLACK);
					DrawTextEx(font, "You win - 50", VecPos(820, 500), 40, 4, BLACK);
					DrawTexture(textures.wheatIcon, 1100 - 10, 500, WHITE);
					DrawTexture(textures.answerBlock, 800, 560, WHITE);
					DrawTextEx(font, "Done", VecPos(800 + 70, 560 + 30), 60, 6, BLACK);
					if (IsMouseInRange(800, 800 + 300, 560, 560 + 120))
					{
						DrawTextEx(font, "Done", VecPos(800 + 72, 560 + 26), 60, 6, BLACK);
						if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
						{
							PlaySoundMulti(textures.clickSound);
							game.money += 50;
							game.isGameOpened = false;
							game.gameWin = false;
							gameCounter++;
							game.isDonePressed = true;
						}
					}
				}
				else
				{
					DrawTextEx(font, "Missed", VecPos(650, 300), 200, 12, BLACK);
					DrawTexture(textures.answerBlock, 800, 560, WHITE);
					DrawTextEx(font, "Done", VecPos(800 + 70, 560 + 30), 60, 6, BLACK);
					if (IsMouseInRange(800, 800 + 300, 560, 560 + 120))
					{
						DrawTextEx(font, "Done", VecPos(800 + 72, 560 + 26), 60, 6, BLACK);
						if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
						{
							PlaySoundMulti(textures.clickSound);
							game.isGameOpened = false;
							game.gameLoose = false;
							gameCounter++;
							game.isDonePressed = true;
						}
					}
				}
			}
		}
		else
		{
			DrawTextEx(font, "Over", VecPos(660, 280), 300, 12, BLACK);
			DrawTextEx(font, TextFormat("Attempts - %2i/3", gameCounter), VecPos(816, 660), 30, 5, BLACK);
		}
	}
	else
	{
		DrawTexture(textures.quizBox, 0, 0, WHITE);
		DrawTextEx(font, "Not enough", VecPos(680, 300), 100, 8, BLACK);
		DrawTextEx(font, "money!", VecPos(790, 400), 100, 8, BLACK);

		DrawTexture(textures.answerBlock, 800, 560, WHITE);
		DrawTextEx(font, "Ok", VecPos(800 + 100, 560 + 30), 60, 6, BLACK);
		if (IsMouseInRange(800, 800 + 300, 560, 560 + 120))
		{
			DrawTextEx(font, "Ok", VecPos(800 + 102, 560 + 26), 60, 6, BLACK);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.gameWarning = false;
			}
		}
	}
}

// When mini game is opened displays an arm that holds dart that can move up, down, right and left and when space pressed throw the dart.

void MoveArm(GameS& game)
{
	int currentFPS = GetFPS();
	int armMove = 0;

	if (currentFPS <= 30)
	{
		armMove = 6;
	}
	else if (currentFPS > 30 && currentFPS <= 60)
	{
		armMove = 3;
	}
	else
	{
		armMove = 1;
	}

	if (IsKeyDown(KEY_S) && IsKeyDown(KEY_A))
	{
		if (game.armY <= 650)
		{
			game.armY += armMove;
			game.dartY += armMove;
		}
		if (game.armX + 294 >= 400)
		{
			game.armX -= armMove;
			game.dartX -= armMove;
		}
	}
	else if (IsKeyDown(KEY_S) && IsKeyDown(KEY_D))
	{
		if (game.armY <= 650)
		{
			game.armY += armMove;
			game.dartY += armMove;
		}
		if (game.armX + 294 <= 1700)
		{
			game.armX += armMove;
			game.dartX += armMove;
		}
	}
	else if (IsKeyDown(KEY_W) && IsKeyDown(KEY_A))
	{
		if (game.armY >= 260)
		{
			game.armY -= armMove;
			game.dartY -= armMove;
		}
		if (game.armX + 294 >= 400)
		{
			game.armX -= armMove;
			game.dartX -= armMove;
		}
	}
	else if (IsKeyDown(KEY_W) && IsKeyDown(KEY_D))
	{
		if (game.armY >= 260)
		{
			game.armY -= armMove;
			game.dartY -= armMove;
		}
		if (game.armX + 294 <= 1700)
		{
			game.armX += armMove;
			game.dartX += armMove;
		}
	}
	else if (IsKeyDown(KEY_A) && game.armX + 294 >= 400)
	{
		game.armX -= armMove;
		game.dartX -= armMove;
	}
	else if (IsKeyDown(KEY_D) && game.armX + 294 <= 1700)
	{
		game.armX += armMove;
		game.dartX += armMove;
	}
	else if (IsKeyDown(KEY_W) && game.armY >= 260)
	{
		game.armY -= armMove;
		game.dartY -= armMove;
	}
	else if (IsKeyDown(KEY_S) && game.armY <= 650)
	{
		game.armY += armMove;
		game.dartY += armMove;
	}
}

// Checks if you missed the frame

bool IsMissed(int randomNums[4], int landmarkPos, GameS& game)
{
	for (int i = 0; i < 4; i++)
	{
		if (randomNums[i] == landmarkPos)
		{
			if (IsHit(i + 1, game))
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
	return true;
}

//Checks if you hited the right frame

bool IsHit(int landmarkPos, GameS& game)
{
	switch (landmarkPos)
	{
	case 1:
		if (game.dartX >= 470 && game.dartX <= 470 + 250 && game.dartY >= 300 && game.dartY <= 700)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 2:
		if (game.dartX >= 740 && game.dartX <= 740 + 250 && game.dartY >= 300 && game.dartY <= 700)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 3:
		if (game.dartX >= 1010 && game.dartX <= 1010 + 250 && game.dartY >= 300 && game.dartY <= 700)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 4:
		if (game.dartX >= 1280 && game.dartX <= 1280 + 250 && game.dartY >= 300 && game.dartY <= 700)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	default:
		return false;
	}
}