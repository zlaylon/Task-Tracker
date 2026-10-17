#include "Task.h"
#include <iostream>

Task::Task(std::string _name, std::string _desc)
{
	Task::task_name = _name;
	Task::description = _desc;
}

void Task::setName(std::string new_name)
{
	this->task_name = new_name;
}

void Task::setDescription(std::string new_description)
{
	this->description = new_description;
}

void Task::completeTask()
{
	if (!this->isCompleted) { this->isCompleted = true; }
}

std::string Task::getName()
{
	return this->task_name;
}

std::string Task::getDescription()
{
	return this->description;
}

std::string Task::getCompletion()
{
	return isCompleted ? "Завершено" : "Не завершено";
}
