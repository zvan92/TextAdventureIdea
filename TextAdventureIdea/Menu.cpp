#include "pch.h"
#include "Menu.h"
#include "Game.h"
#include "FileManager.h"
#include <iostream>
using namespace std;

Menu *Menu::instance = 0;

Menu::Menu()
{
}
Menu::~Menu()
{
}

int Menu::Run()
{
	system("cls");

	quitting = false;

	cout << "========================================\n";
	cout << "==          EVAN'S ADVENTURE          ==\n";
	cout << "========================================\n\n",
	cout << "(1) New Game\n(2) Load Game\n(3) Exit Game\n\nEnter choice: ";

	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		if (Game::Instance()->CreatePlayer() == 1)
		{
			return 1;
		}
		Game::Instance()->setGameOverStatus(false);
		break;
	case 2:
		if (FileManager::Instance()->PromptForLoad() == 1)
		{
			return 1;
		}
		Game::Instance()->setGameOverStatus(false);
		break;
	case 3:
		system("cls");
		cout << "Thanks for playing!\n\n";
		Game::Instance()->setGameOverStatus(true);
		Menu::Instance()->setQuitting(true);
		break;
	}

	return 0;
}