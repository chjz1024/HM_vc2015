project(TAppDecoder CXX)

################################################################################
# Source groups
################################################################################
set(Header_Files
    ../../source/App/TAppDecoder/TAppDecCfg.h
    ../../source/App/TAppDecoder/TAppDecTop.h
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    ../../source/App/TAppDecoder/decmain.cpp
    ../../source/App/TAppDecoder/TAppDecCfg.cpp
    ../../source/App/TAppDecoder/TAppDecTop.cpp
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${Header_Files}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})

if(NOT ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32"
     OR "${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64"))
    message(WARNING "${CMAKE_VS_PLATFORM_NAME} arch is not supported!")
endif()

################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    string(CONCAT TARGET_NAME
          $<$<CONFIG:Debug>:${PROJECT_NAME}>
        $<$<CONFIG:Release>:${PROJECT_NAME}>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${PROJECT_NAME}>
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    string(CONCAT TARGET_NAME
          $<$<CONFIG:Debug>:${PROJECT_NAME}>
        $<$<CONFIG:Release>:${PROJECT_NAME}>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${PROJECT_NAME}>
    )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${TARGET_NAME})

################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    string(CONCAT OUT_DIR
          $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}//../bin/vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/>
        $<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}//../bin/vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${CMAKE_SOURCE_DIR}/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>>
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    string(CONCAT OUT_DIR
          $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}//../bin/vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/>
        $<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}//../bin/vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${CMAKE_SOURCE_DIR}/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>>
    )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR})

################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_include_directories(${PROJECT_NAME} PUBLIC 
          "$<$<CONFIG:Debug>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
        "$<$<CONFIG:Release>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC 
          "$<$<CONFIG:Debug>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
        "$<$<CONFIG:Release>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
          "$<$<CONFIG:Debug>:_DEBUG;"
                            "_CONSOLE;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
        "$<$<CONFIG:Release>:_CONSOLE;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
          "$<$<CONFIG:Debug>:_DEBUG;"
                            "_CONSOLE;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
        "$<$<CONFIG:Release>:_CONSOLE;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
              $<$<CONFIG:Debug>:/Od;
                                /RTC1;
                                /MTd;
                                /W3;
                                /Zi;
                                /EHsc
                                >
            $<$<CONFIG:Release>:/GL;
                                /O2;
                                /Ob2;
                                /Oi-;
                                /GF;
                                /MT;
                                /Gy;
                                /W3;
                                /Zi;
                                /EHsc
                                >
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
              $<$<CONFIG:Debug>:/Od;
                                /RTC1;
                                /MTd;
                                /W3;
                                /Zi;
                                /EHsc
                                >
            $<$<CONFIG:Release>:/GL;
                                /O2;
                                /Ob2;
                                /Oi-;
                                /GF;
                                /MT;
                                /Gy;
                                /W3;
                                /Zi;
                                /EHsc
                                >
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG "/DEBUG /INCREMENTAL")
        set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE "/LTCG /DEBUG /INCREMENTAL:NO")
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG "/DEBUG /INCREMENTAL")
        set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE "/LTCG /DEBUG /INCREMENTAL:NO")
    endif()
endif()

################################################################################
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
    TAppCommon
    TLibCommon
    TLibDecoder
    TLibVideoIO
)

# Link with other targets.
target_link_libraries(${PROJECT_NAME} PUBLIC
    TAppCommon
    TLibCommon
    TLibDecoder
    TLibVideoIO
)



























project(TAppEncoder CXX)

################################################################################
# Source groups
################################################################################
set(Header_Files
    ../../source/App/TAppEncoder/TAppEncCfg.h
    ../../source/App/TAppEncoder/TAppEncTop.h
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    ../../source/App/TAppEncoder/encmain.cpp
    ../../source/App/TAppEncoder/TAppEncCfg.cpp
    ../../source/App/TAppEncoder/TAppEncTop.cpp
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${Header_Files}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})

if(NOT ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32"
     OR "${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64"))
    message(WARNING "${CMAKE_VS_PLATFORM_NAME} arch is not supported!")
endif()

################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    string(CONCAT TARGET_NAME
          $<$<CONFIG:Debug>:${PROJECT_NAME}>
        $<$<CONFIG:Release>:${PROJECT_NAME}>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${PROJECT_NAME}>
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    string(CONCAT TARGET_NAME
          $<$<CONFIG:Debug>:${PROJECT_NAME}>
        $<$<CONFIG:Release>:${PROJECT_NAME}>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${PROJECT_NAME}>
    )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${TARGET_NAME})

################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    string(CONCAT OUT_DIR
          $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}//../bin/vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/>
        $<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}//../bin/vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${CMAKE_SOURCE_DIR}/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>>
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    string(CONCAT OUT_DIR
          $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}//../bin/vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/>
        $<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}//../bin/vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${CMAKE_SOURCE_DIR}/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>>
    )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR})

