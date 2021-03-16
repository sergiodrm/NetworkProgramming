// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Cars/Game/CarsPlayerController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCarsPlayerController() {}
// Cross Module References
	CARS_API UClass* Z_Construct_UClass_ACarsPlayerController_NoRegister();
	CARS_API UClass* Z_Construct_UClass_ACarsPlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_Cars();
// End Cross Module References
	void ACarsPlayerController::StaticRegisterNativesACarsPlayerController()
	{
	}
	UClass* Z_Construct_UClass_ACarsPlayerController_NoRegister()
	{
		return ACarsPlayerController::StaticClass();
	}
	struct Z_Construct_UClass_ACarsPlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACarsPlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_Cars,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACarsPlayerController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Game/CarsPlayerController.h" },
		{ "ModuleRelativePath", "Game/CarsPlayerController.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACarsPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACarsPlayerController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACarsPlayerController_Statics::ClassParams = {
		&ACarsPlayerController::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_ACarsPlayerController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACarsPlayerController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACarsPlayerController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACarsPlayerController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACarsPlayerController, 149932736);
	template<> CARS_API UClass* StaticClass<ACarsPlayerController>()
	{
		return ACarsPlayerController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACarsPlayerController(Z_Construct_UClass_ACarsPlayerController, &ACarsPlayerController::StaticClass, TEXT("/Script/Cars"), TEXT("ACarsPlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACarsPlayerController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
