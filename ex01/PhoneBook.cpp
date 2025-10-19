/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:40:39 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/17 21:59:29 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"
#include "Contact.hpp"
#include <ostream>

PhoneBook::PhoneBook() : contactCount(0) {}

//print question every variable
//take answer every variable
//register all variable into each contact
//less than 8, just add at the end
//more than 8,remove first, push up everything and add at the end
bool	PhoneBook::addContact()
{
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
	
	std::cout << CYAN << "1 name. Qǐng gěi wǒ yí gè rén míngzì." << RESET << std::endl;

	while(true)
	{
		std::cout << CYAN << "First name. Mingzi: " << RESET << std::endl; 
		std::getline(std::cin, firstName);
		if (std::cin.eof())
		{
			std::cout << RED <<"\n EOF signal" << RESET << std::endl;
			return (false);
		}
		if (!firstName.empty())
			break ;
		std::cout << RED << "Can't be empty. bù néng wéi kōng" << RESET << std::endl;
	}
	while (true)
	{
		std::cout << CYAN << "Last name. xìng: " << RESET << std::endl;
		std::getline(std::cin, lastName);
		if (std::cin.eof())
		{
			std::cout << RED << "\n EOF signal" << RESET << std::endl;
			return (false);
		}
		if (!lastName.empty())
			break ;
		std::cout << RED << "Can't be empty. bù néng wéi kōng" << RESET << std::endl;
	}
	while(true)
	{
		std::cout << CYAN <<  "Nickname. chuòhào: " << RESET << std::endl;
		std::getline(std::cin, nickname);
		if (std::cin.eof())
		{
			std::cout << RED << "\nEOF signal" << RESET << std::endl;
			return (false);
		}
		if (!nickname.empty())
			break ;
		std::cout << RED << "Can't be empty. bù néng wéi kōng" << RESET << std::endl;
	}
	while(true)
	{
		std::cout << CYAN << "Phone number. diànhuà hàomǎ: " << RESET << std::endl;
		std::getline(std::cin, phoneNumber);
		if (std::cin.eof())
		{
			std::cout << RED << "\nEOF signal" << RESET << std::endl;
			return (false);
		}
		if (!phoneNumber.empty())
			break ;
		std::cout << RED << "Can't be empty. bù néng wéi kōng" << RESET <<  std::endl;
	}
	while (true)
	{
		std::cout << CYAN << "Darkest secret. zuì shēn de mìmì: " << RESET << std::endl;
		std::getline(std::cin, darkestSecret);
		if (std::cin.eof())
		{
			std::cout << RED << "\nEOF signal" << RESET << std::endl;
			return (false);
		}
		if (!darkestSecret.empty())
			break ;
		std::cout << RED << "Can't be empty. bù néng wéi kōng" << RESET << std::endl;
	}
	if (contactCount < 8)
	{
		contacts[contactCount].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
		contactCount++;
	}
	else
	{
		for (int i = 0; i < 7; i++)
			contacts[i] = contacts[i + 1];
		contacts[7].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	}
	// if (contactCount < 8)
	// {
	// 	for (int i = contactCount - 1; i >= 0; i--)
	// 		contacts[i + 1] = contacts[i];
	// 	contacts[0].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	// 	contactCount++;
	// }
	// else
	// {
	// 	for (int i = 6; i > 0; i--)
	// 		contacts[i + 1] = contacts[i];
	// 	contacts[0].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	// }
	std::cout << CYAN << "Zuò wán le" << RESET << std::endl;
	return (true);
}

//print the first 2 lines
//display every contact w/ proper spacing
//display firstname
//display lastname
//display nickname
//print enter index and take input
//convert input to integer and check the number valid or not
//if no contacts print no contact
//if have contacts ask which index is it? take cin
//change to int and check it is valid or not. if it is below contact number then print
//if not, print invalid index
bool	PhoneBook::searchContacts() const
{
	std::cout << "Index     |First Name|Last Name |Nickname  " << std::endl;
	std::cout << "----------|----------|----------|----------" << std::endl;

	for(int i = 0; i < contactCount; i++)
		contacts[i].displaySummary(i);
	//start asking which index we want specifically?
	if (contactCount > 0)
	{
		//do we need to print \n before this statement?
		std::cout << "\nWhich index you want? Nǐ yào nǎ ge suǒyǐn" << std::endl;
		std::string input;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << RED << "\n EOF" << RESET << std::endl;
			return (false);
		}
		if (input.length() == 1 && input[0] > '0' && input[0] < '9') //need to check this one
		{
			int index = input[0] - '0' - 1; // -1 bcus in my program all start to count with 0. but from user it appears starting from 1. 1 from user is 0 for me.
			if (index < contactCount)
				contacts[index].displayFull();
			else
				std::cout << RED << "Invalid index! Suǒyǐn bù duì" << RESET <<  std::endl;
		}
		else
			std::cout << RED << "Invalid index! Suǒyǐn bù duì" << RESET << std::endl;
	}
	else
		std::cout << RED <<  "\nNo contacts to display. méiyǒu liánxì rén" << RESET << std::endl;
	return (true);
}

// //print the first 2 lines
// //display every contact w/ proper spacing
// //display firstname
// //display lastname
// //display nickname
// //print enter index and take input
// //convert input to integer and check the number valid or not
// //if no contacts print no contact
// //if have contacts ask which index is it? take cin
// //change to int and check it is valid or not. if it is below contact number then print
// //if not, print invalid index
// void	PhoneBook::searchContacts() const
// {
// 	std::cout << "Index     |First Name|Last Name |Nickname  " << std::endl;
// 	std::cout << "----------|----------|----------|----------" << std::endl;

// 	for(int i = 0; i < contactCount; i++)
// 	{
// 		//index spaces
// 		std::cout << std::setw(10) << i << "|";
		
// 		//firstname
// 		std::string firstName = contacts[i].getFirstName();
// 		if (firstName.length() > 10)
// 			std::cout << firstName.substr(0, 9) << ".";
// 		else
// 			std::cout << std::setw(10) << firstName;
// 		std::cout << "|";

// 		//lastname
// 		std::string lastName = contacts[i].getLastName();
// 		if (lastName.length() > 10)
// 			std::cout << lastName.substr(0,9) << ".";
// 		else
// 			std::cout << std::setw(10) << lastName;
// 		std::cout << "|";
		
// 		//nickName
// 		std::string nickName = contacts[i].getNickName();
// 		if (nickName.length() > 10)
// 			std::cout << nickName.substr(0,9) << ".";
// 		else
// 			std::cout << std::setw(10) << nickName;
// 		std::cout << std::endl;
// 	}
// 	//start asking which index we want specifically?
// 	if (contactCount > 0)
// 	{
// 		//do we need to print \n before this statement?
// 		std::cout << "\nWhich index you want? Nǐ yào nǎ ge suǒyǐn";
// 		std::string input;
// 		std::getline(std::cin, input);
// 		if (input.length() == 1 && input[0] >= '0' && input[0] <= '7') //need to check this one
// 		{
// 			int index = input[0] - '0';
// 			if (index < contactCount)
// 				contacts[index].displayFull();
// 			else
// 				std::cout << "Invalid index! Suǒyǐn bù duì" << std::endl;
// 		}
// 		else
// 			std::cout << "Invalid index! Suǒyǐn bù duì" << std::endl;
// 	}
// 	else
// 		std::cout << "\nNo contacts to display. méiyǒu liánxì rén";
// }