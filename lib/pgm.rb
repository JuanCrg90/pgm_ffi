require 'ffi'

require_relative './pgm/bindings'
require_relative './pgm/functions'

module PGM
  extend Functions
end