################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_include_directories(${PROJECT_NAME} PUBLIC 
          "$<$<CONFIG:Debug>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
        "$<$<CONFIG:Release>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC 
          "$<$<CONFIG:Debug>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
        "$<$<CONFIG:Release>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
          "$<$<CONFIG:Debug>:_DEBUG;"
                            "_CONSOLE;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
        "$<$<CONFIG:Release>:_CONSOLE;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
          "$<$<CONFIG:Debug>:_DEBUG;"
                            "_CONSOLE;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
        "$<$<CONFIG:Release>:_CONSOLE;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
              $<$<CONFIG:Debug>:/Od;
                                /RTC1;
                                /MTd;
                                /W3;
                                /Zi;
                                /EHsc
                                >
            $<$<CONFIG:Release>:/GL;
                                /O2;
                                /Ob2;
                                /Oi-;
                                /GF;
                                /MT;
                                /Gy;
                                /W3;
                                /Zi;
                                /EHsc
                                >
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
              $<$<CONFIG:Debug>:/Od;
                                /RTC1;
                                /MTd;
                                /W3;
                                /Zi;
                                /EHsc
                                >
            $<$<CONFIG:Release>:/GL;
                                /O2;
                                /Ob2;
                                /Oi-;
                                /GF;
                                /MT;
                                /Gy;
                                /W3;
                                /Zi;
                                /EHsc
                                >
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG "/DEBUG /INCREMENTAL")
        set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE "/LTCG /DEBUG /INCREMENTAL:NO")
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG "/DEBUG /INCREMENTAL")
        set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE "/LTCG /DEBUG /INCREMENTAL:NO")
    endif()
endif()

################################################################################
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
    TAppCommon
    TLibCommon
    TLibEncoder
    TLibVideoIO
)

# Link with other targets.
target_link_libraries(${PROJECT_NAME} PUBLIC
    TAppCommon
    TLibCommon
    TLibEncoder
    TLibVideoIO
)



























project(TAppCommon CXX)

################################################################################
# Source groups
################################################################################
set(Header_Files
    ../../source/Lib/TAppCommon/program_options_lite.h
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    ../../source/Lib/TAppCommon/program_options_lite.cpp
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${Header_Files}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

if(NOT ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32"
     OR "${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64"))
    message(WARNING "${CMAKE_VS_PLATFORM_NAME} arch is not supported!")
endif()

################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    string(CONCAT TARGET_NAME
          $<$<CONFIG:Debug>:${PROJECT_NAME}>
        $<$<CONFIG:Release>:${PROJECT_NAME}>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${PROJECT_NAME}>
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    string(CONCAT TARGET_NAME
          $<$<CONFIG:Debug>:${PROJECT_NAME}>
        $<$<CONFIG:Release>:${PROJECT_NAME}>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${PROJECT_NAME}>
    )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${TARGET_NAME})

################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    string(CONCAT OUT_DIR
          $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}//vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/${PROJECT_NAME}/>
        $<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}//vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/${PROJECT_NAME}/>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${CMAKE_SOURCE_DIR}/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>>
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    string(CONCAT OUT_DIR
          $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}//vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/${PROJECT_NAME}/>
        $<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}//vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/${PROJECT_NAME}/>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${CMAKE_SOURCE_DIR}/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>>
    )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${OUT_DIR})
set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${OUT_DIR})

################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_include_directories(${PROJECT_NAME} PUBLIC 
          "$<$<CONFIG:Debug>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
        "$<$<CONFIG:Release>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC 
          "$<$<CONFIG:Debug>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
        "$<$<CONFIG:Release>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
          "$<$<CONFIG:Debug>:_DEBUG;"
                            "_LIB;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
        "$<$<CONFIG:Release>:_LIB;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
          "$<$<CONFIG:Debug>:_DEBUG;"
                            "_LIB;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
        "$<$<CONFIG:Release>:_LIB;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
              $<$<CONFIG:Debug>:/Od;
                                /RTC1;
                                /MTd;
                                /W3;
                                /Zi;
                                /EHsc
                                >
            $<$<CONFIG:Release>:/GL;
                                /O2;
                                /Ob2;
                                /Oi-;
                                /GF;
                                /MT;
                                /Gy;
                                /W3;
                                /Zi;
                                /EHsc
                                >
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
              $<$<CONFIG:Debug>:/Od;
                                /RTC1;
                                /MTd;
                                /W3;
                                /Zi;
                                /EHsc
                                >
            $<$<CONFIG:Release>:/GL;
                                /O2;
                                /Ob2;
                                /Oi-;
                                /GF;
                                /MT;
                                /Gy;
                                /W3;
                                /Zi;
                                /EHsc
                                >
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        set_target_properties(${PROJECT_NAME} PROPERTIES STATIC_LIBRARY_FLAGS_RELEASE "/LTCG")
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        set_target_properties(${PROJECT_NAME} PROPERTIES STATIC_LIBRARY_FLAGS_RELEASE "/LTCG")
    endif()
endif()



























project(TLibCommon CXX)

################################################################################
# Source groups
################################################################################
set(no_group_source_files
        ../../source/Lib/libmd5/libmd5.c
)
source_group("" FILES ${no_group_source_files})

