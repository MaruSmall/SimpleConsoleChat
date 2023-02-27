# SimpleConsoleChat
Консольный чат, разработанный одним разработчиком (Грицаник Марина).

Чат представляет из себя простейшую реализацию консольного чата. 
Количество пользователей неограниченно. Чат запускатеся на одной компьютере. 

Функционал: При запуске чата пользователь попадает в главное меню,в которому предлагается выбрать из 3х вариантов действий: 
авторизация(login), зарегистрироваться(singUp), остановка приложения.

После регистрации пользователя, пользователь попадает в меню пользователя, где предлагается выбрать 3 варианта действия: Вход, Регистрация, Завершить работу чата.

Действие Вход: 
1. Возможна если пользователь был зарегистрирован ранее.
2. После входа показывается меню для выбора следующих действий: Показать чат, Отправить сообщение, Выход.

Действие Регистрация: 
1. Пользователю предлагается ввести логин, пароль и имя.

Действие Завершить работу чата:
1. Завершение работы программы.

Действие Показать чат:
1. Показывает сообщения от кого и само сообщения.

Действие Отправить сообщение:
1. Указываем имя пользователя или выбираем отправить всем.
2. Пишем сообщение.

В программе реализовано 4 класса: User, UserExp, Message, Chat.
Классы Message, Chat реализованные в виде шаблонов.
