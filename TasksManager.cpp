#include "TasksManager.h"
#include <iostream>
#include <string>

bool TasksManager::AddTask()
{
	std::string user_name;
	std::string user_desc;

	system("cls");
	std::cout << "Введите название задачи:" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, user_name);

	system("cls");
	std::cout << "Введите описание задачи:" << std::endl;
	std::getline(std::cin, user_desc);

	Task* new_task = new Task(user_name, user_desc);
	TasksManager::tasks_list.push_back(new_task);

	return true;
}

bool TasksManager::RenameTask()
{	
	std::size_t task_index;
	Task* renamable_task;

	system("cls");
	std::cout << "Введите индекс задачи" << std::endl;
	std::cin >> task_index;
	if (std::cin.fail()) {
		std::cout << "Неверный индекс!" << std::endl;
		std::cin.get();
		std::cin.clear();
		return true;
	}

	try {
		int choice;

		renamable_task = TasksManager::tasks_list.at(task_index);

		system("cls");
		std::cout << "Что вы собираетесь сделать?" << std::endl;
		std::cout << "\n[1] Переименовать название | [2] Переименовать описание" << std::endl;
		std::cin >> choice;

		if (choice < 1 && choice > 2) {
			return true;
		}

		switch (choice)
		{
			case 1:
			{
				std::string new_task_name;

				system("cls");
				std::cout << "Введите новое имя задачи:" << std::endl;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::getline(std::cin, new_task_name);

				renamable_task->setName(new_task_name);
				return true;
			}

			case 2:
			{
				std::string new_task_desc;

				system("cls");
				std::cout << "Введите новое описание задачи:" << std::endl;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::getline(std::cin, new_task_desc);

				renamable_task->setDescription(new_task_desc);
				return true;
			}
		}
	}
	catch (std::out_of_range e) {
		std::cout << "Неверный индекс!" << std::endl;
		std::cin.get();
		std::cin.clear();
		return true;
	}
}

bool TasksManager::DeleteTask()
{
	std::size_t task_index;

	system("cls");
	std::cout << "Введите индекс задачи:" << std::endl;
	std::cin >> task_index;
	if (std::cin.fail()) {
		std::cout << "Неверный индекс!" << std::endl;
		std::cin.get();
		std::cin.clear();
		return true;
	}
	else if (task_index < 0 || task_index > TasksManager::tasks_list.size()) {
		std::cout << "Неверный индекс!" << std::endl;
		std::cin.get();
		return true;
	}

	try {
		delete TasksManager::tasks_list.at(task_index);
		TasksManager::tasks_list.erase(TasksManager::tasks_list.begin() + task_index);
	}
	catch (std::exception e) {
		std::cout << "Неверный индекс" << std::endl;
		std::cin.get();
		std::cin.clear();
		return true;
	}
}

void TasksManager::DeleteAllCompletedTasks()
{
	for (std::size_t index = 0; index < TasksManager::tasks_list.size(); index++) {
		Task* task = TasksManager::tasks_list.at(index);
		if (task->getCompletion() == "Завершено") {
			delete task;
			TasksManager::tasks_list.erase(TasksManager::tasks_list.begin() + index);
		}
	}
}

