#pragma once
#include <memory>

/// <summary>
/// Обработка ошибки с дублирующим логин пользователя.
/// </summary>
struct UserLoginExp : public std::exception {
	const char* what() const noexcept override 
	{ 
		return "Ошибка: Пользователь с таким логином уже есть"; 
	} 
};

/// <summary>
/// Обработка ошибки с дублирующим именем пользователя.
/// </summary>
struct UserNameExp : public std::exception {
	const char* what() const noexcept override 
	{ 
		return "Ошибка: Пользователь с таким именем уже есть"; 
	}
};