#pragma once
#include <vector>
#include "Message.h"
#include "User.h"
#include "UserExp.h"

/// <summary>
/// Чат.
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T> class Chat
{
private:

	/// <summary>
	/// Запущен ли чат.
	/// </summary>
	bool isStart = false;

	/// <summary>
	/// Массив пользователей.
	/// </summary>
	std::vector<User> _users;

	/// <summary>
	/// Массив сообщений.
	/// </summary>
	std::vector<Message<T>> _messages;

	/// <summary>
	/// Текущий пользователь.
	/// </summary>
	std::shared_ptr<User> _currentUser = nullptr;

	/// <summary>
	/// Вход.
	/// </summary>
	void login()
	{
		std::string login, password;
		char operation;

		do
		{
			std::cout << "Логин: ";
			std::cin >> login;
			std::cout << "Пароль: ";
			std::cin >> password;

			_currentUser = getUserByLogin(login);

			if (_currentUser == nullptr || (password != _currentUser->getPassword()))
			{
				_currentUser = nullptr;

				std::cout << "Ошибка входа!" << std::endl;
				std::cout << "Нажмите кнопку (0) для выхода или любую другую для повтора";
				std::cin >> operation;

				if (operation == '0')
					break;
			}
		} while (!_currentUser);
	}

	/// <summary>
	/// Регистрация.
	/// </summary>
	void singUp()
	{
		std::string login, password, name;

		std::cout << "Логин: ";
		std::cin >> login;
		std::cout << "Пароль: ";
		std::cin >> password;
		std::cout << "Имя: ";
		std::cin >> name;

		if (getUserByLogin(login) || login == "all")
		{
			throw UserLoginExp();
		}

		if (getUserByName(name) || name == "all")
		{
			throw UserNameExp();
		}

		User user = User(login, password, name);
		_users.push_back(user);
		_currentUser = std::make_shared<User>(user);
	}

	/// <summary>
	/// Показать чат.
	/// </summary>
	void showChat() const
	{
		std::string from;
		std::string to;

		std::cout << "_____Чат_____" << std::endl;

		for (auto& mess : _messages)
		{
			if (_currentUser->getLogin() == mess.getFrom() || _currentUser->getLogin() == mess.getTo() || mess.getTo() == "all")
			{
				from = (_currentUser->getLogin() == mess.getFrom()) ? "me" : getUserByLogin(mess.getFrom())->getName();

				if (mess.getTo() == "all")
				{
					to = "(all)";
				}

				else
				{
					to = (_currentUser->getLogin() == mess.getTo()) ? "me" : getUserByLogin(mess.getTo())->getName();
				}

				std::cout << "Сообщение от: " << from << "Кому: " << to << std::endl;
				std::cout << "Сообщение: " << mess.getText() << std::endl;
			}
		}

		std::cout << "____________________" << std::endl;
	}

	/// <summary>
	/// Показать всех пользователей.
	/// </summary>
	void showAllUsersName() const
	{
		std::cout << "_____Пользователи_____" << std::endl;
		for (auto& user : _users)
		{
			std::cout << user.getName();

			if (_currentUser->getLogin() == user.getLogin())
				std::cout << "(me)";

			std::cout << std::endl;
		}
		std::cout << "____________________" << std::endl;
	}

	/// <summary>
	/// Добавить сообщение.
	/// </summary>
	void addMessage()
	{
		std::string to, text;

		std::cout << "Кому (имя или всем, чтобы отправить всем пропишите all): ";
		std::cin >> to;
		std::cout << "Сообщение: ";
		std::cin.ignore();
		getline(std::cin, text);

		if (!(to == "all" || getUserByName(to)))
		{
			std::cout << "Ошибка отправки сообщения: не могу найти: " << to << std::endl;
			return;
		}

		if (to == "all")
		{
			_messages.push_back(Message<T>{ 
				_currentUser->getLogin(), 
				"all", 
				text });
		}
			
		else
		{
			_messages.push_back(Message<T>{
				_currentUser->getLogin(), 
				getUserByName(to)->getLogin(), 
				text });
		}
			
	}

	/// <summary>
	/// Получить всех пользователей.
	/// </summary>
	std::vector<User>& getAllUsers() 
	{ 
		return _users; 
	}

	/// <summary>
	/// Получить все сообщения.
	/// </summary>
	std::vector<Message<T>>& getAllMessage()
	{ 
		return _messages; 
	}

	/// <summary>
	/// Получить логин пользователя.
	/// </summary>
	std::shared_ptr<User> getUserByLogin(const std::string& login) const
	{
		for (auto& user : _users)
		{
			if (login == user.getLogin())
			{
				return std::make_shared<User>(user);
			}
		}

		return nullptr;
	}

	/// <summary>
	/// Получить имя пользователя.
	/// </summary>
	std::shared_ptr<User> getUserByName(const std::string& name) const
	{
		for (auto& user : _users)
		{
			if (name == user.getName())
			{
				return std::make_shared<User>(user);
			}
		}

		return nullptr;
	}

public:

	/// <summary>
	/// Запустить чат.
	/// </summary>
	void start()
	{
		isStart = true;
	}

	/// <summary>
	/// Работает ли чат.
	/// </summary>
	/// <returns> Флаг работы чата.</returns>
	bool isChatWork() const 
	{ 
		return isStart; 
	}

	/// <summary>
	/// Получить текущего пользователя.
	/// </summary>
	/// <typeparam name="T"> Пользователь.</typeparam>
	std::shared_ptr<User> getCurrentUser() const 
	{ 
		return _currentUser; 
	}

	/// <summary>
	/// Показать меню для действий не авторизованного пользователя.
	/// </summary>
	void showLoginMenu()
	{
		_currentUser = nullptr;

		char operation;

		do
		{
			std::cout << "Выберете действие и введите номер операции, которая находиться в скобках" << std::endl;
			std::cout << "Вход (1)" << std::endl;
			std::cout << "Регистрация (2)" << std::endl;
			std::cout << "Завершить работу чата (0)" << std::endl;
			std::cin >> operation;

			switch (operation)
			{
			case '1':
				login();
				break;

			case '2':
				try
				{
					singUp();
				}
				catch (const std::exception& e)
				{
					std::cout << e.what() << std::endl;
				}
				break;

			case '0':
				isStart = false;
				break;

			default:
				std::cout << "Введена не правильная операция" << std::endl;
				break;
			}
		} while (!_currentUser && isStart);
	}

	/// <summary>
	/// Показать менб авторизованного пользователя.
	/// </summary>
	void showUserMenu()
	{
		char operation;

		std::cout << "Привет, " << _currentUser->getName() << std::endl;

		while (_currentUser)
		{
			std::cout << "Меню: (1)Показать чат | (2)Отправить сообщение | (0)Выход";

			std::cout << std::endl;
			std::cin >> operation;

			switch (operation)
			{

			case '1':
				showChat();
				break;

			case '2':
				addMessage();
				break;

			case '3':
				showAllUsersName();
				break;

			case '0':
				_currentUser = nullptr;
				break;

			default:
				std::cout << "Введена не правильная операция" << std::endl;
				break;
			}
		}
	}
};
