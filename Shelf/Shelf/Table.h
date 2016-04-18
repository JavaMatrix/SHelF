/*
 * Shelf - Super HELpful Functions library
 * Shelf Library by Nathanael Page is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 * Contains functions to help with fundamental C++ tasks.
 *
 * Table.h - Contains class declarations for creating tables.
 */

#pragma once
#include <string>
#include <iostream>
#include <string>
#include "ConsoleIO.h"

namespace shelf
{
	class BoxBrush
	{
	public:
		BoxBrush();
		BoxBrush(char*);

		std::string DrawSide(bool, int, int) const;
		std::string DrawDataLine(std::string*, int, int) const;
		std::string DrawDataLine(char*, int, int) const;
		std::string DrawDividingLine(int, int) const;
		std::string MakeHeader(std::string*, int) const;
		int AutoWidth(std::string*, int, int = 1) const;

		static const BoxBrush SINGLE;
		static const BoxBrush DOUBLE;
		static const BoxBrush BOLD_BORDER;
		static const BoxBrush ASCII;
		static const BoxBrush SLASHES;
	private:
		char corner[4];
		char side[2];
		char divider[2];
		char divider_side_border[4];
		char divider_intersect;
	};

	class Table
	{
	public:
		Table(int, int, int, BoxBrush);
		~Table(void);
		void WriteTable(void);
		std::string* headers;
		std::string** data;
	private:
		BoxBrush brush;
		int columns;
		int rows;
		int columnWidth;
	};
}