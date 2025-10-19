/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:40:34 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/19 17:39:47 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define CYAN    "\033[1;36m"
# define GREEN   "\033[1;32m"
# define YELLOW  "\033[1;33m"
# define RED     "\033[1;31m" 
# define RESET   "\033[0m"

//# include <cstdlib>
# include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8];
	int		contactCount;

public:
	PhoneBook();

	bool	addContact(); //no need parameter bcus cin take directly
	bool	searchContacts() const;
}; //end of class definition

#endif