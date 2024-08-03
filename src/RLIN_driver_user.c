/*===========================================================================*/
/* Module :  RLIN_driver_user.c                                              */
/* Version:  V1.01                                                           */
/*===========================================================================*/
/*                                  COPYRIGHT                                */
/*===========================================================================*/
/* Copyright (c) 2012 by Renesas Electronics Europe GmbH,                    */
/*               a company of the Renesas Electronics Corporation            */
/*===========================================================================*/
/* Purpose: main routine of QB-R5F10PMF-TB startup sample                    */
/*                                                                           */
/*===========================================================================*/
/* In case of any question please do not hesitate to contact:                */
/*                                                                           */
/*        Technical Product Support                                          */
/*                                                                           */
/*        Renesas Electronics Europe GmbH                                    */
/*        Arcadiastrasse 10                                                  */
/*        D-40472 Duesseldorf, Germany                                       */
/*                                                                           */
/*        e-mail: device_support.rl78-eu@lm.renesas.com                      */
/*        FAX:   +49 - (0)211 / 65 03 - 12 79                                */
/*                                                                           */
/*===========================================================================*/
/* Warranty Disclaimer                                                       */
/*                                                                           */
/* Because the Product(s) is licensed free of charge, there is no warranty   */
/* of any kind whatsoever and expressly disclaimed and excluded by Renesas,  */
/* either expressed or implied, including but not limited to those for       */
/* non-infringement of intellectual property, merchantability and/or         */
/* fitness for the particular purpose.                                       */
/* Renesas shall not have any obligation to maintain, service or provide bug */
/* fixes for the supplied Product(s) and/or the Application.                 */
/*                                                                           */
/* Each User is solely responsible for determining the appropriateness of    */
/* using the Product(s) and assumes all risks associated with its exercise   */
/* of rights under this Agreement, including, but not limited to the risks   */
/* and costs of program errors, compliance with applicable laws, damage to   */
/* or loss of data, programs or equipment, and unavailability or             */
/* interruption of operations.                                               */
/*                                                                           */
/* Limitation of Liability                                                   */
/*                                                                           */
/* In no event shall Renesas be liable to the User for any incidental,       */
/* consequential, indirect, or punitive damage (including but not limited    */
/* to lost profits) regardless of whether such liability is based on breach  */
/* of contract, tort, strict liability, breach of warranties, failure of     */
/* essential purpose or otherwise and even if advised of the possibility of  */
/* such damages. Renesas shall not be liable for any services or products    */
/* provided by third party vendors, developers or consultants identified or  */
/* referred to the User by Renesas in connection with the Product(s) and/or  */
/* the Application.                                                          */
/*                                                                           */
/*===========================================================================*/
/* Environment:                                                              */
/*              Device:          R5F10PPJ                                    */
/*              Target Hardware: QB-R5F10PPJ-TB                              */
/*              IDE:             IAR Systems                                 */
/*                               Embedded Workbench for RL78 V1.30.x         */
/*                                                                           */
/*===========================================================================*/
/* History:                                                                  */
/*              V1.00: Initial version                                       */
/*              V1.01: 1st revision, control of LIE0 changed                                                             */
/*===========================================================================*/

/***********************************************************************************************************************
 * File Name    : RLIN_driver_user.c
 * Device(s)    : R5F10PPJ
 * Tool-Chain   : IAR Systems iccrl78
 * Description  : This file implements device driver for Interrupt module.
 * Creation Date: 02.08.2013
 ***********************************************************************************************************************/

#include "RLIN_macrodriver.h"
#include "RLIN_driver.h"
#include "RLIN_userdefine.h"
#include "LIN.h"

uint8_t GetIDbuffer;

/***********************************************************************************************************************
 * Function Name: RLIN0_Transmission_interrupt
 * Description  : This function is RLIN0 Transmission interrupt service routine.
 * Arguments    : None
 * Return Value : None
 ***********************************************************************************************************************/
#pragma vector = INTLIN0TRM_vect
__interrupt static void RLIN0_Transmission_interrupt(void)
{

    LST0 &= 0xFE;
}

/***********************************************************************************************************************
 * Function Name: RLIN0_Reception_interrupt
 * Description  : This function is RLIN0 Reception interrupt service routine.
 * Arguments    : None
 * Return Value : None
 ***********************************************************************************************************************/
#pragma vector = INTLIN0RVC_vect
__interrupt static void RLIN0_Reception_interrupt(void)
{

    uint8_t receive_header_flag;
    uint8_t receive_response_flag;
    receive_header_flag = LST0 & 0x80;   /* get header reception flag */
    receive_response_flag = LST0 & 0X02; /* get response rception flag*/

    GetIDbuffer = LIDB0;
    void Slave_ID_Switch(GetIDbuffer, receive_header_flag, receive_response_flag)
}

/***********************************************************************************************************************
 * Function Name: RLIN0_Status_interrupt
 * Description  : This function is RLIN0 Status interrupt service routine.
 * Arguments    : None
 * Return Value : None
 ***********************************************************************************************************************/
#pragma vector = INTLIN0_vect
__interrupt static void RLIN0_Status_interrupt(void)
{
    //   uint8_t error_type

    //   error_type = Get_ErrorType();
    //   switch (err0r_type)
    //   {
    //     case 0:
    //   }
    while (1U)
    {
        ;
    }
}

/***********************************************************************************************************************
 * Function Name: RLIN0_Wakeup_interrupt
 * Description  : This function is RLIN0 Wakeup interrupt service routine.
 * Arguments    : None
 * Return Value : None
 ***********************************************************************************************************************/
#pragma vector = INTLIN0WUP_vect
__interrupt static void RLIN0_Wakeup_interrupt(void)
{
    LCUC0 = 0x03;
    LED1 = ON;
    LED2 = ON;
}
