#include "teacher.h"

//Ĭ�Ϲ���
Teacher::Teacher()
{

}

//�вι���
Teacher::Teacher(int empId, string name, string pwd)
{
	//��ʼ������
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//�˵�����
void Teacher::operMenu()
{
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t --------------------------\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|        1.�鿴����ԤԼ    |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|        2.���ԤԼ        |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|        0.ע����¼        |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t --------------------------\n";
	cout << "����������ѡ��";
}

//�鿴����ԤԼ
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "�� ";
		cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"] << "\t";
		cout << "ʱ��Σ�" << (of.m_orderData[i]["intelval"] == "1" ? "����" : "����") << "\t";
		cout << "ѧ����ţ�" << of.m_orderData[i]["stuId"] << "\t";
		cout << "ѧ��������" << of.m_orderData[i]["stuName"] << "\t";
		cout << "������ţ�" << of.m_orderData[i]["roomId"] << "\t";

		string status = "״̬��";
		//1 ����� 2 ��ԤԼ -1 ԤԼʧ�� 0 ȡ��ԤԼ
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "���δͨ����ԤԼʧ��";
		}
		else if (of.m_orderData[i]["status"] == "0")
		{
			status += "ԤԼȡ��";
		}
		cout << "ԤԼ" << status << endl;
	}
	system("pause");
	system("cls");
	return;
}

//���ԤԼ
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����˵�ԤԼ��¼����" << endl;

	vector<int>v;//�������������е��±���
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		//��ɸѡ״̬ �����
		if (of.m_orderData[i]["status"] == "1" )
		{
			v.push_back(i);
			cout << index++ << "�� ";
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"] << "\t";
			cout << "ʱ��Σ�" << (of.m_orderData[i]["intelval"] == "1" ? "����" : "����") << "\t";
			cout << "ѧ����ţ�" << of.m_orderData[i]["stuId"] << "\t";
			cout << "ѧ��������" << of.m_orderData[i]["stuName"] << "\t";
			cout << "������ţ�" << of.m_orderData[i]["roomId"] << "\t";

			string status = "״̬��";
			//1 ����� 2 ��ԤԼ -1 ԤԼʧ�� 0 ȡ��ԤԼ
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			cout << "ԤԼ" << status << endl;
		}
		
	}
	cout << "������ͨ����˵ļ�¼��0������" << endl;
	int select = 0;
	int ret = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= (int)v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "��������˽����" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cout << "0������" << endl;
				while (true)
				{
					cin >> ret;
					if (ret >= 0 && ret <= 2)
					{
						if (ret == 1)
						{
							of.m_orderData[v[select - 1]]["status"] = "2";
							cout << "���ͨ��" << endl;
						}
						else if (ret == 2)
						{
							of.m_orderData[v[select - 1]]["status"] = "-1";
							cout << "���δͨ��" << endl;
						}
						else
						{
							system("pause");
							system("cls");
							return;
						}
					}
					else
					{
						cout << "������������������" << endl;
					}
					of.updateOrder();
					system("pause");
					system("cls");
					return;
				}			
			}
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
	return;
}
