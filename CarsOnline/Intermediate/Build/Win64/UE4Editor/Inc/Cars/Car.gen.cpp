// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Cars/Game/Car.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCar() {}
// Cross Module References
	CARS_API UClass* Z_Construct_UClass_ACar_NoRegister();
	CARS_API UClass* Z_Construct_UClass_ACar();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_Cars();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	CARS_API UClass* Z_Construct_UClass_UCarMovementComponent_NoRegister();
	CARS_API UClass* Z_Construct_UClass_UNetComponent_NoRegister();
// End Cross Module References
	void ACar::StaticRegisterNativesACar()
	{
	}
	UClass* Z_Construct_UClass_ACar_NoRegister()
	{
		return ACar::StaticClass();
	}
	struct Z_Construct_UClass_ACar_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_pMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_m_pMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_carMovementComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_m_carMovementComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NetComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NetComponent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACar_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_Cars,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACar_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Game/Car.h" },
		{ "ModuleRelativePath", "Game/Car.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACar_Statics::NewProp_m_pMesh_MetaData[] = {
		{ "Category", "Car" },
		{ "Comment", "//Mesh\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Game/Car.h" },
		{ "ToolTip", "Mesh" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACar_Statics::NewProp_m_pMesh = { "m_pMesh", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACar, m_pMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACar_Statics::NewProp_m_pMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACar_Statics::NewProp_m_pMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACar_Statics::NewProp_m_carMovementComponent_MetaData[] = {
		{ "Category", "Car" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Game/Car.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACar_Statics::NewProp_m_carMovementComponent = { "m_carMovementComponent", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACar, m_carMovementComponent), Z_Construct_UClass_UCarMovementComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACar_Statics::NewProp_m_carMovementComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACar_Statics::NewProp_m_carMovementComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACar_Statics::NewProp_NetComponent_MetaData[] = {
		{ "Category", "Car" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Game/Car.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACar_Statics::NewProp_NetComponent = { "NetComponent", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACar, NetComponent), Z_Construct_UClass_UNetComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACar_Statics::NewProp_NetComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACar_Statics::NewProp_NetComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACar_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACar_Statics::NewProp_m_pMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACar_Statics::NewProp_m_carMovementComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACar_Statics::NewProp_NetComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACar_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACar>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACar_Statics::ClassParams = {
		&ACar::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ACar_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ACar_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ACar_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACar_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACar()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACar_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACar, 1631887823);
	template<> CARS_API UClass* StaticClass<ACar>()
	{
		return ACar::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACar(Z_Construct_UClass_ACar, &ACar::StaticClass, TEXT("/Script/Cars"), TEXT("ACar"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACar);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
