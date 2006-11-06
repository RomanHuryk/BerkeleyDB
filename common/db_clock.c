/*-
 * See the file LICENSE for redistribution information.
 *
 * Copyright (c) 2005,2006 Oracle.  All rights reserved.
 *
 * $Id: db_clock.c,v 1.6 2006/11/01 00:52:21 bostic Exp $
 */

#include "db_config.h"

#include "db_int.h"

/*
 * __db_difftime --
 *
 * Compute the difference in seconds and microseconds of two timers.
 *
 * PUBLIC: void __db_difftime __P((u_int32_t, u_int32_t, u_int32_t, u_int32_t,
 * PUBLIC:    u_int32_t *, u_int32_t *));
 */
void
__db_difftime(ssec, esec, susec, eusec, secp, usecp)
	u_int32_t ssec, esec, susec, eusec, *secp, *usecp;
{
	if ((*secp = esec - ssec) != 0 && eusec < susec) {
		(*secp)--;
		eusec += 1000000;
	}
	*usecp = eusec - susec;
}
