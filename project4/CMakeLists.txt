add_compile_options(-mavx -msse4 -g)
add_compile_options(-O3)
# FIND_PACKAGE( OpenMP REQUIRED)
# if(OPENMP_FOUND)
#     message("OPENMP FOUND")
#     set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
# endif()
# add_compile_options(-fopenmp -lgomp)


add_executable(test test.c matrix.c multiply.c)

# add_executable(test_correct test_correct.c matrix.c multiply.c)
