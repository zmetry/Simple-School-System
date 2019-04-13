#include<iostream>
#include<string>
#include<Windows.h>
#include"allsetting.h"

using namespace std;

/*--------------菜单函数------------*/
void menu_teacher1();
void menu_teacher2();
void menu_student1();
void menu_student2();
void menu();

/*------------操作函数-------------*/
void check_finish(Student &p,Homework &ptr);
bool check_homework(Teacher &p,Homework &ptr);
void upper(char *name,int n);

int main()
{
	char page[200];
	char ch;
	/*--------------对类数组进行初始化---------------*/
	Teacher teacher("蒋光远");
	Student student[3] = {
		Student("张三",123456),
		Student("李四",123456),
		Student("王五",123456)
	};      
	Homework homework[3] = {
		Homework(),
		Homework(),
		Homework()
	};
	Note note[3] = {
		Note("真理惟一可靠的标准就是永远自相符合。 —— 欧文"),
		Note("我读的书愈多，就愈亲近世界，愈明了生活的意义，愈觉得生活的重要。 —— 高尔基"),
		Note("荣誉感是一种优良的品质，因而只有那些禀性高尚积极向上或受过良好教育的人才具备。 —— 爱迪生")
	};
	Course course[3] = {
		Course(),
		Course(),
		Course()
	};
loop3:menu();
	int count = 0;
	cin.get(ch);
	cin.clear();
	cin.get();
/*-----------------主菜单选择--------------------*/
    switch (ch)
	{
	case '1':
		system("cls");
		goto loop7;
	case '2':
		system("cls");
		goto loop2;
	case 'Q':
	case 'q':
		return 0;
	default:
		cout << "选择了无效的选项，请重选" << endl;
		goto loop3;
	}
/*------------------------老师菜单选择-----------------------*/
loop7:char teacher_name[10];
	int teacher_num;
	cout << "您有三次机会输入您的名字和密码，三次都失败则返回主页面" << endl;
	cout << "第" << count + 1 << "次:" << endl;
	cout << "请输入姓名：";
	cin.getline(teacher_name, 10);
	cout << "请输入密码：";
	cin >> teacher_num;
	cin.get();
	if (!(!strcmp(teacher_name,teacher.get_name())&&teacher_num==teacher.get_teacher_num()))
	{
		count++;
		if (count >= 2)
		{
			cout << "请重新进入该页面，再见" << endl;
			system("pause");
			system("cls");
			goto loop3;
		}
		else
			goto loop7;
	}
	system("cls");
	count = 0;
	cout << teacher.get_name() << "老师，欢迎您" << endl;
loop1:if (!course[1].get_test_exit())
		menu_teacher1();
	else
		menu_teacher2();
	cin.get(ch);
	cin.clear();
	cin.get();
	switch (ch)
	{
	case 'A':
	case 'a':
		system("cls");
		if (!homework[0].check_exit())
		{
			for (int i = 0; i < 3; i++)
				teacher.set_homework(homework[i]);
			cout << "请输入作业为什么：";
			cin >> page;
			cin.get();
			cout << "布置作业成功" << endl;
			goto loop1;
		}
		else
		{
			cout << "您已布置作业" << endl;
			goto loop1;
		}
	case 'B':
	case 'b':
		system("cls");
		if (!homework[0].check_exit())
		{
			cout << "您还没布置作业" << endl;
			goto loop1;
		}
		else
		{
			for (int i = 0; i < 3; i++)
				check_finish(student[i], homework[i]);
			goto loop1;
		}		
	case 'C':
	case 'c':
		if (!course[1].get_test_exit())
		{
			system("cls");
			cout << "请输入答案：";
			char temp[50];
			char *answer;
			cin.getline(temp, 50);
			answer = temp;
			upper(answer, 20);
			for (int i = 0; i < 3; i++)
			{
				course[i].set_answer(temp);
				course[i].arrange_test();
			}
			cout << "答案设置完成" << endl;
			goto loop1;
		}
		else
		{
			system("cls");
			for (int i = 0; i < 3; i++)
			{
				if (course[i].get_take_or_not())
				{
					cout << student[i].get_name() << "考了" << course[i].get_score() << "分";
					goto loop1;
				}
				else
				{
					cout << student[i].get_name() << "尚未参加考试" << endl;
					goto loop1;
				}
			}
		}
	case 'D':
	case 'd':
		system("cls");
		if (!course[0].get_test_exit())
		{
			cout << "你还未安排考试" << endl;
			goto loop1;
		}
		else
		{
			system("cls");
			for (int i = 0; i < 3; i++)
				course[i].correct(student[i]);
			goto loop1;
		}
	case 'E':
	case 'e':
		system("cls");
		if (teacher.change_teacher_num())
		{
			system("cls");
			cout << "更改密码成功" << endl;
			goto loop1;
		}
		else
		{
			system("cls");
			cout << "更改密码失败,请重试" << endl;
			goto loop1;
		}
	case 'Q':
	case 'q':
		system("cls");
		goto loop3;
	default:
		system("cls");
		cout << "选择了无效的选项，请重选" << endl;
		goto loop1;
	}
/*--------------------学生菜单选择---------------------------*/
loop2:
	char name[10];
	int num;
	cout << "您有三次机会输入您的名字和密码，三次都失败则返回主页面" << endl;
	cout << "第" << count + 1 << "次:" << endl;
	cout << "请输入姓名：";
	cin.getline(name, 10);
	cout << "请输入密码：";
	cin >> num;
	cin.get();
	int k = 0;
	for (k = 0; k < 3; k++)
		if (student[k].get_student_num() == num && !strcmp(name, student[k].get_name()))
			break;
	if (k >= 3 && count >= 2)
	{
		cout << "请重新进入该页面，再见" << endl;
		system("pause");
		system("cls");
		goto loop3;
	}
	if (k >= 3)
	{
		cout << "此学生不存在,请重试" << endl;
		system("pause");
		system("cls");
		count++;
		goto loop2;
	}
	else
	{
		system("cls");
	loop4:if (course[k].get_take_or_not())
		menu_student2();
		  else
		menu_student1();
		cin.get(ch);
		cin.clear();
		cin.get();
		switch (ch)
		{
		case 'A':
		case 'a':
			if (!check_homework(teacher,homework[1]))
			{
				system("cls");
				cout << "老师暂时还没有布置作业" << endl;
				goto loop4;
			}
			else
			{
				student[k].check_homework(homework[k]);
				system("cls");
				cout << "老师已布置作业，作业为" << page << "请尽快完成。" << endl;
				goto loop4;
			}
		case 'B':
		case 'b':
			if (!check_homework(teacher,homework[k]))
			{
				system("cls");
				cout << "老师尚未布置作业，请您自行学习。" << endl;
				goto loop4;
			}
			else
			{
				student[k].finish_homework(homework[k]);
				system("cls");
				cout << "已完成作业" << endl;
				goto loop4;
			}			
		case 'C':
		case 'c':
			if (!course[k].get_take_or_not())
			{
				if (course[k].get_test_exit())
				{
					system("cls");
					cout << "请学生做完试卷上的题目，并将答案填写到答题卡上" << endl;
					Sleep(5000);
					cout << "现在，请填写答案" << endl;
					char student_answer[20];
					char *ptr;
					cin.getline(student_answer, 20);
					cin.clear();
					ptr = student_answer;
					upper(ptr, 20);
					course[k].student_answer(ptr);
					cout << "答案填写完成，试卷已提交" << endl;
					goto loop4;
				}
				else
				{
					system("cls");
					cout << "老师未安排考试" << endl;
					goto loop4;
				}
			}
			else
			{
				if (course[k].get_correct_())
				{
					system("cls");
					cout << student[k].get_name() << "你在本次考试中得到了" << course[k].get_score() << "分" << endl;
					goto loop4;
				}
				if(!course[k].get_correct_())
				{
					system("cls");
					cout << "老师还未批改试卷，请耐心等候" << endl;
					goto loop4;
				}
			}
		case 'D':
		case 'd':
			system("cls");
			cout << student[k].get_note(note[k]) << endl;
			goto loop4;
		case 'E':
		case 'e':
			system("cls");
			if (student[k].change_student_num())
			{
				system("cls");
				cout << "更改密码成功" << endl;
				goto loop4;
			}
			else
			{
				system("cls");
				cout << "更改密码失败,请重试" << endl;
				goto loop4;
			}
		case 'Q':
		case 'q':
			system("cls");
			goto loop3;
		default:
			system("cls");
			cout << "选择了无效的选项，请重选" << endl;
			goto loop4;
		}
	}	
	system("pause");
	return 0;
}

