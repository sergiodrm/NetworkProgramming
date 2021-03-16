// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef CARS_CheckPoint_generated_h
#error "CheckPoint.generated.h already included, missing '#pragma once' in CheckPoint.h"
#endif
#define CARS_CheckPoint_generated_h

#define CarsOnline_Source_Cars_Game_CheckPoint_h_12_SPARSE_DATA
#define CarsOnline_Source_Cars_Game_CheckPoint_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define CarsOnline_Source_Cars_Game_CheckPoint_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define CarsOnline_Source_Cars_Game_CheckPoint_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACheckPoint(); \
	friend struct Z_Construct_UClass_ACheckPoint_Statics; \
public: \
	DECLARE_CLASS(ACheckPoint, ATriggerBox, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Cars"), NO_API) \
	DECLARE_SERIALIZER(ACheckPoint)


#define CarsOnline_Source_Cars_Game_CheckPoint_h_12_INCLASS \
private: \
	static void StaticRegisterNativesACheckPoint(); \
	friend struct Z_Construct_UClass_ACheckPoint_Statics; \
public: \
	DECLARE_CLASS(ACheckPoint, ATriggerBox, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Cars"), NO_API) \
	DECLARE_SERIALIZER(ACheckPoint)


#define CarsOnline_Source_Cars_Game_CheckPoint_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACheckPoint(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACheckPoint) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACheckPoint); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACheckPoint); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACheckPoint(ACheckPoint&&); \
	NO_API ACheckPoint(const ACheckPoint&); \
public:


#define CarsOnline_Source_Cars_Game_CheckPoint_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACheckPoint(ACheckPoint&&); \
	NO_API ACheckPoint(const ACheckPoint&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACheckPoint); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACheckPoint); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACheckPoint)


#define CarsOnline_Source_Cars_Game_CheckPoint_h_12_PRIVATE_PROPERTY_OFFSET
#define CarsOnline_Source_Cars_Game_CheckPoint_h_9_PROLOG
#define CarsOnline_Source_Cars_Game_CheckPoint_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CarsOnline_Source_Cars_Game_CheckPoint_h_12_PRIVATE_PROPERTY_OFFSET \
	CarsOnline_Source_Cars_Game_CheckPoint_h_12_SPARSE_DATA \
	CarsOnline_Source_Cars_Game_CheckPoint_h_12_RPC_WRAPPERS \
	CarsOnline_Source_Cars_Game_CheckPoint_h_12_INCLASS \
	CarsOnline_Source_Cars_Game_CheckPoint_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define CarsOnline_Source_Cars_Game_CheckPoint_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CarsOnline_Source_Cars_Game_CheckPoint_h_12_PRIVATE_PROPERTY_OFFSET \
	CarsOnline_Source_Cars_Game_CheckPoint_h_12_SPARSE_DATA \
	CarsOnline_Source_Cars_Game_CheckPoint_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	CarsOnline_Source_Cars_Game_CheckPoint_h_12_INCLASS_NO_PURE_DECLS \
	CarsOnline_Source_Cars_Game_CheckPoint_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CARS_API UClass* StaticClass<class ACheckPoint>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID CarsOnline_Source_Cars_Game_CheckPoint_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
