/*
  $Id: paranoia.h,v 1.1 2004/12/18 17:29:32 rocky Exp $

  Copyright (C) 2004 Rocky Bernstein <rocky@panix.com>
  Copyright (C) 1998 Monty xiphmont@mit.edu
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/** \file cdda_paranoia.h 
 *  \brief  The top-level header for libcdda_paranoia: 
    a library for reading CD-DA with error tolerance and repair.
 */

#ifndef _CDIO_PARANOIA_H_
#define _CDIO_PARANOIA_H_

#include <cdio/cdio.h>

#define CD_FRAMEWORDS (CDIO_CD_FRAMESIZE_RAW/2)

/**! Flags used in paranoia_modeset. */

#define PARANOIA_MODE_FULL        0xff
#define PARANOIA_MODE_DISABLE     0

#define PARANOIA_MODE_VERIFY      1
#define PARANOIA_MODE_FRAGMENT    2
#define PARANOIA_MODE_OVERLAP     4
#define PARANOIA_MODE_SCRATCH     8
#define PARANOIA_MODE_REPAIR      16
#define PARANOIA_MODE_NEVERSKIP   32

/** cdrom_paranoia is an opaque structure which is used in all of the
    library operations.
 */
typedef struct cdrom_paranoia_s cdrom_paranoia_t;
typedef struct cdrom_drive_s   cdrom_drive_t;

typedef enum  {
  PARANOIA_CB_READ,
  PARANOIA_CB_VERIFY,
  PARANOIA_CB_FIXUP_EDGE,
  PARANOIA_CB_FIXUP_ATOM,
  PARANOIA_CB_SCRATCH,
  PARANOIA_CB_REPAIR,
  PARANOIA_CB_SKIP,
  PARANOIA_CB_DRIFT,
  PARANOIA_CB_BACKOFF,
  PARANOIA_CB_OVERLAP,
  PARANOIA_CB_FIXUP_DROPPED,
  PARANOIA_CB_FIXUP_DUPED,
  PARANOIA_CB_READERR
} paranoia_cb_mode_t;
  
#ifdef __cplusplus
extern "C" {
#endif

  /*! 
    Get and initialize a new cdrom_paranoia object from cdrom_drive.
    Run this before calling any of the other paranoia routines below.

    @return new cdrom_paranoia object Call paranoia_free() when you are
    done with it
   */
extern cdrom_paranoia_t *paranoia_init(cdrom_drive_t *d);

  /*!
    Free any resources associated with obj.

    @see paranoia_init.
   */
extern void paranoia_free(cdrom_paranoia_t *p);

  /*! 
    Set the kind of repair you want to on for reading. 
    The modes are listed above
   */
extern void paranoia_modeset(cdrom_paranoia_t *p, int mode);

  /*!
    reposition reading offset. 

    @param whence  like corresponding parameter in libc's lseek, e.g. 
                   SEEK_SET or SEEK_END.
  */
extern lsn_t paranoia_seek(cdrom_paranoia_t *p, off_t seek, int whence);

  /*! The returned buffer is *not* to be freed by the caller.  It will
    persist only until the next call to paranoia_read() for this p 
  */
extern int16_t *paranoia_read(cdrom_paranoia_t *p,
			      void(*callback)(long int, paranoia_cb_mode_t));

extern int16_t *paranoia_read_limited(cdrom_paranoia_t *p,
				      void(*callback)(long int, 
						      paranoia_cb_mode_t),
				      int maxretries);


extern void paranoia_overlapset(cdrom_paranoia_t *p,long overlap);

extern void paranoia_set_range(cdrom_paranoia_t *p, long int start, 
			       long int end);

#ifdef __cplusplus
}
#endif

#endif /*_CDIO_PARANOIA_H_*/