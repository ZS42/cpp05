/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:36:52 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/09 15:08:53 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// never put try catch block in constructor or may have leaks
// must put in main here so that if catch is called by throw in
// constructor it isn't constructed
int main()
{
	try
	{
		Form Application;
		// std::cout << B << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	return 0;
}