+ACM-pragma once
+ACM-include +ADw-vector+AD4-
+ACM-include +ACI-Message.h+ACI-
+ACM-include +ACI-User.h+ACI-
+ACM-include +ACI-UserExp.h+ACI-

/// +ADw-summary+AD4-
/// +BCcEMARC-. 
/// +ADw-/summary+AD4-
/// +ADw-typeparam name+AD0AIg-T+ACIAPgA8-/typeparam+AD4-
template +ADw-typename T+AD4- class Chat
+AHs-
private:

	/// +ADw-summary+AD4-
	/// +BBcEMAQ/BEMESQQ1BD0- +BDsEOA- +BEcEMARC-.
	/// +ADw-/summary+AD4-
	bool isStart +AD0- false+ADs-

	/// +ADw-summary+AD4-
	/// +BBwEMARBBEEEOAQy- +BD8EPgQ7BEwENwQ+BDIEMARCBDUEOwQ1BDk-.
	/// +ADw-/summary+AD4-
	std::vector+ADw-User+AD4- +AF8-users+ADs-

	/// +ADw-summary+AD4-
	/// +BBwEMARBBEEEOAQy- +BEEEPgQ+BDEESQQ1BD0EOAQ5-.
	/// +ADw-/summary+AD4-
	std::vector+ADw-Message+ADw-T+AD4APg- +AF8-messages+ADs-

	/// +ADw-summary+AD4-
	/// +BCIENQQ6BEMESQQ4BDk- +BD8EPgQ7BEwENwQ+BDIEMARCBDUEOwRM-.
	/// +ADw-/summary+AD4-
	std::shared+AF8-ptr+ADw-User+AD4- +AF8-currentUser +AD0- nullptr+ADs-

	/// +ADw-summary+AD4-
	/// +BBIERQQ+BDQ-.
	/// +ADw-/summary+AD4-
	void login()
	+AHs-
		std::string login, password+ADs-
		char operation+ADs-

		do
		+AHs-
			std::cout +ADwAPA- +ACIEGwQ+BDMEOAQ9-: +ACIAOw-
			std::cin +AD4APg- login+ADs-
			std::cout +ADwAPA- +ACIEHwQwBEAEPgQ7BEw-: +ACIAOw-
			std::cin +AD4APg- password+ADs-

			+AF8-currentUser +AD0- getUserByLogin(login)+ADs-

			if (+AF8-currentUser +AD0APQ- nullptr +AHwAfA- (password +ACEAPQ- +AF8-currentUser-+AD4-getPassword()))
			+AHs-
				+AF8-currentUser +AD0- nullptr+ADs-

				std::cout +ADwAPA- +ACIEHgRIBDgEMQQ6BDA- +BDIERQQ+BDQEMAAhACI- +ADwAPA- std::endl+ADs-
				std::cout +ADwAPA- +ACIEHQQwBDYEPAQ4BEIENQ- +BDoEPQQ+BD8EOgRD- (0) +BDQEOwRP- +BDIESwRFBD4ENAQw- +BDgEOwQ4- +BDsETgQxBEMETg- +BDQEQARDBDMEQwRO- +BDQEOwRP- +BD8EPgQyBEIEPgRABDAAIgA7-
				std::cin +AD4APg- operation+ADs-

				if (operation +AD0APQ- '0')
					break+ADs-
			+AH0-
		+AH0- while (+ACEAXw-currentUser)+ADs-
	+AH0-

	/// +ADw-summary+AD4-
	/// +BCAENQQzBDgEQQRCBEAEMARGBDgETw-.
	/// +ADw-/summary+AD4-
	void singUp()
	+AHs-
		std::string login, password, name+ADs-

		std::cout +ADwAPA- +ACIEGwQ+BDMEOAQ9-: +ACIAOw-
		std::cin +AD4APg- login+ADs-
		std::cout +ADwAPA- +ACIEHwQwBEAEPgQ7BEw-: +ACIAOw-
		std::cin +AD4APg- password+ADs-
		std::cout +ADwAPA- +ACIEGAQ8BE8-: +ACIAOw-
		std::cin +AD4APg- name+ADs-

		if (getUserByLogin(login) +AHwAfA- login +AD0APQ- +ACI-all+ACI-)
		+AHs-
			throw UserLoginExp()+ADs-
		+AH0-

		if (getUserByName(name) +AHwAfA- name +AD0APQ- +ACI-all+ACI-)
		+AHs-
			throw UserNameExp()+ADs-
		+AH0-

		User user +AD0- User(login, password, name)+ADs-
		+AF8-users.push+AF8-back(user)+ADs-
		+AF8-currentUser +AD0- std::make+AF8-shared+ADw-User+AD4-(user)+ADs-
	+AH0-

	/// +ADw-summary+AD4-
	/// +BB8EPgQ6BDAENwQwBEIETA- +BEcEMARC-.
	/// +ADw-/summary+AD4-
	void showChat() const
	+AHs-
		std::string from+ADs-
		std::string to+ADs-

		std::cout +ADwAPA- +ACIAXwBfAF8AXwBfBCcEMARCAF8AXwBfAF8AXwAi- +ADwAPA- std::endl+ADs-

		for (auto+ACY- mess : +AF8-messages)
		+AHs-
			if (+AF8-currentUser-+AD4-getLogin() +AD0APQ- mess.getFrom() +AHwAfA- +AF8-currentUser-+AD4-getLogin() +AD0APQ- mess.getTo() +AHwAfA- mess.getTo() +AD0APQ- +ACI-all+ACI-)
			+AHs-
				from +AD0- (+AF8-currentUser-+AD4-getLogin() +AD0APQ- mess.getFrom()) ? +ACI-me+ACI- : getUserByLogin(mess.getFrom())-+AD4-getName()+ADs-

				if (mess.getTo() +AD0APQ- +ACI-all+ACI-)
				+AHs-
					to +AD0- +ACI-(all)+ACIAOw-
				+AH0-

				else
				+AHs-
					to +AD0- (+AF8-currentUser-+AD4-getLogin() +AD0APQ- mess.getTo()) ? +ACI-me+ACI- : getUserByLogin(mess.getTo())-+AD4-getName()+ADs-
				+AH0-

				std::cout +ADwAPA- +ACIEIQQ+BD4EMQRJBDUEPQQ4BDU- +BD4EQg-: +ACI- +ADwAPA- from +ADwAPA- +ACIEGgQ+BDwEQw-: +ACI- +ADwAPA- to +ADwAPA- std::endl+ADs-
				std::cout +ADwAPA- +ACIEIQQ+BD4EMQRJBDUEPQQ4BDU-: +ACI- +ADwAPA- mess.getText() +ADwAPA- std::endl+ADs-
			+AH0-
		+AH0-

		std::cout +ADwAPA- +ACIAXwBfAF8AXwBfAF8AXwBfAF8AXwBfAF8AXwBfAF8AXwBfAF8AXwBfACI- +ADwAPA- std::endl+ADs-
	+AH0-

	/// +ADw-summary+AD4-
	/// +BB8EPgQ6BDAENwQwBEIETA- +BDIEQQQ1BEU- +BD8EPgQ7BEwENwQ+BDIEMARCBDUEOwQ1BDk-.
	/// +ADw-/summary+AD4-
	void showAllUsersName() const
	+AHs-
		std::cout +ADwAPA- +ACIAXwBfAF8AXwBfBB8EPgQ7BEwENwQ+BDIEMARCBDUEOwQ4AF8AXwBfAF8AXwAi- +ADwAPA- std::endl+ADs-
		for (auto+ACY- user : +AF8-users)
		+AHs-
			std::cout +ADwAPA- user.getName()+ADs-

			if (+AF8-currentUser-+AD4-getLogin() +AD0APQ- user.getLogin())
				std::cout +ADwAPA- +ACI-(me)+ACIAOw-

			std::cout +ADwAPA- std::endl+ADs-
		+AH0-
		std::cout +ADwAPA- +ACIAXwBfAF8AXwBfAF8AXwBfAF8AXwBfAF8AXwBfAF8AXwBfAF8AXwBfACI- +ADwAPA- std::endl+ADs-
	+AH0-

	/// +ADw-summary+AD4-
	/// +BBQEPgQxBDAEMgQ4BEIETA- +BEEEPgQ+BDEESQQ1BD0EOAQ1-.
	/// +ADw-/summary+AD4-
	void addMessage()
	+AHs-
		std::string to, text+ADs-

		std::cout +ADwAPA- +ACIEGgQ+BDwEQw- (+BDgEPARP- +BDgEOwQ4- +BDIEQQQ1BDw-, +BEcEQgQ+BDEESw- +BD4EQgQ/BEAEMAQyBDgEQgRM- +BDIEQQQ1BDw- +BD8EQAQ+BD8EOARIBDgEQgQ1- all): +ACIAOw-
		std::cin +AD4APg- to+ADs-
		std::cout +ADwAPA- +ACIEIQQ+BD4EMQRJBDUEPQQ4BDU-: +ACIAOw-
		std::cin.ignore()+ADs-
		getline(std::cin, text)+ADs-

		if (+ACE-(to +AD0APQ- +ACI-all+ACI- +AHwAfA- getUserByName(to)))
		+AHs-
			std::cout +ADwAPA- +ACIEHgRIBDgEMQQ6BDA- +BD4EQgQ/BEAEMAQyBDoEOA- +BEEEPgQ+BDEESQQ1BD0EOARP-: +BD0ENQ- +BDwEPgQzBEM- +BD0EMAQ5BEIEOA-: +ACI- +ADwAPA- to +ADwAPA- std::endl+ADs-
			return+ADs-
		+AH0-

		if (to +AD0APQ- +ACI-all+ACI-)
		+AHs-
			+AF8-messages.push+AF8-back(Message+ADw-T+AD4Aew- 
				+AF8-currentUser-+AD4-getLogin(), 
				+ACI-all+ACI-, 
				text +AH0-)+ADs-
		+AH0-
			
		else
		+AHs-
			+AF8-messages.push+AF8-back(Message+ADw-T+AD4Aew-
				+AF8-currentUser-+AD4-getLogin(), 
				getUserByName(to)-+AD4-getLogin(), 
				text +AH0-)+ADs-
		+AH0-
			
	+AH0-

	/// +ADw-summary+AD4-
	/// +BB8EPgQ7BEMERwQ4BEIETA- +BDIEQQQ1BEU- +BD8EPgQ7BEwENwQ+BDIEMARCBDUEOwQ1BDk-.
	/// +ADw-/summary+AD4-
	std::vector+ADw-User+AD4AJg- getAllUsers() 
	+AHs- 
		return +AF8-users+ADs- 
	+AH0-

	/// +ADw-summary+AD4-
	/// +BB8EPgQ7BEMERwQ4BEIETA- +BDIEQQQ1- +BEEEPgQ+BDEESQQ1BD0EOARP-.
	/// +ADw-/summary+AD4-
	std::vector+ADw-Message+ADw-T+AD4APgAm- getAllMessage()
	+AHs- 
		return +AF8-messages+ADs- 
	+AH0-

	/// +ADw-summary+AD4-
	/// +BB8EPgQ7BEMERwQ4BEIETA- +BDsEPgQzBDgEPQ- +BD8EPgQ7BEwENwQ+BDIEMARCBDUEOwRP-.
	/// +ADw-/summary+AD4-
	std::shared+AF8-ptr+ADw-User+AD4- getUserByLogin(const std::string+ACY- login) const
	+AHs-
		for (auto+ACY- user : +AF8-users)
		+AHs-
			if (login +AD0APQ- user.getLogin())
			+AHs-
				return std::make+AF8-shared+ADw-User+AD4-(user)+ADs-
			+AH0-
		+AH0-

		return nullptr+ADs-
	+AH0-

	/// +ADw-summary+AD4-
	/// +BB8EPgQ7BEMERwQ4BEIETA- +BDgEPARP- +BD8EPgQ7BEwENwQ+BDIEMARCBDUEOwRP-.
	/// +ADw-/summary+AD4-
	std::shared+AF8-ptr+ADw-User+AD4- getUserByName(const std::string+ACY- name) const
	+AHs-
		for (auto+ACY- user : +AF8-users)
		+AHs-
			if (name +AD0APQ- user.getName())
			+AHs-
				return std::make+AF8-shared+ADw-User+AD4-(user)+ADs-
			+AH0-
		+AH0-

		return nullptr+ADs-
	+AH0-

