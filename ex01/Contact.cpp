/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:05:12 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/20 08:14:08 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Contact.hpp"
# include <iomanip> //setw
# include <iostream> //cout cin & endl

void	Contact::displayFull() const
{
	if (isEmpty()) {
		std::cout << RED << "No Contacts to display. méiyǒu liánxì rén" << RESET << std::endl;
		return ;
	}
	std::cout << CYAN << "First Name / míng zi: " << firstName << RESET << std::endl;
	std::cout << CYAN << "Last Name / xìng: " << lastName << RESET << std::endl;
	std::cout << CYAN << "Nickname / chuò hào: " << nickName << RESET << std::endl;
	std::cout << CYAN << "Phone Number / diàn huà hào mǎ: " << phoneNumber << RESET << std::endl;
	std::cout << CYAN << "Darkest Secret / zuì shēn de mìmì: " << darkestSecret << RESET << std::endl;
}

bool	Contact::isEmpty() const
{
	return (firstName.empty()
				&& lastName.empty()
				&& nickName.empty()
				&& phoneNumber.empty()
				&& darkestSecret.empty());
}

void	Contact::displaySummary(int index) const
{
	if (isEmpty()) //maybe not needed since we already tracked outside what is filled/not filled
		return ;

	//index spaces
	std::cout << std::setw(10) << index + 1 << "|";

	//firstname
	if (firstName.length() > 10)
		std::cout << firstName.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << firstName;
	std::cout << "|";

	//lastname
	if (lastName.length() > 10)
		std::cout << lastName.substr(0,9) << ".";
	else
		std::cout << std::setw(10) << lastName;
	std::cout << "|";

	//nickName
	if (nickName.length() > 10)
		std::cout << nickName.substr(0,9) << ".";
	else
		std::cout << std::setw(10) << nickName;
	std::cout << std::endl;
}

void	Contact::setContact(std::string first, std::string last,
							std::string nick, std::string phone,
							std::string secret)
{
	firstName = first;
	lastName = last;
	nickName = nick;
	phoneNumber = phone;
	darkestSecret = secret;
}
