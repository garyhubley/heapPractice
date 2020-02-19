
CONFIGURE_FILE( version.h.in inc/version.h )
ADD_LIBRARY( heapLib src/heap.cpp )

TARGET_INCLUDE_DIRECTORIES( heapLib PUBLIC
    "${PROJECT_BINARY_DIR}/inc"
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
    )

