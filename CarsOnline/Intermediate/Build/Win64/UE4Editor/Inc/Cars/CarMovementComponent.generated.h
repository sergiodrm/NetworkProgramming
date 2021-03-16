// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CARS_CarMovementComponent_generated_h
#error "CarMovementComponent.generated.h already included, missing '#pragma once' in CarMovementComponent.h"
#endif
#define CARS_CarMovementComponent_generated_h

#define CarsOnline_Source_Cars_Game_CarMovementComponent_h_13_SPARSE_DATA
#define CarsOnline_Source_Cars_Game_CarMovementComponent_h_13_RPC_WRAPPERS
#define CarsOnline_Source_Cars_Game_CarMovementComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define CarsOnline_Source_Cars_Game_CarMovementComponent_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCarMovementComponent(); \
	friend struct Z_Construct_UClass_UCarMovementComponent_Statics; \
public: \
	DECLARE_CLASS(UCarMovementComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Cars"), NO_API) \
	DECLARE_SERIALIZER(UCarMovementComponent)


#define CarsOnline_Source_Cars_Game_CarMovementComponent_h_13_INCLASS \
private: \
	static void StaticRegisterNativesUCarMovementComponent(); \
	friend struct Z_Construct_UClass_UCarMovementComponent_Statics; \
public: \
	DECLARE_CLASS(UCarMovementComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Cars"), NO_API) \
	DECLARE_SERIALIZER(UCarMovementComponent)


#define CarsOnline_Source_Cars_Game_CarMovementComponent_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCarMovementComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCarMovementComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCarMovementComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCarMovementComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCarMovementComponent(UCarMovementComponent&&); \
	NO_API UCarMovementComponent(const UCarMovementComponent&); \
public:


#define CarsOnline_Source_Cars_Game_CarMovementComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCarMovementComponent(UCarMovementComponent&&); \
	NO_API UCarMovementComponent(const UCarMovementComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCarMovementComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCarMovementComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCarMovementComponent)


#define CarsOnline_Source_Cars_Game_CarMovementComponent_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__m_acceleration() { return STRUCT_OFFSET(UCarMovementComponent, m_acceleration); } \
	FORCEINLINE static uint32 __PPO__m_rotationFactor() { return STRUCT_OFFSET(UCarMovementComponent, m_rotationFactor); } \
	FORCEINLINE static uint32 __PPO__m_brake() { return STRUCT_OFFSET(UCarMovementComponent, m_brake); } \
	FORCEINLINE static uint32 __PPO__m_drag() { return STRUCT_OFFSET(UCarMovementComponent, m_drag); } \
	FORCEINLINE static uint32 __PPO__m_maxVelocity() { return STRUCT_OFFSET(UCarMovementComponent, m_maxVelocity); } \
	FORCEINLINE static uint32 __PPO__m_movementInput() { return STRUCT_OFFSET(UCarMovementComponent, m_movementInput); } \
	FORCEINLINE static uint32 __PPO__m_velocity() { return STRUCT_OFFSET(UCarMovementComponent, m_velocity); }


#define CarsOnline_Source_Cars_Game_CarMovementComponent_h_10_PROLOG
#define CarsOnline_Source_Cars_Game_CarMovementComponent_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CarsOnline_Source_Cars_Game_CarMovementComponent_h_13_PRIVATE_PROPERTY_OFFSET \
	CarsOnline_Source_Cars_Game_CarMovementComponent_h_13_SPARSE_DATA \
	CarsOnline_Source_Cars_Game_CarMovementComponent_h_13_RPC_WRAPPERS \
	CarsOnline_Source_Cars_Game_CarMovementComponent_h_13_INCLASS \
	CarsOnline_Source_Cars_Game_CarMovementComponent_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define CarsOnline_Source_Cars_Game_CarMovementComponent_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CarsOnline_Source_Cars_Game_CarMovementComponent_h_13_PRIVATE_PROPERTY_OFFSET \
	CarsOnline_Source_Cars_Game_CarMovementComponent_h_13_SPARSE_DATA \
	CarsOnline_Source_Cars_Game_CarMovementComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	CarsOnline_Source_Cars_Game_CarMovementComponent_h_13_INCLASS_NO_PURE_DECLS \
	CarsOnline_Source_Cars_Game_CarMovementComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CARS_API UClass* StaticClass<class UCarMovementComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID CarsOnline_Source_Cars_Game_CarMovementComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
