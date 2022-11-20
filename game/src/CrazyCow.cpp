#include "Main.h"
#include "CrazyCow.h"

void CrazyCow(FlyingCows& cows, GameS& game, MenuS& menu, AllTextures textures, Font font)
{
	if (cows.isCCOpen)
	{
		UpdateMusicStream(textures.menuMusic);

		DrawTexture(textures.crazyCowBG, 0, 0, WHITE);

		DrawTextEx(font, TextFormat("%2i", cows.dartsLeft), VecPos(1800, 5), 32, 4, BLACK);
		DrawTexture(textures.miniDart, 1836, 5, WHITE);

		for (int i = 0; i < 10; i++)
		{
			FlyingCow(i, cows, game, textures);
		}

		if (!game.flyingDart)
		{
			DrawTexture(textures.armStageOne, game.armX, game.armY, WHITE);
			if (cows.dartsLeft > 0)
			{
				MoveArmCC(game);

				if (IsMouseInRange(game.armX, game.armX + 100, game.armY, game.armY + 300) || IsKeyPressed(KEY_SPACE))
				{
					if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_SPACE))
					{
						game.flyingDart = true;
						cows.dartsLeft--;
					}
				}
			}
		}
		else
		{
			MoveArmCC(game);
			DrawTexture(textures.armStageTwo, game.armX, game.armY, WHITE);
		}

		DrawTexture(textures.dart, game.dartX, game.dartY, WHITE);

		


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
			if (game.dartX >= 0 && game.dartX >= game.armX - 250)
			{
				game.dartX -= dartMove;
			}
			else
			{
				game.flyingDart = false;
				game.dartX = game.armX - 10;
				game.dartY = game.armY - 10;
			}
		}

		if (cows.downCowsCounter == 9 || cows.dartsLeft == 0)
		{
			FinishCrazyCow(cows, game, menu, textures, font);
		}
	}
}

void MoveArmCC(GameS& game)
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
		if (game.armY <= 800)
		{
			game.armY += armMove;
			game.dartY += armMove;
		}
		if (game.armX >= 260)
		{
			game.armX -= armMove;
			game.dartX -= armMove;
		}
	}
	else if (IsKeyDown(KEY_S) && IsKeyDown(KEY_D))
	{
		if (game.armY <= 800)
		{
			game.armY += armMove;
			game.dartY += armMove;
		}
		if (game.armX <= 1800)
		{
			game.armX += armMove;
			game.dartX += armMove;
		}
	}
	else if (IsKeyDown(KEY_W) && IsKeyDown(KEY_A))
	{
		if (game.armY >= 20)
		{
			game.armY -= armMove;
			game.dartY -= armMove;
		}
		if (game.armX >= 260)
		{
			game.armX -= armMove;
			game.dartX -= armMove;
		}
	}
	else if (IsKeyDown(KEY_W) && IsKeyDown(KEY_D))
	{
		if (game.armY >= 20)
		{
			game.armY -= armMove;
			game.dartY -= armMove;
		}
		if (game.armX <= 1800)
		{
			game.armX += armMove;
			game.dartX += armMove;
		}
	}
	else if (IsKeyDown(KEY_A) && game.armX >= 260)
	{
		game.armX -= armMove;
		game.dartX -= armMove;
	}
	else if (IsKeyDown(KEY_D) && game.armX <= 1800)
	{
		game.armX += armMove;
		game.dartX += armMove;
	}
	else if (IsKeyDown(KEY_W) && game.armY >= 20)
	{
		game.armY -= armMove;
		game.dartY -= armMove;
	}
	else if (IsKeyDown(KEY_S) && game.armY <= 800)
	{
		game.armY += armMove;
		game.dartY += armMove;
	}
}

