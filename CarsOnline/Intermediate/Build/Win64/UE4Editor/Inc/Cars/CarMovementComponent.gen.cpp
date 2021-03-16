// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Cars/Game/CarMovementComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCarMovementComponent() {}
// Cross Module References
	CARS_API UClass* Z_Construct_UClass_UCarMovementComponent_NoRegister();
	CARS_API UClass* Z_Construct_UClass_UCarMovementComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_Cars();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	void UCarMovementComponent::StaticRegisterNativesUCarMovementComponent()
	{
	}
	UClass* Z_Construct_UClass_UCarMovementComponent_NoRegister()
	{
		return UCarMovementComponent::StaticClass();
	}
	struct Z_Construct_UClass_UCarMovementComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_acceleration_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_acceleration;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_rotationFactor_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_rotationFactor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_brake_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_brake;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_drag_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_drag;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_maxVelocity_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_maxVelocity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_movementInput_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_m_movementInput;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_velocity_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_m_velocity;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCarMovementComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_Cars,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCarMovementComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Game/CarMovementComponent.h" },
		{ "ModuleRelativePath", "Game/CarMovementComponent.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_acceleration_MetaData[] = {
		{ "Category", "CarMovementComponent" },
		{ "ModuleRelativePath", "Game/CarMovementComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_acceleration = { "m_acceleration", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCarMovementComponent, m_acceleration), METADATA_PARAMS(Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_acceleration_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_acceleration_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_rotationFactor_MetaData[] = {
		{ "Category", "CarMovementComponent" },
		{ "ModuleRelativePath", "Game/CarMovementComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_rotationFactor = { "m_rotationFactor", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCarMovementComponent, m_rotationFactor), METADATA_PARAMS(Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_rotationFactor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_rotationFactor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_brake_MetaData[] = {
		{ "Category", "CarMovementComponent" },
		{ "ModuleRelativePath", "Game/CarMovementComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_brake = { "m_brake", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCarMovementComponent, m_brake), METADATA_PARAMS(Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_brake_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_brake_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_drag_MetaData[] = {
		{ "Category", "CarMovementComponent" },
		{ "ModuleRelativePath", "Game/CarMovementComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_drag = { "m_drag", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCarMovementComponent, m_drag), METADATA_PARAMS(Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_drag_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_drag_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_maxVelocity_MetaData[] = {
		{ "Category", "CarMovementComponent" },
		{ "ModuleRelativePath", "Game/CarMovementComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_maxVelocity = { "m_maxVelocity", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCarMovementComponent, m_maxVelocity), METADATA_PARAMS(Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_maxVelocity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_maxVelocity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_movementInput_MetaData[] = {
		{ "Category", "CarMovementComponent" },
		{ "ModuleRelativePath", "Game/CarMovementComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_movementInput = { "m_movementInput", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCarMovementComponent, m_movementInput), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_movementInput_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_movementInput_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_velocity_MetaData[] = {
		{ "Category", "CarMovementComponent" },
		{ "ModuleRelativePath", "Game/CarMovementComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_velocity = { "m_velocity", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCarMovementComponent, m_velocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_velocity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_velocity_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCarMovementComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_acceleration,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_rotationFactor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_brake,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_drag,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_maxVelocity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_movementInput,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCarMovementComponent_Statics::NewProp_m_velocity,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCarMovementComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCarMovementComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCarMovementComponent_Statics::ClassParams = {
		&UCarMovementComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UCarMovementComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UCarMovementComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UCarMovementComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCarMovementComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCarMovementComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCarMovementComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCarMovementComponent, 310790860);
	template<> CARS_API UClass* StaticClass<UCarMovementComponent>()
	{
		return UCarMovementComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCarMovementComponent(Z_Construct_UClass_UCarMovementComponent, &UCarMovementComponent::StaticClass, TEXT("/Script/Cars"), TEXT("UCarMovementComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCarMovementComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
