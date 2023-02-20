#pragma once
#include <string>

/// <summary>
/// ������������.
/// </summary>
class User
{
private:
	/// <summary>
	/// �����.
	/// </summary>
	const std::string _login;

	/// <summary>
	/// ������.
	/// </summary>
	std::string _password;

	/// <summary>
	/// ���.
	/// </summary>
	std::string _name;

public:
	/// <summary>
	/// �����������.
	/// </summary>
	/// <param name="login"> �����.</param>
	/// <param name="password"> ������.</param>
	/// <param name="name"> ���.</param>
	User(const std::string& login, const std::string& password, const std::string& name)
		:_login(login), _password(password), _name(name) {};

	/// <summary>
	/// ���������� �� ���������.
	/// </summary>
	~User() = default;

	/// <summary>
	/// �������� �����.
	/// </summary>
	/// <returns> �����.</returns>
	const std::string& getLogin() const { return _login; };

	/// <summary>
	/// �������� ������.
	/// </summary>
	/// <returns> ������.</returns>
	const std::string& getPassword() const { return _password; };

	/// <summary>
	/// ���������� ������.
	/// </summary>
	/// <param name="password"> ������.</param>
	void setPassword(const std::string& password) { _password = password; };

	/// <summary>
	/// �������� ���.
	/// </summary>
	/// <returns> ���.</returns>
	const std::string& getName() const { return _name; }

	/// <summary>
	/// ��������� ���.
	/// </summary>
	/// <param name="name"> ���.</param>
	void setName(const std::string& name) { _name = name; };
};