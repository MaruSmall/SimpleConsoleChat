#pragma once
#include <string>

/// <summary>
/// Сообщение.
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T> class Message
{
private:
	/// <summary>
	/// От кого.
	/// </summary>
	const std::string _from;

	/// <summary>
	/// Кому.
	/// </summary>
	const std::string _to;

	/// <summary>
	/// Тело сообщения. 
	/// </summary>
	const T _messageBody;

public:
	/// <summary>
	/// Конструктор.
	/// </summary>
	/// <param name="from"> От кого.</param>
	/// <param name="to"> Кому.</param>
	/// <param name="messageBody"> Тело сообщения.</param>
	Message(const std::string& from, const std::string& to, const T& messageBody)
		: _from(from), _to(to), _messageBody(messageBody) {};

	Message() = default;
	/// <summary>
	/// Деструктор.
	/// </summary>
	~Message() = default;

	/// <summary>
	/// От кого сообщение.
	/// </summary>
	/// <returns></returns>
	const std::string& getFrom() const 
	{ 
		return _from; 
	};

	/// <summary>
	/// Кому сообщение.
	/// </summary>
	/// <returns></returns>
	const std::string& getTo() const 
	{ 
		return _to; 
	};

	/// <summary>
	/// Получить тело сообщения.
	/// </summary>
	/// <returns></returns>
	const T& getText() const 
	{ 
		return _messageBody; 
	};
};

