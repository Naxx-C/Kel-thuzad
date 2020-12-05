#include "managerMenu.h"

//进入管理员子菜单界面
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//调用管理员子菜单
		manager->operMenu();

		//将父类指针转为子类指针，调用子类里其他接口
		Manager* man = (Manager*)manager;

		int select = 0;
		//接受用户选项
		cin >> select;
		if (select == 1)//添加账号
		{
			//cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			//cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)//查看机房
		{
			//cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4)//清空预约
		{
			//cout << "清空预约" << endl;
			man->cleanFile();
		}
		else if (select == 0)//注销
		{
			delete manager;//销毁掉堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			continue;
		}
	}
}
