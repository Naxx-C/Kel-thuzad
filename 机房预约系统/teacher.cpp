#include "teacher.h"

//默认构造
Teacher::Teacher()
{

}

//有参构造
Teacher::Teacher(int empId, string name, string pwd)
{
	//初始化属性
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//菜单界面
void Teacher::operMenu()
{
	cout << "欢迎教师：" << this->m_Name << "登录！" << endl;
	cout << "\t\t --------------------------\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|        1.查看所有预约    |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|        2.审核预约        |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|        0.注销登录        |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t --------------------------\n";
	cout << "请输入您的选择：";
}

//查看所有预约
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "、 ";
		cout << "预约日期：周" << of.m_orderData[i]["date"] << "\t";
		cout << "时间段：" << (of.m_orderData[i]["intelval"] == "1" ? "上午" : "下午") << "\t";
		cout << "学生编号：" << of.m_orderData[i]["stuId"] << "\t";
		cout << "学生姓名：" << of.m_orderData[i]["stuName"] << "\t";
		cout << "机房编号：" << of.m_orderData[i]["roomId"] << "\t";

		string status = "状态：";
		//1 审核中 2 已预约 -1 预约失败 0 取消预约
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "审核未通过：预约失败";
		}
		else if (of.m_orderData[i]["status"] == "0")
		{
			status += "预约取消";
		}
		cout << "预约" << status << endl;
	}
	system("pause");
	system("cls");
	return;
}

//审核预约
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "待审核的预约记录如下" << endl;

	vector<int>v;//存放在最大容器中的下标编号
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		//在筛选状态 审核中
		if (of.m_orderData[i]["status"] == "1" )
		{
			v.push_back(i);
			cout << index++ << "、 ";
			cout << "预约日期：周" << of.m_orderData[i]["date"] << "\t";
			cout << "时间段：" << (of.m_orderData[i]["intelval"] == "1" ? "上午" : "下午") << "\t";
			cout << "学生编号：" << of.m_orderData[i]["stuId"] << "\t";
			cout << "学生姓名：" << of.m_orderData[i]["stuName"] << "\t";
			cout << "机房编号：" << of.m_orderData[i]["roomId"] << "\t";

			string status = "状态：";
			//1 审核中 2 已预约 -1 预约失败 0 取消预约
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			cout << "预约" << status << endl;
		}
		
	}
	cout << "请输入通过审核的记录，0代表返回" << endl;
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
				cout << "请输入审核结果：" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;
				cout << "0、返回" << endl;
				while (true)
				{
					cin >> ret;
					if (ret >= 0 && ret <= 2)
					{
						if (ret == 1)
						{
							of.m_orderData[v[select - 1]]["status"] = "2";
							cout << "审核通过" << endl;
						}
						else if (ret == 2)
						{
							of.m_orderData[v[select - 1]]["status"] = "-1";
							cout << "审核未通过" << endl;
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
						cout << "输入有误，请重新输入" << endl;
					}
					of.updateOrder();
					system("pause");
					system("cls");
					return;
				}			
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
	return;
}
