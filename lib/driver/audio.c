/*
    $Id: audio.c,v 1.1 2005/03/01 00:49:24 rocky Exp $

    Copyright (C) 2005 Rocky Bernstein <rocky@panix.com>

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
/*! Audio (via line output) related routines. */


#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <cdio/cdio.h>
#include <cdio/audio.h>
#include "cdio_private.h"

/*!
  Get volume of an audio CD.
  
  @param p_cdio the CD object to be acted upon.
  
*/
driver_return_code_t 
cdio_audio_get_volume (CdIo_t *p_cdio,  /*out*/ cdio_audio_volume_t *p_volume)
{
  if (!p_cdio) return DRIVER_OP_UNINIT;

  if (!p_cdio->op.audio_get_volume) {
    return p_cdio->op.audio_get_volume (p_cdio->env, p_volume);
  } else {
    return DRIVER_OP_UNSUPPORTED;
  }
}
/*!
  Playing CD through analog output
  
  @param p_cdio the CD object to be acted upon.
*/
driver_return_code_t 
cdio_audio_pause (CdIo_t *p_cdio) 
{
  if (!p_cdio) return DRIVER_OP_UNINIT;

  if (!p_cdio->op.audio_pause) {
    return p_cdio->op.audio_pause (p_cdio->env);
  } else {
    return DRIVER_OP_UNSUPPORTED;
  }
}

/*!
  Playing CD through analog output at the given MSF.
  
  @param p_cdio the CD object to be acted upon.
*/
driver_return_code_t 
cdio_audio_play_msf (CdIo_t *p_cdio, msf_t *p_msf)
{
  if (!p_cdio) return DRIVER_OP_UNINIT;

  if (!p_cdio->op.audio_play_msf) {
    return p_cdio->op.audio_play_msf (p_cdio->env, p_msf);
  } else {
    return DRIVER_OP_UNSUPPORTED;
  }
}

/*!
  Playing CD through analog output
  
  @param p_cdio the CD object to be acted upon.
*/
driver_return_code_t 
cdio_audio_play_track_index (CdIo_t *p_cdio, cdio_track_index_t *p_track_index)
{
  if (!p_cdio) return DRIVER_OP_UNINIT;

  if (!p_cdio->op.audio_play_track_index) {
    return p_cdio->op.audio_play_track_index (p_cdio->env, p_track_index);
  } else {
    return DRIVER_OP_UNSUPPORTED;
  }
}

/*!
  Get subchannel information.
  
  @param p_cdio the CD object to be acted upon.
*/
driver_return_code_t 
cdio_audio_read_subchannel (CdIo_t *p_cdio, cdio_subchannel_t *p_subchannel)
{
  if (!p_cdio) return DRIVER_OP_UNINIT;

  if (!p_cdio->op.audio_read_subchannel) {
    return p_cdio->op.audio_read_subchannel(p_cdio->env, p_subchannel);
  } else {
    return DRIVER_OP_UNSUPPORTED;
  }
}

/*!
  Resume playing an audio CD.
  
  @param p_cdio the CD object to be acted upon.
  
*/
driver_return_code_t 
cdio_audio_resume (CdIo_t *p_cdio)
{
  if (!p_cdio) return DRIVER_OP_UNINIT;

  if (!p_cdio->op.audio_resume) {
    return p_cdio->op.audio_resume(p_cdio->env);
  } else {
    return DRIVER_OP_UNSUPPORTED;
  }
}

/*!
  Set volume of an audio CD.
  
  @param p_cdio the CD object to be acted upon.
  
*/
driver_return_code_t 
cdio_audio_set_volume (CdIo_t *p_cdio,  const cdio_audio_volume_t *p_volume)
{
  if (!p_cdio) return DRIVER_OP_UNINIT;

  if (!p_cdio->op.audio_set_volume) {
    return p_cdio->op.audio_set_volume(p_cdio->env, p_volume);
  } else {
    return DRIVER_OP_UNSUPPORTED;
  }
}