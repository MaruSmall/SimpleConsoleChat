#pragma once
#include <string>

/// <summary>
/// Пользователь.
/// </summary>
class User
{
private:
	/// <summary>
	/// Логин.
	/// </summary>
	const std::string _login;

	/// <summary>
	/// Пароль.
	/// </summary>
	std::string _password;

	/// <summary>
	/// Имя.
	/// </summary>
	std::string _name;

public:
	/// <summary>
	/// Конструктор.
	/// </summary>
	/// <param name="login"> Логин.</param>
	/// <param name="password"> Пароль.</param>
	/// <param name="name"> Имя.</param>
	User(const std::string& login, const std::string& password, const std::string& name)
		:_login(login), _password(password), _name(name) {};

	/// <summary>
	/// Деструктор по умолчанию.
	/// </summary>
	~User() = default;

	/// <summary>
	/// Получить логин.
	/// </summary>
	/// <returns> Логин.</returns>
	const std::string& getLogin() const { return _login; };

	/// <summary>
	/// Получить пароль.
	/// </summary>
	/// <returns> Пароль.</returns>
	const std::string& getPassword() const { return _password; };

	/// <summary>
	/// Установить пароль.
	/// </summary>
	/// <param name="password"> Пароль.</param>
	void setPassword(const std::string& password) { _password = password; };

	/// <summary>
	/// Получить Имя.
	/// </summary>
	/// <returns> Имя.</returns>
	const std::string& getName() const { return _name; }

	/// <summary>
	/// Усановить имя.
	/// </summary>
	/// <param name="name"> Имя.</param>
	void setName(const std::string& name) { _name = name; };
};