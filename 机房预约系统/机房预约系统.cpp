#include<iostream>
using namespace std;
#include"LoginIn.h"
#include"showMenu.h"

int main() 
{
	int select = 0;
	while (true) 
	{
		showMenu();

		cin >> select;//�����û�ѡ��
		switch (select)
		{
		case 1://ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�ϵͳ
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	system("cls");
	return 0;
}
