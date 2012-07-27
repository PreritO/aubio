#! /usr/bin/python

import sys
from aubio import source, sink, pvoc, tss

if __name__ == '__main__':
  if len(sys.argv) < 2:
    print 'usage: %s <inputfile> <outputfile_transient> <outputfile_steady>' % sys.argv[0]
    sys.exit(1)

  samplerate = 44100
  win_s = 512                 # fft size
  hop_s = win_s / 2           # block size
  threshold = 0.26

  f = source(sys.argv[1], samplerate, hop_s)
  g = sink(sys.argv[2], samplerate)
  h = sink(sys.argv[3], samplerate)

  pv = pvoc(win_s, hop_s)     # phase vocoder
  pw = pvoc(win_s, hop_s)     # another phase vocoder
  t = tss(win_s, hop_s)       # transient steady state separation

  t.set_threshold(threshold)

  read = hop_s

  while read:
    samples, read = f()               # read file
    spec = pv(samples)                # compute spectrum
    trans_spec, stead_spec = t(spec)  # transient steady-state separation
    transients = pv.rdo(trans_spec)   # overlap-add synthesis of transients
    steadstate = pw.rdo(stead_spec)   # overlap-add synthesis of steady states
    g(transients, read)               # write transients to output
    h(steadstate, read)               # write steady states to output
