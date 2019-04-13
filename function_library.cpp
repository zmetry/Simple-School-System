#include<iostream>
#include<string>

#include"allsetting.h"

using namespace std;

/*老师类的操作函数*/

Teacher::Teacher()
{
	name = new char[8];
	strcpy_s(name, 8, "No name");
	teacher_num = 123456;
	v = 1;
}

Teacher::Teacher(const char *name_)
{
	if (name_)
	{
		int len = strlen(name_) + 1;
		name = new char[len];
		strcpy_s(name, len, name_);
		teacher_num = 123456;
		v = 1;
	}
	else
	{
		name = new char[8];
		strcpy_s(name, 8, "No name");
		teacher_num = 123456;
		v = 1;
	}
}

Teacher::~Teacher()
{
	if (v)
		delete[]name;
}

bool Teacher::check_homework_exit(Homework &p) const
{
	return p.exit;
}

char* Teacher::get_name() const
{
	return name;
}

int Teacher::get_teacher_num() const
{
	return teacher_num;
}

/*老师设置作业*/
void Teacher::set_homework(Homework &p)
{
	p.exit = 1;
}          

int Teacher::change_teacher_num()
{
	int temp1, temp2, temp3, count = 0;
loop1:	cout << "请输入初始密码：";
	cin >> temp1;
	cin.get();
	cout << "请输入更改的密码：";
	cin >> temp2;
	cout << "请再次输入更改的密码：";
	cin >> temp3;
	if (count <= 2)
	{
		if (temp1 == teacher_num && temp3 == temp2)
		{
			teacher_num = temp2;
			return 1;
		}
		else
		{
			if (temp1 != teacher_num)
			{
				count++;
				system("cls");
				cout << "与初始密码不符,您还有" << 3 - count << "次机会" << endl;
				count++;
				goto loop1;
			}
			else
			{
				if (temp2 != temp3)
				{
					count++;
					system("cls");
					cout << "两次输入的密码不一致，请重试" << endl;
					goto loop1;
				}
			}
		}
	}
	else
		return 0;
}


/*=====================================学生类的操作函数==============================================*/

/*学生完成作业*/
void Student::finish_homework(Homework &p)
{
	p.finish = 1;
}

/*学生查看作业*/
void Student::check_homework(Homework &p)
{
	p.check = 1;
}

char* Student::get_note(Note &p)
{
	return p.note;
}

/*老师查看哪些学生完成了作业*/
bool Student::get_finish(Homework &p) const
{
	if (p.finish)
		return true;
	else
		return false;
}

char *Student::get_name() const
{
	return this->name;
}

Student::Student(const char *name_, int student_num_)
{
	if (name_)
	{
		this->name = new char[strlen(name_) + 1];
		strcpy_s(this->name, strlen(name_) + 1, name_);
	}
	else
	{
		this->name = new char[8];
		strcpy_s(this->name, 8, "No name");
	}
	this->student_num = student_num_;
	exit_0 = 1;
}

int Student::get_student_num() const
{
	return this->student_num;
}

int Student::change_student_num()
{
	int temp1, temp2, temp3, count = 0;
loop1:	cout << "请输入初始密码：";
	cin >> temp1;
	cin.get();
	cout << "请输入更改的密码：";
	cin >> temp2;
	cout << "请再次输入更改的密码：";
	cin >> temp3;
	if (count <= 2)
	{
		if (temp1 == student_num && temp3 == temp2)
		{
			student_num = temp2;
			return 1;
		}
		else
		{
			if (temp1 != student_num)
			{
				count++;
				system("cls");
				cout << "与初始密码不符,您还有" << 3 - count << "次机会" << endl;
				count++;
				goto loop1;
			}
			else
			{
				if (temp2 != temp3)
				{
					count++;
					system("cls");
					cout << "两次输入的密码不一致，请重试" << endl;
					goto loop1;
				}
			}
		}
	}
	else
		return 0;
}

/*Student::Student(Student &p)
{
	p.exit_0 = 0;
	if (p.name)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, p.name);
	}
	else
	{

		this->name = new char[8];
		strcpy_s(this->name, 8, "No name");
	}
	this->student_num = p.student_num;
}*/

Student::~Student()
{
	if (exit_0)
		delete[]name;
}

Student::Student()
{
	name = new char[8];
	strcpy_s(name, 8, "No name");
	student_num = 0;
}

/*老师查看哪些学生查看了作业*/
void Student::student_get(Homework &p)
{
	if (p.check)
		cout << name << " has check the homework." << endl;
	else
		cout << name << " hasn't check the homework." << endl;
}

/*============================作业类的操作函数========================================*/

Homework::Homework()
{
	exit = 0;
	check = 0;
	finish = 0;
}

Homework::~Homework()
{

}

bool Homework::check_exit()
{
	if (exit)
		return true;
	else
		return false;
}
/*==============================笔记类的操作函数======================================*/

Note::Note()
{
	note = new char[2];
	strcpy_s(note, 2, " ");
	exit = 1;
}

Note::Note(const char *note_)
{
	if (note_)
	{
		note = new char[strlen(note_) + 1];
		strcpy_s(note, strlen(note_) + 1, note_);
	}
	else
	{
		note = new char[2];
		strcpy_s(note, 2, " ");
	}
	exit = 1;
}

Note::~Note()
{
	if (exit)
		delete[]note;
}

char* Note::get_note() const
{
	return note;
}

/*================================考试类的操作函数======================================*/

/*老师设置考试的标准答案*/
void Course::set_answer(char *answer)
{
	for (int i = 0; i < 20; i++)
		correct_answer[i] = answer[i];
	correct_answer[20] = 0;
}

/*老师进行考试的批改*/
void Course::correct(Student &p)
{
	if (!take_or_not)
		cout << p.get_name() << "未参加考试" << endl;
	else
	{
		for (int i = 0; i < 20; i++)
			if (correct_answer[i] == answer[i])
				score += 5;
		cout << p.get_name() << "考了" << score << "分" << endl;
	}
	correct_ = 1;
}

/*学生考试的答案*/
void Course::student_answer(char *answer_)
{
	for (int i = 0; i < 20; i++)
		answer[i] = answer_[i];
	answer[20] = 0;
	take_or_not = 1;
}

Course::Course()
{
	exit = 1;
	score = 0;
	test_exit = 0;
	take_or_not = 0;
	correct_ = 0;
}

Course::~Course()
{

}

void Course::arrange_test()
{
	test_exit = 1;
}

bool Course::get_test_exit() const
{
	if (test_exit)
		return true;
	else
		return false;
}

bool Course::get_take_or_not() const
{
	if (take_or_not)
		return true;
	else
		return false;

}

int Course::get_score() const
{
	return score;
}

bool Course::get_correct_() const
{
	if (correct_)
		return true;
	else 
		return false;
}
