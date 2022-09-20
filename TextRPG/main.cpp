#include <iostream>

using namespace std;

enum PlayerType
{
	PT_Knight = 1,
	PT_Archer,
	PT_Mage
};

enum MonsterType
{
	MT_Slime = 1,
	MT_Orc,
	MT_Skeleton
};

struct ObjectInfo
{
	int Type;
	int Hp;
	int Attack;
	int Defence;
};

ObjectInfo PlayerInfo;

ObjectInfo MonsterInfo;

void EnterLobby();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();
void EnterBattle();

int main()
{
	//랜덤 시드 설정
	srand(time(0));

	EnterLobby();
	return 0;
}

void EnterLobby()
{
	while (true)
	{
		cout << "------------------" << endl;
		cout << "로비에 입장했습니다!" << endl;
		cout << "------------------" << endl;

		//플레이어 선택
		SelectPlayer();

		cout << "--------------------------" << endl;
		cout << "(1) 필드 입장 (2) 게임 종료" << endl;
		cout << "--------------------------" << endl;

		int Input;
		cin >> Input;

		if (Input == 1)
		{
			EnterField();
		}
		else
		{
			return;
		}
	}
}

void SelectPlayer()
{
	while (true)
	{
		cout << "------------------" << endl;
		cout << "직업을 골라주세요!" << endl;
		cout << "(1) 기사 (2) 궁수 (3) 법사" << endl;
		cout << "> ";

		cin >> PlayerInfo.Type;

		if (PlayerInfo.Type == PT_Knight)
		{
			cout << "기사 생성중...!" << endl;
			PlayerInfo.Hp = 150;
			PlayerInfo.Attack = 10;
			PlayerInfo.Defence = 5;
			break;
		}
		else if (PlayerInfo.Type == PT_Archer)
		{
			cout << "궁수 생성중...!" << endl;
			PlayerInfo.Hp = 100;
			PlayerInfo.Attack = 15;
			PlayerInfo.Defence = 3;
			break;
		}
		else if (PlayerInfo.Type == PT_Mage)
		{
			cout << "법사 생성중...!" << endl;
			PlayerInfo.Hp = 80;
			PlayerInfo.Attack = 25;
			PlayerInfo.Defence = 0;
			break;
		}
	}

}

void EnterField()
{
	while (true)
	{
		cout << "------------------" << endl;
		cout << "필드에 입장했습니다!" << endl;
		cout << "------------------" << endl;

		cout << "[PLAYER] HP : " << PlayerInfo.Hp << " / ATT : " << PlayerInfo.Attack << " / DEF : " << PlayerInfo.Defence << endl;

		CreateRandomMonster();

		cout << "------------------" << endl;
		cout << "(1) 전투 (2) 도주" << endl;
		cout << "> ";

		int Input;
		cin >> Input;

		if (Input == 1)
		{
			EnterBattle();
			if (PlayerInfo.Hp == 0)
			{
				return;
			}
		}
		else
		{
			return;
		}
	}
}

void CreateRandomMonster()
{
	//1-3 으로 랜덤숫자를 뽑는다
	MonsterInfo.Type = 1 + (rand() % 3);

	switch (MonsterInfo.Type)
	{
	case MT_Slime:
		cout << "슬라임 생성중...! (Hp:15 / ATT:5 / DEF:0)" << endl;
		MonsterInfo.Hp = 15;
		MonsterInfo.Attack = 5;
		MonsterInfo.Defence = 0;
		break;
	case MT_Orc:
		cout << "오크 생성중...! (Hp:40 / ATT:10 / DEF:3)" << endl;
		MonsterInfo.Hp = 40;
		MonsterInfo.Attack = 10;
		MonsterInfo.Defence = 3;
		break;
	case MT_Skeleton:
		cout << "스켈레톤 생성중...! (Hp:80 / ATT:15 / DEF:5)" << endl;
		MonsterInfo.Hp = 80;
		MonsterInfo.Attack = 15;
		MonsterInfo.Defence = 5;
		break;
	}
}

void EnterBattle()
{
	//먼저 플레이어가 때리고 몬스터가 살아있으면 몬스터가 반격하는 식으로 구현
	while (true)
	{
		//먼저 플레이어가 때리기
		int Damage = PlayerInfo.Attack - MonsterInfo.Defence;
		if (Damage < 0)
		{
			Damage = 0;
		}
		MonsterInfo.Hp -= Damage;
		if (MonsterInfo.Hp < 0)
		{
			MonsterInfo.Hp = 0;
		}
		cout << "몬스터 남은 체력 : " << MonsterInfo.Hp << endl;
		
		//몬스터가 죽었다면 반격의 기회 없이 바로 빠져나오면 된다
		if (MonsterInfo.Hp == 0)
		{
			cout << "몬스터를 처치했습니다!" << endl;
			return;
		}

		//몬스터 반격
		Damage = MonsterInfo.Attack - PlayerInfo.Defence;
		if (Damage < 0)
		{
			Damage = 0;
		}
		PlayerInfo.Hp -= Damage;
		if (PlayerInfo.Hp < 0)
		{
			PlayerInfo.Hp = 0;
		}
		cout << "플레이어 남은 체력 : " << PlayerInfo.Hp << endl;
		if (PlayerInfo.Hp == 0)
		{
			cout << "당신은 사망했습니다... GAME OVER" << endl;
			return;
		}
	}
}