## Итоговое задание 32.6.1

Задание: создать тесты с моком объекта, имитирующим подключение к базе данных

Подробнее: напишите реализацию классов (которые будут участвовать в тестах), как показано на схеме:

![Схема](https://lms-cdn.skillfactory.ru/assets/courseware/v1/2d26d0aa699111a03f6a2315f8ded0b3/asset-v1:SkillFactory+CPLUS+2020+type@asset+block/CPLUS_32.6m_1.png)

Сборка через Make:
g++ -o main -std=c++17 DBConnection.cpp -I/usr/local/include -L/usr/local/lib -lgtest -lgtest_main -lpthread -lgmock
Подключение билиотек GTest и GMock
