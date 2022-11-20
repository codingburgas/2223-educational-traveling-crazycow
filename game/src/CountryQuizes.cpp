#include "Include.h"
#include "OpenCountry.h"
#include "GameInCountry.h"

void OpenBulgariaQuiz(GameS& game, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundBulgaria, 0, 0, WHITE);

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
		{"  Vihren Peak", "  Botev Peak", "  Musala Peak", "   Black Peak"},
		{"     South", "    Central", "   Northwest", "   Southwest"},
		{"   Southwest", "   Northwest", "     North", "   Northeast"},
		{"       28", "       30", "       27", "       25"},
		{"     Varna", "     Sofia", "    Sozopol", "     Plovdiv"},
		{"    Romania", "     Greece", "    Turkey", "     Serbia"},
		{"    St. Ivan", " Belene Island", " St. Anastasia", " Snake Island"}
	};

	int answersPos[10] = { 4, 2, 3, 1, 3, 1, 1, 4, 3, 2 };


	OpenQuiz(questions, answers, answersPos, game.quizCounter[0], game, textures, font);

	if (!game.isQuizOpened)
	{
		DrawTexture(textures.gameRight, 1300, 300, WHITE);
		if (IsMouseInRange(1300, 1300 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameRight, 1304, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.isArrowPressed = true;
				game.openQuiz = false;
				game.openGame = true;
			}
		}
	}
}

void OpenSpainQuiz(GameS& game, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundSpain, 0, 0, WHITE);

	const char* questions[10] = {
				"Which is to Spain's west from \n most of the Iberian Peninsula?",
				"Which is the highest mountain \n            in Spain?",
				"    Which city is the capital \n             of Spain",
				"      Which is a Spanish \n  territory in mainland Africa?",
				"     Which isn't one of the \n       Balearic Islands?",
				"       Which sea borders \n       Spain on the north?",
				"     How much is the total \n       land area of Spain?",
				"   Which is the longest river \n            in Spain?",
				" Which Spanish island has the \n       largest population?",
				"  Which Spanish city has the \n       largest population?"
	};

	const char* answers[10][4] = {
		{"   Portugal", "   Belgium", "   Morocco", "     Italy"},
		{"     Aneto", "     Chullo", "     Teide", "    Moncayo"},
		{"   Bracelona", "    Madrid", "     Sevill", "   Valencia"},
		{"     Melilla", "     Rabat", "    Tangier", "   Algeciras"},
		{"    Majorca", "  Formentera", "     Ibiza", "    Tenerife"},
		{"   Black Sea", "Tyrrhenian Sea", " Bay of Biscay", "  Balearic Sea"},
		{"    999,234", "    211,500", "    505,000", "    101,000"},
		{"     Tagus", "     Minho", "   Llobregat", "    Bidasoa"},
		{"     Ibiza", "    Tenerife", " Gran Canaria", "    Majorca"},
		{"   Barcelona", "    Murcia", "     Palma", "    Madrid"}
	};

	

	int answersPos[10] = { 1, 3, 2, 1, 4, 3, 3, 1, 2, 4};

	OpenQuiz(questions, answers, answersPos, game.quizCounter[1], game, textures, font);

	if (!game.isQuizOpened)
	{
		DrawTexture(textures.gameRight, 1300, 300, WHITE);
		if (IsMouseInRange(1300, 1300 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameRight, 1304, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.isArrowPressed = true;
				game.openQuiz = false;
				game.openGame = true;
			}
		}
	}
}

void OpenFranceQuiz(GameS& game, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundFrance, 0, 0, WHITE);

	const char* questions[10] = {

				" With which of these countries\n  does France share a border?",
				"  How many countries share a \n   border with France in total?",
				"     The Alps form a natural \n   border between France and:",
				" What is the capital of France?",
				"   What animal is the Symbol \n            of France?",
				"    Which river does not flow \n         through France?",
				"Which river flows through Paris?",
				"    The Pyrenees mountains \n     separate France from: ",
				"Just how big is France, anyway?",
				"      Which town is famous \n          for its wine?"
	};

	const char* answers[10][4] = {

		{"    Germany", "      Italy", "  Switzerland", "   All above"},
		{"        6", "        8", "        7", "       10"},
		{"    Germany", "      Spain", "      Italy", "     Belgium"},
		{"      Paris", "      Lyon", "     Berlin", "     Madrid"},
		{"    Cardinal", "      Lion", "       Pig", "    Rooster"},
		{"      Rhine", "      Loire", "       Po", "      Rhone"},
		{"      Rhine", "      Rhone", "     Escaut", "      Seine"},
		{"    Germany", "      Spain", "      Italy", "  Switzerland"},
		{"  643 801 km2", "  343 801 km2", "  863 801 km2", "  583 801 km2"},
		{"     Reims", "    Le Havre", "     Nantes", "    Bordeaux"}
	};

	int answersPos[10] = { 4, 2, 3, 1, 4, 3, 4, 2, 1, 4 };

	OpenQuiz(questions, answers, answersPos, game.quizCounter[2], game, textures, font);

	if (!game.isQuizOpened)
	{
		DrawTexture(textures.gameRight, 1300, 300, WHITE);
		if (IsMouseInRange(1300, 1300 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameRight, 1304, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.isArrowPressed = true;
				game.openQuiz = false;
				game.openGame = true;
			}
		}
	}
}


