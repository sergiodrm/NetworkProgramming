// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Cars/Game/GameCamera.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameCamera() {}
// Cross Module References
	CARS_API UClass* Z_Construct_UClass_AGameCamera_NoRegister();
	CARS_API UClass* Z_Construct_UClass_AGameCamera();
	ENGINE_API UClass* Z_Construct_UClass_ACameraActor();
	UPackage* Z_Construct_UPackage__Script_Cars();
// End Cross Module References
	void AGameCamera::StaticRegisterNativesAGameCamera()
	{
	}
	UClass* Z_Construct_UClass_AGameCamera_NoRegister()
	{
		return AGameCamera::StaticClass();
	}
	struct Z_Construct_UClass_AGameCamera_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_minDistance_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_minDistance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_distanceFromVelocityFactor_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_distanceFromVelocityFactor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGameCamera_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACameraActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Cars,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameCamera_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Input Rendering" },
		{ "IncludePath", "Game/GameCamera.h" },
		{ "ModuleRelativePath", "Game/GameCamera.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameCamera_Statics::NewProp_m_minDistance_MetaData[] = {
		{ "Category", "GameCamera" },
		{ "ModuleRelativePath", "Game/GameCamera.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGameCamera_Statics::NewProp_m_minDistance = { "m_minDistance", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGameCamera, m_minDistance), METADATA_PARAMS(Z_Construct_UClass_AGameCamera_Statics::NewProp_m_minDistance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGameCamera_Statics::NewProp_m_minDistance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameCamera_Statics::NewProp_m_distanceFromVelocityFactor_MetaData[] = {
		{ "Category", "GameCamera" },
		{ "ModuleRelativePath", "Game/GameCamera.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGameCamera_Statics::NewProp_m_distanceFromVelocityFactor = { "m_distanceFromVelocityFactor", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGameCamera, m_distanceFromVelocityFactor), METADATA_PARAMS(Z_Construct_UClass_AGameCamera_Statics::NewProp_m_distanceFromVelocityFactor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGameCamera_Statics::NewProp_m_distanceFromVelocityFactor_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGameCamera_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameCamera_Statics::NewProp_m_minDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameCamera_Statics::NewProp_m_distanceFromVelocityFactor,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGameCamera_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGameCamera>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGameCamera_Statics::ClassParams = {
		&AGameCamera::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AGameCamera_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AGameCamera_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AGameCamera_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGameCamera_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGameCamera()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGameCamera_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGameCamera, 4289214993);
	template<> CARS_API UClass* StaticClass<AGameCamera>()
	{
		return AGameCamera::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGameCamera(Z_Construct_UClass_AGameCamera, &AGameCamera::StaticClass, TEXT("/Script/Cars"), TEXT("AGameCamera"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGameCamera);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
