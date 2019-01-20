module PGM
  module Bindings
    # Base For bindings.
    #
    # When extended, this module sets up FFI to use my PGM C library.
    module Base
      def self.extended(base)
        lib_path = File.expand_path(__dir__ + '/../../../ext/src/lib')
        base.extend FFI::Library
        base.include Structs
        base.ffi_lib "#{lib_path}/pgm.so"
        base.typedef :pointer, :pgm
      end
    end
  end
end
