/*
 * kpd_interface.h
 *
 *  Created on: Sep 23, 2023
 *      Author: hp
 */

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

#define NO_PRESSED_KEY         255

u8 kpd_get(void);
void kpd_init(void);

#endif /* KPD_INTERFACE_H_ */
