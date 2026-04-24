r"""Wrapper for litecad.h

Generated with:
C:\Python314\Scripts\ctypesgen litecad.h -o litecad.py

Do not modify this file.
"""

import ctypes
import sys
from ctypes import (
    c_void_p,
    CFUNCTYPE,
    POINTER,
    c_int,
    sizeof,
    c_double,
    cast,
    c_uint,
)  # noqa: F401, F403
import ctypes.util
import glob
import os.path
import platform
import re
from os.path import dirname

__docformat__ = "restructuredtext"

# Begin preamble for Python

_int_types = (ctypes.c_int16, ctypes.c_int32)
if hasattr(ctypes, "c_int64"):
    # Some builds of ctypes apparently do not have ctypes.c_int64
    # defined; it's a pretty good bet that these builds do not
    # have 64-bit pointers.
    _int_types += (ctypes.c_int64,)
for t in _int_types:
    if ctypes.sizeof(t) == ctypes.sizeof(ctypes.c_size_t):
        c_ptrdiff_t = t
del t
del _int_types


class UserString:
    def __init__(self, seq):
        if isinstance(seq, bytes):
            self.data = seq
        elif isinstance(seq, UserString):
            self.data = seq.data[:]
        else:
            self.data = str(seq).encode()

    def __bytes__(self):
        return self.data

    def __str__(self):
        return self.data.decode()

    def __repr__(self):
        return repr(self.data)

    def __int__(self):
        return int(self.data.decode())

    def __long__(self):
        return int(self.data.decode())

    def __float__(self):
        return float(self.data.decode())

    def __complex__(self):
        return complex(self.data.decode())

    def __hash__(self):
        return hash(self.data)

    def __le__(self, string):
        if isinstance(string, UserString):
            return self.data <= string.data
        else:
            return self.data <= string

    def __lt__(self, string):
        if isinstance(string, UserString):
            return self.data < string.data
        else:
            return self.data < string

    def __ge__(self, string):
        if isinstance(string, UserString):
            return self.data >= string.data
        else:
            return self.data >= string

    def __gt__(self, string):
        if isinstance(string, UserString):
            return self.data > string.data
        else:
            return self.data > string

    def __eq__(self, string):
        if isinstance(string, UserString):
            return self.data == string.data
        else:
            return self.data == string

    def __ne__(self, string):
        if isinstance(string, UserString):
            return self.data != string.data
        else:
            return self.data != string

    def __contains__(self, char):
        return char in self.data

    def __len__(self):
        return len(self.data)

    def __getitem__(self, index):
        return self.__class__(self.data[index])

    def __getslice__(self, start, end):
        start = max(start, 0)
        end = max(end, 0)
        return self.__class__(self.data[start:end])

    def __add__(self, other):
        if isinstance(other, UserString):
            return self.__class__(self.data + other.data)
        elif isinstance(other, bytes):
            return self.__class__(self.data + other)
        else:
            return self.__class__(self.data + str(other).encode())

    def __radd__(self, other):
        if isinstance(other, bytes):
            return self.__class__(other + self.data)
        else:
            return self.__class__(str(other).encode() + self.data)

    def __mul__(self, n):
        return self.__class__(self.data * n)

    __rmul__ = __mul__

    def __mod__(self, args):
        return self.__class__(self.data % args)

    # the following methods are defined in alphabetical order:
    def capitalize(self):
        return self.__class__(self.data.capitalize())

    def center(self, width, *args):
        return self.__class__(self.data.center(width, *args))

    def count(self, sub, start=0, end=sys.maxsize):
        return self.data.count(sub, start, end)

    def decode(self, encoding=None, errors=None):  # XXX improve this?
        if encoding:
            if errors:
                return self.__class__(self.data.decode(encoding, errors))
            else:
                return self.__class__(self.data.decode(encoding))
        else:
            return self.__class__(self.data.decode())

    def encode(self, encoding=None, errors=None):  # XXX improve this?
        if encoding:
            if errors:
                return self.__class__(self.data.encode(encoding, errors))
            else:
                return self.__class__(self.data.encode(encoding))
        else:
            return self.__class__(self.data.encode())

    def endswith(self, suffix, start=0, end=sys.maxsize):
        return self.data.endswith(suffix, start, end)

    def expandtabs(self, tabsize=8):
        return self.__class__(self.data.expandtabs(tabsize))

    def find(self, sub, start=0, end=sys.maxsize):
        return self.data.find(sub, start, end)

    def index(self, sub, start=0, end=sys.maxsize):
        return self.data.index(sub, start, end)

    def isalpha(self):
        return self.data.isalpha()

    def isalnum(self):
        return self.data.isalnum()

    def isdecimal(self):
        return self.data.isdecimal()

    def isdigit(self):
        return self.data.isdigit()

    def islower(self):
        return self.data.islower()

    def isnumeric(self):
        return self.data.isnumeric()

    def isspace(self):
        return self.data.isspace()

    def istitle(self):
        return self.data.istitle()

    def isupper(self):
        return self.data.isupper()

    def join(self, seq):
        return self.data.join(seq)

    def ljust(self, width, *args):
        return self.__class__(self.data.ljust(width, *args))

    def lower(self):
        return self.__class__(self.data.lower())

    def lstrip(self, chars=None):
        return self.__class__(self.data.lstrip(chars))

    def partition(self, sep):
        return self.data.partition(sep)

    def replace(self, old, new, maxsplit=-1):
        return self.__class__(self.data.replace(old, new, maxsplit))

    def rfind(self, sub, start=0, end=sys.maxsize):
        return self.data.rfind(sub, start, end)

    def rindex(self, sub, start=0, end=sys.maxsize):
        return self.data.rindex(sub, start, end)

    def rjust(self, width, *args):
        return self.__class__(self.data.rjust(width, *args))

    def rpartition(self, sep):
        return self.data.rpartition(sep)

    def rstrip(self, chars=None):
        return self.__class__(self.data.rstrip(chars))

    def split(self, sep=None, maxsplit=-1):
        return self.data.split(sep, maxsplit)

    def rsplit(self, sep=None, maxsplit=-1):
        return self.data.rsplit(sep, maxsplit)

    def splitlines(self, keepends=0):
        return self.data.splitlines(keepends)

    def startswith(self, prefix, start=0, end=sys.maxsize):
        return self.data.startswith(prefix, start, end)

    def strip(self, chars=None):
        return self.__class__(self.data.strip(chars))

    def swapcase(self):
        return self.__class__(self.data.swapcase())

    def title(self):
        return self.__class__(self.data.title())

    def translate(self, *args):
        return self.__class__(self.data.translate(*args))

    def upper(self):
        return self.__class__(self.data.upper())

    def zfill(self, width):
        return self.__class__(self.data.zfill(width))


class MutableString(UserString):
    """mutable string objects

    Python strings are immutable objects.  This has the advantage, that
    strings may be used as dictionary keys.  If this property isn't needed
    and you insist on changing string values in place instead, you may cheat
    and use MutableString.

    But the purpose of this class is an educational one: to prevent
    people from inventing their own mutable string class derived
    from UserString and than forget thereby to remove (override) the
    __hash__ method inherited from UserString.  This would lead to
    errors that would be very hard to track down.

    A faster and better solution is to rewrite your program using lists."""

    def __init__(self, string=""):
        self.data = string

    def __hash__(self):
        raise TypeError("unhashable type (it is mutable)")

    def __setitem__(self, index, sub):
        if index < 0:
            index += len(self.data)
        if index < 0 or index >= len(self.data):
            raise IndexError
        self.data = self.data[:index] + sub + self.data[index + 1 :]

    def __delitem__(self, index):
        if index < 0:
            index += len(self.data)
        if index < 0 or index >= len(self.data):
            raise IndexError
        self.data = self.data[:index] + self.data[index + 1 :]

    def __setslice__(self, start, end, sub):
        start = max(start, 0)
        end = max(end, 0)
        if isinstance(sub, UserString):
            self.data = self.data[:start] + sub.data + self.data[end:]
        elif isinstance(sub, bytes):
            self.data = self.data[:start] + sub + self.data[end:]
        else:
            self.data = self.data[:start] + str(sub).encode() + self.data[end:]

    def __delslice__(self, start, end):
        start = max(start, 0)
        end = max(end, 0)
        self.data = self.data[:start] + self.data[end:]

    def immutable(self):
        return UserString(self.data)

    def __iadd__(self, other):
        if isinstance(other, UserString):
            self.data += other.data
        elif isinstance(other, bytes):
            self.data += other
        else:
            self.data += str(other).encode()
        return self

    def __imul__(self, n):
        self.data *= n
        return self


class String(MutableString, ctypes.Union):
    _fields_ = [("raw", ctypes.POINTER(ctypes.c_char)), ("data", ctypes.c_char_p)]

    def __init__(self, obj=b""):
        if isinstance(obj, (bytes, UserString)):
            self.data = bytes(obj)
        else:
            self.raw = obj

    def __len__(self):
        return self.data and len(self.data) or 0

    def from_param(cls, obj):
        # Convert None or 0
        if obj is None or obj == 0:
            return cls(ctypes.POINTER(ctypes.c_char)())

        # Convert from String
        elif isinstance(obj, String):
            return obj

        # Convert from bytes
        elif isinstance(obj, bytes):
            return cls(obj)

        # Convert from str
        elif isinstance(obj, str):
            return cls(obj.encode())

        # Convert from c_char_p
        elif isinstance(obj, ctypes.c_char_p):
            return obj

        # Convert from POINTER(ctypes.c_char)
        elif isinstance(obj, ctypes.POINTER(ctypes.c_char)):
            return obj

        # Convert from raw pointer
        elif isinstance(obj, int):
            return cls(ctypes.cast(obj, ctypes.POINTER(ctypes.c_char)))

        # Convert from ctypes.c_char array
        elif isinstance(obj, ctypes.c_char * len(obj)):
            return obj

        # Convert from object
        else:
            return String.from_param(obj._as_parameter_)

    from_param = classmethod(from_param)


def ReturnString(obj, func=None, arguments=None):
    return String.from_param(obj)


# As of ctypes 1.0, ctypes does not support custom error-checking
# functions on callbacks, nor does it support custom datatypes on
# callbacks, so we must ensure that all callbacks return
# primitive datatypes.
#
# Non-primitive return values wrapped with UNCHECKED won't be
# typechecked, and will be converted to ctypes.c_void_p.
def UNCHECKED(type):
    if hasattr(type, "_type_") and isinstance(type._type_, str) and type._type_ != "P":
        return type
    else:
        return ctypes.c_void_p


# ctypes doesn't have direct support for variadic functions, so we have to write
# our own wrapper class
class _variadic_function(object):
    def __init__(self, func, restype, argtypes, errcheck):
        self.func = func
        self.func.restype = restype
        self.argtypes = argtypes
        if errcheck:
            self.func.errcheck = errcheck

    def _as_parameter_(self):
        # So we can pass this variadic function as a function pointer
        return self.func

    def __call__(self, *args):
        fixed_args = []
        i = 0
        for argtype in self.argtypes:
            # Typecheck what we can
            fixed_args.append(argtype.from_param(args[i]))
            i += 1
        return self.func(*fixed_args + list(args[i:]))


def ord_if_char(value):
    """
    Simple helper used for casts to simple builtin types:  if the argument is a
    string type, it will be converted to it's ordinal value.

    This function will raise an exception if the argument is string with more
    than one characters.
    """
    return ord(value) if (isinstance(value, bytes) or isinstance(value, str)) else value


# End preamble

_libs = {}
_libdirs = []

# Begin loader

"""
Load libraries - appropriately for all our supported platforms
"""
# ----------------------------------------------------------------------------
# Copyright (c) 2008 David James
# Copyright (c) 2006-2008 Alex Holkner
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
#  * Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#  * Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the
#    distribution.
#  * Neither the name of pyglet nor the names of its
#    contributors may be used to endorse or promote products
#    derived from this software without specific prior written
#    permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
# ----------------------------------------------------------------------------


def _environ_path(name):
    """Split an environment variable into a path-like list elements"""
    if name in os.environ:
        return os.environ[name].split(":")
    return []


class LibraryLoader:
    """
    A base class For loading of libraries ;-)
    Subclasses load libraries for specific platforms.
    """

    # library names formatted specifically for platforms
    name_formats = ["%s"]

    class Lookup:
        """Looking up calling conventions for a platform"""

        mode = ctypes.DEFAULT_MODE

        def __init__(self, path):
            super(LibraryLoader.Lookup, self).__init__()
            self.access = dict(cdecl=ctypes.CDLL(path, self.mode))

        def get(self, name, calling_convention="cdecl"):
            """Return the given name according to the selected calling convention"""
            if calling_convention not in self.access:
                raise LookupError(
                    "Unknown calling convention '{}' for function '{}'".format(
                        calling_convention, name
                    )
                )
            return getattr(self.access[calling_convention], name)

        def has(self, name, calling_convention="cdecl"):
            """Return True if this given calling convention finds the given 'name'"""
            if calling_convention not in self.access:
                return False
            return hasattr(self.access[calling_convention], name)

        def __getattr__(self, name):
            return getattr(self.access["cdecl"], name)

    def __init__(self):
        self.other_dirs = []

    def __call__(self, libname):
        """Given the name of a library, load it."""
        paths = self.getpaths(libname)

        for path in paths:
            # noinspection PyBroadException
            try:
                return self.Lookup(path)
            except Exception:  # pylint: disable=broad-except
                pass

        raise ImportError("Could not load %s." % libname)

    def getpaths(self, libname):
        """Return a list of paths where the library might be found."""
        if os.path.isabs(libname):
            yield libname
        else:
            # search through a prioritized series of locations for the library

            # we first search any specific directories identified by user
            for dir_i in self.other_dirs:
                for fmt in self.name_formats:
                    # dir_i should be absolute already
                    yield os.path.join(dir_i, fmt % libname)

            # check if this code is even stored in a physical file
            try:
                this_file = __file__
            except NameError:
                this_file = None

            # then we search the directory where the generated python interface is stored
            if this_file is not None:
                for fmt in self.name_formats:
                    yield os.path.abspath(
                        os.path.join(os.path.dirname(__file__), fmt % libname)
                    )

            # now, use the ctypes tools to try to find the library
            for fmt in self.name_formats:
                path = ctypes.util.find_library(fmt % libname)
                if path:
                    yield path

            # then we search all paths identified as platform-specific lib paths
            for path in self.getplatformpaths(libname):
                yield path

            # Finally, we'll try the users current working directory
            for fmt in self.name_formats:
                yield os.path.abspath(os.path.join(os.path.curdir, fmt % libname))

    def getplatformpaths(self, _libname):  # pylint: disable=no-self-use
        """Return all the library paths available in this platform"""
        return []


# Darwin (Mac OS X)


class DarwinLibraryLoader(LibraryLoader):
    """Library loader for MacOS"""

    name_formats = [
        "lib%s.dylib",
        "lib%s.so",
        "lib%s.bundle",
        "%s.dylib",
        "%s.so",
        "%s.bundle",
        "%s",
    ]

    class Lookup(LibraryLoader.Lookup):
        """
        Looking up library files for this platform (Darwin aka MacOS)
        """

        # Darwin requires dlopen to be called with mode RTLD_GLOBAL instead
        # of the default RTLD_LOCAL.  Without this, you end up with
        # libraries not being loadable, resulting in "Symbol not found"
        # errors
        mode = ctypes.RTLD_GLOBAL

    def getplatformpaths(self, libname):
        if os.path.pathsep in libname:
            names = [libname]
        else:
            names = [fmt % libname for fmt in self.name_formats]

        for directory in self.getdirs(libname):
            for name in names:
                yield os.path.join(directory, name)

    @staticmethod
    def getdirs(libname):
        """Implements the dylib search as specified in Apple documentation:

        http://developer.apple.com/documentation/DeveloperTools/Conceptual/
            DynamicLibraries/Articles/DynamicLibraryUsageGuidelines.html

        Before commencing the standard search, the method first checks
        the bundle's ``Frameworks`` directory if the application is running
        within a bundle (OS X .app).
        """

        dyld_fallback_library_path = _environ_path("DYLD_FALLBACK_LIBRARY_PATH")
        if not dyld_fallback_library_path:
            dyld_fallback_library_path = [
                os.path.expanduser("~/lib"),
                "/usr/local/lib",
                "/usr/lib",
            ]

        dirs = []

        if "/" in libname:
            dirs.extend(_environ_path("DYLD_LIBRARY_PATH"))
        else:
            dirs.extend(_environ_path("LD_LIBRARY_PATH"))
            dirs.extend(_environ_path("DYLD_LIBRARY_PATH"))
            dirs.extend(_environ_path("LD_RUN_PATH"))

        if hasattr(sys, "frozen") and getattr(sys, "frozen") == "macosx_app":
            dirs.append(os.path.join(os.environ["RESOURCEPATH"], "..", "Frameworks"))

        dirs.extend(dyld_fallback_library_path)

        return dirs


# Posix


class PosixLibraryLoader(LibraryLoader):
    """Library loader for POSIX-like systems (including Linux)"""

    _ld_so_cache = None

    _include = re.compile(r"^\s*include\s+(?P<pattern>.*)")

    name_formats = ["lib%s.so", "%s.so", "%s"]

    class _Directories(dict):
        """Deal with directories"""

        def __init__(self):
            dict.__init__(self)
            self.order = 0

        def add(self, directory):
            """Add a directory to our current set of directories"""
            if len(directory) > 1:
                directory = directory.rstrip(os.path.sep)
            # only adds and updates order if exists and not already in set
            if not os.path.exists(directory):
                return
            order = self.setdefault(directory, self.order)
            if order == self.order:
                self.order += 1

        def extend(self, directories):
            """Add a list of directories to our set"""
            for a_dir in directories:
                self.add(a_dir)

        def ordered(self):
            """Sort the list of directories"""
            return (i[0] for i in sorted(self.items(), key=lambda d: d[1]))

    def _get_ld_so_conf_dirs(self, conf, dirs):
        """
        Recursive function to help parse all ld.so.conf files, including proper
        handling of the `include` directive.
        """

        try:
            with open(conf) as fileobj:
                for dirname in fileobj:
                    dirname = dirname.strip()
                    if not dirname:
                        continue

                    match = self._include.match(dirname)
                    if not match:
                        dirs.add(dirname)
                    else:
                        for dir2 in glob.glob(match.group("pattern")):
                            self._get_ld_so_conf_dirs(dir2, dirs)
        except IOError:
            pass

    def _create_ld_so_cache(self):
        # Recreate search path followed by ld.so.  This is going to be
        # slow to build, and incorrect (ld.so uses ld.so.cache, which may
        # not be up-to-date).  Used only as fallback for distros without
        # /sbin/ldconfig.
        #
        # We assume the DT_RPATH and DT_RUNPATH binary sections are omitted.

        directories = self._Directories()
        for name in (
            "LD_LIBRARY_PATH",
            "SHLIB_PATH",  # HP-UX
            "LIBPATH",  # OS/2, AIX
            "LIBRARY_PATH",  # BE/OS
        ):
            if name in os.environ:
                directories.extend(os.environ[name].split(os.pathsep))

        self._get_ld_so_conf_dirs("/etc/ld.so.conf", directories)

        bitage = platform.architecture()[0]

        unix_lib_dirs_list = []
        if bitage.startswith("64"):
            # prefer 64 bit if that is our arch
            unix_lib_dirs_list += ["/lib64", "/usr/lib64"]

        # must include standard libs, since those paths are also used by 64 bit
        # installs
        unix_lib_dirs_list += ["/lib", "/usr/lib"]
        if sys.platform.startswith("linux"):
            # Try and support multiarch work in Ubuntu
            # https://wiki.ubuntu.com/MultiarchSpec
            if bitage.startswith("32"):
                # Assume Intel/AMD x86 compat
                unix_lib_dirs_list += ["/lib/i386-linux-gnu", "/usr/lib/i386-linux-gnu"]
            elif bitage.startswith("64"):
                # Assume Intel/AMD x86 compatible
                unix_lib_dirs_list += [
                    "/lib/x86_64-linux-gnu",
                    "/usr/lib/x86_64-linux-gnu",
                ]
            else:
                # guess...
                unix_lib_dirs_list += glob.glob("/lib/*linux-gnu")
        directories.extend(unix_lib_dirs_list)

        cache = {}
        lib_re = re.compile(r"lib(.*)\.s[ol]")
        # ext_re = re.compile(r"\.s[ol]$")
        for our_dir in directories.ordered():
            try:
                for path in glob.glob("%s/*.s[ol]*" % our_dir):
                    file = os.path.basename(path)

                    # Index by filename
                    cache_i = cache.setdefault(file, set())
                    cache_i.add(path)

                    # Index by library name
                    match = lib_re.match(file)
                    if match:
                        library = match.group(1)
                        cache_i = cache.setdefault(library, set())
                        cache_i.add(path)
            except OSError:
                pass

        self._ld_so_cache = cache

    def getplatformpaths(self, libname):
        if self._ld_so_cache is None:
            self._create_ld_so_cache()

        result = self._ld_so_cache.get(libname, set())
        for i in result:
            # we iterate through all found paths for library, since we may have
            # actually found multiple architectures or other library types that
            # may not load
            yield i


# Windows


class WindowsLibraryLoader(LibraryLoader):
    """Library loader for Microsoft Windows"""

    name_formats = ["%s.dll", "lib%s.dll", "%slib.dll", "%s"]

    class Lookup(LibraryLoader.Lookup):
        """Lookup class for Windows libraries..."""

        def __init__(self, path):
            super(WindowsLibraryLoader.Lookup, self).__init__(path)
            self.access["cdecl"] = ctypes.windll.LoadLibrary(path)


# Platform switching

# If your value of sys.platform does not appear in this dict, please contact
# the Ctypesgen maintainers.

loaderclass = {
    "darwin": DarwinLibraryLoader,
    "cygwin": WindowsLibraryLoader,
    "win32": WindowsLibraryLoader,
    "msys": WindowsLibraryLoader,
}

load_library = loaderclass.get(sys.platform, PosixLibraryLoader)()


def add_library_search_dirs(other_dirs):
    """
    Add libraries to search paths.
    If library paths are relative, convert them to absolute with respect to this
    file's directory
    """
    for path in other_dirs:
        if not os.path.isabs(path):
            path = os.path.abspath(path)
        load_library.other_dirs.append(path)


del loaderclass

# End loader

add_library_search_dirs(
    [
        #dirname(__file__),
        #dirname(__file__) + "/../../out/build/debug",
        dirname(__file__) + "/../../out/build/release",
    ]
)

_libs = {"cmn": load_library("gllc")}

# No libraries

# No modules

F_LCEVENT = CFUNCTYPE(UNCHECKED(None), c_void_p)  # D:\\projects\\gllc\\litecad.h: 3187

F_WAITPOINT = CFUNCTYPE(
    UNCHECKED(None), c_int, c_void_p
)  # D:\\projects\\gllc\\litecad.h: 3188

F_REDRAW = CFUNCTYPE(
    UNCHECKED(None), c_void_p, c_int
)  # D:\\projects\\gllc\\litecad.h: 3189

# D:\\projects\\gllc\\litecad.h: 3193
for _lib in _libs.values():
    if not _lib.has("lcEventSetProc", "cdecl"):
        continue
    lcEventSetProc = _lib.get("lcEventSetProc", "cdecl")
    lcEventSetProc.argtypes = [c_int, F_LCEVENT, c_int, c_void_p]
    lcEventSetProc.restype = None
    break

# D:\\projects\\gllc\\litecad.h: 3194
for _lib in _libs.values():
    if not _lib.has("lcEventReturnCode", "cdecl"):
        continue
    lcEventReturnCode = _lib.get("lcEventReturnCode", "cdecl")
    lcEventReturnCode.argtypes = [c_int]
    lcEventReturnCode.restype = None
    break

# D:\\projects\\gllc\\litecad.h: 3195
for _lib in _libs.values():
    if not _lib.has("lcEventsEnable", "cdecl"):
        continue
    lcEventsEnable = _lib.get("lcEventsEnable", "cdecl")
    lcEventsEnable.argtypes = [c_int]
    lcEventsEnable.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3198
for _lib in _libs.values():
    if not _lib.has("lcInitialize", "cdecl"):
        continue
    lcInitialize = _lib.get("lcInitialize", "cdecl")
    lcInitialize.argtypes = []
    lcInitialize.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3199
for _lib in _libs.values():
    if not _lib.has("lcUninitialize", "cdecl"):
        continue
    lcUninitialize = _lib.get("lcUninitialize", "cdecl")
    lcUninitialize.argtypes = [c_int]
    lcUninitialize.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3202
for _lib in _libs.values():
    if not _lib.has("lcStrAdd", "cdecl"):
        continue
    lcStrAdd = _lib.get("lcStrAdd", "cdecl")
    lcStrAdd.argtypes = [String, String]
    lcStrAdd.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3203
for _lib in _libs.values():
    if not _lib.has("lcStrSet", "cdecl"):
        continue
    lcStrSet = _lib.get("lcStrSet", "cdecl")
    lcStrSet.argtypes = [String, String]
    lcStrSet.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3204
for _lib in _libs.values():
    if not _lib.has("lcStrGet", "cdecl"):
        continue
    lcStrGet = _lib.get("lcStrGet", "cdecl")
    lcStrGet.argtypes = [String]
    if sizeof(c_int) == sizeof(c_void_p):
        lcStrGet.restype = ReturnString
    else:
        lcStrGet.restype = String
        lcStrGet.errcheck = ReturnString
    break

# D:\\projects\\gllc\\litecad.h: 3205
for _lib in _libs.values():
    if not _lib.has("lcStrFileLoad", "cdecl"):
        continue
    lcStrFileLoad = _lib.get("lcStrFileLoad", "cdecl")
    lcStrFileLoad.argtypes = [String]
    lcStrFileLoad.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3206
for _lib in _libs.values():
    if not _lib.has("lcStrFileSave", "cdecl"):
        continue
    lcStrFileSave = _lib.get("lcStrFileSave", "cdecl")
    lcStrFileSave.argtypes = [String, String]
    lcStrFileSave.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3209
for _lib in _libs.values():
    if not _lib.has("lcPropGetBool", "cdecl"):
        continue
    lcPropGetBool = _lib.get("lcPropGetBool", "cdecl")
    lcPropGetBool.argtypes = [c_void_p, c_int]
    lcPropGetBool.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3210
for _lib in _libs.values():
    if not _lib.has("lcPropGetInt", "cdecl"):
        continue
    lcPropGetInt = _lib.get("lcPropGetInt", "cdecl")
    lcPropGetInt.argtypes = [c_void_p, c_int]
    lcPropGetInt.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3211
for _lib in _libs.values():
    if not _lib.has("lcPropGetFloat", "cdecl"):
        continue
    lcPropGetFloat = _lib.get("lcPropGetFloat", "cdecl")
    lcPropGetFloat.argtypes = [c_void_p, c_int]
    lcPropGetFloat.restype = c_double
    break

# D:\\projects\\gllc\\litecad.h: 3212
for _lib in _libs.values():
    if not _lib.has("lcPropGetStr", "cdecl"):
        continue
    lcPropGetStr = _lib.get("lcPropGetStr", "cdecl")
    lcPropGetStr.argtypes = [c_void_p, c_int]
    if sizeof(c_int) == sizeof(c_void_p):
        lcPropGetStr.restype = ReturnString
    else:
        lcPropGetStr.restype = String
        lcPropGetStr.errcheck = ReturnString
    break

# D:\\projects\\gllc\\litecad.h: 3213
for _lib in _libs.values():
    if not _lib.has("lcPropGetStrA", "cdecl"):
        continue
    lcPropGetStrA = _lib.get("lcPropGetStrA", "cdecl")
    lcPropGetStrA.argtypes = [c_void_p, c_int, String, c_int]
    lcPropGetStrA.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3214
for _lib in _libs.values():
    if not _lib.has("lcPropGetStr2", "cdecl"):
        continue
    lcPropGetStr2 = _lib.get("lcPropGetStr2", "cdecl")
    lcPropGetStr2.argtypes = [c_void_p, c_int]
    lcPropGetStr2.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3215
for _lib in _libs.values():
    if not _lib.has("lcPropGetChar", "cdecl"):
        continue
    lcPropGetChar = _lib.get("lcPropGetChar", "cdecl")
    lcPropGetChar.argtypes = [c_int]
    lcPropGetChar.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3216
for _lib in _libs.values():
    if not _lib.has("lcPropGetHandle", "cdecl"):
        continue
    lcPropGetHandle = _lib.get("lcPropGetHandle", "cdecl")
    lcPropGetHandle.argtypes = [c_void_p, c_int]
    lcPropGetHandle.restype = c_void_p
    lcPropGetHandle.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3217
for _lib in _libs.values():
    if not _lib.has("lcPropPutBool", "cdecl"):
        continue
    lcPropPutBool = _lib.get("lcPropPutBool", "cdecl")
    lcPropPutBool.argtypes = [c_void_p, c_int, c_int]
    lcPropPutBool.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3218
for _lib in _libs.values():
    if not _lib.has("lcPropPutInt", "cdecl"):
        continue
    lcPropPutInt = _lib.get("lcPropPutInt", "cdecl")
    lcPropPutInt.argtypes = [c_void_p, c_int, c_int]
    lcPropPutInt.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3219
for _lib in _libs.values():
    if not _lib.has("lcPropPutFloat", "cdecl"):
        continue
    lcPropPutFloat = _lib.get("lcPropPutFloat", "cdecl")
    lcPropPutFloat.argtypes = [c_void_p, c_int, c_double]
    lcPropPutFloat.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3220
for _lib in _libs.values():
    if not _lib.has("lcPropPutStr", "cdecl"):
        continue
    lcPropPutStr = _lib.get("lcPropPutStr", "cdecl")
    lcPropPutStr.argtypes = [c_void_p, c_int, String]
    lcPropPutStr.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3221
for _lib in _libs.values():
    if not _lib.has("lcPropPutHandle", "cdecl"):
        continue
    lcPropPutHandle = _lib.get("lcPropPutHandle", "cdecl")
    lcPropPutHandle.argtypes = [c_void_p, c_int, c_void_p]
    lcPropPutHandle.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3224
for _lib in _libs.values():
    print(
        "cdecl:",
        _lib.has("lcCreateWindow", "cdecl"),
        "stdcall:",
        _lib.has("lcCreateWindow", "stdcall"),
    )
    if not _lib.has("lcCreateWindow", "cdecl"):
        continue
    lcCreateWindow = _lib.get("lcCreateWindow", "cdecl")
    lcCreateWindow.argtypes = [c_void_p, c_int]
    lcCreateWindow.restype = c_void_p
    lcCreateWindow.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3225
for _lib in _libs.values():
    if not _lib.has("lcDeleteWindow", "cdecl"):
        continue
    lcDeleteWindow = _lib.get("lcDeleteWindow", "cdecl")
    lcDeleteWindow.argtypes = [c_void_p]
    lcDeleteWindow.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3226
for _lib in _libs.values():
    if not _lib.has("lcWndOnClose", "cdecl"):
        continue
    lcWndOnClose = _lib.get("lcWndOnClose", "cdecl")
    lcWndOnClose.argtypes = [c_void_p]
    lcWndOnClose.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3227
for _lib in _libs.values():
    if not _lib.has("lcWndExeCommand", "cdecl"):
        continue
    lcWndExeCommand = _lib.get("lcWndExeCommand", "cdecl")
    lcWndExeCommand.argtypes = [c_void_p, c_int, c_int]
    lcWndExeCommand.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3228
for _lib in _libs.values():
    if not _lib.has("lcWndExitCommand", "cdecl"):
        continue
    lcWndExitCommand = _lib.get("lcWndExitCommand", "cdecl")
    lcWndExitCommand.argtypes = [c_void_p]
    lcWndExitCommand.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3229
for _lib in _libs.values():
    if not _lib.has("lcWndResize", "cdecl"):
        continue
    lcWndResize = _lib.get("lcWndResize", "cdecl")
    lcWndResize.argtypes = [c_void_p, c_int, c_int, c_int, c_int]
    lcWndResize.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3230
for _lib in _libs.values():
    if not _lib.has("lcWndRedraw", "cdecl"):
        continue
    lcWndRedraw = _lib.get("lcWndRedraw", "cdecl")
    lcWndRedraw.argtypes = [c_void_p]
    lcWndRedraw.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3231
for _lib in _libs.values():
    if not _lib.has("lcWndRedrawAuto", "cdecl"):
        continue
    lcWndRedrawAuto = _lib.get("lcWndRedrawAuto", "cdecl")
    lcWndRedrawAuto.argtypes = [c_void_p, c_int, F_REDRAW]
    lcWndRedrawAuto.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3232
for _lib in _libs.values():
    if not _lib.has("lcWndSetFocus", "cdecl"):
        continue
    lcWndSetFocus = _lib.get("lcWndSetFocus", "cdecl")
    lcWndSetFocus.argtypes = [c_void_p]
    lcWndSetFocus.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3233
for _lib in _libs.values():
    if not _lib.has("lcWndSetExtents", "cdecl"):
        continue
    lcWndSetExtents = _lib.get("lcWndSetExtents", "cdecl")
    lcWndSetExtents.argtypes = [c_void_p, c_double, c_double, c_double, c_double]
    lcWndSetExtents.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3235
for _lib in _libs.values():
    if not _lib.has("lcWndSetBlock", "cdecl"):
        continue
    lcWndSetBlock = _lib.get("lcWndSetBlock", "cdecl")
    lcWndSetBlock.argtypes = [c_void_p, c_void_p]
    lcWndSetBlock.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3236
for _lib in _libs.values():
    if not _lib.has("lcWndSetProps", "cdecl"):
        continue
    lcWndSetProps = _lib.get("lcWndSetProps", "cdecl")
    lcWndSetProps.argtypes = [c_void_p, c_void_p]
    lcWndSetProps.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3237
for _lib in _libs.values():
    if not _lib.has("lcWndSetCmdwin", "cdecl"):
        continue
    lcWndSetCmdwin = _lib.get("lcWndSetCmdwin", "cdecl")
    lcWndSetCmdwin.argtypes = [c_void_p, c_void_p]
    lcWndSetCmdwin.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3238
for _lib in _libs.values():
    if not _lib.has("lcWndSetBasePoint", "cdecl"):
        continue
    lcWndSetBasePoint = _lib.get("lcWndSetBasePoint", "cdecl")
    lcWndSetBasePoint.argtypes = [c_void_p, c_int, c_double, c_double]
    lcWndSetBasePoint.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3239
for _lib in _libs.values():
    if not _lib.has("lcWndEmulator", "cdecl"):
        continue
    lcWndEmulator = _lib.get("lcWndEmulator", "cdecl")
    lcWndEmulator.argtypes = [c_void_p, c_int]
    lcWndEmulator.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3240
for _lib in _libs.values():
    if not _lib.has("lcWndMagnifier", "cdecl"):
        continue
    lcWndMagnifier = _lib.get("lcWndMagnifier", "cdecl")
    lcWndMagnifier.argtypes = [c_void_p, c_int, c_int, c_int, c_int, c_int]
    lcWndMagnifier.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3242
for _lib in _libs.values():
    if not _lib.has("lcWndHoverText", "cdecl"):
        continue
    lcWndHoverText = _lib.get("lcWndHoverText", "cdecl")
    lcWndHoverText.argtypes = [c_void_p, String, c_int, c_int, c_int]
    lcWndHoverText.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3243
for _lib in _libs.values():
    if not _lib.has("lcWndMessage", "cdecl"):
        continue
    lcWndMessage = _lib.get("lcWndMessage", "cdecl")
    lcWndMessage.argtypes = [c_void_p, String, c_int]
    lcWndMessage.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3244
for _lib in _libs.values():
    if not _lib.has("lcWndWaitPoint", "cdecl"):
        continue
    lcWndWaitPoint = _lib.get("lcWndWaitPoint", "cdecl")
    lcWndWaitPoint.argtypes = [
        c_void_p,
        String,
        POINTER(c_double),
        POINTER(c_double),
    ]
    lcWndWaitPoint.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3246
for _lib in _libs.values():
    if not _lib.has("lcWndWaitPoint2", "cdecl"):
        continue
    lcWndWaitPoint2 = _lib.get("lcWndWaitPoint2", "cdecl")
    lcWndWaitPoint2.argtypes = [
        c_void_p,
        String,
        POINTER(c_double),
        POINTER(c_double),
        F_WAITPOINT,
        c_int,
    ]
    lcWndWaitPoint2.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3248
for _lib in _libs.values():
    if not _lib.has("lcWndInputStr", "cdecl"):
        continue
    lcWndInputStr = _lib.get("lcWndInputStr", "cdecl")
    lcWndInputStr.argtypes = [c_void_p]
    lcWndInputStr.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3249
for _lib in _libs.values():
    if not _lib.has("lcWndUpdate", "cdecl"):
        continue
    lcWndUpdate = _lib.get("lcWndUpdate", "cdecl")
    lcWndUpdate.argtypes = [c_void_p, c_int]
    lcWndUpdate.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3250
for _lib in _libs.values():
    if not _lib.has("lcWndDrwAdd", "cdecl"):
        continue
    lcWndDrwAdd = _lib.get("lcWndDrwAdd", "cdecl")
    lcWndDrwAdd.argtypes = [c_void_p, String]
    lcWndDrwAdd.restype = c_void_p
    lcWndDrwAdd.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3251
for _lib in _libs.values():
    if not _lib.has("lcWndDrwDelete", "cdecl"):
        continue
    lcWndDrwDelete = _lib.get("lcWndDrwDelete", "cdecl")
    lcWndDrwDelete.argtypes = [c_void_p, c_void_p]
    lcWndDrwDelete.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3252
for _lib in _libs.values():
    if not _lib.has("lcWndDrwGet", "cdecl"):
        continue
    lcWndDrwGet = _lib.get("lcWndDrwGet", "cdecl")
    lcWndDrwGet.argtypes = [c_void_p, c_int]
    lcWndDrwGet.restype = c_void_p
    lcWndDrwGet.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3254
for _lib in _libs.values():
    if not _lib.has("lcWndZoomRect", "cdecl"):
        continue
    lcWndZoomRect = _lib.get("lcWndZoomRect", "cdecl")
    lcWndZoomRect.argtypes = [c_void_p, c_double, c_double, c_double, c_double]
    lcWndZoomRect.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3256
for _lib in _libs.values():
    if not _lib.has("lcWndZoomScale", "cdecl"):
        continue
    lcWndZoomScale = _lib.get("lcWndZoomScale", "cdecl")
    lcWndZoomScale.argtypes = [c_void_p, c_double]
    lcWndZoomScale.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3257
for _lib in _libs.values():
    if not _lib.has("lcWndZoomMove", "cdecl"):
        continue
    lcWndZoomMove = _lib.get("lcWndZoomMove", "cdecl")
    lcWndZoomMove.argtypes = [c_void_p, c_double, c_double]
    lcWndZoomMove.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3258
for _lib in _libs.values():
    if not _lib.has("lcWndZoomPos", "cdecl"):
        continue
    lcWndZoomPos = _lib.get("lcWndZoomPos", "cdecl")
    lcWndZoomPos.argtypes = [c_void_p, c_double, c_double, c_double]
    lcWndZoomPos.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3259
for _lib in _libs.values():
    if not _lib.has("lcWndZoomEnt", "cdecl"):
        continue
    lcWndZoomEnt = _lib.get("lcWndZoomEnt", "cdecl")
    lcWndZoomEnt.argtypes = [c_void_p, c_void_p, c_double]
    lcWndZoomEnt.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3261
for _lib in _libs.values():
    if not _lib.has("lcWndGetCursorCoord", "cdecl"):
        continue
    lcWndGetCursorCoord = _lib.get("lcWndGetCursorCoord", "cdecl")
    lcWndGetCursorCoord.argtypes = [
        c_void_p,
        POINTER(c_int),
        POINTER(c_int),
        POINTER(c_double),
        POINTER(c_double),
    ]
    lcWndGetCursorCoord.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3263
for _lib in _libs.values():
    if not _lib.has("lcCoordDrwToWnd", "cdecl"):
        continue
    lcCoordDrwToWnd = _lib.get("lcCoordDrwToWnd", "cdecl")
    lcCoordDrwToWnd.argtypes = [
        c_void_p,
        c_double,
        c_double,
        POINTER(c_int),
        POINTER(c_int),
    ]
    lcCoordDrwToWnd.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3265
for _lib in _libs.values():
    if not _lib.has("lcCoordWndToDrw", "cdecl"):
        continue
    lcCoordWndToDrw = _lib.get("lcCoordWndToDrw", "cdecl")
    lcCoordWndToDrw.argtypes = [
        c_void_p,
        c_int,
        c_int,
        POINTER(c_double),
        POINTER(c_double),
    ]
    lcCoordWndToDrw.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3267
for _lib in _libs.values():
    if not _lib.has("lcWndCoordFromDrw", "cdecl"):
        continue
    lcWndCoordFromDrw = _lib.get("lcWndCoordFromDrw", "cdecl")
    lcWndCoordFromDrw.argtypes = [
        c_void_p,
        c_double,
        c_double,
        POINTER(c_int),
        POINTER(c_int),
    ]
    lcWndCoordFromDrw.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3269
for _lib in _libs.values():
    if not _lib.has("lcWndCoordToDrw", "cdecl"):
        continue
    lcWndCoordToDrw = _lib.get("lcWndCoordToDrw", "cdecl")
    lcWndCoordToDrw.argtypes = [
        c_void_p,
        c_int,
        c_int,
        POINTER(c_double),
        POINTER(c_double),
    ]
    lcWndCoordToDrw.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3273
for _lib in _libs.values():
    if not _lib.has("lcWndGetEntByPoint", "cdecl"):
        continue
    lcWndGetEntByPoint = _lib.get("lcWndGetEntByPoint", "cdecl")
    lcWndGetEntByPoint.argtypes = [c_void_p, c_int, c_int]
    lcWndGetEntByPoint.restype = c_void_p
    lcWndGetEntByPoint.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3274
for _lib in _libs.values():
    if not _lib.has("lcWndGetEntByPoint2", "cdecl"):
        continue
    lcWndGetEntByPoint2 = _lib.get("lcWndGetEntByPoint2", "cdecl")
    lcWndGetEntByPoint2.argtypes = [c_void_p, c_double, c_double, c_double]
    lcWndGetEntByPoint2.restype = c_void_p
    lcWndGetEntByPoint2.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3275
for _lib in _libs.values():
    if not _lib.has("lcWndGetEntsByPoint", "cdecl"):
        continue
    lcWndGetEntsByPoint = _lib.get("lcWndGetEntsByPoint", "cdecl")
    lcWndGetEntsByPoint.argtypes = [c_void_p, c_int, c_int, c_int]
    lcWndGetEntsByPoint.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3276
for _lib in _libs.values():
    if not _lib.has("lcWndGetEntsByRect", "cdecl"):
        continue
    lcWndGetEntsByRect = _lib.get("lcWndGetEntsByRect", "cdecl")
    lcWndGetEntsByRect.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
        c_int,
    ]
    lcWndGetEntsByRect.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3278
for _lib in _libs.values():
    if not _lib.has("lcWndGetEntity", "cdecl"):
        continue
    lcWndGetEntity = _lib.get("lcWndGetEntity", "cdecl")
    lcWndGetEntity.argtypes = [c_int]
    lcWndGetEntity.restype = c_void_p
    lcWndGetEntity.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3279
for _lib in _libs.values():
    if not _lib.has("lcWndGetEntByID", "cdecl"):
        continue
    lcWndGetEntByID = _lib.get("lcWndGetEntByID", "cdecl")
    lcWndGetEntByID.argtypes = [c_void_p, c_int]
    lcWndGetEntByID.restype = c_void_p
    lcWndGetEntByID.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3280
for _lib in _libs.values():
    if not _lib.has("lcWndGetEntByIDH", "cdecl"):
        continue
    lcWndGetEntByIDH = _lib.get("lcWndGetEntByIDH", "cdecl")
    lcWndGetEntByIDH.argtypes = [c_void_p, String]
    lcWndGetEntByIDH.restype = c_void_p
    lcWndGetEntByIDH.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3281
for _lib in _libs.values():
    if not _lib.has("lcWndGetEntByKey", "cdecl"):
        continue
    lcWndGetEntByKey = _lib.get("lcWndGetEntByKey", "cdecl")
    lcWndGetEntByKey.argtypes = [c_void_p, c_int]
    lcWndGetEntByKey.restype = c_void_p
    lcWndGetEntByKey.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3282
for _lib in _libs.values():
    if not _lib.has("lcWndPickEnt", "cdecl"):
        continue
    lcWndPickEnt = _lib.get("lcWndPickEnt", "cdecl")
    lcWndPickEnt.argtypes = [c_void_p, String, String]
    lcWndPickEnt.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3285
for _lib in _libs.values():
    if not _lib.has("lcFontGetFirst", "cdecl"):
        continue
    lcFontGetFirst = _lib.get("lcFontGetFirst", "cdecl")
    lcFontGetFirst.argtypes = []
    lcFontGetFirst.restype = c_void_p
    lcFontGetFirst.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3286
for _lib in _libs.values():
    if not _lib.has("lcFontGetNext", "cdecl"):
        continue
    lcFontGetNext = _lib.get("lcFontGetNext", "cdecl")
    lcFontGetNext.argtypes = [c_void_p]
    lcFontGetNext.restype = c_void_p
    lcFontGetNext.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3287
for _lib in _libs.values():
    if not _lib.has("lcFontAddRes", "cdecl"):
        continue
    lcFontAddRes = _lib.get("lcFontAddRes", "cdecl")
    lcFontAddRes.argtypes = [String, c_void_p, c_int]
    lcFontAddRes.restype = c_void_p
    lcFontAddRes.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3288
for _lib in _libs.values():
    if not _lib.has("lcFontAddFile", "cdecl"):
        continue
    lcFontAddFile = _lib.get("lcFontAddFile", "cdecl")
    lcFontAddFile.argtypes = [String, String, String]
    lcFontAddFile.restype = c_void_p
    lcFontAddFile.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3290
for _lib in _libs.values():
    if not _lib.has("lcFontAddBin", "cdecl"):
        continue
    lcFontAddBin = _lib.get("lcFontAddBin", "cdecl")
    lcFontAddBin.argtypes = [String, c_void_p]
    lcFontAddBin.restype = c_void_p
    lcFontAddBin.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3291
for _lib in _libs.values():
    if not _lib.has("lcFontGetChar", "cdecl"):
        continue
    lcFontGetChar = _lib.get("lcFontGetChar", "cdecl")
    lcFontGetChar.argtypes = [c_void_p, c_int]
    lcFontGetChar.restype = c_void_p
    lcFontGetChar.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3292
for _lib in _libs.values():
    if not _lib.has("lcFontGetName", "cdecl"):
        continue
    lcFontGetName = _lib.get("lcFontGetName", "cdecl")
    lcFontGetName.argtypes = [String]
    if sizeof(c_int) == sizeof(c_void_p):
        lcFontGetName.restype = ReturnString
    else:
        lcFontGetName.restype = String
        lcFontGetName.errcheck = ReturnString
    break

# D:\\projects\\gllc\\litecad.h: 3295
for _lib in _libs.values():
    if not _lib.has("lcProgressCreate", "cdecl"):
        continue
    lcProgressCreate = _lib.get("lcProgressCreate", "cdecl")
    lcProgressCreate.argtypes = [c_void_p, c_int, c_int, String]
    lcProgressCreate.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3296
for _lib in _libs.values():
    if not _lib.has("lcProgressSetText", "cdecl"):
        continue
    lcProgressSetText = _lib.get("lcProgressSetText", "cdecl")
    lcProgressSetText.argtypes = [String]
    lcProgressSetText.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3297
for _lib in _libs.values():
    if not _lib.has("lcProgressStart", "cdecl"):
        continue
    lcProgressStart = _lib.get("lcProgressStart", "cdecl")
    lcProgressStart.argtypes = [c_int, c_int]
    lcProgressStart.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3298
for _lib in _libs.values():
    if not _lib.has("lcProgressSetPos", "cdecl"):
        continue
    lcProgressSetPos = _lib.get("lcProgressSetPos", "cdecl")
    lcProgressSetPos.argtypes = [c_int]
    lcProgressSetPos.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3299
for _lib in _libs.values():
    if not _lib.has("lcProgressInc", "cdecl"):
        continue
    lcProgressInc = _lib.get("lcProgressInc", "cdecl")
    lcProgressInc.argtypes = []
    lcProgressInc.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3300
for _lib in _libs.values():
    if not _lib.has("lcProgressDelete", "cdecl"):
        continue
    lcProgressDelete = _lib.get("lcProgressDelete", "cdecl")
    lcProgressDelete.argtypes = []
    lcProgressDelete.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3303
for _lib in _libs.values():
    if not _lib.has("lcQuadCreate", "cdecl"):
        continue
    lcQuadCreate = _lib.get("lcQuadCreate", "cdecl")
    lcQuadCreate.argtypes = []
    lcQuadCreate.restype = c_void_p
    lcQuadCreate.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3304
for _lib in _libs.values():
    if not _lib.has("lcQuadDelete", "cdecl"):
        continue
    lcQuadDelete = _lib.get("lcQuadDelete", "cdecl")
    lcQuadDelete.argtypes = [c_void_p]
    lcQuadDelete.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3305
for _lib in _libs.values():
    if not _lib.has("lcQuadSet", "cdecl"):
        continue
    lcQuadSet = _lib.get("lcQuadSet", "cdecl")
    lcQuadSet.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcQuadSet.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3307
for _lib in _libs.values():
    if not _lib.has("lcQuadTransXYtoUV", "cdecl"):
        continue
    lcQuadTransXYtoUV = _lib.get("lcQuadTransXYtoUV", "cdecl")
    lcQuadTransXYtoUV.argtypes = [
        c_void_p,
        c_double,
        c_double,
        POINTER(c_double),
        POINTER(c_double),
    ]
    lcQuadTransXYtoUV.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3309
for _lib in _libs.values():
    if not _lib.has("lcQuadTransUVtoXY", "cdecl"):
        continue
    lcQuadTransUVtoXY = _lib.get("lcQuadTransUVtoXY", "cdecl")
    lcQuadTransUVtoXY.argtypes = [
        c_void_p,
        c_double,
        c_double,
        POINTER(c_double),
        POINTER(c_double),
    ]
    lcQuadTransUVtoXY.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3311
for _lib in _libs.values():
    if not _lib.has("lcQuadContains", "cdecl"):
        continue
    lcQuadContains = _lib.get("lcQuadContains", "cdecl")
    lcQuadContains.argtypes = [c_void_p, c_double, c_double]
    lcQuadContains.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3314
for _lib in _libs.values():
    if not _lib.has("lcGridCreate", "cdecl"):
        continue
    lcGridCreate = _lib.get("lcGridCreate", "cdecl")
    lcGridCreate.argtypes = []
    lcGridCreate.restype = c_void_p
    lcGridCreate.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3315
for _lib in _libs.values():
    if not _lib.has("lcGridDelete", "cdecl"):
        continue
    lcGridDelete = _lib.get("lcGridDelete", "cdecl")
    lcGridDelete.argtypes = [c_void_p]
    lcGridDelete.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3316
for _lib in _libs.values():
    if not _lib.has("lcGridSet", "cdecl"):
        continue
    lcGridSet = _lib.get("lcGridSet", "cdecl")
    lcGridSet.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
        c_int,
    ]
    lcGridSet.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3318
for _lib in _libs.values():
    if not _lib.has("lcGridSetDest", "cdecl"):
        continue
    lcGridSetDest = _lib.get("lcGridSetDest", "cdecl")
    lcGridSetDest.argtypes = [c_void_p, c_int, c_int, c_double, c_double]
    lcGridSetDest.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3319
for _lib in _libs.values():
    if not _lib.has("lcGridUpdate", "cdecl"):
        continue
    lcGridUpdate = _lib.get("lcGridUpdate", "cdecl")
    lcGridUpdate.argtypes = [c_void_p]
    lcGridUpdate.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3320
for _lib in _libs.values():
    if not _lib.has("lcGridTrans", "cdecl"):
        continue
    lcGridTrans = _lib.get("lcGridTrans", "cdecl")
    lcGridTrans.argtypes = [
        c_void_p,
        c_double,
        c_double,
        POINTER(c_double),
        POINTER(c_double),
    ]
    lcGridTrans.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3322
for _lib in _libs.values():
    if not _lib.has("lcGridGetNode", "cdecl"):
        continue
    lcGridGetNode = _lib.get("lcGridGetNode", "cdecl")
    lcGridGetNode.argtypes = [
        c_void_p,
        c_int,
        c_int,
        c_int,
        POINTER(c_double),
        POINTER(c_double),
    ]
    lcGridGetNode.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3324
for _lib in _libs.values():
    if not _lib.has("lcGridGetCell", "cdecl"):
        continue
    lcGridGetCell = _lib.get("lcGridGetCell", "cdecl")
    lcGridGetCell.argtypes = [
        c_void_p,
        c_double,
        c_double,
        POINTER(c_int),
        POINTER(c_int),
    ]
    lcGridGetCell.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3326
for _lib in _libs.values():
    if not _lib.has("lcGridSetView", "cdecl"):
        continue
    lcGridSetView = _lib.get("lcGridSetView", "cdecl")
    lcGridSetView.argtypes = [c_void_p, c_int, c_void_p, c_int, c_int]
    lcGridSetView.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3330
for _lib in _libs.values():
    if not _lib.has("lcCreateCmdwin", "cdecl"):
        continue
    lcCreateCmdwin = _lib.get("lcCreateCmdwin", "cdecl")
    lcCreateCmdwin.argtypes = [c_void_p, c_int, c_int, c_int, c_int]
    lcCreateCmdwin.restype = c_void_p
    lcCreateCmdwin.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3332
for _lib in _libs.values():
    if not _lib.has("lcCmdwinResize", "cdecl"):
        continue
    lcCmdwinResize = _lib.get("lcCmdwinResize", "cdecl")
    lcCmdwinResize.argtypes = [c_void_p, c_int, c_int, c_int, c_int]
    lcCmdwinResize.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3334
for _lib in _libs.values():
    if not _lib.has("lcCmdwinUpdate", "cdecl"):
        continue
    lcCmdwinUpdate = _lib.get("lcCmdwinUpdate", "cdecl")
    lcCmdwinUpdate.argtypes = [c_void_p]
    lcCmdwinUpdate.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3337
for _lib in _libs.values():
    if not _lib.has("lcCreateProps", "cdecl"):
        continue
    lcCreateProps = _lib.get("lcCreateProps", "cdecl")
    lcCreateProps.argtypes = [c_void_p, c_int]
    lcCreateProps.restype = c_void_p
    lcCreateProps.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3338
for _lib in _libs.values():
    if not _lib.has("lcDeleteProps", "cdecl"):
        continue
    lcDeleteProps = _lib.get("lcDeleteProps", "cdecl")
    lcDeleteProps.argtypes = [c_void_p]
    lcDeleteProps.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3339
for _lib in _libs.values():
    if not _lib.has("lcPropsResize", "cdecl"):
        continue
    lcPropsResize = _lib.get("lcPropsResize", "cdecl")
    lcPropsResize.argtypes = [c_void_p, c_int, c_int, c_int, c_int]
    lcPropsResize.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3341
for _lib in _libs.values():
    if not _lib.has("lcPropsUpdate", "cdecl"):
        continue
    lcPropsUpdate = _lib.get("lcPropsUpdate", "cdecl")
    lcPropsUpdate.argtypes = [c_void_p, c_int]
    lcPropsUpdate.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3344
for _lib in _libs.values():
    if not _lib.has("lcCreateStatbar", "cdecl"):
        continue
    lcCreateStatbar = _lib.get("lcCreateStatbar", "cdecl")
    lcCreateStatbar.argtypes = [c_void_p]
    lcCreateStatbar.restype = c_void_p
    lcCreateStatbar.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3345
for _lib in _libs.values():
    if not _lib.has("lcDeleteStatbar", "cdecl"):
        continue
    lcDeleteStatbar = _lib.get("lcDeleteStatbar", "cdecl")
    lcDeleteStatbar.argtypes = [c_void_p]
    lcDeleteStatbar.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3346
for _lib in _libs.values():
    if not _lib.has("lcStatbarResize", "cdecl"):
        continue
    lcStatbarResize = _lib.get("lcStatbarResize", "cdecl")
    lcStatbarResize.argtypes = [c_void_p, c_int, c_int, c_int, c_int]
    lcStatbarResize.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3348
for _lib in _libs.values():
    if not _lib.has("lcStatbarCell", "cdecl"):
        continue
    lcStatbarCell = _lib.get("lcStatbarCell", "cdecl")
    lcStatbarCell.argtypes = [c_void_p, c_int, c_int]
    lcStatbarCell.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3349
for _lib in _libs.values():
    if not _lib.has("lcStatbarText", "cdecl"):
        continue
    lcStatbarText = _lib.get("lcStatbarText", "cdecl")
    lcStatbarText.argtypes = [c_void_p, c_int, String]
    lcStatbarText.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3350
for _lib in _libs.values():
    if not _lib.has("lcStatbarRedraw", "cdecl"):
        continue
    lcStatbarRedraw = _lib.get("lcStatbarRedraw", "cdecl")
    lcStatbarRedraw.argtypes = [c_void_p]
    lcStatbarRedraw.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3353
for _lib in _libs.values():
    if not _lib.has("lcDgGetValue", "cdecl"):
        continue
    lcDgGetValue = _lib.get("lcDgGetValue", "cdecl")
    lcDgGetValue.argtypes = [c_void_p, c_int, c_int, String, String]
    lcDgGetValue.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3355
for _lib in _libs.values():
    if not _lib.has("lcHelp", "cdecl"):
        continue
    lcHelp = _lib.get("lcHelp", "cdecl")
    lcHelp.argtypes = [String]
    lcHelp.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3356
for _lib in _libs.values():
    if not _lib.has("lcGetPolarPoint", "cdecl"):
        continue
    lcGetPolarPoint = _lib.get("lcGetPolarPoint", "cdecl")
    lcGetPolarPoint.argtypes = [
        c_double,
        c_double,
        c_double,
        c_double,
        POINTER(c_double),
        POINTER(c_double),
    ]
    lcGetPolarPoint.restype = None
    break

# D:\\projects\\gllc\\litecad.h: 3358
for _lib in _libs.values():
    if not _lib.has("lcGetPolarPrm", "cdecl"):
        continue
    lcGetPolarPrm = _lib.get("lcGetPolarPrm", "cdecl")
    lcGetPolarPrm.argtypes = [
        c_double,
        c_double,
        c_double,
        c_double,
        POINTER(c_double),
        POINTER(c_double),
    ]
    lcGetPolarPrm.restype = None
    break

# D:\\projects\\gllc\\litecad.h: 3360
for _lib in _libs.values():
    if not _lib.has("lcGetClientSize", "cdecl"):
        continue
    lcGetClientSize = _lib.get("lcGetClientSize", "cdecl")
    lcGetClientSize.argtypes = [c_void_p, POINTER(c_int), POINTER(c_int)]
    lcGetClientSize.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3361
for _lib in _libs.values():
    if not _lib.has("lcGetErrorCode", "cdecl"):
        continue
    lcGetErrorCode = _lib.get("lcGetErrorCode", "cdecl")
    lcGetErrorCode.argtypes = []
    lcGetErrorCode.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3362
for _lib in _libs.values():
    if not _lib.has("lcGetErrorStr", "cdecl"):
        continue
    lcGetErrorStr = _lib.get("lcGetErrorStr", "cdecl")
    lcGetErrorStr.argtypes = []
    if sizeof(c_int) == sizeof(c_void_p):
        lcGetErrorStr.restype = ReturnString
    else:
        lcGetErrorStr.restype = String
        lcGetErrorStr.errcheck = ReturnString
    break

# D:\\projects\\gllc\\litecad.h: 3363
for _lib in _libs.values():
    if not _lib.has("lcGetStr", "cdecl"):
        continue
    lcGetStr = _lib.get("lcGetStr", "cdecl")
    lcGetStr.argtypes = [c_int]
    lcGetStr.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3364
for _lib in _libs.values():
    if not _lib.has("lcGetDrwXData", "cdecl"):
        continue
    lcGetDrwXData = _lib.get("lcGetDrwXData", "cdecl")
    lcGetDrwXData.argtypes = [String]
    lcGetDrwXData.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3365
for _lib in _libs.values():
    if not _lib.has("lcGetDrwPreview", "cdecl"):
        continue
    lcGetDrwPreview = _lib.get("lcGetDrwPreview", "cdecl")
    lcGetDrwPreview.argtypes = [String, c_void_p]
    lcGetDrwPreview.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3366
for _lib in _libs.values():
    if not _lib.has("lcFilletSetLines", "cdecl"):
        continue
    lcFilletSetLines = _lib.get("lcFilletSetLines", "cdecl")
    lcFilletSetLines.argtypes = [
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcFilletSetLines.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3368
for _lib in _libs.values():
    if not _lib.has("lcFillet", "cdecl"):
        continue
    lcFillet = _lib.get("lcFillet", "cdecl")
    lcFillet.argtypes = [c_double, c_double, c_double]
    lcFillet.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3369
for _lib in _libs.values():
    if not _lib.has("lcFilletGetPoint", "cdecl"):
        continue
    lcFilletGetPoint = _lib.get("lcFilletGetPoint", "cdecl")
    lcFilletGetPoint.argtypes = [c_int, POINTER(c_double), POINTER(c_double)]
    lcFilletGetPoint.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3370
for _lib in _libs.values():
    if not _lib.has("lcFileToStrA", "cdecl"):
        continue
    lcFileToStrA = _lib.get("lcFileToStrA", "cdecl")
    lcFileToStrA.argtypes = [String, String]
    lcFileToStrA.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3373
for _lib in _libs.values():
    if not _lib.has("lcCreateCommand", "cdecl"):
        continue
    lcCreateCommand = _lib.get("lcCreateCommand", "cdecl")
    lcCreateCommand.argtypes = [c_void_p, c_int, String]
    lcCreateCommand.restype = c_void_p
    lcCreateCommand.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3374
for _lib in _libs.values():
    if not _lib.has("lcCmdExit", "cdecl"):
        continue
    lcCmdExit = _lib.get("lcCmdExit", "cdecl")
    lcCmdExit.argtypes = [c_void_p]
    lcCmdExit.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3375
for _lib in _libs.values():
    if not _lib.has("lcCmdCursorText", "cdecl"):
        continue
    lcCmdCursorText = _lib.get("lcCmdCursorText", "cdecl")
    lcCmdCursorText.argtypes = [c_void_p, String]
    lcCmdCursorText.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3376
for _lib in _libs.values():
    if not _lib.has("lcCmdMessage", "cdecl"):
        continue
    lcCmdMessage = _lib.get("lcCmdMessage", "cdecl")
    lcCmdMessage.argtypes = [c_void_p, String, c_int]
    lcCmdMessage.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3377
for _lib in _libs.values():
    if not _lib.has("lcCmdResetLastPt", "cdecl"):
        continue
    lcCmdResetLastPt = _lib.get("lcCmdResetLastPt", "cdecl")
    lcCmdResetLastPt.argtypes = [c_void_p]
    lcCmdResetLastPt.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3379
for _lib in _libs.values():
    if not _lib.has("lcTIS_InitLibrary", "cdecl"):
        continue
    lcTIS_InitLibrary = _lib.get("lcTIS_InitLibrary", "cdecl")
    lcTIS_InitLibrary.argtypes = [String, c_int]
    lcTIS_InitLibrary.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3380
for _lib in _libs.values():
    if not _lib.has("lcTIS_CloseLibrary", "cdecl"):
        continue
    lcTIS_CloseLibrary = _lib.get("lcTIS_CloseLibrary", "cdecl")
    lcTIS_CloseLibrary.argtypes = []
    lcTIS_CloseLibrary.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3381
for _lib in _libs.values():
    if not _lib.has("lcCameraConnect", "cdecl"):
        continue
    lcCameraConnect = _lib.get("lcCameraConnect", "cdecl")
    lcCameraConnect.argtypes = [String]
    lcCameraConnect.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3382
for _lib in _libs.values():
    if not _lib.has("lcCameraDisconnect", "cdecl"):
        continue
    lcCameraDisconnect = _lib.get("lcCameraDisconnect", "cdecl")
    lcCameraDisconnect.argtypes = []
    lcCameraDisconnect.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3383
for _lib in _libs.values():
    if not _lib.has("lcCameraShot", "cdecl"):
        continue
    lcCameraShot = _lib.get("lcCameraShot", "cdecl")
    lcCameraShot.argtypes = []
    lcCameraShot.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3388
for _lib in _libs.values():
    if not _lib.has("lcCreateDrawing", "cdecl"):
        continue
    lcCreateDrawing = _lib.get("lcCreateDrawing", "cdecl")
    lcCreateDrawing.argtypes = []
    lcCreateDrawing.restype = c_void_p
    lcCreateDrawing.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3389
for _lib in _libs.values():
    if not _lib.has("lcDeleteDrawing", "cdecl"):
        continue
    lcDeleteDrawing = _lib.get("lcDeleteDrawing", "cdecl")
    lcDeleteDrawing.argtypes = [c_void_p]
    lcDeleteDrawing.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3390
for _lib in _libs.values():
    if not _lib.has("lcDrwNew", "cdecl"):
        continue
    lcDrwNew = _lib.get("lcDrwNew", "cdecl")
    lcDrwNew.argtypes = [c_void_p, String, c_void_p]
    lcDrwNew.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3391
for _lib in _libs.values():
    if not _lib.has("lcDrwLoad", "cdecl"):
        continue
    lcDrwLoad = _lib.get("lcDrwLoad", "cdecl")
    lcDrwLoad.argtypes = [c_void_p, String, c_void_p]
    lcDrwLoad.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3392
for _lib in _libs.values():
    if not _lib.has("lcDrwLoadMem", "cdecl"):
        continue
    lcDrwLoadMem = _lib.get("lcDrwLoadMem", "cdecl")
    lcDrwLoadMem.argtypes = [c_void_p, c_void_p, c_void_p]
    lcDrwLoadMem.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3393
for _lib in _libs.values():
    if not _lib.has("lcDxfLoadMem", "cdecl"):
        continue
    lcDxfLoadMem = _lib.get("lcDxfLoadMem", "cdecl")
    lcDxfLoadMem.argtypes = [c_void_p, c_void_p, c_void_p]
    lcDxfLoadMem.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3394
for _lib in _libs.values():
    if not _lib.has("lcDrwLoadTIN", "cdecl"):
        continue
    lcDrwLoadTIN = _lib.get("lcDrwLoadTIN", "cdecl")
    lcDrwLoadTIN.argtypes = [c_void_p, String, c_void_p]
    lcDrwLoadTIN.restype = c_void_p
    lcDrwLoadTIN.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3395
for _lib in _libs.values():
    if not _lib.has("lcDrwSaveTIN", "cdecl"):
        continue
    lcDrwSaveTIN = _lib.get("lcDrwSaveTIN", "cdecl")
    lcDrwSaveTIN.argtypes = [c_void_p, c_void_p]
    lcDrwSaveTIN.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3396
for _lib in _libs.values():
    if not _lib.has("lcDrwInsert", "cdecl"):
        continue
    lcDrwInsert = _lib.get("lcDrwInsert", "cdecl")
    lcDrwInsert.argtypes = [c_void_p, String, c_int, c_void_p]
    lcDrwInsert.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3398
for _lib in _libs.values():
    if not _lib.has("lcDrwInsertSHP", "cdecl"):
        continue
    lcDrwInsertSHP = _lib.get("lcDrwInsertSHP", "cdecl")
    lcDrwInsertSHP.argtypes = [c_void_p, c_void_p, String, c_void_p]
    lcDrwInsertSHP.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3400
for _lib in _libs.values():
    if not _lib.has("lcDrwCopy", "cdecl"):
        continue
    lcDrwCopy = _lib.get("lcDrwCopy", "cdecl")
    lcDrwCopy.argtypes = [c_void_p, c_void_p]
    lcDrwCopy.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3401
for _lib in _libs.values():
    if not _lib.has("lcDrwSave", "cdecl"):
        continue
    lcDrwSave = _lib.get("lcDrwSave", "cdecl")
    lcDrwSave.argtypes = [c_void_p, String, c_int, c_void_p]
    lcDrwSave.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3402
for _lib in _libs.values():
    if not _lib.has("lcDrwSaveMem", "cdecl"):
        continue
    lcDrwSaveMem = _lib.get("lcDrwSaveMem", "cdecl")
    lcDrwSaveMem.argtypes = [c_void_p, c_void_p, c_int]
    lcDrwSaveMem.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3404
for _lib in _libs.values():
    if not _lib.has("lcDrwAddLayer", "cdecl"):
        continue
    lcDrwAddLayer = _lib.get("lcDrwAddLayer", "cdecl")
    lcDrwAddLayer.argtypes = [c_void_p, String, String, c_void_p, c_int]
    lcDrwAddLayer.restype = c_void_p
    lcDrwAddLayer.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3406
for _lib in _libs.values():
    if not _lib.has("lcDrwAddLayer2", "cdecl"):
        continue
    lcDrwAddLayer2 = _lib.get("lcDrwAddLayer2", "cdecl")
    lcDrwAddLayer2.argtypes = [c_void_p, String, c_void_p]
    lcDrwAddLayer2.restype = c_void_p
    lcDrwAddLayer2.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3407
for _lib in _libs.values():
    if not _lib.has("lcDrwAddLinetype", "cdecl"):
        continue
    lcDrwAddLinetype = _lib.get("lcDrwAddLinetype", "cdecl")
    lcDrwAddLinetype.argtypes = [c_void_p, String, String]
    lcDrwAddLinetype.restype = c_void_p
    lcDrwAddLinetype.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3408
for _lib in _libs.values():
    if not _lib.has("lcDrwAddLinetypeF", "cdecl"):
        continue
    lcDrwAddLinetypeF = _lib.get("lcDrwAddLinetypeF", "cdecl")
    lcDrwAddLinetypeF.argtypes = [c_void_p, String, String, String]
    lcDrwAddLinetypeF.restype = c_void_p
    lcDrwAddLinetypeF.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3410
for _lib in _libs.values():
    if not _lib.has("lcDrwAddTextStyle", "cdecl"):
        continue
    lcDrwAddTextStyle = _lib.get("lcDrwAddTextStyle", "cdecl")
    lcDrwAddTextStyle.argtypes = [c_void_p, String, String, c_int]
    lcDrwAddTextStyle.restype = c_void_p
    lcDrwAddTextStyle.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3412
for _lib in _libs.values():
    if not _lib.has("lcDrwAddDimStyle", "cdecl"):
        continue
    lcDrwAddDimStyle = _lib.get("lcDrwAddDimStyle", "cdecl")
    lcDrwAddDimStyle.argtypes = [c_void_p, String]
    lcDrwAddDimStyle.restype = c_void_p
    lcDrwAddDimStyle.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3413
for _lib in _libs.values():
    if not _lib.has("lcDrwAddMlineStyle", "cdecl"):
        continue
    lcDrwAddMlineStyle = _lib.get("lcDrwAddMlineStyle", "cdecl")
    lcDrwAddMlineStyle.argtypes = [c_void_p, String]
    lcDrwAddMlineStyle.restype = c_void_p
    lcDrwAddMlineStyle.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3414
for _lib in _libs.values():
    if not _lib.has("lcDrwAddPntStyle", "cdecl"):
        continue
    lcDrwAddPntStyle = _lib.get("lcDrwAddPntStyle", "cdecl")
    lcDrwAddPntStyle.argtypes = [
        c_void_p,
        String,
        c_void_p,
        c_double,
        c_void_p,
        c_double,
        c_double,
    ]
    lcDrwAddPntStyle.restype = c_void_p
    lcDrwAddPntStyle.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3417
for _lib in _libs.values():
    if not _lib.has("lcDrwAddFilling", "cdecl"):
        continue
    lcDrwAddFilling = _lib.get("lcDrwAddFilling", "cdecl")
    lcDrwAddFilling.argtypes = [c_void_p, String]
    lcDrwAddFilling.restype = c_void_p
    lcDrwAddFilling.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3418
for _lib in _libs.values():
    if not _lib.has("lcDrwAddImage", "cdecl"):
        continue
    lcDrwAddImage = _lib.get("lcDrwAddImage", "cdecl")
    lcDrwAddImage.argtypes = [c_void_p, String, String]
    lcDrwAddImage.restype = c_void_p
    lcDrwAddImage.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3419
for _lib in _libs.values():
    if not _lib.has("lcDrwAddImage2", "cdecl"):
        continue
    lcDrwAddImage2 = _lib.get("lcDrwAddImage2", "cdecl")
    lcDrwAddImage2.argtypes = [
        c_void_p,
        String,
        c_int,
        c_int,
        c_int,
        c_void_p,
        c_int,
    ]
    lcDrwAddImage2.restype = c_void_p
    lcDrwAddImage2.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3421
for _lib in _libs.values():
    if not _lib.has("lcDrwAddImage3", "cdecl"):
        continue
    lcDrwAddImage3 = _lib.get("lcDrwAddImage3", "cdecl")
    lcDrwAddImage3.argtypes = [c_void_p, String, c_void_p]
    lcDrwAddImage3.restype = c_void_p
    lcDrwAddImage3.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3422
for _lib in _libs.values():
    if not _lib.has("lcDrwAddImageCam", "cdecl"):
        continue
    lcDrwAddImageCam = _lib.get("lcDrwAddImageCam", "cdecl")
    lcDrwAddImageCam.argtypes = [c_void_p, String]
    lcDrwAddImageCam.restype = c_void_p
    lcDrwAddImageCam.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3423
for _lib in _libs.values():
    if not _lib.has("lcDrwAddBlock", "cdecl"):
        continue
    lcDrwAddBlock = _lib.get("lcDrwAddBlock", "cdecl")
    lcDrwAddBlock.argtypes = [c_void_p, String, c_double, c_double]
    lcDrwAddBlock.restype = c_void_p
    lcDrwAddBlock.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3424
for _lib in _libs.values():
    if not _lib.has("lcDrwAddBlockFromFile", "cdecl"):
        continue
    lcDrwAddBlockFromFile = _lib.get("lcDrwAddBlockFromFile", "cdecl")
    lcDrwAddBlockFromFile.argtypes = [
        c_void_p,
        String,
        String,
        c_int,
        c_void_p,
    ]
    lcDrwAddBlockFromFile.restype = c_void_p
    lcDrwAddBlockFromFile.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3426
for _lib in _libs.values():
    if not _lib.has("lcDrwAddBlockFromDrw", "cdecl"):
        continue
    lcDrwAddBlockFromDrw = _lib.get("lcDrwAddBlockFromDrw", "cdecl")
    lcDrwAddBlockFromDrw.argtypes = [
        c_void_p,
        String,
        c_void_p,
        c_int,
        c_void_p,
    ]
    lcDrwAddBlockFromDrw.restype = c_void_p
    lcDrwAddBlockFromDrw.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3428
for _lib in _libs.values():
    if not _lib.has("lcDrwAddBlockFile", "cdecl"):
        continue
    lcDrwAddBlockFile = _lib.get("lcDrwAddBlockFile", "cdecl")
    lcDrwAddBlockFile.argtypes = [c_void_p, String, String, c_int, c_void_p]
    lcDrwAddBlockFile.restype = c_void_p
    lcDrwAddBlockFile.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3430
for _lib in _libs.values():
    if not _lib.has("lcDrwAddBlockPaper", "cdecl"):
        continue
    lcDrwAddBlockPaper = _lib.get("lcDrwAddBlockPaper", "cdecl")
    lcDrwAddBlockPaper.argtypes = [
        c_void_p,
        String,
        c_int,
        c_int,
        c_double,
        c_double,
    ]
    lcDrwAddBlockPaper.restype = c_void_p
    lcDrwAddBlockPaper.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3432
for _lib in _libs.values():
    if not _lib.has("lcDrwAddBlockCopy", "cdecl"):
        continue
    lcDrwAddBlockCopy = _lib.get("lcDrwAddBlockCopy", "cdecl")
    lcDrwAddBlockCopy.argtypes = [c_void_p, String, c_void_p]
    lcDrwAddBlockCopy.restype = c_void_p
    lcDrwAddBlockCopy.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3434
for _lib in _libs.values():
    if not _lib.has("lcDrwDeleteObject", "cdecl"):
        continue
    lcDrwDeleteObject = _lib.get("lcDrwDeleteObject", "cdecl")
    lcDrwDeleteObject.argtypes = [c_void_p, c_void_p]
    lcDrwDeleteObject.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3435
for _lib in _libs.values():
    if not _lib.has("lcDrwDeleteUnused", "cdecl"):
        continue
    lcDrwDeleteUnused = _lib.get("lcDrwDeleteUnused", "cdecl")
    lcDrwDeleteUnused.argtypes = [c_void_p, c_int]
    lcDrwDeleteUnused.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3436
for _lib in _libs.values():
    if not _lib.has("lcDrwCountObjects", "cdecl"):
        continue
    lcDrwCountObjects = _lib.get("lcDrwCountObjects", "cdecl")
    lcDrwCountObjects.argtypes = [c_void_p, c_int]
    lcDrwCountObjects.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3437
for _lib in _libs.values():
    if not _lib.has("lcDrwSortObjects", "cdecl"):
        continue
    lcDrwSortObjects = _lib.get("lcDrwSortObjects", "cdecl")
    lcDrwSortObjects.argtypes = [c_void_p, c_int]
    lcDrwSortObjects.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3438
for _lib in _libs.values():
    if not _lib.has("lcDrwUpdateWinFonts", "cdecl"):
        continue
    lcDrwUpdateWinFonts = _lib.get("lcDrwUpdateWinFonts", "cdecl")
    lcDrwUpdateWinFonts.argtypes = [c_void_p, c_void_p]
    lcDrwUpdateWinFonts.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3439
for _lib in _libs.values():
    if not _lib.has("lcDrwUpdateBlkRefs", "cdecl"):
        continue
    lcDrwUpdateBlkRefs = _lib.get("lcDrwUpdateBlkRefs", "cdecl")
    lcDrwUpdateBlkRefs.argtypes = [c_void_p, c_void_p]
    lcDrwUpdateBlkRefs.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3440
for _lib in _libs.values():
    if not _lib.has("lcDrwUpdateTexts", "cdecl"):
        continue
    lcDrwUpdateTexts = _lib.get("lcDrwUpdateTexts", "cdecl")
    lcDrwUpdateTexts.argtypes = [c_void_p, c_void_p]
    lcDrwUpdateTexts.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3442
for _lib in _libs.values():
    if not _lib.has("lcDrwGetFirstObject", "cdecl"):
        continue
    lcDrwGetFirstObject = _lib.get("lcDrwGetFirstObject", "cdecl")
    lcDrwGetFirstObject.argtypes = [c_void_p, c_int]
    lcDrwGetFirstObject.restype = c_void_p
    lcDrwGetFirstObject.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3443
for _lib in _libs.values():
    if not _lib.has("lcDrwGetNextObject", "cdecl"):
        continue
    lcDrwGetNextObject = _lib.get("lcDrwGetNextObject", "cdecl")
    lcDrwGetNextObject.argtypes = [c_void_p, c_void_p]
    lcDrwGetNextObject.restype = c_void_p
    lcDrwGetNextObject.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3444
for _lib in _libs.values():
    if not _lib.has("lcDrwGetObjectByID", "cdecl"):
        continue
    lcDrwGetObjectByID = _lib.get("lcDrwGetObjectByID", "cdecl")
    lcDrwGetObjectByID.argtypes = [c_void_p, c_int, c_int]
    lcDrwGetObjectByID.restype = c_void_p
    lcDrwGetObjectByID.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3445
for _lib in _libs.values():
    if not _lib.has("lcDrwGetObjectByIDH", "cdecl"):
        continue
    lcDrwGetObjectByIDH = _lib.get("lcDrwGetObjectByIDH", "cdecl")
    lcDrwGetObjectByIDH.argtypes = [c_void_p, c_int, String]
    lcDrwGetObjectByIDH.restype = c_void_p
    lcDrwGetObjectByIDH.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3446
for _lib in _libs.values():
    if not _lib.has("lcDrwGetObjectByName", "cdecl"):
        continue
    lcDrwGetObjectByName = _lib.get("lcDrwGetObjectByName", "cdecl")
    lcDrwGetObjectByName.argtypes = [c_void_p, c_int, String]
    lcDrwGetObjectByName.restype = c_void_p
    lcDrwGetObjectByName.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3447
for _lib in _libs.values():
    if not _lib.has("lcDrwGetEntByID", "cdecl"):
        continue
    lcDrwGetEntByID = _lib.get("lcDrwGetEntByID", "cdecl")
    lcDrwGetEntByID.argtypes = [c_void_p, c_int]
    lcDrwGetEntByID.restype = c_void_p
    lcDrwGetEntByID.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3448
for _lib in _libs.values():
    if not _lib.has("lcDrwGetEntByIDH", "cdecl"):
        continue
    lcDrwGetEntByIDH = _lib.get("lcDrwGetEntByIDH", "cdecl")
    lcDrwGetEntByIDH.argtypes = [c_void_p, String]
    lcDrwGetEntByIDH.restype = c_void_p
    lcDrwGetEntByIDH.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3449
for _lib in _libs.values():
    if not _lib.has("lcDrwGetEntByKey", "cdecl"):
        continue
    lcDrwGetEntByKey = _lib.get("lcDrwGetEntByKey", "cdecl")
    lcDrwGetEntByKey.argtypes = [c_void_p, c_int]
    lcDrwGetEntByKey.restype = c_void_p
    lcDrwGetEntByKey.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3451
for _lib in _libs.values():
    if not _lib.has("lcDrwClearXData", "cdecl"):
        continue
    lcDrwClearXData = _lib.get("lcDrwClearXData", "cdecl")
    lcDrwClearXData.argtypes = [c_void_p, c_int, c_int]
    lcDrwClearXData.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3452
for _lib in _libs.values():
    if not _lib.has("lcDrwPurge", "cdecl"):
        continue
    lcDrwPurge = _lib.get("lcDrwPurge", "cdecl")
    lcDrwPurge.argtypes = [c_void_p]
    lcDrwPurge.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3453
for _lib in _libs.values():
    if not _lib.has("lcDrwExplode", "cdecl"):
        continue
    lcDrwExplode = _lib.get("lcDrwExplode", "cdecl")
    lcDrwExplode.argtypes = [c_void_p, c_int]
    lcDrwExplode.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3454
for _lib in _libs.values():
    if not _lib.has("lcDrwSetLimits", "cdecl"):
        continue
    lcDrwSetLimits = _lib.get("lcDrwSetLimits", "cdecl")
    lcDrwSetLimits.argtypes = [c_void_p, c_double, c_double, c_double, c_double]
    lcDrwSetLimits.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3457
for _lib in _libs.values():
    if not _lib.has("lcDrwUndoRecord", "cdecl"):
        continue
    lcDrwUndoRecord = _lib.get("lcDrwUndoRecord", "cdecl")
    lcDrwUndoRecord.argtypes = [c_void_p, c_int]
    lcDrwUndoRecord.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3458
for _lib in _libs.values():
    if not _lib.has("lcDrwUndo", "cdecl"):
        continue
    lcDrwUndo = _lib.get("lcDrwUndo", "cdecl")
    lcDrwUndo.argtypes = [c_void_p, c_int]
    lcDrwUndo.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3461
for _lib in _libs.values():
    if not _lib.has("lcCRectsClear", "cdecl"):
        continue
    lcCRectsClear = _lib.get("lcCRectsClear", "cdecl")
    lcCRectsClear.argtypes = [c_void_p]
    lcCRectsClear.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3462
for _lib in _libs.values():
    if not _lib.has("lcCRectsAdd", "cdecl"):
        continue
    lcCRectsAdd = _lib.get("lcCRectsAdd", "cdecl")
    lcCRectsAdd.argtypes = [
        c_void_p,
        c_int,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcCRectsAdd.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3464
for _lib in _libs.values():
    if not _lib.has("lcCRectsDivide", "cdecl"):
        continue
    lcCRectsDivide = _lib.get("lcCRectsDivide", "cdecl")
    lcCRectsDivide.argtypes = [c_void_p, c_int, c_int, c_int]
    lcCRectsDivide.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3465
for _lib in _libs.values():
    if not _lib.has("lcCRectsGetFirst", "cdecl"):
        continue
    lcCRectsGetFirst = _lib.get("lcCRectsGetFirst", "cdecl")
    lcCRectsGetFirst.argtypes = [c_void_p]
    lcCRectsGetFirst.restype = c_void_p
    lcCRectsGetFirst.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3466
for _lib in _libs.values():
    if not _lib.has("lcCRectsGetNext", "cdecl"):
        continue
    lcCRectsGetNext = _lib.get("lcCRectsGetNext", "cdecl")
    lcCRectsGetNext.argtypes = [c_void_p, c_void_p]
    lcCRectsGetNext.restype = c_void_p
    lcCRectsGetNext.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3467
for _lib in _libs.values():
    if not _lib.has("lcCRectsGetWithID", "cdecl"):
        continue
    lcCRectsGetWithID = _lib.get("lcCRectsGetWithID", "cdecl")
    lcCRectsGetWithID.argtypes = [c_void_p, c_int]
    lcCRectsGetWithID.restype = c_void_p
    lcCRectsGetWithID.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3468
for _lib in _libs.values():
    if not _lib.has("lcCRectsActive", "cdecl"):
        continue
    lcCRectsActive = _lib.get("lcCRectsActive", "cdecl")
    lcCRectsActive.argtypes = [c_void_p, c_void_p]
    lcCRectsActive.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3469
for _lib in _libs.values():
    if not _lib.has("lcCRectsGetActive", "cdecl"):
        continue
    lcCRectsGetActive = _lib.get("lcCRectsGetActive", "cdecl")
    lcCRectsGetActive.argtypes = [c_void_p]
    lcCRectsGetActive.restype = c_void_p
    lcCRectsGetActive.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3470
for _lib in _libs.values():
    if not _lib.has("lcCRectsDelete", "cdecl"):
        continue
    lcCRectsDelete = _lib.get("lcCRectsDelete", "cdecl")
    lcCRectsDelete.argtypes = [c_void_p, c_void_p]
    lcCRectsDelete.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3471
for _lib in _libs.values():
    if not _lib.has("lcCRectsSave", "cdecl"):
        continue
    lcCRectsSave = _lib.get("lcCRectsSave", "cdecl")
    lcCRectsSave.argtypes = [c_void_p, c_void_p, String]
    lcCRectsSave.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3472
for _lib in _libs.values():
    if not _lib.has("lcCRectsBitmap", "cdecl"):
        continue
    lcCRectsBitmap = _lib.get("lcCRectsBitmap", "cdecl")
    lcCRectsBitmap.argtypes = [c_void_p, c_void_p, String, c_double]
    lcCRectsBitmap.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3476
for _lib in _libs.values():
    if not _lib.has("lcBlockSetViewRect", "cdecl"):
        continue
    lcBlockSetViewRect = _lib.get("lcBlockSetViewRect", "cdecl")
    lcBlockSetViewRect.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcBlockSetViewRect.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3478
for _lib in _libs.values():
    if not _lib.has("lcBlockSetViewRect2", "cdecl"):
        continue
    lcBlockSetViewRect2 = _lib.get("lcBlockSetViewRect2", "cdecl")
    lcBlockSetViewRect2.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcBlockSetViewRect2.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3480
for _lib in _libs.values():
    if not _lib.has("lcBlockSetPaperSize", "cdecl"):
        continue
    lcBlockSetPaperSize = _lib.get("lcBlockSetPaperSize", "cdecl")
    lcBlockSetPaperSize.argtypes = [c_void_p, c_int, c_int, c_double, c_double]
    lcBlockSetPaperSize.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3482
for _lib in _libs.values():
    if not _lib.has("lcBlockRasterize", "cdecl"):
        continue
    lcBlockRasterize = _lib.get("lcBlockRasterize", "cdecl")
    lcBlockRasterize.argtypes = [
        c_void_p,
        String,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
        c_int,
    ]
    lcBlockRasterize.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3485
for _lib in _libs.values():
    if not _lib.has("lcBlockRasterizeMem", "cdecl"):
        continue
    lcBlockRasterizeMem = _lib.get("lcBlockRasterizeMem", "cdecl")
    lcBlockRasterizeMem.argtypes = [
        c_void_p,
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
        c_int,
    ]
    lcBlockRasterizeMem.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3488
for _lib in _libs.values():
    if not _lib.has("lcBlockUpdate", "cdecl"):
        continue
    lcBlockUpdate = _lib.get("lcBlockUpdate", "cdecl")
    lcBlockUpdate.argtypes = [c_void_p, c_int, c_void_p]
    lcBlockUpdate.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3489
for _lib in _libs.values():
    if not _lib.has("lcBlockMove", "cdecl"):
        continue
    lcBlockMove = _lib.get("lcBlockMove", "cdecl")
    lcBlockMove.argtypes = [c_void_p, c_double, c_double, c_int]
    lcBlockMove.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3490
for _lib in _libs.values():
    if not _lib.has("lcBlockScale", "cdecl"):
        continue
    lcBlockScale = _lib.get("lcBlockScale", "cdecl")
    lcBlockScale.argtypes = [c_void_p, c_double, c_double, c_double, c_int]
    lcBlockScale.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3492
for _lib in _libs.values():
    if not _lib.has("lcBlockRotate", "cdecl"):
        continue
    lcBlockRotate = _lib.get("lcBlockRotate", "cdecl")
    lcBlockRotate.argtypes = [c_void_p, c_double, c_double, c_double, c_int]
    lcBlockRotate.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3494
for _lib in _libs.values():
    if not _lib.has("lcBlockMirror", "cdecl"):
        continue
    lcBlockMirror = _lib.get("lcBlockMirror", "cdecl")
    lcBlockMirror.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
    ]
    lcBlockMirror.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3498
for _lib in _libs.values():
    if not _lib.has("lcBlockClear", "cdecl"):
        continue
    lcBlockClear = _lib.get("lcBlockClear", "cdecl")
    lcBlockClear.argtypes = [c_void_p, c_void_p]
    lcBlockClear.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3499
for _lib in _libs.values():
    if not _lib.has("lcBlockPurge", "cdecl"):
        continue
    lcBlockPurge = _lib.get("lcBlockPurge", "cdecl")
    lcBlockPurge.argtypes = [c_void_p]
    lcBlockPurge.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3500
for _lib in _libs.values():
    if not _lib.has("lcBlockSortEnts", "cdecl"):
        continue
    lcBlockSortEnts = _lib.get("lcBlockSortEnts", "cdecl")
    lcBlockSortEnts.argtypes = [c_void_p, c_int, c_void_p]
    lcBlockSortEnts.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3501
for _lib in _libs.values():
    if not _lib.has("lcBlockSortEnts2", "cdecl"):
        continue
    lcBlockSortEnts2 = _lib.get("lcBlockSortEnts2", "cdecl")
    lcBlockSortEnts2.argtypes = [c_void_p, c_void_p, c_int]
    lcBlockSortEnts2.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3503
for _lib in _libs.values():
    if not _lib.has("lcBlockAddPoint", "cdecl"):
        continue
    lcBlockAddPoint = _lib.get("lcBlockAddPoint", "cdecl")
    lcBlockAddPoint.argtypes = [c_void_p, c_double, c_double]
    lcBlockAddPoint.restype = c_void_p
    lcBlockAddPoint.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3504
for _lib in _libs.values():
    if not _lib.has("lcBlockAddPoint2", "cdecl"):
        continue
    lcBlockAddPoint2 = _lib.get("lcBlockAddPoint2", "cdecl")
    lcBlockAddPoint2.argtypes = [c_void_p, c_double, c_double, c_int, c_double]
    lcBlockAddPoint2.restype = c_void_p
    lcBlockAddPoint2.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3506
for _lib in _libs.values():
    if not _lib.has("lcBlockAddPoint3d", "cdecl"):
        continue
    lcBlockAddPoint3d = _lib.get("lcBlockAddPoint3d", "cdecl")
    lcBlockAddPoint3d.argtypes = [c_void_p, c_double, c_double, c_double]
    lcBlockAddPoint3d.restype = c_void_p
    lcBlockAddPoint3d.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3507
for _lib in _libs.values():
    if not _lib.has("lcBlockAddPointsF", "cdecl"):
        continue
    lcBlockAddPointsF = _lib.get("lcBlockAddPointsF", "cdecl")
    lcBlockAddPointsF.argtypes = [c_void_p, String, c_void_p]
    lcBlockAddPointsF.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3508
for _lib in _libs.values():
    if not _lib.has("lcBlockAddXline", "cdecl"):
        continue
    lcBlockAddXline = _lib.get("lcBlockAddXline", "cdecl")
    lcBlockAddXline.argtypes = [c_void_p, c_double, c_double, c_double, c_int]
    lcBlockAddXline.restype = c_void_p
    lcBlockAddXline.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3510
for _lib in _libs.values():
    if not _lib.has("lcBlockAddXline2P", "cdecl"):
        continue
    lcBlockAddXline2P = _lib.get("lcBlockAddXline2P", "cdecl")
    lcBlockAddXline2P.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
    ]
    lcBlockAddXline2P.restype = c_void_p
    lcBlockAddXline2P.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3512
for _lib in _libs.values():
    if not _lib.has("lcBlockAddLine", "cdecl"):
        continue
    lcBlockAddLine = _lib.get("lcBlockAddLine", "cdecl")
    lcBlockAddLine.argtypes = [c_void_p, c_double, c_double, c_double, c_double]
    lcBlockAddLine.restype = c_void_p
    lcBlockAddLine.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3514
for _lib in _libs.values():
    if not _lib.has("lcBlockAddLineDir", "cdecl"):
        continue
    lcBlockAddLineDir = _lib.get("lcBlockAddLineDir", "cdecl")
    lcBlockAddLineDir.argtypes = [c_void_p, c_double, c_double, c_double, c_double]
    lcBlockAddLineDir.restype = c_void_p
    lcBlockAddLineDir.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3516
for _lib in _libs.values():
    if not _lib.has("lcBlockAddLineTan", "cdecl"):
        continue
    lcBlockAddLineTan = _lib.get("lcBlockAddLineTan", "cdecl")
    lcBlockAddLineTan.argtypes = [c_void_p, c_void_p, c_void_p, c_int]
    lcBlockAddLineTan.restype = c_void_p
    lcBlockAddLineTan.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3517
for _lib in _libs.values():
    if not _lib.has("lcBlockAddPolyline", "cdecl"):
        continue
    lcBlockAddPolyline = _lib.get("lcBlockAddPolyline", "cdecl")
    lcBlockAddPolyline.argtypes = [c_void_p, c_int, c_int, c_int]
    lcBlockAddPolyline.restype = c_void_p
    lcBlockAddPolyline.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3519
for _lib in _libs.values():
    if not _lib.has("lcBlockAddRPolygon", "cdecl"):
        continue
    lcBlockAddRPolygon = _lib.get("lcBlockAddRPolygon", "cdecl")
    lcBlockAddRPolygon.argtypes = [
        c_void_p,
        c_int,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
        c_int,
    ]
    lcBlockAddRPolygon.restype = c_void_p
    lcBlockAddRPolygon.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3522
for _lib in _libs.values():
    if not _lib.has("lcBlockAddSpline", "cdecl"):
        continue
    lcBlockAddSpline = _lib.get("lcBlockAddSpline", "cdecl")
    lcBlockAddSpline.argtypes = [c_void_p, c_int, c_int]
    lcBlockAddSpline.restype = c_void_p
    lcBlockAddSpline.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3523
for _lib in _libs.values():
    if not _lib.has("lcBlockAddBezier", "cdecl"):
        continue
    lcBlockAddBezier = _lib.get("lcBlockAddBezier", "cdecl")
    lcBlockAddBezier.argtypes = [c_void_p]
    lcBlockAddBezier.restype = c_void_p
    lcBlockAddBezier.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3524
for _lib in _libs.values():
    if not _lib.has("lcBlockAddMline", "cdecl"):
        continue
    lcBlockAddMline = _lib.get("lcBlockAddMline", "cdecl")
    lcBlockAddMline.argtypes = [c_void_p, c_int, c_int]
    lcBlockAddMline.restype = c_void_p
    lcBlockAddMline.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3525
for _lib in _libs.values():
    if not _lib.has("lcBlockAddRect", "cdecl"):
        continue
    lcBlockAddRect = _lib.get("lcBlockAddRect", "cdecl")
    lcBlockAddRect.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
    ]
    lcBlockAddRect.restype = c_void_p
    lcBlockAddRect.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3527
for _lib in _libs.values():
    if not _lib.has("lcBlockAddRect2", "cdecl"):
        continue
    lcBlockAddRect2 = _lib.get("lcBlockAddRect2", "cdecl")
    lcBlockAddRect2.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
    ]
    lcBlockAddRect2.restype = c_void_p
    lcBlockAddRect2.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3530
for _lib in _libs.values():
    if not _lib.has("lcBlockAddCircle", "cdecl"):
        continue
    lcBlockAddCircle = _lib.get("lcBlockAddCircle", "cdecl")
    lcBlockAddCircle.argtypes = [c_void_p, c_double, c_double, c_double, c_int]
    lcBlockAddCircle.restype = c_void_p
    lcBlockAddCircle.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3532
for _lib in _libs.values():
    if not _lib.has("lcBlockAddArc", "cdecl"):
        continue
    lcBlockAddArc = _lib.get("lcBlockAddArc", "cdecl")
    lcBlockAddArc.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcBlockAddArc.restype = c_void_p
    lcBlockAddArc.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3534
for _lib in _libs.values():
    if not _lib.has("lcBlockAddArc3P", "cdecl"):
        continue
    lcBlockAddArc3P = _lib.get("lcBlockAddArc3P", "cdecl")
    lcBlockAddArc3P.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcBlockAddArc3P.restype = c_void_p
    lcBlockAddArc3P.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3536
for _lib in _libs.values():
    if not _lib.has("lcBlockAddFillet", "cdecl"):
        continue
    lcBlockAddFillet = _lib.get("lcBlockAddFillet", "cdecl")
    lcBlockAddFillet.argtypes = [c_void_p, c_void_p, c_void_p, c_double]
    lcBlockAddFillet.restype = c_void_p
    lcBlockAddFillet.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3538
for _lib in _libs.values():
    if not _lib.has("lcBlockAddEllipse", "cdecl"):
        continue
    lcBlockAddEllipse = _lib.get("lcBlockAddEllipse", "cdecl")
    lcBlockAddEllipse.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcBlockAddEllipse.restype = c_void_p
    lcBlockAddEllipse.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3541
for _lib in _libs.values():
    if not _lib.has("lcBlockAddText", "cdecl"):
        continue
    lcBlockAddText = _lib.get("lcBlockAddText", "cdecl")
    lcBlockAddText.argtypes = [c_void_p, String, c_double, c_double]
    lcBlockAddText.restype = c_void_p
    lcBlockAddText.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3542
for _lib in _libs.values():
    if not _lib.has("lcBlockAddText2", "cdecl"):
        continue
    lcBlockAddText2 = _lib.get("lcBlockAddText2", "cdecl")
    lcBlockAddText2.argtypes = [
        c_void_p,
        String,
        c_double,
        c_double,
        c_int,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcBlockAddText2.restype = c_void_p
    lcBlockAddText2.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3545
for _lib in _libs.values():
    if not _lib.has("lcBlockAddText3", "cdecl"):
        continue
    lcBlockAddText3 = _lib.get("lcBlockAddText3", "cdecl")
    lcBlockAddText3.argtypes = [
        c_void_p,
        String,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
        c_double,
        c_double,
    ]
    lcBlockAddText3.restype = c_void_p
    lcBlockAddText3.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3548
for _lib in _libs.values():
    if not _lib.has("lcBlockAddTextWin", "cdecl"):
        continue
    lcBlockAddTextWin = _lib.get("lcBlockAddTextWin", "cdecl")
    lcBlockAddTextWin.argtypes = [c_void_p, String, c_double, c_double]
    lcBlockAddTextWin.restype = c_void_p
    lcBlockAddTextWin.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3549
for _lib in _libs.values():
    if not _lib.has("lcBlockAddTextWin2", "cdecl"):
        continue
    lcBlockAddTextWin2 = _lib.get("lcBlockAddTextWin2", "cdecl")
    lcBlockAddTextWin2.argtypes = [
        c_void_p,
        String,
        c_double,
        c_double,
        c_int,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcBlockAddTextWin2.restype = c_void_p
    lcBlockAddTextWin2.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3552
for _lib in _libs.values():
    if not _lib.has("lcBlockAddMText", "cdecl"):
        continue
    lcBlockAddMText = _lib.get("lcBlockAddMText", "cdecl")
    lcBlockAddMText.argtypes = [
        c_void_p,
        String,
        c_double,
        c_double,
        c_double,
        c_int,
        c_double,
        c_double,
        c_double,
    ]
    lcBlockAddMText.restype = c_void_p
    lcBlockAddMText.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3555
for _lib in _libs.values():
    if not _lib.has("lcBlockAddArcText", "cdecl"):
        continue
    lcBlockAddArcText = _lib.get("lcBlockAddArcText", "cdecl")
    lcBlockAddArcText.argtypes = [
        c_void_p,
        String,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
        c_double,
        c_double,
        c_int,
    ]
    lcBlockAddArcText.restype = c_void_p
    lcBlockAddArcText.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3558
for _lib in _libs.values():
    if not _lib.has("lcBlockAddBlockRef", "cdecl"):
        continue
    lcBlockAddBlockRef = _lib.get("lcBlockAddBlockRef", "cdecl")
    lcBlockAddBlockRef.argtypes = [
        c_void_p,
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcBlockAddBlockRef.restype = c_void_p
    lcBlockAddBlockRef.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3560
for _lib in _libs.values():
    if not _lib.has("lcBlockAddBlockRefID", "cdecl"):
        continue
    lcBlockAddBlockRefID = _lib.get("lcBlockAddBlockRefID", "cdecl")
    lcBlockAddBlockRefID.argtypes = [
        c_void_p,
        c_int,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcBlockAddBlockRefID.restype = c_void_p
    lcBlockAddBlockRefID.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3562
for _lib in _libs.values():
    if not _lib.has("lcBlockAddBlockRefIDH", "cdecl"):
        continue
    lcBlockAddBlockRefIDH = _lib.get("lcBlockAddBlockRefIDH", "cdecl")
    lcBlockAddBlockRefIDH.argtypes = [
        c_void_p,
        String,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcBlockAddBlockRefIDH.restype = c_void_p
    lcBlockAddBlockRefIDH.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3564
for _lib in _libs.values():
    if not _lib.has("lcBlockAddAttDef", "cdecl"):
        continue
    lcBlockAddAttDef = _lib.get("lcBlockAddAttDef", "cdecl")
    lcBlockAddAttDef.argtypes = [
        c_void_p,
        c_int,
        String,
        String,
        String,
        c_double,
        c_double,
        c_int,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcBlockAddAttDef.restype = c_void_p
    lcBlockAddAttDef.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3568
for _lib in _libs.values():
    if not _lib.has("lcBlockAddXref", "cdecl"):
        continue
    lcBlockAddXref = _lib.get("lcBlockAddXref", "cdecl")
    lcBlockAddXref.argtypes = [
        c_void_p,
        String,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcBlockAddXref.restype = c_void_p
    lcBlockAddXref.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3570
for _lib in _libs.values():
    if not _lib.has("lcBlockAddImageRef", "cdecl"):
        continue
    lcBlockAddImageRef = _lib.get("lcBlockAddImageRef", "cdecl")
    lcBlockAddImageRef.argtypes = [
        c_void_p,
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
    ]
    lcBlockAddImageRef.restype = c_void_p
    lcBlockAddImageRef.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3572
for _lib in _libs.values():
    if not _lib.has("lcBlockAddImageRefUns", "cdecl"):
        continue
    lcBlockAddImageRefUns = _lib.get("lcBlockAddImageRefUns", "cdecl")
    lcBlockAddImageRefUns.argtypes = [
        c_void_p,
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_int,
        c_int,
    ]
    lcBlockAddImageRefUns.restype = c_void_p
    lcBlockAddImageRefUns.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3575
for _lib in _libs.values():
    if not _lib.has("lcBlockAddImagePlace", "cdecl"):
        continue
    lcBlockAddImagePlace = _lib.get("lcBlockAddImagePlace", "cdecl")
    lcBlockAddImagePlace.argtypes = [
        c_void_p,
        c_int,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
    ]
    lcBlockAddImagePlace.restype = c_void_p
    lcBlockAddImagePlace.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3577
for _lib in _libs.values():
    if not _lib.has("lcBlockAddEcw", "cdecl"):
        continue
    lcBlockAddEcw = _lib.get("lcBlockAddEcw", "cdecl")
    lcBlockAddEcw.argtypes = [c_void_p, String]
    lcBlockAddEcw.restype = c_void_p
    lcBlockAddEcw.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3578
for _lib in _libs.values():
    if not _lib.has("lcBlockAddBarcode", "cdecl"):
        continue
    lcBlockAddBarcode = _lib.get("lcBlockAddBarcode", "cdecl")
    lcBlockAddBarcode.argtypes = [
        c_void_p,
        c_int,
        c_double,
        c_double,
        c_double,
        c_double,
        String,
    ]
    lcBlockAddBarcode.restype = c_void_p
    lcBlockAddBarcode.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3580
for _lib in _libs.values():
    if not _lib.has("lcBlockAddHatch", "cdecl"):
        continue
    lcBlockAddHatch = _lib.get("lcBlockAddHatch", "cdecl")
    lcBlockAddHatch.argtypes = [c_void_p, String, String, c_double, c_double]
    lcBlockAddHatch.restype = c_void_p
    lcBlockAddHatch.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3582
for _lib in _libs.values():
    if not _lib.has("lcBlockAddViewport", "cdecl"):
        continue
    lcBlockAddViewport = _lib.get("lcBlockAddViewport", "cdecl")
    lcBlockAddViewport.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcBlockAddViewport.restype = c_void_p
    lcBlockAddViewport.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3586
for _lib in _libs.values():
    if not _lib.has("lcBlockAddFace", "cdecl"):
        continue
    lcBlockAddFace = _lib.get("lcBlockAddFace", "cdecl")
    lcBlockAddFace.argtypes = [
        c_void_p,
        c_int,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcBlockAddFace.restype = c_void_p
    lcBlockAddFace.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3589
for _lib in _libs.values():
    if not _lib.has("lcBlockAddFace4", "cdecl"):
        continue
    lcBlockAddFace4 = _lib.get("lcBlockAddFace4", "cdecl")
    lcBlockAddFace4.argtypes = [
        c_void_p,
        c_int,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcBlockAddFace4.restype = c_void_p
    lcBlockAddFace4.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3593
for _lib in _libs.values():
    if not _lib.has("lcBlockAddLeader", "cdecl"):
        continue
    lcBlockAddLeader = _lib.get("lcBlockAddLeader", "cdecl")
    lcBlockAddLeader.argtypes = [
        c_void_p,
        String,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
        c_int,
    ]
    lcBlockAddLeader.restype = c_void_p
    lcBlockAddLeader.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3596
for _lib in _libs.values():
    if not _lib.has("lcBlockAddDimLin", "cdecl"):
        continue
    lcBlockAddDimLin = _lib.get("lcBlockAddDimLin", "cdecl")
    lcBlockAddDimLin.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        String,
    ]
    lcBlockAddDimLin.restype = c_void_p
    lcBlockAddDimLin.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3599
for _lib in _libs.values():
    if not _lib.has("lcBlockAddDimHor", "cdecl"):
        continue
    lcBlockAddDimHor = _lib.get("lcBlockAddDimHor", "cdecl")
    lcBlockAddDimHor.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        String,
    ]
    lcBlockAddDimHor.restype = c_void_p
    lcBlockAddDimHor.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3601
for _lib in _libs.values():
    if not _lib.has("lcBlockAddDimVer", "cdecl"):
        continue
    lcBlockAddDimVer = _lib.get("lcBlockAddDimVer", "cdecl")
    lcBlockAddDimVer.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        String,
    ]
    lcBlockAddDimVer.restype = c_void_p
    lcBlockAddDimVer.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3603
for _lib in _libs.values():
    if not _lib.has("lcBlockAddDimAli", "cdecl"):
        continue
    lcBlockAddDimAli = _lib.get("lcBlockAddDimAli", "cdecl")
    lcBlockAddDimAli.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        String,
    ]
    lcBlockAddDimAli.restype = c_void_p
    lcBlockAddDimAli.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3605
for _lib in _libs.values():
    if not _lib.has("lcBlockAddDimAli2", "cdecl"):
        continue
    lcBlockAddDimAli2 = _lib.get("lcBlockAddDimAli2", "cdecl")
    lcBlockAddDimAli2.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        String,
    ]
    lcBlockAddDimAli2.restype = c_void_p
    lcBlockAddDimAli2.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3607
for _lib in _libs.values():
    if not _lib.has("lcBlockAddDimOrd", "cdecl"):
        continue
    lcBlockAddDimOrd = _lib.get("lcBlockAddDimOrd", "cdecl")
    lcBlockAddDimOrd.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
        String,
    ]
    lcBlockAddDimOrd.restype = c_void_p
    lcBlockAddDimOrd.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3609
for _lib in _libs.values():
    if not _lib.has("lcBlockAddDimRad", "cdecl"):
        continue
    lcBlockAddDimRad = _lib.get("lcBlockAddDimRad", "cdecl")
    lcBlockAddDimRad.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        String,
    ]
    lcBlockAddDimRad.restype = c_void_p
    lcBlockAddDimRad.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3611
for _lib in _libs.values():
    if not _lib.has("lcBlockAddDimRad2", "cdecl"):
        continue
    lcBlockAddDimRad2 = _lib.get("lcBlockAddDimRad2", "cdecl")
    lcBlockAddDimRad2.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        String,
    ]
    lcBlockAddDimRad2.restype = c_void_p
    lcBlockAddDimRad2.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3613
for _lib in _libs.values():
    if not _lib.has("lcBlockAddDimDia", "cdecl"):
        continue
    lcBlockAddDimDia = _lib.get("lcBlockAddDimDia", "cdecl")
    lcBlockAddDimDia.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        String,
    ]
    lcBlockAddDimDia.restype = c_void_p
    lcBlockAddDimDia.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3615
for _lib in _libs.values():
    if not _lib.has("lcBlockAddDimDia2", "cdecl"):
        continue
    lcBlockAddDimDia2 = _lib.get("lcBlockAddDimDia2", "cdecl")
    lcBlockAddDimDia2.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        String,
    ]
    lcBlockAddDimDia2.restype = c_void_p
    lcBlockAddDimDia2.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3617
for _lib in _libs.values():
    if not _lib.has("lcBlockAddDimAng", "cdecl"):
        continue
    lcBlockAddDimAng = _lib.get("lcBlockAddDimAng", "cdecl")
    lcBlockAddDimAng.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        String,
    ]
    lcBlockAddDimAng.restype = c_void_p
    lcBlockAddDimAng.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3620
for _lib in _libs.values():
    if not _lib.has("lcBlockAddDimAng2", "cdecl"):
        continue
    lcBlockAddDimAng2 = _lib.get("lcBlockAddDimAng2", "cdecl")
    lcBlockAddDimAng2.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        String,
    ]
    lcBlockAddDimAng2.restype = c_void_p
    lcBlockAddDimAng2.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3624
for _lib in _libs.values():
    if not _lib.has("lcBlockAddRPlan", "cdecl"):
        continue
    lcBlockAddRPlan = _lib.get("lcBlockAddRPlan", "cdecl")
    lcBlockAddRPlan.argtypes = [c_void_p]
    lcBlockAddRPlan.restype = c_void_p
    lcBlockAddRPlan.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3625
for _lib in _libs.values():
    if not _lib.has("lcBlockAddRPlan2", "cdecl"):
        continue
    lcBlockAddRPlan2 = _lib.get("lcBlockAddRPlan2", "cdecl")
    lcBlockAddRPlan2.argtypes = [c_void_p, c_void_p]
    lcBlockAddRPlan2.restype = c_void_p
    lcBlockAddRPlan2.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3626
for _lib in _libs.values():
    if not _lib.has("lcBlockAddArrow", "cdecl"):
        continue
    lcBlockAddArrow = _lib.get("lcBlockAddArrow", "cdecl")
    lcBlockAddArrow.argtypes = [c_void_p, c_double, c_double, c_double, c_double]
    lcBlockAddArrow.restype = c_void_p
    lcBlockAddArrow.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3628
for _lib in _libs.values():
    if not _lib.has("lcBlockAddSpiral", "cdecl"):
        continue
    lcBlockAddSpiral = _lib.get("lcBlockAddSpiral", "cdecl")
    lcBlockAddSpiral.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
        c_int,
    ]
    lcBlockAddSpiral.restype = c_void_p
    lcBlockAddSpiral.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3630
for _lib in _libs.values():
    if not _lib.has("lcBlockAddCamview", "cdecl"):
        continue
    lcBlockAddCamview = _lib.get("lcBlockAddCamview", "cdecl")
    lcBlockAddCamview.argtypes = [c_void_p, c_double, c_double, c_double, c_double]
    lcBlockAddCamview.restype = c_void_p
    lcBlockAddCamview.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3632
for _lib in _libs.values():
    if not _lib.has("lcBlockAddTIN", "cdecl"):
        continue
    lcBlockAddTIN = _lib.get("lcBlockAddTIN", "cdecl")
    lcBlockAddTIN.argtypes = [c_void_p, String, c_int]
    lcBlockAddTIN.restype = c_void_p
    lcBlockAddTIN.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3633
for _lib in _libs.values():
    if not _lib.has("lcBlockAddClone", "cdecl"):
        continue
    lcBlockAddClone = _lib.get("lcBlockAddClone", "cdecl")
    lcBlockAddClone.argtypes = [c_void_p, c_void_p]
    lcBlockAddClone.restype = c_void_p
    lcBlockAddClone.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3634
for _lib in _libs.values():
    if not _lib.has("lcBlockBeginShape", "cdecl"):
        continue
    lcBlockBeginShape = _lib.get("lcBlockBeginShape", "cdecl")
    lcBlockBeginShape.argtypes = [c_void_p]
    lcBlockBeginShape.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3635
for _lib in _libs.values():
    if not _lib.has("lcBlockAddShape", "cdecl"):
        continue
    lcBlockAddShape = _lib.get("lcBlockAddShape", "cdecl")
    lcBlockAddShape.argtypes = [c_void_p]
    lcBlockAddShape.restype = c_void_p
    lcBlockAddShape.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3636
for _lib in _libs.values():
    if not _lib.has("lcBlockAddShapeSel", "cdecl"):
        continue
    lcBlockAddShapeSel = _lib.get("lcBlockAddShapeSel", "cdecl")
    lcBlockAddShapeSel.argtypes = [c_void_p, c_int]
    lcBlockAddShapeSel.restype = c_void_p
    lcBlockAddShapeSel.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3637
for _lib in _libs.values():
    if not _lib.has("lcBlockRepEllipse", "cdecl"):
        continue
    lcBlockRepEllipse = _lib.get("lcBlockRepEllipse", "cdecl")
    lcBlockRepEllipse.argtypes = [c_void_p, c_void_p, POINTER(c_int)]
    lcBlockRepEllipse.restype = c_void_p
    lcBlockRepEllipse.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3638
for _lib in _libs.values():
    if not _lib.has("lcBlockJoinAll", "cdecl"):
        continue
    lcBlockJoinAll = _lib.get("lcBlockJoinAll", "cdecl")
    lcBlockJoinAll.argtypes = [c_void_p, c_double]
    lcBlockJoinAll.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3639
for _lib in _libs.values():
    if not _lib.has("lcBlockCopyLayer", "cdecl"):
        continue
    lcBlockCopyLayer = _lib.get("lcBlockCopyLayer", "cdecl")
    lcBlockCopyLayer.argtypes = [c_void_p, c_void_p, c_void_p]
    lcBlockCopyLayer.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3640
for _lib in _libs.values():
    if not _lib.has("lcBlockDeleteEnt", "cdecl"):
        continue
    lcBlockDeleteEnt = _lib.get("lcBlockDeleteEnt", "cdecl")
    lcBlockDeleteEnt.argtypes = [c_void_p, c_void_p]
    lcBlockDeleteEnt.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3643
for _lib in _libs.values():
    if not _lib.has("lcBlockGetFirstEnt", "cdecl"):
        continue
    lcBlockGetFirstEnt = _lib.get("lcBlockGetFirstEnt", "cdecl")
    lcBlockGetFirstEnt.argtypes = [c_void_p]
    lcBlockGetFirstEnt.restype = c_void_p
    lcBlockGetFirstEnt.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3644
for _lib in _libs.values():
    if not _lib.has("lcBlockGetNextEnt", "cdecl"):
        continue
    lcBlockGetNextEnt = _lib.get("lcBlockGetNextEnt", "cdecl")
    lcBlockGetNextEnt.argtypes = [c_void_p, c_void_p]
    lcBlockGetNextEnt.restype = c_void_p
    lcBlockGetNextEnt.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3645
for _lib in _libs.values():
    if not _lib.has("lcBlockGetLastEnt", "cdecl"):
        continue
    lcBlockGetLastEnt = _lib.get("lcBlockGetLastEnt", "cdecl")
    lcBlockGetLastEnt.argtypes = [c_void_p]
    lcBlockGetLastEnt.restype = c_void_p
    lcBlockGetLastEnt.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3646
for _lib in _libs.values():
    if not _lib.has("lcBlockGetPrevEnt", "cdecl"):
        continue
    lcBlockGetPrevEnt = _lib.get("lcBlockGetPrevEnt", "cdecl")
    lcBlockGetPrevEnt.argtypes = [c_void_p, c_void_p]
    lcBlockGetPrevEnt.restype = c_void_p
    lcBlockGetPrevEnt.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3647
for _lib in _libs.values():
    if not _lib.has("lcBlockGetEntByID", "cdecl"):
        continue
    lcBlockGetEntByID = _lib.get("lcBlockGetEntByID", "cdecl")
    lcBlockGetEntByID.argtypes = [c_void_p, c_int]
    lcBlockGetEntByID.restype = c_void_p
    lcBlockGetEntByID.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3648
for _lib in _libs.values():
    if not _lib.has("lcBlockGetEntByIDH", "cdecl"):
        continue
    lcBlockGetEntByIDH = _lib.get("lcBlockGetEntByIDH", "cdecl")
    lcBlockGetEntByIDH.argtypes = [c_void_p, String]
    lcBlockGetEntByIDH.restype = c_void_p
    lcBlockGetEntByIDH.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3649
for _lib in _libs.values():
    if not _lib.has("lcBlockGetEntByKey", "cdecl"):
        continue
    lcBlockGetEntByKey = _lib.get("lcBlockGetEntByKey", "cdecl")
    lcBlockGetEntByKey.argtypes = [c_void_p, c_int]
    lcBlockGetEntByKey.restype = c_void_p
    lcBlockGetEntByKey.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3650
for _lib in _libs.values():
    if not _lib.has("lcBlockGetBlkRefByTag", "cdecl"):
        continue
    lcBlockGetBlkRefByTag = _lib.get("lcBlockGetBlkRefByTag", "cdecl")
    lcBlockGetBlkRefByTag.argtypes = [
        c_void_p,
        c_void_p,
        String,
        String,
        c_int,
    ]
    lcBlockGetBlkRefByTag.restype = c_void_p
    lcBlockGetBlkRefByTag.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3652
for _lib in _libs.values():
    if not _lib.has("lcBlockGetTIN", "cdecl"):
        continue
    lcBlockGetTIN = _lib.get("lcBlockGetTIN", "cdecl")
    lcBlockGetTIN.argtypes = [c_void_p, String]
    lcBlockGetTIN.restype = c_void_p
    lcBlockGetTIN.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3655
for _lib in _libs.values():
    if not _lib.has("lcBlockUnselect", "cdecl"):
        continue
    lcBlockUnselect = _lib.get("lcBlockUnselect", "cdecl")
    lcBlockUnselect.argtypes = [c_void_p]
    lcBlockUnselect.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3656
for _lib in _libs.values():
    if not _lib.has("lcBlockSelectEnt", "cdecl"):
        continue
    lcBlockSelectEnt = _lib.get("lcBlockSelectEnt", "cdecl")
    lcBlockSelectEnt.argtypes = [c_void_p, c_void_p, c_int]
    lcBlockSelectEnt.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3657
for _lib in _libs.values():
    if not _lib.has("lcBlockSelErase", "cdecl"):
        continue
    lcBlockSelErase = _lib.get("lcBlockSelErase", "cdecl")
    lcBlockSelErase.argtypes = [c_void_p]
    lcBlockSelErase.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3658
for _lib in _libs.values():
    if not _lib.has("lcBlockSelMove", "cdecl"):
        continue
    lcBlockSelMove = _lib.get("lcBlockSelMove", "cdecl")
    lcBlockSelMove.argtypes = [c_void_p, c_double, c_double, c_int, c_int]
    lcBlockSelMove.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3660
for _lib in _libs.values():
    if not _lib.has("lcBlockSelScale", "cdecl"):
        continue
    lcBlockSelScale = _lib.get("lcBlockSelScale", "cdecl")
    lcBlockSelScale.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_int,
        c_int,
    ]
    lcBlockSelScale.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3662
for _lib in _libs.values():
    if not _lib.has("lcBlockSelRotate", "cdecl"):
        continue
    lcBlockSelRotate = _lib.get("lcBlockSelRotate", "cdecl")
    lcBlockSelRotate.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_int,
        c_int,
    ]
    lcBlockSelRotate.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3664
for _lib in _libs.values():
    if not _lib.has("lcBlockSelMirror", "cdecl"):
        continue
    lcBlockSelMirror = _lib.get("lcBlockSelMirror", "cdecl")
    lcBlockSelMirror.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
        c_int,
    ]
    lcBlockSelMirror.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3666
for _lib in _libs.values():
    if not _lib.has("lcBlockSelExplode", "cdecl"):
        continue
    lcBlockSelExplode = _lib.get("lcBlockSelExplode", "cdecl")
    lcBlockSelExplode.argtypes = [c_void_p]
    lcBlockSelExplode.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3667
for _lib in _libs.values():
    if not _lib.has("lcBlockSelSplit", "cdecl"):
        continue
    lcBlockSelSplit = _lib.get("lcBlockSelSplit", "cdecl")
    lcBlockSelSplit.argtypes = [c_void_p, c_int]
    lcBlockSelSplit.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3668
for _lib in _libs.values():
    if not _lib.has("lcBlockSelJoin", "cdecl"):
        continue
    lcBlockSelJoin = _lib.get("lcBlockSelJoin", "cdecl")
    lcBlockSelJoin.argtypes = [c_void_p, c_double]
    lcBlockSelJoin.restype = c_void_p
    lcBlockSelJoin.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3669
for _lib in _libs.values():
    if not _lib.has("lcBlockSelAlign", "cdecl"):
        continue
    lcBlockSelAlign = _lib.get("lcBlockSelAlign", "cdecl")
    lcBlockSelAlign.argtypes = [c_void_p, c_int, c_double, c_double]
    lcBlockSelAlign.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3670
for _lib in _libs.values():
    if not _lib.has("lcBlockSelBlock", "cdecl"):
        continue
    lcBlockSelBlock = _lib.get("lcBlockSelBlock", "cdecl")
    lcBlockSelBlock.argtypes = [c_void_p, String, c_double, c_double, c_int, c_int]
    lcBlockSelBlock.restype = c_void_p
    lcBlockSelBlock.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3672
for _lib in _libs.values():
    if not _lib.has("lcBlockGetFirstSel", "cdecl"):
        continue
    lcBlockGetFirstSel = _lib.get("lcBlockGetFirstSel", "cdecl")
    lcBlockGetFirstSel.argtypes = [c_void_p]
    lcBlockGetFirstSel.restype = c_void_p
    lcBlockGetFirstSel.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3673
for _lib in _libs.values():
    if not _lib.has("lcBlockGetNextSel", "cdecl"):
        continue
    lcBlockGetNextSel = _lib.get("lcBlockGetNextSel", "cdecl")
    lcBlockGetNextSel.argtypes = [c_void_p]
    lcBlockGetNextSel.restype = c_void_p
    lcBlockGetNextSel.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3676
for _lib in _libs.values():
    if not _lib.has("lcBlockOrderByLayers", "cdecl"):
        continue
    lcBlockOrderByLayers = _lib.get("lcBlockOrderByLayers", "cdecl")
    lcBlockOrderByLayers.argtypes = [c_void_p, c_void_p]
    lcBlockOrderByLayers.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3677
for _lib in _libs.values():
    if not _lib.has("lcBlockSortTSP", "cdecl"):
        continue
    lcBlockSortTSP = _lib.get("lcBlockSortTSP", "cdecl")
    lcBlockSortTSP.argtypes = [c_void_p, c_void_p, c_void_p]
    lcBlockSortTSP.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3678
for _lib in _libs.values():
    if not _lib.has("lcBlockGetJumpsLen", "cdecl"):
        continue
    lcBlockGetJumpsLen = _lib.get("lcBlockGetJumpsLen", "cdecl")
    lcBlockGetJumpsLen.argtypes = [c_void_p, c_void_p, c_void_p]
    lcBlockGetJumpsLen.restype = c_double
    break

# D:\\projects\\gllc\\litecad.h: 3681
for _lib in _libs.values():
    if not _lib.has("lcLayerClear", "cdecl"):
        continue
    lcLayerClear = _lib.get("lcLayerClear", "cdecl")
    lcLayerClear.argtypes = [c_void_p, c_void_p]
    lcLayerClear.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3682
for _lib in _libs.values():
    if not _lib.has("lcLayerCopyProps", "cdecl"):
        continue
    lcLayerCopyProps = _lib.get("lcLayerCopyProps", "cdecl")
    lcLayerCopyProps.argtypes = [c_void_p, c_void_p]
    lcLayerCopyProps.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3685
for _lib in _libs.values():
    if not _lib.has("lcFillSetLine", "cdecl"):
        continue
    lcFillSetLine = _lib.get("lcFillSetLine", "cdecl")
    lcFillSetLine.argtypes = [c_void_p, c_int, c_double, c_double, c_double]
    lcFillSetLine.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3689
for _lib in _libs.values():
    if not _lib.has("lcMLStyleAddLine", "cdecl"):
        continue
    lcMLStyleAddLine = _lib.get("lcMLStyleAddLine", "cdecl")
    lcMLStyleAddLine.argtypes = [c_void_p, c_double, String, c_void_p]
    lcMLStyleAddLine.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3691
for _lib in _libs.values():
    if not _lib.has("lcMLStyleDelLine", "cdecl"):
        continue
    lcMLStyleDelLine = _lib.get("lcMLStyleDelLine", "cdecl")
    lcMLStyleDelLine.argtypes = [c_void_p, c_int]
    lcMLStyleDelLine.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3692
for _lib in _libs.values():
    if not _lib.has("lcMLStyleSortLines", "cdecl"):
        continue
    lcMLStyleSortLines = _lib.get("lcMLStyleSortLines", "cdecl")
    lcMLStyleSortLines.argtypes = [c_void_p]
    lcMLStyleSortLines.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3694
for _lib in _libs.values():
    if not _lib.has("lcEntType", "cdecl"):
        continue
    lcEntType = _lib.get("lcEntType", "cdecl")
    lcEntType.argtypes = [c_void_p, c_int]
    lcEntType.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3697
for _lib in _libs.values():
    if not _lib.has("lcEntErase", "cdecl"):
        continue
    lcEntErase = _lib.get("lcEntErase", "cdecl")
    lcEntErase.argtypes = [c_void_p, c_int]
    lcEntErase.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3698
for _lib in _libs.values():
    if not _lib.has("lcEntMove", "cdecl"):
        continue
    lcEntMove = _lib.get("lcEntMove", "cdecl")
    lcEntMove.argtypes = [c_void_p, c_double, c_double]
    lcEntMove.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3699
for _lib in _libs.values():
    if not _lib.has("lcEntAlign", "cdecl"):
        continue
    lcEntAlign = _lib.get("lcEntAlign", "cdecl")
    lcEntAlign.argtypes = [c_void_p, c_int, c_double, c_double]
    lcEntAlign.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3700
for _lib in _libs.values():
    if not _lib.has("lcEntScale", "cdecl"):
        continue
    lcEntScale = _lib.get("lcEntScale", "cdecl")
    lcEntScale.argtypes = [c_void_p, c_double, c_double, c_double]
    lcEntScale.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3701
for _lib in _libs.values():
    if not _lib.has("lcEntRotate", "cdecl"):
        continue
    lcEntRotate = _lib.get("lcEntRotate", "cdecl")
    lcEntRotate.argtypes = [c_void_p, c_double, c_double, c_double]
    lcEntRotate.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3702
for _lib in _libs.values():
    if not _lib.has("lcEntMirror", "cdecl"):
        continue
    lcEntMirror = _lib.get("lcEntMirror", "cdecl")
    lcEntMirror.argtypes = [c_void_p, c_double, c_double, c_double, c_double]
    lcEntMirror.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3703
for _lib in _libs.values():
    if not _lib.has("lcEntExplode", "cdecl"):
        continue
    lcEntExplode = _lib.get("lcEntExplode", "cdecl")
    lcEntExplode.argtypes = [c_void_p, c_int, c_int]
    lcEntExplode.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3704
for _lib in _libs.values():
    if not _lib.has("lcEntSplit", "cdecl"):
        continue
    lcEntSplit = _lib.get("lcEntSplit", "cdecl")
    lcEntSplit.argtypes = [c_void_p, c_int, c_int, c_int]
    lcEntSplit.restype = c_void_p
    lcEntSplit.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3705
for _lib in _libs.values():
    if not _lib.has("lcEntBreak", "cdecl"):
        continue
    lcEntBreak = _lib.get("lcEntBreak", "cdecl")
    lcEntBreak.argtypes = [c_void_p, c_double, c_double, c_double, c_int, c_int]
    lcEntBreak.restype = c_void_p
    lcEntBreak.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3707
for _lib in _libs.values():
    if not _lib.has("lcEntBreak2", "cdecl"):
        continue
    lcEntBreak2 = _lib.get("lcEntBreak2", "cdecl")
    lcEntBreak2.argtypes = [c_void_p, c_void_p, c_double, c_int, c_int]
    lcEntBreak2.restype = c_void_p
    lcEntBreak2.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3709
for _lib in _libs.values():
    if not _lib.has("lcEntOffset", "cdecl"):
        continue
    lcEntOffset = _lib.get("lcEntOffset", "cdecl")
    lcEntOffset.argtypes = [c_void_p, c_double]
    lcEntOffset.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3710
for _lib in _libs.values():
    if not _lib.has("lcEntExtend", "cdecl"):
        continue
    lcEntExtend = _lib.get("lcEntExtend", "cdecl")
    lcEntExtend.argtypes = [c_void_p, c_void_p, c_int]
    lcEntExtend.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3711
for _lib in _libs.values():
    if not _lib.has("lcEntToTop", "cdecl"):
        continue
    lcEntToTop = _lib.get("lcEntToTop", "cdecl")
    lcEntToTop.argtypes = [c_void_p]
    lcEntToTop.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3712
for _lib in _libs.values():
    if not _lib.has("lcEntToBottom", "cdecl"):
        continue
    lcEntToBottom = _lib.get("lcEntToBottom", "cdecl")
    lcEntToBottom.argtypes = [c_void_p]
    lcEntToBottom.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3713
for _lib in _libs.values():
    if not _lib.has("lcEntToAbove", "cdecl"):
        continue
    lcEntToAbove = _lib.get("lcEntToAbove", "cdecl")
    lcEntToAbove.argtypes = [c_void_p, c_void_p]
    lcEntToAbove.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3714
for _lib in _libs.values():
    if not _lib.has("lcEntToUnder", "cdecl"):
        continue
    lcEntToUnder = _lib.get("lcEntToUnder", "cdecl")
    lcEntToUnder.argtypes = [c_void_p, c_void_p]
    lcEntToUnder.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3715
for _lib in _libs.values():
    if not _lib.has("lcEntGetGrip", "cdecl"):
        continue
    lcEntGetGrip = _lib.get("lcEntGetGrip", "cdecl")
    lcEntGetGrip.argtypes = [c_void_p, c_int, POINTER(c_double), POINTER(c_double)]
    lcEntGetGrip.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3716
for _lib in _libs.values():
    if not _lib.has("lcEntPutGrip", "cdecl"):
        continue
    lcEntPutGrip = _lib.get("lcEntPutGrip", "cdecl")
    lcEntPutGrip.argtypes = [c_void_p, c_int, c_double, c_double]
    lcEntPutGrip.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3717
for _lib in _libs.values():
    if not _lib.has("lcEntUpdate", "cdecl"):
        continue
    lcEntUpdate = _lib.get("lcEntUpdate", "cdecl")
    lcEntUpdate.argtypes = [c_void_p]
    lcEntUpdate.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3718
for _lib in _libs.values():
    if not _lib.has("lcEntCopyBase", "cdecl"):
        continue
    lcEntCopyBase = _lib.get("lcEntCopyBase", "cdecl")
    lcEntCopyBase.argtypes = [c_void_p, c_void_p]
    lcEntCopyBase.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3719
for _lib in _libs.values():
    if not _lib.has("lcEntXData", "cdecl"):
        continue
    lcEntXData = _lib.get("lcEntXData", "cdecl")
    lcEntXData.argtypes = [c_void_p, c_int, c_int, c_int]
    lcEntXData.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3720
for _lib in _libs.values():
    if not _lib.has("lcEntContainEnt", "cdecl"):
        continue
    lcEntContainEnt = _lib.get("lcEntContainEnt", "cdecl")
    lcEntContainEnt.argtypes = [c_void_p, c_void_p]
    lcEntContainEnt.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3721
for _lib in _libs.values():
    if not _lib.has("lcEntCrossEnt", "cdecl"):
        continue
    lcEntCrossEnt = _lib.get("lcEntCrossEnt", "cdecl")
    lcEntCrossEnt.argtypes = [c_void_p, c_void_p]
    lcEntCrossEnt.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3722
for _lib in _libs.values():
    if not _lib.has("lcEntReverse", "cdecl"):
        continue
    lcEntReverse = _lib.get("lcEntReverse", "cdecl")
    lcEntReverse.argtypes = [c_void_p]
    lcEntReverse.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3723
for _lib in _libs.values():
    if not _lib.has("lcEntGetPoint", "cdecl"):
        continue
    lcEntGetPoint = _lib.get("lcEntGetPoint", "cdecl")
    lcEntGetPoint.argtypes = [
        c_void_p,
        c_double,
        POINTER(c_double),
        POINTER(c_double),
        POINTER(c_double),
    ]
    lcEntGetPoint.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3725
for _lib in _libs.values():
    if not _lib.has("lcEntGetDist", "cdecl"):
        continue
    lcEntGetDist = _lib.get("lcEntGetDist", "cdecl")
    lcEntGetDist.argtypes = [
        c_void_p,
        c_double,
        c_double,
        POINTER(c_double),
        POINTER(c_double),
        POINTER(c_double),
    ]
    lcEntGetDist.restype = c_double
    break

# D:\\projects\\gllc\\litecad.h: 3727
for _lib in _libs.values():
    if not _lib.has("lcEntTransform", "cdecl"):
        continue
    lcEntTransform = _lib.get("lcEntTransform", "cdecl")
    lcEntTransform.argtypes = [c_void_p, c_void_p]
    lcEntTransform.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3728
for _lib in _libs.values():
    if not _lib.has("lcIntersection", "cdecl"):
        continue
    lcIntersection = _lib.get("lcIntersection", "cdecl")
    lcIntersection.argtypes = [c_void_p, c_void_p, c_int]
    lcIntersection.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3729
for _lib in _libs.values():
    if not _lib.has("lcInterGetPoint", "cdecl"):
        continue
    lcInterGetPoint = _lib.get("lcInterGetPoint", "cdecl")
    lcInterGetPoint.argtypes = [c_int, POINTER(c_double), POINTER(c_double)]
    lcInterGetPoint.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3731
for _lib in _libs.values():
    if not _lib.has("lcLineGetPoint", "cdecl"):
        continue
    lcLineGetPoint = _lib.get("lcLineGetPoint", "cdecl")
    lcLineGetPoint.argtypes = [
        c_void_p,
        c_int,
        c_double,
        POINTER(c_double),
        POINTER(c_double),
    ]
    lcLineGetPoint.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3735
for _lib in _libs.values():
    if not _lib.has("lcPlineAddVer", "cdecl"):
        continue
    lcPlineAddVer = _lib.get("lcPlineAddVer", "cdecl")
    lcPlineAddVer.argtypes = [c_void_p, c_void_p, c_double, c_double]
    lcPlineAddVer.restype = c_void_p
    lcPlineAddVer.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3736
for _lib in _libs.values():
    if not _lib.has("lcPlineAddVer2", "cdecl"):
        continue
    lcPlineAddVer2 = _lib.get("lcPlineAddVer2", "cdecl")
    lcPlineAddVer2.argtypes = [
        c_void_p,
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcPlineAddVer2.restype = c_void_p
    lcPlineAddVer2.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3738
for _lib in _libs.values():
    if not _lib.has("lcPlineAddVerDir", "cdecl"):
        continue
    lcPlineAddVerDir = _lib.get("lcPlineAddVerDir", "cdecl")
    lcPlineAddVerDir.argtypes = [c_void_p, c_void_p, c_double, c_double]
    lcPlineAddVerDir.restype = c_void_p
    lcPlineAddVerDir.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3740
for _lib in _libs.values():
    if not _lib.has("lcPlineEnd", "cdecl"):
        continue
    lcPlineEnd = _lib.get("lcPlineEnd", "cdecl")
    lcPlineEnd.argtypes = [c_void_p]
    lcPlineEnd.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3741
for _lib in _libs.values():
    if not _lib.has("lcPlineFromPtbuf", "cdecl"):
        continue
    lcPlineFromPtbuf = _lib.get("lcPlineFromPtbuf", "cdecl")
    lcPlineFromPtbuf.argtypes = [c_void_p, c_void_p]
    lcPlineFromPtbuf.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3742
for _lib in _libs.values():
    if not _lib.has("lcPlineFromMpgon", "cdecl"):
        continue
    lcPlineFromMpgon = _lib.get("lcPlineFromMpgon", "cdecl")
    lcPlineFromMpgon.argtypes = [c_void_p, c_void_p]
    lcPlineFromMpgon.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3743
for _lib in _libs.values():
    if not _lib.has("lcPlineFromFile", "cdecl"):
        continue
    lcPlineFromFile = _lib.get("lcPlineFromFile", "cdecl")
    lcPlineFromFile.argtypes = [c_void_p, String]
    lcPlineFromFile.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3744
for _lib in _libs.values():
    if not _lib.has("lcPlineDeleteVer", "cdecl"):
        continue
    lcPlineDeleteVer = _lib.get("lcPlineDeleteVer", "cdecl")
    lcPlineDeleteVer.argtypes = [c_void_p, c_void_p]
    lcPlineDeleteVer.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3745
for _lib in _libs.values():
    if not _lib.has("lcPlineDelExVers", "cdecl"):
        continue
    lcPlineDelExVers = _lib.get("lcPlineDelExVers", "cdecl")
    lcPlineDelExVers.argtypes = [c_void_p, c_double]
    lcPlineDelExVers.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3746
for _lib in _libs.values():
    if not _lib.has("lcPlineGetFirstVer", "cdecl"):
        continue
    lcPlineGetFirstVer = _lib.get("lcPlineGetFirstVer", "cdecl")
    lcPlineGetFirstVer.argtypes = [c_void_p]
    lcPlineGetFirstVer.restype = c_void_p
    lcPlineGetFirstVer.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3747
for _lib in _libs.values():
    if not _lib.has("lcPlineGetNextVer", "cdecl"):
        continue
    lcPlineGetNextVer = _lib.get("lcPlineGetNextVer", "cdecl")
    lcPlineGetNextVer.argtypes = [c_void_p, c_void_p]
    lcPlineGetNextVer.restype = c_void_p
    lcPlineGetNextVer.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3748
for _lib in _libs.values():
    if not _lib.has("lcPlineGetLastVer", "cdecl"):
        continue
    lcPlineGetLastVer = _lib.get("lcPlineGetLastVer", "cdecl")
    lcPlineGetLastVer.argtypes = [c_void_p]
    lcPlineGetLastVer.restype = c_void_p
    lcPlineGetLastVer.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3749
for _lib in _libs.values():
    if not _lib.has("lcPlineGetPrevVer", "cdecl"):
        continue
    lcPlineGetPrevVer = _lib.get("lcPlineGetPrevVer", "cdecl")
    lcPlineGetPrevVer.argtypes = [c_void_p, c_void_p]
    lcPlineGetPrevVer.restype = c_void_p
    lcPlineGetPrevVer.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3750
for _lib in _libs.values():
    if not _lib.has("lcPlineGetVer", "cdecl"):
        continue
    lcPlineGetVer = _lib.get("lcPlineGetVer", "cdecl")
    lcPlineGetVer.argtypes = [c_void_p, c_int]
    lcPlineGetVer.restype = c_void_p
    lcPlineGetVer.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3751
for _lib in _libs.values():
    if not _lib.has("lcPlineGetVerPt", "cdecl"):
        continue
    lcPlineGetVerPt = _lib.get("lcPlineGetVerPt", "cdecl")
    lcPlineGetVerPt.argtypes = [c_void_p, c_double, c_double, c_double]
    lcPlineGetVerPt.restype = c_void_p
    lcPlineGetVerPt.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3752
for _lib in _libs.values():
    if not _lib.has("lcPlineGetSeg", "cdecl"):
        continue
    lcPlineGetSeg = _lib.get("lcPlineGetSeg", "cdecl")
    lcPlineGetSeg.argtypes = [c_void_p, c_double, c_double, c_double]
    lcPlineGetSeg.restype = c_void_p
    lcPlineGetSeg.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3753
for _lib in _libs.values():
    if not _lib.has("lcPlineReverse", "cdecl"):
        continue
    lcPlineReverse = _lib.get("lcPlineReverse", "cdecl")
    lcPlineReverse.argtypes = [c_void_p]
    lcPlineReverse.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3754
for _lib in _libs.values():
    if not _lib.has("lcPlineSetStartVer", "cdecl"):
        continue
    lcPlineSetStartVer = _lib.get("lcPlineSetStartVer", "cdecl")
    lcPlineSetStartVer.argtypes = [c_void_p, c_void_p]
    lcPlineSetStartVer.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3755
for _lib in _libs.values():
    if not _lib.has("lcPlineContainPoint", "cdecl"):
        continue
    lcPlineContainPoint = _lib.get("lcPlineContainPoint", "cdecl")
    lcPlineContainPoint.argtypes = [c_void_p, c_double, c_double]
    lcPlineContainPoint.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3756
for _lib in _libs.values():
    if not _lib.has("lcPlineGetRoundPrm", "cdecl"):
        continue
    lcPlineGetRoundPrm = _lib.get("lcPlineGetRoundPrm", "cdecl")
    lcPlineGetRoundPrm.argtypes = [
        c_void_p,
        c_void_p,
        POINTER(c_double),
        POINTER(c_double),
        POINTER(c_double),
        POINTER(c_double),
        POINTER(c_double),
    ]
    lcPlineGetRoundPrm.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3759
for _lib in _libs.values():
    if not _lib.has("lcPlineGetPoint", "cdecl"):
        continue
    lcPlineGetPoint = _lib.get("lcPlineGetPoint", "cdecl")
    lcPlineGetPoint.argtypes = [
        c_void_p,
        c_double,
        POINTER(c_double),
        POINTER(c_double),
        POINTER(c_double),
    ]
    lcPlineGetPoint.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3761
for _lib in _libs.values():
    if not _lib.has("lcPlineGetPointOpp", "cdecl"):
        continue
    lcPlineGetPointOpp = _lib.get("lcPlineGetPointOpp", "cdecl")
    lcPlineGetPointOpp.argtypes = [
        c_void_p,
        c_double,
        POINTER(c_double),
        POINTER(c_double),
        POINTER(c_double),
        POINTER(c_double),
        POINTER(c_double),
    ]
    lcPlineGetPointOpp.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3763
for _lib in _libs.values():
    if not _lib.has("lcPlineGetDist", "cdecl"):
        continue
    lcPlineGetDist = _lib.get("lcPlineGetDist", "cdecl")
    lcPlineGetDist.argtypes = [
        c_void_p,
        c_double,
        c_double,
        POINTER(c_double),
        POINTER(c_double),
        POINTER(c_double),
    ]
    lcPlineGetDist.restype = c_double
    break

# D:\\projects\\gllc\\litecad.h: 3765
for _lib in _libs.values():
    if not _lib.has("lcPlineDivide", "cdecl"):
        continue
    lcPlineDivide = _lib.get("lcPlineDivide", "cdecl")
    lcPlineDivide.argtypes = [c_void_p, c_int, c_int]
    lcPlineDivide.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3766
for _lib in _libs.values():
    if not _lib.has("lcPlineDivide2", "cdecl"):
        continue
    lcPlineDivide2 = _lib.get("lcPlineDivide2", "cdecl")
    lcPlineDivide2.argtypes = [c_void_p, c_double, c_int]
    lcPlineDivide2.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3767
for _lib in _libs.values():
    if not _lib.has("lcGetDivPt", "cdecl"):
        continue
    lcGetDivPt = _lib.get("lcGetDivPt", "cdecl")
    lcGetDivPt.argtypes = [
        c_int,
        POINTER(c_double),
        POINTER(c_double),
        POINTER(c_double),
    ]
    lcGetDivPt.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3768
for _lib in _libs.values():
    if not _lib.has("lcPlineMakeArrow", "cdecl"):
        continue
    lcPlineMakeArrow = _lib.get("lcPlineMakeArrow", "cdecl")
    lcPlineMakeArrow.argtypes = [c_void_p, c_double, c_double]
    lcPlineMakeArrow.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3769
for _lib in _libs.values():
    if not _lib.has("lcPlineSplitBySI", "cdecl"):
        continue
    lcPlineSplitBySI = _lib.get("lcPlineSplitBySI", "cdecl")
    lcPlineSplitBySI.argtypes = [c_void_p, c_int, c_int]
    lcPlineSplitBySI.restype = c_void_p
    lcPlineSplitBySI.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3772
for _lib in _libs.values():
    if not _lib.has("lcBezierAddVer", "cdecl"):
        continue
    lcBezierAddVer = _lib.get("lcBezierAddVer", "cdecl")
    lcBezierAddVer.argtypes = [c_void_p, c_void_p, c_double, c_double]
    lcBezierAddVer.restype = c_void_p
    lcBezierAddVer.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3773
for _lib in _libs.values():
    if not _lib.has("lcBezierEnd", "cdecl"):
        continue
    lcBezierEnd = _lib.get("lcBezierEnd", "cdecl")
    lcBezierEnd.argtypes = [c_void_p]
    lcBezierEnd.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3774
for _lib in _libs.values():
    if not _lib.has("lcBezierSetVerPrm", "cdecl"):
        continue
    lcBezierSetVerPrm = _lib.get("lcBezierSetVerPrm", "cdecl")
    lcBezierSetVerPrm.argtypes = [
        c_void_p,
        c_void_p,
        c_int,
        c_double,
        c_double,
    ]
    lcBezierSetVerPrm.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3778
for _lib in _libs.values():
    if not _lib.has("lcMlineAddVer", "cdecl"):
        continue
    lcMlineAddVer = _lib.get("lcMlineAddVer", "cdecl")
    lcMlineAddVer.argtypes = [c_void_p, c_void_p, c_double, c_double]
    lcMlineAddVer.restype = c_void_p
    lcMlineAddVer.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3779
for _lib in _libs.values():
    if not _lib.has("lcMlineAddVerDir", "cdecl"):
        continue
    lcMlineAddVerDir = _lib.get("lcMlineAddVerDir", "cdecl")
    lcMlineAddVerDir.argtypes = [c_void_p, c_void_p, c_double, c_double]
    lcMlineAddVerDir.restype = c_void_p
    lcMlineAddVerDir.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3781
for _lib in _libs.values():
    if not _lib.has("lcMlineDeleteVer", "cdecl"):
        continue
    lcMlineDeleteVer = _lib.get("lcMlineDeleteVer", "cdecl")
    lcMlineDeleteVer.argtypes = [c_void_p, c_void_p]
    lcMlineDeleteVer.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3782
for _lib in _libs.values():
    if not _lib.has("lcMlineGetFirstVer", "cdecl"):
        continue
    lcMlineGetFirstVer = _lib.get("lcMlineGetFirstVer", "cdecl")
    lcMlineGetFirstVer.argtypes = [c_void_p]
    lcMlineGetFirstVer.restype = c_void_p
    lcMlineGetFirstVer.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3783
for _lib in _libs.values():
    if not _lib.has("lcMlineGetNextVer", "cdecl"):
        continue
    lcMlineGetNextVer = _lib.get("lcMlineGetNextVer", "cdecl")
    lcMlineGetNextVer.argtypes = [c_void_p, c_void_p]
    lcMlineGetNextVer.restype = c_void_p
    lcMlineGetNextVer.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3784
for _lib in _libs.values():
    if not _lib.has("lcMlineGetLastVer", "cdecl"):
        continue
    lcMlineGetLastVer = _lib.get("lcMlineGetLastVer", "cdecl")
    lcMlineGetLastVer.argtypes = [c_void_p]
    lcMlineGetLastVer.restype = c_void_p
    lcMlineGetLastVer.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3785
for _lib in _libs.values():
    if not _lib.has("lcMlineGetPrevVer", "cdecl"):
        continue
    lcMlineGetPrevVer = _lib.get("lcMlineGetPrevVer", "cdecl")
    lcMlineGetPrevVer.argtypes = [c_void_p, c_void_p]
    lcMlineGetPrevVer.restype = c_void_p
    lcMlineGetPrevVer.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3786
for _lib in _libs.values():
    if not _lib.has("lcMlineGetVer", "cdecl"):
        continue
    lcMlineGetVer = _lib.get("lcMlineGetVer", "cdecl")
    lcMlineGetVer.argtypes = [c_void_p, c_int]
    lcMlineGetVer.restype = c_void_p
    lcMlineGetVer.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3787
for _lib in _libs.values():
    if not _lib.has("lcMlineGetVerPt", "cdecl"):
        continue
    lcMlineGetVerPt = _lib.get("lcMlineGetVerPt", "cdecl")
    lcMlineGetVerPt.argtypes = [c_void_p, c_double, c_double, c_double]
    lcMlineGetVerPt.restype = c_void_p
    lcMlineGetVerPt.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3788
for _lib in _libs.values():
    if not _lib.has("lcMlineGetSeg", "cdecl"):
        continue
    lcMlineGetSeg = _lib.get("lcMlineGetSeg", "cdecl")
    lcMlineGetSeg.argtypes = [c_void_p, c_double, c_double, c_double]
    lcMlineGetSeg.restype = c_void_p
    lcMlineGetSeg.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3790
for _lib in _libs.values():
    if not _lib.has("lcMlineReverse", "cdecl"):
        continue
    lcMlineReverse = _lib.get("lcMlineReverse", "cdecl")
    lcMlineReverse.argtypes = [c_void_p]
    lcMlineReverse.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3793
for _lib in _libs.values():
    if not _lib.has("lcRPlanAddVer", "cdecl"):
        continue
    lcRPlanAddVer = _lib.get("lcRPlanAddVer", "cdecl")
    lcRPlanAddVer.argtypes = [c_void_p, c_double, c_double]
    lcRPlanAddVer.restype = c_void_p
    lcRPlanAddVer.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3794
for _lib in _libs.values():
    if not _lib.has("lcRPlanSetCurve", "cdecl"):
        continue
    lcRPlanSetCurve = _lib.get("lcRPlanSetCurve", "cdecl")
    lcRPlanSetCurve.argtypes = [c_void_p, c_double, c_double, c_double]
    lcRPlanSetCurve.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3796
for _lib in _libs.values():
    if not _lib.has("lcRPlanSetPos", "cdecl"):
        continue
    lcRPlanSetPos = _lib.get("lcRPlanSetPos", "cdecl")
    lcRPlanSetPos.argtypes = [c_void_p, c_double, c_double]
    lcRPlanSetPos.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3797
for _lib in _libs.values():
    if not _lib.has("lcRPlanDeleteVer", "cdecl"):
        continue
    lcRPlanDeleteVer = _lib.get("lcRPlanDeleteVer", "cdecl")
    lcRPlanDeleteVer.argtypes = [c_void_p, c_void_p]
    lcRPlanDeleteVer.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3798
for _lib in _libs.values():
    if not _lib.has("lcRPlanGetFirstVer", "cdecl"):
        continue
    lcRPlanGetFirstVer = _lib.get("lcRPlanGetFirstVer", "cdecl")
    lcRPlanGetFirstVer.argtypes = [c_void_p]
    lcRPlanGetFirstVer.restype = c_void_p
    lcRPlanGetFirstVer.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3799
for _lib in _libs.values():
    if not _lib.has("lcRPlanGetNextVer", "cdecl"):
        continue
    lcRPlanGetNextVer = _lib.get("lcRPlanGetNextVer", "cdecl")
    lcRPlanGetNextVer.argtypes = [c_void_p, c_void_p]
    lcRPlanGetNextVer.restype = c_void_p
    lcRPlanGetNextVer.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3800
for _lib in _libs.values():
    if not _lib.has("lcRPlanGetLastVer", "cdecl"):
        continue
    lcRPlanGetLastVer = _lib.get("lcRPlanGetLastVer", "cdecl")
    lcRPlanGetLastVer.argtypes = [c_void_p]
    lcRPlanGetLastVer.restype = c_void_p
    lcRPlanGetLastVer.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3801
for _lib in _libs.values():
    if not _lib.has("lcRPlanGetPrevVer", "cdecl"):
        continue
    lcRPlanGetPrevVer = _lib.get("lcRPlanGetPrevVer", "cdecl")
    lcRPlanGetPrevVer.argtypes = [c_void_p, c_void_p]
    lcRPlanGetPrevVer.restype = c_void_p
    lcRPlanGetPrevVer.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3802
for _lib in _libs.values():
    if not _lib.has("lcRPlanGetVer", "cdecl"):
        continue
    lcRPlanGetVer = _lib.get("lcRPlanGetVer", "cdecl")
    lcRPlanGetVer.argtypes = [c_void_p, c_int]
    lcRPlanGetVer.restype = c_void_p
    lcRPlanGetVer.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3803
for _lib in _libs.values():
    if not _lib.has("lcRPlanGetPoint", "cdecl"):
        continue
    lcRPlanGetPoint = _lib.get("lcRPlanGetPoint", "cdecl")
    lcRPlanGetPoint.argtypes = [
        c_void_p,
        c_double,
        POINTER(c_double),
        POINTER(c_double),
        POINTER(c_double),
        POINTER(c_int),
    ]
    lcRPlanGetPoint.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3805
for _lib in _libs.values():
    if not _lib.has("lcRPlanGetDist", "cdecl"):
        continue
    lcRPlanGetDist = _lib.get("lcRPlanGetDist", "cdecl")
    lcRPlanGetDist.argtypes = [
        c_void_p,
        c_double,
        c_double,
        POINTER(c_double),
        POINTER(c_double),
        POINTER(c_double),
        POINTER(c_double),
    ]
    lcRPlanGetDist.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3807
for _lib in _libs.values():
    if not _lib.has("lcRPlanWriteCSV", "cdecl"):
        continue
    lcRPlanWriteCSV = _lib.get("lcRPlanWriteCSV", "cdecl")
    lcRPlanWriteCSV.argtypes = [c_void_p, String]
    lcRPlanWriteCSV.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3810
for _lib in _libs.values():
    if not _lib.has("lcXlinePutDir", "cdecl"):
        continue
    lcXlinePutDir = _lib.get("lcXlinePutDir", "cdecl")
    lcXlinePutDir.argtypes = [c_void_p, c_double, c_double]
    lcXlinePutDir.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3813
for _lib in _libs.values():
    if not _lib.has("lcRectGetPolyline", "cdecl"):
        continue
    lcRectGetPolyline = _lib.get("lcRectGetPolyline", "cdecl")
    lcRectGetPolyline.argtypes = [
        c_void_p,
        POINTER(c_double),
        POINTER(c_double),
        POINTER(c_double),
    ]
    lcRectGetPolyline.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3819
for _lib in _libs.values():
    if not _lib.has("lcImgRefGetPixel", "cdecl"):
        continue
    lcImgRefGetPixel = _lib.get("lcImgRefGetPixel", "cdecl")
    lcImgRefGetPixel.argtypes = [
        c_void_p,
        c_int,
        c_int,
        POINTER(c_double),
        POINTER(c_double),
        POINTER(c_int),
    ]
    lcImgRefGetPixel.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3821
for _lib in _libs.values():
    if not _lib.has("lcImgRefResize", "cdecl"):
        continue
    lcImgRefResize = _lib.get("lcImgRefResize", "cdecl")
    lcImgRefResize.argtypes = [c_void_p, c_int, c_int, c_int]
    lcImgRefResize.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3825
for _lib in _libs.values():
    if not _lib.has("lcHatchSetPattern", "cdecl"):
        continue
    lcHatchSetPattern = _lib.get("lcHatchSetPattern", "cdecl")
    lcHatchSetPattern.argtypes = [c_void_p, String, String, c_double, c_double]
    lcHatchSetPattern.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3827
for _lib in _libs.values():
    if not _lib.has("lcHatchBoundStart", "cdecl"):
        continue
    lcHatchBoundStart = _lib.get("lcHatchBoundStart", "cdecl")
    lcHatchBoundStart.argtypes = [c_void_p]
    lcHatchBoundStart.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3828
for _lib in _libs.values():
    if not _lib.has("lcHatchBoundPoint", "cdecl"):
        continue
    lcHatchBoundPoint = _lib.get("lcHatchBoundPoint", "cdecl")
    lcHatchBoundPoint.argtypes = [c_void_p, c_double, c_double]
    lcHatchBoundPoint.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3829
for _lib in _libs.values():
    if not _lib.has("lcHatchBoundEntity", "cdecl"):
        continue
    lcHatchBoundEntity = _lib.get("lcHatchBoundEntity", "cdecl")
    lcHatchBoundEntity.argtypes = [c_void_p, c_void_p]
    lcHatchBoundEntity.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3830
for _lib in _libs.values():
    if not _lib.has("lcHatchBoundEndLoop", "cdecl"):
        continue
    lcHatchBoundEndLoop = _lib.get("lcHatchBoundEndLoop", "cdecl")
    lcHatchBoundEndLoop.argtypes = [c_void_p]
    lcHatchBoundEndLoop.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3831
for _lib in _libs.values():
    if not _lib.has("lcHatchBoundEnd", "cdecl"):
        continue
    lcHatchBoundEnd = _lib.get("lcHatchBoundEnd", "cdecl")
    lcHatchBoundEnd.argtypes = [c_void_p]
    lcHatchBoundEnd.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3832
for _lib in _libs.values():
    if not _lib.has("lcHatchPatStart", "cdecl"):
        continue
    lcHatchPatStart = _lib.get("lcHatchPatStart", "cdecl")
    lcHatchPatStart.argtypes = [c_void_p]
    lcHatchPatStart.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3833
for _lib in _libs.values():
    if not _lib.has("lcHatchPatLine", "cdecl"):
        continue
    lcHatchPatLine = _lib.get("lcHatchPatLine", "cdecl")
    lcHatchPatLine.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcHatchPatLine.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3837
for _lib in _libs.values():
    if not _lib.has("lcHatchPatEnd", "cdecl"):
        continue
    lcHatchPatEnd = _lib.get("lcHatchPatEnd", "cdecl")
    lcHatchPatEnd.argtypes = [c_void_p]
    lcHatchPatEnd.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3838
for _lib in _libs.values():
    if not _lib.has("lcHatchGetLoopSize", "cdecl"):
        continue
    lcHatchGetLoopSize = _lib.get("lcHatchGetLoopSize", "cdecl")
    lcHatchGetLoopSize.argtypes = [c_void_p, c_int]
    lcHatchGetLoopSize.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3839
for _lib in _libs.values():
    if not _lib.has("lcHatchGetPoint", "cdecl"):
        continue
    lcHatchGetPoint = _lib.get("lcHatchGetPoint", "cdecl")
    lcHatchGetPoint.argtypes = [
        c_void_p,
        c_int,
        POINTER(c_double),
        POINTER(c_double),
    ]
    lcHatchGetPoint.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3840
for _lib in _libs.values():
    if not _lib.has("lcHatchGetEnt", "cdecl"):
        continue
    lcHatchGetEnt = _lib.get("lcHatchGetEnt", "cdecl")
    lcHatchGetEnt.argtypes = [c_void_p, c_int]
    lcHatchGetEnt.restype = c_void_p
    lcHatchGetEnt.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3843
for _lib in _libs.values():
    if not _lib.has("lcVportSetView", "cdecl"):
        continue
    lcVportSetView = _lib.get("lcVportSetView", "cdecl")
    lcVportSetView.argtypes = [c_void_p, c_double, c_double, c_double, c_double]
    lcVportSetView.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3845
for _lib in _libs.values():
    if not _lib.has("lcVportLayerDlg", "cdecl"):
        continue
    lcVportLayerDlg = _lib.get("lcVportLayerDlg", "cdecl")
    lcVportLayerDlg.argtypes = [c_void_p, c_void_p]
    lcVportLayerDlg.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3846
for _lib in _libs.values():
    if not _lib.has("lcVportLayerCmd", "cdecl"):
        continue
    lcVportLayerCmd = _lib.get("lcVportLayerCmd", "cdecl")
    lcVportLayerCmd.argtypes = [c_void_p, c_int, c_void_p]
    lcVportLayerCmd.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3849
for _lib in _libs.values():
    if not _lib.has("lcBlkRefAddAtt", "cdecl"):
        continue
    lcBlkRefAddAtt = _lib.get("lcBlkRefAddAtt", "cdecl")
    lcBlkRefAddAtt.argtypes = [c_void_p, String, String]
    lcBlkRefAddAtt.restype = c_void_p
    lcBlkRefAddAtt.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3851
for _lib in _libs.values():
    if not _lib.has("lcBlkRefGetFirstAtt", "cdecl"):
        continue
    lcBlkRefGetFirstAtt = _lib.get("lcBlkRefGetFirstAtt", "cdecl")
    lcBlkRefGetFirstAtt.argtypes = [c_void_p]
    lcBlkRefGetFirstAtt.restype = c_void_p
    lcBlkRefGetFirstAtt.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3852
for _lib in _libs.values():
    if not _lib.has("lcBlkRefGetNextAtt", "cdecl"):
        continue
    lcBlkRefGetNextAtt = _lib.get("lcBlkRefGetNextAtt", "cdecl")
    lcBlkRefGetNextAtt.argtypes = [c_void_p, c_void_p]
    lcBlkRefGetNextAtt.restype = c_void_p
    lcBlkRefGetNextAtt.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3853
for _lib in _libs.values():
    if not _lib.has("lcBlkRefGetAtt", "cdecl"):
        continue
    lcBlkRefGetAtt = _lib.get("lcBlkRefGetAtt", "cdecl")
    lcBlkRefGetAtt.argtypes = [c_void_p, String]
    lcBlkRefGetAtt.restype = c_void_p
    lcBlkRefGetAtt.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3854
for _lib in _libs.values():
    if not _lib.has("lcBlkRefGetAttVal", "cdecl"):
        continue
    lcBlkRefGetAttVal = _lib.get("lcBlkRefGetAttVal", "cdecl")
    lcBlkRefGetAttVal.argtypes = [c_void_p, String]
    if sizeof(c_int) == sizeof(c_void_p):
        lcBlkRefGetAttVal.restype = ReturnString
    else:
        lcBlkRefGetAttVal.restype = String
        lcBlkRefGetAttVal.errcheck = ReturnString
    break

# D:\\projects\\gllc\\litecad.h: 3855
for _lib in _libs.values():
    if not _lib.has("lcBlkRefPutAttVal", "cdecl"):
        continue
    lcBlkRefPutAttVal = _lib.get("lcBlkRefPutAttVal", "cdecl")
    lcBlkRefPutAttVal.argtypes = [c_void_p, String, String]
    lcBlkRefPutAttVal.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3858
for _lib in _libs.values():
    if not _lib.has("lcShapeAddEnt", "cdecl"):
        continue
    lcShapeAddEnt = _lib.get("lcShapeAddEnt", "cdecl")
    lcShapeAddEnt.argtypes = [c_void_p, c_void_p, c_int]
    lcShapeAddEnt.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3859
for _lib in _libs.values():
    if not _lib.has("lcShapeEnd", "cdecl"):
        continue
    lcShapeEnd = _lib.get("lcShapeEnd", "cdecl")
    lcShapeEnd.argtypes = [c_void_p]
    lcShapeEnd.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3860
for _lib in _libs.values():
    if not _lib.has("lcShapeGetFirstEnt", "cdecl"):
        continue
    lcShapeGetFirstEnt = _lib.get("lcShapeGetFirstEnt", "cdecl")
    lcShapeGetFirstEnt.argtypes = [c_void_p]
    lcShapeGetFirstEnt.restype = c_void_p
    lcShapeGetFirstEnt.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3861
for _lib in _libs.values():
    if not _lib.has("lcShapeGetNextEnt", "cdecl"):
        continue
    lcShapeGetNextEnt = _lib.get("lcShapeGetNextEnt", "cdecl")
    lcShapeGetNextEnt.argtypes = [c_void_p, c_void_p]
    lcShapeGetNextEnt.restype = c_void_p
    lcShapeGetNextEnt.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3862
for _lib in _libs.values():
    if not _lib.has("lcShapeGetLastEnt", "cdecl"):
        continue
    lcShapeGetLastEnt = _lib.get("lcShapeGetLastEnt", "cdecl")
    lcShapeGetLastEnt.argtypes = [c_void_p]
    lcShapeGetLastEnt.restype = c_void_p
    lcShapeGetLastEnt.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3863
for _lib in _libs.values():
    if not _lib.has("lcShapeGetPrevEnt", "cdecl"):
        continue
    lcShapeGetPrevEnt = _lib.get("lcShapeGetPrevEnt", "cdecl")
    lcShapeGetPrevEnt.argtypes = [c_void_p, c_void_p]
    lcShapeGetPrevEnt.restype = c_void_p
    lcShapeGetPrevEnt.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3866
for _lib in _libs.values():
    if not _lib.has("lcTIN_AddPoint", "cdecl"):
        continue
    lcTIN_AddPoint = _lib.get("lcTIN_AddPoint", "cdecl")
    lcTIN_AddPoint.argtypes = [c_void_p, String, c_double, c_double, c_double]
    lcTIN_AddPoint.restype = c_void_p
    lcTIN_AddPoint.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3868
for _lib in _libs.values():
    if not _lib.has("lcTIN_PtypeGetByName", "cdecl"):
        continue
    lcTIN_PtypeGetByName = _lib.get("lcTIN_PtypeGetByName", "cdecl")
    lcTIN_PtypeGetByName.argtypes = [c_void_p, String]
    lcTIN_PtypeGetByName.restype = c_void_p
    lcTIN_PtypeGetByName.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3869
for _lib in _libs.values():
    if not _lib.has("lcTIN_PtypeGetFirst", "cdecl"):
        continue
    lcTIN_PtypeGetFirst = _lib.get("lcTIN_PtypeGetFirst", "cdecl")
    lcTIN_PtypeGetFirst.argtypes = [c_void_p]
    lcTIN_PtypeGetFirst.restype = c_void_p
    lcTIN_PtypeGetFirst.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3870
for _lib in _libs.values():
    if not _lib.has("lcTIN_PtypeGetNext", "cdecl"):
        continue
    lcTIN_PtypeGetNext = _lib.get("lcTIN_PtypeGetNext", "cdecl")
    lcTIN_PtypeGetNext.argtypes = [c_void_p, c_void_p]
    lcTIN_PtypeGetNext.restype = c_void_p
    lcTIN_PtypeGetNext.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3871
for _lib in _libs.values():
    if not _lib.has("lcTIN_PntGetFirst", "cdecl"):
        continue
    lcTIN_PntGetFirst = _lib.get("lcTIN_PntGetFirst", "cdecl")
    lcTIN_PntGetFirst.argtypes = [c_void_p]
    lcTIN_PntGetFirst.restype = c_void_p
    lcTIN_PntGetFirst.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3872
for _lib in _libs.values():
    if not _lib.has("lcTIN_PntGetNext", "cdecl"):
        continue
    lcTIN_PntGetNext = _lib.get("lcTIN_PntGetNext", "cdecl")
    lcTIN_PntGetNext.argtypes = [c_void_p, c_void_p]
    lcTIN_PntGetNext.restype = c_void_p
    lcTIN_PntGetNext.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3873
for _lib in _libs.values():
    if not _lib.has("lcTIN_PntGetNear", "cdecl"):
        continue
    lcTIN_PntGetNear = _lib.get("lcTIN_PntGetNear", "cdecl")
    lcTIN_PntGetNear.argtypes = [c_void_p, c_double, c_double]
    lcTIN_PntGetNear.restype = c_void_p
    lcTIN_PntGetNear.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3874
for _lib in _libs.values():
    if not _lib.has("lcTIN_PntDelDup", "cdecl"):
        continue
    lcTIN_PntDelDup = _lib.get("lcTIN_PntDelDup", "cdecl")
    lcTIN_PntDelDup.argtypes = [c_void_p, c_double, c_void_p]
    lcTIN_PntDelDup.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3875
for _lib in _libs.values():
    if not _lib.has("lcTIN_TriGetFirst", "cdecl"):
        continue
    lcTIN_TriGetFirst = _lib.get("lcTIN_TriGetFirst", "cdecl")
    lcTIN_TriGetFirst.argtypes = [c_void_p]
    lcTIN_TriGetFirst.restype = c_void_p
    lcTIN_TriGetFirst.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3876
for _lib in _libs.values():
    if not _lib.has("lcTIN_TriGetNext", "cdecl"):
        continue
    lcTIN_TriGetNext = _lib.get("lcTIN_TriGetNext", "cdecl")
    lcTIN_TriGetNext.argtypes = [c_void_p, c_void_p]
    lcTIN_TriGetNext.restype = c_void_p
    lcTIN_TriGetNext.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3877
for _lib in _libs.values():
    if not _lib.has("lcTIN_TriGetByPos", "cdecl"):
        continue
    lcTIN_TriGetByPos = _lib.get("lcTIN_TriGetByPos", "cdecl")
    lcTIN_TriGetByPos.argtypes = [c_void_p, c_double, c_double]
    lcTIN_TriGetByPos.restype = c_void_p
    lcTIN_TriGetByPos.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3878
for _lib in _libs.values():
    if not _lib.has("lcTIN_TriGetEdge", "cdecl"):
        continue
    lcTIN_TriGetEdge = _lib.get("lcTIN_TriGetEdge", "cdecl")
    lcTIN_TriGetEdge.argtypes = [c_void_p, c_void_p, c_int]
    lcTIN_TriGetEdge.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3879
for _lib in _libs.values():
    if not _lib.has("lcTIN_TriUpdate", "cdecl"):
        continue
    lcTIN_TriUpdate = _lib.get("lcTIN_TriUpdate", "cdecl")
    lcTIN_TriUpdate.argtypes = [c_void_p, c_void_p]
    lcTIN_TriUpdate.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3880
for _lib in _libs.values():
    if not _lib.has("lcTIN_Bnd", "cdecl"):
        continue
    lcTIN_Bnd = _lib.get("lcTIN_Bnd", "cdecl")
    lcTIN_Bnd.argtypes = [c_void_p, c_double, c_void_p]
    lcTIN_Bnd.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3881
for _lib in _libs.values():
    if not _lib.has("lcTIN_BndGetPoint", "cdecl"):
        continue
    lcTIN_BndGetPoint = _lib.get("lcTIN_BndGetPoint", "cdecl")
    lcTIN_BndGetPoint.argtypes = [c_void_p, c_int]
    lcTIN_BndGetPoint.restype = c_void_p
    lcTIN_BndGetPoint.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3882
for _lib in _libs.values():
    if not _lib.has("lcTIN_Triangulate", "cdecl"):
        continue
    lcTIN_Triangulate = _lib.get("lcTIN_Triangulate", "cdecl")
    lcTIN_Triangulate.argtypes = [c_void_p, c_void_p]
    lcTIN_Triangulate.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3883
for _lib in _libs.values():
    if not _lib.has("lcTIN_Isolines", "cdecl"):
        continue
    lcTIN_Isolines = _lib.get("lcTIN_Isolines", "cdecl")
    lcTIN_Isolines.argtypes = [c_void_p, c_double, c_int, c_void_p]
    lcTIN_Isolines.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3884
for _lib in _libs.values():
    if not _lib.has("lcTIN_IsoGetFirst", "cdecl"):
        continue
    lcTIN_IsoGetFirst = _lib.get("lcTIN_IsoGetFirst", "cdecl")
    lcTIN_IsoGetFirst.argtypes = [c_void_p]
    lcTIN_IsoGetFirst.restype = c_void_p
    lcTIN_IsoGetFirst.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3885
for _lib in _libs.values():
    if not _lib.has("lcTIN_IsoGetNext", "cdecl"):
        continue
    lcTIN_IsoGetNext = _lib.get("lcTIN_IsoGetNext", "cdecl")
    lcTIN_IsoGetNext.argtypes = [c_void_p, c_void_p]
    lcTIN_IsoGetNext.restype = c_void_p
    lcTIN_IsoGetNext.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3886
for _lib in _libs.values():
    if not _lib.has("lcTIN_IsoMakeLabels", "cdecl"):
        continue
    lcTIN_IsoMakeLabels = _lib.get("lcTIN_IsoMakeLabels", "cdecl")
    lcTIN_IsoMakeLabels.argtypes = [c_void_p]
    lcTIN_IsoMakeLabels.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3887
for _lib in _libs.values():
    if not _lib.has("lcTIN_GetIsoLabel", "cdecl"):
        continue
    lcTIN_GetIsoLabel = _lib.get("lcTIN_GetIsoLabel", "cdecl")
    lcTIN_GetIsoLabel.argtypes = [
        c_int,
        POINTER(c_double),
        POINTER(c_double),
        POINTER(c_double),
        POINTER(c_int),
    ]
    lcTIN_GetIsoLabel.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3889
for _lib in _libs.values():
    if not _lib.has("lcTIN_GetZ", "cdecl"):
        continue
    lcTIN_GetZ = _lib.get("lcTIN_GetZ", "cdecl")
    lcTIN_GetZ.argtypes = [c_void_p, c_double, c_double, POINTER(c_double)]
    lcTIN_GetZ.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3890
for _lib in _libs.values():
    if not _lib.has("lcTIN_ColorFill", "cdecl"):
        continue
    lcTIN_ColorFill = _lib.get("lcTIN_ColorFill", "cdecl")
    lcTIN_ColorFill.argtypes = [c_void_p, c_double, c_double, c_void_p]
    lcTIN_ColorFill.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3892
for _lib in _libs.values():
    if not _lib.has("lcTIN_Save", "cdecl"):
        continue
    lcTIN_Save = _lib.get("lcTIN_Save", "cdecl")
    lcTIN_Save.argtypes = [c_void_p, String, c_int, c_int, c_void_p]
    lcTIN_Save.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3894
for _lib in _libs.values():
    if not _lib.has("lcTIN_InterLine", "cdecl"):
        continue
    lcTIN_InterLine = _lib.get("lcTIN_InterLine", "cdecl")
    lcTIN_InterLine.argtypes = [c_void_p, c_double, c_double, c_double, c_double]
    lcTIN_InterLine.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3896
for _lib in _libs.values():
    if not _lib.has("lcTIN_InterGetPoint", "cdecl"):
        continue
    lcTIN_InterGetPoint = _lib.get("lcTIN_InterGetPoint", "cdecl")
    lcTIN_InterGetPoint.argtypes = [
        c_void_p,
        c_int,
        POINTER(c_double),
        POINTER(c_double),
        POINTER(c_double),
    ]
    lcTIN_InterGetPoint.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3898
for _lib in _libs.values():
    if not _lib.has("lcTIN_Clear", "cdecl"):
        continue
    lcTIN_Clear = _lib.get("lcTIN_Clear", "cdecl")
    lcTIN_Clear.argtypes = [c_void_p]
    lcTIN_Clear.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3899
for _lib in _libs.values():
    if not _lib.has("lcTIN_AddTrian", "cdecl"):
        continue
    lcTIN_AddTrian = _lib.get("lcTIN_AddTrian", "cdecl")
    lcTIN_AddTrian.argtypes = [c_void_p, c_int, c_int, c_int]
    lcTIN_AddTrian.restype = c_void_p
    lcTIN_AddTrian.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3900
for _lib in _libs.values():
    if not _lib.has("lcTIN_BndAddPnt", "cdecl"):
        continue
    lcTIN_BndAddPnt = _lib.get("lcTIN_BndAddPnt", "cdecl")
    lcTIN_BndAddPnt.argtypes = [c_void_p, c_int]
    lcTIN_BndAddPnt.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3901
for _lib in _libs.values():
    if not _lib.has("lcTIN_Merge", "cdecl"):
        continue
    lcTIN_Merge = _lib.get("lcTIN_Merge", "cdecl")
    lcTIN_Merge.argtypes = [c_void_p, String, c_void_p]
    lcTIN_Merge.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3903
for _lib in _libs.values():
    if not _lib.has("lcColorRGB", "cdecl"):
        continue
    lcColorRGB = _lib.get("lcColorRGB", "cdecl")
    lcColorRGB.argtypes = [c_int, c_int, c_int]
    lcColorRGB.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3905
for _lib in _libs.values():
    if not _lib.has("lcColorIsRGB", "cdecl"):
        continue
    lcColorIsRGB = _lib.get("lcColorIsRGB", "cdecl")
    lcColorIsRGB.argtypes = [String]
    lcColorIsRGB.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3906
for _lib in _libs.values():
    if not _lib.has("lcColorGetRed", "cdecl"):
        continue
    lcColorGetRed = _lib.get("lcColorGetRed", "cdecl")
    lcColorGetRed.argtypes = [String]
    lcColorGetRed.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3907
for _lib in _libs.values():
    if not _lib.has("lcColorGetGreen", "cdecl"):
        continue
    lcColorGetGreen = _lib.get("lcColorGetGreen", "cdecl")
    lcColorGetGreen.argtypes = [String]
    lcColorGetGreen.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3908
for _lib in _libs.values():
    if not _lib.has("lcColorGetBlue", "cdecl"):
        continue
    lcColorGetBlue = _lib.get("lcColorGetBlue", "cdecl")
    lcColorGetBlue.argtypes = [String]
    lcColorGetBlue.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3909
for _lib in _libs.values():
    if not _lib.has("lcColorGetIndex", "cdecl"):
        continue
    lcColorGetIndex = _lib.get("lcColorGetIndex", "cdecl")
    lcColorGetIndex.argtypes = [String, c_int]
    lcColorGetIndex.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3910
for _lib in _libs.values():
    if not _lib.has("lcColorToVal", "cdecl"):
        continue
    lcColorToVal = _lib.get("lcColorToVal", "cdecl")
    lcColorToVal.argtypes = [
        String,
        POINTER(c_int),
        POINTER(c_int),
        POINTER(c_int),
        POINTER(c_int),
        POINTER(c_int),
    ]
    lcColorToVal.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3913
for _lib in _libs.values():
    if not _lib.has("lcColorSetPalette", "cdecl"):
        continue
    lcColorSetPalette = _lib.get("lcColorSetPalette", "cdecl")
    lcColorSetPalette.argtypes = [c_int, c_int, c_int, c_int]
    lcColorSetPalette.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3914
for _lib in _libs.values():
    if not _lib.has("lcColorGetPalette", "cdecl"):
        continue
    lcColorGetPalette = _lib.get("lcColorGetPalette", "cdecl")
    lcColorGetPalette.argtypes = [c_int, POINTER(c_int), POINTER(c_int), POINTER(c_int)]
    lcColorGetPalette.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3915
for _lib in _libs.values():
    if not _lib.has("lcColorSavePalette", "cdecl"):
        continue
    lcColorSavePalette = _lib.get("lcColorSavePalette", "cdecl")
    lcColorSavePalette.argtypes = [String, c_void_p]
    lcColorSavePalette.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3916
for _lib in _libs.values():
    if not _lib.has("lcColorLoadPalette", "cdecl"):
        continue
    lcColorLoadPalette = _lib.get("lcColorLoadPalette", "cdecl")
    lcColorLoadPalette.argtypes = [String, c_void_p]
    lcColorLoadPalette.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3919
for _lib in _libs.values():
    if not _lib.has("lcImageSetPixelRGB", "cdecl"):
        continue
    lcImageSetPixelRGB = _lib.get("lcImageSetPixelRGB", "cdecl")
    lcImageSetPixelRGB.argtypes = [c_void_p, c_int, c_int, c_int, c_int, c_int]
    lcImageSetPixelRGB.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3921
for _lib in _libs.values():
    if not _lib.has("lcImageSetPixelI", "cdecl"):
        continue
    lcImageSetPixelI = _lib.get("lcImageSetPixelI", "cdecl")
    lcImageSetPixelI.argtypes = [c_void_p, c_int, c_int, c_int]
    lcImageSetPixelI.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3922
for _lib in _libs.values():
    if not _lib.has("lcImageGetPixelRGB", "cdecl"):
        continue
    lcImageGetPixelRGB = _lib.get("lcImageGetPixelRGB", "cdecl")
    lcImageGetPixelRGB.argtypes = [
        c_void_p,
        c_int,
        c_int,
        POINTER(c_int),
        POINTER(c_int),
        POINTER(c_int),
    ]
    lcImageGetPixelRGB.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3924
for _lib in _libs.values():
    if not _lib.has("lcImageGetPixelI", "cdecl"):
        continue
    lcImageGetPixelI = _lib.get("lcImageGetPixelI", "cdecl")
    lcImageGetPixelI.argtypes = [c_void_p, c_int, c_int, POINTER(c_int)]
    lcImageGetPixelI.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3925
for _lib in _libs.values():
    if not _lib.has("lcImageSetPalColor", "cdecl"):
        continue
    lcImageSetPalColor = _lib.get("lcImageSetPalColor", "cdecl")
    lcImageSetPalColor.argtypes = [c_void_p, c_int, c_int, c_int, c_int]
    lcImageSetPalColor.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3927
for _lib in _libs.values():
    if not _lib.has("lcImageGetPalColor", "cdecl"):
        continue
    lcImageGetPalColor = _lib.get("lcImageGetPalColor", "cdecl")
    lcImageGetPalColor.argtypes = [
        c_void_p,
        c_int,
        POINTER(c_int),
        POINTER(c_int),
        POINTER(c_int),
    ]
    lcImageGetPalColor.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3929
for _lib in _libs.values():
    if not _lib.has("lcImageLoad", "cdecl"):
        continue
    lcImageLoad = _lib.get("lcImageLoad", "cdecl")
    lcImageLoad.argtypes = [c_void_p, String, c_void_p]
    lcImageLoad.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3930
for _lib in _libs.values():
    if not _lib.has("lcImageLoadDIB", "cdecl"):
        continue
    lcImageLoadDIB = _lib.get("lcImageLoadDIB", "cdecl")
    lcImageLoadDIB.argtypes = [c_void_p, c_void_p]
    lcImageLoadDIB.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3931
for _lib in _libs.values():
    if not _lib.has("lcImageLoadCamera", "cdecl"):
        continue
    lcImageLoadCamera = _lib.get("lcImageLoadCamera", "cdecl")
    lcImageLoadCamera.argtypes = [c_void_p]
    lcImageLoadCamera.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3932
for _lib in _libs.values():
    if not _lib.has("lcImageCopyQuad", "cdecl"):
        continue
    lcImageCopyQuad = _lib.get("lcImageCopyQuad", "cdecl")
    lcImageCopyQuad.argtypes = [
        c_void_p,
        c_void_p,
        c_uint,
        c_uint,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcImageCopyQuad.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3936
for _lib in _libs.values():
    if not _lib.has("lcImageProc", "cdecl"):
        continue
    lcImageProc = _lib.get("lcImageProc", "cdecl")
    lcImageProc.argtypes = [c_void_p, c_int]
    lcImageProc.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3941
for _lib in _libs.values():
    if not _lib.has("lcExpEntity", "cdecl"):
        continue
    lcExpEntity = _lib.get("lcExpEntity", "cdecl")
    lcExpEntity.argtypes = [c_void_p, c_int, c_int, c_int]
    lcExpEntity.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3942
for _lib in _libs.values():
    if not _lib.has("lcExpGetPline", "cdecl"):
        continue
    lcExpGetPline = _lib.get("lcExpGetPline", "cdecl")
    lcExpGetPline.argtypes = [c_double]
    lcExpGetPline.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3943
for _lib in _libs.values():
    if not _lib.has("lcExpGetVertex", "cdecl"):
        continue
    lcExpGetVertex = _lib.get("lcExpGetVertex", "cdecl")
    lcExpGetVertex.argtypes = [POINTER(c_double), POINTER(c_double)]
    lcExpGetVertex.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3944
for _lib in _libs.values():
    if not _lib.has("lcExpBlock", "cdecl"):
        continue
    lcExpBlock = _lib.get("lcExpBlock", "cdecl")
    lcExpBlock.argtypes = [c_void_p, F_LCEVENT, c_int, c_void_p]
    lcExpBlock.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3946
for _lib in _libs.values():
    if not _lib.has("lcGbrLoad", "cdecl"):
        continue
    lcGbrLoad = _lib.get("lcGbrLoad", "cdecl")
    lcGbrLoad.argtypes = [c_void_p, String]
    lcGbrLoad.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3947
for _lib in _libs.values():
    if not _lib.has("lcGbrClose", "cdecl"):
        continue
    lcGbrClose = _lib.get("lcGbrClose", "cdecl")
    lcGbrClose.argtypes = [c_void_p]
    lcGbrClose.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3949
for _lib in _libs.values():
    if not _lib.has("lcPlugGetOption", "cdecl"):
        continue
    lcPlugGetOption = _lib.get("lcPlugGetOption", "cdecl")
    lcPlugGetOption.argtypes = [String, String]
    if sizeof(c_int) == sizeof(c_void_p):
        lcPlugGetOption.restype = ReturnString
    else:
        lcPlugGetOption.restype = String
        lcPlugGetOption.errcheck = ReturnString
    break

# D:\\projects\\gllc\\litecad.h: 3950
for _lib in _libs.values():
    if not _lib.has("lcPlugGetOption2", "cdecl"):
        continue
    lcPlugGetOption2 = _lib.get("lcPlugGetOption2", "cdecl")
    lcPlugGetOption2.argtypes = [String, String]
    lcPlugGetOption2.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3951
for _lib in _libs.values():
    if not _lib.has("lcPlugSetOption", "cdecl"):
        continue
    lcPlugSetOption = _lib.get("lcPlugSetOption", "cdecl")
    lcPlugSetOption.argtypes = [String, String, String, c_int]
    lcPlugSetOption.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3954
for _lib in _libs.values():
    if not _lib.has("lcPrintSetup", "cdecl"):
        continue
    lcPrintSetup = _lib.get("lcPrintSetup", "cdecl")
    lcPrintSetup.argtypes = [c_void_p]
    lcPrintSetup.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3955
for _lib in _libs.values():
    if not _lib.has("lcPrintLayout", "cdecl"):
        continue
    lcPrintLayout = _lib.get("lcPrintLayout", "cdecl")
    lcPrintLayout.argtypes = [c_void_p]
    lcPrintLayout.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3956
for _lib in _libs.values():
    if not _lib.has("lcPrintBlock", "cdecl"):
        continue
    lcPrintBlock = _lib.get("lcPrintBlock", "cdecl")
    lcPrintBlock.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
    ]
    lcPrintBlock.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3959
for _lib in _libs.values():
    if not _lib.has("lcXDataBegin", "cdecl"):
        continue
    lcXDataBegin = _lib.get("lcXDataBegin", "cdecl")
    lcXDataBegin.argtypes = []
    lcXDataBegin.restype = c_void_p
    lcXDataBegin.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3960
for _lib in _libs.values():
    if not _lib.has("lcXDataEnd", "cdecl"):
        continue
    lcXDataEnd = _lib.get("lcXDataEnd", "cdecl")
    lcXDataEnd.argtypes = [c_void_p]
    lcXDataEnd.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3961
for _lib in _libs.values():
    if not _lib.has("lcXDataClear", "cdecl"):
        continue
    lcXDataClear = _lib.get("lcXDataClear", "cdecl")
    lcXDataClear.argtypes = [c_void_p]
    lcXDataClear.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3962
for _lib in _libs.values():
    if not _lib.has("lcXDataSet", "cdecl"):
        continue
    lcXDataSet = _lib.get("lcXDataSet", "cdecl")
    lcXDataSet.argtypes = [c_void_p]
    lcXDataSet.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3968
for _lib in _libs.values():
    if not _lib.has("lcWndTabClear", "cdecl"):
        continue
    lcWndTabClear = _lib.get("lcWndTabClear", "cdecl")
    lcWndTabClear.argtypes = [c_void_p]
    lcWndTabClear.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3969
for _lib in _libs.values():
    if not _lib.has("lcWndTabAdd", "cdecl"):
        continue
    lcWndTabAdd = _lib.get("lcWndTabAdd", "cdecl")
    lcWndTabAdd.argtypes = [c_void_p, c_int, String, String, c_void_p]
    lcWndTabAdd.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3971
for _lib in _libs.values():
    if not _lib.has("lcWndTabSelect", "cdecl"):
        continue
    lcWndTabSelect = _lib.get("lcWndTabSelect", "cdecl")
    lcWndTabSelect.argtypes = [c_void_p, c_int]
    lcWndTabSelect.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3974
for _lib in _libs.values():
    if not _lib.has("lcWndPaperEnable", "cdecl"):
        continue
    lcWndPaperEnable = _lib.get("lcWndPaperEnable", "cdecl")
    lcWndPaperEnable.argtypes = [c_void_p, c_int]
    lcWndPaperEnable.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3975
for _lib in _libs.values():
    if not _lib.has("lcWndPaperSetSize", "cdecl"):
        continue
    lcWndPaperSetSize = _lib.get("lcWndPaperSetSize", "cdecl")
    lcWndPaperSetSize.argtypes = [c_void_p, c_int, c_int]
    lcWndPaperSetSize.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3976
for _lib in _libs.values():
    if not _lib.has("lcWndPaperSetSize2", "cdecl"):
        continue
    lcWndPaperSetSize2 = _lib.get("lcWndPaperSetSize2", "cdecl")
    lcWndPaperSetSize2.argtypes = [c_void_p, c_double, c_double]
    lcWndPaperSetSize2.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3977
for _lib in _libs.values():
    if not _lib.has("lcWndPaperSetPos", "cdecl"):
        continue
    lcWndPaperSetPos = _lib.get("lcWndPaperSetPos", "cdecl")
    lcWndPaperSetPos.argtypes = [c_void_p, c_double, c_double]
    lcWndPaperSetPos.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3980
for _lib in _libs.values():
    if not _lib.has("lcGripClear", "cdecl"):
        continue
    lcGripClear = _lib.get("lcGripClear", "cdecl")
    lcGripClear.argtypes = [c_void_p]
    lcGripClear.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3981
for _lib in _libs.values():
    if not _lib.has("lcGripAdd", "cdecl"):
        continue
    lcGripAdd = _lib.get("lcGripAdd", "cdecl")
    lcGripAdd.argtypes = [
        c_void_p,
        c_void_p,
        c_int,
        c_int,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcGripAdd.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3983
for _lib in _libs.values():
    if not _lib.has("lcGripSet", "cdecl"):
        continue
    lcGripSet = _lib.get("lcGripSet", "cdecl")
    lcGripSet.argtypes = [
        c_void_p,
        c_void_p,
        c_int,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcGripSet.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3987
for _lib in _libs.values():
    if not _lib.has("lcPaint_PenCreate", "cdecl"):
        continue
    lcPaint_PenCreate = _lib.get("lcPaint_PenCreate", "cdecl")
    lcPaint_PenCreate.argtypes = [c_void_p, c_int, c_int, c_double, c_int]
    lcPaint_PenCreate.restype = c_void_p
    lcPaint_PenCreate.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3989
for _lib in _libs.values():
    if not _lib.has("lcPaint_PenSelect", "cdecl"):
        continue
    lcPaint_PenSelect = _lib.get("lcPaint_PenSelect", "cdecl")
    lcPaint_PenSelect.argtypes = [c_void_p, c_void_p]
    lcPaint_PenSelect.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3990
for _lib in _libs.values():
    if not _lib.has("lcPaint_PenSelectID", "cdecl"):
        continue
    lcPaint_PenSelectID = _lib.get("lcPaint_PenSelectID", "cdecl")
    lcPaint_PenSelectID.argtypes = [c_void_p, c_int]
    lcPaint_PenSelectID.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3991
for _lib in _libs.values():
    if not _lib.has("lcPaint_BrushCreate", "cdecl"):
        continue
    lcPaint_BrushCreate = _lib.get("lcPaint_BrushCreate", "cdecl")
    lcPaint_BrushCreate.argtypes = [c_void_p, c_int, c_int, c_int, c_int]
    lcPaint_BrushCreate.restype = c_void_p
    lcPaint_BrushCreate.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 3993
for _lib in _libs.values():
    if not _lib.has("lcPaint_BrushSelect", "cdecl"):
        continue
    lcPaint_BrushSelect = _lib.get("lcPaint_BrushSelect", "cdecl")
    lcPaint_BrushSelect.argtypes = [c_void_p, c_void_p]
    lcPaint_BrushSelect.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3994
for _lib in _libs.values():
    if not _lib.has("lcPaint_BrushSelectID", "cdecl"):
        continue
    lcPaint_BrushSelectID = _lib.get("lcPaint_BrushSelectID", "cdecl")
    lcPaint_BrushSelectID.argtypes = [c_void_p, c_int]
    lcPaint_BrushSelectID.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3996
for _lib in _libs.values():
    if not _lib.has("lcPaint_DrawPtbuf", "cdecl"):
        continue
    lcPaint_DrawPtbuf = _lib.get("lcPaint_DrawPtbuf", "cdecl")
    lcPaint_DrawPtbuf.argtypes = [c_void_p, c_void_p, c_int]
    lcPaint_DrawPtbuf.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3997
for _lib in _libs.values():
    if not _lib.has("lcPaint_DrawMpgon", "cdecl"):
        continue
    lcPaint_DrawMpgon = _lib.get("lcPaint_DrawMpgon", "cdecl")
    lcPaint_DrawMpgon.argtypes = [c_void_p, c_void_p, c_int, c_int]
    lcPaint_DrawMpgon.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 3998
for _lib in _libs.values():
    if not _lib.has("lcPaint_DrawImage", "cdecl"):
        continue
    lcPaint_DrawImage = _lib.get("lcPaint_DrawImage", "cdecl")
    lcPaint_DrawImage.argtypes = [
        c_void_p,
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_int,
        c_int,
        c_void_p,
    ]
    lcPaint_DrawImage.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4001
for _lib in _libs.values():
    if not _lib.has("lcPaint_DrawImage2", "cdecl"):
        continue
    lcPaint_DrawImage2 = _lib.get("lcPaint_DrawImage2", "cdecl")
    lcPaint_DrawImage2.argtypes = [
        c_void_p,
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
        c_int,
        c_void_p,
    ]
    lcPaint_DrawImage2.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4004
for _lib in _libs.values():
    if not _lib.has("lcPaint_DrawText", "cdecl"):
        continue
    lcPaint_DrawText = _lib.get("lcPaint_DrawText", "cdecl")
    lcPaint_DrawText.argtypes = [c_void_p, c_double, c_double, String]
    lcPaint_DrawText.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4005
for _lib in _libs.values():
    if not _lib.has("lcPaint_DrawText2", "cdecl"):
        continue
    lcPaint_DrawText2 = _lib.get("lcPaint_DrawText2", "cdecl")
    lcPaint_DrawText2.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
        String,
    ]
    lcPaint_DrawText2.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4007
for _lib in _libs.values():
    if not _lib.has("lcPaint_DrawTextBC", "cdecl"):
        continue
    lcPaint_DrawTextBC = _lib.get("lcPaint_DrawTextBC", "cdecl")
    lcPaint_DrawTextBC.argtypes = [
        c_void_p,
        c_void_p,
        c_double,
        c_double,
        c_int,
        String,
    ]
    lcPaint_DrawTextBC.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4009
for _lib in _libs.values():
    if not _lib.has("lcPaint_DrawArcText", "cdecl"):
        continue
    lcPaint_DrawArcText = _lib.get("lcPaint_DrawArcText", "cdecl")
    lcPaint_DrawArcText.argtypes = [
        c_void_p,
        String,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
        c_double,
        c_double,
        c_int,
    ]
    lcPaint_DrawArcText.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4012
for _lib in _libs.values():
    if not _lib.has("lcPaint_DrawHatch", "cdecl"):
        continue
    lcPaint_DrawHatch = _lib.get("lcPaint_DrawHatch", "cdecl")
    lcPaint_DrawHatch.argtypes = [c_void_p, c_void_p]
    lcPaint_DrawHatch.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4013
for _lib in _libs.values():
    if not _lib.has("lcPaint_DrawPoint", "cdecl"):
        continue
    lcPaint_DrawPoint = _lib.get("lcPaint_DrawPoint", "cdecl")
    lcPaint_DrawPoint.argtypes = [c_void_p, c_double, c_double, c_int, c_double]
    lcPaint_DrawPoint.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4015
for _lib in _libs.values():
    if not _lib.has("lcPaint_DrawLine", "cdecl"):
        continue
    lcPaint_DrawLine = _lib.get("lcPaint_DrawLine", "cdecl")
    lcPaint_DrawLine.argtypes = [c_void_p, c_double, c_double, c_double, c_double]
    lcPaint_DrawLine.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4017
for _lib in _libs.values():
    if not _lib.has("lcPaint_DrawXline", "cdecl"):
        continue
    lcPaint_DrawXline = _lib.get("lcPaint_DrawXline", "cdecl")
    lcPaint_DrawXline.argtypes = [c_void_p, c_double, c_double, c_double, c_int]
    lcPaint_DrawXline.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4019
for _lib in _libs.values():
    if not _lib.has("lcPaint_DrawRect", "cdecl"):
        continue
    lcPaint_DrawRect = _lib.get("lcPaint_DrawRect", "cdecl")
    lcPaint_DrawRect.argtypes = [c_void_p, c_double, c_double, c_double, c_double]
    lcPaint_DrawRect.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4021
for _lib in _libs.values():
    if not _lib.has("lcPaint_DrawRect2", "cdecl"):
        continue
    lcPaint_DrawRect2 = _lib.get("lcPaint_DrawRect2", "cdecl")
    lcPaint_DrawRect2.argtypes = [c_void_p, c_double, c_double, c_double, c_double]
    lcPaint_DrawRect2.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4023
for _lib in _libs.values():
    if not _lib.has("lcPaint_DrawPickBox", "cdecl"):
        continue
    lcPaint_DrawPickBox = _lib.get("lcPaint_DrawPickBox", "cdecl")
    lcPaint_DrawPickBox.argtypes = [c_void_p]
    lcPaint_DrawPickBox.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4024
for _lib in _libs.values():
    if not _lib.has("lcPaint_DrawGrid", "cdecl"):
        continue
    lcPaint_DrawGrid = _lib.get("lcPaint_DrawGrid", "cdecl")
    lcPaint_DrawGrid.argtypes = [c_void_p, c_void_p, c_int, c_int, c_int]
    lcPaint_DrawGrid.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4026
for _lib in _libs.values():
    if not _lib.has("lcPaint_DrawCPrompt", "cdecl"):
        continue
    lcPaint_DrawCPrompt = _lib.get("lcPaint_DrawCPrompt", "cdecl")
    lcPaint_DrawCPrompt.argtypes = [c_void_p, c_int, c_int, c_int, String]
    lcPaint_DrawCPrompt.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4028
for _lib in _libs.values():
    if not _lib.has("lcPaint_SetPixel", "cdecl"):
        continue
    lcPaint_SetPixel = _lib.get("lcPaint_SetPixel", "cdecl")
    lcPaint_SetPixel.argtypes = [c_void_p, c_int, c_int, c_int]
    lcPaint_SetPixel.restype = None
    break

# D:\\projects\\gllc\\litecad.h: 4031
for _lib in _libs.values():
    if not _lib.has("lcPaint_CreatePtbuf", "cdecl"):
        continue
    lcPaint_CreatePtbuf = _lib.get("lcPaint_CreatePtbuf", "cdecl")
    lcPaint_CreatePtbuf.argtypes = []
    lcPaint_CreatePtbuf.restype = c_void_p
    lcPaint_CreatePtbuf.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 4032
for _lib in _libs.values():
    if not _lib.has("lcPaint_DeletePtbuf", "cdecl"):
        continue
    lcPaint_DeletePtbuf = _lib.get("lcPaint_DeletePtbuf", "cdecl")
    lcPaint_DeletePtbuf.argtypes = [c_void_p]
    lcPaint_DeletePtbuf.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4033
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufClear", "cdecl"):
        continue
    lcPaint_PtbufClear = _lib.get("lcPaint_PtbufClear", "cdecl")
    lcPaint_PtbufClear.argtypes = [c_void_p]
    lcPaint_PtbufClear.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4034
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddPoint", "cdecl"):
        continue
    lcPaint_PtbufAddPoint = _lib.get("lcPaint_PtbufAddPoint", "cdecl")
    lcPaint_PtbufAddPoint.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
    ]
    lcPaint_PtbufAddPoint.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4036
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddPoint2", "cdecl"):
        continue
    lcPaint_PtbufAddPoint2 = _lib.get("lcPaint_PtbufAddPoint2", "cdecl")
    lcPaint_PtbufAddPoint2.argtypes = [c_void_p, c_double, c_double]
    lcPaint_PtbufAddPoint2.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4037
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddPointP", "cdecl"):
        continue
    lcPaint_PtbufAddPointP = _lib.get("lcPaint_PtbufAddPointP", "cdecl")
    lcPaint_PtbufAddPointP.argtypes = [c_void_p, c_double, c_double]
    lcPaint_PtbufAddPointP.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4038
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddLine", "cdecl"):
        continue
    lcPaint_PtbufAddLine = _lib.get("lcPaint_PtbufAddLine", "cdecl")
    lcPaint_PtbufAddLine.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcPaint_PtbufAddLine.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4040
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddLineP", "cdecl"):
        continue
    lcPaint_PtbufAddLineP = _lib.get("lcPaint_PtbufAddLineP", "cdecl")
    lcPaint_PtbufAddLineP.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcPaint_PtbufAddLineP.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4042
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddCircle", "cdecl"):
        continue
    lcPaint_PtbufAddCircle = _lib.get("lcPaint_PtbufAddCircle", "cdecl")
    lcPaint_PtbufAddCircle.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_int,
    ]
    lcPaint_PtbufAddCircle.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4044
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddCircle2", "cdecl"):
        continue
    lcPaint_PtbufAddCircle2 = _lib.get("lcPaint_PtbufAddCircle2", "cdecl")
    lcPaint_PtbufAddCircle2.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
    ]
    lcPaint_PtbufAddCircle2.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4046
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddCircle3", "cdecl"):
        continue
    lcPaint_PtbufAddCircle3 = _lib.get("lcPaint_PtbufAddCircle3", "cdecl")
    lcPaint_PtbufAddCircle3.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
        c_int,
    ]
    lcPaint_PtbufAddCircle3.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4049
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddArc", "cdecl"):
        continue
    lcPaint_PtbufAddArc = _lib.get("lcPaint_PtbufAddArc", "cdecl")
    lcPaint_PtbufAddArc.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
    ]
    lcPaint_PtbufAddArc.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4051
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddArc3p", "cdecl"):
        continue
    lcPaint_PtbufAddArc3p = _lib.get("lcPaint_PtbufAddArc3p", "cdecl")
    lcPaint_PtbufAddArc3p.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
    ]
    lcPaint_PtbufAddArc3p.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4053
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddArcSDE", "cdecl"):
        continue
    lcPaint_PtbufAddArcSDE = _lib.get("lcPaint_PtbufAddArcSDE", "cdecl")
    lcPaint_PtbufAddArcSDE.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
    ]
    lcPaint_PtbufAddArcSDE.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4056
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddArcSDAR", "cdecl"):
        continue
    lcPaint_PtbufAddArcSDAR = _lib.get("lcPaint_PtbufAddArcSDAR", "cdecl")
    lcPaint_PtbufAddArcSDAR.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
    ]
    lcPaint_PtbufAddArcSDAR.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4059
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddArcSER", "cdecl"):
        continue
    lcPaint_PtbufAddArcSER = _lib.get("lcPaint_PtbufAddArcSER", "cdecl")
    lcPaint_PtbufAddArcSER.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
        c_int,
    ]
    lcPaint_PtbufAddArcSER.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4062
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddArcSEL", "cdecl"):
        continue
    lcPaint_PtbufAddArcSEL = _lib.get("lcPaint_PtbufAddArcSEL", "cdecl")
    lcPaint_PtbufAddArcSEL.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
        c_int,
    ]
    lcPaint_PtbufAddArcSEL.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4065
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddArcSEA", "cdecl"):
        continue
    lcPaint_PtbufAddArcSEA = _lib.get("lcPaint_PtbufAddArcSEA", "cdecl")
    lcPaint_PtbufAddArcSEA.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
    ]
    lcPaint_PtbufAddArcSEA.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4067
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddArcSEB", "cdecl"):
        continue
    lcPaint_PtbufAddArcSEB = _lib.get("lcPaint_PtbufAddArcSEB", "cdecl")
    lcPaint_PtbufAddArcSEB.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
    ]
    lcPaint_PtbufAddArcSEB.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4069
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddArcCSE", "cdecl"):
        continue
    lcPaint_PtbufAddArcCSE = _lib.get("lcPaint_PtbufAddArcCSE", "cdecl")
    lcPaint_PtbufAddArcCSE.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
        c_int,
    ]
    lcPaint_PtbufAddArcCSE.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4072
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddArcCSA", "cdecl"):
        continue
    lcPaint_PtbufAddArcCSA = _lib.get("lcPaint_PtbufAddArcCSA", "cdecl")
    lcPaint_PtbufAddArcCSA.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
    ]
    lcPaint_PtbufAddArcCSA.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4074
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddArcCSL", "cdecl"):
        continue
    lcPaint_PtbufAddArcCSL = _lib.get("lcPaint_PtbufAddArcCSL", "cdecl")
    lcPaint_PtbufAddArcCSL.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
        c_int,
    ]
    lcPaint_PtbufAddArcCSL.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4077
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddArcCRAA", "cdecl"):
        continue
    lcPaint_PtbufAddArcCRAA = _lib.get("lcPaint_PtbufAddArcCRAA", "cdecl")
    lcPaint_PtbufAddArcCRAA.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
        c_int,
    ]
    lcPaint_PtbufAddArcCRAA.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4080
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddEllipse", "cdecl"):
        continue
    lcPaint_PtbufAddEllipse = _lib.get("lcPaint_PtbufAddEllipse", "cdecl")
    lcPaint_PtbufAddEllipse.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
    ]
    lcPaint_PtbufAddEllipse.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4083
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddEllipse2", "cdecl"):
        continue
    lcPaint_PtbufAddEllipse2 = _lib.get("lcPaint_PtbufAddEllipse2", "cdecl")
    lcPaint_PtbufAddEllipse2.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
    ]
    lcPaint_PtbufAddEllipse2.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4085
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddRect", "cdecl"):
        continue
    lcPaint_PtbufAddRect = _lib.get("lcPaint_PtbufAddRect", "cdecl")
    lcPaint_PtbufAddRect.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
    ]
    lcPaint_PtbufAddRect.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4087
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddRect2", "cdecl"):
        continue
    lcPaint_PtbufAddRect2 = _lib.get("lcPaint_PtbufAddRect2", "cdecl")
    lcPaint_PtbufAddRect2.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
    ]
    lcPaint_PtbufAddRect2.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4089
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddRect3", "cdecl"):
        continue
    lcPaint_PtbufAddRect3 = _lib.get("lcPaint_PtbufAddRect3", "cdecl")
    lcPaint_PtbufAddRect3.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
        c_double,
        c_int,
    ]
    lcPaint_PtbufAddRect3.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4092
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddWline", "cdecl"):
        continue
    lcPaint_PtbufAddWline = _lib.get("lcPaint_PtbufAddWline", "cdecl")
    lcPaint_PtbufAddWline.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
        c_double,
        c_int,
        c_int,
        c_int,
    ]
    lcPaint_PtbufAddWline.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4095
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufAddPtbuf", "cdecl"):
        continue
    lcPaint_PtbufAddPtbuf = _lib.get("lcPaint_PtbufAddPtbuf", "cdecl")
    lcPaint_PtbufAddPtbuf.argtypes = [c_void_p, c_void_p]
    lcPaint_PtbufAddPtbuf.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4096
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufGetPoint", "cdecl"):
        continue
    lcPaint_PtbufGetPoint = _lib.get("lcPaint_PtbufGetPoint", "cdecl")
    lcPaint_PtbufGetPoint.argtypes = [
        c_void_p,
        c_int,
        POINTER(c_double),
        POINTER(c_double),
    ]
    lcPaint_PtbufGetPoint.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4097
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufGetPoint2", "cdecl"):
        continue
    lcPaint_PtbufGetPoint2 = _lib.get("lcPaint_PtbufGetPoint2", "cdecl")
    lcPaint_PtbufGetPoint2.argtypes = [
        c_void_p,
        c_int,
        POINTER(c_double),
        POINTER(c_double),
        POINTER(c_double),
        POINTER(c_double),
        POINTER(c_int),
    ]
    lcPaint_PtbufGetPoint2.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4099
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufInterpolate", "cdecl"):
        continue
    lcPaint_PtbufInterpolate = _lib.get("lcPaint_PtbufInterpolate", "cdecl")
    lcPaint_PtbufInterpolate.argtypes = [
        c_void_p,
        c_int,
        c_void_p,
        c_int,
        c_int,
    ]
    lcPaint_PtbufInterpolate.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4101
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufMove", "cdecl"):
        continue
    lcPaint_PtbufMove = _lib.get("lcPaint_PtbufMove", "cdecl")
    lcPaint_PtbufMove.argtypes = [c_void_p, c_double, c_double]
    lcPaint_PtbufMove.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4102
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufRotate", "cdecl"):
        continue
    lcPaint_PtbufRotate = _lib.get("lcPaint_PtbufRotate", "cdecl")
    lcPaint_PtbufRotate.argtypes = [c_void_p, c_double, c_double, c_double]
    lcPaint_PtbufRotate.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4103
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufScale", "cdecl"):
        continue
    lcPaint_PtbufScale = _lib.get("lcPaint_PtbufScale", "cdecl")
    lcPaint_PtbufScale.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcPaint_PtbufScale.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4105
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufMirror", "cdecl"):
        continue
    lcPaint_PtbufMirror = _lib.get("lcPaint_PtbufMirror", "cdecl")
    lcPaint_PtbufMirror.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcPaint_PtbufMirror.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4107
for _lib in _libs.values():
    if not _lib.has("lcPaint_PtbufCopy", "cdecl"):
        continue
    lcPaint_PtbufCopy = _lib.get("lcPaint_PtbufCopy", "cdecl")
    lcPaint_PtbufCopy.argtypes = [c_void_p, c_void_p]
    lcPaint_PtbufCopy.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4110
for _lib in _libs.values():
    if not _lib.has("lcPaint_CreateMpgon", "cdecl"):
        continue
    lcPaint_CreateMpgon = _lib.get("lcPaint_CreateMpgon", "cdecl")
    lcPaint_CreateMpgon.argtypes = []
    lcPaint_CreateMpgon.restype = c_void_p
    lcPaint_CreateMpgon.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 4111
for _lib in _libs.values():
    if not _lib.has("lcPaint_DeleteMpgon", "cdecl"):
        continue
    lcPaint_DeleteMpgon = _lib.get("lcPaint_DeleteMpgon", "cdecl")
    lcPaint_DeleteMpgon.argtypes = [c_void_p]
    lcPaint_DeleteMpgon.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4112
for _lib in _libs.values():
    if not _lib.has("lcPaint_MpgonClear", "cdecl"):
        continue
    lcPaint_MpgonClear = _lib.get("lcPaint_MpgonClear", "cdecl")
    lcPaint_MpgonClear.argtypes = [c_void_p]
    lcPaint_MpgonClear.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4113
for _lib in _libs.values():
    if not _lib.has("lcPaint_MpgonAddPgon", "cdecl"):
        continue
    lcPaint_MpgonAddPgon = _lib.get("lcPaint_MpgonAddPgon", "cdecl")
    lcPaint_MpgonAddPgon.argtypes = [c_void_p, c_void_p]
    lcPaint_MpgonAddPgon.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4114
for _lib in _libs.values():
    if not _lib.has("lcPaint_MpgonAddText", "cdecl"):
        continue
    lcPaint_MpgonAddText = _lib.get("lcPaint_MpgonAddText", "cdecl")
    lcPaint_MpgonAddText.argtypes = [
        c_void_p,
        c_void_p,
        c_double,
        c_double,
        String,
        c_int,
    ]
    lcPaint_MpgonAddText.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4116
for _lib in _libs.values():
    if not _lib.has("lcPaint_MpgonAddBarcode", "cdecl"):
        continue
    lcPaint_MpgonAddBarcode = _lib.get("lcPaint_MpgonAddBarcode", "cdecl")
    lcPaint_MpgonAddBarcode.argtypes = [
        c_void_p,
        c_int,
        c_double,
        c_double,
        c_double,
        c_double,
        String,
    ]
    lcPaint_MpgonAddBarcode.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4119
for _lib in _libs.values():
    if not _lib.has("lcPaint_MpgonMove", "cdecl"):
        continue
    lcPaint_MpgonMove = _lib.get("lcPaint_MpgonMove", "cdecl")
    lcPaint_MpgonMove.argtypes = [c_void_p, c_double, c_double]
    lcPaint_MpgonMove.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4120
for _lib in _libs.values():
    if not _lib.has("lcPaint_MpgonRotate", "cdecl"):
        continue
    lcPaint_MpgonRotate = _lib.get("lcPaint_MpgonRotate", "cdecl")
    lcPaint_MpgonRotate.argtypes = [c_void_p, c_double, c_double, c_double]
    lcPaint_MpgonRotate.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4121
for _lib in _libs.values():
    if not _lib.has("lcPaint_MpgonScale", "cdecl"):
        continue
    lcPaint_MpgonScale = _lib.get("lcPaint_MpgonScale", "cdecl")
    lcPaint_MpgonScale.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcPaint_MpgonScale.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4123
for _lib in _libs.values():
    if not _lib.has("lcPaint_MpgonMirror", "cdecl"):
        continue
    lcPaint_MpgonMirror = _lib.get("lcPaint_MpgonMirror", "cdecl")
    lcPaint_MpgonMirror.argtypes = [
        c_void_p,
        c_double,
        c_double,
        c_double,
        c_double,
    ]
    lcPaint_MpgonMirror.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4125
for _lib in _libs.values():
    if not _lib.has("lcPaint_MpgonCopy", "cdecl"):
        continue
    lcPaint_MpgonCopy = _lib.get("lcPaint_MpgonCopy", "cdecl")
    lcPaint_MpgonCopy.argtypes = [c_void_p, c_void_p]
    lcPaint_MpgonCopy.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4127
for _lib in _libs.values():
    if not _lib.has("lcPaint_HatchGen", "cdecl"):
        continue
    lcPaint_HatchGen = _lib.get("lcPaint_HatchGen", "cdecl")
    lcPaint_HatchGen.argtypes = [
        c_void_p,
        c_void_p,
        c_double,
        c_double,
        c_double,
    ]
    lcPaint_HatchGen.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4131
for _lib in _libs.values():
    if not _lib.has("lcPaint_ImageAdd", "cdecl"):
        continue
    lcPaint_ImageAdd = _lib.get("lcPaint_ImageAdd", "cdecl")
    lcPaint_ImageAdd.argtypes = [c_int]
    lcPaint_ImageAdd.restype = c_void_p
    lcPaint_ImageAdd.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 4132
for _lib in _libs.values():
    if not _lib.has("lcPaint_ImageDelete", "cdecl"):
        continue
    lcPaint_ImageDelete = _lib.get("lcPaint_ImageDelete", "cdecl")
    lcPaint_ImageDelete.argtypes = [c_void_p]
    lcPaint_ImageDelete.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4133
for _lib in _libs.values():
    if not _lib.has("lcPaint_ImageGetFirst", "cdecl"):
        continue
    lcPaint_ImageGetFirst = _lib.get("lcPaint_ImageGetFirst", "cdecl")
    lcPaint_ImageGetFirst.argtypes = []
    lcPaint_ImageGetFirst.restype = c_void_p
    lcPaint_ImageGetFirst.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 4134
for _lib in _libs.values():
    if not _lib.has("lcPaint_ImageGetNext", "cdecl"):
        continue
    lcPaint_ImageGetNext = _lib.get("lcPaint_ImageGetNext", "cdecl")
    lcPaint_ImageGetNext.argtypes = [c_void_p]
    lcPaint_ImageGetNext.restype = c_void_p
    lcPaint_ImageGetNext.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 4135
for _lib in _libs.values():
    if not _lib.has("lcPaint_ImageGetByID", "cdecl"):
        continue
    lcPaint_ImageGetByID = _lib.get("lcPaint_ImageGetByID", "cdecl")
    lcPaint_ImageGetByID.argtypes = [c_int]
    lcPaint_ImageGetByID.restype = c_void_p
    lcPaint_ImageGetByID.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 4136
for _lib in _libs.values():
    if not _lib.has("lcPaint_ImageLoad", "cdecl"):
        continue
    lcPaint_ImageLoad = _lib.get("lcPaint_ImageLoad", "cdecl")
    lcPaint_ImageLoad.argtypes = [c_void_p, String]
    lcPaint_ImageLoad.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4137
for _lib in _libs.values():
    if not _lib.has("lcPaint_ImageCopy", "cdecl"):
        continue
    lcPaint_ImageCopy = _lib.get("lcPaint_ImageCopy", "cdecl")
    lcPaint_ImageCopy.argtypes = [c_void_p, c_void_p]
    lcPaint_ImageCopy.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4138
for _lib in _libs.values():
    if not _lib.has("lcPaint_ImageCreate", "cdecl"):
        continue
    lcPaint_ImageCreate = _lib.get("lcPaint_ImageCreate", "cdecl")
    lcPaint_ImageCreate.argtypes = [c_void_p, c_int, c_int]
    lcPaint_ImageCreate.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4139
for _lib in _libs.values():
    if not _lib.has("lcPaint_ImageSetPixel", "cdecl"):
        continue
    lcPaint_ImageSetPixel = _lib.get("lcPaint_ImageSetPixel", "cdecl")
    lcPaint_ImageSetPixel.argtypes = [c_void_p, c_int, c_int, c_int, c_int, c_int]
    lcPaint_ImageSetPixel.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4141
for _lib in _libs.values():
    if not _lib.has("lcPaint_ImageFlip", "cdecl"):
        continue
    lcPaint_ImageFlip = _lib.get("lcPaint_ImageFlip", "cdecl")
    lcPaint_ImageFlip.argtypes = [c_void_p, c_int, c_int]
    lcPaint_ImageFlip.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4142
for _lib in _libs.values():
    if not _lib.has("lcPaint_ImageRotate", "cdecl"):
        continue
    lcPaint_ImageRotate = _lib.get("lcPaint_ImageRotate", "cdecl")
    lcPaint_ImageRotate.argtypes = [c_void_p, c_double]
    lcPaint_ImageRotate.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4143
for _lib in _libs.values():
    if not _lib.has("lcPaint_ImageGray", "cdecl"):
        continue
    lcPaint_ImageGray = _lib.get("lcPaint_ImageGray", "cdecl")
    lcPaint_ImageGray.argtypes = [c_void_p]
    lcPaint_ImageGray.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4144
for _lib in _libs.values():
    if not _lib.has("lcPaint_ImageResize", "cdecl"):
        continue
    lcPaint_ImageResize = _lib.get("lcPaint_ImageResize", "cdecl")
    lcPaint_ImageResize.argtypes = [c_void_p, c_int, c_int, c_int]
    lcPaint_ImageResize.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4146
for _lib in _libs.values():
    if not _lib.has("lcPaint_ImageGetPtbuf", "cdecl"):
        continue
    lcPaint_ImageGetPtbuf = _lib.get("lcPaint_ImageGetPtbuf", "cdecl")
    lcPaint_ImageGetPtbuf.argtypes = [c_void_p, c_double]
    lcPaint_ImageGetPtbuf.restype = c_void_p
    lcPaint_ImageGetPtbuf.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 4148
for _lib in _libs.values():
    if not _lib.has("lcPaint_FontOpenLC", "cdecl"):
        continue
    lcPaint_FontOpenLC = _lib.get("lcPaint_FontOpenLC", "cdecl")
    lcPaint_FontOpenLC.argtypes = [String]
    lcPaint_FontOpenLC.restype = c_void_p
    lcPaint_FontOpenLC.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 4149
for _lib in _libs.values():
    if not _lib.has("lcPaint_FontOpenTT", "cdecl"):
        continue
    lcPaint_FontOpenTT = _lib.get("lcPaint_FontOpenTT", "cdecl")
    lcPaint_FontOpenTT.argtypes = [String, c_int, c_int]
    lcPaint_FontOpenTT.restype = c_void_p
    lcPaint_FontOpenTT.errcheck = lambda v, *a: cast(v, c_void_p)
    break

# D:\\projects\\gllc\\litecad.h: 4150
for _lib in _libs.values():
    if not _lib.has("lcPaint_FontClose", "cdecl"):
        continue
    lcPaint_FontClose = _lib.get("lcPaint_FontClose", "cdecl")
    lcPaint_FontClose.argtypes = [c_void_p]
    lcPaint_FontClose.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4151
for _lib in _libs.values():
    if not _lib.has("lcPaint_FontSelect", "cdecl"):
        continue
    lcPaint_FontSelect = _lib.get("lcPaint_FontSelect", "cdecl")
    lcPaint_FontSelect.argtypes = [c_void_p, c_void_p]
    lcPaint_FontSelect.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4153
for _lib in _libs.values():
    if not _lib.has("lcLoadLib", "cdecl"):
        continue
    lcLoadLib = _lib.get("lcLoadLib", "cdecl")
    lcLoadLib.argtypes = [String]
    lcLoadLib.restype = c_int
    break

# D:\\projects\\gllc\\litecad.h: 4154
for _lib in _libs.values():
    if not _lib.has("lcFreeLib", "cdecl"):
        continue
    lcFreeLib = _lib.get("lcFreeLib", "cdecl")
    lcFreeLib.argtypes = []
    lcFreeLib.restype = None
    break

# D:\\projects\\gllc\\litecad.h: 11
try:
    LC_FALSE = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 12
try:
    LC_TRUE = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 15
try:
    LC_WS_HSCROLL = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 16
try:
    LC_WS_VSCROLL = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 17
try:
    LC_WS_BORDER = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 18
try:
    LC_WS_CLIENTEDGE = 8
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 19
try:
    LC_WS_SUNKEN = 8
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 20
try:
    LC_WS_STATICEDGE = 16
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 21
try:
    LC_WS_RULERS = 256
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 22
try:
    LC_WS_VIEWTABS = 512
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 24
try:
    LC_WS_FILETABS = 1024
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 26
try:
    LC_WS_DEFAULT = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 28
try:
    LC_MRU_IMAGE_W = 348
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 29
try:
    LC_MRU_IMAGE_H = 273
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 32
try:
    LC_PS_SOLID = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 33
try:
    LC_PS_DASH = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 34
try:
    LC_PS_DOT = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 35
try:
    LC_PS_DASHDOT = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 36
try:
    LC_PS_DASHDOTDOT = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 39
try:
    LC_LW_THIN = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 40
try:
    LC_LW_REAL = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 41
try:
    LC_LW_PIXEL = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 44
try:
    LC_FILL_SOLID = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 45
try:
    LC_FILL_BDIAGONAL = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 46
try:
    LC_FILL_CROSS = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 47
try:
    LC_FILL_DIAGCROSS = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 48
try:
    LC_FILL_FDIAGONAL = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 49
try:
    LC_FILL_HORIZONTAL = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 50
try:
    LC_FILL_VERTICAL = 6
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 53
try:
    LC_IMGRES_BOX = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 55
try:
    LC_IMGRES_BILINEAR = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 56
try:
    LC_IMGRES_BSPLINE = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 57
try:
    LC_IMGRES_BICUBIC = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 58
try:
    LC_IMGRES_CATMULLROM = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 59
try:
    LC_IMGRES_LANCZOS3 = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 62
try:
    LC_IMGPROC_GRAY = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 63
try:
    LC_IMGPROC_FLIPHOR = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 64
try:
    LC_IMGPROC_FLIPVER = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 65
try:
    LC_IMGPROC_ROT180 = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 68
try:
    LC_GRIP_POINT = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 69
try:
    LC_GRIP_CENROT = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 70
try:
    LC_GRIP_ANGLE = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 71
try:
    LC_GRIP_ANGLE2 = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 72
try:
    LC_GRIP_BEZIER = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 73
try:
    LC_GRIP_BEZIER0 = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 74
try:
    LC_GRIP_ARCRAD = 6
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 77
try:
    LC_GRIP_NOMOVE = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 78
try:
    LC_GRIP_NOROTATE = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 79
try:
    LC_GRIP_NOSCALE = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 83
try:
    LC_BARTYPE_CODE39 = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 84
try:
    LC_BARTYPE_CODE93 = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 85
try:
    LC_BARTYPE_CODE128 = 6
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 86
try:
    LC_BARTYPE_EAN13 = 7
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 87
try:
    LC_BARTYPE_ITF = 8
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 88
try:
    LC_BARTYPE_EAN8 = 9
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 89
try:
    LC_BARTYPE_QR = 21
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 90
try:
    LC_BARTYPE_MQR = 22
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 91
try:
    LC_BARTYPE_DMATRIX = 23
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 92
try:
    LC_BARTYPE_DM = 23
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 93
try:
    LC_BARTYPE_DMATRIXR = 24
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 94
try:
    LC_BARTYPE_DMR = 24
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 98
try:
    LC_BARC_QRECL_L = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 99
try:
    LC_BARC_QRECL_M = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 100
try:
    LC_BARC_QRECL_Q = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 101
try:
    LC_BARC_QRECL_H = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 104
try:
    LC_LEADER_TCENTER = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 105
try:
    LC_LEADER_TLEFT = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 106
try:
    LC_LEADER_TRIGHT = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 108
try:
    LC_LEADER_VERT = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 109
try:
    LC_LEADER_CORNER = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 112
try:
    LC_VPL_CLEAR = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 113
try:
    LC_VPL_ADD = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 114
try:
    LC_VPL_DELETE = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 115
try:
    LC_VPL_PROP_BEGIN = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 116
try:
    LC_VPL_PROP_END = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 119
try:
    LC_RAD_TO_DEG = 57.2957795130823208768
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 121
try:
    LC_DEG_TO_RAD = 0.01745329251994329577
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 124
try:
    LC_PI = 3.14159265358979323846
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 125
try:
    LC_PI2 = 1.57079632679489661923
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 126
try:
    LC_PI4 = 0.78539816339744830962
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 127
try:
    LC_2PI = 6.28318530717958647692
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 130
try:
    LC_DEG1 = 0.01745329251994329577
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 131
try:
    LC_DEG2 = 0.03490658503988659154
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 132
try:
    LC_DEG3 = 0.05235987755982988731
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 133
try:
    LC_DEG4 = 0.06981317007977318308
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 134
try:
    LC_DEG5 = 0.08726646259971647885
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 135
try:
    LC_DEG6 = 0.10471975511965977462
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 136
try:
    LC_DEG7 = 0.12217304763960307038
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 137
try:
    LC_DEG8 = 0.13962634015954636615
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 138
try:
    LC_DEG9 = 0.15707963267948966192
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 139
try:
    LC_DEG10 = 0.17453292519943295769
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 140
try:
    LC_DEG20 = 0.34906585039886591538
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 141
try:
    LC_DEG30 = 0.52359877559829887308
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 142
try:
    LC_DEG40 = 0.69813170079773183077
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 143
try:
    LC_DEG45 = 0.78539816339744830962
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 144
try:
    LC_DEG50 = 0.87266462599716478846
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 145
try:
    LC_DEG60 = 1.04719755119659774615
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 146
try:
    LC_DEG70 = 1.22173047639603070385
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 147
try:
    LC_DEG80 = 1.39626340159546366154
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 148
try:
    LC_DEG90 = 1.57079632679489661923
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 149
try:
    LC_DEG180 = 3.14159265358979323846
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 150
try:
    LC_DEG270 = 4.71238898038468985769
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 151
try:
    LC_DEG360 = 6.28318530717958647692
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 154
try:
    LC_INSUNIT_UNDEFINED = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 155
try:
    LC_INSUNIT_INCHES = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 156
try:
    LC_INSUNIT_FEET = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 157
try:
    LC_INSUNIT_MILES = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 158
try:
    LC_INSUNIT_MILLIMETERS = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 159
try:
    LC_INSUNIT_CENTIMETERS = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 160
try:
    LC_INSUNIT_METERS = 6
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 161
try:
    LC_INSUNIT_KILOMETERS = 7
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 162
try:
    LC_INSUNIT_MICROINCHES = 8
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 163
try:
    LC_INSUNIT_MILS = 9
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 164
try:
    LC_INSUNIT_YARDS = 10
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 165
try:
    LC_INSUNIT_ANGSTROMS = 11
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 166
try:
    LC_INSUNIT_NANOMETERS = 12
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 167
try:
    LC_INSUNIT_MICRONS = 13
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 168
try:
    LC_INSUNIT_DECIMETERS = 14
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 169
try:
    LC_INSUNIT_DEKAMETERS = 15
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 170
try:
    LC_INSUNIT_HECTOMETERS = 16
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 171
try:
    LC_INSUNIT_GIGAMETERS = 17
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 172
try:
    LC_INSUNIT_ASTRONOMICAL = 18
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 173
try:
    LC_INSUNIT_LIGHTYEARS = 19
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 174
try:
    LC_INSUNIT_PARSECS = 20
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 177
try:
    LC_LUNIT_SCIEN = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 178
try:
    LC_LUNIT_DECIM = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 179
try:
    LC_LUNIT_ENGIN = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 180
try:
    LC_LUNIT_ARCHI = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 181
try:
    LC_LUNIT_FRACT = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 184
try:
    LC_AUNIT_DEGREE = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 185
try:
    LC_AUNIT_DMS = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 186
try:
    LC_AUNIT_GRAD = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 187
try:
    LC_AUNIT_RADIAN = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 188
try:
    LC_AUNIT_SURVEY = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 190
try:
    LC_ANGLE_DEGREE = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 191
try:
    LC_ANGLE_DMS = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 192
try:
    LC_ANGLE_GRAD = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 193
try:
    LC_ANGLE_RADIAN = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 194
try:
    LC_ANGLE_SURVEY = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 197
try:
    LC_PAPER_CUSTOM = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 198
try:
    LC_PAPER_USER = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 199
try:
    LC_PAPER_A0 = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 200
try:
    LC_PAPER_A1 = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 201
try:
    LC_PAPER_A2 = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 202
try:
    LC_PAPER_A3 = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 203
try:
    LC_PAPER_A4 = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 204
try:
    LC_PAPER_A5 = 6
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 205
try:
    LC_PAPER_A6 = 7
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 206
try:
    LC_PAPER_B0 = 11
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 207
try:
    LC_PAPER_B1 = 12
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 208
try:
    LC_PAPER_B2 = 13
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 209
try:
    LC_PAPER_B3 = 14
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 210
try:
    LC_PAPER_B4 = 15
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 211
try:
    LC_PAPER_B5 = 16
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 212
try:
    LC_PAPER_B6 = 17
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 213
try:
    LC_PAPER_C0 = 21
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 214
try:
    LC_PAPER_C1 = 22
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 215
try:
    LC_PAPER_C2 = 23
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 216
try:
    LC_PAPER_C3 = 24
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 217
try:
    LC_PAPER_C4 = 25
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 218
try:
    LC_PAPER_C5 = 26
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 219
try:
    LC_PAPER_C6 = 27
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 220
try:
    LC_PAPER_ANSI_A = 31
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 221
try:
    LC_PAPER_ANSI_B = 32
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 222
try:
    LC_PAPER_ANSI_C = 33
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 223
try:
    LC_PAPER_ANSI_D = 34
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 224
try:
    LC_PAPER_ANSI_E = 35
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 225
try:
    LC_PAPER_LETTER = 36
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 226
try:
    LC_PAPER_LEGAL = 37
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 227
try:
    LC_PAPER_EXECUTIVE = 38
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 228
try:
    LC_PAPER_LEDGER = 39
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 229
try:
    LC_PAPER_UNLIMITED = 100
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 232
try:
    LC_PAPER_PORTRAIT = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 233
try:
    LC_PAPER_BOOK = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 234
try:
    LC_PAPER_LANDSCAPE = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 235
try:
    LC_PAPER_ALBUM = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 238
try:
    LC_PRN_SCALELW = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 239
try:
    LC_PRN_1COLOR = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 242
try:
    LC_TA_LEFBOT = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 243
try:
    LC_TA_CENBOT = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 244
try:
    LC_TA_RIGBOT = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 245
try:
    LC_TA_LEFCEN = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 246
try:
    LC_TA_CENTER = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 247
try:
    LC_TA_RIGCEN = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 248
try:
    LC_TA_LEFTOP = 6
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 249
try:
    LC_TA_CENTOP = 7
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 250
try:
    LC_TA_RIGTOP = 8
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 251
try:
    LC_TA_ALIGNED = 11
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 252
try:
    LC_TA_FIT = 12
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 255
try:
    LC_TEXT_BACKWARD = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 256
try:
    LC_TEXT_UPDOWN = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 259
try:
    LC_ATA_LEFT = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 260
try:
    LC_ATA_CENTER = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 261
try:
    LC_ATA_RIGHT = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 264
try:
    LC_BTA_LEFT = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 265
try:
    LC_BTA_CENTER = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 266
try:
    LC_BTA_RIGHT = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 269
try:
    LC_PLFIT_BULGE = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 270
try:
    LC_PLFIT_NONE = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 271
try:
    LC_PLFIT_QUAD = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 272
try:
    LC_PLFIT_CUBIC = 6
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 273
try:
    LC_PLFIT_BEZIER = 7
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 274
try:
    LC_PLFIT_SPLINE = 99
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 275
try:
    LC_PLFIT_ROUND = 101
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 276
try:
    LC_PLFIT_LINQUAD = 102
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 279
try:
    LC_POINT_PIXEL = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 280
try:
    LC_POINT_NONE = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 281
try:
    LC_POINT_PLUS = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 282
try:
    LC_POINT_X = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 283
try:
    LC_POINT_TICK = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 285
try:
    LC_POINT_CIRCLE = 32
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 286
try:
    LC_POINT_SQUARE = 64
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 287
try:
    LC_POINT_RHOMB = 128
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 288
try:
    LC_POINT_FILLED = 256
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 290
try:
    LC_POINT_BEAM0 = 10000
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 291
try:
    LC_POINT_BEAM1 = 10001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 294
try:
    LC_BLK_ENT_RETAIN = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 295
try:
    LC_BLK_ENT_CONVERT = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 296
try:
    LC_BLK_ENT_DELETE = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 299
try:
    LC_EA_LEFT = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 300
try:
    LC_EA_TOP = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 301
try:
    LC_EA_RIGHT = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 302
try:
    LC_EA_BOTTOM = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 303
try:
    LC_EA_CENTER = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 304
try:
    LC_EA_CENTERX = 6
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 305
try:
    LC_EA_CENTERY = 7
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 308
try:
    LC_IMGA_CENTER = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 309
try:
    LC_IMGA_LEFBOT = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 310
try:
    LC_IMGA_RIGBOT = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 311
try:
    LC_IMGA_LEFTOP = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 312
try:
    LC_IMGA_RIGTOP = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 315
try:
    LC_LBUTTON = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 316
try:
    LC_RBUTTON = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 317
try:
    LC_MBUTTON = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 320
try:
    LC_SHIFT = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 321
try:
    LC_CTRL = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 322
try:
    LC_ALT = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 325
try:
    LC_KBD_QWERTY = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 326
try:
    LC_KBD_AZERTY = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 327
try:
    LC_KBD_QWERTZ = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 331
try:
    LC_CURSOR_NULL = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 332
try:
    LC_CURSOR_ARROW = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 333
try:
    LC_CURSOR_CROSS = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 334
try:
    LC_CURSOR_HAND = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 335
try:
    LC_CURSOR_HELP = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 336
try:
    LC_CURSOR_NO = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 337
try:
    LC_CURSOR_WAIT = 6
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 338
try:
    LC_CURSOR_PAN1 = 7
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 339
try:
    LC_CURSOR_PAN2 = 8
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 342
try:
    LC_EXP_OUTLINE = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 343
try:
    LC_EXP_HATCH = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 344
try:
    LC_EXP_ALL = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 345
try:
    LC_EXP_MAXRESOL = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 348
try:
    LC_EM_TOP = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 349
try:
    LC_EM_ENT = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 350
try:
    LC_EM_PLINE = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 351
try:
    LC_EM_VERTEX = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 352
try:
    LC_EM_ENDPLINE = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 353
try:
    LC_EM_ENDENT = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 356
try:
    LC_EMUL_START = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 357
try:
    LC_EMUL_STOP = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 358
try:
    LC_EMUL_PARAMS = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 361
try:
    LC_MAG_ZOOM_4 = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 362
try:
    LC_MAG_ZOOM_6 = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 363
try:
    LC_MAG_ZOOM_8 = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 364
try:
    LC_MAG_ZOOM_10 = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 365
try:
    LC_MAG_ZOOM_12 = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 366
try:
    LC_MAG_ZOOM_14 = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 368
try:
    LC_MAG_CENTER = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 371
try:
    LC_DRWEXP_L = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 372
try:
    LC_DRWEXP_P = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 373
try:
    LC_DRWEXP_LA = 10
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 374
try:
    LC_DRWEXP_PA = 11
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 375
try:
    LC_DRWEXP_BLOCKS = 20
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 378
try:
    LC_HELP_DG_PRINT = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 379
try:
    LC_HELP_DG_RASTER = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 380
try:
    LC_HELP_DG_COLOR = 10
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 381
try:
    LC_HELP_DG_LAYERS = 11
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 382
try:
    LC_HELP_DG_SELLTYPE = 12
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 383
try:
    LC_HELP_DG_LINETYPES = 13
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 384
try:
    LC_HELP_DG_LOADLINETYPE = 14
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 385
try:
    LC_HELP_DG_TEXTSTYLES = 15
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 386
try:
    LC_HELP_DG_PNTSTYLES = 16
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 387
try:
    LC_HELP_DG_DIMSTYLES = 17
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 388
try:
    LC_HELP_DG_MLSTYLES = 18
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 389
try:
    LC_HELP_DG_HATSTYLES = 19
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 390
try:
    LC_HELP_DG_BLOCKS = 20
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 391
try:
    LC_HELP_DG_LAYOUTS = 21
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 392
try:
    LC_HELP_DG_IMAGES = 22
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 393
try:
    LC_HELP_DG_IMAGEINSERT = 23
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 394
try:
    LC_HELP_DG_SELBLOCK = 30
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 395
try:
    LC_HELP_DG_SELTSTYLE = 31
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 396
try:
    LC_HELP_DG_SELPTYPE = 32
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 397
try:
    LC_HELP_DG_CREBLOCK = 33
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 398
try:
    LC_HELP_DG_PAGEPROP = 34
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 399
try:
    LC_HELP_DG_SELFONT = 35
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 400
try:
    LC_HELP_DG_TEXT = 40
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 401
try:
    LC_HELP_DG_ARCTEXT = 41
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 402
try:
    LC_HELP_DG_INPUTCOORD = 42
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 403
try:
    LC_HELP_DG_WORKFIELD = 43
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 404
try:
    LC_HELP_DG_CRBITMAP = 44
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 405
try:
    LC_HELP_DG_INSERT = 45
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 406
try:
    LC_HELP_DG_TSP = 51
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 407
try:
    LC_HELP_DG_ARRAY = 52
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 408
try:
    LC_HELP_DG_ARRAYARC = 53
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 409
try:
    LC_HELP_DG_HATCH = 54
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 410
try:
    LC_HELP_DG_GRID = 61
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 411
try:
    LC_HELP_DG_PTRACK = 62
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 412
try:
    LC_HELP_DG_OSNAP = 63
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 413
try:
    LC_HELP_DG_KBMOVE = 64
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 414
try:
    LC_HELP_DG_DRWPROPS = 65
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 415
try:
    LC_HELP_DG_SYSPROPS = 66
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 416
try:
    LC_HELP_DG_SELECTION = 67
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 417
try:
    LC_HELP_DG_QSELECT = 68
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 418
try:
    LC_HELP_DG_RPOLYGON = 69
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 419
try:
    LC_HELP_DG_LIMITS = 70
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 420
try:
    LC_HELP_DG_NDLSET = 71
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 421
try:
    LC_HELP_DG_LMESH = 72
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 422
try:
    LC_HELP_DG_CRECTS = 73
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 423
try:
    LC_HELP_DG_SELLINFILL = 74
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 426
try:
    LC_MB_OK = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 429
try:
    LC_MB_OKCANCEL = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 431
try:
    LC_MB_ABORTRETRYIGNORE = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 434
try:
    LC_MB_YESNOCANCEL = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 436
try:
    LC_MB_YESNO = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 438
try:
    LC_MB_RETRYCANCEL = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 440
try:
    LC_MB_CANCELTRYCONTINUE = 6
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 443
try:
    LC_MB_HELP = 16384
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 447
try:
    LC_MB_ICONSTOP = 16
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 450
try:
    LC_MB_ICONERROR = 16
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 452
try:
    LC_MB_ICONHAND = 16
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 455
try:
    LC_MB_ICONQUESTION = 32
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 457
try:
    LC_MB_ICONEXCLAMATION = 48
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 459
try:
    LC_MB_ICONWARNING = 48
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 461
try:
    LC_MB_ICONINFORMATION = 64
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 464
try:
    LC_MB_ICONASTERISK = 64
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 468
try:
    LC_UNDO_BEGIN = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 469
try:
    LC_UNDO_END = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 470
try:
    LC_UNDO_CLEAR = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 473
try:
    LC_ERR_OBJTYPE = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 474
try:
    LC_ERR_NOTAG = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 475
try:
    LC_ERR_USERCANCEL = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 476
try:
    LC_ERR_FILENAME = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 477
try:
    LC_ERR_FILELOAD = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 478
try:
    LC_ERR_FILESAVE = 6
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 479
try:
    LC_ERR_UNRESBLOCKREF = 7
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 480
try:
    LC_ERR_UNRESVIEWREF = 8
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 481
try:
    LC_ERR_UNRESHATCH = 9
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 482
try:
    LC_ERR_FILE_TIN_SAVE = 101
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 485
try:
    LC_OBJ_LAYER = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 486
try:
    LC_OBJ_LINETYPE = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 487
try:
    LC_OBJ_TEXTSTYLE = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 488
try:
    LC_OBJ_DIMSTYLE = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 489
try:
    LC_OBJ_PNTSTYLE = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 490
try:
    LC_OBJ_IMAGE = 6
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 491
try:
    LC_OBJ_MLSTYLE = 8
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 492
try:
    LC_OBJ_LINFILL = 9
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 493
try:
    LC_OBJ_BLOCK = 10
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 494
try:
    LC_OBJ_LAYOUT = 11
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 497
try:
    LC_ENT_LINE = 101
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 498
try:
    LC_ENT_POLYLINE = 102
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 499
try:
    LC_ENT_CIRCLE = 103
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 500
try:
    LC_ENT_ARC = 104
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 501
try:
    LC_ENT_BLOCKREF = 105
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 502
try:
    LC_ENT_POINT = 107
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 503
try:
    LC_ENT_XLINE = 108
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 504
try:
    LC_ENT_ELLIPSE = 109
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 505
try:
    LC_ENT_TEXT = 110
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 506
try:
    LC_ENT_TEXTWIN = 111
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 507
try:
    LC_ENT_IMAGEREF = 115
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 508
try:
    LC_ENT_VIEWPORT = 116
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 509
try:
    LC_ENT_CLIPRECT = 117
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 510
try:
    LC_ENT_RECT = 118
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 511
try:
    LC_ENT_ATTDEF = 120
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 512
try:
    LC_ENT_ECW = 121
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 513
try:
    LC_ENT_MTEXT = 122
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 514
try:
    LC_ENT_ARCTEXT = 123
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 515
try:
    LC_ENT_HATCH = 124
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 516
try:
    LC_ENT_FACE = 126
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 517
try:
    LC_ENT_MLINE = 127
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 518
try:
    LC_ENT_DIMROT = 131
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 519
try:
    LC_ENT_DIMLIN = 131
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 520
try:
    LC_ENT_DIMALI = 132
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 521
try:
    LC_ENT_DIMORD = 133
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 522
try:
    LC_ENT_DIMRAD = 134
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 523
try:
    LC_ENT_DIMDIA = 135
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 524
try:
    LC_ENT_DIMANG = 136
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 525
try:
    LC_ENT_LEADER = 137
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 526
try:
    LC_ENT_RPLAN = 141
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 527
try:
    LC_ENT_TIN = 142
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 528
try:
    LC_ENT_BARCODE = 150
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 529
try:
    LC_ENT_SHAPE = 160
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 530
try:
    LC_ENT_BRI = 161
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 531
try:
    LC_ENT_XREF = 199
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 532
try:
    LC_ENT_ARROW = 301
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 533
try:
    LC_ENT_SPIRAL = 302
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 534
try:
    LC_ENT_CAMERA = 303
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 538
try:
    LC_ENT_PATHTEXT = 305
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 539
try:
    LC_ENT_BEZIER = 306
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 540
try:
    LC_ENT_CUSTOM = 1000
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 541
try:
    LC_ENT_ALL = 32767
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 544
try:
    LC_LWEIGHT_DEFAULT = -3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 547
try:
    LC_LWEIGHT_BYBLOCK = -2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 550
try:
    LC_LWEIGHT_BYLAYER = -1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 552
try:
    LC_LWIDTH_DEFAULT = -3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 553
try:
    LC_LWIDTH_BYBLOCK = -2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 554
try:
    LC_LWIDTH_BYLAYER = -1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 557
try:
    LC_COLOR_RGB = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 558
try:
    LC_COLOR_INDEX = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 561
try:
    LC_COLOR_RED = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 562
try:
    LC_COLOR_YELLOW = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 563
try:
    LC_COLOR_GREEN = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 564
try:
    LC_COLOR_CYAN = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 565
try:
    LC_COLOR_BLUE = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 566
try:
    LC_COLOR_MAGENTA = 6
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 567
try:
    LC_COLOR_FOREGROUND = 7
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 568
try:
    LC_COLOR_GRAY = 8
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 569
try:
    LC_COLOR_LTGRAY = 9
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 571
try:
    LC_COLOR_BYBLOCK = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 572
try:
    LC_COLOR_BYLAYER = 256
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 573
try:
    LC_COLOR_WIPEOUT = 259
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 580
try:
    LC_MLINE_TOP = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 581
try:
    LC_MLINE_MIDDLE = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 582
try:
    LC_MLINE_BOTTOM = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 584
try:
    LC_TABLE_IDSET = 349000349
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 588
try:
    LC_PLUG_IMPDRW = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 590
try:
    LC_PLUG_EXPDRW = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 591
try:
    LC_PLUG_IMGDIB = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 594
try:
    LC_FP_FLOAD = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 595
try:
    LC_FP_FSAVE = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 596
try:
    LC_FP_NITEMS = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 597
try:
    LC_FP_ITEM = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 598
try:
    LC_FP_ITEMPOS = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 601
try:
    LC_OSNAP_NULL = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 602
try:
    LC_OSNAP_NODE = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 605
try:
    LC_OSNAP_ENDPOINT = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 608
try:
    LC_OSNAP_MIDPOINT = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 611
try:
    LC_OSNAP_CENTER = 8
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 613
try:
    LC_OSNAP_NEAREST = 16
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 616
try:
    LC_OSNAP_INTER = 32
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 619
try:
    LC_OSNAP_PERPEND = 64
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 622
try:
    LC_OSNAP_TANGENT = 128
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 625
try:
    LC_OSNAP_QUADRANT = 256
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 628
try:
    LC_OSNAP_INSERT = 512
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 631
try:
    LC_OSNAP_NONE = 1024
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 632
try:
    LC_OSNAP_ALL = 1023
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 635
try:
    LC_ATTRIB_HIDDEN = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 636
try:
    LC_ATTRIB_CONST = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 637
try:
    LC_ATTRIB_VERIFY = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 638
try:
    LC_ATTRIB_PRESET = 8
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 639
try:
    LC_ATTRIB_LOCK = 16
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 640
try:
    LC_ATTRIB_MTEXT = 32
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 643
try:
    LC_FACE_EDGE1INVIS = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 644
try:
    LC_FACE_EDGE2INVIS = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 645
try:
    LC_FACE_EDGE3INVIS = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 646
try:
    LC_FACE_EDGE4INVIS = 8
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 647
try:
    LC_FACE_EDGE1HIDDEN = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 648
try:
    LC_FACE_EDGE2HIDDEN = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 649
try:
    LC_FACE_EDGE3HIDDEN = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 650
try:
    LC_FACE_EDGE4HIDDEN = 8
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 653
try:
    LC_BLOCK_OVERWRITENO = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 654
try:
    LC_BLOCK_OVERWRITEYES = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 655
try:
    LC_BLOCK_OVERWRITEDLG = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 658
try:
    LC_ARROW_CLOSEDF = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 659
try:
    LC_ARROW_CLOSEDB = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 660
try:
    LC_ARROW_CLOSED = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 661
try:
    LC_ARROW_DOT = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 662
try:
    LC_ARROW_ARCHTICK = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 663
try:
    LC_ARROW_OBLIQUE = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 664
try:
    LC_ARROW_OPEN = 6
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 665
try:
    LC_ARROW_ORIGIN = 7
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 666
try:
    LC_ARROW_ORIGIN2 = 8
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 667
try:
    LC_ARROW_OPEN90 = 9
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 668
try:
    LC_ARROW_OPEN30 = 10
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 669
try:
    LC_ARROW_DOTSMALL = 11
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 670
try:
    LC_ARROW_DOTB = 12
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 671
try:
    LC_ARROW_DOTSMALLB = 13
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 672
try:
    LC_ARROW_BOX = 14
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 673
try:
    LC_ARROW_BOXF = 15
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 674
try:
    LC_ARROW_DATUM = 16
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 675
try:
    LC_ARROW_DATUMF = 17
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 676
try:
    LC_ARROW_INTEGRAL = 18
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 677
try:
    LC_ARROW_NONE = 19
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 680
try:
    LC_COFO_NONE = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 681
try:
    LC_COFO_Y800 = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 682
try:
    LC_COFO_RGB24 = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 683
try:
    LC_COFO_RGB32 = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 684
try:
    LC_COFO_UYVY = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 685
try:
    LC_COFO_Y16 = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 686
try:
    LC_COFO_MEGA = 65536
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 693
try:
    LC_CMD_FILESAVE = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 695
try:
    LC_CMD_FILESAVEAS = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 696
try:
    LC_CMD_PRINT = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 697
try:
    LC_CMD_RASTERIZE = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 698
try:
    LC_CMD_FILENEW = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 699
try:
    LC_CMD_FILEOPEN = 6
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 700
try:
    LC_CMD_FILERECENT = 7
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 701
try:
    LC_CMD_FILEINSERT = 8
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 702
try:
    LC_CMD_FILECLOSE = 9
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 705
try:
    LC_CMD_VIEW__MIN = 31
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 706
try:
    LC_CMD_ZOOM_IN = 31
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 707
try:
    LC_CMD_ZOOM_OUT = 32
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 708
try:
    LC_CMD_ZOOM_EXT = 33
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 709
try:
    LC_CMD_ZOOM_PAGE = 34
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 710
try:
    LC_CMD_ZOOM_PREV = 35
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 711
try:
    LC_CMD_ZOOM_LIM = 36
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 712
try:
    LC_CMD_PAN_LEFT = 37
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 713
try:
    LC_CMD_PAN_RIGHT = 38
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 714
try:
    LC_CMD_PAN_UP = 39
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 715
try:
    LC_CMD_PAN_DOWN = 40
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 716
try:
    LC_CMD_VIEW__MAX = 40
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 717
try:
    LC_CMD_ZOOM_WIN = 51
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 718
try:
    LC_CMD_ZOOM_RECT = 51
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 719
try:
    LC_CMD_ZOOM_SEL = 52
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 720
try:
    LC_CMD_PAGENEXT = 53
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 721
try:
    LC_CMD_PAGEPREV = 54
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 722
try:
    LC_CMD_PAGEMODEL = 55
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 723
try:
    LC_CMD_PAGEVPORT = 56
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 725
try:
    LC_CMD_VP_ACT = 57
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 726
try:
    LC_CMD_VP_DEACT = 58
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 727
try:
    LC_CMD_EDITMODE_ON = 59
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 728
try:
    LC_CMD_EDITMODE_OFF = 60
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 729
try:
    LC_CMD_MAG__MIN = 71
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 730
try:
    LC_CMD_MAGON = 71
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 731
try:
    LC_CMD_MAGOFF = 72
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 732
try:
    LC_CMD_MAGPRM = 73
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 733
try:
    LC_CMD_MAGZOOM4 = 74
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 734
try:
    LC_CMD_MAGZOOM6 = 75
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 735
try:
    LC_CMD_MAGZOOM8 = 76
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 736
try:
    LC_CMD_MAGZOOM10 = 77
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 737
try:
    LC_CMD_MAGZOOM12 = 78
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 738
try:
    LC_CMD_MAGZOOM14 = 79
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 739
try:
    LC_CMD_MAG__MAX = 79
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 742
try:
    LC_CMD_GRID = 101
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 743
try:
    LC_CMD_OSNAP = 102
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 744
try:
    LC_CMD_PTRACK = 103
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 745
try:
    LC_CMD_SELOPTS = 104
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 746
try:
    LC_CMD_QSELECT = 105
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 747
try:
    LC_CMD_KBMOVE = 106
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 748
try:
    LC_CMD_DIST = 111
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 749
try:
    LC_CMD_AREA = 112
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 750
try:
    LC_CMD_SCALEBLK = 113
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 752
try:
    LC_CMD_TSP2 = 116
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 753
try:
    LC_CMD_LIMITS = 117
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 754
try:
    LC_CMD_SAVESTR = 118
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 755
try:
    LC_CMD_DELDUPVER = 119
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 756
try:
    LC_CMD_DELEXVER = 120
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 758
try:
    LC_CMD_UNHIDE = 136
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 759
try:
    LC_CMD_SHDOTS = 137
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 760
try:
    LC_CMD_SMALLVRECT = 138
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 761
try:
    LC_CMD_PLUGINS = 141
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 762
try:
    LC_CMD_CENTERCURSOR = 142
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 764
try:
    LC_CMD_HELP = 1001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 765
try:
    LC_CMD_RESET = 1003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 768
try:
    LC_CMD_SW_GRID = 1011
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 769
try:
    LC_CMD_SW_GRIDSNAP = 1012
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 770
try:
    LC_CMD_SW_OSNAP = 1014
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 771
try:
    LC_CMD_SW_PTRACK = 1015
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 772
try:
    LC_CMD_SW_POLAR = 1015
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 773
try:
    LC_CMD_SW_ORTHO = 1016
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 776
try:
    LC_CMD_POINT = 201
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 777
try:
    LC_CMD_LINE = 202
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 778
try:
    LC_LINE_SERIAL = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 779
try:
    LC_LINE_SEPARATE = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 780
try:
    LC_LINE_CONT = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 781
try:
    LC_CMD_XLINE = 203
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 782
try:
    LC_XLINE_BASE = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 783
try:
    LC_XLINE_ANG = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 784
try:
    LC_XLINE_SEP = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 785
try:
    LC_XLINE_RAY = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 786
try:
    LC_XLINE_XLINE = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 787
try:
    LC_CMD_LMESH = 204
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 788
try:
    LC_CMD_POLYLINE = 205
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 789
try:
    LC_CMD_PLINE = 205
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 790
try:
    LC_CMD_SPLINE = 206
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 791
try:
    LC_CMD_RPOLYGON = 207
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 792
try:
    LC_CMD_RECT = 208
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 793
try:
    LC_RECT_2P = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 794
try:
    LC_RECT_3P = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 795
try:
    LC_RECT_CSA = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 796
try:
    LC_CMD_CIRCLE = 209
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 797
try:
    LC_CIRCLE_CR = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 798
try:
    LC_CIRCLE_2P = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 799
try:
    LC_CIRCLE_3P = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 800
try:
    LC_CMD_ARC = 210
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 801
try:
    LC_ARC_SME = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 802
try:
    LC_ARC_SEM = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 803
try:
    LC_ARC_SEC = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 804
try:
    LC_ARC_SED = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 805
try:
    LC_ARC_CSE = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 806
try:
    LC_ARC_CONT = 6
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 807
try:
    LC_CMD_ELLIPSE = 211
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 808
try:
    LC_ELL_AX = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 809
try:
    LC_ELL_CEN = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 810
try:
    LC_ELL_RECT = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 811
try:
    LC_CMD_TEXT = 212
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 812
try:
    LC_CMD_TEXTW = 213
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 813
try:
    LC_CMD_ATEXT = 214
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 814
try:
    LC_CMD_ARCTEXT = 214
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 815
try:
    LC_CMD_MTEXT = 215
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 816
try:
    LC_CMD_INSERT = 216
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 817
try:
    LC_CMD_BLOCKREF = 216
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 818
try:
    LC_INSERT_DLG = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 819
try:
    LC_INSERT_NODLG = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 820
try:
    LC_INSERT_RESET = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 821
try:
    LC_CMD_BARCODE = 217
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 822
try:
    LC_BARCODE_39 = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 823
try:
    LC_BARCODE_93 = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 824
try:
    LC_BARCODE_128 = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 825
try:
    LC_BARCODE_EAN13 = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 826
try:
    LC_BARCODE_EAN8 = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 827
try:
    LC_BARCODE_ITF = 6
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 828
try:
    LC_BARCODE_MQR = 7
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 829
try:
    LC_BARCODE_QR = 8
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 830
try:
    LC_BARCODE_DMATRIX = 9
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 831
try:
    LC_BARCODE_DM = 9
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 832
try:
    LC_BARCODE_DMATRIXR = 10
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 833
try:
    LC_BARCODE_DMR = 10
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 834
try:
    LC_CMD_DIMLIN = 221
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 835
try:
    LC_CMD_DIMROT = 221
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 836
try:
    LC_CMD_DIMALI = 223
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 837
try:
    LC_CMD_DIMORD = 224
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 838
try:
    LC_CMD_DIMRAD = 225
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 839
try:
    LC_CMD_DIMDIA = 226
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 840
try:
    LC_CMD_DIMANG = 227
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 841
try:
    LC_CMD_LEADER = 228
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 842
try:
    LC_CMD_ARROW = 231
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 843
try:
    LC_CMD_SPIRAL = 232
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 844
try:
    LC_CMD_HATCH = 233
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 845
try:
    LC_CMD_ECW = 234
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 846
try:
    LC_CMD_VPORT = 236
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 847
try:
    LC_CMD_VIEWPORT = 236
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 851
try:
    LC_CMD_FACE = 238
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 852
try:
    LC_CMD_SHAPE = 239
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 853
try:
    LC_CMD_SKETCH = 240
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 854
try:
    LC_CMD_CLOUD = 241
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 855
try:
    LC_CMD_RPLAN = 242
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 856
try:
    LC_CMD_MLINE = 243
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 857
try:
    LC_CMD_BEZIER = 244
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 858
try:
    LC_CMD_BRI = 245
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 859
try:
    LC_CMD_CLIPRECTS = 250
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 860
try:
    LC_CMD_CRECTS = 250
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 861
try:
    LC_CMD_ATTDEF = 251
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 863
try:
    LC_CMD_TIN_LOAD = 301
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 865
try:
    LC_CMD_TIN_LOADPT = 302
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 867
try:
    LC_CMD_TIN_ADDPT = 303
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 868
try:
    LC_CMD_TIN_DELETE = 304
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 869
try:
    LC_CMD_TIN_PROPS = 305
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 870
try:
    LC_CMD_TIN_PTYPES = 306
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 871
try:
    LC_CMD_TIN_MOVEPT = 307
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 872
try:
    LC_CMD_TIN_EDITPT = 308
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 873
try:
    LC_CMD_TIN_DELPT = 309
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 874
try:
    LC_CMD_TIN_BNDDELPT = 310
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 875
try:
    LC_CMD_TIN_DELPTDUP = 311
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 876
try:
    LC_CMD_TIN_DELTRALL = 312
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 877
try:
    LC_CMD_TIN_DELTR = 313
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 878
try:
    LC_CMD_TIN_BNDDELTR = 314
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 879
try:
    LC_CMD_TIN_SWAPTR = 315
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 880
try:
    LC_CMD_TIN_BNDAUTO = 316
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 881
try:
    LC_CMD_TIN_BND = 317
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 882
try:
    LC_CMD_TIN_BNDEDIT = 318
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 883
try:
    LC_CMD_TIN_BNDCLEAR = 319
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 884
try:
    LC_CMD_TIN_BNDTRANG = 320
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 885
try:
    LC_CMD_TIN_BNDTRANG2 = 321
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 886
try:
    LC_CMD_TIN_GENISO = 322
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 887
try:
    LC_CMD_TIN_GENFILL = 323
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 888
try:
    LC_CMD_TIN_RELOAD = 324
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 889
try:
    LC_CMD_TIN_SAVE = 325
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 890
try:
    LC_CMD_TIN_SAVEPT = 326
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 891
try:
    LC_CMD_TIN_BNDSAVE = 327
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 892
try:
    LC_CMD_TIN_BNDPLINE = 328
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 893
try:
    LC_CMD_TIN_Z = 329
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 894
try:
    LC_CMD_TIN_ZOOM = 330
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 895
try:
    LC_CMD_TIN_ISOTODRW = 331
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 896
try:
    LC_CMD_TIN_TILES = 332
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 899
try:
    LC_CMD_CBCUT = 401
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 900
try:
    LC_CMD_CBCOPY = 402
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 901
try:
    LC_CMD_CBPASTE = 403
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 902
try:
    LC_CMD_UNDO = 404
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 903
try:
    LC_CMD_REDO = 405
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 904
try:
    LC_CMD_UNDOCLEAR = 406
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 905
try:
    LC_CMD_COPY = 410
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 906
try:
    LC_COPY_MOVE = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 907
try:
    LC_COPY_ROTATE = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 908
try:
    LC_COPY_SCALE = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 909
try:
    LC_COPY_MIRROR = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 910
try:
    LC_COPY_ARRRECT = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 911
try:
    LC_COPY_ARRCIRC = 6
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 912
try:
    LC_CMD_ERASE = 411
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 913
try:
    LC_CMD_MOVE = 412
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 914
try:
    LC_CMD_ROTATE = 413
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 915
try:
    LC_CMD_SCALE = 414
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 916
try:
    LC_CMD_MIRROR = 415
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 917
try:
    LC_CMD_EXPLODE = 416
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 918
try:
    LC_CMD_SPLIT = 417
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 919
try:
    LC_CMD_JOIN = 418
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 921
try:
    LC_CMD_ORDER = 420
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 922
try:
    LC_ORDER_FRONT = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 923
try:
    LC_ORDER_BACK = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 924
try:
    LC_ORDER_ABOVE = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 925
try:
    LC_ORDER_UNDER = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 926
try:
    LC_ORDER_SWAP = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 927
try:
    LC_CMD_ORDER_SEQ = 430
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 928
try:
    LC_CMD_ALIGN = 431
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 929
try:
    LC_ALIGN_LEFT = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 930
try:
    LC_ALIGN_RIGHT = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 931
try:
    LC_ALIGN_TOP = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 932
try:
    LC_ALIGN_BOTTOM = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 933
try:
    LC_ALIGN_CENTER = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 934
try:
    LC_ALIGN_CENX = 6
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 935
try:
    LC_ALIGN_CENY = 7
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 936
try:
    LC_CMD_CLOSEBLOCK = 439
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 937
try:
    LC_CMD_BASEPOINT = 440
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 938
try:
    LC_CMD_TRIM = 441
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 939
try:
    LC_CMD_EXTEND = 442
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 940
try:
    LC_CMD_OFFSET = 443
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 941
try:
    LC_CMD_OFFSET_POINT = 0
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 942
try:
    LC_CMD_OFFSET_DIST = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 943
try:
    LC_CMD_BREAK = 444
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 944
try:
    LC_CMD_STRETCH = 445
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 945
try:
    LC_CMD_FILLET = 446
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 946
try:
    LC_CMD_IMGRES = 451
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 947
try:
    LC_CMD_IMGPOS = 452
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 952
try:
    LC_CMD_JOINALL = 465
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 953
try:
    LC_CMD_ENTEXT = 468
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 954
try:
    LC_CMD_JUMPS = 469
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 955
try:
    LC_CMD_UNSIMG = 470
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 956
try:
    LC_CMD_UPDATE = 474
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 957
try:
    LC_CMD_DELOVER = 475
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 958
try:
    LC_CMD_CMPD = 476
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 961
try:
    LC_CMD_LAYER = 501
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 962
try:
    LC_CMD_LAYERORD = 502
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 963
try:
    LC_CMD_COLOR = 503
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 966
try:
    LC_CMD_FCOLOR = 504
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 967
try:
    LC_CMD_LINETYPE = 505
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 968
try:
    LC_CMD_TEXTSTYLE = 507
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 969
try:
    LC_CMD_BLOCK = 508
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 970
try:
    LC_CMD_CREBLOCK = 508
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 971
try:
    LC_CMD_BLOCKS = 509
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 972
try:
    LC_CMD_IMAGE = 510
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 973
try:
    LC_CMD_PNTSTYLE = 511
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 974
try:
    LC_CMD_DIMSTYLE = 512
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 975
try:
    LC_CMD_MLSTYLE = 513
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 976
try:
    LC_CMD_LINFILL = 515
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 977
try:
    LC_CMD_LAYOUT = 516
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 978
try:
    LC_CMD_XREFS = 517
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 979
try:
    LC_CMD_UNITS = 521
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 980
try:
    LC_CMD_DRWPRM = 522
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 981
try:
    LC_CMD_SYSPRM = 523
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 984
try:
    LC_CMD_3DVIEW = 601
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 986
try:
    LC_CMD_3D = 601
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 987
try:
    LC_CMD_3D_STDVIEW = 602
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 988
try:
    LC_CMD_3D_PARAMS = 603
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 989
try:
    LC_CMD_3D_SAVEIMAGE = 604
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 991
try:
    LC_CMD_AKAGRIP = 29999
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 992
try:
    LC_CMD_CUSTOM = 30000
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 999
try:
    LC_PROP_G_REGCODE = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1000
try:
    LC_PROP_G_VERSION = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1001
try:
    LC_PROP_G_MSGTITLE = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1003
try:
    LC_PROP_G_APPFILENAME = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1004
try:
    LC_PROP_G_DWGAPP = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1005
try:
    LC_PROP_G_DXFAPP = 6
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1006
try:
    LC_PROP_G_HELPFILE = 10
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1008
try:
    LC_PROP_G_DIRDLL = 11
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1009
try:
    LC_PROP_G_DIRFONTS = 13
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1012
try:
    LC_PROP_G_DIRLNG = 14
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1015
try:
    LC_PROP_G_DIRTPL = 16
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1018
try:
    LC_PROP_G_DIRCFG = 17
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1021
try:
    LC_PROP_G_ICON16 = 20
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1022
try:
    LC_PROP_G_ICON32 = 21
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1023
try:
    LC_PROP_G_RULERBMP = 22
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1024
try:
    LC_PROP_G_PRNUSEBMP = 25
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1025
try:
    LC_PROP_G_PRNBMPFILE = 26
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1026
try:
    LC_PROP_G_PRNBTNRAS = 27
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1028
try:
    LC_PROP_G_PRNBTNSRIF = 28
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1031
try:
    LC_PROP_G_PNTPIXSIZE = 29
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1034
try:
    LC_PROP_G_GETDELENT = 30
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1037
try:
    LC_PROP_G_SBARHEIGHT = 32
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1038
try:
    LC_PROP_G_FILEPROGRESS = 33
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1040
try:
    LC_PROP_G_FILEDEFEXT = 35
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1042
try:
    LC_PROP_G_FILELCD = 31
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1043
try:
    LC_PROP_G_DEMOTEXT = 36
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1044
try:
    LC_PROP_G_DEMOSIZE = 37
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1045
try:
    LC_PROP_G_DEMOCOLOR = 38
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1046
try:
    LC_PROP_G_TABCMDWND = 39
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1047
try:
    LC_PROP_G_UNDOMSG = 40
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1049
try:
    LC_PROP_G_MINCHARSIZE = 41
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1051
try:
    LC_PROP_G_PANREDQUAL = 42
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1052
try:
    LC_PROP_G_ENTEXT = 43
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1053
try:
    LC_PROP_G_BLKRELOADMODE = 44
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1054
try:
    LC_PROP_G_TABFILE = 45
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1057
try:
    LC_PROP_G_MSGSAVEAS = 46
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1059
try:
    LC_PROP_G_JUR = 47
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1060
try:
    LC_PROP_G_FILEEXTS = 48
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1061
try:
    LC_PROP_G_DLGVAL = 50
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1062
try:
    LC_PROP_G_STR = 51
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1063
try:
    LC_PROP_G_INT = 52
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1064
try:
    LC_PROP_G_FLOAT = 53
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1065
try:
    LC_PROP_G_HANDLE = 54
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1066
try:
    LC_PROP_G_DELKEYERASE = 55
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1070
try:
    LC_PROP_SEL_PICKBOXSIZE = 61
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1072
try:
    LC_PROP_SEL_PICKBYRECT = 62
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1074
try:
    LC_PROP_SEL_PICKDRAG = 63
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1077
try:
    LC_PROP_SEL_PICKADD = 64
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1080
try:
    LC_PROP_SEL_PICKBYLAYER = 65
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1082
try:
    LC_PROP_SEL_PICKINPGON = 66
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1084
try:
    LC_PROP_SEL_PICKINPGONF = 67
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1085
try:
    LC_PROP_SEL_PICKINIMG = 68
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1087
try:
    LC_PROP_SEL_COLORL1 = 69
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1088
try:
    LC_PROP_SEL_COLORL2 = 70
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1089
try:
    LC_PROP_SEL_COLORF = 71
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1090
try:
    LC_PROP_SEL_HATCHFILL = 72
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1092
try:
    LC_PROP_SEL_ENABLEGRIPS = 73
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1093
try:
    LC_PROP_SEL_GRIPSIZE = 74
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1094
try:
    LC_PROP_SEL_GRIPCOLORF = 75
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1095
try:
    LC_PROP_SEL_GRIPCOLORB = 76
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1096
try:
    LC_PROP_SEL_GRIPENTLIM = 77
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1098
try:
    LC_PROP_SEL_GRIPNUM = 78
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1100
try:
    LC_PROP_G_CAMERA_COUNT = 90
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1101
try:
    LC_PROP_G_CAMERA_I = 91
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1102
try:
    LC_PROP_G_CAMERA_INAME = 92
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1104
try:
    LC_PROP_G_CAMERA_CONNECTED = 93
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1106
try:
    LC_PROP_G_CAMERA_NAME = 94
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1107
try:
    LC_PROP_G_CAMERA_TIME = 95
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1108
try:
    LC_PROP_G_CAMERA_WIDTH = 96
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1109
try:
    LC_PROP_G_CAMERA_HEIGHT = 97
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1110
try:
    LC_PROP_G_CAMERA_BPP = 98
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1111
try:
    LC_PROP_G_CAMERA_COFO = 99
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1113
try:
    LC_PROP_G_CAMERA_BITS = 100
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1114
try:
    LC_PROP_G_CAMERA_BPROW = 101
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1116
try:
    LC_PROP_G_PTBUFNEWPTS = 131
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1117
try:
    LC_PROP_G_PTBUFCLR = 132
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1118
try:
    LC_PROP_G_MPGONCLR = 133
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1120
try:
    LC_PROP_G_TEXT_ALIGN = 141
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1121
try:
    LC_PROP_G_TEXT_H = 142
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1122
try:
    LC_PROP_G_TEXT_WS = 143
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1123
try:
    LC_PROP_G_TEXT_CSPACE = 144
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1124
try:
    LC_PROP_G_TEXT_ANG = 145
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1125
try:
    LC_PROP_G_TEXT_OBL = 146
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1126
try:
    LC_PROP_G_TEXT_UPDOWN = 147
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1127
try:
    LC_PROP_G_TEXT_BACK = 148
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1128
try:
    LC_PROP_G_TEXT_FILL = 149
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1129
try:
    LC_PROP_G_TEXT_BORDER = 150
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1131
try:
    LC_PROP_G_BARC_CENTER = 161
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1133
try:
    LC_PROP_G_BARC_ANGLE = 162
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1134
try:
    LC_PROP_G_BARC_BELOW = 163
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1136
try:
    LC_PROP_G_BARC_QZONE = 164
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1137
try:
    LC_PROP_G_BARC_CHKSUM = 165
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1138
try:
    LC_PROP_G_BARC_ECL = 166
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1140
try:
    LC_PROP_G_BARC_INVERT = 167
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1141
try:
    LC_PROP_G_BARC_WRATIO = 168
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1143
try:
    LC_PROP_G_BARC_LINEW = 169
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1145
try:
    LC_PROP_G_BEAMCOLOR0D = 191
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1147
try:
    LC_PROP_G_BEAMCOLOR1D = 192
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1148
try:
    LC_PROP_G_BEAMCOLOR2D = 193
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1149
try:
    LC_PROP_G_BEAMCOLOR0U = 194
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1151
try:
    LC_PROP_G_BEAMCOLOR1U = 195
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1152
try:
    LC_PROP_G_BEAMCOLOR2U = 196
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1154
try:
    LC_PROP_G_NAV_LEFT = 201
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1155
try:
    LC_PROP_G_NAV_TOP = 202
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1156
try:
    LC_PROP_G_NAV_WIDTH = 203
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1157
try:
    LC_PROP_G_NAV_HEIGHT = 204
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1159
try:
    LC_PROP_G_JL_EALEN = 210
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1160
try:
    LC_PROP_G_JL_EAW = 211
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1161
try:
    LC_PROP_G_JL_JALEN = 212
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1162
try:
    LC_PROP_G_JL_JAW = 213
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1163
try:
    LC_PROP_G_JL_ACOLOR = 214
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1165
try:
    LC_PROP_G_JL_NUMFONT = 215
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1167
try:
    LC_PROP_G_JL_NUMSIZE = 216
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1169
try:
    LC_PROP_G_JL_NUMCOLOR = 217
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1171
try:
    LC_PROP_G_JL_DRAWJARR = 218
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1172
try:
    LC_PROP_G_JL_DRAWJLINE = 219
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1174
try:
    LC_PROP_G_JL_DRAWEDOT = 220
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1175
try:
    LC_PROP_G_JL_DRAWEARR = 221
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1176
try:
    LC_PROP_G_JL_DRAWENUM = 222
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1178
try:
    LC_PROP_G_OSNAP_MARK = 226
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1179
try:
    LC_PROP_G_OSNAP_APER = 227
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1180
try:
    LC_PROP_G_OSNAP_MARKSIZE = 228
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1182
try:
    LC_PROP_G_OSNAP_APERSIZE = 229
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1185
try:
    LC_PROP_G_OSNAP_MARKCOLOR = 230
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1191
try:
    LC_PROP_G_EMUL_OVERDIST = 232
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1193
try:
    LC_PROP_G_EMUL_OVERCOLOR = 233
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1196
try:
    LC_PROP_G_RAS_FILL = 250
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1197
try:
    LC_PROP_G_RAS_COLOR = 251
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1199
try:
    LC_PROP_G_RAS_NOPRINT = 252
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1202
try:
    LC_PROP_G_WPT_TEXTX = 260
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1203
try:
    LC_PROP_G_WPT_TEXTY = 261
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1204
try:
    LC_PROP_G_WPT_TEXTA = 262
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1206
try:
    LC_PROP_G_TIN_PT0 = 270
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1207
try:
    LC_PROP_G_TIN_PT1 = 271
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1208
try:
    LC_PROP_G_TIN_TR = 272
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1211
try:
    LC_PROP_WND__MIN = 301
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1212
try:
    LC_PROP_WND_ID = 301
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1213
try:
    LC_PROP_WND_WIDTH = 302
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1214
try:
    LC_PROP_WND_HEIGHT = 303
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1215
try:
    LC_PROP_WND_PIXELSIZE = 304
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1217
try:
    LC_PROP_WND_PICKBOXSIZE = 305
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1219
try:
    LC_PROP_WND_CURSORX = 306
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1222
try:
    LC_PROP_WND_CURX = 306
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1223
try:
    LC_PROP_WND_CURSORY = 307
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1226
try:
    LC_PROP_WND_CURY = 307
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1227
try:
    LC_PROP_WND_CURLEF = 308
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1229
try:
    LC_PROP_WND_CURBOT = 309
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1231
try:
    LC_PROP_WND_CURRIG = 310
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1233
try:
    LC_PROP_WND_CURTOP = 311
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1235
try:
    LC_PROP_WND_XMIN = 312
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1236
try:
    LC_PROP_WND_YMIN = 313
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1237
try:
    LC_PROP_WND_XMAX = 314
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1238
try:
    LC_PROP_WND_YMAX = 315
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1239
try:
    LC_PROP_WND_XCEN = 316
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1240
try:
    LC_PROP_WND_YCEN = 317
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1241
try:
    LC_PROP_WND_DX = 318
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1242
try:
    LC_PROP_WND_DY = 319
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1243
try:
    LC_PROP_WND_RULERSENABLE = 320
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1245
try:
    LC_PROP_WND_RULERS = 321
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1246
try:
    LC_PROP_WND_SELECT = 322
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1247
try:
    LC_PROP_WND_VIEWBLOCK = 323
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1248
try:
    LC_PROP_WND_BLOCK = 323
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1249
try:
    LC_PROP_WND_DRW = 324
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1250
try:
    LC_PROP_WND_HWND = 325
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1251
try:
    LC_PROP_WND_HASFOCUS = 326
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1252
try:
    LC_PROP_WND_HASFILETABS = 327
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1253
try:
    LC_PROP_WND_NUMFILETABS = 328
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1254
try:
    LC_PROP_WND_NUMDRW = 328
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1255
try:
    LC_PROP_WND_DROPFILES = 329
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1257
try:
    LC_PROP_WND_ZOOMWHEEL = 330
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1261
try:
    LC_PROP_WND_JUMPLINES = 339
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1262
try:
    LC_PROP_WND_MAGNIFIER = 340
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1264
try:
    LC_PROP_WND_NAVIGATOR = 341
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1265
try:
    LC_PROP_WND_COLORBG = 342
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1266
try:
    LC_PROP_WND_COLORCURSOR = 343
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1267
try:
    LC_PROP_WND_COLORFORE = 344
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1268
try:
    LC_PROP_WND_COLORINFBG = 345
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1269
try:
    LC_PROP_WND_COLORINFBORD = 346
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1270
try:
    LC_PROP_WND_COLORINFTEXT = 347
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1271
try:
    LC_PROP_WND_CURSORSYS = 348
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1272
try:
    LC_PROP_WND_CURSORARROW = 348
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1275
try:
    LC_PROP_WND_CURSORCROSS = 349
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1276
try:
    LC_PROP_WND_CURSORSIZE = 350
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1279
try:
    LC_PROP_WND_CURSORPBOX = 351
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1280
try:
    LC_PROP_WND_COORDS = 352
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1282
try:
    LC_PROP_WND_ENT = 353
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1284
try:
    LC_PROP_WND_PROPWND = 354
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1285
try:
    LC_PROP_WND_BLOCKBPT = 355
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1286
try:
    LC_PROP_WND_LWMODE = 355
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1288
try:
    LC_PROP_WND_LWSCALE = 356
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1292
try:
    LC_PROP_WND_ALPHABLEND = 360
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1294
try:
    LC_PROP_WND_STDBLKFRAME = 361
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1296
try:
    LC_PROP_WND_BLKBASEPT = 362
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1297
try:
    LC_PROP_WND_SIZE = 363
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1300
try:
    LC_PROP_WND_DTIME = 364
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1301
try:
    LC_PROP_WND_DRAWPAPER = 365
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1303
try:
    LC_PROP_WND_FROZEN = 366
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1304
try:
    LC_PROP_WND_FROZENVIEW = 367
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1305
try:
    LC_PROP_WND_COMMAND = 368
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1308
try:
    LC_PROP_WND_CMD = 368
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1309
try:
    LC_PROP_WND_CMDENT1 = 369
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1312
try:
    LC_PROP_WND_OSNAP = 370
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1314
try:
    LC_PROP_WND_OSNAPMENU = 371
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1317
try:
    LC_PROP_WND_ORTHO = 372
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1318
try:
    LC_PROP_WND_PTRACK = 373
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1319
try:
    LC_PROP_WND_PTRACK_ANGLE = 374
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1320
try:
    LC_PROP_WND_PTRACK_ANGREL = 375
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1321
try:
    LC_PROP_WND_PTRACK_DIST = 376
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1324
try:
    LC_PROP_WND_BASEPT = 377
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1325
try:
    LC_PROP_WND_BASEX = 378
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1326
try:
    LC_PROP_WND_BASEY = 379
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1327
try:
    LC_PROP_WND_GRIDSNAP = 380
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1328
try:
    LC_PROP_WND_GRIDSHOW = 381
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1329
try:
    LC_PROP_WND_GRIDDX = 382
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1330
try:
    LC_PROP_WND_GRIDDY = 383
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1331
try:
    LC_PROP_WND_GRIDX0 = 384
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1332
try:
    LC_PROP_WND_GRIDY0 = 385
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1333
try:
    LC_PROP_WND_GRIDBOLDX = 386
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1334
try:
    LC_PROP_WND_GRIDBOLDY = 387
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1335
try:
    LC_PROP_WND_GRIDCOLOR = 388
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1336
try:
    LC_PROP_WND_GRIDDOTTED = 389
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1337
try:
    LC_PROP_WND_GRIDCOLOR2 = 390
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1338
try:
    LC_PROP_WND_GRIDDOTTED2 = 391
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1340
try:
    LC_PROP_WND_RSNAP = 402
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1341
try:
    LC_PROP_WND_RSNAPSHOW = 403
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1342
try:
    LC_PROP_WND_RSNAPLEF = 404
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1343
try:
    LC_PROP_WND_RSNAPBOT = 405
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1344
try:
    LC_PROP_WND_RSNAPRIG = 406
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1345
try:
    LC_PROP_WND_RSNAPTOP = 407
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1346
try:
    LC_PROP_WND_RSNAPW = 408
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1347
try:
    LC_PROP_WND_RSNAPH = 409
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1348
try:
    LC_PROP_WND_RSNAPCOLORM = 410
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1350
try:
    LC_PROP_WND_RSNAPCOLORP = 411
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1353
try:
    LC_PROP_WND_PANSTEP = 420
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1354
try:
    LC_PROP_WND_PANLW = 421
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1356
try:
    LC_PROP_WND_PANIMAGE = 422
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1358
try:
    LC_PROP_WND_PANFILL = 423
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1360
try:
    LC_PROP_WND_PANPIXSZ = 424
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1363
try:
    LC_PROP_WND_MEASCOLORPNT = 430
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1365
try:
    LC_PROP_WND_MEASCOLORLINE = 431
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1367
try:
    LC_PROP_WND_MEASLINESIZE = 432
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1368
try:
    LC_PROP_WND_MEASFONTSIZE = 433
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1369
try:
    LC_PROP_WND_MEASFILLAREA = 434
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1371
try:
    LC_PROP_WND_KBMOVE_ENABLE = 437
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1372
try:
    LC_PROP_WND_KBMOVE_DIST = 438
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1373
try:
    LC_PROP_WND_KBMOVE_ANGLE = 439
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1374
try:
    LC_PROP_WND_KBMOVE_SCALE = 440
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1376
try:
    LC_PROP_WND_XLINEANG = 444
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1378
try:
    LC_PROP_WND_BGIMAGE = 445
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1380
try:
    LC_PROP_WND_LTVIEWMIN = 446
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1382
try:
    LC_PROP_WND_LTVIEWMAX = 447
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1385
try:
    LC_PROP_WND_FRAME_LEFT = 451
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1387
try:
    LC_PROP_WND_FRAME_TOP = 452
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1389
try:
    LC_PROP_WND_FRAME_WIDTH = 453
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1390
try:
    LC_PROP_WND_FRAME_HEIGHT = 454
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1393
try:
    LC_PROP_WND_HANDLE0 = 460
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1394
try:
    LC_PROP_WND_HANDLE1 = 461
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1395
try:
    LC_PROP_WND_HANDLE2 = 462
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1396
try:
    LC_PROP_WND_HANDLE3 = 463
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1397
try:
    LC_PROP_WND_HANDLE4 = 464
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1398
try:
    LC_PROP_WND_HANDLE5 = 465
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1399
try:
    LC_PROP_WND_HANDLE6 = 466
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1400
try:
    LC_PROP_WND_HANDLE7 = 467
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1401
try:
    LC_PROP_WND_HANDLE8 = 468
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1402
try:
    LC_PROP_WND_HANDLE9 = 469
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1403
try:
    LC_PROP_WND_INT0 = 470
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1404
try:
    LC_PROP_WND_INT1 = 471
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1405
try:
    LC_PROP_WND_INT2 = 472
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1406
try:
    LC_PROP_WND_INT3 = 473
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1407
try:
    LC_PROP_WND_INT4 = 474
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1408
try:
    LC_PROP_WND_INT5 = 475
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1409
try:
    LC_PROP_WND_INT6 = 476
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1410
try:
    LC_PROP_WND_INT7 = 477
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1411
try:
    LC_PROP_WND_INT8 = 478
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1412
try:
    LC_PROP_WND_INT9 = 479
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1413
try:
    LC_PROP_WND_FLOAT0 = 480
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1414
try:
    LC_PROP_WND_FLOAT1 = 481
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1415
try:
    LC_PROP_WND_FLOAT2 = 482
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1416
try:
    LC_PROP_WND_FLOAT3 = 483
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1417
try:
    LC_PROP_WND_FLOAT4 = 484
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1418
try:
    LC_PROP_WND_FLOAT5 = 485
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1419
try:
    LC_PROP_WND_FLOAT6 = 486
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1420
try:
    LC_PROP_WND_FLOAT7 = 487
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1421
try:
    LC_PROP_WND_FLOAT8 = 488
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1422
try:
    LC_PROP_WND_FLOAT9 = 489
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1423
try:
    LC_PROP_WND_STR0 = 490
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1424
try:
    LC_PROP_WND_STR1 = 491
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1425
try:
    LC_PROP_WND_STR2 = 492
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1426
try:
    LC_PROP_WND_STR3 = 493
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1427
try:
    LC_PROP_WND_STR4 = 494
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1428
try:
    LC_PROP_WND_STR5 = 495
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1429
try:
    LC_PROP_WND_STR6 = 496
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1430
try:
    LC_PROP_WND_STR7 = 497
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1431
try:
    LC_PROP_WND_STR8 = 498
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1432
try:
    LC_PROP_WND_STR9 = 499
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1433
try:
    LC_PROP_WND__MAX = 499
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1436
try:
    LC_PROP_SBAR__MIN = 501
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1437
try:
    LC_PROP_SBAR_H = 501
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1438
try:
    LC_PROP_SBAR_FONTNAME = 502
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1439
try:
    LC_PROP_SBAR_FONTSIZE = 503
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1440
try:
    LC_PROP_SBAR_TEXTY = 504
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1441
try:
    LC_PROP_SBAR_TEXTCOLOR = 505
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1442
try:
    LC_PROP_SBAR_BGCOLOR = 506
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1443
try:
    LC_PROP_SBAR_FRAMECOLOR = 507
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1444
try:
    LC_PROP_SBAR__MAX = 519
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1447
try:
    LC_PROP_FONT__MIN = 601
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1448
try:
    LC_PROP_FONT_FILENAME = 601
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1449
try:
    LC_PROP_FONT_NAME = 602
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1450
try:
    LC_PROP_FONT_LCF = 603
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1451
try:
    LC_PROP_FONT_HEIGHT = 604
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1452
try:
    LC_PROP_FONT_FILLED = 605
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1453
try:
    LC_PROP_FONT_TTF = 606
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1454
try:
    LC_PROP_FONT_NCHARS = 607
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1455
try:
    LC_PROP_FONT__MAX = 629
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1458
try:
    LC_PROP_MPGON__MIN = 631
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1459
try:
    LC_PROP_MPGON_XMIN = 631
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1460
try:
    LC_PROP_MPGON_YMIN = 632
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1461
try:
    LC_PROP_MPGON_XMAX = 633
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1462
try:
    LC_PROP_MPGON_YMAX = 634
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1463
try:
    LC_PROP_MPGON_XCEN = 635
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1464
try:
    LC_PROP_MPGON_YCEN = 636
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1465
try:
    LC_PROP_MPGON_W = 637
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1466
try:
    LC_PROP_MPGON_H = 638
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1467
try:
    LC_PROP_MPGON__MAX = 649
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1470
try:
    LC_PROP_TINPTYPE__MIN = 680
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1471
try:
    LC_PROP_TINPTYPE_NAME = 680
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1472
try:
    LC_PROP_TINPTYPE_DTEXT = 681
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1473
try:
    LC_PROP_TINPTYPE_COLOR = 682
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1474
try:
    LC_PROP_TINPTYPE__MAX = 699
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1477
try:
    LC_PROP_TINPNT__MIN = 701
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1478
try:
    LC_PROP_TINPNT_TYPE = 701
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1479
try:
    LC_PROP_TINPNT_I = 702
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1480
try:
    LC_PROP_TINPNT_X = 703
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1481
try:
    LC_PROP_TINPNT_Y = 704
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1482
try:
    LC_PROP_TINPNT_Z = 705
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1483
try:
    LC_PROP_TINPNT_COLOR = 706
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1484
try:
    LC_PROP_TINPNT_NAME = 707
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1485
try:
    LC_PROP_TINPNT_ONAME = 708
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1487
try:
    LC_PROP_TINPNT_DESCR = 709
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1488
try:
    LC_PROP_TINPNT_IMGFILE = 715
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1489
try:
    LC_PROP_TINPNT_IMGFILE2 = 716
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1490
try:
    LC_PROP_TINPNT_ATTR = 720
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1491
try:
    LC_PROP_TINPNT_ATTR1 = 721
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1492
try:
    LC_PROP_TINPNT_ATTR2 = 722
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1493
try:
    LC_PROP_TINPNT_ATTR3 = 723
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1494
try:
    LC_PROP_TINPNT_ATTR4 = 724
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1495
try:
    LC_PROP_TINPNT_ATTR5 = 725
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1496
try:
    LC_PROP_TINPNT_ATTR6 = 726
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1497
try:
    LC_PROP_TINPNT_ATTR7 = 727
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1498
try:
    LC_PROP_TINPNT_ATTR8 = 728
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1499
try:
    LC_PROP_TINPNT_ATTR9 = 729
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1500
try:
    LC_PROP_TINPNT__MAX = 730
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1503
try:
    LC_PROP_TINTR__MIN = 731
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1504
try:
    LC_PROP_TINTR_I = 731
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1505
try:
    LC_PROP_TINTR_IPT0 = 732
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1506
try:
    LC_PROP_TINTR_IPT1 = 733
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1507
try:
    LC_PROP_TINTR_IPT2 = 734
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1508
try:
    LC_PROP_TINTR_PT0 = 735
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1509
try:
    LC_PROP_TINTR_PT1 = 736
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1510
try:
    LC_PROP_TINTR_PT2 = 737
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1511
try:
    LC_PROP_TINTR_PT0X = 738
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1512
try:
    LC_PROP_TINTR_PT0Y = 739
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1513
try:
    LC_PROP_TINTR_PT0Z = 740
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1514
try:
    LC_PROP_TINTR_PT1X = 741
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1515
try:
    LC_PROP_TINTR_PT1Y = 742
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1516
try:
    LC_PROP_TINTR_PT1Z = 743
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1517
try:
    LC_PROP_TINTR_PT2X = 744
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1518
try:
    LC_PROP_TINTR_PT2Y = 745
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1519
try:
    LC_PROP_TINTR_PT2Z = 746
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1520
try:
    LC_PROP_TINTR_XC = 747
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1521
try:
    LC_PROP_TINTR_YC = 748
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1522
try:
    LC_PROP_TINTR_ZC = 749
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1523
try:
    LC_PROP_TINTR_NVX = 750
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1524
try:
    LC_PROP_TINTR_NVY = 751
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1525
try:
    LC_PROP_TINTR_NVZ = 752
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1526
try:
    LC_PROP_TINTR_NANG = 753
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1527
try:
    LC_PROP_TINTR_XMIN = 754
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1528
try:
    LC_PROP_TINTR_YMIN = 755
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1529
try:
    LC_PROP_TINTR_ZMIN = 756
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1530
try:
    LC_PROP_TINTR_XMAX = 757
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1531
try:
    LC_PROP_TINTR_YMAX = 758
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1532
try:
    LC_PROP_TINTR_ZMAX = 759
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1533
try:
    LC_PROP_TINTR_DX = 760
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1534
try:
    LC_PROP_TINTR_DY = 761
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1535
try:
    LC_PROP_TINTR_DZ = 762
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1536
try:
    LC_PROP_TINTR_FLAGS = 763
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1537
try:
    LC_PROP_TINTR_MARK = 764
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1538
try:
    LC_PROP_TINTR_EDGE_PT0 = 771
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1539
try:
    LC_PROP_TINTR_EDGE_PT1 = 772
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1540
try:
    LC_PROP_TINTR_EDGE_TR = 773
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1541
try:
    LC_PROP_TINTR__MAX = 780
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1544
try:
    LC_PROP_TINISO__MIN = 781
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1545
try:
    LC_PROP_TINISO_Z = 781
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1546
try:
    LC_PROP_TINISO_NVERS = 782
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1547
try:
    LC_PROP_TINISO_IVER = 783
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1548
try:
    LC_PROP_TINISO_X = 784
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1549
try:
    LC_PROP_TINISO_Y = 785
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1550
try:
    LC_PROP_TINISO_CLOSED = 786
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1551
try:
    LC_PROP_TINISO__MAX = 800
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1556
try:
    LC_PROP_GRID__MIN = 1881
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1557
try:
    LC_PROP_GRID_XMIN = 1882
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1558
try:
    LC_PROP_GRID_XMAX = 1883
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1559
try:
    LC_PROP_GRID_YMIN = 1884
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1560
try:
    LC_PROP_GRID_YMAX = 1885
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1561
try:
    LC_PROP_GRID_W = 1886
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1562
try:
    LC_PROP_GRID_H = 1887
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1563
try:
    LC_PROP_GRID_NCELLX = 1888
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1564
try:
    LC_PROP_GRID_NCELLY = 1889
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1565
try:
    LC_PROP_GRID__MAX = 1890
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1568
try:
    LC_PROP_CMD__MIN = 2001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1569
try:
    LC_PROP_CMD_ID = 2001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1570
try:
    LC_PROP_CMD_PARAM = 2002
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1571
try:
    LC_PROP_CMD_STEP = 2003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1572
try:
    LC_PROP_CMD_LCWND = 2004
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1573
try:
    LC_PROP_CMD_HWND = 2005
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1574
try:
    LC_PROP_CMD_DRW = 2006
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1575
try:
    LC_PROP_CMD_BLOCK = 2007
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1576
try:
    LC_PROP_CMD_CURSORCROSS = 2008
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1577
try:
    LC_PROP_CMD_INT0 = 2010
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1578
try:
    LC_PROP_CMD_INT1 = 2011
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1579
try:
    LC_PROP_CMD_INT2 = 2012
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1580
try:
    LC_PROP_CMD_INT3 = 2013
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1581
try:
    LC_PROP_CMD_INT4 = 2014
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1582
try:
    LC_PROP_CMD_INT5 = 2015
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1583
try:
    LC_PROP_CMD_INT6 = 2016
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1584
try:
    LC_PROP_CMD_INT7 = 2017
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1585
try:
    LC_PROP_CMD_INT8 = 2018
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1586
try:
    LC_PROP_CMD_INT9 = 2019
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1587
try:
    LC_PROP_CMD_FLOAT0 = 2020
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1588
try:
    LC_PROP_CMD_FLOAT1 = 2021
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1589
try:
    LC_PROP_CMD_FLOAT2 = 2022
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1590
try:
    LC_PROP_CMD_FLOAT3 = 2023
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1591
try:
    LC_PROP_CMD_FLOAT4 = 2024
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1592
try:
    LC_PROP_CMD_FLOAT5 = 2025
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1593
try:
    LC_PROP_CMD_FLOAT6 = 2026
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1594
try:
    LC_PROP_CMD_FLOAT7 = 2027
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1595
try:
    LC_PROP_CMD_FLOAT8 = 2028
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1596
try:
    LC_PROP_CMD_FLOAT9 = 2029
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1597
try:
    LC_PROP_CMD_HAND0 = 2030
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1598
try:
    LC_PROP_CMD_HAND1 = 2031
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1599
try:
    LC_PROP_CMD_HAND2 = 2032
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1600
try:
    LC_PROP_CMD_HAND3 = 2033
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1601
try:
    LC_PROP_CMD_HAND4 = 2034
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1602
try:
    LC_PROP_CMD_HAND5 = 2035
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1603
try:
    LC_PROP_CMD_HAND6 = 2036
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1604
try:
    LC_PROP_CMD_HAND7 = 2037
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1605
try:
    LC_PROP_CMD_HAND8 = 2038
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1606
try:
    LC_PROP_CMD_HAND9 = 2039
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1607
try:
    LC_PROP_CMD_STR = 2040
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1609
try:
    LC_PROP_CMD__MAX = 2050
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1614
try:
    LC_PROP_DRW__MIN = 3001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1615
try:
    LC_PROP_DRW_UID = 3001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1616
try:
    LC_PROP_DRW_FILENAME = 3002
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1617
try:
    LC_PROP_DRW_DESCR = 3003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1618
try:
    LC_PROP_DRW_COMMENT = 3003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1619
try:
    LC_PROP_DRW_READONLY = 3004
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1620
try:
    LC_PROP_DRW_DIRTY = 3005
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1621
try:
    LC_PROP_DRW_IDMAX = 3006
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1623
try:
    LC_PROP_DRW_SYNCZOOM = 3011
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1624
try:
    LC_PROP_DRW_HASALPHABLEND = 3013
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1626
try:
    LC_PROP_DRW_BLKREFGRIPS = 3014
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1628
try:
    LC_PROP_DRW_JL_BASE = 3015
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1629
try:
    LC_PROP_DRW_JL_BASEX = 3016
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1630
try:
    LC_PROP_DRW_JL_BASEY = 3017
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1631
try:
    LC_PROP_DRW_JL_LAYER = 3018
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1633
try:
    LC_PROP_DRW_EXTOFFLAYER = 3019
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1635
try:
    LC_PROP_DRW_ENABLEUNDO = 3021
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1636
try:
    LC_PROP_DRW_LOCKSEL = 3022
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1637
try:
    LC_PROP_DRW_MAXHATDASH = 3023
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1639
try:
    LC_PROP_DRW_PROPLINFILL = 3024
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1641
try:
    LC_PROP_DRW_PROPZTH = 3025
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1644
try:
    LC_PROP_DRW_3DVIEW = 3026
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1645
try:
    LC_PROP_DRW_PBTEXT = 3027
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1648
try:
    LC_PROP_DRW_LUNITS = 3031
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1650
try:
    LC_PROP_DRW_LUPREC = 3032
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1652
try:
    LC_PROP_DRW_AUNITS = 3033
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1654
try:
    LC_PROP_DRW_AUPREC = 3034
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1656
try:
    LC_PROP_DRW_ANGBASE = 3035
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1657
try:
    LC_PROP_DRW_ANGDIR = 3036
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1659
try:
    LC_PROP_DRW_INSUNITS = 3037
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1660
try:
    LC_PROP_DRW_PDMODE = 3038
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1662
try:
    LC_PROP_DRW_PDSIZE = 3039
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1664
try:
    LC_PROP_DRW_CMLJUST = 3040
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1667
try:
    LC_PROP_DRW_CMLSCALE = 3041
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1670
try:
    LC_PROP_DRW_COLORBACKM = 3051
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1671
try:
    LC_PROP_DRW_COLORBACKP = 3052
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1672
try:
    LC_PROP_DRW_COLORFOREM = 3053
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1673
try:
    LC_PROP_DRW_COLORFOREP = 3054
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1674
try:
    LC_PROP_DRW_COLORCURSORM = 3055
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1675
try:
    LC_PROP_DRW_COLORCURSORP = 3056
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1676
try:
    LC_PROP_DRW_COLORPAPER = 3057
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1680
try:
    LC_PROP_DRW_COLOR = 3061
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1681
try:
    LC_PROP_DRW_COLORBYLAYER = 3062
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1682
try:
    LC_PROP_DRW_COLORBYBLOCK = 3063
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1683
try:
    LC_PROP_DRW_COLORI = 3064
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1684
try:
    LC_PROP_DRW_COLORT = 3065
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1687
try:
    LC_PROP_DRW_FCOLOR = 3066
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1688
try:
    LC_PROP_DRW_FCOLORBYLAYER = 3067
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1689
try:
    LC_PROP_DRW_FCOLORBYBLOCK = 3068
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1690
try:
    LC_PROP_DRW_FCOLORI = 3069
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1691
try:
    LC_PROP_DRW_FCOLORT = 3070
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1694
try:
    LC_PROP_DRW_LAYER = 3081
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1696
try:
    LC_PROP_DRW_LINETYPE = 3082
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1698
try:
    LC_PROP_DRW_LTSCALE = 3083
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1699
try:
    LC_PROP_DRW_TEXTSTYLE = 3084
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1701
try:
    LC_PROP_DRW_DIMSTYLE = 3085
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1703
try:
    LC_PROP_DRW_PNTSTYLE = 3086
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1706
try:
    LC_PROP_DRW_MLSTYLE = 3087
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1709
try:
    LC_PROP_DRW_BLOCK = 3089
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1711
try:
    LC_PROP_DRW_VISBLOCK = 3090
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1714
try:
    LC_PROP_DRW_LAYOUT = 3091
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1716
try:
    LC_PROP_DRW_BARCTYPE = 3092
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1718
try:
    LC_PROP_DRW_BARCSOLID = 3093
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1720
try:
    LC_PROP_DRW_LWMODE = 3094
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1722
try:
    LC_PROP_DRW_LWSCALE = 3095
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1724
try:
    LC_PROP_DRW_LWIDTH = 3096
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1725
try:
    LC_PROP_DRW_LWDEFAULT = 3097
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1727
try:
    LC_PROP_DRW_LINFILL = 3098
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1729
try:
    LC_PROP_DRW_TINPNT = 3102
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1730
try:
    LC_PROP_DRW_TINTR = 3103
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1732
try:
    LC_PROP_DRW_TINXY0 = 3104
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1735
try:
    LC_PROP_DRW_EXPLODEARC = 3131
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1737
try:
    LC_PROP_DRW_EXPPLINELA = 3132
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1740
try:
    LC_PROP_DRW_EXPSIMPLINE = 3133
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1742
try:
    LC_PROP_DRW_EXPTEXTSPLINE = 3134
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1746
try:
    LC_PROP_DRW_BLOCK_MODEL = 3151
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1747
try:
    LC_PROP_DRW_LAYER_0 = 3152
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1748
try:
    LC_PROP_DRW_LINETYPE_CONT = 3153
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1750
try:
    LC_PROP_DRW_LINETYPE_BYLAY = 3154
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1752
try:
    LC_PROP_DRW_LINETYPE_BYBLK = 3155
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1754
try:
    LC_PROP_DRW_TEXTSTYLE_STD = 3156
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1756
try:
    LC_PROP_DRW_TSTYLE_STD = 3156
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1757
try:
    LC_PROP_DRW_PNTSTYLE_STD = 3157
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1759
try:
    LC_PROP_DRW_DIMSTYLE_STD = 3158
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1761
try:
    LC_PROP_DRW_MLSTYLE_STD = 3159
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1765
try:
    LC_PROP_DRW_RESOLARC = 3171
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1767
try:
    LC_PROP_DRW_RESOLSPLINE = 3172
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1768
try:
    LC_PROP_DRW_RESOLTEXT = 3173
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1771
try:
    LC_PROP_DRW_LIM_MINPIXSIZE = 3181
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1773
try:
    LC_PROP_DRW_LIM_MAXLEF = 3182
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1774
try:
    LC_PROP_DRW_LIM_MAXBOT = 3183
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1775
try:
    LC_PROP_DRW_LIM_MAXRIG = 3184
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1776
try:
    LC_PROP_DRW_LIM_MAXTOP = 3185
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1777
try:
    LC_PROP_DRW_LIM_MAXON = 3186
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1780
try:
    LC_PROP_DRW_XDATASIZE = 3251
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1781
try:
    LC_PROP_DRW_XDATA = 3252
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1782
try:
    LC_PROP_DRW_INT0 = 3260
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1783
try:
    LC_PROP_DRW_INT1 = 3261
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1784
try:
    LC_PROP_DRW_INT2 = 3262
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1785
try:
    LC_PROP_DRW_INT3 = 3263
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1786
try:
    LC_PROP_DRW_INT4 = 3264
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1787
try:
    LC_PROP_DRW_INT5 = 3265
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1788
try:
    LC_PROP_DRW_INT6 = 3266
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1789
try:
    LC_PROP_DRW_INT7 = 3267
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1790
try:
    LC_PROP_DRW_INT8 = 3268
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1791
try:
    LC_PROP_DRW_INT9 = 3269
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1792
try:
    LC_PROP_DRW_FLOAT0 = 3270
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1793
try:
    LC_PROP_DRW_FLOAT1 = 3271
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1794
try:
    LC_PROP_DRW_FLOAT2 = 3272
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1795
try:
    LC_PROP_DRW_FLOAT3 = 3273
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1796
try:
    LC_PROP_DRW_FLOAT4 = 3274
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1797
try:
    LC_PROP_DRW_FLOAT5 = 3275
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1798
try:
    LC_PROP_DRW_FLOAT6 = 3276
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1799
try:
    LC_PROP_DRW_FLOAT7 = 3277
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1800
try:
    LC_PROP_DRW_FLOAT8 = 3278
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1801
try:
    LC_PROP_DRW_FLOAT9 = 3279
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1802
try:
    LC_PROP_DRW_STR0 = 3280
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1803
try:
    LC_PROP_DRW_STR1 = 3281
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1804
try:
    LC_PROP_DRW_STR2 = 3282
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1805
try:
    LC_PROP_DRW_STR3 = 3283
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1806
try:
    LC_PROP_DRW_STR4 = 3284
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1807
try:
    LC_PROP_DRW_STR5 = 3285
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1808
try:
    LC_PROP_DRW_STR6 = 3286
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1809
try:
    LC_PROP_DRW_STR7 = 3287
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1810
try:
    LC_PROP_DRW_STR8 = 3288
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1811
try:
    LC_PROP_DRW_STR9 = 3289
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1812
try:
    LC_PROP_DRW__MAX = 3299
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1817
try:
    LC_PROP_TABLE__MIN = 4000
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1820
try:
    LC_PROP_TABLE_ID = 4001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1821
try:
    LC_PROP_TABLE_NAME = 4002
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1822
try:
    LC_PROP_TABLE_DESC = 4003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1823
try:
    LC_PROP_TABLE_DESCR = 4003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1824
try:
    LC_PROP_TABLE_DRW = 4004
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1825
try:
    LC_PROP_TABLE_DELETED = 4005
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1826
try:
    LC_PROP_TABLE_ODA_HANDLE = 4010
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1827
try:
    LC_PROP_TABLE_TYPE = 4011
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1828
try:
    LC_PROP_TABLE_PRIORITY = 4012
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1829
try:
    LC_PROP_TABLE_NREFS = 4013
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1830
try:
    LC_PROP_TABLE_XDATASIZE = 4051
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1831
try:
    LC_PROP_TABLE_XDATA = 4052
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1832
try:
    LC_PROP_TABLE_XSTR = 4053
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1833
try:
    LC_PROP_TABLE_INT0 = 4060
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1834
try:
    LC_PROP_TABLE_INT1 = 4061
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1835
try:
    LC_PROP_TABLE_INT2 = 4062
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1836
try:
    LC_PROP_TABLE_INT3 = 4063
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1837
try:
    LC_PROP_TABLE_INT4 = 4064
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1838
try:
    LC_PROP_TABLE_FLOAT0 = 4070
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1839
try:
    LC_PROP_TABLE_FLOAT1 = 4071
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1840
try:
    LC_PROP_TABLE_FLOAT2 = 4072
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1841
try:
    LC_PROP_TABLE_FLOAT3 = 4073
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1842
try:
    LC_PROP_TABLE_FLOAT4 = 4074
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1843
try:
    LC_PROP_TABLEBASE__MAX = 4100
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1846
try:
    LC_PROP_LAYER_ID = 4001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1848
try:
    LC_PROP_LAYER_NAME = 4002
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1850
try:
    LC_PROP_LAYER_DESC = 4003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1852
try:
    LC_PROP_LAYER_DESCR = 4003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1853
try:
    LC_PROP_LAYER_DRW = 4004
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1854
try:
    LC_PROP_LAYER_DELETED = 4005
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1855
try:
    LC_PROP_LAYER_COLOR = 4101
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1856
try:
    LC_PROP_LAYER_COLORI = 4102
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1857
try:
    LC_PROP_LAYER_COLORT = 4103
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1858
try:
    LC_PROP_LAYER_FCOLOR = 4104
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1859
try:
    LC_PROP_LAYER_FCOLORI = 4105
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1860
try:
    LC_PROP_LAYER_FCOLORT = 4106
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1861
try:
    LC_PROP_LAYER_LINETYPE = 4111
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1863
try:
    LC_PROP_LAYER_LWEIGHT = 4112
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1864
try:
    LC_PROP_LAYER_LWIDTH = 4112
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1865
try:
    LC_PROP_LAYER_LOCKED = 4113
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1866
try:
    LC_PROP_LAYER_NOPRINT = 4114
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1867
try:
    LC_PROP_LAYER_VISIBLE = 4115
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1868
try:
    LC_PROP_LAYER_0 = 4116
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1869
try:
    LC_PROP_LAYER_NODLG = 4117
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1871
try:
    LC_PROP_LAYER_JUMPLINES = 4118
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1873
try:
    LC_PROP_LAYER_OSNAP = 4119
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1875
try:
    LC_PROP_LAYER_NOEXPORT = 4120
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1878
try:
    LC_PROP_LINETYPE_ID = 4001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1879
try:
    LC_PROP_LINETYPE_NAME = 4002
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1880
try:
    LC_PROP_LINETYPE_DESC = 4003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1881
try:
    LC_PROP_LINETYPE_DESCR = 4003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1882
try:
    LC_PROP_LINETYPE_DRW = 4004
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1883
try:
    LC_PROP_LINETYPE_DELETED = 4005
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1884
try:
    LC_PROP_LINETYPE_DATA = 4145
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1885
try:
    LC_PROP_LINETYPE_SCALE = 4146
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1886
try:
    LC_PROP_LINETYPE_CONTINUOUS = 4147
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1887
try:
    LC_PROP_LINETYPE_BYLAYER = 4148
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1888
try:
    LC_PROP_LINETYPE_BYBLOCK = 4149
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1889
try:
    LC_PROP_LINETYPE_STD = 4150
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1892
try:
    LC_PROP_LINETYPE_PATLEN = 4151
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1893
try:
    LC_PROP_LINETYPE_NELEM = 4153
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1894
try:
    LC_PROP_LINETYPE_IELEM = 4154
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1895
try:
    LC_PROP_LTELEM_LEN = 4155
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1896
try:
    LC_PROP_LTELEM_COMPLEX = 4156
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1898
try:
    LC_PROP_LTELEM_SHAPE = 4157
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1901
try:
    LC_PROP_LTELEM_TEXT = 4158
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1902
try:
    LC_PROP_LTELEM_STYLE = 4159
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1904
try:
    LC_PROP_LTELEM_FONTNAME = 4160
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1906
try:
    LC_PROP_LTELEM_SCALE = 4161
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1907
try:
    LC_PROP_LTELEM_ANGLE = 4162
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1909
try:
    LC_PROP_LTELEM_ABSANGLE = 4163
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1910
try:
    LC_PROP_LTELEM_X = 4164
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1911
try:
    LC_PROP_LTELEM_Y = 4165
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1914
try:
    LC_PROP_TSTYLE_ID = 4001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1915
try:
    LC_PROP_TSTYLE_NAME = 4002
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1916
try:
    LC_PROP_TSTYLE_DESC = 4003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1917
try:
    LC_PROP_TSTYLE_DESCR = 4003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1918
try:
    LC_PROP_TSTYLE_DRW = 4004
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1919
try:
    LC_PROP_TSTYLE_DELETED = 4005
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1920
try:
    LC_PROP_TSTYLE_FONT = 4175
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1921
try:
    LC_PROP_TSTYLE_HFONT = 4176
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1922
try:
    LC_PROP_TSTYLE_HEIGHT = 4177
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1923
try:
    LC_PROP_TSTYLE_WSCALE = 4178
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1924
try:
    LC_PROP_TSTYLE_OBLIQUE = 4179
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1925
try:
    LC_PROP_TSTYLE_ANGLE = 4180
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1926
try:
    LC_PROP_TSTYLE_ALIGN = 4181
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1927
try:
    LC_PROP_TSTYLE_UPDOWN = 4182
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1928
try:
    LC_PROP_TSTYLE_BACKWARD = 4183
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1929
try:
    LC_PROP_TSTYLE_LINESPACE = 4184
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1930
try:
    LC_PROP_TSTYLE_CHARSPACE = 4185
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1931
try:
    LC_PROP_TSTYLE_STANDARD = 4186
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1932
try:
    LC_PROP_TSTYLE_SHAPES = 4187
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1933
try:
    LC_PROP_TSTYLE_WINFONT = 4188
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1935
try:
    LC_PROP_TSTYLE_SOLID = 4189
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1936
try:
    LC_PROP_TSTYLE_CLOSED = 4190
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1937
try:
    LC_PROP_TSTYLE_HOLLOW = 4191
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1938
try:
    LC_PROP_TSTYLE_BOLD = 4192
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1939
try:
    LC_PROP_TSTYLE_ITALIC = 4193
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1941
try:
    LC_PROP_TSTYLE_UNDERLINE = 4194
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1943
try:
    LC_PROP_TSTYLE_STRIKEOUT = 4195
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1945
try:
    LC_PROP_TSTYLE_MONOWIDTH = 4196
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1949
try:
    LC_PROP_DIMST_ID = 4001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1950
try:
    LC_PROP_DIMST_NAME = 4002
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1951
try:
    LC_PROP_DIMST_DESC = 4003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1952
try:
    LC_PROP_DIMST_DESCR = 4003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1953
try:
    LC_PROP_DIMST_DRW = 4004
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1954
try:
    LC_PROP_DIMST_DELETED = 4005
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1955
try:
    LC_PROP_DIMST_STANDARD = 4205
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1956
try:
    LC_PROP_DIMST_ADEC = 4211
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1958
try:
    LC_PROP_DIMST_ASZ = 4212
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1960
try:
    LC_PROP_DIMST_AUNIT = 4213
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1962
try:
    LC_PROP_DIMST_AZIN = 4214
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1964
try:
    LC_PROP_DIMST_BLK1 = 4215
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1965
try:
    LC_PROP_DIMST_BLK2 = 4216
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1966
try:
    LC_PROP_DIMST_CEN = 4217
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1969
try:
    LC_PROP_DIMST_CLRD = 4218
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1972
try:
    LC_PROP_DIMST_CLRE = 4219
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1974
try:
    LC_PROP_DIMST_CLRT = 4220
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1975
try:
    LC_PROP_DIMST_DEC = 4221
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1978
try:
    LC_PROP_DIMST_DSEP = 4222
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1981
try:
    LC_PROP_DIMST_EXE = 4223
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1983
try:
    LC_PROP_DIMST_EXO = 4224
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1985
try:
    LC_PROP_DIMST_GAP = 4225
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1988
try:
    LC_PROP_DIMST_LDRBLK = 4226
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1989
try:
    LC_PROP_DIMST_LFAC = 4227
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1991
try:
    LC_PROP_DIMST_LWD = 4228
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1992
try:
    LC_PROP_DIMST_LWE = 4229
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1993
try:
    LC_PROP_DIMST_POST = 4230
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1995
try:
    LC_PROP_DIMST_RND = 4231
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 1997
try:
    LC_PROP_DIMST_SCALE = 4232
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2000
try:
    LC_PROP_DIMST_TAD = 4233
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2003
try:
    LC_PROP_DIMST_TIH = 4234
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2006
try:
    LC_PROP_DIMST_TXT = 4235
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2009
try:
    LC_PROP_DIMST_TXSTY = 4236
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2010
try:
    LC_PROP_DIMST_TSTYLE = 4236
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2011
try:
    LC_PROP_DIMST_LUNIT = 4237
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2013
try:
    LC_PROP_DIMST_ZIN = 4238
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2017
try:
    LC_PROP_PSTYLE_ID = 4001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2018
try:
    LC_PROP_PSTYLE_NAME = 4002
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2019
try:
    LC_PROP_PSTYLE_DESC = 4003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2020
try:
    LC_PROP_PSTYLE_DESCR = 4003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2021
try:
    LC_PROP_PSTYLE_DRW = 4004
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2022
try:
    LC_PROP_PSTYLE_DELETED = 4005
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2023
try:
    LC_PROP_PSTYLE_STANDARD = 4265
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2024
try:
    LC_PROP_PSTYLE_BLOCK = 4266
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2025
try:
    LC_PROP_PSTYLE_BSCALE = 4267
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2026
try:
    LC_PROP_PSTYLE_TSTYLE = 4268
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2027
try:
    LC_PROP_PSTYLE_TH = 4269
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2028
try:
    LC_PROP_PSTYLE_TWS = 4270
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2029
try:
    LC_PROP_PSTYLE_PTMODE = 4271
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2030
try:
    LC_PROP_PSTYLE_PTSIZE = 4272
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2031
try:
    LC_PROP_PSTYLE_SNAP = 4273
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2032
try:
    LC_PROP_PSTYLE_FIXED = 4274
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2035
try:
    LC_PROP_MLSTYLE_ID = 4001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2036
try:
    LC_PROP_MLSTYLE_NAME = 4002
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2037
try:
    LC_PROP_MLSTYLE_DESC = 4003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2038
try:
    LC_PROP_MLSTYLE_DESCR = 4003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2039
try:
    LC_PROP_MLSTYLE_DRW = 4004
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2040
try:
    LC_PROP_MLSTYLE_DELETED = 4005
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2041
try:
    LC_PROP_MLSTYLE_STANDARD = 4281
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2042
try:
    LC_PROP_MLSTYLE_JOINTS = 4282
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2043
try:
    LC_PROP_MLSTYLE_STARTLINE = 4283
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2044
try:
    LC_PROP_MLSTYLE_STARTARC = 4284
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2045
try:
    LC_PROP_MLSTYLE_ENDLINE = 4285
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2046
try:
    LC_PROP_MLSTYLE_ENDARC = 4286
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2047
try:
    LC_PROP_MLSTYLE_NLINES = 4287
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2048
try:
    LC_PROP_MLSTYLE_ILINE = 4288
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2049
try:
    LC_PROP_MLSTYLE_OFFSET = 4289
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2050
try:
    LC_PROP_MLSTYLE_LTYPE = 4290
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2051
try:
    LC_PROP_MLSTYLE_COLOR = 4291
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2054
try:
    LC_PROP_IMAGE_ID = 4001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2055
try:
    LC_PROP_IMAGE_NAME = 4002
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2056
try:
    LC_PROP_IMAGE_DESC = 4003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2057
try:
    LC_PROP_IMAGE_DESCR = 4003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2058
try:
    LC_PROP_IMAGE_DRW = 4004
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2059
try:
    LC_PROP_IMAGE_DELETED = 4005
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2060
try:
    LC_PROP_IMAGE_FILENAME = 4401
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2061
try:
    LC_PROP_IMAGE_SIZE = 4402
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2062
try:
    LC_PROP_IMAGE_WPIX = 4403
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2063
try:
    LC_PROP_IMAGE_W = 4404
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2064
try:
    LC_PROP_IMAGE_HPIX = 4405
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2065
try:
    LC_PROP_IMAGE_H = 4406
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2066
try:
    LC_PROP_IMAGE_CBIT = 4407
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2067
try:
    LC_PROP_IMAGE_RGB = 4408
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2068
try:
    LC_PROP_IMAGE_EMBEDDED = 4409
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2069
try:
    LC_PROP_IMAGE_CREATED = 4410
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2070
try:
    LC_PROP_IMAGE_COLORS = 4411
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2071
try:
    LC_PROP_IMAGE_BITS = 4412
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2072
try:
    LC_PROP_IMAGE_DIB = 4413
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2075
try:
    LC_PROP_LFILL_ID = 4001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2076
try:
    LC_PROP_LFILL_NAME = 4002
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2077
try:
    LC_PROP_LFILL_DESC = 4003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2078
try:
    LC_PROP_LFILL_DESCR = 4003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2079
try:
    LC_PROP_LFILL_DRW = 4004
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2080
try:
    LC_PROP_LFILL_DELETED = 4005
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2081
try:
    LC_PROP_LFILL_ENABLED0 = 4501
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2082
try:
    LC_PROP_LFILL_DIST0 = 4502
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2083
try:
    LC_PROP_LFILL_ANGLE0 = 4503
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2084
try:
    LC_PROP_LFILL_GAP0 = 4504
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2085
try:
    LC_PROP_LFILL_ENABLED1 = 4505
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2086
try:
    LC_PROP_LFILL_DIST1 = 4506
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2087
try:
    LC_PROP_LFILL_ANGLE1 = 4507
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2088
try:
    LC_PROP_LFILL_GAP1 = 4508
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2093
try:
    LC_PROP_BLOCK_ID = 4001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2094
try:
    LC_PROP_BLOCK_NAME = 4002
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2095
try:
    LC_PROP_BLOCK_DESC = 4003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2096
try:
    LC_PROP_BLOCK_DESCR = 4003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2097
try:
    LC_PROP_BLOCK_DRW = 4004
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2098
try:
    LC_PROP_BLOCK_DELETED = 4005
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2099
try:
    LC_PROP_BLOCK_X = 4801
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2100
try:
    LC_PROP_BLOCK_Y = 4802
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2101
try:
    LC_PROP_BLOCK_UFSCALING = 4803
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2102
try:
    LC_PROP_BLOCK_UNITS = 4804
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2103
try:
    LC_PROP_BLOCK_UNITSCALE = 4810
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2104
try:
    LC_PROP_BLOCK_MODEL = 4811
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2105
try:
    LC_PROP_BLOCK_PAPER = 4812
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2106
try:
    LC_PROP_BLOCK_LAYOUT = 4813
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2107
try:
    LC_PROP_BLOCK_STANDARD = 4814
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2108
try:
    LC_PROP_BLOCK_LAYOUTNAME = 4815
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2109
try:
    LC_PROP_BLOCK_LAYOUTORDER = 4816
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2111
try:
    LC_PROP_BLOCK_HIDDEN = 4818
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2112
try:
    LC_PROP_BLOCK_DIM = 4819
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2113
try:
    LC_PROP_BLOCK_HATCH = 4820
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2114
try:
    LC_PROP_BLOCK_NOBJ = 4821
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2116
try:
    LC_PROP_BLOCK_NENTS = 4821
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2118
try:
    LC_PROP_BLOCK_NSELOBJ = 4822
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2119
try:
    LC_PROP_BLOCK_NSELENTS = 4822
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2120
try:
    LC_PROP_BLOCK_ATTRIBS = 4827
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2122
try:
    LC_PROP_BLOCK_ODA_LAYOUTHANDLE = 4829
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2124
try:
    LC_PROP_BLOCK_ODA_VPORTHANDLE = 4830
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2129
try:
    LC_PROP_BLOCK_XMIN = 4831
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2130
try:
    LC_PROP_BLOCK_YMIN = 4832
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2131
try:
    LC_PROP_BLOCK_XMAX = 4833
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2132
try:
    LC_PROP_BLOCK_YMAX = 4834
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2133
try:
    LC_PROP_BLOCK_XCEN = 4835
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2134
try:
    LC_PROP_BLOCK_YCEN = 4836
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2135
try:
    LC_PROP_BLOCK_DX = 4837
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2136
try:
    LC_PROP_BLOCK_DY = 4838
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2137
try:
    LC_PROP_BLOCK_VISLEF = 4839
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2138
try:
    LC_PROP_BLOCK_VISBOT = 4840
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2139
try:
    LC_PROP_BLOCK_VISRIG = 4841
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2140
try:
    LC_PROP_BLOCK_VISTOP = 4842
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2141
try:
    LC_PROP_BLOCK_SELXMIN = 4843
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2142
try:
    LC_PROP_BLOCK_SELYMIN = 4844
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2143
try:
    LC_PROP_BLOCK_SELXMAX = 4845
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2144
try:
    LC_PROP_BLOCK_SELYMAX = 4846
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2145
try:
    LC_PROP_BLOCK_SELXCEN = 4847
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2146
try:
    LC_PROP_BLOCK_SELYCEN = 4848
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2147
try:
    LC_PROP_SHAPE_ANGLE = 4849
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2148
try:
    LC_PROP_PAPER__MIN = 4851
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2149
try:
    LC_PROP_PAPER_INCH = 4851
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2151
try:
    LC_PROP_PAPER_X0 = 4852
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2153
try:
    LC_PROP_PAPER_Y0 = 4853
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2155
try:
    LC_PROP_PAPER_SIZE = 4854
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2156
try:
    LC_PROP_PAPER_ORIENT = 4855
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2158
try:
    LC_PROP_PAPER_W = 4856
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2159
try:
    LC_PROP_PAPER_H = 4857
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2161
try:
    LC_PROP_TABLE__MAX = 4999
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2164
try:
    LC_PROP_ENT__MIN = 5001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2165
try:
    LC_PROP_ENT_TYPE = 5030
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2166
try:
    LC_PROP_ENT_ID = 5001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2167
try:
    LC_PROP_ENT_KEY = 5002
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2168
try:
    LC_PROP_ENT_BLOCK = 5024
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2170
try:
    LC_PROP_ENT_DRW = 5025
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2171
try:
    LC_PROP_ENT_LAYER = 5020
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2173
try:
    LC_PROP_ENT_LINETYPE = 5021
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2175
try:
    LC_PROP_ENT_LTSCALE = 5022
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2176
try:
    LC_PROP_ENT_LWEIGHT = 5023
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2177
try:
    LC_PROP_ENT_LWIDTH = 5023
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2178
try:
    LC_PROP_ENT_PRIORITY = 5040
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2179
try:
    LC_PROP_ENT_FROMCB = 5035
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2182
try:
    LC_PROP_ENT_COLOR = 5003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2183
try:
    LC_PROP_ENT_COLORI = 5004
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2184
try:
    LC_PROP_ENT_COLORT = 5005
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2185
try:
    LC_PROP_ENT_COLORBYLAYER = 5006
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2186
try:
    LC_PROP_ENT_COLORBYBLOCK = 5007
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2188
try:
    LC_PROP_ENT_SOLIDFILL = 5008
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2189
try:
    LC_PROP_ENT_FILLED = 5008
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2190
try:
    LC_PROP_ENT_FILLING = 5008
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2191
try:
    LC_PROP_ENT_WIPEOUT = 5011
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2192
try:
    LC_PROP_ENT_FCOLOR = 5012
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2193
try:
    LC_PROP_ENT_FCOLORI = 5013
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2194
try:
    LC_PROP_ENT_FCOLORT = 5014
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2195
try:
    LC_PROP_ENT_FCOLORBYLAYER = 5015
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2196
try:
    LC_PROP_ENT_FCOLORBYBLOCK = 5016
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2197
try:
    LC_PROP_ENT_FALPHA = 5017
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2198
try:
    LC_PROP_ENT_LINFILL = 5018
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2200
try:
    LC_PROP_ENT_LINFILLNL = 5019
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2202
try:
    LC_PROP_ENT_LOCKED = 5026
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2203
try:
    LC_PROP_ENT_VISIBLE = 5027
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2204
try:
    LC_PROP_ENT_HIDDEN = 5028
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2205
try:
    LC_PROP_ENT_BLINK = 5029
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2206
try:
    LC_PROP_ENT_DELETED = 5031
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2207
try:
    LC_PROP_ENT_IMMORTAL = 5032
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2208
try:
    LC_PROP_ENT_SELECTED = 5033
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2209
try:
    LC_PROP_ENT_GRIPMODE = 5034
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2211
try:
    LC_PROP_ENT_XMIN = 5052
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2212
try:
    LC_PROP_ENT_YMIN = 5053
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2213
try:
    LC_PROP_ENT_XMAX = 5054
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2214
try:
    LC_PROP_ENT_YMAX = 5055
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2215
try:
    LC_PROP_ENT_XCEN = 5056
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2216
try:
    LC_PROP_ENT_YCEN = 5057
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2217
try:
    LC_PROP_ENT_DX = 5058
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2218
try:
    LC_PROP_ENT_DY = 5059
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2219
try:
    LC_PROP_ENT_LEN = 5060
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2221
try:
    LC_PROP_ENT_Z = 5061
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2222
try:
    LC_PROP_ENT_THICKNESS = 5062
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2225
try:
    LC_PROP_ENT_XDATAID = 5041
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2226
try:
    LC_PROP_ENT_XDATAFLAGS = 5042
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2227
try:
    LC_PROP_ENT_XDATASIZE = 5043
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2228
try:
    LC_PROP_ENT_XDATA = 5044
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2229
try:
    LC_PROP_ENT_XSTR = 5045
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2230
try:
    LC_PROP_ENTBASE__MAX = 5100
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2233
try:
    LC_PROP_POINT_STYLE = 5101
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2235
try:
    LC_PROP_POINT_X = 5102
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2236
try:
    LC_PROP_POINT_Y = 5103
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2237
try:
    LC_PROP_POINT_Z = 5061
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2238
try:
    LC_PROP_POINT_SIZE = 5104
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2239
try:
    LC_PROP_POINT_MODE = 5105
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2240
try:
    LC_PROP_POINT_BANGLE = 5106
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2241
try:
    LC_PROP_POINT_TDX = 5107
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2242
try:
    LC_PROP_POINT_TDY = 5108
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2243
try:
    LC_PROP_POINT_TANGLE = 5109
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2244
try:
    LC_PROP_POINT_TEXT = 5110
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2245
try:
    LC_PROP_POINT_TEXTLEN = 5111
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2249
try:
    LC_PROP_PTARR_FILENAME = 5112
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2250
try:
    LC_PROP_PTARR_FNAME = 5113
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2251
try:
    LC_PROP_PTARR_DIR = 5114
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2252
try:
    LC_PROP_PTARR_LOADED = 5115
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2253
try:
    LC_PROP_PTARR_NUM = 5116
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2254
try:
    LC_PROP_PTARR_NUMVIS = 5117
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2255
try:
    LC_PROP_PTARR_TEXTVLIM = 5118
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2256
try:
    LC_PROP_PTARR_VLIM10 = 5119
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2257
try:
    LC_PROP_PTARR_VLIM100 = 5120
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2260
try:
    LC_PROP_LINE_X0 = 5131
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2261
try:
    LC_PROP_LINE_Y0 = 5132
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2262
try:
    LC_PROP_LINE_Z0 = 5133
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2263
try:
    LC_PROP_LINE_X1 = 5134
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2264
try:
    LC_PROP_LINE_Y1 = 5135
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2265
try:
    LC_PROP_LINE_Z1 = 5136
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2266
try:
    LC_PROP_LINE_DX = 5137
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2267
try:
    LC_PROP_LINE_DY = 5138
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2268
try:
    LC_PROP_LINE_DZ = 5139
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2269
try:
    LC_PROP_LINE_ANG = 5140
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2270
try:
    LC_PROP_LINE_LEN = 5141
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2271
try:
    LC_PROP_LINE_DSARROW0 = 5142
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2272
try:
    LC_PROP_LINE_DSARROW1 = 5143
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2273
try:
    LC_PROP_LINE_W0 = 5144
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2274
try:
    LC_PROP_LINE_W1 = 5145
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2275
try:
    LC_PROP_LINE_SOLID = 5146
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2278
try:
    LC_PROP_XLINE_X0 = 5151
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2279
try:
    LC_PROP_XLINE_Y0 = 5152
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2280
try:
    LC_PROP_XLINE_ANG = 5154
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2281
try:
    LC_PROP_XLINE_DIRX = 5155
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2282
try:
    LC_PROP_XLINE_DIRY = 5156
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2283
try:
    LC_PROP_XLINE_RAY = 5157
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2286
try:
    LC_PROP_CIRCLE_X = 5201
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2287
try:
    LC_PROP_CIRCLE_Y = 5202
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2288
try:
    LC_PROP_CIRCLE_R = 5204
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2289
try:
    LC_PROP_CIRCLE_RAD = 5204
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2290
try:
    LC_PROP_CIRCLE_RADIUS = 5204
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2291
try:
    LC_PROP_CIRCLE_DIAM = 5205
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2292
try:
    LC_PROP_CIRCLE_LEN = 5206
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2293
try:
    LC_PROP_CIRCLE_AREA = 5207
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2294
try:
    LC_PROP_CIRCLE_ANG0 = 5208
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2295
try:
    LC_PROP_CIRCLE_DIRCW = 5209
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2296
try:
    LC_PROP_CIRCLE_RESOL = 5210
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2297
try:
    LC_PROP_CIRC_X = 5201
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2298
try:
    LC_PROP_CIRC_Y = 5202
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2299
try:
    LC_PROP_CIRC_R = 5204
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2300
try:
    LC_PROP_CIRC_RAD = 5204
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2301
try:
    LC_PROP_CIRC_RADIUS = 5204
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2302
try:
    LC_PROP_CIRC_DIAM = 5205
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2303
try:
    LC_PROP_CIRC_LEN = 5206
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2304
try:
    LC_PROP_CIRC_AREA = 5207
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2305
try:
    LC_PROP_CIRC_ANG0 = 5208
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2306
try:
    LC_PROP_CIRC_DIRCW = 5209
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2307
try:
    LC_PROP_CIRC_RESOL = 5210
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2310
try:
    LC_PROP_ARC_X = 5231
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2311
try:
    LC_PROP_ARC_Y = 5232
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2312
try:
    LC_PROP_ARC_R = 5234
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2313
try:
    LC_PROP_ARC_RAD = 5234
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2314
try:
    LC_PROP_ARC_RADIUS = 5234
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2315
try:
    LC_PROP_ARC_ANG0 = 5235
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2316
try:
    LC_PROP_ARC_ANGARC = 5236
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2317
try:
    LC_PROP_ARC_ANGEND = 5237
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2318
try:
    LC_PROP_ARC_X0 = 5238
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2319
try:
    LC_PROP_ARC_Y0 = 5239
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2320
try:
    LC_PROP_ARC_Z0 = 5240
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2321
try:
    LC_PROP_ARC_XMID = 5241
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2322
try:
    LC_PROP_ARC_YMID = 5242
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2323
try:
    LC_PROP_ARC_XEND = 5243
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2324
try:
    LC_PROP_ARC_YEND = 5244
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2325
try:
    LC_PROP_ARC_ZEND = 5245
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2326
try:
    LC_PROP_ARC_LEN = 5246
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2327
try:
    LC_PROP_ARC_CHLEN = 5247
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2328
try:
    LC_PROP_ARC_AREA = 5248
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2329
try:
    LC_PROP_ARC_CCW = 5249
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2330
try:
    LC_PROP_ARC_SECTOR = 5250
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2331
try:
    LC_PROP_ARC_RESOL = 5251
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2334
try:
    LC_PROP_ELL_X = 5261
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2335
try:
    LC_PROP_ELL_Y = 5262
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2336
try:
    LC_PROP_ELL_R1 = 5264
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2337
try:
    LC_PROP_ELL_R2 = 5265
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2338
try:
    LC_PROP_ELL_RATIO = 5266
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2339
try:
    LC_PROP_ELL_ANGLE = 5267
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2340
try:
    LC_PROP_ELL_ANG0 = 5268
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2341
try:
    LC_PROP_ELL_ANGARC = 5269
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2343
try:
    LC_PROP_ELL_ANGEND = 5270
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2344
try:
    LC_PROP_ELL_X0 = 5271
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2345
try:
    LC_PROP_ELL_Y0 = 5272
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2346
try:
    LC_PROP_ELL_XEND = 5273
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2347
try:
    LC_PROP_ELL_YEND = 5274
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2348
try:
    LC_PROP_ELL_LEN = 5276
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2349
try:
    LC_PROP_ELL_AREA = 5277
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2350
try:
    LC_PROP_ELL_FULL = 5278
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2351
try:
    LC_PROP_ELL_CCW = 5279
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2352
try:
    LC_PROP_ELL_SECTOR = 5282
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2353
try:
    LC_PROP_ELL_RESOL = 5283
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2354
try:
    LC_PROP_ELL__MAX = 5299
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2357
try:
    LC_PROP_PLINE_FIT = 5301
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2358
try:
    LC_PROP_PLINE_CLOSED = 5302
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2359
try:
    LC_PROP_PLINE_NVERS = 5303
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2360
try:
    LC_PROP_PLINE_WIDTH = 5305
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2362
try:
    LC_PROP_PLINE_LEN = 5306
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2363
try:
    LC_PROP_PLINE_AREA = 5307
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2364
try:
    LC_PROP_PLINE_CW = 5308
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2365
try:
    LC_PROP_PLINE_CCW = 5309
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2366
try:
    LC_PROP_PLINE_Z = 5310
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2367
try:
    LC_PROP_PLINE_CONSTZ = 5311
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2368
try:
    LC_PROP_PLINE_RESOLA = 5312
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2369
try:
    LC_PROP_PLINE_RESOLS = 5313
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2370
try:
    LC_PROP_PLINE_RADIUS = 5314
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2373
try:
    LC_PROP_PLINE_CHAMFER = 5315
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2375
try:
    LC_PROP_PLINE_HASANG0 = 5316
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2376
try:
    LC_PROP_PLINE_ANG0 = 5317
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2377
try:
    LC_PROP_PLINE_HASANG2 = 5318
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2378
try:
    LC_PROP_PLINE_ANG2 = 5319
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2379
try:
    LC_PROP_PLINE_WIPEOUT = 5325
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2380
try:
    LC_PROP_PLINE_ODSOLID = 5326
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2384
try:
    LC_PROP_MLINE_STYLE = 5351
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2386
try:
    LC_PROP_MLINE_JUST = 5352
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2387
try:
    LC_PROP_MLINE_SCALE = 5353
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2388
try:
    LC_PROP_MLINE_NVERS = 5354
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2389
try:
    LC_PROP_MLINE_CLOSED = 5355
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2390
try:
    LC_PROP_MLINE_FIT = 5356
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2391
try:
    LC_PROP_MLINE_LEN = 5357
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2392
try:
    LC_PROP_MLINE_AREA = 5358
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2395
try:
    LC_PROP_RECT_X = 5371
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2396
try:
    LC_PROP_RECT_Y = 5372
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2397
try:
    LC_PROP_RECT_W = 5374
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2398
try:
    LC_PROP_RECT_H = 5375
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2399
try:
    LC_PROP_RECT_ANGLE = 5376
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2400
try:
    LC_PROP_RECT_R = 5377
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2401
try:
    LC_PROP_RECT_RAD = 5377
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2402
try:
    LC_PROP_RECT_RADIUS = 5377
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2403
try:
    LC_PROP_RECT_CHAMFER = 5378
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2404
try:
    LC_PROP_RECT_DIRCW = 5379
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2405
try:
    LC_PROP_RECT_START = 5380
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2406
try:
    LC_PROP_RECT_LEN = 5381
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2407
try:
    LC_PROP_RECT_AREA = 5382
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2408
try:
    LC_PROP_RECT_RESOL = 5383
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2409
try:
    LC_PROP_RECT_GRID = 5384
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2410
try:
    LC_PROP_RECT_GRNW = 5385
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2411
try:
    LC_PROP_RECT_GRNH = 5386
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2412
try:
    LC_PROP_RECT_GRDW = 5387
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2413
try:
    LC_PROP_RECT_GRDH = 5388
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2416
try:
    LC_PROP_CRECT_ID = 5390
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2417
try:
    LC_PROP_CRECT_NAME = 5391
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2418
try:
    LC_PROP_CRECT_X = 5392
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2419
try:
    LC_PROP_CRECT_Y = 5393
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2420
try:
    LC_PROP_CRECT_W = 5394
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2421
try:
    LC_PROP_CRECT_H = 5395
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2422
try:
    LC_PROP_CRECT_ANGLE = 5396
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2423
try:
    LC_PROP_CRECT_LEN = 5398
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2424
try:
    LC_PROP_CRECT_AREA = 5399
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2427
try:
    LC_PROP_TEXT_STYLE = 5401
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2429
try:
    LC_PROP_TEXT_STR = 5402
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2430
try:
    LC_PROP_TEXT_STRT = 5403
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2432
try:
    LC_PROP_TEXT_LEN = 5404
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2433
try:
    LC_PROP_TEXT_ALIGN = 5405
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2435
try:
    LC_PROP_TEXT_H = 5406
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2437
try:
    LC_PROP_TEXT_X = 5407
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2438
try:
    LC_PROP_TEXT_Y = 5408
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2439
try:
    LC_PROP_TEXT_DX = 5409
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2440
try:
    LC_PROP_TEXT_DY = 5410
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2441
try:
    LC_PROP_TEXT_WSCALE = 5412
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2442
try:
    LC_PROP_TEXT_ANGLE = 5413
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2443
try:
    LC_PROP_TEXT_OBLIQUE = 5414
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2444
try:
    LC_PROP_TEXT_CHARSPACE = 5415
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2445
try:
    LC_PROP_TEXT_WRECT = 5416
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2446
try:
    LC_PROP_TEXT_X0 = 5417
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2447
try:
    LC_PROP_TEXT_Y0 = 5418
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2448
try:
    LC_PROP_TEXT_XFIT = 5419
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2449
try:
    LC_PROP_TEXT_YFIT = 5420
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2450
try:
    LC_PROP_TEXT_UPDOWN = 5421
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2451
try:
    LC_PROP_TEXT_BACKWARD = 5422
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2452
try:
    LC_PROP_TEXT_RESOL = 5423
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2455
try:
    LC_PROP_TEXTW_STYLE = 5431
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2457
try:
    LC_PROP_TEXTW_STR = 5432
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2458
try:
    LC_PROP_TEXTW_STRT = 5433
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2460
try:
    LC_PROP_TEXTW_LEN = 5434
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2462
try:
    LC_PROP_TEXTW_ALIGN = 5435
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2463
try:
    LC_PROP_TEXTW_X = 5436
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2464
try:
    LC_PROP_TEXTW_Y = 5437
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2465
try:
    LC_PROP_TEXTW_H = 5438
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2466
try:
    LC_PROP_TEXTW_DX = 5440
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2468
try:
    LC_PROP_TEXTW_DY = 5441
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2470
try:
    LC_PROP_TEXTW_WSCALE = 5442
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2471
try:
    LC_PROP_TEXTW_ANGLE = 5443
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2474
try:
    LC_PROP_MTEXT__MIN = 5451
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2475
try:
    LC_PROP_MTEXT_STYLE = 5451
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2476
try:
    LC_PROP_MTEXT_STR = 5452
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2477
try:
    LC_PROP_MTEXT_LEN = 5453
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2478
try:
    LC_PROP_MTEXT_ALIGN = 5454
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2479
try:
    LC_PROP_MTEXT_X = 5455
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2480
try:
    LC_PROP_MTEXT_Y = 5456
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2481
try:
    LC_PROP_MTEXT_H = 5458
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2482
try:
    LC_PROP_MTEXT_WSCALE = 5459
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2483
try:
    LC_PROP_MTEXT_ANGLE = 5460
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2484
try:
    LC_PROP_MTEXT_OBLIQUE = 5461
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2485
try:
    LC_PROP_MTEXT_WRECT = 5462
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2486
try:
    LC_PROP_MTEXT_HRECT = 5463
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2487
try:
    LC_PROP_MTEXT_WRAPWIDTH = 5464
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2488
try:
    LC_PROP_MTEXT_LINESPACE = 5465
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2489
try:
    LC_PROP_MTEXT_CHARSPACE = 5466
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2490
try:
    LC_PROP_MTEXT_MIRROR = 5467
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2491
try:
    LC_PROP_MTEXT_RESOL = 5468
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2492
try:
    LC_PROP_MTEXT__MAX = 5470
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2495
try:
    LC_PROP_ATEXT__MIN = 5481
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2496
try:
    LC_PROP_ATEXT_STYLE = 5481
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2497
try:
    LC_PROP_ATEXT_STR = 5482
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2498
try:
    LC_PROP_ATEXT_STRT = 5483
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2500
try:
    LC_PROP_ATEXT_LEN = 5484
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2501
try:
    LC_PROP_ATEXT_X = 5485
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2502
try:
    LC_PROP_ATEXT_Y = 5486
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2503
try:
    LC_PROP_ATEXT_R = 5487
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2504
try:
    LC_PROP_ATEXT_RAD = 5487
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2505
try:
    LC_PROP_ATEXT_RADIUS = 5487
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2506
try:
    LC_PROP_ATEXT_ANGLE = 5488
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2507
try:
    LC_PROP_ATEXT_ANGSTA = 5489
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2508
try:
    LC_PROP_ATEXT_ANGEND = 5490
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2509
try:
    LC_PROP_ATEXT_CW = 5491
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2510
try:
    LC_PROP_ATEXT_H = 5492
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2511
try:
    LC_PROP_ATEXT_WSCALE = 5493
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2512
try:
    LC_PROP_ATEXT_CHARSPACE = 5494
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2513
try:
    LC_PROP_ATEXT_ALIGN = 5495
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2514
try:
    LC_PROP_ATEXT_RESOL = 5496
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2515
try:
    LC_PROP_ATEXT__MAX = 5499
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2518
try:
    LC_PROP_ATT_MODE = 5501
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2519
try:
    LC_PROP_ATT_TSTYLE = 5502
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2521
try:
    LC_PROP_ATT_TAG = 5503
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2522
try:
    LC_PROP_ATT_PROMPT = 5504
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2523
try:
    LC_PROP_ATT_VALUE = 5505
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2524
try:
    LC_PROP_ATT_ALIGN = 5506
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2525
try:
    LC_PROP_ATT_X = 5507
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2526
try:
    LC_PROP_ATT_Y = 5508
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2527
try:
    LC_PROP_ATT_H = 5510
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2528
try:
    LC_PROP_ATT_WSCALE = 5511
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2529
try:
    LC_PROP_ATT_ANGLE = 5512
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2530
try:
    LC_PROP_ATT_OBLIQUE = 5513
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2531
try:
    LC_PROP_ATT_X0 = 5514
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2532
try:
    LC_PROP_ATT_Y0 = 5515
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2533
try:
    LC_PROP_ATT_XFIT = 5516
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2534
try:
    LC_PROP_ATT_YFIT = 5517
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2535
try:
    LC_PROP_ATT_UPDOWN = 5518
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2536
try:
    LC_PROP_ATT_BACKWARD = 5519
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2537
try:
    LC_PROP_ATT_COLOR = 5521
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2538
try:
    LC_PROP_ATT_LAYER = 5522
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2539
try:
    LC_PROP_ATT_LINETYPE = 5523
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2540
try:
    LC_PROP_ATT_LTSCALE = 5524
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2541
try:
    LC_PROP_ATT_LWIDTH = 5525
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2542
try:
    LC_PROP_ATT_INVIS = 5526
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2543
try:
    LC_PROP_ATT_LOCKPOS = 5527
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2544
try:
    LC_PROP_ATT_MTEXT = 5528
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2547
try:
    LC_PROP_BLKREF_BLOCK = 5531
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2549
try:
    LC_PROP_BLKREF_X = 5532
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2550
try:
    LC_PROP_BLKREF_Y = 5533
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2551
try:
    LC_PROP_BLKREF_SCALE = 5534
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2552
try:
    LC_PROP_BLKREF_SCX = 5535
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2553
try:
    LC_PROP_BLKREF_SCY = 5536
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2554
try:
    LC_PROP_BLKREF_UFSCALE = 5537
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2555
try:
    LC_PROP_BLKREF_ANGLE = 5538
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2556
try:
    LC_PROP_BLKREF_ARNX = 5539
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2557
try:
    LC_PROP_BLKREF_ARDX = 5540
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2558
try:
    LC_PROP_BLKREF_ARNY = 5541
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2559
try:
    LC_PROP_BLKREF_ARDY = 5542
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2560
try:
    LC_PROP_BLKREF_ARANG = 5543
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2561
try:
    LC_PROP_BLKREF_ATTRIBS = 5544
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2562
try:
    LC_PROP_BLKREF_GRIPMODE = 5545
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2564
try:
    LC_PROP_BLKREF_ONS_XY = 5546
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2565
try:
    LC_PROP_BLKREF_ONS_SCALE = 5547
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2566
try:
    LC_PROP_BLKREF_ONS_ANGLE = 5548
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2568
try:
    LC_PROP_BLKREF_RETURN = 5549
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2572
try:
    LC_PROP_IMGREF_IMAGE = 5551
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2574
try:
    LC_PROP_IMGREF_XC = 5552
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2575
try:
    LC_PROP_IMGREF_YC = 5553
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2576
try:
    LC_PROP_IMGREF_W = 5554
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2577
try:
    LC_PROP_IMGREF_H = 5555
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2578
try:
    LC_PROP_IMGREF_WPIX = 5556
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2579
try:
    LC_PROP_IMGREF_HPIX = 5557
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2580
try:
    LC_PROP_IMGREF_SCALE = 5558
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2581
try:
    LC_PROP_IMGREF_PIXELSIZE = 5558
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2582
try:
    LC_PROP_IMGREF_SCALEX = 5560
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2583
try:
    LC_PROP_IMGREF_SCALEY = 5561
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2584
try:
    LC_PROP_IMGREF_SQPIX = 5562
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2585
try:
    LC_PROP_IMGREF_ANGLE = 5564
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2587
try:
    LC_PROP_IMGREF_BORDER = 5565
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2588
try:
    LC_PROP_IMGREF_TRANSP = 5566
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2590
try:
    LC_PROP_IMGREF_TRCOLOR = 5567
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2591
try:
    LC_PROP_IMGREF_TRALPHA = 5568
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2592
try:
    LC_PROP_IMGREF_GRAYS = 5569
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2593
try:
    LC_PROP_IMGREF_GREY = 5569
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2594
try:
    LC_PROP_IMGREF_FLIPHOR = 5570
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2595
try:
    LC_PROP_IMGREF_FLIPVER = 5571
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2596
try:
    LC_PROP_IMGREF_PATH = 5573
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2597
try:
    LC_PROP_IMGREF_GP_X = 5574
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2598
try:
    LC_PROP_IMGREF_GP_Y = 5575
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2599
try:
    LC_PROP_IMGREF_GP_COLOR = 5576
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2600
try:
    LC_PROP_IMGREF_GP_GRAY = 5577
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2601
try:
    LC_PROP_IMGREF_UNSCALABLE = 5578
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2602
try:
    LC_PROP_IMGREF_UNSSCALE = 5579
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2603
try:
    LC_PROP_IMGREF_UNSALIGN = 5580
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2608
try:
    LC_PROP_ECW_FILENAME = 5581
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2609
try:
    LC_PROP_ECW_LOADED = 5582
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2610
try:
    LC_PROP_ECW_WPIX = 5583
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2611
try:
    LC_PROP_ECW_HPIX = 5584
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2612
try:
    LC_PROP_ECW_CBIT = 5585
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2613
try:
    LC_PROP_ECW_XMIN = 5586
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2614
try:
    LC_PROP_ECW_YMIN = 5587
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2615
try:
    LC_PROP_ECW_XMAX = 5588
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2616
try:
    LC_PROP_ECW_YMAX = 5589
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2617
try:
    LC_PROP_ECW_W = 5590
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2618
try:
    LC_PROP_ECW_H = 5591
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2619
try:
    LC_PROP_ECW_SCALEX = 5592
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2620
try:
    LC_PROP_ECW_SCALEY = 5593
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2621
try:
    LC_PROP_ECW_BORDER = 5594
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2622
try:
    LC_PROP_ECW_GRAYS = 5595
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2623
try:
    LC_PROP_ECW_BRIGHT = 5596
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2626
try:
    LC_PROP_BRI_FILENAME = 5601
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2627
try:
    LC_PROP_BRI_LOADED = 5602
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2628
try:
    LC_PROP_BRI_WPIX = 5603
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2629
try:
    LC_PROP_BRI_HPIX = 5604
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2630
try:
    LC_PROP_BRI_XMIN = 5605
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2631
try:
    LC_PROP_BRI_YMIN = 5606
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2632
try:
    LC_PROP_BRI_XMAX = 5607
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2633
try:
    LC_PROP_BRI_YMAX = 5608
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2634
try:
    LC_PROP_BRI_W = 5609
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2635
try:
    LC_PROP_BRI_H = 5610
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2636
try:
    LC_PROP_BRI_PIXSIZE = 5611
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2637
try:
    LC_PROP_BRI_BORDER = 5612
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2640
try:
    LC_PROP_CAMERA_X = 5621
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2641
try:
    LC_PROP_CAMERA_Y = 5622
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2642
try:
    LC_PROP_CAMERA_W = 5623
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2643
try:
    LC_PROP_CAMERA_H = 5624
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2646
try:
    LC_PROP_HATCH_NAME = 5631
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2647
try:
    LC_PROP_HATCH_PATTERN = 5632
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2648
try:
    LC_PROP_HATCH_SCALE = 5633
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2649
try:
    LC_PROP_HATCH_ANGLE = 5634
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2650
try:
    LC_PROP_HATCH_SIZE = 5635
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2651
try:
    LC_PROP_HATCH_ASSOC = 5636
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2652
try:
    LC_PROP_HATCH_SOLID = 5637
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2653
try:
    LC_PROP_HATCH_CUSTOM = 5638
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2654
try:
    LC_PROP_HATCH_NENTS = 5639
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2656
try:
    LC_PROP_HATCH_NPT = 5640
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2657
try:
    LC_PROP_HATCH_NLOOP = 5641
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2658
try:
    LC_PROP_HATCH_NHPL = 5642
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2659
try:
    LC_PROP_HATCH_IHPL = 5643
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2660
try:
    LC_PROP_HATCH_FALPHA = 5644
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2662
try:
    LC_PROP_HATCH_AREA = 5645
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2663
try:
    LC_PROP_HATCH_NDASHES = 5646
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2664
try:
    LC_PROP_HPL_ANGLE = 5651
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2665
try:
    LC_PROP_HPL_X0 = 5652
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2666
try:
    LC_PROP_HPL_Y0 = 5653
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2667
try:
    LC_PROP_HPL_DX = 5654
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2668
try:
    LC_PROP_HPL_DY = 5655
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2669
try:
    LC_PROP_HPL_NDASH = 5656
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2670
try:
    LC_PROP_HPL_DASH1 = 5657
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2671
try:
    LC_PROP_HPL_DASH2 = 5658
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2672
try:
    LC_PROP_HPL_DASH3 = 5659
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2673
try:
    LC_PROP_HPL_DASH4 = 5660
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2674
try:
    LC_PROP_HPL_DASH5 = 5661
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2675
try:
    LC_PROP_HPL_DASH6 = 5662
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2676
try:
    LC_PROP_HPL_DASH7 = 5663
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2677
try:
    LC_PROP_HPL_DASH8 = 5664
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2680
try:
    LC_PROP_VPORT_LEF = 5703
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2681
try:
    LC_PROP_VPORT_BOT = 5704
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2682
try:
    LC_PROP_VPORT_RIG = 5705
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2683
try:
    LC_PROP_VPORT_TOP = 5706
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2684
try:
    LC_PROP_VPORT_BORDER = 5707
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2685
try:
    LC_PROP_VPORT_W = 5711
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2686
try:
    LC_PROP_VPORT_H = 5712
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2687
try:
    LC_PROP_VPORT_VX = 5713
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2688
try:
    LC_PROP_VPORT_VY = 5714
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2689
try:
    LC_PROP_VPORT_VSCALE = 5715
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2690
try:
    LC_PROP_VPORT_VANGLE = 5716
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2691
try:
    LC_PROP_VPORT_FIXSCALE = 5717
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2694
try:
    LC_PROP_BARC_XC = 5751
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2695
try:
    LC_PROP_BARC_X = 5751
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2696
try:
    LC_PROP_BARC_YC = 5752
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2697
try:
    LC_PROP_BARC_Y = 5752
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2698
try:
    LC_PROP_BARC_W = 5753
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2699
try:
    LC_PROP_BARC_H = 5754
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2700
try:
    LC_PROP_BARC_ANG = 5755
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2701
try:
    LC_PROP_BARC_TYPE = 5756
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2703
try:
    LC_PROP_BARC_CODE = 5757
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2704
try:
    LC_PROP_BARC_TEXT = 5757
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2705
try:
    LC_PROP_BARC_CHECKSUM = 5758
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2706
try:
    LC_PROP_BARC_NCHARS = 5759
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2707
try:
    LC_PROP_BARC_NUBITS = 5760
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2708
try:
    LC_PROP_BARC_NARSIZE = 5761
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2709
try:
    LC_PROP_BARC_WIDERATIO = 5762
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2710
try:
    LC_PROP_BARC_QZONE = 5763
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2711
try:
    LC_PROP_BARC_OFFSET = 5764
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2712
try:
    LC_PROP_BARC_INVERT = 5765
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2713
try:
    LC_PROP_BARC_HIDETEXT = 5766
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2714
try:
    LC_PROP_BARC_TSTYLE = 5767
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2716
try:
    LC_PROP_BARC_TEXTH = 5768
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2717
try:
    LC_PROP_BARC_TEXTW = 5769
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2718
try:
    LC_PROP_BARC_TEXTCS = 5770
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2719
try:
    LC_PROP_BARC_TEXTALIGN = 5771
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2720
try:
    LC_PROP_BARC_TEXTRES = 5772
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2722
try:
    LC_PROP_BARC_ECLEVEL = 5773
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2723
try:
    LC_PROP_BARC_MASKPAT = 5774
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2724
try:
    LC_PROP_BARC_DATATYPE = 5775
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2725
try:
    LC_PROP_BARC_SIZE = 5776
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2726
try:
    LC_PROP_BARC_NBARS = 5777
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2728
try:
    LC_PROP_BARC_NMODX = 5777
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2729
try:
    LC_PROP_BARC_NMODY = 5778
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2732
try:
    LC_PROP_ARR_X0 = 5801
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2733
try:
    LC_PROP_ARR_Y0 = 5802
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2734
try:
    LC_PROP_ARR_X1 = 5803
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2735
try:
    LC_PROP_ARR_Y1 = 5804
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2736
try:
    LC_PROP_ARR_ANG = 5805
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2737
try:
    LC_PROP_ARR_LEN = 5806
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2738
try:
    LC_PROP_ARR_W = 5807
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2739
try:
    LC_PROP_ARR_SW = 5808
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2740
try:
    LC_PROP_ARR_SL = 5809
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2741
try:
    LC_PROP_ARR_TIME = 5810
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2742
try:
    LC_PROP_ARR_SHARP = 5811
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2745
try:
    LC_PROP_SPIR_X = 5821
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2746
try:
    LC_PROP_SPIR_Y = 5822
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2747
try:
    LC_PROP_SPIR_R = 5823
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2748
try:
    LC_PROP_SPIR_RADIUS = 5823
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2749
try:
    LC_PROP_SPIR_R2 = 5824
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2750
try:
    LC_PROP_SPIR_RATIO = 5825
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2751
try:
    LC_PROP_SPIR_ANGLE = 5826
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2752
try:
    LC_PROP_SPIR_TURNS = 5827
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2753
try:
    LC_PROP_SPIR_DIRCW = 5829
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2754
try:
    LC_PROP_SPIR_CLOSED = 5830
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2755
try:
    LC_PROP_SPIR_DSTEP = 5831
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2756
try:
    LC_PROP_SPIR_RESOL = 5832
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2759
try:
    LC_PROP_XREF_FILENAME = 5841
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2760
try:
    LC_PROP_XREF_FNAME = 5842
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2761
try:
    LC_PROP_XREF_PATH = 5843
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2762
try:
    LC_PROP_XREF_X = 5844
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2763
try:
    LC_PROP_XREF_Y = 5845
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2764
try:
    LC_PROP_XREF_SCX = 5846
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2765
try:
    LC_PROP_XREF_SCY = 5847
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2766
try:
    LC_PROP_XREF_ANGLE = 5848
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2769
try:
    LC_PROP_DIM_STYLE = 6001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2771
try:
    LC_PROP_DIM_MEAS = 6003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2772
try:
    LC_PROP_DIM_TEXT = 6004
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2774
try:
    LC_PROP_DIMANG_STYLE = 6001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2775
try:
    LC_PROP_DIMANG_MEAS = 6003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2776
try:
    LC_PROP_DIMANG_TEXT = 6004
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2778
try:
    LC_PROP_DIMALI_STYLE = 6001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2779
try:
    LC_PROP_DIMALI_MEAS = 6003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2780
try:
    LC_PROP_DIMALI_TEXT = 6004
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2782
try:
    LC_PROP_DIMDIA_STYLE = 6001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2783
try:
    LC_PROP_DIMDIA_MEAS = 6003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2784
try:
    LC_PROP_DIMDIA_TEXT = 6004
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2786
try:
    LC_PROP_DIMRAD_STYLE = 6001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2787
try:
    LC_PROP_DIMRAD_MEAS = 6003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2788
try:
    LC_PROP_DIMRAD_TEXT = 6004
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2790
try:
    LC_PROP_DIMORD_STYLE = 6001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2791
try:
    LC_PROP_DIMORD_MEAS = 6003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2792
try:
    LC_PROP_DIMORD_TEXT = 6004
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2794
try:
    LC_PROP_DIMROT_STYLE = 6001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2795
try:
    LC_PROP_DIMROT_MEAS = 6003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2796
try:
    LC_PROP_DIMROT_TEXT = 6004
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2797
try:
    LC_PROP_DIMLIN_STYLE = 6001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2798
try:
    LC_PROP_DIMLIN_MEAS = 6003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2799
try:
    LC_PROP_DIMLIN_TEXT = 6004
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2801
try:
    LC_PROP_DIMANG__MIN = 6011
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2802
try:
    LC_PROP_DIMANG_3PNT = 6011
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2803
try:
    LC_PROP_DIMANG_2LINE = 6012
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2804
try:
    LC_PROP_DIMANG_CPX = 6013
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2805
try:
    LC_PROP_DIMANG_CPY = 6014
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2806
try:
    LC_PROP_DIMANG_DP1X = 6015
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2807
try:
    LC_PROP_DIMANG_DP1Y = 6016
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2808
try:
    LC_PROP_DIMANG_DP2X = 6017
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2809
try:
    LC_PROP_DIMANG_DP2Y = 6018
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2810
try:
    LC_PROP_DIMANG_L1P1X = 6021
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2811
try:
    LC_PROP_DIMANG_L1P1Y = 6022
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2812
try:
    LC_PROP_DIMANG_L1P2X = 6023
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2813
try:
    LC_PROP_DIMANG_L1P2Y = 6024
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2814
try:
    LC_PROP_DIMANG_DP3X = 6023
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2815
try:
    LC_PROP_DIMANG_DP3Y = 6024
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2816
try:
    LC_PROP_DIMANG_L2P1X = 6025
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2817
try:
    LC_PROP_DIMANG_L2P1Y = 6026
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2818
try:
    LC_PROP_DIMANG_L2P2X = 6027
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2819
try:
    LC_PROP_DIMANG_L2P2Y = 6028
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2820
try:
    LC_PROP_DIMANG_DP4X = 6027
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2821
try:
    LC_PROP_DIMANG_DP4Y = 6028
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2822
try:
    LC_PROP_DIMANG_APX = 6029
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2823
try:
    LC_PROP_DIMANG_APY = 6030
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2824
try:
    LC_PROP_DIMANG_EXT1 = 6031
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2825
try:
    LC_PROP_DIMANG_EXT2 = 6032
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2826
try:
    LC_PROP_DIMANG_RAD = 6033
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2827
try:
    LC_PROP_DIMANG_TPOS = 6034
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2828
try:
    LC_PROP_DIMANG__MAX = 6050
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2830
try:
    LC_PROP_DIMALI__MIN = 6051
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2831
try:
    LC_PROP_DIMALI_DP1X = 6051
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2832
try:
    LC_PROP_DIMALI_DP1Y = 6052
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2833
try:
    LC_PROP_DIMALI_DP2X = 6053
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2834
try:
    LC_PROP_DIMALI_DP2Y = 6054
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2835
try:
    LC_PROP_DIMALI_TPX = 6055
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2836
try:
    LC_PROP_DIMALI_TPY = 6056
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2837
try:
    LC_PROP_DIMALI__MAX = 6069
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2839
try:
    LC_PROP_DIMDIA__MIN = 6071
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2840
try:
    LC_PROP_DIMDIA_CPX = 6071
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2841
try:
    LC_PROP_DIMDIA_CPY = 6072
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2842
try:
    LC_PROP_DIMDIA_RPX = 6073
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2843
try:
    LC_PROP_DIMDIA_RPY = 6074
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2844
try:
    LC_PROP_DIMDIA_FPX = 6075
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2845
try:
    LC_PROP_DIMDIA_FPY = 6076
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2846
try:
    LC_PROP_DIMDIA_TPX = 6077
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2847
try:
    LC_PROP_DIMDIA_TPY = 6078
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2848
try:
    LC_PROP_DIMDIA__MAX = 6085
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2850
try:
    LC_PROP_DIMRAD__MIN = 6086
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2851
try:
    LC_PROP_DIMRAD_CPX = 6086
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2852
try:
    LC_PROP_DIMRAD_CPY = 6087
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2853
try:
    LC_PROP_DIMRAD_RPX = 6088
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2854
try:
    LC_PROP_DIMRAD_RPY = 6089
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2855
try:
    LC_PROP_DIMRAD_TPX = 6090
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2856
try:
    LC_PROP_DIMRAD_TPY = 6091
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2857
try:
    LC_PROP_DIMRAD__MAX = 6099
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2859
try:
    LC_PROP_DIMORD__MIN = 6101
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2860
try:
    LC_PROP_DIMORD_XORD = 6101
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2862
try:
    LC_PROP_DIMORD_DPX = 6102
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2863
try:
    LC_PROP_DIMORD_DPY = 6103
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2864
try:
    LC_PROP_DIMORD_TPX = 6104
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2865
try:
    LC_PROP_DIMORD_TPY = 6105
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2866
try:
    LC_PROP_DIMORD__MAX = 6119
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2868
try:
    LC_PROP_DIMROT__MIN = 6121
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2869
try:
    LC_PROP_DIMROT_ANGLE = 6121
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2870
try:
    LC_PROP_DIMROT_DP1X = 6122
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2871
try:
    LC_PROP_DIMROT_DP1Y = 6123
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2872
try:
    LC_PROP_DIMROT_DP2X = 6124
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2873
try:
    LC_PROP_DIMROT_DP2Y = 6125
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2874
try:
    LC_PROP_DIMROT_TPX = 6126
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2875
try:
    LC_PROP_DIMROT_TPY = 6127
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2876
try:
    LC_PROP_DIMROT__MAX = 6139
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2878
try:
    LC_PROP_DIMLIN__MIN = 6121
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2879
try:
    LC_PROP_DIMLIN_ANGLE = 6121
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2880
try:
    LC_PROP_DIMLIN_DP1X = 6122
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2881
try:
    LC_PROP_DIMLIN_DP1Y = 6123
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2882
try:
    LC_PROP_DIMLIN_DP2X = 6124
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2883
try:
    LC_PROP_DIMLIN_DP2Y = 6125
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2884
try:
    LC_PROP_DIMLIN_TPX = 6126
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2885
try:
    LC_PROP_DIMLIN_TPY = 6127
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2886
try:
    LC_PROP_DIMLIN__MAX = 6139
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2889
try:
    LC_PROP_LEADER_STYLE = 6202
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2891
try:
    LC_PROP_LEADER_TEXT = 6203
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2892
try:
    LC_PROP_LEADER_ALIGN = 6204
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2894
try:
    LC_PROP_LEADER_TPX = 6205
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2895
try:
    LC_PROP_LEADER_TPY = 6206
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2896
try:
    LC_PROP_LEADER_APX = 6207
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2897
try:
    LC_PROP_LEADER_APY = 6208
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2898
try:
    LC_PROP_LEADER_P1X = 6209
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2899
try:
    LC_PROP_LEADER_P1Y = 6210
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2900
try:
    LC_PROP_LEADER_P0X = 6211
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2901
try:
    LC_PROP_LEADER_P0Y = 6212
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2902
try:
    LC_PROP_LEADER_LDIST = 6213
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2903
try:
    LC_PROP_LEADER_VERT = 6214
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2904
try:
    LC_PROP_LEADER_CORNER = 6215
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2905
try:
    LC_PROP_LEADER_TBW = 6216
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2906
try:
    LC_PROP_LEADER_TBH = 6217
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2909
try:
    LC_PROP_FACE_X0 = 6281
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2910
try:
    LC_PROP_FACE_Y0 = 6282
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2911
try:
    LC_PROP_FACE_Z0 = 6283
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2912
try:
    LC_PROP_FACE_X1 = 6284
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2913
try:
    LC_PROP_FACE_Y1 = 6285
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2914
try:
    LC_PROP_FACE_Z1 = 6286
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2915
try:
    LC_PROP_FACE_X2 = 6287
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2916
try:
    LC_PROP_FACE_Y2 = 6288
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2917
try:
    LC_PROP_FACE_Z2 = 6289
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2918
try:
    LC_PROP_FACE_X3 = 6290
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2919
try:
    LC_PROP_FACE_Y3 = 6291
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2920
try:
    LC_PROP_FACE_Z3 = 6292
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2921
try:
    LC_PROP_FACE_EDGE1 = 6293
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2922
try:
    LC_PROP_FACE_EDGE2 = 6294
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2923
try:
    LC_PROP_FACE_EDGE3 = 6295
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2924
try:
    LC_PROP_FACE_EDGE4 = 6296
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2925
try:
    LC_PROP_FACE_EDGE = 6297
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2927
try:
    LC_PROP_FACE_NPTS = 6298
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2930
try:
    LC_PROP_RPLAN_LEN = 6301
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2931
try:
    LC_PROP_RPLAN_MARKARC = 6302
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2932
try:
    LC_PROP_RPLAN_MARKSIZE = 6303
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2933
try:
    LC_PROP_RPLAN_NVERS = 6311
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2934
try:
    LC_PROP_RPLAN_IVER = 6312
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2937
try:
    LC_PROP_SHAPE_NENTS = 6341
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2938
try:
    LC_PROP_SHAPE_NPATHS = 6342
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2941
try:
    LC_PROP_TIN_NAME = 7001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2942
try:
    LC_PROP_TIN_DESCR = 7002
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2943
try:
    LC_PROP_TIN_FILENAME = 7003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2944
try:
    LC_PROP_TIN_NPTYPES = 7004
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2945
try:
    LC_PROP_TIN_NPOINTS = 7005
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2946
try:
    LC_PROP_TIN_NTRIANS = 7006
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2947
try:
    LC_PROP_TIN_NBNDPTS = 7007
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2948
try:
    LC_PROP_TIN_NISOLINES = 7008
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2949
try:
    LC_PROP_TIN_HASCFILL = 7009
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2950
try:
    LC_PROP_TIN_PNTIMGDIR = 7010
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2952
try:
    LC_PROP_TIN_XMIN = 7020
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2953
try:
    LC_PROP_TIN_XMAX = 7021
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2954
try:
    LC_PROP_TIN_YMIN = 7022
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2955
try:
    LC_PROP_TIN_YMAX = 7023
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2956
try:
    LC_PROP_TIN_ZMIN = 7024
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2957
try:
    LC_PROP_TIN_ZMAX = 7025
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2958
try:
    LC_PROP_TIN_DX = 7026
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2959
try:
    LC_PROP_TIN_DY = 7027
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2960
try:
    LC_PROP_TIN_DZ = 7028
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2961
try:
    LC_PROP_TIN_ISOBASE = 7031
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2962
try:
    LC_PROP_TIN_ISOSTEP = 7032
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2963
try:
    LC_PROP_TIN_ISOBOLD = 7033
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2964
try:
    LC_PROP_TIN_ISOSPLINE = 7034
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2965
try:
    LC_PROP_TIN_IMG_ZSTEP = 7041
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2966
try:
    LC_PROP_TIN_IMG_PSIZE = 7043
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2967
try:
    LC_PROP_TIN_IMG_NX = 7044
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2968
try:
    LC_PROP_TIN_IMG_NY = 7045
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2970
try:
    LC_PROP_TIN_VIEWPT = 7051
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2971
try:
    LC_PROP_TIN_VIEWPTN = 7052
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2972
try:
    LC_PROP_TIN_VIEWPTI = 7053
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2973
try:
    LC_PROP_TIN_VIEWPTZ = 7054
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2974
try:
    LC_PROP_TIN_VIEWTR = 7055
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2975
try:
    LC_PROP_TIN_VIEWCF = 7056
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2976
try:
    LC_PROP_TIN_VIEWTRI = 7058
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2977
try:
    LC_PROP_TIN_VIEWTRV = 7059
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2978
try:
    LC_PROP_TIN_VIEWBND = 7060
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2979
try:
    LC_PROP_TIN_VIEWBNDI = 7061
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2980
try:
    LC_PROP_TIN_VIEWISO = 7062
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2981
try:
    LC_PROP_TIN_VIEWISOH = 7063
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2982
try:
    LC_PROP_TIN_VIEWZ = 7065
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2983
try:
    LC_PROP_VIEWTINTILES = 7066
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2984
try:
    LC_PROP_VIEWTINCFIR = 7067
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2986
try:
    LC_PROP_TIN_COLTR = 7071
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2987
try:
    LC_PROP_TIN_COLTRI = 7072
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2988
try:
    LC_PROP_TIN_COLTRV = 7073
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2989
try:
    LC_PROP_TIN_COLISO = 7074
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2990
try:
    LC_PROP_TIN_COLISOB = 7075
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2991
try:
    LC_PROP_TIN_COLISOW = 7076
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2992
try:
    LC_PROP_TIN_COLBND = 7077
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2993
try:
    LC_PROP_TIN_COLBNDP = 7078
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2994
try:
    LC_PROP_TIN_COLTRF = 7079
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2996
try:
    LC_PROP_TIN_COLFRONT0 = 7080
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 2998
try:
    LC_PROP_TIN_COLFRONT = 7081
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3001
try:
    LC_PROP_TIN_LX_PRJNAME = 7091
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3002
try:
    LC_PROP_TIN_LX_APPNAME = 7092
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3003
try:
    LC_PROP_TIN_LX_DESCR = 7093
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3004
try:
    LC_PROP_TIN_LX_MANUF = 7094
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3005
try:
    LC_PROP_TIN_LX_VER = 7095
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3006
try:
    LC_PROP_TIN_LX_URL = 7096
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3007
try:
    LC_PROP_TIN_LX_TIME = 7097
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3008
try:
    LC_PROP_ENT__MAX = 9999
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3012
try:
    LC_PROP_VER__MIN = 10001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3013
try:
    LC_PROP_VER_X = 10001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3014
try:
    LC_PROP_VER_Y = 10002
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3015
try:
    LC_PROP_VER_Z = 10003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3016
try:
    LC_PROP_VER_FIX = 10006
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3018
try:
    LC_PROP_VER_RADIUS = 10007
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3019
try:
    LC_PROP_VER_WEIGHT = 10008
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3020
try:
    LC_PROP_VER_INDEX = 10009
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3021
try:
    LC_PROP_VER_FIRST = 10010
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3022
try:
    LC_PROP_VER_LAST = 10011
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3024
try:
    LC_PROP_VER_W0 = 10012
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3025
try:
    LC_PROP_VER_W1 = 10013
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3026
try:
    LC_PROP_VER_SEGDX = 10014
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3027
try:
    LC_PROP_VER_SEGDY = 10015
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3028
try:
    LC_PROP_VER_SEGANG = 10016
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3029
try:
    LC_PROP_VER_SEGLEN = 10017
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3030
try:
    LC_PROP_VER_BULGE = 10021
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3031
try:
    LC_PROP_VER_SEGARCANG = 10022
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3032
try:
    LC_PROP_VER_SEGARCH = 10023
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3033
try:
    LC_PROP_VER_SEGARCLEN = 10024
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3034
try:
    LC_PROP_VER_SEGARCRAD = 10025
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3035
try:
    LC_PROP_VER__MAX = 10040
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3038
try:
    LC_PROP_RPVER__MIN = 10041
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3039
try:
    LC_PROP_RPVER_X = 10041
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3040
try:
    LC_PROP_RPVER_Y = 10042
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3041
try:
    LC_PROP_RPVER_ANGLE = 10043
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3042
try:
    LC_PROP_RPVER_DIRANG = 10044
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3043
try:
    LC_PROP_RPVER_R = 10045
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3044
try:
    LC_PROP_RPVER_L1 = 10046
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3045
try:
    LC_PROP_RPVER_L2 = 10047
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3046
try:
    LC_PROP_RPVER_ANGL1 = 10048
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3047
try:
    LC_PROP_RPVER_ANGARC = 10049
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3048
try:
    LC_PROP_RPVER_ANGL2 = 10050
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3049
try:
    LC_PROP_RPVER_BISEC = 10051
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3050
try:
    LC_PROP_RPVER_DOMER = 10052
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3051
try:
    LC_PROP_RPVER_ARCLEN = 10053
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3052
try:
    LC_PROP_RPVER_CURLEN = 10054
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3053
try:
    LC_PROP_RPVER_LINE1 = 10055
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3054
try:
    LC_PROP_RPVER_T1 = 10056
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3055
try:
    LC_PROP_RPVER_T2 = 10057
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3056
try:
    LC_PROP_RPVER_LINE2 = 10058
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3057
try:
    LC_PROP_RPVER_DIST1 = 10059
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3058
try:
    LC_PROP_RPVER_DIST2 = 10060
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3059
try:
    LC_PROP_RPVER__MAX = 10070
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3061
try:
    LC_PROP_XDATA__MIN = 10901
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3062
try:
    LC_PROP_XDATA_BOOL = 10901
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3063
try:
    LC_PROP_XDATA_INT = 10902
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3064
try:
    LC_PROP_XDATA_FLOAT = 10903
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3065
try:
    LC_PROP_XDATA_STR = 10907
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3066
try:
    LC_PROP_XDATA__MAX = 10910
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3069
try:
    LC_PROP_OTHER__MIN = 11001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3070
try:
    LC_PROP_CMDWND_ENABLE = 11001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3071
try:
    LC_PROP_PROPWND_ENABLE = 11002
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3072
try:
    LC_PROP_PROPWND_DIVCOEF = 11003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3074
try:
    LC_PROP_OTHER__MAX = 11999
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3077
try:
    LC_PROP_EVENT__MIN = 12001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3078
try:
    LC_PROP_EVENT_TYPE = 12001
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3079
try:
    LC_PROP_EVENT_APPPRM1 = 12002
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3080
try:
    LC_PROP_EVENT_APPPRM2 = 12003
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3081
try:
    LC_PROP_EVENT_WND = 12004
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3082
try:
    LC_PROP_EVENT_DRW = 12005
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3083
try:
    LC_PROP_EVENT_BLOCK = 12006
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3084
try:
    LC_PROP_EVENT_ENTITY = 12007
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3085
try:
    LC_PROP_EVENT_ENT = 12007
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3086
try:
    LC_PROP_EVENT_HCMD = 12008
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3087
try:
    LC_PROP_EVENT_HOBJ = 12008
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3088
try:
    LC_PROP_EVENT_HDC = 12009
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3090
try:
    LC_PROP_EVENT_MODE = 12010
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3091
try:
    LC_PROP_EVENT_INT1 = 12021
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3092
try:
    LC_PROP_EVENT_INT2 = 12022
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3093
try:
    LC_PROP_EVENT_INT3 = 12023
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3094
try:
    LC_PROP_EVENT_INT4 = 12024
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3095
try:
    LC_PROP_EVENT_INT5 = 12025
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3096
try:
    LC_PROP_EVENT_INT6 = 12026
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3097
try:
    LC_PROP_EVENT_FLOAT1 = 12031
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3098
try:
    LC_PROP_EVENT_FLOAT2 = 12032
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3099
try:
    LC_PROP_EVENT_FLOAT3 = 12033
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3100
try:
    LC_PROP_EVENT_FLOAT4 = 12034
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3101
try:
    LC_PROP_EVENT_FLOAT5 = 12035
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3102
try:
    LC_PROP_EVENT_FLOAT6 = 12036
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3103
try:
    LC_PROP_EVENT_STR1 = 12041
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3104
try:
    LC_PROP_EVENT_STR2 = 12042
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3105
try:
    LC_PROP_EVENT_STR3 = 12043
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3106
try:
    LC_PROP_EVENT__MAX = 12999
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3109
try:
    LC_EVENT_HELP = 101
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3110
try:
    LC_EVENT_PAINT = 102
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3111
try:
    LC_EVENT_PAINTBG = 124
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3112
try:
    LC_EVENT_WNDVIEW = 103
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3113
try:
    LC_EVENT_MOUSEMOVE = 105
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3114
try:
    LC_EVENT_LBDOWN = 106
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3115
try:
    LC_EVENT_LBUP = 107
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3116
try:
    LC_EVENT_LBDBLCLK = 108
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3117
try:
    LC_EVENT_RBDOWN = 109
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3118
try:
    LC_EVENT_RBUP = 110
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3119
try:
    LC_EVENT_KEYDOWN = 111
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3120
try:
    LC_EVENT_VIEWBLOCK = 112
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3121
try:
    LC_EVENT_EXTENTS = 113
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3122
try:
    LC_EVENT_SNAP = 114
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3123
try:
    LC_EVENT_MAGNIFIER = 115
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3124
try:
    LC_EVENT_NAVIGATOR = 116
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3125
try:
    LC_EVENT_CMDINWND = 117
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3126
try:
    LC_EVENT_GRID = 118
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3127
try:
    LC_EVENT_OSNAP = 119
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3128
try:
    LC_EVENT_PTRACK = 120
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3129
try:
    LC_EVENT_ORTHO = 121
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3130
try:
    LC_EVENT_FILETAB = 122
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3131
try:
    LC_EVENT_WAITPOINT = 123
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3133
try:
    LC_EVENT_FILE = 131
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3134
try:
    LC_EVENT_ADDENTITY = 132
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3135
try:
    LC_EVENT_WNDPROP = 133
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3136
try:
    LC_EVENT_DRWPROP = 134
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3137
try:
    LC_EVENT_ENTPROP = 135
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3138
try:
    LC_EVENT_ENTMOVE = 136
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3139
try:
    LC_EVENT_ENTSCALE = 137
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3140
try:
    LC_EVENT_ENTROTATE = 138
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3141
try:
    LC_EVENT_ENTMIRROR = 139
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3142
try:
    LC_EVENT_ENTERASE = 140
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3143
try:
    LC_EVENT_DRAWIMAGE = 141
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3144
try:
    LC_EVENT_SELECT = 145
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3145
try:
    LC_EVENT_PICKENT = 146
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3146
try:
    LC_EVENT_ADDSTR = 147
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3147
try:
    LC_EVENT_ADDCMD = 148
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3148
try:
    LC_EVENT_CCMD = 149
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3149
try:
    LC_EVENT_TIN = 150
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3150
try:
    LC_EVENT_DRWFILEEXT = 151
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3151
try:
    LC_EVENT_DRWPREVIEW = 152
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3152
try:
    LC_EVENT_DRWLOAD = 153
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3153
try:
    LC_EVENT_DRWSAVE = 154
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3154
try:
    LC_EVENT_GRIPMOVE = 155
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3155
try:
    LC_EVENT_GRIPDRAG = 156
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3156
try:
    LC_EVENT_DIRTY = 157
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3157
try:
    LC_EVENT_SELENT1 = 161
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3158
try:
    LC_EVENT_SELENTS = 162
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3159
try:
    LC_EVENT_GRIPPAINT = 165
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3160
try:
    LC_EVENT_DRAWCURSOR = 166
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3161
try:
    LC_EVENT_RULERCORNER = 167
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3162
try:
    LC_EVENT_WNDTAB = 171
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3163
try:
    LC_EVENT_CMD1 = 212
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3164
try:
    LC_EVENT_LAYERS = 303
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3167
try:
    LC_CCMD_CREATE = 1
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3168
try:
    LC_CCMD_DESTROY = 2
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3169
try:
    LC_CCMD_START = 3
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3170
try:
    LC_CCMD_FINISH = 4
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3171
try:
    LC_CCMD_LBDOWN = 5
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3172
try:
    LC_CCMD_LBUP = 6
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3173
try:
    LC_CCMD_RBDOWN = 7
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3174
try:
    LC_CCMD_RBUP = 8
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3175
try:
    LC_CCMD_MOUSEMOVE = 9
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3176
try:
    LC_CCMD_PAINT = 10
except NameError:
    pass

# D:\\projects\\gllc\\litecad.h: 3177
try:
    LC_CCMD_SNAP = 11
except NameError:
    pass

# No inserted files

# No prefix-stripping
