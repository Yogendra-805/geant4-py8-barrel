# Create a FindPythia8.cmake file and place it in a directory in CMAKE_MODULE_PATH
# This file should define variables like PYTHIA8_INCLUDE_DIRS and PYTHIA8_LIBRARIES
# based on the actual Pythia8 installation on your system.

# Find the Pythia8 include directory
find_path(PYTHIA8_INCLUDE_DIRS NAMES Pythia8/Pythia.h PATHS /home/particle/pythia8310/include)

# Find the Pythia8 libraries
find_library(PYTHIA8_LIBRARIES NAMES libpythia8.a PATHS /home/particle/pythia8310/lib)

# Export the variables
set(PYTHIA8_FOUND TRUE)
set(PYTHIA8_INCLUDE_DIRS ${PYTHIA8_INCLUDE_DIRS})
set(PYTHIA8_LIBRARIES ${PYTHIA8_LIBRARIES})
