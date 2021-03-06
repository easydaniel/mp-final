/**
 ******************************************************************************
  * @file            : USB_HOST
  * @version         : v1.0_Cube
  * @brief           :  This file implements the USB Host 
  ******************************************************************************
  *
  * Copyright (c) 2017 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/

#include "usb_host.h"
#include "usbh_core.h"
#include "usbh_hid.h"
#include "global_var.h"

/* USB Host Core handle declaration */
USBH_HandleTypeDef hUsbHostFS;
ApplicationTypeDef Appli_state = APPLICATION_IDLE;

/**
* -- Insert your variables declaration here --
*/ 
/* USER CODE BEGIN 0 */
void USBH_HID_EventCallback(USBH_HandleTypeDef *phost) {
	Increase();
	HID_KEYBD_Info_TypeDef* kb_info;
	if (phost->pActiveClass->BgndProcess(phost) == USBH_OK) {
		if (kb_info = USBH_HID_GetKeybdInfo(phost)) {
			HID_KEYBRD_Handler(kb_info);
			return;
		}
	}
}
/* USER CODE END 0 */

/*
* user callbak declaration
*/ 
static void USBH_UserProcess  (USBH_HandleTypeDef *phost, uint8_t id);

/**
* -- Insert your external function declaration here --
*/ 
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/* init function */				        
void MX_USB_HOST_Init(void)
{
  /* Init Host Library,Add Supported Class and Start the library*/
  USBH_Init(&hUsbHostFS, USBH_UserProcess, HOST_FS);

  USBH_RegisterClass(&hUsbHostFS, USBH_HID_CLASS);

  USBH_Start(&hUsbHostFS);
}

/*
 * Background task
*/ 
void MX_USB_HOST_Process()
{
  /* USB Host Background task */
    USBH_Process(&hUsbHostFS);
	if (hUsbHostFS.device.is_connected) {
		if (hUsbHostFS.gState == HOST_CLASS) {
			if (status == 1) {
				Set_Color(0, 256, 0);
				stamina_red = 0;
				stamina_green = 256;
				status = 2;
			}
		} else {
			if (status == 0) {
				Set_Color(192, 168, 53);
				status = 1;
			}
		}
	} else {
		status = 0;
		Breath();
	}
	return;
}
/*
 * user callbak definition
*/ 
static void USBH_UserProcess  (USBH_HandleTypeDef *phost, uint8_t id)
{

  /* USER CODE BEGIN 2 */
  switch(id)
  { 
  case HOST_USER_SELECT_CONFIGURATION:
  break;
    
  case HOST_USER_DISCONNECTION:
  Appli_state = APPLICATION_DISCONNECT;
  break;
    
  case HOST_USER_CLASS_ACTIVE:
  Appli_state = APPLICATION_READY;
  break;

  case HOST_USER_CONNECTION:
  Appli_state = APPLICATION_START;
  break;

  default:
  break; 
  }
  /* USER CODE END 2 */
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
