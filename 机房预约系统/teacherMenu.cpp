#include "teacherMenu.h"

// ������ʦ�Ӳ˵�����
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//������ʦ�Ӳ˵�
		teacher->operMenu();

		//������ָ��תΪ����ָ�룬���������������ӿ�
		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		//�����û�ѡ��
		cin >> select;
		if (select == 1)//����ԤԼ
		{
			tea->showAllOrder();
		}
		else if (select == 2)//�鿴����ԤԼ
		{
			tea->validOrder();
		}
		else if (select == 0)//ע��
		{
			delete teacher;//���ٵ���������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "������������������" << endl;
			system("pause");
			system("cls");
			continue;
		}
	}
}
