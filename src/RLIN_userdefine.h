/*===========================================================================*/
/* Module :  RLIN_userdefine.h                                               */
/* Version:  V1.00                                                           */
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
/*                                                                           */
/*===========================================================================*/

/***********************************************************************************************************************
* File Name    : RLIN_userdefine.h
* Device(s)    : R5F10PPJ
* Tool-Chain   : IAR Systems iccrl78
* Description  : This file includes user definition.
* Creation Date: 02.08.2013
***********************************************************************************************************************/

#ifndef _USER_DEF_H
#define _USER_DEF_H

/***********************************************************************************************************************
User definitions
***********************************************************************************************************************/

//#define RLIN_Slave

#define  LED1   P6_bit.no6
#define  LED2   P6_bit.no7
#define  ON   0
#define  OFF  1


#define RLIN_Enable   P5_bit.no3

#define TRUE   1
#define FALSE  0

#define DateBuffer_1     0x06D8
#define DateBuffer_2     0x06D9
#define DateBuffer_3     0x06DA
#define DateBuffer_4     0x06DB
#define DateBuffer_5     0x06DC
#define DateBuffer_6     0x06DD
#define DateBuffer_7     0x06DE
#define DateBuffer_8     0x06DF

#endif
