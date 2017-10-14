# Created by and for Qt Creator. This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

TARGET = OpenGLEngine

OTHER_FILES = \
   $$PWD/shaders/basicFragment.fs \
   $$PWD/shaders/basicVertex.vs \
   $$PWD/shaders/litTexture.fs \
   $$PWD/shaders/litTexture.vs \
   $$PWD/shaders/phongFragment.fs \
   $$PWD/shaders/phongFragmentDebug.fs \
   $$PWD/shaders/phongVertex.vs \
   $$PWD/shaders/phongVertexDebug.vs

HEADERS = \
   $$PWD/include/attenuation.h \
   $$PWD/include/baselight.h \
   $$PWD/include/basicshader.h \
   $$PWD/include/camera.h \
   $$PWD/include/directionallight.h \
   $$PWD/include/engine.h \
   $$PWD/include/engine_input.h \
   $$PWD/include/engine_time.h \
   $$PWD/include/game.h \
   $$PWD/include/material.h \
   $$PWD/include/matrix4f.h \
   $$PWD/include/mesh.h \
   $$PWD/include/phongshader.h \
   $$PWD/include/point_light.h \
   $$PWD/include/quaternion.h \
   $$PWD/include/render_util.h \
   $$PWD/include/resource_loader.h \
   $$PWD/include/shader.h \
   $$PWD/include/texture.h \
   $$PWD/include/transform.h \
   $$PWD/include/vector2f.h \
   $$PWD/include/vector3f.h \
   $$PWD/include/vertex.h \
   $$PWD/include/window.h \
    include/spot_light.h

SOURCES = \
   $$PWD/src/attenuation.cpp \
   $$PWD/src/baselight.cpp \
   $$PWD/src/basicshader.cpp \
   $$PWD/src/camera.cpp \
   $$PWD/src/directionallight.cpp \
   $$PWD/src/engine.cpp \
   $$PWD/src/engine_input.cpp \
   $$PWD/src/engine_time.cpp \
   $$PWD/src/game.cpp \
   $$PWD/src/main.cpp \
   $$PWD/src/material.cpp \
   $$PWD/src/matrix4f.cpp \
   $$PWD/src/mesh.cpp \
   $$PWD/src/phongshader.cpp \
   $$PWD/src/pointlight.cpp \
   $$PWD/src/quaternion.cpp \
   $$PWD/src/render_util.cpp \
   $$PWD/src/resource_loader.cpp \
   $$PWD/src/shader.cpp \
   $$PWD/src/texture.cpp \
   $$PWD/src/transform.cpp \
   $$PWD/src/vector2f.cpp \
   $$PWD/src/vector3f.cpp \
   $$PWD/src/vertex.cpp \
   $$PWD/src/window.cpp \
    src/spot_light.cpp

INCLUDEPATH = \
    $$PWD/include

#DEFINES = 


unix|win32: LIBS += -lGL
unix|win32: LIBS += -lSDL2
unix|win32: LIBS += -lSOIL
unix|win32: LIBS += -lGLEW
unix|win32: LIBS += -lassimp
