cmake_minimum_required(VERSION 3.15)

project(raklite)

include("FetchContent")

FetchContent_Declare(
	"xbyak"    
	GIT_REPOSITORY "https://github.com/herumi/xbyak.git"
	GIT_TAG "ce083a0dcc306c1717685a81f577a4e050193919"
)

FetchContent_Declare( 
	"ktsignal"
	GIT_REPOSITORY "https://github.com/kin4stat/ktsignal.git"
	GIT_TAG "f08a19d9a00ad5284871bf44178d835da7b26ebf"
)

FetchContent_Declare( 
	"kthook"
	GIT_REPOSITORY "https://github.com/kin4stat/kthook.git"
	GIT_TAG "21ca70481273d1efcc98ca49063178e46277009b"
)

FetchContent_MakeAvailable("xbyak" "ktsignal" "kthook")

add_library(${PROJECT_NAME} STATIC)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_sources(${PROJECT_NAME} PRIVATE
    "src/raklite/raklite.cpp"

	"src/RakNet/BitStream.cpp"
	"src/RakNet/DS_HuffmanEncodingTree.cpp"
	"src/RakNet/PluginInterface.cpp"
	"src/RakNet/StringCompressor.cpp"
)

target_link_libraries(${PROJECT_NAME}
    "kthook"
)