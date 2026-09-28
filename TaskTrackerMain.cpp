#include <iostream>
#include <vector>
#include <string>
#include "Task.h"
#include "TasksManager.h"

TasksManager* tskmng = new TasksManager();

int main()
{
	setlocale(LC_ALL, "");

	while (true)
	{
		system("cls");

		int user_input{};

		std::cout << "Трекер задач (1.3)" << std::endl;

		if (tskmng->tasks_list.empty()) {
			std::cout << "\n";
			std::cout << "У вас не имеется задач!" << std::endl;
			std::cout << "\n";
		}
		else {
			for (int i = 0; i < tskmng->tasks_list.size(); i++)
			{
				Task* task = tskmng->tasks_list[i];
				std::cout << "\n------------------------------------------------" << std::endl;
				std::cout << "[" << i << "] " << task->getName() << "\n" << task->getDescription() << "\nСтатус: " << task->getCompletion() << std::endl;
				std::cout << "------------------------------------------------" << std::endl;
			}
		}
		std::cout << "\nУчтите, что имя/описание задачи работает корректно только на английском языке!" << std::endl;
		std::cout << "[1] Создать задачу | [2] Изменить название задачи | [3] Удалить задачу | [4] Пометить задачу как завершенная" << std::endl;
		std::cout << "[5] Удалить все выполненные задачи" << std::endl;

		std::cin >> user_input;

		if (std::cin.fail())
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
			std::cin.clear();

			std::cout << "Неверные данные!";
			std::cin.get();
		}

		switch (user_input)
		{
			case 1:
			{
				while (tskmng->AddTask()) {
					break;
				}
				break;
			}

			case 2:
			{
				while (tskmng->RenameTask()) {
					break;
				}
				break;
			}

			case 3:
			{
				while (tskmng->DeleteTask()) {
					break;
				}
				break;
			}

			case 4:
			{
				Task* completable_task;
				std::size_t index;

				std::cout << "\nВведите индекс задачи для завершения: ";
				std::cin >> index;

				try {
					completable_task = tskmng->tasks_list.at(index);
					completable_task->completeTask();
					break;
				}
				catch (std::out_of_range e) {
					std::cout << "\nНеверный индекс!" << std::endl;
					std::cin.get();
					break;
				}
				break;
			}

			case 5:
			{
				tskmng->DeleteAllCompletedTasks();
				break;
			}
		}
	}
}