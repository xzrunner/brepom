cmake_minimum_required(VERSION 3.16)

project(brepom)

################################################################################
# Source groups
################################################################################
set(label__attribute
    "include/brepom/AttrColor.h"
    "include/brepom/AttrNamedShape.h"
    "include/brepom/AttrNaming.h"
    "include/brepom/AttrRenderObj.h"
    "include/brepom/AttrPolytope.h"
    "source/AttrColor.cpp"
    "source/AttrNamedShape.cpp"
    "source/AttrNaming.cpp"
    "source/AttrRenderObj.cpp"
    "source/AttrPolytope.cpp"
)
source_group("label\\attribute" FILES ${label__attribute})

set(label__base
    "include/brepom/Attribute.h"
    "include/brepom/Label.h"
    "source/Label.cpp"
)
source_group("label\\base" FILES ${label__base})

set(label__naming
    "include/brepom/LabelBuilder.h"
    "include/brepom/LabelTools.h"
    "source/LabelBuilder.cpp"
    "source/LabelTools.cpp"
)
source_group("label\\naming" FILES ${label__naming})

set(shape__base
    "include/brepom/TopoShape.h"
    "include/brepom/TopoShapeType.h"
)
source_group("shape\\base" FILES ${shape__base})

set(shape__brep
    "include/brepom/TopoBody.h"
    "include/brepom/TopoEdge.h"
    "include/brepom/TopoFace.h"
    "include/brepom/TopoLoop.h"
    "include/brepom/TopoShell.h"
    "include/brepom/TopoVertex.h"
    "source/TopoBody.cpp"
    "source/TopoEdge.cpp"
    "source/TopoFace.cpp"
    "source/TopoLoop.cpp"
    "source/TopoShell.cpp"
    "source/TopoVertex.cpp"
)
source_group("shape\\brep" FILES ${shape__brep})

set(shape__components
    "include/brepom/CompHalfEdge.h"
    "source/CompHalfEdge.cpp"
)
source_group("shape\\components" FILES ${shape__components})

set(shape__tools
    "include/brepom/BRepBuilder.h"
    "include/brepom/BRepExplore.h"
    "include/brepom/PrimBuilder.h"
    "include/brepom/RenderBuilder.h"
    "include/brepom/TopoAdapter.h"
    "source/BRepBuilder.cpp"
    "source/BRepExplore.cpp"
    "source/PrimBuilder.cpp"
    "source/RenderBuilder.cpp"
    "source/TopoAdapter.cpp"
)
source_group("shape\\tools" FILES ${shape__tools})

set(ALL_FILES
    ${label__attribute}
    ${label__base}
    ${label__naming}
    ${shape__base}
    ${shape__brep}
    ${shape__components}
    ${shape__tools}
)

################################################################################
# Target
################################################################################

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/external/objcomp/include)
include_directories(${CMAKE_SOURCE_DIR}/external/sm)
include_directories(${CMAKE_SOURCE_DIR}/external/guard/include)
include_directories(${CMAKE_SOURCE_DIR}/external/halfedge/include)
include_directories(${CMAKE_SOURCE_DIR}/external/polymesh3/include)
include_directories(${CMAKE_SOURCE_DIR}/external/unirender/include)

add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE include external/objcomp/include external/sm external/guard/include external/halfedge/include external/polymesh3/include external/unirender/include)
