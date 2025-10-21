// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"


int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t; //store account object.vector is configurable array
	typedef std::vector<int>								  ints_t; //store transaction amount
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t; //a pair containing account and transaction amount

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 }; //initialize every acc
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) ); //sizeof(amounts) = total memory used. amounts_size = number of elements
	accounts_t				accounts( amounts, amounts + amounts_size ); // creating account. the parameter is stop before amounts + amounts_size
	accounts_t::iterator	acc_begin	= accounts.begin(); //iterator points at the 1st acc
	accounts_t::iterator	acc_end		= accounts.end(); //iterator at the last acc

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 }; //deposits init
	size_t const		d_size( sizeof(d) / sizeof(int) ); //size of the array / size of int bytes = no of elements
	ints_t				deposits( d, d + d_size ); //the start and the end marking
	ints_t::iterator	dep_begin	= deposits.begin(); //mark at the starts of the deposits
	ints_t::iterator	dep_end		= deposits.end(); //mark at the end of deposits

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 }; //withdrawals init
	size_t const		w_size( sizeof(w) / sizeof(int) ); //size of the array/size of int = no of elements
	ints_t				withdrawals( w, w + w_size ); //start of the array and end of array
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	Account::displayAccountsInfos(); //show total across all acc
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) ); //show each acc individually
	//starting from acc_begin to acc_end. call the function displaystatus
	for ( acc_int_t it( acc_begin, dep_begin );it.first != acc_end && it.second != dep_end;++(it.first), ++(it.second) ) { //pre increment because post increment do extra work. memorize value b4 increment

		(*(it.first)).makeDeposit( *(it.second) );//dereference account then makedeposit then pass deposit
	}

	Account::displayAccountsInfos(); //show total after depo
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );//iterate from start to end then displaystatus for every type

	for ( acc_int_t it( acc_begin, wit_begin ); //start iterate from acc_begin and withdraw_begin
		  it.first != acc_end && it.second != wit_end; //as long as it doesnt reach acc_end
		  ++(it.first), ++(it.second) ) { //pre increment because post increment takes extra memory store old value

		(*(it.first)).makeWithdrawal( *(it.second) );//access account and makewithdrawal using value
	}

	Account::displayAccountsInfos(); //show total after withdraw
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );//for every iteration display status

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
