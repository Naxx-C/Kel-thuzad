#include "studentMenu.h"

// ����ѧ���Ӳ˵�����
void studentMenu(Identity* &student)
{
	while (true)
	{
		//����ѧ���Ӳ˵�
		student->operMenu();

		//������ָ��תΪ����ָ�룬���������������ӿ�
		Student* stu = (Student*)student;

		int select = 0;
		//�����û�ѡ��
		cin >> select;
		if (select == 1)//����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2)//�鿴����ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3)//�鿴������ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4)//ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else if (select == 0)//ע��
		{
			delete student;//���ٵ���������
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

