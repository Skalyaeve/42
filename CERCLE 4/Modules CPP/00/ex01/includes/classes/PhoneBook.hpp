#ifndef PHONE_BOOK_CLASS_HPP
	#define PHONE_BOOK_CLASS_HPP

	#include "Contact.hpp"

	class PhoneBook
	{
		public	:

			PhoneBook();
			~PhoneBook();

			Contact&	getMember( const int index );
			const int&	showCount( void ) const;
			void		updateCount( void );
	
		private	:
		
			Contact		members[ 8 ];
			int			count;
	};

#endif