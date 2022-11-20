/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "pin_mux.h"

#include <cstdio>
/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
 int currPos = 0;
 int currRow = 12;
 #define ngetc(c) (read (0, (c), 1))

void delay (void)
{
    for (int i = 0; i < 800000; i++){}
}

void addLine (bool drawChar)
{
    for (int i = 0; i < 80; i++)
    {
        if (i == currPos && drawChar)
        {
            printf("O");
        }
        else
        {
            printf(" ");
        }
    }
    printf("\r\n");
 }

 void updateScreen (void)
 {
     for (int i = 0; i < 24; i++)
     {
         if (i == currRow)
         {
            addLine(true); 
         }
         else
         {
            addLine(false);
         }
     }
 }

/*!
 * @brief Main function
 */
int main(void)
{
    char ch;

    /* Init board hardware. */
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    printf("Use 80 x 24 Terminal settings \r\n");
    ch = getchar();
    updateScreen();

    while (1)
    {
        // Non nonblocking (for now...)
        ch = getchar();
        if (ch == 'd')
        {
            currPos++;
        }
        else if (ch == 'a')
        {
            currPos--;
        }
        else if (ch == 'w')
        {
            currRow--;
        }
        else if (ch == 's')
        {
            currRow++;
        }
        delay();
        updateScreen();
        if (currPos == 80)
        {
            currPos = 0;
        }
    }
}