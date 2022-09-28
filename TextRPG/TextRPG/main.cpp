#include <iostream>

using namespace std;

// main
//  - EnterLobby
//  -- CreatePlayer
//  -- EnterGame
//  --- CreateMonsters
//  --- EnterBattle
enum PlayerType
{
	PT_Knight = 1,
	PT_Archer,
	PT_Maze
};

enum MonsterType
{
	MT_Slime = 1,
	MT_Orc,
	MT_Skeleton
};

struct StatInfo
{
	int Hp = 0;
	int Attack = 0;
	int Defence = 0;
};

void EnterLobby();
void PrintMessage(const char* msg);
void CreatePlayer(StatInfo* PlayerInfo);
void PrintStat(const char* Type, const StatInfo& Info);
void EnterGame(StatInfo* PlayerInfo);
void CreateMonsters(StatInfo MonsterInfo[], int Count);
bool EnterBattle(StatInfo* PlayerInfo, StatInfo* MonsterInfo);

int main()
{
	srand((unsigned)time(nullptr));
	EnterLobby();
	return 0;
}

void EnterLobby()
{
	while (true)
	{
		PrintMessage("�κ� �����߽��ϴ�");
		StatInfo PlayerInfo;
		CreatePlayer(&PlayerInfo);
		PrintStat("PLAYER", PlayerInfo);
		EnterGame(&PlayerInfo);
	}
}

void PrintMessage(const char* msg)
{
	cout << "*******************************" << endl;
	cout << msg << endl;
	cout << "*******************************" << endl;
}

void CreatePlayer(StatInfo* PlayerInfo)
{
	bool Ready = false;
	while (Ready == false)
	{
		PrintMessage("ĳ���� ����");
		cout << "(1) ���� (2) �ü� (3) ����" << endl;
		int Input = 0;
		cin >> Input;
		cout << "> ";

		switch (Input)
		{
		case PT_Knight:
			PlayerInfo->Hp = 100;
			PlayerInfo->Attack = 10;
			PlayerInfo->Defence = 5;
			Ready = true;
			break;
		case PT_Archer:
			PlayerInfo->Hp = 80;
			PlayerInfo->Attack = 15;
			PlayerInfo->Defence = 3;
			Ready = true;
			break;
		case PT_Maze:
			PlayerInfo->Hp = 50;
			PlayerInfo->Attack = 20;
			PlayerInfo->Defence = 1;
			Ready = true;
			break;
		}
	}
}

void PrintStat(const char* Type, const StatInfo& Info)
{
	cout << "*******************************" << endl;
	cout << Type << " : Hp:" << Info.Hp << " ATT:" << Info.Attack << " DEF:" << Info.Defence << endl;
	cout << "*******************************" << endl;
}

void EnterGame(StatInfo* PlayerInfo)
{
	PrintMessage("���ӿ� �����߽��ϴ�");
	const int MONSTER_COUNT = 2;
	while (true)
	{
		StatInfo MonsterInfo[MONSTER_COUNT];
		CreateMonsters(MonsterInfo, MONSTER_COUNT);
		PrintStat("PLAYER", *PlayerInfo);
		for (int i = 0; i < MONSTER_COUNT; i++)
		{
			PrintStat("MONSTER", MonsterInfo[i]);
		}
		cout << "(1) ù��° ���Ϳ� ���� (2) �ι�° ���Ϳ� ���� (3) ����" << endl;
		cout << "> ";
		int Input = 0;
		cin >> Input;

		if (Input == 1 || Input == 2)
		{
			int Index = Input - 1;
			bool Victory = EnterBattle(PlayerInfo, &(MonsterInfo[Index]));
			if (Victory == false)
			{
				return;
			}
		}
	}

}

void CreateMonsters(StatInfo MonsterInfo[], int Count)
{
	for (int i = 0; i < Count; i++)
	{
		int RandomValue = 1 + (rand() % 3);
		switch (RandomValue)
		{
		case MT_Slime:
			MonsterInfo[i].Hp = 30;
			MonsterInfo[i].Attack = 5;
			MonsterInfo[i].Defence = 1;
			break;
		case MT_Orc:
			MonsterInfo[i].Hp = 50;
			MonsterInfo[i].Attack = 8;
			MonsterInfo[i].Defence = 2;
			break;
		case MT_Skeleton:
			MonsterInfo[i].Hp = 80;
			MonsterInfo[i].Attack = 10;
			MonsterInfo[i].Defence = 3;
			break;
		}
	}
}

bool EnterBattle(StatInfo* PlayerInfo, StatInfo* MonsterInfo)
{
	while (true)
	{
		int Damage = PlayerInfo->Attack - MonsterInfo->Defence;
		if (Damage < 0)
		{
			Damage = 0;
		}
		MonsterInfo->Hp -= Damage;
		if (MonsterInfo->Hp < 0)
		{
			MonsterInfo->Hp = 0;
		}
		PrintStat("MONSTER", *MonsterInfo);
		if (MonsterInfo->Hp == 0)
		{
			PrintMessage("���͸� óġ�߽��ϴ�");
			return true;
		}

		Damage = MonsterInfo->Attack - PlayerInfo->Defence;
		if (Damage < 0)
		{
			Damage = 0;
		}
		PlayerInfo->Hp -= Damage;
		if (PlayerInfo->Hp < 0)
		{
			PlayerInfo->Hp = 0;
		}
		PrintStat("PLAYER", *PlayerInfo);
		if (PlayerInfo->Hp == 0)
		{
			PrintMessage("GAME OVER");
			return false;
		}
	}
}