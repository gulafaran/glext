SET(SRC
  main.c
  )

FIND_PACKAGE(X11 REQUIRED)

ADD_DEFINITIONS(-std=c99 -D_DEFAULT_SOURCE)
ADD_EXECUTABLE(glext ${SRC})
INSTALL(TARGETS glext DESTINATION bin)

if (UNIX)
  INSTALL(CODE "
  execute_process(COMMAND chown root ${CMAKE_INSTALL_PREFIX}/bin/glext)
  execute_process(COMMAND chmod g+s ${CMAKE_INSTALL_PREFIX}/bin/glext)
  ")
endif ()
