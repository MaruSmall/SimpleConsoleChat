#pragma once
#include <vector>
#include "Message.h"
#include "User.h"
#include "UserExp.h"

/// <summary>
/// ���.
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T> class Chat
{
private:

	/// <summary>
	/// ������� �� ���.
	/// </summary>
	bool isStart = false;

	/// <summary>
	/// ������ �������������.
	/// </summary>
	std::vector<User> _users;

	/// <summary>
	/// ������ ���������.
	/// </summary>
	std::vector<Message<T>> _messages;

	/// <summary>
	/// ������� ������������.
	/// </summary>
	std::shared_ptr<User> _currentUser = nullptr;

	/// <summary>
	/// ����.
	/// </summary>
	void login()
	{
		std::string login, password;
		char operation;

		do
		{
			std::cout << "�����: ";
			std::cin >> login;
			std::cout << "������: ";
			std::cin >> password;

			_currentUser = getUserByLogin(login);

			if (_currentUser == nullptr || (password != _currentUser->getPassword()))
			{
				_currentUser = nullptr;

				std::cout << "������ �����!" << std::endl;
				std::cout << "������� ������ (0) ��� ������ ��� ����� ������ ��� �������";
				std::cin >> operation;

				if (operation == '0')
					break;
			}
		} while (!_currentUser);
	}

	/// <summary>
	/// �����������.
	/// </summary>
	void singUp()
	{
		std::string login, password, name;

		std::cout << "�����: ";
		std::cin >> login;
		std::cout << "������: ";
		std::cin >> password;
		std::cout << "���: ";
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
	/// �������� ���.
	/// </summary>
	void showChat() const
	{
		std::string from;
		std::string to;

		std::cout << "_____���_____" << std::endl;

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

				std::cout << "��������� ��: " << from << "����: " << to << std::endl;
				std::cout << "���������: " << mess.getText() << std::endl;
			}
		}

		std::cout << "____________________" << std::endl;
	}

	/// <summary>
	/// �������� ���� �������������.
	/// </summary>
	void showAllUsersName() const
	{
		std::cout << "_____������������_____" << std::endl;
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
	/// �������� ���������.
	/// </summary>
	void addMessage()
	{
		std::string to, text;

		std::cout << "���� (��� ��� ����, ����� ��������� ���� ��������� all): ";
		std::cin >> to;
		std::cout << "���������: ";
		std::cin.ignore();
		getline(std::cin, text);

		if (!(to == "all" || getUserByName(to)))
		{
			std::cout << "������ �������� ���������: �� ���� �����: " << to << std::endl;
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
	/// �������� ���� �������������.
	/// </summary>
	std::vector<User>& getAllUsers() 
	{ 
		return _users; 
	}

	/// <summary>
	/// �������� ��� ���������.
	/// </summary>
	std::vector<Message<T>>& getAllMessage()
	{ 
		return _messages; 
	}

	/// <summary>
	/// �������� ����� ������������.
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
	/// �������� ��� ������������.
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
	/// ��������� ���.
	/// </summary>
	void start()
	{
		isStart = true;
	}

	/// <summary>
	/// �������� �� ���.
	/// </summary>
	/// <returns> ���� ������ ����.</returns>
	bool isChatWork() const 
	{ 
		return isStart; 
	}

	/// <summary>
	/// �������� �������� ������������.
	/// </summary>
	/// <typeparam name="T"> ������������.</typeparam>
	std::shared_ptr<User> getCurrentUser() const 
	{ 
		return _currentUser; 
	}

	/// <summary>
	/// �������� ���� ��� �������� �� ��������������� ������������.
	/// </summary>
	void showLoginMenu()
	{
		_currentUser = nullptr;

		char operation;

		do
		{
			std::cout << "�������� �������� � ������� ����� ��������, ������� ���������� � �������" << std::endl;
			std::cout << "���� (1)" << std::endl;
			std::cout << "����������� (2)" << std::endl;
			std::cout << "��������� ������ ���� (0)" << std::endl;
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
				std::cout << "������� �� ���������� ��������" << std::endl;
				break;
			}
		} while (!_currentUser && isStart);
	}

	/// <summary>
	/// �������� ���� ��������������� ������������.
	/// </summary>
	void showUserMenu()
	{
		char operation;

		std::cout << "������, " << _currentUser->getName() << std::endl;

		while (_currentUser)
		{
			std::cout << "����: (1)�������� ��� | (2)��������� ��������� | (0)�����";

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
				std::cout << "������� �� ���������� ��������" << std::endl;
				break;
			}
		}
	}
};
