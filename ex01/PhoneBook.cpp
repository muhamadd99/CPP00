/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:40:39 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/13 18:27:22 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0) {}

void	PhoneBook::addContact()
{
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
	
	std::cout << "Qǐng gěi wǒ yí gè rén míngzì." << std::endl;

	std::cout << "First name. Mingzi: "; 
	std::getline(std::cin, firstName);

	std::cout << "Last name. xìng: ";
	std::getline(std::cin, lastName);

	std::cout << "Nickname. chuòhào: ";
	std::getline(std::cin, nickname);
	
	std::cout << "Phone number. diànhuà hàomǎ: ";
	std::getline(std::cin, phoneNumber);
	
	std::cout << "Darkest secret. zuì shēn de mìmì: ";
	std::getline(std::cin, darkestSecret);
	
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
	
	std::cout << "Zuò wán le" << std::endl;
}

void	PhoneBook::searchContacts() const
{
	std::cout << "Index     |First Name|Last Name |Nickname  " << std::endl;
	std::cout << "----------|----------|----------|----------" << std::endl;

	for(int i = 0; i < contactCount; i++)
	{
		//index spaces
		std::cout << i << "         |";
		
		//firstname
		std::string firstName = contacts[i].getFirstName();
		if (firstName.length() > 10)
			std::cout << firstName.substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << firstName;
		std::cout << "|";

		if (Phonebook.contacts[i])
			std::cout << Contact (getter?)
	}
}