public:

	/// +ADw-summary+AD4-
	/// +BBcEMAQ/BEMEQQRCBDgEQgRM- +BEcEMARC-.
	/// +ADw-/summary+AD4-
	void start()
	+AHs-
		isStart +AD0- true+ADs-
	+AH0-

	/// +ADw-summary+AD4-
	/// +BCAEMAQxBD4EQgQwBDUEQg- +BDsEOA- +BEcEMARC-.
	/// +ADw-/summary+AD4-
	/// +ADw-returns+AD4- +BCQEOwQwBDM- +BEAEMAQxBD4EQgRL- +BEcEMARCBDA-.+ADw-/returns+AD4-
	bool isChatWork() const 
	+AHs- 
		return isStart+ADs- 
	+AH0-

	/// +ADw-summary+AD4-
	/// +BB8EPgQ7BEMERwQ4BEIETA- +BEIENQQ6BEMESQQ1BDMEPg- +BD8EPgQ7BEwENwQ+BDIEMARCBDUEOwRP-.
	/// +ADw-/summary+AD4-
	/// +ADw-typeparam name+AD0AIg-T+ACIAPg- +BB8EPgQ7BEwENwQ+BDIEMARCBDUEOwRM-.+ADw-/typeparam+AD4-
	std::shared+AF8-ptr+ADw-User+AD4- getCurrentUser() const 
	+AHs- 
		return +AF8-currentUser+ADs- 
	+AH0-

	/// +ADw-summary+AD4-
	/// +BB8EPgQ6BDAENwQwBEIETA- +BDwENQQ9BE4- +BDQEOwRP- +BDQENQQ5BEEEQgQyBDgEOQ- +BD0ENQ- +BDAEMgRCBD4EQAQ4BDcEPgQyBDAEPQQ9BD4EMwQ+- +BD8EPgQ7BEwENwQ+BDIEMARCBDUEOwRP-.
	/// +ADw-/summary+AD4-
	void showLoginMenu()
	+AHs-
		+AF8-currentUser +AD0- nullptr+ADs-

		char operation+ADs-

		do
		+AHs-
			std::cout +ADwAPA- +ACIEEgRLBDEENQRABDUEQgQ1- +BDQENQQ5BEEEQgQyBDgENQ- +BDg- +BDIEMgQ1BDQEOARCBDU- +BD0EPgQ8BDUEQA- +BD4EPwQ1BEAEMARGBDgEOA-, +BDoEPgRCBD4EQAQwBE8- +BD0EMARFBD4ENAQ4BEIETARBBE8- +BDI- +BEEEOgQ+BDEEOgQwBEUAIg- +ADwAPA- std::endl+ADs-
			std::cout +ADwAPA- +ACIEEgRFBD4ENA- (1)+ACI- +ADwAPA- std::endl+ADs-
			std::cout +ADwAPA- +ACIEIAQ1BDMEOARBBEIEQAQwBEYEOARP- (2)+ACI- +ADwAPA- std::endl+ADs-
			std::cout +ADwAPA- +ACIEFwQwBDIENQRABEgEOARCBEw- +BEAEMAQxBD4EQgRD- +BEcEMARCBDA- (0)+ACI- +ADwAPA- std::endl+ADs-
			std::cin +AD4APg- operation+ADs-

			switch (operation)
			+AHs-
			case '1':
				login()+ADs-
				break+ADs-

			case '2':
				try
				+AHs-
					singUp()+ADs-
				+AH0-
				catch (const std::exception+ACY- e)
				+AHs-
					std::cout +ADwAPA- e.what() +ADwAPA- std::endl+ADs-
				+AH0-
				break+ADs-

			case '0':
				isStart +AD0- false+ADs-
				break+ADs-

			default:
				std::cout +ADwAPA- +ACIEEgQyBDUENAQ1BD0EMA- +BD0ENQ- +BD8EQAQwBDIEOAQ7BEwEPQQwBE8- +BD4EPwQ1BEAEMARGBDgETwAi- +ADwAPA- std::endl+ADs-
				break+ADs-
			+AH0-
		+AH0- while (+ACEAXw-currentUser +ACYAJg- isStart)+ADs-
	+AH0-

	/// +ADw-summary+AD4-
	/// +BB8EPgQ6BDAENwQwBEIETA- +BDwENQQ9BDE- +BDAEMgRCBD4EQAQ4BDcEPgQyBDAEPQQ9BD4EMwQ+- +BD8EPgQ7BEwENwQ+BDIEMARCBDUEOwRP-.
	/// +ADw-/summary+AD4-
	void showUserMenu()
	+AHs-
		char operation+ADs-

		std::cout +ADwAPA- +ACIEHwRABDgEMgQ1BEI-, +ACI- +ADwAPA- +AF8-currentUser-+AD4-getName() +ADwAPA- std::endl+ADs-

		while (+AF8-currentUser)
		+AHs-
			std::cout +ADwAPA- +ACIEHAQ1BD0ETg-: (1)+BB8EPgQ6BDAENwQwBEIETA- +BEcEMARC- +AHw- (2)+BB4EQgQ/BEAEMAQyBDgEQgRM- +BEEEPgQ+BDEESQQ1BD0EOAQ1- +AHw- (0)+BBIESwRFBD4ENAAiADs-

			std::cout +ADwAPA- std::endl+ADs-
			std::cin +AD4APg- operation+ADs-

			switch (operation)
			+AHs-

			case '1':
				showChat()+ADs-
				break+ADs-

			case '2':
				addMessage()+ADs-
				break+ADs-

			case '3':
				showAllUsersName()+ADs-
				break+ADs-

			case '0':
				+AF8-currentUser +AD0- nullptr+ADs-
				break+ADs-

			default:
				std::cout +ADwAPA- +ACIEEgQyBDUENAQ1BD0EMA- +BD0ENQ- +BD8EQAQwBDIEOAQ7BEwEPQQwBE8- +BD4EPwQ1BEAEMARGBDgETwAi- +ADwAPA- std::endl+ADs-
				break+ADs-
			+AH0-
		+AH0-
	+AH0-
+AH0AOw-
