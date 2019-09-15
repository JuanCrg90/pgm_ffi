Gem::Specification.new do |spec|
  spec.name = "pgm"
  spec.summary = "pgm color inverted ffi bindings"
  spec.version = "0.0.1"
  spec.authors = ["Juan C. Ruiz"]

  spec.required_ruby_version = "> 2.3"
  spec.files = `git ls-files`.split("\n")

  spec.add_runtime_dependency "ffi", "~> 1.11"

  spec.add_development_dependency 'bundler', '~> 2.0'
  spec.add_development_dependency 'rake', '~> 10.0'
end
