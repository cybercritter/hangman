file(GLOB_RECURSE
    ALL_CXX_SOURCE_FILES
    *.[chi]pp *.[chi]xx *.cc *.hh *.ii *.[CHI]
)
target_sources(${PROJECT_NAME} ${ALL_CXX_SOURCE_FILES})