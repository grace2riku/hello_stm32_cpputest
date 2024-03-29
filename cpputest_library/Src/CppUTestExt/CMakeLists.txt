set(CppUTestExt_src
        CodeMemoryReportFormatter.cpp
        GTest.cpp
        IEEE754ExceptionsPlugin.cpp
        MemoryReporterPlugin.cpp
        MockFailure.cpp
        MockSupportPlugin.cpp
        MockActualCall.cpp
        MockSupport_c.cpp
        MemoryReportAllocator.cpp
        MockExpectedCall.cpp
        MockNamedValue.cpp
        OrderedTest.cpp
        MemoryReportFormatter.cpp
        MockExpectedCallsList.cpp
        MockSupport.cpp
)

set(CppUTestExt_headers
        ${CppUTestRootDirectory}/include/CppUTestExt/CodeMemoryReportFormatter.h
        ${CppUTestRootDirectory}/include/CppUTestExt/IEEE754ExceptionsPlugin.h
        ${CppUTestRootDirectory}/include/CppUTestExt/MemoryReportAllocator.h
        ${CppUTestRootDirectory}/include/CppUTestExt/MockExpectedCall.h
        ${CppUTestRootDirectory}/include/CppUTestExt/MockCheckedExpectedCall.h
        ${CppUTestRootDirectory}/include/CppUTestExt/MockExpectedCallsList.h
        ${CppUTestRootDirectory}/include/CppUTestExt/MockSupportPlugin.h
        ${CppUTestRootDirectory}/include/CppUTestExt/MemoryReportFormatter.h
        ${CppUTestRootDirectory}/include/CppUTestExt/MockFailure.h
        ${CppUTestRootDirectory}/include/CppUTestExt/MockSupport.h
        ${CppUTestRootDirectory}/include/CppUTestExt/MockSupport_c.h
        ${CppUTestRootDirectory}/include/CppUTestExt/GMock.h
        ${CppUTestRootDirectory}/include/CppUTestExt/GTest.h
        ${CppUTestRootDirectory}/include/CppUTestExt/GTestSupport.h
        ${CppUTestRootDirectory}/include/CppUTestExt/MemoryReporterPlugin.h
        ${CppUTestRootDirectory}/include/CppUTestExt/OrderedTest.h
        ${CppUTestRootDirectory}/include/CppUTestExt/GTestConvertor.h
        ${CppUTestRootDirectory}/include/CppUTestExt/MockActualCall.h
        ${CppUTestRootDirectory}/include/CppUTestExt/MockCheckedActualCall.h
        ${CppUTestRootDirectory}/include/CppUTestExt/MockNamedValue.h
        ${CppUTestRootDirectory}/include/CppUTestExt/MockSupport.h
)

add_library(${CppUTestExtLibName} STATIC ${CppUTestExt_src} ${CppUTestExt_headers})
target_link_libraries(${CppUTestExtLibName} ${CPPUNIT_EXTERNAL_LIBRARIES})

target_link_libraries(${CppUTestExtLibName} PUBLIC ${CppUTestLibName})

if(LIBNAME_POSTFIX_DEBUG)
    set_target_properties(${CppUTestExtLibName} PROPERTIES DEBUG_POSTFIX "d")
endif()

#[[Arrange for the include directory to be added to the include paths of any CMake target depending on CppUTestExt.]]
target_include_directories(${CppUTestExtLibName}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
        $<INSTALL_INTERFACE:include>
)

set_target_properties(${CppUTestExtLibName} PROPERTIES
    PUBLIC_HEADER "${CppUTestExt_headers}")
install(TARGETS ${CppUTestExtLibName}
    EXPORT CppUTestTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/CppUTestExt"
    PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/CppUTestExt")
