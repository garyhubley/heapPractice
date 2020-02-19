CMAKE_MINIMUM_REQUIRED( VERSION 3.10 )

PROJECT( garysHeap VERSION 0.1 )

ADD_EXECUTABLE( heapTests
    tests/src/heapTests.cpp
    tests/src/utilities.cpp
    )
ADD_SUBDIRECTORY( heap )

TARGET_INCLUDE_DIRECTORIES( heapTests PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/inc"
    )

TARGET_LINK_LIBRARIES( heapTests PUBLIC heapLib )