void FlyingCow(int cowNum, FlyingCows& cows, GameS& game, AllTextures textures)
{
	int currentFPS = GetFPS();
	int cowMove = 0;

	if (currentFPS <= 30)
	{
		cowMove = 12;
	}
	else if (currentFPS > 30 && currentFPS <= 60)
	{
		cowMove = 6;
	}
	else
	{
		cowMove = 3;
	}

	if (!cows.downCows[cowNum])
	{
		if (cows.cowDir[cowNum])
		{
			DrawTexture(textures.flyingCowRight, cows.cowsX[cowNum], cows.cowsY[cowNum], WHITE);
		}
		else
		{
			DrawTexture(textures.flyingCowLeft, cows.cowsX[cowNum], cows.cowsY[cowNum], WHITE);
		}
	}
	else
	{
		if (cows.cowDir[cowNum])
		{
			DrawTexture(textures.fallenCowRight, cows.cowsX[cowNum], cows.cowsY[cowNum], WHITE);
		}
		else
		{
			DrawTexture(textures.fallenCowLeft, cows.cowsX[cowNum], cows.cowsY[cowNum], WHITE);
		}
	}
	

	if (!cows.downCows[cowNum])
	{
		cows.cowsCounters[cowNum]++;
		if (cows.cowsCounters[cowNum] >= 100)
		{
			cows.randomNums[cowNum] = 1 + (rand() % 8);
			cows.cowsCounters[cowNum] = 0;
		}

		switch (cows.randomNums[cowNum])
		{
		case 1:
			if (cows.cowsX[cowNum] >= 1840)
			{
				cows.randomNums[cowNum] = 1 + (rand() % 8);
			}
			else
			{
				cows.cowDir[cowNum] = true;
				cows.cowsX[cowNum] += cowMove;
			}
			break;
		case 2:
			if (cows.cowsX[cowNum] <= 40)
			{
				cows.randomNums[cowNum] = 1 + (rand() % 8);
			}
			else
			{
				cows.cowDir[cowNum] = false;
				cows.cowsX[cowNum] -= cowMove;
			}
			break;
		case 3:
			if (cows.cowsY[cowNum] >= 400)
			{
				cows.randomNums[cowNum] = 1 + (rand() % 8);
			}
			else
			{
				cows.cowsY[cowNum] += cowMove;
			}
			break;
		case 4:
			if (cows.cowsY[cowNum] <= 40)
			{
				cows.randomNums[cowNum] = 1 + (rand() % 6);
			}
			else
			{
				cows.cowsY[cowNum] -= cowMove;
			}
			break;
		case 5:
			if (cows.cowsX[cowNum] >= 1840 || cows.cowsY[cowNum] >= 400)
			{
				cows.randomNums[cowNum] = 1 + (rand() % 6);
			}
			else
			{
				cows.cowDir[cowNum] = true;
				cows.cowsX[cowNum] += cowMove;
				cows.cowsY[cowNum] += cowMove;
			}
			break;
		case 6:
			if (cows.cowsX[cowNum] >= 1840 || cows.cowsY[cowNum] <= 40)
			{
				cows.randomNums[cowNum] = 1 + (rand() % 6);
			}
			else
			{
				cows.cowDir[cowNum] = true;
				cows.cowsX[cowNum] += cowMove;
				cows.cowsY[cowNum] -= cowMove;
			}
			break;
		case 7:
			if (cows.cowsX[cowNum] <= 40 || cows.cowsY[cowNum] >= 400)
			{
				cows.randomNums[cowNum] = 1 + (rand() % 6);
			}
			else
			{
				cows.cowDir[cowNum] = false;
				cows.cowsX[cowNum] -= cowMove;
				cows.cowsY[cowNum] += cowMove;
			}
			break;
		case 8:
			if (cows.cowsX[cowNum] <= 40 || cows.cowsY[cowNum] <= 40)
			{
				cows.randomNums[cowNum] = 1 + (rand() % 6);
			}
			else
			{
				cows.cowDir[cowNum] = false;
				cows.cowsX[cowNum] -= cowMove;
				cows.cowsY[cowNum] -= cowMove;
			}
			break;
		default:
			cows.randomNums[cowNum] = 1 + (rand() % 6);
		}

		HitCow(cowNum, cows, game);
	}
	else
	{
		if (cows.cowsY[cowNum] <= 700)
		{
			cows.cowsY[cowNum] += cowMove;
		}
	}
}

void HitCow(int cowNum, FlyingCows& cows, GameS& game)
{
	if (game.flyingDart && game.dartX <= game.armX - 230)
	{
		if (game.dartX >= cows.cowsX[cowNum] && game.dartX <= cows.cowsX[cowNum] + 100 &&
			game.dartY + 10 >= cows.cowsY[cowNum] && game.dartY + 10 <= cows.cowsY[cowNum] + 150)
		{
			cows.downCows[cowNum] = true;
			cows.downCowsCounter++;
		}
	}
}

