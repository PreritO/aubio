/*
  Copyright (C) 2003-2009 Paul Brossier <piem@aubio.org>

  This file is part of aubio.

  aubio is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  aubio is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with aubio.  If not, see <http://www.gnu.org/licenses/>.

*/

/** \file 
  
  Pitch detection using the YIN algorithm
 
  This algorithm was developped by A. de Cheveigne and H. Kawahara and
  published in:
  
  De Cheveigné, A., Kawahara, H. (2002) "YIN, a fundamental frequency
  estimator for speech and music", J. Acoust. Soc. Am. 111, 1917-1930.  
 
  see http://recherche.ircam.fr/equipes/pcm/pub/people/cheveign.html

*/

#ifndef PITCHYIN_H
#define PITCHYIN_H

#ifdef __cplusplus
extern "C" {
#endif

/** pitch detection object */
typedef struct _aubio_pitchyin_t aubio_pitchyin_t;

/** creation of the pitch detection object
 
  \param bufsize size of the input buffer to analyse 
 
*/
aubio_pitchyin_t *new_aubio_pitchyin (uint_t bufsize);

/** deletion of the pitch detection object
 
  \param p pitch detection object as returned by new_aubio_pitchyin()
 
*/
void del_aubio_pitchyin (aubio_pitchyin_t * o);

/** execute pitch detection on an input buffer 
 
  \param p pitch detection object as returned by new_aubio_pitchyin()
  \param input input signal window (length as specified at creation time) 
  \param tol tolerance parameter for minima selection [default 0.85] 
 
*/
void aubio_pitchyin_do (aubio_pitchyin_t * o, fvec_t * in, fvec_t * out);


/** set tolerance parameter for YIN algorithm 
  
  \param o YIN pitch detection object 
  \param tol tolerance parameter for minima selection [default 0.15]

*/
uint_t aubio_pitchyin_set_tolerance (aubio_pitchyin_t * o, smpl_t tol);

/** get tolerance parameter for YIN algorithm 
  
  \param o YIN pitch detection object 
  \return tolerance parameter for minima selection [default 0.15]

*/
smpl_t aubio_pitchyin_get_tolerance (aubio_pitchyin_t * o);

#ifdef __cplusplus
}
#endif

#endif /*PITCHYIN_H*/ 