void menu_teacher1()
{
	cout << "a)布置作业               b)查看作业完成情况" << endl;
	cout << "c)安排考试并设置答案     d)批改试卷        " << endl;
	cout << "e)更改密码               q)返回主页面" << endl;
}

void menu_teacher2()
{
	cout << "a)布置作业               b)查看作业完成情况" << endl;
	cout << "c)查看考试成绩           d)批改试卷        " << endl;
	cout << "e)更改密码               q)返回主页面" << endl;
}

void menu_student1()
{
	cout << "a)查看作业               b)完成作业" << endl;
	cout << "c)参加考试               d)查看笔记" << endl;
	cout << "e)更改密码               q)退出登录并返回主页面" << endl;
}

void menu_student2()
{
	cout << "a)查看作业               b)完成作业" << endl;
	cout << "c)查看成绩               d)查看笔记" << endl;
	cout << "e)更改密码               q)退出登录并返回主页面" << endl;
}

void menu()
{
	cout << "1)进入老师操作页面               2)进入学生操作界面" << endl;
	cout << "q)退出" << endl;
}

void check_finish(Student &p,Homework &ptr)
{
	if (p.get_finish(ptr))
		cout << p.get_name() << "完成了作业" << endl;
	else
		cout << p.get_name() << "没有完成作业" << endl;
}

bool check_homework(Teacher &p,Homework &ptr)
{
	if (p.check_homework_exit(ptr))
		return true;
	else
		return false;

}

void upper(char *name,int n)
{
	for (int i = 0; i < n; i++)
		if (name[i] <= 'z'&&name[i] >= 'a')
			name[i] += 'A' - 'a';
}