void OpenItalyQuiz(GameS& game, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundItaly, 0, 0, WHITE);

	const char* questions[10] = {
				" Which of the following islands \n     doesn't belong to Italy?",
				"Which is the mountain range that \n    runs on the entire Italy?",
				" Which is the highest mountain \n        in Italian territory?",
				"Which mountain range forms the \n     northern border of Italy?",
				"  Which is the largest lake on \n       the Italian peninsula?",
				"Which body of water surrounds \n   the Southern part of Italy?",
				"    Which city is the capital \n              of Italy",
				"Which river flows through Rome?",
				"   How many countries does \n           Italy border?",
				"How many seas surround Italy?"
	};

	const char* answers[10][4] = {
		{"    Corsica", "    Sardinia", "     Sicily", "      Capri"},
		{"   Strandzha", "  Carpathians", "  Apennines", "Lepontine Alps"},
		{"    Pordoi", "  Campolongo", "  Marmolada", " Gran Paradiso"},
		{"     Andes", "      Alps", "   Macaroni", "    Rockies"},
		{" Lake Macaroni", "  Lake Louis", "  Lake George", "Lake Trasimeno"},
		{" Pacific Ocean", "Atlantic Ocean", "Mediterranean", "    Red Sea"},
		{"     Rome", "    Palermo", "    Venice", "     Milan"},
		{"Euphrates River", "   Tiber River", "   Nile River", "  Indus River"},
		{"     Four", "      Three", "      Five", "       Six"},
		{"    Three", "      Two", "       Four", "      One"}
	};

	int answersPos[10] = { 1, 3, 4, 2, 4, 3, 1, 2, 1, 3 };

	OpenQuiz(questions, answers, answersPos, game.quizCounter[3], game, textures, font);

	if (!game.isQuizOpened)
	{
		DrawTexture(textures.gameRight, 1300, 300, WHITE);
		if (IsMouseInRange(1300, 1300 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameRight, 1304, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.isArrowPressed = true;
				game.openQuiz = false;
				game.openGame = true;
			}
		}
	}
}


void OpenGermanyQuiz(GameS& game, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundGermany, 0, 0, WHITE);

	const char* questions[10] = {
				"    Which city is the capital \n          of Germany?",
				"    How many states does \n         Germany have?",
				"  Which is not a German state?",
				"  Which is not one of the three \n           city states?",
				"  Which state surrounds Berlin?",
				"    What river runs through \n            Cologne?",
				"Which one is not a German river?",
				"  Which one is not a German \n            mountain?",
				"    Which one is the tallest \n      mountain in Germany?",
				"   How many lakes are there \n           in Germany?"
	};

	const char* answers[10][4] = {
		{"    Berlin", "     Bern", "     Bonn", "   Munchen"},
		{"       9", "       14", "       16", "       19"},
		{"    Saarland", "   Burgenland", "    Berlin", "    Hessen"},
		{"    Bremen", "     Berlin", "   Hamburg", " Brandenburg"},
		{" Mecklenburg", "  Brandenburg", "Niedersachsen", "   Nordrhein"},
		{"    Rihne", "    Danube", "     Nile", "     Oder"},
		{"    Danube", "    Rihne", "    Iskar", "    Weser"},
		{"   Adelegg", " The Pyrenees", "   Ahlsburg", "   Ahr Hills"},
		{"  Wetterstein", "Ester Mountains", "    Adelegg", "   Karwendel"},
		{"     203", "      81", "      78", "      109"}
	};

	int answersPos[10] = { 1, 3, 2, 4, 2, 1, 3, 2, 1, 4 };

	OpenQuiz(questions, answers, answersPos, game.quizCounter[4], game, textures, font);

	if (!game.isQuizOpened)
	{
		DrawTexture(textures.gameRight, 1300, 300, WHITE);
		if (IsMouseInRange(1300, 1300 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameRight, 1304, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.isArrowPressed = true;
				game.openQuiz = false;
				game.openGame = true;
			}
		}
	}
}

