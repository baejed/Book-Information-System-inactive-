#pragma once
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

const std::string server = "tcp://127.0.0.1:3306";
const std::string username = "root";
const std::string password = "";

sql::Driver* driver;
sql::Connection* con;

sql::Connection* getDatabaseConnection()
{
	try
	{
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
	}
	catch (std::exception e)
	{
		std::cout << "Could not connect to server. Error message: " << e.what() << std::endl;
		system("pause");
		exit(1);
	}

	return con;
}

bool CheckLoginInfo(std::string username, std::string password, sql::Connection* connection)
{
	connection->setSchema("book_information_system_db");
	std::string sqlQuery = ("SELECT * FROM login_information");
	sql::Statement* statement = connection->createStatement();
	sql::ResultSet* resultSet = statement->executeQuery(sqlQuery);

	while (resultSet->next())
	{
		bool usernameMatch = username == resultSet->getString(1);
		bool passwordMatch = password == resultSet->getString(2);

		if (usernameMatch && passwordMatch)
			return true;
	}

	return false;
}

bool BookExists(std::string isbn, sql::Connection* connection)
{
	connection->setSchema("book_information_system_db");
	std::string sqlQuery = ("SELECT * FROM book_informations");
	sql::Statement* statement = connection->createStatement();
	sql::ResultSet* resultSet = statement->executeQuery(sqlQuery);

	while (resultSet->next())
	{
		if (isbn == resultSet->getString(1))
			return true;
	}

	return false;
}

bool HasCompleteInput(std::string input1, std::string input2, std::string input3)
{
	if (!(input1 == "" || input2 == "" || input3 == ""))
		return true;
	else
		return false;
}

void AddOrUpdateBook(std::string isbn, std::string title, std::string author, sql::Connection* connection)
{

	std::string sqlQuery;
	sql::Statement* statement;

	if (BookExists(isbn, connection))
		sqlQuery = "UPDATE book_informations SET book_title = \"" + title + "\", author = \"" + author + "\" WHERE isbn = \"" + isbn + "\"";
	else
		sqlQuery = "INSERT INTO book_informations (isbn, book_title, author) VALUES (\"" + isbn + "\", \"" + title + "\", \"" + author + "\")";

	statement = connection->createStatement();

	if (HasCompleteInput(isbn, title, author))
	{
		try
		{
			sql::ResultSet* resultSet = statement->executeQuery(sqlQuery);

		}
		catch (std::exception e)
		{

		}
	}
}