void OpenCrazyCow(FlyingCows& cows, GameS& game, MenuS& menu, MapS& map, AllTextures textures, Font font)
{
	if ((game.money == 0 || NeedMoney(game, map.unlockedCountries)) && !cows.isCCOver)
	{
		if (!cows.CCWarning)
		{
			DrawTexture(textures.startBlock, 1900 - 480, 840, WHITE);
			DrawTextEx(font, "CrazyCow", VecPos(1900 - 480 + 84, 876), 70, 4, BLACK);
			if (IsMouseInRange(1900 - 480, 1900, 840, 840 + 149))
			{
				DrawTextEx(font, "CrazyCow", VecPos(1900 - 480 + 86, 873), 70, 4, BLACK);
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					PlaySoundMulti(textures.clickSound);
					map.openMap = false;
					menu.isMenuOpen = false;

					cows.CCWarning = true;
				}
			}
		}
		else
		{
			DrawTexture(textures.crazyCowBG, 0, 0, WHITE);
			DrawTexture(textures.quizBox, 0, 0, WHITE);
			DrawTextEx(font, "Are you sure?", VecPos(560, 290), 120, 8, BLACK);

			DrawTextEx(font, "You have 1 Attempt!", VecPos(750, 420), 40, 4, BLACK);

			DrawTexture(textures.answerBlock, 540, 520, WHITE);
			DrawTextEx(font, "Yes", VecPos(540 + 120, 520 + 50), 34, 4, BLACK);

			DrawTexture(textures.answerBlock, 540 + 500, 520, WHITE);
			DrawTextEx(font, "No", VecPos(540 + 500 + 134, 520 + 50), 34, 4, BLACK);

			if (IsMouseInRange(540, 540 + 300, 520, 520 + 120))
			{
				DrawTextEx(font, "Yes", VecPos(540 + 122, 520 + 48), 34, 4, BLACK);

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					cows.isCCOpen = true;
					cows.CCWarning = false;
				}
			}

			if (IsMouseInRange(540 + 500, 540 + 500 + 300, 520, 520 + 120))
			{
				DrawTextEx(font, "No", VecPos(540 + 500 + 136, 520 + 48), 34, 4, BLACK);

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					PlaySoundMulti(textures.clickSound);
					menu.isMenuOpen = true;
					cows.CCWarning = false;
				}
			}
		}
	}
}

bool NeedMoney(GameS& game, int unlockedCountries)
{
	static int count = 0;
	for (int i = 0; i < 9; i++)
	{
		if (game.quizCounter[i] == 3 && game.gameCounter[i] == 3)
		{
			count++;
		}
	}

	if (count == unlockedCountries && game.money < 200)
	{
		count = 0;
		return true;
	}
	else
	{
		count = 0;
		return false;
	}
}

void FinishCrazyCow(FlyingCows& cows, GameS& game, MenuS& menu, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBox, 0, 0, WHITE);

	DrawTextEx(font, "Good Job!", VecPos(580, 300), 160, 8, BLACK);
	DrawTextEx(font, TextFormat("You win - %2i", cows.downCowsCounter * 25), VecPos(810, 500), 40, 4, BLACK);
	DrawTexture(textures.wheatIcon, 1100 - 10, 500, WHITE);

	DrawTexture(textures.answerBlock, 800, 560, WHITE);
	DrawTextEx(font, "Done", VecPos(800 + 70, 560 + 30), 60, 6, BLACK);
	if (IsMouseInRange(800, 800 + 300, 560, 560 + 120))
	{
		DrawTextEx(font, "Done", VecPos(800 + 72, 560 + 26), 60, 6, BLACK);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			PlaySoundMulti(textures.clickSound);
			cows.isCCOpen = false;
			cows.isCCOver = true;
			menu.isMenuOpen = true;
			game.money += cows.downCowsCounter * 25;

			game.armX = 900;
			game.armY = 700;
			game.dartX = game.armX - 10;
			game.dartY = game.armY - 10;
		}
	}
}