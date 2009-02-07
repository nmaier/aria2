/* <!-- copyright */
/*
 * aria2 - The high speed download utility
 *
 * Copyright (C) 2009 Tatsuhiro Tsujikawa
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */
/* copyright --> */
#include "LongestSequencePieceSelector.h"
#include "a2algo.h"

namespace aria2 {

bool LongestSequencePieceSelector::select
(size_t& index,
 const std::deque<size_t>& candidateIndexes) const
{
  std::pair<std::deque<size_t>::const_iterator, size_t> p = 
    max_sequence(candidateIndexes.begin(), candidateIndexes.end());
  if(p.second == 0) {
    return false;
  } else {
    index = *(p.first)+p.second-1;
    return true;
  }
}

void LongestSequencePieceSelector::addPieceStats
(const unsigned char* bitfield, size_t bitfieldLength) {}

void LongestSequencePieceSelector::subtractPieceStats
(const unsigned char* bitfield, size_t bitfieldLength) {}

void LongestSequencePieceSelector::updatePieceStats
(const unsigned char* newBitfield, size_t newBitfieldLength,
 const unsigned char* oldBitfield) {}

void LongestSequencePieceSelector::addPieceStats(size_t index) {}

} // namespace aria2