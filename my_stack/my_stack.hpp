/*
 * my_stack.hpp
 * (C) Copyright Wei 2006
 * All Rights Reserved.
 *
 * $Id: $
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */
#ifndef MY_STACK_HPP__
#define MY_STACK_HPP__

#include <stdint.h>

#define STACK_SIZE	20

// IAR .. [Pa115]:no support for exported templates
template <class TA_>
class stack_tm
{
public:
	stack_tm();
	bool push(TA_ &);
	bool pop();
	TA_& top();	// peek the top
	int  size();
	bool empty();
	bool full();
private:
	TA_ a[STACK_SIZE];
	int tos; 	// Top of Stack
};

template <class TA_>
stack_tm<TA_>::stack_tm()
{
	tos = 0;
}

template <class TA_>
int stack_tm<TA_>::size()
{
	return tos;
}

template <class TA_>
bool stack_tm<TA_>::empty()
{
	return (tos == 0);
}

template <class TA_>
bool stack_tm<TA_>::full()
{
	return (tos == STACK_SIZE);
}

template <class TA_>
bool stack_tm<TA_>::push(TA_ &cm)
{
	if (full()) {return false;}

	a[tos++] = cm; // C99
	//memcpy(&a[tos++], &cm, sizeof(TA_));

	return true;
}

template <class TA_>
bool stack_tm<TA_>::pop()
{
	if (empty()) { return false; }

	--tos;
	return true;
}

template <class TA_>
TA_& stack_tm<TA_>::top()	// peek the top
{
	if (empty()) { return a[0]; } // undefined

	return a[tos - 1];
}

#endif /* MY_STACK_HPP__ */
