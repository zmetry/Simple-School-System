#pragma once

#include<string>

#ifndef ALLSETTING_H_
#define ALLSETTING_H_

class Homework
{
private:
	int finish;           //学生是否完成作业
	int check;            //学生是否查看作业
	int exit;           //老师是否布置作业
public:
	Homework();
	~Homework();
	bool check_exit();
	friend class Teacher;
	friend class Student;
};

class Note
{
private:
	char *note;
	int exit;
public:
	Note();
	Note(const char *note = " ");
	~Note();
	friend class Student;
	char* get_note() const;
};

class Teacher
{
private:
	char *name;
	int teacher_num;
	int v;
public:
	Teacher(const char *name = "No name");
	void set_homework(Homework &p);
	Teacher();
	~Teacher();
	bool check_homework_exit(Homework &p) const;
	char* get_name() const;
	int get_teacher_num() const;
	int change_teacher_num();
};

class Student
{
private:
	int student_num;
	char *name;
	int exit_0;           //删除内存时区分
public:
	void finish_homework(Homework &p);
	void check_homework(Homework &p);
	void student_get(Homework &p);          //学生了解作业
	Student(const char *name = "No name", int student_num = 0);     //初始化函数,构造函数
	//Student(Student &p);                       //拷贝函数
	Student();
	~Student();            //析构函数
	friend class Homework;
	bool get_finish(Homework &p) const;
	char *get_name() const;
	int get_student_num()const;
	int change_student_num();
	char * get_note(Note &p);
	friend class Note;
	friend class Course;
};

class Course
{
private:
	char answer[20];              //学生的答案
	char correct_answer[20];     //老师设置的正确答案
	int exit;
	int score;                  //记录考试成绩
	int take_or_not;             //判断是否参加考试
	int test_exit;              //判断考试是否安排
	int correct_;                //老师是否改卷
public:
	void correct(Student &p) ;          //老师批改作业 
	void set_answer(char *answer);      //老师设置答案
	void student_answer(char *answer);   //学生的答案
	Course();
	~Course();
	void arrange_test();             //老师安排考试
	bool get_test_exit() const;           //学生了解考试是否进行
	bool get_take_or_not() const;     //了解学生是否参加考试
	int get_score() const;            //获取分数
	bool get_correct_() const;
	char * get_name(Student &p);
};

#endif // !ALLSETTING_H_
