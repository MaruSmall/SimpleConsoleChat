#pragma once
#include <memory>

/// <summary>
/// ��������� ������ � ����������� ����� ������������.
/// </summary>
struct UserLoginExp : public std::exception {
	const char* what() const noexcept override 
	{ 
		return "������: ������������ � ����� ������� ��� ����"; 
	} 
};

/// <summary>
/// ��������� ������ � ����������� ������ ������������.
/// </summary>
struct UserNameExp : public std::exception {
	const char* what() const noexcept override 
	{ 
		return "������: ������������ � ����� ������ ��� ����"; 
	}
};