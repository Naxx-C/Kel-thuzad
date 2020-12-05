#include "teacherMenu.h"

// 进入老师子菜单界面
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//调用老师子菜单
		teacher->operMenu();

		//将父类指针转为子类指针，调用子类里其他接口
		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		//接受用户选项
		cin >> select;
		if (select == 1)//申请预约
		{
			tea->showAllOrder();
		}
		else if (select == 2)//查看自身预约
		{
			tea->validOrder();
		}
		else if (select == 0)//注销
		{
			delete teacher;//销毁掉堆区对象
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
