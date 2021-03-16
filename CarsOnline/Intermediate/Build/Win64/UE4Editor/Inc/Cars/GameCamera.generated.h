// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CARS_GameCamera_generated_h
#error "GameCamera.generated.h already included, missing '#pragma once' in GameCamera.h"
#endif
#define CARS_GameCamera_generated_h

#define CarsOnline_Source_Cars_Game_GameCamera_h_12_SPARSE_DATA
#define CarsOnline_Source_Cars_Game_GameCamera_h_12_RPC_WRAPPERS
#define CarsOnline_Source_Cars_Game_GameCamera_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define CarsOnline_Source_Cars_Game_GameCamera_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGameCamera(); \
	friend struct Z_Construct_UClass_AGameCamera_Statics; \
public: \
	DECLARE_CLASS(AGameCamera, ACameraActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Cars"), NO_API) \
	DECLARE_SERIALIZER(AGameCamera)


#define CarsOnline_Source_Cars_Game_GameCamera_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAGameCamera(); \
	friend struct Z_Construct_UClass_AGameCamera_Statics; \
public: \
	DECLARE_CLASS(AGameCamera, ACameraActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Cars"), NO_API) \
	DECLARE_SERIALIZER(AGameCamera)


#define CarsOnline_Source_Cars_Game_GameCamera_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGameCamera(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGameCamera) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGameCamera); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGameCamera); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGameCamera(AGameCamera&&); \
	NO_API AGameCamera(const AGameCamera&); \
public:


#define CarsOnline_Source_Cars_Game_GameCamera_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGameCamera(AGameCamera&&); \
	NO_API AGameCamera(const AGameCamera&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGameCamera); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGameCamera); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGameCamera)


#define CarsOnline_Source_Cars_Game_GameCamera_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__m_minDistance() { return STRUCT_OFFSET(AGameCamera, m_minDistance); } \
	FORCEINLINE static uint32 __PPO__m_distanceFromVelocityFactor() { return STRUCT_OFFSET(AGameCamera, m_distanceFromVelocityFactor); }


#define CarsOnline_Source_Cars_Game_GameCamera_h_9_PROLOG
#define CarsOnline_Source_Cars_Game_GameCamera_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CarsOnline_Source_Cars_Game_GameCamera_h_12_PRIVATE_PROPERTY_OFFSET \
	CarsOnline_Source_Cars_Game_GameCamera_h_12_SPARSE_DATA \
	CarsOnline_Source_Cars_Game_GameCamera_h_12_RPC_WRAPPERS \
	CarsOnline_Source_Cars_Game_GameCamera_h_12_INCLASS \
	CarsOnline_Source_Cars_Game_GameCamera_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define CarsOnline_Source_Cars_Game_GameCamera_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CarsOnline_Source_Cars_Game_GameCamera_h_12_PRIVATE_PROPERTY_OFFSET \
	CarsOnline_Source_Cars_Game_GameCamera_h_12_SPARSE_DATA \
	CarsOnline_Source_Cars_Game_GameCamera_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	CarsOnline_Source_Cars_Game_GameCamera_h_12_INCLASS_NO_PURE_DECLS \
	CarsOnline_Source_Cars_Game_GameCamera_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CARS_API UClass* StaticClass<class AGameCamera>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID CarsOnline_Source_Cars_Game_GameCamera_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
