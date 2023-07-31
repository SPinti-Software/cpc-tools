/*
 * Copyright (C) 2023 d0p1
 *
 * This file is part of CpcTools.
 *
 * CpcTools are free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CpcTools are distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CpcTools.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CPCTOOLS_CHECK_LEXER_HPP
# define CPCTOOLS_CHECK_LEXER_HPP 1

# include <fstream>
# include <iostream>

struct Token
{
  std::size_t length;
  std::size_t line;
  std::size_t col;

  std::string value;
};

class Lexer
{
public:
  Lexer(const std::ifstream &buff) : buffer(buff) {}
  Token token();
  ~Lexer() {}

private:
  const std::ifstream &buffer;
};

#endif /* !CPCTOOLS_CHECK_LEXER_HPP */
