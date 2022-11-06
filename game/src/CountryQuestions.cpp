#include "Functions.h"

void OpenBulgaria(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened,
	bool* isAnswered, AllTextures textures, Font font)
{
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
		{"  Vihren peak", "  Botev Peak", "  Musala Peak", "   Black Peak"},
		{"     South", "    Central", "   Northwest", " Southwestern"},
		{" Southwestern", "   Northwest", "     North", "   Northeast"},
		{"       28", "       30", "       27", "       25"},
		{"     Varna", "     Sofia", "    Sozopol", "     Plovdiv"},
		{"    Romania", "     Greece", "    Turkey", "     Serbia"},
		{"    St. Ivan", " Belene Island", " St. Anastasia", " Snake Island"}
	};

	int answersPos[10] = { 4, 2, 3, 1, 3, 1, 1, 4, 3, 2 };

	OpenQuiz(questions, answers, answersPos, money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered,
		isQuizOpened, textures, font);
}

void OpenSpain(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened,
	bool* isAnswered, AllTextures textures, Font font)
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

	int answersPos[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	OpenQuiz(questions, answers, answersPos, money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered,
		isQuizOpened, textures, font);
}

void OpenFrance(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened,
	bool* isAnswered, AllTextures textures, Font font)
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

	OpenQuiz(questions, answers, answersPos, money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered,
		isQuizOpened, textures, font);
}

void OpenItaly(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened,
	bool* isAnswered, AllTextures textures, Font font)
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

	OpenQuiz(questions, answers, answersPos, money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered,
		isQuizOpened, textures, font);
}

void OpenGermany(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened,
	bool* isAnswered, AllTextures textures, Font font)
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

	OpenQuiz(questions, answers, answersPos, money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered,
		isQuizOpened, textures, font);
}

void OpenTurkey(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened,
	bool* isAnswered, AllTextures textures, Font font)
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

	OpenQuiz(questions, answers, answersPos, money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered,
		isQuizOpened, textures, font);
}

void OpenGreece(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened,
	bool* isAnswered, AllTextures textures, Font font)
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

	OpenQuiz(questions, answers, answersPos, money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered,
		isQuizOpened, textures, font);
}

void OpenEngland(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened,
	bool* isAnswered, AllTextures textures, Font font)
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

	OpenQuiz(questions, answers, answersPos, money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered,
		isQuizOpened, textures, font);
}

void OpenNorway(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened,
	bool* isAnswered, AllTextures textures, Font font)
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

	OpenQuiz(questions, answers, answersPos, money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isAnswered,
		isQuizOpened, textures, font);
}