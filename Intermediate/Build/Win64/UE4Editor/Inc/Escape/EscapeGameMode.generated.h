// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ESCAPE_EscapeGameMode_generated_h
#error "EscapeGameMode.generated.h already included, missing '#pragma once' in EscapeGameMode.h"
#endif
#define ESCAPE_EscapeGameMode_generated_h

#define Escape_Source_Escape_EscapeGameMode_h_14_RPC_WRAPPERS
#define Escape_Source_Escape_EscapeGameMode_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define Escape_Source_Escape_EscapeGameMode_h_14_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesAEscapeGameMode(); \
	friend ESCAPE_API class UClass* Z_Construct_UClass_AEscapeGameMode(); \
	public: \
	DECLARE_CLASS(AEscapeGameMode, AGameMode, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, TEXT("/Script/Escape"), NO_API) \
	DECLARE_SERIALIZER(AEscapeGameMode) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Escape_Source_Escape_EscapeGameMode_h_14_INCLASS \
	private: \
	static void StaticRegisterNativesAEscapeGameMode(); \
	friend ESCAPE_API class UClass* Z_Construct_UClass_AEscapeGameMode(); \
	public: \
	DECLARE_CLASS(AEscapeGameMode, AGameMode, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, TEXT("/Script/Escape"), NO_API) \
	DECLARE_SERIALIZER(AEscapeGameMode) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Escape_Source_Escape_EscapeGameMode_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEscapeGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEscapeGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEscapeGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEscapeGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEscapeGameMode(AEscapeGameMode&&); \
	NO_API AEscapeGameMode(const AEscapeGameMode&); \
public:


#define Escape_Source_Escape_EscapeGameMode_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEscapeGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEscapeGameMode(AEscapeGameMode&&); \
	NO_API AEscapeGameMode(const AEscapeGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEscapeGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEscapeGameMode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEscapeGameMode)


#define Escape_Source_Escape_EscapeGameMode_h_14_PRIVATE_PROPERTY_OFFSET
#define Escape_Source_Escape_EscapeGameMode_h_11_PROLOG
#define Escape_Source_Escape_EscapeGameMode_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Escape_Source_Escape_EscapeGameMode_h_14_PRIVATE_PROPERTY_OFFSET \
	Escape_Source_Escape_EscapeGameMode_h_14_RPC_WRAPPERS \
	Escape_Source_Escape_EscapeGameMode_h_14_INCLASS \
	Escape_Source_Escape_EscapeGameMode_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Escape_Source_Escape_EscapeGameMode_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Escape_Source_Escape_EscapeGameMode_h_14_PRIVATE_PROPERTY_OFFSET \
	Escape_Source_Escape_EscapeGameMode_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	Escape_Source_Escape_EscapeGameMode_h_14_INCLASS_NO_PURE_DECLS \
	Escape_Source_Escape_EscapeGameMode_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Escape_Source_Escape_EscapeGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
