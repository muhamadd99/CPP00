/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:40:34 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/20 14:12:48 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define CYAN    "\033[1;36m"
# define GREEN   "\033[1;32m"
# define YELLOW  "\033[1;33m"
# define RED     "\033[1;31m" 
# define RESET   "\033[0m"

# include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8];
	int		contactCount;

public:
	PhoneBook();

	bool	addContact();
	bool	searchContacts() const;
	bool	str_onlywspace(const std::string& str) const;
	std::string	get_valid_str(const std::string& message);
}; //end of class definition

#endif