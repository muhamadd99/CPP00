/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:40:39 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/12 23:03:36 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"

int	main()
{
	PhoneBook	pBook;
	std::string	command;
	
	while (true)
	{
		std::cout << "What do you want? ADD / SEARCH / EXIT";
		std::getline(std::cin, command);

		if (command == "ADD")
			pBook.addContact();
		else if (command == "SEARCH")
			pBook.searchContacts();
		else if  (command == "EXIT")
			break ;
		else
			std::cout << "Invalid command\n";
	}
	return (0);
}

