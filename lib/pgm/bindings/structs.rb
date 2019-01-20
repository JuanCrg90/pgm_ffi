module PGM
  # FFI Strucs.
  #
  # These match the structs defined in PGM's header file and are required
  # to correctly interact with the library's function
  module Bindings
    module Structs
      extend FFI::Library

      class Pgm < FFI::Struct
        layout :magic_number, :string,
               :width, :int,
               :height, :int,
               :max_val, :int,
               :image, :pointer
      end
    end
  end
end