set(Header_Files
    ../../source/Lib/libmd5/libmd5.h
    ../../source/Lib/libmd5/MD5.h
    ../../source/Lib/TLibCommon/AccessUnit.h
    ../../source/Lib/TLibCommon/CommonDef.h
    ../../source/Lib/TLibCommon/ContextModel.h
    ../../source/Lib/TLibCommon/ContextModel3DBuffer.h
    ../../source/Lib/TLibCommon/ContextTables.h
    ../../source/Lib/TLibCommon/Debug.h
    ../../source/Lib/TLibCommon/NAL.h
    ../../source/Lib/TLibCommon/SEI.h
    ../../source/Lib/TLibCommon/TComBitCounter.h
    ../../source/Lib/TLibCommon/TComBitStream.h
    ../../source/Lib/TLibCommon/TComCABACTables.h
    ../../source/Lib/TLibCommon/TComChromaFormat.h
    ../../source/Lib/TLibCommon/TComCodingStatistics.h
    ../../source/Lib/TLibCommon/TComDataCU.h
    ../../source/Lib/TLibCommon/TComInterpolationFilter.h
    ../../source/Lib/TLibCommon/TComList.h
    ../../source/Lib/TLibCommon/TComLoopFilter.h
    ../../source/Lib/TLibCommon/TComMotionInfo.h
    ../../source/Lib/TLibCommon/TComMv.h
    ../../source/Lib/TLibCommon/TComPattern.h
    ../../source/Lib/TLibCommon/TComPic.h
    ../../source/Lib/TLibCommon/TComPicSym.h
    ../../source/Lib/TLibCommon/TComPicYuv.h
    ../../source/Lib/TLibCommon/TComPrediction.h
    ../../source/Lib/TLibCommon/TComRdCost.h
    ../../source/Lib/TLibCommon/TComRdCostWeightPrediction.h
    ../../source/Lib/TLibCommon/TComRectangle.h
    ../../source/Lib/TLibCommon/TComRom.h
    ../../source/Lib/TLibCommon/TComSampleAdaptiveOffset.h
    ../../source/Lib/TLibCommon/TComSlice.h
    ../../source/Lib/TLibCommon/TComTrQuant.h
    ../../source/Lib/TLibCommon/TComTU.h
    ../../source/Lib/TLibCommon/TComWeightPrediction.h
    ../../source/Lib/TLibCommon/TComYuv.h
    ../../source/Lib/TLibCommon/TypeDef.h
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    ../../source/Lib/TLibCommon/ContextModel.cpp
    ../../source/Lib/TLibCommon/ContextModel3DBuffer.cpp
    ../../source/Lib/TLibCommon/Debug.cpp
    ../../source/Lib/TLibCommon/SEI.cpp
    ../../source/Lib/TLibCommon/TComBitStream.cpp
    ../../source/Lib/TLibCommon/TComCABACTables.cpp
    ../../source/Lib/TLibCommon/TComChromaFormat.cpp
    ../../source/Lib/TLibCommon/TComDataCU.cpp
    ../../source/Lib/TLibCommon/TComInterpolationFilter.cpp
    ../../source/Lib/TLibCommon/TComLoopFilter.cpp
    ../../source/Lib/TLibCommon/TComMotionInfo.cpp
    ../../source/Lib/TLibCommon/TComPattern.cpp
    ../../source/Lib/TLibCommon/TComPic.cpp
    ../../source/Lib/TLibCommon/TComPicSym.cpp
    ../../source/Lib/TLibCommon/TComPicYuv.cpp
    ../../source/Lib/TLibCommon/TComPicYuvMD5.cpp
    ../../source/Lib/TLibCommon/TComPrediction.cpp
    ../../source/Lib/TLibCommon/TComRdCost.cpp
    ../../source/Lib/TLibCommon/TComRdCostWeightPrediction.cpp
    ../../source/Lib/TLibCommon/TComRom.cpp
    ../../source/Lib/TLibCommon/TComSampleAdaptiveOffset.cpp
    ../../source/Lib/TLibCommon/TComSlice.cpp
    ../../source/Lib/TLibCommon/TComTrQuant.cpp
    ../../source/Lib/TLibCommon/TComTU.cpp
    ../../source/Lib/TLibCommon/TComWeightPrediction.cpp
    ../../source/Lib/TLibCommon/TComYuv.cpp
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${no_group_source_files}
    ${Header_Files}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

if(NOT ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32"
     OR "${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64"))
    message(WARNING "${CMAKE_VS_PLATFORM_NAME} arch is not supported!")
endif()

################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    string(CONCAT TARGET_NAME
          $<$<CONFIG:Debug>:${PROJECT_NAME}>
        $<$<CONFIG:Release>:${PROJECT_NAME}>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${PROJECT_NAME}>
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    string(CONCAT TARGET_NAME
          $<$<CONFIG:Debug>:${PROJECT_NAME}>
        $<$<CONFIG:Release>:${PROJECT_NAME}>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${PROJECT_NAME}>
    )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${TARGET_NAME})

################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    string(CONCAT OUT_DIR
          $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}//vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/${PROJECT_NAME}/>
        $<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}//vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/${PROJECT_NAME}/>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${CMAKE_SOURCE_DIR}/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>>
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    string(CONCAT OUT_DIR
          $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}//vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/${PROJECT_NAME}/>
        $<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}//vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/${PROJECT_NAME}/>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${CMAKE_SOURCE_DIR}/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>>
    )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${OUT_DIR})
set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${OUT_DIR})

