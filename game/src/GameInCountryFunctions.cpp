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
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	default:
		*countryNumber = 0;
	}
}

void OpenBulgaria(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened,
				  bool* isAnswered, AllTextures textures, Font font)
{
	Vector2 pos;
	pos.x = 300;
	pos.y = 300;

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

	int answersPos[10] = {1, 2, 1, 1, 2, 1, 2, 1, 2 ,2};

	if (!*isQuizOpened)
	{
		DrawTextEx(font, "Quiz", pos, 300, 12, BLACK);
		if (IsMouseInRange(300, 300 + 800, 300, 300 + 400))
		{
			pos.x = 304;
			pos.y = 294;
			DrawTextEx(font, "Quiz", pos, 300, 12, BLACK);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				*isQuizOpened = true;
				*questionsNumberCounter = 0;
				usedNums.clear();
			}
		}
	}

	if (*questionsNumberCounter == 5)
	{
		*isQuizOpened = false;
	}

	if (*questionsNumberCounter < 5 && *isQuizOpened)
	{
		OpenQuiz(questions, answersPos, money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered, textures, font);
	}
}

void OpenQuiz(const char** questions, int* tPos, int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion,
			  bool* isAnswered, AllTextures textures, Font font)
{
	Vector2 pos;
	pos.x = 400;
	pos.y = 400;

	DrawRectangle(300, 300, 500, 500, BLACK);

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

	DrawTextEx(font, questions[*randomQuestion - 1], pos, 40, 5, WHITE);

	switch (*randomQuestion)
	{
	case 1:
		AnswerPosition(tPos[0], trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered, textures, font);
		break;
	case 2:
		AnswerPosition(tPos[1], trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered, textures, font);
		break;
	case 3:
		AnswerPosition(tPos[2], trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered, textures, font);
		break;
	case 4:
		AnswerPosition(tPos[3], trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered, textures, font);
		break;
	case 5:
		AnswerPosition(tPos[4], trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered, textures, font);
		break;
	case 6:
		AnswerPosition(tPos[5], trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered, textures, font);
		break;
	case 7:
		AnswerPosition(tPos[6], trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered, textures, font);
		break;
	case 8:
		AnswerPosition(tPos[7], trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered, textures, font);
		break;
	case 9:
		AnswerPosition(tPos[8], trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered, textures, font);
		break;
	case 10:
		AnswerPosition(tPos[9], trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered, textures, font);
		break;
	}
}

void AnswerPosition(int tPos, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isAnswered,
					AllTextures textures, Font font)
{
	DrawRectangle(400, 500, 50, 50, WHITE);
	DrawRectangle(500, 500, 50, 50, WHITE);
	DrawRectangle(400, 600, 50, 50, WHITE);
	DrawRectangle(500, 600, 50, 50, WHITE);

	if (IsMouseInRange(400, 400 + 50, 500, 500 + 50))
	{
		DrawRectangle(400, 500, 50, 50, GRAY);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			if (tPos == 1)
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
	else if (IsMouseInRange(500, 500 + 50, 500, 500 + 50))
	{
		DrawRectangle(500, 500, 50, 50, GRAY);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			if (tPos == 2)
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
	else if (IsMouseInRange(400, 400 + 50, 600, 600 + 50))
	{
		DrawRectangle(400, 600, 50, 50, GRAY);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			if (tPos == 3)
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
	else if (IsMouseInRange(500, 500 + 50, 600, 600 + 50))
	{
		DrawRectangle(500, 600, 50, 50, GRAY);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			if (tPos == 4)
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