cmake_minimum_required(VERSION 2.8)

project(TP1_Calculatrice)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(${PROJECT_NAME}
    "main.cpp"
calcwidget.cpp
    calcmodel.cpp
    calcexception.cpp
    calccontroller.cpp
        calcwidget.h
    calcmodel.h
    calcexception.h
    calccontroller.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)


