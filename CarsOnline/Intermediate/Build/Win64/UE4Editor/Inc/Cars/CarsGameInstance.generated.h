// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UUserWidget;
#ifdef CARS_CarsGameInstance_generated_h
#error "CarsGameInstance.generated.h already included, missing '#pragma once' in CarsGameInstance.h"
#endif
#define CARS_CarsGameInstance_generated_h

#define CarsOnline_Source_Cars_CarsGameInstance_h_15_SPARSE_DATA
#define CarsOnline_Source_Cars_CarsGameInstance_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnServerStartButtonClick); \
	DECLARE_FUNCTION(execOnClientButtonClick); \
	DECLARE_FUNCTION(execOnServerButtonClick); \
	DECLARE_FUNCTION(execChangeMenuWidget);


#define CarsOnline_Source_Cars_CarsGameInstance_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnServerStartButtonClick); \
	DECLARE_FUNCTION(execOnClientButtonClick); \
	DECLARE_FUNCTION(execOnServerButtonClick); \
	DECLARE_FUNCTION(execChangeMenuWidget);


#define CarsOnline_Source_Cars_CarsGameInstance_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCarsGameInstance(); \
	friend struct Z_Construct_UClass_UCarsGameInstance_Statics; \
public: \
	DECLARE_CLASS(UCarsGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/Cars"), NO_API) \
	DECLARE_SERIALIZER(UCarsGameInstance)


#define CarsOnline_Source_Cars_CarsGameInstance_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUCarsGameInstance(); \
	friend struct Z_Construct_UClass_UCarsGameInstance_Statics; \
public: \
	DECLARE_CLASS(UCarsGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/Cars"), NO_API) \
	DECLARE_SERIALIZER(UCarsGameInstance)


#define CarsOnline_Source_Cars_CarsGameInstance_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCarsGameInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCarsGameInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCarsGameInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCarsGameInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCarsGameInstance(UCarsGameInstance&&); \
	NO_API UCarsGameInstance(const UCarsGameInstance&); \
public:


#define CarsOnline_Source_Cars_CarsGameInstance_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCarsGameInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCarsGameInstance(UCarsGameInstance&&); \
	NO_API UCarsGameInstance(const UCarsGameInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCarsGameInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCarsGameInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCarsGameInstance)


#define CarsOnline_Source_Cars_CarsGameInstance_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__StartingWidgetClass() { return STRUCT_OFFSET(UCarsGameInstance, StartingWidgetClass); } \
	FORCEINLINE static uint32 __PPO__CurrentWidget() { return STRUCT_OFFSET(UCarsGameInstance, CurrentWidget); }


#define CarsOnline_Source_Cars_CarsGameInstance_h_12_PROLOG
#define CarsOnline_Source_Cars_CarsGameInstance_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CarsOnline_Source_Cars_CarsGameInstance_h_15_PRIVATE_PROPERTY_OFFSET \
	CarsOnline_Source_Cars_CarsGameInstance_h_15_SPARSE_DATA \
	CarsOnline_Source_Cars_CarsGameInstance_h_15_RPC_WRAPPERS \
	CarsOnline_Source_Cars_CarsGameInstance_h_15_INCLASS \
	CarsOnline_Source_Cars_CarsGameInstance_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define CarsOnline_Source_Cars_CarsGameInstance_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CarsOnline_Source_Cars_CarsGameInstance_h_15_PRIVATE_PROPERTY_OFFSET \
	CarsOnline_Source_Cars_CarsGameInstance_h_15_SPARSE_DATA \
	CarsOnline_Source_Cars_CarsGameInstance_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	CarsOnline_Source_Cars_CarsGameInstance_h_15_INCLASS_NO_PURE_DECLS \
	CarsOnline_Source_Cars_CarsGameInstance_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CARS_API UClass* StaticClass<class UCarsGameInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID CarsOnline_Source_Cars_CarsGameInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
