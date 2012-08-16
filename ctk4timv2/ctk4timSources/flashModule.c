/**
 *  @file flashModule.c
 *  @brief Module that allows Flash Writes
 *  @version 01/03/2012
 *  @version 1.0.0
 *
 *  C Toolkit For MSP430 Texas Instrument Microcontroller
 *  Copyright (C) 2012  Leandro Perez Guatibonza
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../ctk4timIncludes/flashModule.h"

/**
 * @brief Flash Erase
 */
void flashErase()
{

}

/**
 * @brief Flash Write
 */
void flashWrite()
{
	uchar *ptrSegment = 0;

	// Select Clock SMCLK/3 --> 333KHz Approximately
	FCTL2 = FWKEY | FSSEL1 | FN1 | FN0;

	// Clear LOCK Bit
	FCTL3 = FWKEY;

	// Enable Segment Erase
	FCTL1 = FWKEY | ERASE;

	// Write Dummy Byte Start Segment Erase
	//ptrSegment = &0xFC10;
	//*ptrSegment = 0x00;

	// Set LOCK Bit
	FCTL3 = FWKEY | LOCK;
}
