// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ESCAPE_OpenDoor_generated_h
#error "OpenDoor.generated.h already included, missing '#pragma once' in OpenDoor.h"
#endif
#define ESCAPE_OpenDoor_generated_h

#define Escape_Source_Escape_OpenDoor_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execHandleProgress) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->HandleProgress(Z_Param_Value); \
		P_NATIVE_END; \
	}


#define Escape_Source_Escape_OpenDoor_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execHandleProgress) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->HandleProgress(Z_Param_Value); \
		P_NATIVE_END; \
	}


#define Escape_Source_Escape_OpenDoor_h_12_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUOpenDoor(); \
	friend ESCAPE_API class UClass* Z_Construct_UClass_UOpenDoor(); \
	public: \
	DECLARE_CLASS(UOpenDoor, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Escape"), NO_API) \
	DECLARE_SERIALIZER(UOpenDoor) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Escape_Source_Escape_OpenDoor_h_12_INCLASS \
	private: \
	static void StaticRegisterNativesUOpenDoor(); \
	friend ESCAPE_API class UClass* Z_Construct_UClass_UOpenDoor(); \
	public: \
	DECLARE_CLASS(UOpenDoor, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Escape"), NO_API) \
	DECLARE_SERIALIZER(UOpenDoor) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Escape_Source_Escape_OpenDoor_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOpenDoor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOpenDoor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOpenDoor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOpenDoor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOpenDoor(UOpenDoor&&); \
	NO_API UOpenDoor(const UOpenDoor&); \
public:


#define Escape_Source_Escape_OpenDoor_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOpenDoor(UOpenDoor&&); \
	NO_API UOpenDoor(const UOpenDoor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOpenDoor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOpenDoor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UOpenDoor)


#define Escape_Source_Escape_OpenDoor_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__PressurePlate() { return STRUCT_OFFSET(UOpenDoor, PressurePlate); } \
	FORCEINLINE static uint32 __PPO__AudioComp() { return STRUCT_OFFSET(UOpenDoor, AudioComp); }


#define Escape_Source_Escape_OpenDoor_h_9_PROLOG
#define Escape_Source_Escape_OpenDoor_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Escape_Source_Escape_OpenDoor_h_12_PRIVATE_PROPERTY_OFFSET \
	Escape_Source_Escape_OpenDoor_h_12_RPC_WRAPPERS \
	Escape_Source_Escape_OpenDoor_h_12_INCLASS \
	Escape_Source_Escape_OpenDoor_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Escape_Source_Escape_OpenDoor_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Escape_Source_Escape_OpenDoor_h_12_PRIVATE_PROPERTY_OFFSET \
	Escape_Source_Escape_OpenDoor_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	Escape_Source_Escape_OpenDoor_h_12_INCLASS_NO_PURE_DECLS \
	Escape_Source_Escape_OpenDoor_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Escape_Source_Escape_OpenDoor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
