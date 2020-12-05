#include "studentMenu.h"

// 进入学生子菜单界面
void studentMenu(Identity* &student)
{
	while (true)
	{
		//调用学生子菜单
		student->operMenu();

		//将父类指针转为子类指针，调用子类里其他接口
		Student* stu = (Student*)student;

		int select = 0;
		//接受用户选项
		cin >> select;
		if (select == 1)//申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2)//查看自身预约
		{
			stu->showMyOrder();
		}
		else if (select == 3)//查看所有人预约
		{
			stu->showAllOrder();
		}
		else if (select == 4)//取消预约
		{
			stu->cancelOrder();
		}
		else if (select == 0)//注销
		{
			delete student;//销毁掉堆区对象
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

