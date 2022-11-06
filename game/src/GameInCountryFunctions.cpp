#include "Functions.h"

vector<int> usedNums;

void OpenCountry(int* countryNumber, int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion,
				 bool* isQuizOpened, bool* isAnswered, AllTextures textures, Font font)
{
	switch (*countryNumber)
	{
	case 1:
		OpenBulgaria(money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isQuizOpened, isAnswered, textures, font);
		break;
	case 2:
		OpenSpain(money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isQuizOpened, isAnswered, textures, font);
		break;
	case 3:
		OpenFrance(money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isQuizOpened, isAnswered, textures, font);
		break;
	case 4:
		OpenItaly(money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isQuizOpened, isAnswered, textures, font);
		break;
	case 5:
		OpenGermany(money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isQuizOpened, isAnswered, textures, font);
		break;
	case 6:
		OpenTurkey(money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isQuizOpened, isAnswered, textures, font);
		break;
	case 7:
		OpenGreece(money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isQuizOpened, isAnswered, textures, font);
		break;
	case 8:
		OpenEngland(money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isQuizOpened, isAnswered, textures, font);
		break;
	case 9:
		OpenNorway(money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isQuizOpened, isAnswered, textures, font);
		break;
	default:
		*countryNumber = 0;
	}
}

void OpenQuiz(const char** questions, const char* answers[10][4], int* tPos, int* money, int* trueQuestionCounter,
			  int* questionsNumberCounter, int* randomQuestion,bool* isAnswered, bool* isQuizOpened, AllTextures textures, Font font)
{

	DrawTexture(textures.quizBox, 0, 0, WHITE);
	if (!*isQuizOpened)
	{
		DrawTextEx(font, "Quiz", VecPos(660, 280), 300, 12, BLACK);
		DrawTextEx(font, "Price - 10", VecPos(826, 620), 40, 6, BLACK);
		DrawTexture(textures.wheatIcon, 1050, 620, WHITE);
		if (IsMouseInRange(660, 660 + 570, 280, 280 + 280))
		{
			DrawTextEx(font, "Quiz", VecPos(664, 274), 300, 12, BLACK);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				*isQuizOpened = true;
				*money -= 10;
				*questionsNumberCounter = 0;
				usedNums.clear();
			}
		}
	}

	if (*questionsNumberCounter == 5 && *isQuizOpened)
	{
		DrawTextEx(font, "Result", VecPos(760, 230), 140, 10, BLACK);

		DrawTextEx(font, TextFormat("You answered correctly    -    %02i/5", *trueQuestionCounter), VecPos(540, 400), 40, 4, BLACK);

		if (*trueQuestionCounter != 0)
		{
			DrawTextEx(font, TextFormat("From this Quiz you gain    -    %02i ", *trueQuestionCounter * 20), VecPos(540, 500), 40, 4, BLACK);
			DrawTexture(textures.wheatIcon, 1240, 500, WHITE);
		}
		else
		{
			DrawTextEx(font, "From this Quiz you gain    -    0 ", VecPos(540, 500), 40, 4, BLACK);
			DrawTexture(textures.wheatIcon, 1240, 500, WHITE);
		}
		

		DrawTexture(textures.answerBlock, 800, 560, WHITE);
		DrawTextEx(font, "Done", VecPos(800 + 70, 560 + 30), 60, 6, BLACK);
		if (IsMouseInRange(800, 800 + 300, 560, 560 + 120))
		{
			DrawTextEx(font, "Done", VecPos(800 + 72, 560 + 26), 60, 6, BLACK);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				*isQuizOpened = false;
				*money += *trueQuestionCounter * 20;
				*trueQuestionCounter = 0;
			}
		}
	}

	if (*questionsNumberCounter < 5 && *isQuizOpened)
	{
		if (*isAnswered)
		{
			*randomQuestion = 1 + (rand() % 10);
			while (find(usedNums.begin(), usedNums.end(), *randomQuestion) != usedNums.end())
			{
				*randomQuestion = 1 + (rand() % 10);
			}
			usedNums.push_back(*randomQuestion);
			*isAnswered = false;
		}

		switch (*randomQuestion)
		{
		case 1:
			AnswerPosition(tPos[0], questions[0], answers[0], trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered, textures, font);
			break;
		case 2:
			AnswerPosition(tPos[1], questions[1], answers[1], trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered, textures, font);
			break;
		case 3:
			AnswerPosition(tPos[2], questions[2], answers[2], trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered, textures, font);
			break;
		case 4:
			AnswerPosition(tPos[3], questions[3], answers[3], trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered, textures, font);
			break;
		case 5:
			AnswerPosition(tPos[4], questions[4], answers[4], trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered, textures, font);
			break;
		case 6:
			AnswerPosition(tPos[5], questions[5], answers[5], trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered, textures, font);
			break;
		case 7:
			AnswerPosition(tPos[6], questions[6], answers[6], trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered, textures, font);
			break;
		case 8:
			AnswerPosition(tPos[7], questions[7], answers[7], trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered, textures, font);
			break;
		case 9:
			AnswerPosition(tPos[8], questions[8], answers[8], trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered, textures, font);
			break;
		case 10:
			AnswerPosition(tPos[9], questions[9], answers[9], trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered, textures, font);
			break;
		}
	}
}

void AnswerPosition(int tPos, const char* question, const char** answers, int* trueQuestionCounter, int* questionsNumberCounter,
					int* randomQuestion, bool* isAnswered, AllTextures textures, Font font)
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

	Answer(tPos, 1, 540, 440, 300, 120, answers, trueQuestionCounter, questionsNumberCounter, isAnswered, textures, font);
	Answer(tPos, 2, 540 + 500, 440, 300, 120, answers, trueQuestionCounter, questionsNumberCounter, isAnswered, textures, font);
	Answer(tPos, 3, 540, 440 + 140, 300, 120, answers, trueQuestionCounter, questionsNumberCounter, isAnswered, textures, font);
	Answer(tPos, 4, 540 + 500, 440 + 140, 300, 120, answers, trueQuestionCounter, questionsNumberCounter, isAnswered, textures, font);
}

void Answer(int tPos, int tPosVal, int x1, int y1, int x2, int y2, const char** answers, int* trueQuestionCounter,
			int* questionsNumberCounter, bool* isAnswered, AllTextures textures, Font font)
{
	if (IsMouseInRange(x1, x1 + x2, y1, y1 + y2))
	{
		DrawTextEx(font, answers[tPosVal - 1], VecPos(x1 + 22, y1 + 47), 34, 4, BLACK);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			if (tPos == tPosVal)
			{
				*questionsNumberCounter += 1;
				*trueQuestionCounter += 1;
				*isAnswered = true;
			}
			else
			{
				*questionsNumberCounter += 1;
				*isAnswered = true;
			}
		}
	}
}