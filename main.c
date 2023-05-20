/* SPDX-License-Identifier: GPL-3.0-only
 * VibrateMii, Wii homebrew that turns the Wiimote into a vibrator. Prototype 1.
 * Copyright (C) 2023, Edith Claire DeHoyos EMAIL: edithdehoyos2003@gmail.com
 *
 * main.c 

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <gccore.h>
#include <wiiuse/wpad.h>

static void *FB = NULL;
static GXRModeObj *rmode = NULL;

int i = 0;

int main(int argc, char **argv) {

	// Initialize Video and Controllers
	VIDEO_Init();
	WPAD_Init();

	rmode = VIDEO_GetPreferredMode(NULL);

	FB = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));

	// Initialize the Console
	console_init(FB,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);
	VIDEO_Configure(rmode);
	VIDEO_SetNextFramebuffer(FB);
	
	// Make the display visible 
	VIDEO_SetBlack(FALSE);

	// Flush the video registers
	VIDEO_Flush();

	// Wait for Vsync
	VIDEO_WaitVSync();
	if(rmode->viTVMode&VI_NON_INTERLACE) VIDEO_WaitVSync();

	// Position the cursor at row 2, Column 0
	printf("\x1b[2;0H");

	// Print the copyright statement
	printf("Copyright (C) 2023, Edith Claire Dehoyos\n");
	
	printf("VibrateMii, Prototype 1\n");

	printf("Press A to begin vibrating\n");
loop:
	while(i == 0) {
		
		WPAD_ScanPads();
		u32 pressedButtons = WPAD_ButtonsDown(0);

		if ( pressedButtons & WPAD_BUTTON_A ) i++;

		if ( pressedButtons & WPAD_BUTTON_HOME ) exit(0);

		VIDEO_WaitVSync();

	}

	WPAD_Rumble(0,1);
	printf("Vibration enabled! Hit B to stop!\n");
	i--;

	while(i == 0) {
	
		WPAD_ScanPads();
		u32 pressedButtons = WPAD_ButtonsDown(0);

		if ( pressedButtons & WPAD_BUTTON_B ) i++;

		if ( pressedButtons & WPAD_BUTTON_HOME ) exit(0);

		VIDEO_WaitVSync();
	}

	WPAD_Rumble(0,0);
	printf("Vibration disabled! Hit A to restart! Hit HOME to exit!\n");
	i--;
	goto loop;
	
	
	return 0;
}