################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_include_directories(${PROJECT_NAME} PUBLIC 
          "$<$<CONFIG:Debug>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
        "$<$<CONFIG:Release>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC 
          "$<$<CONFIG:Debug>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
        "$<$<CONFIG:Release>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
          "$<$<CONFIG:Debug>:_DEBUG;"
                            "_LIB;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
        "$<$<CONFIG:Release>:_LIB;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
          "$<$<CONFIG:Debug>:_DEBUG;"
                            "_LIB;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
        "$<$<CONFIG:Release>:_LIB;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
              $<$<CONFIG:Debug>:/Od;
                                /RTC1;
                                /MTd;
                                /W3;
                                /Zi;
                                /EHsc
                                >
            $<$<CONFIG:Release>:/GL;
                                /O2;
                                /Ob2;
                                /Oi-;
                                /GF;
                                /MT;
                                /Gy;
                                /W3;
                                /Zi;
                                /EHsc
                                >
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
              $<$<CONFIG:Debug>:/Od;
                                /RTC1;
                                /MTd;
                                /W3;
                                /Zi;
                                /EHsc
                                >
            $<$<CONFIG:Release>:/GL;
                                /O2;
                                /Ob2;
                                /Oi-;
                                /GF;
                                /MT;
                                /Gy;
                                /W3;
                                /Zi;
                                /EHsc
                                >
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Release>:/d2Qvec-sse2only>"
        )
    endif()
    source_file_compile_options(../../source/Lib/TLibCommon/TComTrQuant.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        set_target_properties(${PROJECT_NAME} PROPERTIES STATIC_LIBRARY_FLAGS_RELEASE "/LTCG")
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        set_target_properties(${PROJECT_NAME} PROPERTIES STATIC_LIBRARY_FLAGS_RELEASE "/LTCG")
    endif()
endif()



























project(TLibDecoder CXX)

################################################################################
# Source groups
################################################################################
set(Header_Files
    ../../source/Lib/TLibDecoder/AnnexBread.h
    ../../source/Lib/TLibDecoder/NALread.h
    ../../source/Lib/TLibDecoder/SEIread.h
    ../../source/Lib/TLibDecoder/SyntaxElementParser.h
    ../../source/Lib/TLibDecoder/TDecBinCoder.h
    ../../source/Lib/TLibDecoder/TDecBinCoderCABAC.h
    ../../source/Lib/TLibDecoder/TDecCAVLC.h
    ../../source/Lib/TLibDecoder/TDecConformance.h
    ../../source/Lib/TLibDecoder/TDecCu.h
    ../../source/Lib/TLibDecoder/TDecEntropy.h
    ../../source/Lib/TLibDecoder/TDecGop.h
    ../../source/Lib/TLibDecoder/TDecSbac.h
    ../../source/Lib/TLibDecoder/TDecSlice.h
    ../../source/Lib/TLibDecoder/TDecTop.h
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    ../../source/Lib/TLibDecoder/AnnexBread.cpp
    ../../source/Lib/TLibDecoder/NALread.cpp
    ../../source/Lib/TLibDecoder/SEIread.cpp
    ../../source/Lib/TLibDecoder/SyntaxElementParser.cpp
    ../../source/Lib/TLibDecoder/TDecBinCoderCABAC.cpp
    ../../source/Lib/TLibDecoder/TDecCAVLC.cpp
    ../../source/Lib/TLibDecoder/TDecConformance.cpp
    ../../source/Lib/TLibDecoder/TDecCu.cpp
    ../../source/Lib/TLibDecoder/TDecEntropy.cpp
    ../../source/Lib/TLibDecoder/TDecGop.cpp
    ../../source/Lib/TLibDecoder/TDecSbac.cpp
    ../../source/Lib/TLibDecoder/TDecSlice.cpp
    ../../source/Lib/TLibDecoder/TDecTop.cpp
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${Header_Files}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC TLibCommon)

if(NOT ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32"
     OR "${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64"))
    message(WARNING "${CMAKE_VS_PLATFORM_NAME} arch is not supported!")
endif()

################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    string(CONCAT TARGET_NAME
          $<$<CONFIG:Debug>:${PROJECT_NAME}>
        $<$<CONFIG:Release>:${PROJECT_NAME}>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${PROJECT_NAME}>
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    string(CONCAT TARGET_NAME
          $<$<CONFIG:Debug>:${PROJECT_NAME}>
        $<$<CONFIG:Release>:${PROJECT_NAME}>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${PROJECT_NAME}>
    )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${TARGET_NAME})

################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    string(CONCAT OUT_DIR
          $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}//vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/${PROJECT_NAME}/>
        $<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}//vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/${PROJECT_NAME}/>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${CMAKE_SOURCE_DIR}/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>>
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    string(CONCAT OUT_DIR
          $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}//vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/${PROJECT_NAME}/>
        $<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}//vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/${PROJECT_NAME}/>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${CMAKE_SOURCE_DIR}/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>>
    )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${OUT_DIR})
set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${OUT_DIR})

################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_include_directories(${PROJECT_NAME} PUBLIC 
          "$<$<CONFIG:Debug>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
        "$<$<CONFIG:Release>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC 
          "$<$<CONFIG:Debug>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
        "$<$<CONFIG:Release>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
          "$<$<CONFIG:Debug>:_DEBUG;"
                            "_LIB;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
        "$<$<CONFIG:Release>:_LIB;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
          "$<$<CONFIG:Debug>:_DEBUG;"
                            "_LIB;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
        "$<$<CONFIG:Release>:_LIB;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
              $<$<CONFIG:Debug>:/Od;
                                /RTC1;
                                /MTd;
                                /W3;
                                /Zi;
                                /EHsc
                                >
            $<$<CONFIG:Release>:/GL;
                                /O2;
                                /Ob2;
                                /Oi-;
                                /GF;
                                /MT;
                                /Gy;
                                /W3;
                                /Zi;
                                /EHsc
                                >
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
              $<$<CONFIG:Debug>:/Od;
                                /RTC1;
                                /MTd;
                                /W3;
                                /Zi;
                                /EHsc
                                >
            $<$<CONFIG:Release>:/GL;
                                /O2;
                                /Ob2;
                                /Oi-;
                                /GF;
                                /MT;
                                /Gy;
                                /W3;
                                /Zi;
                                /EHsc
                                >
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        set_target_properties(${PROJECT_NAME} PROPERTIES STATIC_LIBRARY_FLAGS_RELEASE "/LTCG")
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        set_target_properties(${PROJECT_NAME} PROPERTIES STATIC_LIBRARY_FLAGS_RELEASE "/LTCG")
    endif()
