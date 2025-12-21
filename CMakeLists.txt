cmake_minimum_required(VERSION 3.15...4.0)

project(graphics_pipeline VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME}
                src/main.cpp
                src/core/pipeline/Renderer.cpp include/graphics_pipeline/core/pipeline/Renderer.h
                src/core/scene/Camera.cpp include/graphics_pipeline/core/scene/Camera.h
                src/core/scene/Scene.cpp include/graphics_pipeline/core/scene/Scene.h
                src/model_parser/obj/ObjModel.cpp include/graphics_pipeline/model_parser/obj/ObjModel.h
                src/model_parser/obj/ObjParser.cpp include/graphics_pipeline/model_parser/obj/ObjParser.h
                include/graphics_pipeline/model_parser/obj/ObjModelData.h
                include/graphics_pipeline/model_parser/obj/ObjFace.h
                include/graphics_pipeline/core/model/IModel.h
                include/graphics_pipeline/core/model/IModelParser.h
                include/graphics_pipeline/core/pipeline/FrameBuffer.h
                include/graphics_pipeline/frame_buffer/PNG.h
                third_party/include/stb/stb_image_write.h)

target_include_directories(${PROJECT_NAME} PUBLIC "include")
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE "${CMAKE_SOURCE_DIR}/third_party/include")