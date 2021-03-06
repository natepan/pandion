/**
 * This file is part of Pandion.
 *
 * Pandion is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Pandion is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Pandion.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Filename:    UTF.h
 * Author(s):   Dries Staelens
 * Copyright:   Copyright (c) 2010 Dries Staelens
 * Description: This file declares several functions that convert UTF-8,
 *              UTF-16 and UTF-32 strings into each other.
 */

#pragma once

/**
 * Ignore MSVC++ compiler whining about exceptions.
 */
#pragma warning(disable : 4290)

/**
 * Define types for UTF strings.
 */
typedef std::string UTF8String;
typedef std::wstring UTF16String;
typedef std::basic_string<unsigned> UTF32String;

/**
 * Codepoint used to represent invalid characters.
 */
const unsigned INVALID_CODEPOINT = 0xFFFD;

/**
 * Surrogate borders for UTF-16 strings.
 */
const wchar_t HI_SURROGATE_START = 0xD800;
const wchar_t HI_SURROGATE_END = 0xDBFF;
const wchar_t LO_SURROGATE_START = 0xDC00;
const wchar_t LO_SURROGATE_END = 0xDFFF;

/**
 * Class grouping static methods for converting between UTF types.
 */
class UTF
{
public:
	static UTF16String utf8to16( const UTF8String  fromString);
	static UTF8String  utf16to8( const UTF16String fromString);
	static UTF32String utf8to32( const UTF8String  fromString);
	static UTF8String  utf32to8( const UTF32String fromString);
	static UTF32String utf16to32(const UTF16String fromString);
	static UTF16String utf32to16(const UTF32String fromString);

	static unsigned getNextUTF8Codepoint(
		UTF8String::const_iterator& begin,
		UTF8String::const_iterator& end);
	static unsigned getNextUTF16Codepoint(
		UTF16String::const_iterator& begin,
		UTF16String::const_iterator& end);
	static unsigned getNextUTF32Codepoint(
		UTF32String::const_iterator& begin,
		UTF32String::const_iterator& end);

	static void appendCodepointToUTF8String(
		UTF8String& toString, unsigned codepoint);
	static void appendCodepointToUTF16String(
		UTF16String& toString, unsigned codepoint);
	static void appendCodepointToUTF32String(
		UTF32String& toString, unsigned codepoint);

	static bool isValidCodepoint(unsigned codepoint);
};