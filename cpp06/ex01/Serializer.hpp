/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:52:29 by gcavanna          #+#    #+#             */
/*   Updated: 2024/01/25 13:32:39 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIAZER_HPP
# define SERIALIAZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
	int	a;
	std::string b;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &other);
		~Serializer();

		Serializer &operator=(const Serializer &other);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data*	 deserialize(uintptr_t raw);

};


#endif