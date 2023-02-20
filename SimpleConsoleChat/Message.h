#pragma once
#include <string>

/// <summary>
/// ���������
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T> class Message
{
private:
	/// <summary>
	/// �� ����.
	/// </summary>
	const std::string _from;
	
	/// <summary>
	/// ����.
	/// </summary>
	const std::string _to;
	
	/// <summary>
	/// ���� ���������. 
	/// </summary>
	const T _messageBody;

public:
	/// <summary>
	/// �����������.
	/// </summary>
	/// <param name="from"> �� ����.</param>
	/// <param name="to"> ����.</param>
	/// <param name="messageBody"> ���� ���������.</param>
	Message(const std::string& from, const std::string& to, const T& temessageBodyxt)
		: _from(from), _to(to), _messageBody(messageBody) {};
	
	/// <summary>
	/// ����������.
	/// </summary>
	~Message() = default;
	
	/// <summary>
	/// �� ���� ���������.
	/// </summary>
	/// <returns></returns>
	const std::string& getFrom() const { return _from; };
	
	/// <summary>
	/// ���� ���������.
	/// </summary>
	/// <returns></returns>
	const std::string& getTo() const { return _to; };
	
	/// <summary>
	/// �������� ���� ���������.
	/// </summary>
	/// <returns></returns>
	const T& getText() const { return _messageBody; };
};

