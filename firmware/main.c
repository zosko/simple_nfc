/*****************************************************************************
Written and Copyright (C) by Nicolas Kruse

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*****************************************************************************/

#include <avr/io.h>
#include "nfcemulator.h"
							                                                                   
uint8_t tagStorage[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE1, 0x10, 0x80, 0x00, //Byte  0 to 15:
                        0x03, 0xFF, 0x00, 0xB4, 0xC2, 0x09, 0x00, 0x00, 0x00, 0xA5, 0x74, 0x65, 0x78, 0x74, 0x2F, 0x68, //Byte 16 to 31:
                        0x74, 0x6D, 0x6C, 0xEF, 0xBB, 0xBF, 0x3C, 0x68, 0x74, 0x6D, 0x6C, 0x3E, 0x3C, 0x62, 0x6F, 0x64, //...
                        0x79, 0x20, 0x73, 0x74, 0x79, 0x6C, 0x65, 0x3D, 0x22, 0x62, 0x61, 0x63, 0x6B, 0x67, 0x72, 0x6F, 
                        0x75, 0x6E, 0x64, 0x2D, 0x63, 0x6F, 0x6C, 0x6F, 0x72, 0x3A, 0x62, 0x6C, 0x61, 0x63, 0x6B, 0x3B, 
                        0x63, 0x6F, 0x6C, 0x6F, 0x72, 0x3A, 0x77, 0x68, 0x69, 0x74, 0x65, 0x3B, 0x66, 0x6F, 0x6E, 0x74, 
                        0x3A, 0x41, 0x72, 0x69, 0x61, 0x6C, 0x3B, 0x22, 0x3E, 0x3C, 0x68, 0x31, 0x3E, 0x53, 0x69, 0x6D, 
                        0x70, 0x6C, 0x65, 0x20, 0x4E, 0x46, 0x43, 0x3C, 0x2F, 0x68, 0x31, 0x3E, 0x3C, 0x70, 0x3E, 0x46, 
                        0x72, 0x6F, 0x6D, 0x20, 0x3C, 0x61, 0x20, 0x68, 0x72, 0x65, 0x66, 0x3D, 0x22, 0x68, 0x74, 0x74, 
                        0x70, 0x3A, 0x2F, 0x2F, 0x79, 0x6F, 0x68, 0x72, 0x62, 0x6C, 0x6F, 0x67, 0x2E, 0x62, 0x6C, 0x6F, 
                        0x67, 0x73, 0x70, 0x6F, 0x74, 0x2E, 0x64, 0x65, 0x22, 0x3E, 0x79, 0x6F, 0x68, 0x72, 0x62, 0x6C, 
                        0x6F, 0x67, 0x3C, 0x2F, 0x61, 0x3E, 0x3C, 0x2F, 0x70, 0x3E, 0x3C, 0x2F, 0x62, 0x6F, 0x64, 0x79, 
                        0x3E, 0x3C, 0x2F, 0x68, 0x74, 0x6D, 0x6C, 0x3E, 0xFE}; // 201 size
						
//Byte 14 (value=0x80=1024/8) specifies tag size in bytes divided by 8
//Byte 18, 19 specify NDEF-Message size, Byte 20..35 is NDEF-header, content starts at Byte 36
								
int main(void)
{
	setupNfcEmulator(tagStorage, sizeof(tagStorage));
		  	
	while(1)
	{
		//do other stuff
			
		checkForNfcReader();
	}
}