endif()



























project(TLibEncoder CXX)

################################################################################
# Source groups
################################################################################
set(Header_Files
    ../../source/Lib/TLibEncoder/AnnexBwrite.h
    ../../source/Lib/TLibEncoder/NALwrite.h
    ../../source/Lib/TLibEncoder/SEIEncoder.h
    ../../source/Lib/TLibEncoder/SEIwrite.h
    ../../source/Lib/TLibEncoder/SyntaxElementWriter.h
    ../../source/Lib/TLibEncoder/TEncAnalyze.h
    ../../source/Lib/TLibEncoder/TEncBinCoder.h
    ../../source/Lib/TLibEncoder/TEncBinCoderCABAC.h
    ../../source/Lib/TLibEncoder/TEncBinCoderCABACCounter.h
    ../../source/Lib/TLibEncoder/TEncCavlc.h
    ../../source/Lib/TLibEncoder/TEncCfg.h
    ../../source/Lib/TLibEncoder/TEncCu.h
    ../../source/Lib/TLibEncoder/TEncEntropy.h
    ../../source/Lib/TLibEncoder/TEncGOP.h
    ../../source/Lib/TLibEncoder/TEncPic.h
    ../../source/Lib/TLibEncoder/TEncPreanalyzer.h
    ../../source/Lib/TLibEncoder/TEncRateCtrl.h
    ../../source/Lib/TLibEncoder/TEncSampleAdaptiveOffset.h
    ../../source/Lib/TLibEncoder/TEncSbac.h
    ../../source/Lib/TLibEncoder/TEncSearch.h
    ../../source/Lib/TLibEncoder/TEncSlice.h
    ../../source/Lib/TLibEncoder/TEncTop.h
    ../../source/Lib/TLibEncoder/WeightPredAnalysis.h
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    ../../source/Lib/TLibEncoder/NALwrite.cpp
    ../../source/Lib/TLibEncoder/SEIEncoder.cpp
    ../../source/Lib/TLibEncoder/SEIwrite.cpp
    ../../source/Lib/TLibEncoder/SyntaxElementWriter.cpp
    ../../source/Lib/TLibEncoder/TEncBinCoderCABAC.cpp
    ../../source/Lib/TLibEncoder/TEncBinCoderCABACCounter.cpp
    ../../source/Lib/TLibEncoder/TEncCavlc.cpp
    ../../source/Lib/TLibEncoder/TEncCu.cpp
    ../../source/Lib/TLibEncoder/TEncEntropy.cpp
    ../../source/Lib/TLibEncoder/TEncGOP.cpp
    ../../source/Lib/TLibEncoder/TEncPic.cpp
    ../../source/Lib/TLibEncoder/TEncPreanalyzer.cpp
    ../../source/Lib/TLibEncoder/TEncRateCtrl.cpp
    ../../source/Lib/TLibEncoder/TEncSampleAdaptiveOffset.cpp
    ../../source/Lib/TLibEncoder/TEncSbac.cpp
    ../../source/Lib/TLibEncoder/TEncSearch.cpp
    ../../source/Lib/TLibEncoder/TEncSlice.cpp
    ../../source/Lib/TLibEncoder/TEncTop.cpp
    ../../source/Lib/TLibEncoder/WeightPredAnalysis.cpp
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${Header_Files}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC TLibCommon)

if(NOT ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32"
     OR "${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64"))
    message(WARNING "${CMAKE_VS_PLATFORM_NAME} arch is not supported!")
endif()

################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    string(CONCAT TARGET_NAME
          $<$<CONFIG:Debug>:${PROJECT_NAME}>
        $<$<CONFIG:Release>:${PROJECT_NAME}>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${PROJECT_NAME}>
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    string(CONCAT TARGET_NAME
          $<$<CONFIG:Debug>:${PROJECT_NAME}>
        $<$<CONFIG:Release>:${PROJECT_NAME}>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${PROJECT_NAME}>
    )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${TARGET_NAME})

################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    string(CONCAT OUT_DIR
          $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}//vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/${PROJECT_NAME}/>
        $<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}//vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/${PROJECT_NAME}/>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${CMAKE_SOURCE_DIR}/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>>
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    string(CONCAT OUT_DIR
          $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}//vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/${PROJECT_NAME}/>
        $<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}//vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/${PROJECT_NAME}/>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${CMAKE_SOURCE_DIR}/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>>
    )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${OUT_DIR})
set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${OUT_DIR})

################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_include_directories(${PROJECT_NAME} PUBLIC 
          "$<$<CONFIG:Debug>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
        "$<$<CONFIG:Release>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC 
          "$<$<CONFIG:Debug>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
        "$<$<CONFIG:Release>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
          "$<$<CONFIG:Debug>:_DEBUG;"
                            "_LIB;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_SCL_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
        "$<$<CONFIG:Release>:_LIB;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_SCL_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
          "$<$<CONFIG:Debug>:_DEBUG;"
                            "_LIB;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_SCL_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
        "$<$<CONFIG:Release>:_LIB;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_SCL_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
              $<$<CONFIG:Debug>:/Od;
                                /RTC1;
                                /MTd;
                                /W3;
                                /Zi;
                                /EHsc
                                >
            $<$<CONFIG:Release>:/GL;
                                /O2;
                                /Ob2;
                                /Oi-;
                                /GF;
                                /MT;
                                /Gy;
                                /W3;
                                /Zi;
                                /EHsc
                                >
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
              $<$<CONFIG:Debug>:/Od;
                                /RTC1;
                                /MTd;
                                /W3;
                                /Zi;
                                /EHsc
                                >
            $<$<CONFIG:Release>:/GL;
                                /O2;
                                /Ob2;
                                /Oi-;
                                /GF;
                                /MT;
                                /Gy;
                                /W3;
                                /Zi;
                                /EHsc
                                >
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        set_target_properties(${PROJECT_NAME} PROPERTIES STATIC_LIBRARY_FLAGS_RELEASE "/LTCG")
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        set_target_properties(${PROJECT_NAME} PROPERTIES STATIC_LIBRARY_FLAGS_RELEASE "/LTCG")
    endif()
