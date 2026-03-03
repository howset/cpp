#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream> //getline, cin, cerr
# include <cctype> //isalpha
# include <iomanip> //setw()
# include <cstdlib> //atoi

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_number;
		std::string	dark_secret;
	public:
		void		set_entry();
		void		set_fields(std::string &field,
								const std::string &field_name,
								bool numbers);
		void		show_shorten(int index);
		void		show_complete();
		std::string	trim_str(std::string str);
};

#endif