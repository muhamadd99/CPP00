/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:40:39 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/20 14:13:40 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream> //cout cin
#include <string> //std::string

PhoneBook::PhoneBook() : contactCount(0) {}

bool	PhoneBook::str_onlywspace(const std::string& str) const
{
	for (size_t i = 0; i < str.length(); i++)
		if(!std::isspace(str[i]))
			return (false);
	return (true);
}

std::string	PhoneBook::get_valid_str(const std::string& message)
{
	std::string input;

	while (true)
	{
		std::cout << CYAN << message << RESET << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << RED <<"\n EOF signal" << RESET << std::endl;
			return ("");
		}
		if (!str_onlywspace(input) && !input.empty())
			break ;
		std::cout << RED << "Can't be empty. bù néng wéi kōng" << RESET << std::endl;
	}
	return (input);
}

//print question every variable
//take answer every variable
//register all variable into each contact
//less than 8, just add at the end
//more than 8,remove first, push up everything and add at the end
bool	PhoneBook::addContact()
{
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
	
	std::cout << CYAN << "1 name. Qǐng gěi wǒ yí gè rén míngzì." << RESET << std::endl;

	firstName = get_valid_str("First name / Míngzì: ");
	if (firstName.empty())
		return (false);
	lastName = get_valid_str("Last name. xìng: ");
	if (lastName.empty())
		return (false);
	nickname = get_valid_str("Nickname. chuòhào: ");
	if (nickname.empty())
		return (false);
	phoneNumber = get_valid_str("Phone number. diànhuà hàomǎ: ");
	if (phoneNumber.empty())
		return (false);
	darkestSecret = get_valid_str("Darkest secret. zuì shēn de mìmì: ");
	if (darkestSecret.empty())
		return (false);
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
	std::cout << CYAN << "Zuò wán le" << RESET << std::endl;
	return (true);
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

bool	PhoneBook::searchContacts() const
{
	std::cout << "Index     |First Name|Last Name |Nickname  " << std::endl;
	std::cout << "----------|----------|----------|----------" << std::endl;

	for(int i = 0; i < contactCount; i++)
		contacts[i].displaySummary(i);
	if (contactCount > 0)
	{
		std::cout << "\nWhich index you want? Nǐ yào nǎ ge suǒyǐn" << std::endl;
		std::string input;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << RED << "\n EOF" << RESET << std::endl;
			return (false);
		}
		if (input.length() == 1 && input[0] > '0' && input[0] < '9')
		{
			int index = input[0] - '0' - 1;
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