void OpenTurkeyQuiz(GameS& game, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundTurkey, 0, 0, WHITE);

	const char* questions[10] = {
				"       What is the capital\n           of Turkey?",
				"       What is the largest\n    minority group in Turkey?",
				"       What is the name of\n      the bi-continental city?",
				"    Which one of the following\nrivers flows only through Turkey?",
				"    Which one of the following\ncountries does not border Turkey?",
				"        The biggest island\n           of Turkey is?",
				"    Which one of the following\n    seas isn't around Turkey?",
				"        The biggest lake of\n             Turkey is?",
				"      The highest mountain\n           of Turkey is?",
				"  Which city is in the European\n          part of Turkey?"
	};

	const char* answers[10][4] = {
		{"    Istanbul", " Constantinople", "   Byzantium", "     Ankara"},
		{"      PLO", "    Muslims", "     Kurds", "  Palestinians"},
		{"    Istanbul", "    Antalya", "     Ankara", "      Izmir"},
		{"      Firat", "      Dicle", "Buyuk Menderes", "      Meric"},
		{"    Georgia", "      Iraq", "      Iran", "     Russia"},
		{"   Buyukada", "    Gokceada ", "   Heybeliada", "    Bozcaada"},
		{"  Caspian sea", "     Aegean", " Mediterranean", "   Black sea"},
		{"     Egirdir", "    Beysehir", "      Tuz", "      Van"},
		{"   Cilo Dagi", "   Agri Dagi", "     Uludag", "   Aydos Dagi"},
		{"    Trabzon", "     Edirne", "      Izmir", "     Bursa"}
	};

	int answersPos[10] = { 4, 3, 1, 3, 4, 2, 1, 4, 2, 2 };

	OpenQuiz(questions, answers, answersPos, game.quizCounter[5], game, textures, font);

	if (!game.isQuizOpened)
	{
		DrawTexture(textures.gameRight, 1300, 300, WHITE);
		if (IsMouseInRange(1300, 1300 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameRight, 1304, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.isArrowPressed = true;
				game.openQuiz = false;
				game.openGame = true;
			}
		}
	}
}

void OpenGreeceQuiz(GameS& game, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundGreece, 0, 0, WHITE);

	const char* questions[10] = {
				"Which of the following mountains\n     is the highest in Greece?",
				"   Which large mountain range \n  runs through central Greece?",
				"What mountain range is nicknamed \n      the 'spine of Greece'?",
				"    What percentage of Greece \n      is mountainous or hilly?",
				"  How many islands are there \n            in Greece?",
				"What connects the southern Greek \n  with the rest of the mainland?",
				"   Which is the largest island \n            in Greece?",
				"    Which city is the capital \n            of Greece?",
				"Which sea is located along the \n    eastern coast of Greece?",
				"Which large peninsula of Greece \nwas home to Sparta and Corinth?"
	};

	const char* answers[10][4] = {
		{"   Menelaos", "   Taygetos", "    Olympus", "      Etna"},
		{"  The Pindos", "   The Atlas", "   The Ural", " The Taygetos"},
		{"    Andes", " Rocky Mounts", "     Alps", "    Pindus"},
		{"      25%", " less than 10%", "   nearly 50%", "      80%"},
		{"   nearly 450", "   over 1400", "       65", "       18"},
		{"Loutraki Bridge", "Straits of Patra", "Corinth Isthmus", "Canals of Attiki"},
		{"     Crete", "  Pantelleria", "  Samothraki", "   Mytilene"},
		{"     Assos", "    Athens", "    Lindos", "    Sparta"},
		{"    Red Sea", "  Arabian Sea", "  Aegean Sea", "   Black Sea"},
		{"   Thessaly", "  Peloponnese", "    Epirus", "   Macedonia"}
	};

	int answersPos[10] = { 3, 1, 4, 4, 2, 3, 1, 2, 3, 2 };

	OpenQuiz(questions, answers, answersPos, game.quizCounter[6], game, textures, font);

	if (!game.isQuizOpened)
	{
		DrawTexture(textures.gameRight, 1300, 300, WHITE);
		if (IsMouseInRange(1300, 1300 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameRight, 1304, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.isArrowPressed = true;
				game.openQuiz = false;
				game.openGame = true;
			}
		}
	}
}

