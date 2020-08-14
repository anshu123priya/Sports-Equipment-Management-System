cmake_minimum_required(VERSION 3.1)
project(sem)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(sem 
	AddEquipmentController.cpp
        AddEquipmentController.h
        Application.cpp
        Application.h
        AvailableEquipments.cpp
        AvailableEquipments.h
        Guard.cpp
        Guard.h
        main.cpp
        OutstandingEquipments.cpp
        OutstandingEquipments.h
        SecretaryController.cpp
        SecretaryController.h
        SecretaryHomePageController.cpp
        SecretaryHomePageController.h
        SecretaryLoginController.cpp
        SecretaryLoginController.h
        Student.cpp
        Student.h
        StudentController.cpp
        StudentController.h
        StudentDuesController.cpp
        StudentDuesController.h
        StudentHomePageController.cpp
        StudentHomePageController.h
        StudentIssueEquipmentController.cpp
        StudentIssueEquipmentController.h
        StudentLoginController.cpp
        StudentLoginController.h
        StudentReturnEquipmentController.cpp
        StudentReturnEquipmentController.h
        TotalEquipments.cpp
        TotalEquipments.h
        ViewByAvailabilityController.cpp
        ViewByAvailabilityController.h
        ViewByCategoryController.cpp
        ViewByCategoryController.h
        ViewByOutstandingController.cpp
        ViewByOutstandingController.h
        ViewDetailsController.cpp
        ViewDetailsController.h
        ViewStudentDuesController.cpp
        ViewStudentDuesController.h)
include_directories(${CMAKE_CURRENT_LIST_DIR}/mysql-headers)
target_link_libraries(sem mysqlclient)