endif()



























project(TLibVideoIO CXX)

################################################################################
# Source groups
################################################################################
set(Header_Files
    ../../source/Lib/TLibVideoIO/TVideoIOYuv.h
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    ../../source/Lib/TLibVideoIO/TVideoIOYuv.cpp
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${Header_Files}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

if(NOT ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32"
     OR "${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64"))
    message(WARNING "${CMAKE_VS_PLATFORM_NAME} arch is not supported!")
endif()

################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    string(CONCAT TARGET_NAME
          $<$<CONFIG:Debug>:${PROJECT_NAME}>
        $<$<CONFIG:Release>:${PROJECT_NAME}>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${PROJECT_NAME}>
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    string(CONCAT TARGET_NAME
          $<$<CONFIG:Debug>:${PROJECT_NAME}>
        $<$<CONFIG:Release>:${PROJECT_NAME}>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${PROJECT_NAME}>
    )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${TARGET_NAME})

################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    string(CONCAT OUT_DIR
          $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}//vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/${PROJECT_NAME}/>
        $<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}//vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/${PROJECT_NAME}/>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${CMAKE_SOURCE_DIR}/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>>
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    string(CONCAT OUT_DIR
          $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}//vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/${PROJECT_NAME}/>
        $<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}//vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/${PROJECT_NAME}/>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${CMAKE_SOURCE_DIR}/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>>
    )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${OUT_DIR})
set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${OUT_DIR})

################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_include_directories(${PROJECT_NAME} PUBLIC 
          "$<$<CONFIG:Debug>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
        "$<$<CONFIG:Release>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC 
          "$<$<CONFIG:Debug>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
        "$<$<CONFIG:Release>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
          "$<$<CONFIG:Debug>:_DEBUG;"
                            "_LIB;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
        "$<$<CONFIG:Release>:_LIB;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
          "$<$<CONFIG:Debug>:_DEBUG;"
                            "_LIB;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
        "$<$<CONFIG:Release>:_LIB;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
              $<$<CONFIG:Debug>:/Od;
                                /RTC1;
                                /MTd;
                                /W3;
                                /Zi;
                                /EHsc
                                >
            $<$<CONFIG:Release>:/GL;
                                /O2;
                                /Ob2;
                                /Oi-;
                                /GF;
                                /MT;
                                /Gy;
                                /W3;
                                /Zi;
                                /EHsc
                                >
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
              $<$<CONFIG:Debug>:/Od;
                                /RTC1;
                                /MTd;
                                /W3;
                                /Zi;
                                /EHsc
                                >
            $<$<CONFIG:Release>:/GL;
                                /O2;
                                /Ob2;
                                /Oi-;
                                /GF;
                                /MT;
                                /Gy;
                                /W3;
                                /Zi;
                                /EHsc
                                >
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        set_target_properties(${PROJECT_NAME} PROPERTIES STATIC_LIBRARY_FLAGS_RELEASE "/LTCG")
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        set_target_properties(${PROJECT_NAME} PROPERTIES STATIC_LIBRARY_FLAGS_RELEASE "/LTCG")
    endif()
endif()



























project(TAppDecoderAnalyser CXX)

################################################################################
# Source groups
################################################################################
set(Header_Files
    ../../source/App/TAppDecoder/TAppDecCfg.h
    ../../source/App/TAppDecoder/TAppDecTop.h
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    ../../source/App/TAppDecoder/decmain.cpp
    ../../source/App/TAppDecoder/TAppDecCfg.cpp
    ../../source/App/TAppDecoder/TAppDecTop.cpp
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${Header_Files}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})

if(NOT ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32"
     OR "${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64"))
    message(WARNING "${CMAKE_VS_PLATFORM_NAME} arch is not supported!")
endif()

################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    string(CONCAT TARGET_NAME
          $<$<CONFIG:Debug>:${PROJECT_NAME}>
        $<$<CONFIG:Release>:${PROJECT_NAME}>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${PROJECT_NAME}>
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    string(CONCAT TARGET_NAME
          $<$<CONFIG:Debug>:${PROJECT_NAME}>
        $<$<CONFIG:Release>:${PROJECT_NAME}>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${PROJECT_NAME}>
    )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${TARGET_NAME})

################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    string(CONCAT OUT_DIR
          $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}//../bin/vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/>
        $<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}//../bin/vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${CMAKE_SOURCE_DIR}/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>>
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    string(CONCAT OUT_DIR
          $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}//../bin/vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/>
        $<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}//../bin/vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${CMAKE_SOURCE_DIR}/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>>
    )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR})

