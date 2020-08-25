import os
from conans import ConanFile, CMake


class ToolsetConan(ConanFile):
    name = "toolset"
    version = "1.0.0"
    license = "<Put the package license here>"
    author = "<Put your name here> <And your email here>"
    url = "<Package recipe repository url here, for issues about the package>"
    description = "<Description of Toolset here>"
    topics = ("<Put some tag here>", "<here>", "<and here>")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = {"shared": False}
    generators = "cmake"
    exports_sources = "src/*"

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder="src")
        cmake.build()

        # Explicit way:
        # self.run('cmake %s/hello %s'
        #          % (self.source_folder, cmake.command_line))
        # self.run("cmake --build . %s" % cmake.build_config)

    def package(self):
        self.copy("*.h", dst="include", src="src")
        self.copy("*", dst="bin", src=os.path.join(self.build_folder, 'bin'), keep_path=False)
        self.copy("*", dst="lib", src=os.path.join(self.build_folder, 'lib'), keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["libtoolset"]
        bin_folder = os.path.join(self.package_folder, "bin")
        self.env_info.PATH.append(bin_folder)
        self.output.info('Append tool-set path %s' % bin_folder)
