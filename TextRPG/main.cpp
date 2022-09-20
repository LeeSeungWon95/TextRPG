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
	//���� �õ� ����
	srand(time(0));

	EnterLobby();
	return 0;
}

void EnterLobby()
{
	while (true)
	{
		cout << "------------------" << endl;
		cout << "�κ� �����߽��ϴ�!" << endl;
		cout << "------------------" << endl;

		//�÷��̾� ����
		SelectPlayer();

		cout << "--------------------------" << endl;
		cout << "(1) �ʵ� ���� (2) ���� ����" << endl;
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
		cout << "������ ����ּ���!" << endl;
		cout << "(1) ��� (2) �ü� (3) ����" << endl;
		cout << "> ";

		cin >> PlayerInfo.Type;

		if (PlayerInfo.Type == PT_Knight)
		{
			cout << "��� ������...!" << endl;
			PlayerInfo.Hp = 150;
			PlayerInfo.Attack = 10;
			PlayerInfo.Defence = 5;
			break;
		}
		else if (PlayerInfo.Type == PT_Archer)
		{
			cout << "�ü� ������...!" << endl;
			PlayerInfo.Hp = 100;
			PlayerInfo.Attack = 15;
			PlayerInfo.Defence = 3;
			break;
		}
		else if (PlayerInfo.Type == PT_Mage)
		{
			cout << "���� ������...!" << endl;
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
		cout << "�ʵ忡 �����߽��ϴ�!" << endl;
		cout << "------------------" << endl;

		cout << "[PLAYER] HP : " << PlayerInfo.Hp << " / ATT : " << PlayerInfo.Attack << " / DEF : " << PlayerInfo.Defence << endl;

		CreateRandomMonster();

		cout << "------------------" << endl;
		cout << "(1) ���� (2) ����" << endl;
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
	//1-3 ���� �������ڸ� �̴´�
	MonsterInfo.Type = 1 + (rand() % 3);

	switch (MonsterInfo.Type)
	{
	case MT_Slime:
		cout << "������ ������...! (Hp:15 / ATT:5 / DEF:0)" << endl;
		MonsterInfo.Hp = 15;
		MonsterInfo.Attack = 5;
		MonsterInfo.Defence = 0;
		break;
	case MT_Orc:
		cout << "��ũ ������...! (Hp:40 / ATT:10 / DEF:3)" << endl;
		MonsterInfo.Hp = 40;
		MonsterInfo.Attack = 10;
		MonsterInfo.Defence = 3;
		break;
	case MT_Skeleton:
		cout << "���̷��� ������...! (Hp:80 / ATT:15 / DEF:5)" << endl;
		MonsterInfo.Hp = 80;
		MonsterInfo.Attack = 15;
		MonsterInfo.Defence = 5;
		break;
	}
}

void EnterBattle()
{
	//���� �÷��̾ ������ ���Ͱ� ��������� ���Ͱ� �ݰ��ϴ� ������ ����
	while (true)
	{
		//���� �÷��̾ ������
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
		cout << "���� ���� ü�� : " << MonsterInfo.Hp << endl;
		
		//���Ͱ� �׾��ٸ� �ݰ��� ��ȸ ���� �ٷ� ���������� �ȴ�
		if (MonsterInfo.Hp == 0)
		{
			cout << "���͸� óġ�߽��ϴ�!" << endl;
			return;
		}

		//���� �ݰ�
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
		cout << "�÷��̾� ���� ü�� : " << PlayerInfo.Hp << endl;
		if (PlayerInfo.Hp == 0)
		{
			cout << "����� ����߽��ϴ�... GAME OVER" << endl;
			return;
		}
	}
}