void OpenEnglandQuiz(GameS& game, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundEngland, 0, 0, WHITE);

	const char* questions[10] = {
				"  Which is the largest country \n            of the UK?",
				"  Which is the smallest country \n            of the UK?",
				"    How many seas border the \n         United Kingdom?",
				"  What is the highest mountain \n           in the UK?",
				"   What is the largest natural \n         lake in the UK?",
				"  What is the longest canal in \n              the UK?",
				"   What is the highest mountain \n             in Wales?",
				" What was the previous capital \n            of England?",
				"How many administrative counties \n       are there in England?",
				"     Which city is the capital \n            of England?"
	};

	const char* answers[10][4] = {
		{"     Wales", "    England", "    Scotland", " North Ireland"},
		{" North Ireland", "    Scotland", "     Wales", "    England"},
		{"        1", "        2", "        3", "        4"},
		{"  Schiehallion", " Sgurr Fhuaran", "   Ben Nevis", "   Waun Fach"},
		{"Coniston Water", "Bassenthwaite", "   Ullswater", "  Windermere"},
		{"  Grand Union", " Oxford Canal", "Lee Navigation", "Lancaster Cana"},
		{" Garnedd Ugain", "   Snowdon", "    Skiddaw", "  Glyder Fawr"},
		{"    Oxford", "    Bristol", "  Winchester", "  Birmingham"},
		{"       20", "       24", "       27", "       31"},
		{"    London", "  Manchester", "     York", "   Liverpool"}
	};

	int answersPos[10] = { 2, 1, 4, 3, 4, 1, 2, 3, 3, 1 };

	OpenQuiz(questions, answers, answersPos, game.quizCounter[7], game, textures, font);

	if (!game.isQuizOpened)
	{
		DrawTexture(textures.gameRight, 1300, 300, WHITE);
		if (IsMouseInRange(1300, 1300 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameRight, 1304, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.isArrowPressed = true;
				game.openQuiz = false;
				game.openGame = true;
			}
		}
	}
}

void OpenNorwayQuiz(GameS& game, AllTextures textures, Font font)
{
	DrawTexture(textures.quizBackgroundNorway, 0, 0, WHITE);

	const char* questions[10] = {
				"    What is the name of the\n  highest mountain in Norway?",
				"    What is the name of the\n oldest existing city in Norway?",
				"    What is the name of the\n    longest river in Norway?",
				"    What is the name of the\n   largest glacier in Norway?",
				"    What is the northernmost\n     city of mainland Norway?",
				"   After Svalbard, what is the\n    largest island in Norway?",
				"    What is the name of the \n    deepest lake in Norway?",
				"    Which city is the capital\n            of Norway?",
				"   Norway is the world's third\n       largest exporter of...",
				"     What is the population\n           of Norway?"
	};

	const char* answers[10][4] = {
		{" Galdhoepiggen", "   Bloksberg", "   Glittertind", "   Snoehetta"},
		{"      Oslo", "     Bergen", "   Trondheim", "   Toensberg"},
		{"     Laagen", "     Glomma", "   Akerselva", "     Rauma"},
		{"     Olav V", "   Svartisen", "  Sognebreen", " Jostedalsbren"},
		{"  Hammerfest", " Longyearbyen", "   Nordkapp", "     Bodoe"},
		{"    Helgoey", "      Hitra", "    Hinnoey", "      Senja"},
		{"Seljordsvatnet", "   Femunden", "Hornindalsvatn", "    Mjoesa"},
		{"   Helsinki", "      Oslo", "   Trondheim", "     Berlin"},
		{"       Oil", "      Wood", "   Furniture", "      Iron"},
		{"    4,660,539", "    12,351,752", "     807,413", "    37,961,664"}
	};

	int answersPos[10] = { 1, 4, 2, 4, 1, 3, 3, 2, 1, 1 };

	OpenQuiz(questions, answers, answersPos, game.quizCounter[8], game, textures, font);

	if (!game.isQuizOpened)
	{
		DrawTexture(textures.gameRight, 1300, 300, WHITE);
		if (IsMouseInRange(1300, 1300 + 110, 300, 300 + 300))
		{
			DrawTexture(textures.gameRight, 1304, 300, GRAY);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySoundMulti(textures.clickSound);
				game.isArrowPressed = true;
				game.openQuiz = false;
				game.openGame = true;
			}
		}
	}
}