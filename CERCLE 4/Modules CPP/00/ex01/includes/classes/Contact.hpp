#ifndef CONTACT_CLASS_HPP
	#define CONTACT_CLASS_HPP

	#include <iostream>

	class Contact
	{
		public	:

			Contact();
			~Contact();

			void				setValue( const int value, const std::string& str );
			const std::string&	getValue( const int value ) const;

		private	:
		
			std::string	firstName;
			std::string	lastName;
			std::string	nickname;
			std::string	phoneNumber;
			std::string	darkestSecret;
	};

#endif