################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_include_directories(${PROJECT_NAME} PUBLIC 
          "$<$<CONFIG:Debug>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
        "$<$<CONFIG:Release>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC 
          "$<$<CONFIG:Debug>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
        "$<$<CONFIG:Release>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
          "$<$<CONFIG:Debug>:_DEBUG;"
                            "_CONSOLE;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "RExt__DECODER_DEBUG_BIT_STATISTICS=1;"
                            "_MBCS"
                            ">"
        "$<$<CONFIG:Release>:_CONSOLE;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "RExt__DECODER_DEBUG_BIT_STATISTICS=1;"
                            "_MBCS"
                            ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
          "$<$<CONFIG:Debug>:_DEBUG;"
                            "_CONSOLE;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
        "$<$<CONFIG:Release>:_CONSOLE;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
              $<$<CONFIG:Debug>:/Od;
                                /RTC1;
                                /MTd;
                                /W3;
                                /Zi;
                                /EHsc
                                >
            $<$<CONFIG:Release>:/GL;
                                /O2;
                                /Ob2;
                                /Oi-;
                                /GF;
                                /MT;
                                /Gy;
                                /W3;
                                /Zi;
                                /EHsc
                                >
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
              $<$<CONFIG:Debug>:/Od;
                                /RTC1;
                                /MTd;
                                /W3;
                                /Zi;
                                /EHsc
                                >
            $<$<CONFIG:Release>:/GL;
                                /O2;
                                /Ob2;
                                /Oi-;
                                /GF;
                                /MT;
                                /Gy;
                                /W3;
                                /Zi;
                                /EHsc
                                >
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG "/DEBUG /INCREMENTAL")
        set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE "/LTCG /DEBUG /INCREMENTAL:NO")
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG "/DEBUG /INCREMENTAL")
        set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE "/LTCG /DEBUG /INCREMENTAL:NO")
    endif()
endif()

################################################################################
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
    TAppCommon
    TLibCommon
    TLibDecoderAnalyser
    TLibVideoIO
)

# Link with other targets.
target_link_libraries(${PROJECT_NAME} PUBLIC
    TAppCommon
    TLibCommon
    TLibDecoderAnalyser
    TLibVideoIO
)



























project(TLibDecoderAnalyser CXX)

################################################################################
# Source groups
################################################################################
set(Header_Files
    ../../source/Lib/TLibDecoder/AnnexBread.h
    ../../source/Lib/TLibDecoder/NALread.h
    ../../source/Lib/TLibDecoder/SEIread.h
    ../../source/Lib/TLibDecoder/SyntaxElementParser.h
    ../../source/Lib/TLibDecoder/TDecBinCoder.h
    ../../source/Lib/TLibDecoder/TDecBinCoderCABAC.h
    ../../source/Lib/TLibDecoder/TDecCAVLC.h
    ../../source/Lib/TLibDecoder/TDecConformance.h
    ../../source/Lib/TLibDecoder/TDecCu.h
    ../../source/Lib/TLibDecoder/TDecEntropy.h
    ../../source/Lib/TLibDecoder/TDecGop.h
    ../../source/Lib/TLibDecoder/TDecSbac.h
    ../../source/Lib/TLibDecoder/TDecSlice.h
    ../../source/Lib/TLibDecoder/TDecTop.h
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    ../../source/Lib/TLibDecoder/AnnexBread.cpp
    ../../source/Lib/TLibDecoder/NALread.cpp
    ../../source/Lib/TLibDecoder/SEIread.cpp
    ../../source/Lib/TLibDecoder/SyntaxElementParser.cpp
    ../../source/Lib/TLibDecoder/TDecBinCoderCABAC.cpp
    ../../source/Lib/TLibDecoder/TDecCAVLC.cpp
    ../../source/Lib/TLibDecoder/TDecConformance.cpp
    ../../source/Lib/TLibDecoder/TDecCu.cpp
    ../../source/Lib/TLibDecoder/TDecEntropy.cpp
    ../../source/Lib/TLibDecoder/TDecGop.cpp
    ../../source/Lib/TLibDecoder/TDecSbac.cpp
    ../../source/Lib/TLibDecoder/TDecSlice.cpp
    ../../source/Lib/TLibDecoder/TDecTop.cpp
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${Header_Files}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC TLibDecoder)

if(NOT ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32"
     OR "${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64"))
    message(WARNING "${CMAKE_VS_PLATFORM_NAME} arch is not supported!")
endif()

################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    string(CONCAT TARGET_NAME
          $<$<CONFIG:Debug>:${PROJECT_NAME}>
        $<$<CONFIG:Release>:${PROJECT_NAME}>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${PROJECT_NAME}>
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    string(CONCAT TARGET_NAME
          $<$<CONFIG:Debug>:${PROJECT_NAME}>
        $<$<CONFIG:Release>:${PROJECT_NAME}>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${PROJECT_NAME}>
    )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${TARGET_NAME})

################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    string(CONCAT OUT_DIR
          $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}//vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/${PROJECT_NAME}/>
        $<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}//vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/${PROJECT_NAME}/>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${CMAKE_SOURCE_DIR}/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>>
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    string(CONCAT OUT_DIR
          $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}//vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/${PROJECT_NAME}/>
        $<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}//vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/${PROJECT_NAME}/>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${CMAKE_SOURCE_DIR}/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>>
    )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${OUT_DIR})
set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${OUT_DIR})

