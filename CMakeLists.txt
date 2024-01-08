cmake_minimum_required(VERSION 3.27)
project(til_cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(til_cpp src/main.cpp
	src/token/token.cpp
	src/token/token.h
	
	src/lexer/lexer.cpp
	src/lexer/lexer.h
	
	src/parser/parser.cpp
	src/parser/parser.h
	
	src/AST/node.cpp
	src/AST/node.h
	
	src/AST/root/root.node.h
	src/AST/root/root.node.cpp
	
	src/AST/constant/constant.node.cpp
	src/AST/constant/constant.node.h
	
	src/AST/operator/binary/binary.node.cpp
	src/AST/operator/binary/binary.node.h
	
	src/AST/operator/unary/unary.node.cpp
	src/AST/operator/unary/unary.node.h
	
	src/AST/variable/variable.node.cpp
	src/AST/variable/variable.node.h
	
	src/types.h
	src/util.h
)
