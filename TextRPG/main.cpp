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

int PlayerType;
int Hp;
int Attack;
int Defence;

int MonsterType;
int MonsterHp;
int MonsterAttack;
int MonsterDefence;

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

		cin >> PlayerType;

		if (PlayerType == PT_Knight)
		{
			cout << "��� ������...!" << endl;
			Hp = 150;
			Attack = 10;
			Defence = 5;
			break;
		}
		else if (PlayerType == PT_Archer)
		{
			cout << "�ü� ������...!" << endl;
			Hp = 100;
			Attack = 15;
			Defence = 3;
			break;
		}
		else if (PlayerType == PT_Mage)
		{
			cout << "���� ������...!" << endl;
			Hp = 80;
			Attack = 25;
			Defence = 0;
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

		cout << "[PLAYER] HP : " << Hp << " / ATT : " << Attack << " / DEF : " << Defence << endl;

		CreateRandomMonster();

		cout << "------------------" << endl;
		cout << "(1) ���� (2) ����" << endl;
		cout << "> ";

		int Input;
		cin >> Input;

		if (Input == 1)
		{
			EnterBattle();
			if (Hp == 0)
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
	MonsterType = 1 + (rand() % 3);

	switch (MonsterType)
	{
	case MT_Slime:
		cout << "������ ������...! (Hp:15 / ATT:5 / DEF:0)" << endl;
		MonsterHp = 15;
		MonsterAttack = 5;
		MonsterDefence = 0;
		break;
	case MT_Orc:
		cout << "��ũ ������...! (Hp:40 / ATT:10 / DEF:3)" << endl;
		MonsterHp = 40;
		MonsterAttack = 10;
		MonsterDefence = 3;
		break;
	case MT_Skeleton:
		cout << "���̷��� ������...! (Hp:80 / ATT:15 / DEF:5)" << endl;
		MonsterHp = 80;
		MonsterAttack = 15;
		MonsterDefence = 5;
		break;
	}
}

void EnterBattle()
{
	//���� �÷��̾ ������ ���Ͱ� ��������� ���Ͱ� �ݰ��ϴ� ������ ����
	while (true)
	{
		//���� �÷��̾ ������
		int Damage = Attack - MonsterDefence;
		if (Damage < 0)
		{
			Damage = 0;
		}
		MonsterHp -= Damage;
		if (MonsterHp < 0)
		{
			MonsterHp = 0;
		}
		cout << "���� ���� ü�� : " << MonsterHp << endl;
		
		//���Ͱ� �׾��ٸ� �ݰ��� ��ȸ ���� �ٷ� ���������� �ȴ�
		if (MonsterHp == 0)
		{
			cout << "���͸� óġ�߽��ϴ�!" << endl;
			return;
		}

		//���� �ݰ�
		Damage = MonsterAttack - Defence;
		if (Damage < 0)
		{
			Damage = 0;
		}
		Hp -= Damage;
		if (Hp < 0)
		{
			Hp = 0;
		}
		cout << "�÷��̾� ���� ü�� : " << Hp << endl;
		if (Hp == 0)
		{
			cout << "����� ����߽��ϴ�... GAME OVER" << endl;
			return;
		}
	}
}