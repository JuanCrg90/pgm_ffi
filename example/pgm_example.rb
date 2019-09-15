require 'pgm'

pgm = PGM::Bindings::Structs::Pgm.new

PGM::Functions.load_pgm(pgm, './Feep.pgm')

pgm_out = PGM::Bindings::Structs::Pgm.new

PGM::Functions.invert_colors(pgm, pgm_out)

PGM::Functions.save_pgm(pgm_out, './feep_out.pgm')