################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_include_directories(${PROJECT_NAME} PUBLIC 
          "$<$<CONFIG:Debug>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
        "$<$<CONFIG:Release>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC 
          "$<$<CONFIG:Debug>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
        "$<$<CONFIG:Release>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
          "$<$<CONFIG:Debug>:_DEBUG;"
                            "_LIB;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "RExt__DECODER_DEBUG_BIT_STATISTICS=1;"
                            "_MBCS"
                            ">"
        "$<$<CONFIG:Release>:_LIB;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "RExt__DECODER_DEBUG_BIT_STATISTICS=1;"
                            "_MBCS"
                            ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
          "$<$<CONFIG:Debug>:_DEBUG;"
                            "_LIB;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
        "$<$<CONFIG:Release>:_LIB;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
              $<$<CONFIG:Debug>:/Od;
                                /RTC1;
                                /MTd;
                                /W3;
                                /Zi;
                                /EHsc
                                >
            $<$<CONFIG:Release>:/GL;
                                /O2;
                                /Ob2;
                                /Oi-;
                                /GF;
                                /MT;
                                /Gy;
                                /W3;
                                /Zi;
                                /EHsc
                                >
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
              $<$<CONFIG:Debug>:/Od;
                                /RTC1;
                                /MTd;
                                /W3;
                                /Zi;
                                /EHsc
                                >
            $<$<CONFIG:Release>:/GL;
                                /O2;
                                /Ob2;
                                /Oi-;
                                /GF;
                                /MT;
                                /Gy;
                                /W3;
                                /Zi;
                                /EHsc
                                >
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        set_target_properties(${PROJECT_NAME} PROPERTIES STATIC_LIBRARY_FLAGS_RELEASE "/LTCG")
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        set_target_properties(${PROJECT_NAME} PROPERTIES STATIC_LIBRARY_FLAGS_RELEASE "/LTCG")
    endif()
endif()



























project(TAppMctsExtractor CXX)

################################################################################
# Source groups
################################################################################
set(Header_Files
    ../../source/App/TAppMCTSExtractor/TAppMctsExtCfg.h
    ../../source/App/TAppMCTSExtractor/TAppMctsExtTop.h
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    ../../source/App/TAppMCTSExtractor/mctsExtmain.cpp
    ../../source/App/TAppMCTSExtractor/TAppMctsExtCfg.cpp
    ../../source/App/TAppMCTSExtractor/TAppMctsExtTop.cpp
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${Header_Files}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})

if(NOT ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32"
     OR "${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64"))
    message(WARNING "${CMAKE_VS_PLATFORM_NAME} arch is not supported!")
endif()

################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    string(CONCAT TARGET_NAME
          $<$<CONFIG:Debug>:${PROJECT_NAME}>
        $<$<CONFIG:Release>:${PROJECT_NAME}>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${PROJECT_NAME}>
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    string(CONCAT TARGET_NAME
          $<$<CONFIG:Debug>:${PROJECT_NAME}>
        $<$<CONFIG:Release>:${PROJECT_NAME}>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${PROJECT_NAME}>
    )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${TARGET_NAME})

################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    string(CONCAT OUT_DIR
          $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}//../bin/vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/>
        $<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}//../bin/vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${CMAKE_SOURCE_DIR}/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>>
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    string(CONCAT OUT_DIR
          $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}//../bin/vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/>
        $<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}//../bin/vc2015/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/>
        $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${CMAKE_SOURCE_DIR}/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>>
    )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR})

################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_include_directories(${PROJECT_NAME} PUBLIC
          "$<$<CONFIG:Debug>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
        "$<$<CONFIG:Release>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC
          "$<$<CONFIG:Debug>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
        "$<$<CONFIG:Release>:${CMAKE_CURRENT_SOURCE_DIR}/../../source/Lib>"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
          "$<$<CONFIG:Debug>:_DEBUG;"
                            "_CONSOLE;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
        "$<$<CONFIG:Release>:_CONSOLE;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
          "$<$<CONFIG:Debug>:_MBCS;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
        "$<$<CONFIG:Release>:_MBCS;"
                            "_CRT_SECURE_NO_WARNINGS;"
                            "_MBCS"
                            ">"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        target_compile_options(${PROJECT_NAME} PRIVATE
              $<$<CONFIG:Debug>:/Od;
                                /MTd;
                                /W3;
                                /Zi;
                                /EHsc
                                >
            $<$<CONFIG:Release>:/GL;
                                /O2;
                                /Oi;
                                /MT;
                                /Gy;
                                /W3;
                                /EHsc
                                >
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
              $<$<CONFIG:Debug>:/Od;
                                /MTd;
                                /W3;
                                /Zi;
                                /EHsc
                                >
            $<$<CONFIG:Release>:/GL;
                                /O2;
                                /Oi;
                                /MT;
                                /Gy;
                                /W3;
                                /EHsc
                                >
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
        set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG "/DEBUG")
        set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE "/LTCG /DEBUG:FULL")
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG "/DEBUG:FULL")
        set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE "/LTCG /DEBUG:FULL")
    endif()
endif()

################################################################################
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
    TAppCommon
    TLibCommon
    TLibDecoder
    TLibEncoder
    TLibVideoIO
)

# Link with other targets.
target_link_libraries(${PROJECT_NAME} PUBLIC
    TAppCommon
    TLibCommon
    TLibDecoder
    TLibEncoder
    TLibVideoIO
)




















project(combined CXX)
set(SOURCE_FILES
        ../../source/combined/testmain.cpp
        )
set(ALL_FILES
        ${SOURCE_FILES}
        )

message(WARNING ${CMAKE_SOURCE_DIR} ${PROJECT_NAME})

add_executable(${PROJECT_NAME} ${ALL_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_SOURCE_DIR}/../source/Lib
        )
add_dependencies(${PROJECT_NAME} TLibEncoder)
target_link_libraries(${PROJECT_NAME} TLibEncoder)
