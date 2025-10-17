/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:05:12 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/17 10:48:47 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"

void	Contact::displayFull() const
{
	if (isEmpty()) { //do i need to print it wrong
		std::cout << "No Contacts to display. méiyǒu liánxì rén" << std::endl;
		return ;
	}
	std::cout << "First Name / míng zi: " << firstName << std::endl;
	std::cout << "Last Name / xìng: " << lastName << std::endl;
	std::cout << "Nickname / chuò hào: " << nickName << std::endl;
	std::cout << "Phone Number / diàn huà hào mǎ: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret / zuì shēn de mìmì: " << darkestSecret << std::endl;
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
	std::cout << std::setw(10) << index + 1<< "|";

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

// std::string	Contact::getFirstName() const
// {
// 	return (firstName);
// }

// std::string Contact::getLastName() const
// {
// 	return (lastName);
// }

// std::string Contact::getNickName() const
// {
// 	return (nickName);
// }

// std::string Contact::getPhoneNumber() const
// {
// 	return (phoneNumber);
// }

// std::string Contact::getDarkestSecret() const
// {
// 	return (darkestSecret);
// }