require_relative './bindings/base'
module PGM
  # PGM Library Functions
  module Functions
    extend PGM::Bindings::Base

    attach_function :load_pgm, :loadPgm, %i[pgm string], :void
    attach_function :save_pgm, :savePgm, %i[pgm string], :void
    attach_function :invert_colors, :invertColors, %i[pgm pgm], :void
  end
end
