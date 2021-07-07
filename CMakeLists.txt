project( newcubofinalfinal )

message( "Configuring main application - ${PROJECT_NAME} : " )

# OpenGL
find_package(OpenGL REQUIRED)

file(GLOB SOURCES "*.cpp" ${DEPENDENCY_DIR}/include/glad/glad/glad.c "Solver/*.cpp" )
file(GLOB HEADERS "*.h" "Solver/*.h")
file(GLOB SHADERS "*.vert" "*.frag" "*.vs" "*.fs" )

include_directories( 
${DEPENDENCY_DIR}/include/glad/ 
${DEPENDENCY_DIR}/include/glfw/
${DEPENDENCY_DIR}/include/freeimage/
${DEPENDENCY_DIR}/include/glew
${DEPENDENCY_DIR}/include/glm
${DEPENDENCY_DIR}/include/freeglut

)

message( "\nBuild mode test is: ${CMAKE_BUILD_TYPE}" )

if ( CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("\nOpenGL_GLUT_GLFW_Program -- Debug mode ****************")
	link_directories(
	${DEPENDENCY_DIR}/lib/glad/Debug/
	${DEPENDENCY_DIR}/lib/glfw/Debug/
	${DEPENDENCY_DIR}/lib/freeglut/Debug/
	${DEPENDENCY_DIR}/lib/freeimage/Debug/
	${DEPENDENCY_DIR}/lib/glew/Debug/
	${DEPENDENCY_DIR}/lib/glm/Debug/
	)
else()
    message("\nOpenGL_GLUT_GLFW_Program -- Release mode ****************")
	link_directories(
	${DEPENDENCY_DIR}/lib/glad/Release/
	${DEPENDENCY_DIR}/lib/glfw/Release/
	${DEPENDENCY_DIR}/lib/freeglut/Release/
	${DEPENDENCY_DIR}/lib/freeimage/Release/
	${DEPENDENCY_DIR}/lib/glew/Release/
	${DEPENDENCY_DIR}/lib/glm/Release/
	)
endif ()
 
add_executable( ${PROJECT_NAME}  ${HEADERS} ${SOURCES} ${SHADERS} )

if ( CMAKE_BUILD_TYPE STREQUAL "Debug")
	if ( WIN32 )
	    message("\nOpenGL_GLUT_GLFW_Program -- Debug mode Windows ****************")
		target_link_libraries( ${PROJECT_NAME} 
						   opengl32
						   freeglut_staticd.lib
						   glad.lib
	                       glfw3.lib
						   glew32d.lib
						   FreeImaged.lib
						   glm_static.lib
						    )
	else()
		message("\nOpenGL_GLUT_GLFW_Program -- Debug mode Linux ****************")
		target_link_libraries( ${PROJECT_NAME} 
						   ${OPENGL_LIBRARY}
							-lm
							-lGL
							-lGLU
							-lX11
							-lXi
							-lXxf86vm 
							-lXrandr 
							-pthread 
							-ldl
							-lm
						   libglad.a
	                       libglfw3.a
						   libGLEWd.a
						   libglut.a
						   libfreeimage.a
						   libglm_static.a
						    )
	endif()					    	
else()
	if ( WIN32 )
		message("\nOpenGL_GLUT_GLFW_Program -- Release mode Windows ****************")
		target_link_libraries( ${PROJECT_NAME} 
						   opengl32
						   freeglut_static.lib
						   glad.lib
	                       glfw3.lib
						   glew32.lib
						   FreeImage.lib
						   glm_static.lib
						    )
	else()
		message("\nOpenGL_GLUT_GLFW_Program -- Release mode Linux ****************")
		target_link_libraries( ${PROJECT_NAME} 
						  ${OPENGL_LIBRARY}
							-lm
							-lGL
							-lGLU
							-lX11
							-lXi
							-lXxf86vm 
							-lXrandr 
							-pthread 
							-ldl
							-lm
						   libglad.a
	                       libglfw3.a
						   libGLEW.a
						   libglut.a
						   libfreeimage.a
						   libglm_static.a
						    )
	endif()	
endif ()                      