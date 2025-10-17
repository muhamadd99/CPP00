/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:40:34 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/17 10:46:26 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>																										
# include <iostream>
# include <string>
# include <cstdlib>
# include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8];
	int		contactCount;

public:
	PhoneBook();

	void	addContact(); //no need parameter bcus cin take directly
	void	searchContacts() const;
}; //end of class definition

#endif