cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.
#________________________________________________________________________________________________________________

set(PROJECT_NAME HASH_TABLE) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта
#________________________________________________________________________________________________________________

set(TArrayTableLIB TArrayTableLIB) #Переменная с именем приложения
set(THashTableLIB THashTableLIB) #Переменная с именем библиотеки
set(TTableLIB TTableLIB)
set(TTreeTableLIB TTreeTableLIB)
set(test test)
set(gtest gtest)
set(main main)
#________________________________________________________________________________________________________________

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()
#________________________________________________________________________________________________________________

include_directories(
${CMAKE_CURRENT_SOURCE_DIR}/TArrayTableLIB 
${CMAKE_CURRENT_SOURCE_DIR}/THashTableLIB 
${CMAKE_CURRENT_SOURCE_DIR}/TTableLIB 
${CMAKE_CURRENT_SOURCE_DIR}/TTreeTableLIB
) #Добавляем директорию "${CMAKE_CURRENT_SOURCE_DIR}/vectorlib" в дополняемые каталоги включаемых файлов



#${CMAKE_CURRENT_SOURCE_DIR} - стандартная переменная с адресом рабочей директории
#________________________________________________________________________________________________________________

add_subdirectory(TArrayTableLIB) #Добавляем директорию с под-CMakeList-ом, и выполняем под-CMakeList
add_subdirectory(THashTableLIB)
add_subdirectory(TTableLIB)
add_subdirectory(TTreeTableLIB)
add_subdirectory(test)
add_subdirectory(gtest)
add_subdirectory(main)
#________________________________________________________________________________________________________________

#file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
#file(GLOB srcs "*.cpp") #Добавляем в переменную srcs все файлы с расширением .cpp
#________________________________________________________________________________________________________________

#include_directories(lib1)
#add_executable(${PROJECT_NAME} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${PROJECT_NAME}, в него добавляются файлы из переменных ${srcs} и ${hdrs}
#________________________________________________________________________________________________________________

 #Собираем проект в поддиректории lib1
#target_link_libraries(${PROJECT_NAME} ${MyLib1}) #Подключаем к проекту с именем ${PROJECT_NAME} библиотеку с именем ${MyLib1}