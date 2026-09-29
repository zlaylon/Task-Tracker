#pragma once
#include "Task.h"
#include <vector>

class TasksManager
{
	public:
		std::vector<Task*> tasks_list;

		bool AddTask();

		bool RenameTask();

		bool DeleteTask();

		void DeleteAllCompletedTasks();

		int GetAllTasks();

		int GetAllCompletedTasks();
};

