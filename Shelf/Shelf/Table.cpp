/*
* Shelf - Super HELpful Functions library
* Shelf Library by Nathanael Page is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
* Contains functions to help with fundamental C++ tasks.
*
* Table.cpp - contains definitions for the Table and BoxBrush classes.
*/

#include "Table.h"

using namespace std;

namespace shelf {
#pragma region BoxBrush
	const BoxBrush BoxBrush::SINGLE("\u00DA\u00BF\u00D9\u00C0\u00B3\u00C4\u00B3\u00C4\u00C2\u00B4\u00C1\u00C3\u00C5");
	const BoxBrush BoxBrush::DOUBLE("\u00C9\u00BB\u00BC\u00C8\u00BA\u00CD\u00BA\u00CD\u00CB\u00B9\u00CA\u00CC\u00CE");
	const BoxBrush BoxBrush::BOLD_BORDER("\u00C9\u00BB\u00CB\u00C8\u00BA\u00CD\u00B3\u00C4\u00D1\u00B6\u00CF\u00C7\u00C5");
	const BoxBrush BoxBrush::ASCII("++++|-|-+++++");
	const BoxBrush BoxBrush::SLASHES("/////////////");

	BoxBrush::BoxBrush() {
		for (int i = 0; i < 4; i++)
			corner[i] = '+';

		side[0] = '|';
		side[1] = '-';

		divider[0] = '|';
		divider[1] = '-';

		for (int i = 0; i < 4; i++)
			divider_side_border[i] = '+';

		divider_intersect = '+';
	}

	BoxBrush::BoxBrush(char* chars) {
		for (int i = 0; i < 4; i++)
			corner[i] = chars[i];
		for (int i = 0; i < 2; i++)
			side[i] = chars[i + 4];
		for (int i = 0; i < 2; i++)
			divider[i] = chars[i + 6];
		for (int i = 0; i < 4; i++)
			divider_side_border[i] = chars[i + 8];
		divider_intersect = chars[12];
	}

	string BoxBrush::DrawSide(bool top, int numCells, int cellWidth) const {
		string result = "";

		if (top)
			result += corner[0];
		else
			result += corner[3];

		for (int i = 0; i < numCells - 1; i++) {
			result += string(cellWidth, side[1]);

			if (top)
				result += divider_side_border[0];
			else
				result += divider_side_border[2];
		}

		result += string(cellWidth, side[1]);

		if (top)
			result += corner[1];
		else
			result += corner[2];

		return result;
	}

	string BoxBrush::DrawDataLine(string* data, int dataCount, int cellWidth) const {
		string result = "";
		result += side[0];
		for (int i = 0; i < dataCount; i++) {
			string item = data[i];
			int bufferSize = (cellWidth - item.length()) / 2;
			int extraBuffer = (cellWidth - item.length()) % 2;
			result += string(bufferSize, ' ') + item + string(bufferSize + extraBuffer, ' ') + side[0];
		}
		return result;
	}

	string BoxBrush::DrawDataLine(char* data, int dataCount, int cellWidth) const {
		string result = "";
		result += side[0];
		for (int i = 0; i < dataCount; i++) {
			string item = string(1, data[i]);
			int bufferSize = (cellWidth - item.length()) / 2;
			int extraBuffer = (cellWidth - item.length()) % 2;
			result += string(bufferSize, ' ') + item + string(bufferSize + extraBuffer, ' ') + side[0];
		}
		return result;
	}

	string BoxBrush::DrawDividingLine(int numCells, int cellWidth) const {
		string result = "";
		result += divider_side_border[3];
		for (int i = 0; i < numCells - 1; i++) {
			result += string(cellWidth, divider[1]) + divider_intersect;
		}
		result += string(cellWidth, divider[1]) + divider_side_border[1];

		return result;
	}

	string BoxBrush::MakeHeader(string* lines, int numLines) const {
		string result;
		int width = AutoWidth(lines, numLines);
		result += DrawSide(true, 1, width) + "\n";
		for (int i = 0; i < numLines; i++) {
			string line[] = { lines[i] };
			result += DrawDataLine(line, 1, width) + "\n";
		}
		result += DrawSide(false, 1, width) + "\n";

		return result;
	}

	int BoxBrush::AutoWidth(string* data, int numData, int minBorder) const {
		int result = 0;
		for (int i = 0; i < numData; i++) {
			if ((int) data[i].length() > result)
				result = data[i].length();
		}
		return result + (2 * minBorder);
	}
#pragma endregion

#pragma region Table
	Table::Table(int columns, int rows, int columnWidth, BoxBrush brush) : columns(columns), rows(rows), 
		columnWidth(columnWidth), brush(brush) {
			headers = new string[columns];
			data = new string*[rows];
			for (int i = 0; i < rows; i++) {
				data[i] = new string[columns];
			}
	}

	Table::~Table() {
		delete[] headers;
		delete[] data;
	}

	void Table::WriteTable() {
		ConsoleIO::WriteLine(brush.DrawSide(true, columns, columnWidth));
		ConsoleIO::WriteLine(brush.DrawDataLine(headers, columns, columnWidth));
		ConsoleIO::WriteLine(brush.DrawDividingLine(columns, columnWidth));
		for (int i = 0; i < rows; i++) {
			ConsoleIO::WriteLine(brush.DrawDataLine(data[i], columns, columnWidth));
		}
		ConsoleIO::WriteLine(brush.DrawSide(false, columns, columnWidth));
	}
#pragma endregion
}