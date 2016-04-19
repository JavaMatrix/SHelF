/*
 * Shelf - Super HELpful Functions library
 * Shelf Library by Nathanael Page is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 * Contains functions to help with fundamental C++ tasks.
 *
 * Shelf.h - A one-shot header to include the entire library, as well as some helpers.
 */

#pragma once

#include "ConsoleIO.h"
#include "Table.h"
#include <string>

namespace shelf {
	void ping();
	string shelf::lib::get_version();
	std::string to_string(int);
	std::string to_string(double);
	std::string to_string(unsigned int);
}