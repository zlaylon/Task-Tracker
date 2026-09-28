#pragma once

#include <iostream>

class Task
{
	public:
		Task(std::string _name, std::string _desc);

		void setName(std::string new_name);

		void setDescription(std::string new_description);

		void completeTask();

		std::string getName();

		std::string getDescription();

		std::string getCompletion();

	private:
		std::string task_name;
		std::string description;
		bool isCompleted = false;
};

