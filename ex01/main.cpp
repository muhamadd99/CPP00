/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:58:05 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/19 17:42:19 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"
#include <iostream>
#include <string>

int	main()
{
	PhoneBook	pBook;
	std::string	command;
	
	while (true)
	{
		std::cout << YELLOW << "What do you want. Ni yao shenme? ADD / SEARCH / EXIT" << RESET << std::endl;
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << RED << "\n EOF" << RESET << std::endl;
			break ;
		}
		if (command == "ADD")
		{
			if (!pBook.addContact())
				break ;
		}
		else if (command == "SEARCH")
		{
			if (!pBook.searchContacts())
				break ;
		}
		else if  (command == "EXIT")
			break ;
		else
			std::cout << RED << "Invalid command\n" << RESET << std::endl;
	}
	return (0);
}