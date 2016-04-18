/*
 * Shelf - Super HELpful Functions library
 * Shelf Library by Nathanael Page is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
 * Contains functions to help with fundamental C++ tasks.
 *
 * ConsoleIO.h - contains a class declaration for basic console functions.
 */
#pragma once
#include <string>
#include <iostream>
#include <conio.h>
namespace shelf {
	class ConsoleIO
	{
	public:
		static void Write(std::string);
		static void WriteLine(std::string = "");
		static int GetNextInt(std::string, int = 0);
		static long GetNextLong(std::string, long = 0L);
		static double GetNextDouble(std::string, double = 0.0);
		static float GetNextFloat(std::string, float = 0.0f);
		static std::string GetNextString(std::string, int = 100);
		static char* GetNextCString(std::string, int=100);
		static std::string GetNextStringMasked(std::string, std::string="", int=100);
		static char GetNextChar(std::string, char*, int);
		static int GetNextPositiveInt(std::string, std::string, std::string);
		static double GetNextPositiveDouble(std::string, std::string, std::string);
		static void Wait();
	private:
		static bool in(char, char*, int);
	};
}