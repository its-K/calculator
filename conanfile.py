from conans import ConanFile, CMake

class PocoTimerConan(ConanFile):
   settings = "os", "compiler", "build_type", "arch"
   requires = "rapidjson/1.1.0","fmt/8.0.1","date/3.0.1"
   generators = "cmake", "gcc", "txt"
   default_options = {"poco:shared": True, "openssl:shared": True}

   def imports(self):
      self.copy("*.dll", dst="bin", src="bin") # From bin to bin
      self.copy("*.dylib*", dst="bin", src="lib") # From lib to bin

   def build(self):
      cmake = CMake(self)
      cmake.configure(source_folder="src")
      cmake.build()