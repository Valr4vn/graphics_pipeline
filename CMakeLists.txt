cmake_minimum_required(VERSION 3.15...4.0)

project(graphics_pipeline VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME}
                src/main.cpp
                src/model/obj/ObjModel.cpp include/graphics_pipeline/model/obj/ObjModel.h
                src/model/obj/ObjParser.cpp include/graphics_pipeline/model/obj/ObjModel.h
                include/graphics_pipeline/model/obj/ObjModelData.h
                include/graphics_pipeline/model/obj/ObjFace.h)

target_include_directories(${PROJECT_NAME} PUBLIC "include")