// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CARS_Car_generated_h
#error "Car.generated.h already included, missing '#pragma once' in Car.h"
#endif
#define CARS_Car_generated_h

#define CarsOnline_Source_Cars_Game_Car_h_12_SPARSE_DATA
#define CarsOnline_Source_Cars_Game_Car_h_12_RPC_WRAPPERS
#define CarsOnline_Source_Cars_Game_Car_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define CarsOnline_Source_Cars_Game_Car_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACar(); \
	friend struct Z_Construct_UClass_ACar_Statics; \
public: \
	DECLARE_CLASS(ACar, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Cars"), NO_API) \
	DECLARE_SERIALIZER(ACar)


#define CarsOnline_Source_Cars_Game_Car_h_12_INCLASS \
private: \
	static void StaticRegisterNativesACar(); \
	friend struct Z_Construct_UClass_ACar_Statics; \
public: \
	DECLARE_CLASS(ACar, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Cars"), NO_API) \
	DECLARE_SERIALIZER(ACar)


#define CarsOnline_Source_Cars_Game_Car_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACar(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACar) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACar); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACar); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACar(ACar&&); \
	NO_API ACar(const ACar&); \
public:


#define CarsOnline_Source_Cars_Game_Car_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACar(ACar&&); \
	NO_API ACar(const ACar&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACar); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACar); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACar)


#define CarsOnline_Source_Cars_Game_Car_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__m_pMesh() { return STRUCT_OFFSET(ACar, m_pMesh); } \
	FORCEINLINE static uint32 __PPO__m_carMovementComponent() { return STRUCT_OFFSET(ACar, m_carMovementComponent); } \
	FORCEINLINE static uint32 __PPO__NetComponent() { return STRUCT_OFFSET(ACar, NetComponent); }


#define CarsOnline_Source_Cars_Game_Car_h_9_PROLOG
#define CarsOnline_Source_Cars_Game_Car_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CarsOnline_Source_Cars_Game_Car_h_12_PRIVATE_PROPERTY_OFFSET \
	CarsOnline_Source_Cars_Game_Car_h_12_SPARSE_DATA \
	CarsOnline_Source_Cars_Game_Car_h_12_RPC_WRAPPERS \
	CarsOnline_Source_Cars_Game_Car_h_12_INCLASS \
	CarsOnline_Source_Cars_Game_Car_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define CarsOnline_Source_Cars_Game_Car_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CarsOnline_Source_Cars_Game_Car_h_12_PRIVATE_PROPERTY_OFFSET \
	CarsOnline_Source_Cars_Game_Car_h_12_SPARSE_DATA \
	CarsOnline_Source_Cars_Game_Car_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	CarsOnline_Source_Cars_Game_Car_h_12_INCLASS_NO_PURE_DECLS \
	CarsOnline_Source_Cars_Game_Car_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CARS_API UClass* StaticClass<class ACar>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID CarsOnline_Source_Cars_Game_Car_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
