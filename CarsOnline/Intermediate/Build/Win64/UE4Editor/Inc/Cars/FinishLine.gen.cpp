// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Cars/Game/FinishLine.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFinishLine() {}
// Cross Module References
	CARS_API UClass* Z_Construct_UClass_AFinishLine_NoRegister();
	CARS_API UClass* Z_Construct_UClass_AFinishLine();
	ENGINE_API UClass* Z_Construct_UClass_ATriggerBox();
	UPackage* Z_Construct_UPackage__Script_Cars();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	CARS_API UClass* Z_Construct_UClass_ACheckPoint_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AFinishLine::execOnOverlapBegin)
	{
		P_GET_OBJECT(AActor,Z_Param_OverlappedActor);
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnOverlapBegin(Z_Param_OverlappedActor,Z_Param_OtherActor);
		P_NATIVE_END;
	}
	void AFinishLine::StaticRegisterNativesAFinishLine()
	{
		UClass* Class = AFinishLine::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnOverlapBegin", &AFinishLine::execOnOverlapBegin },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AFinishLine_OnOverlapBegin_Statics
	{
		struct FinishLine_eventOnOverlapBegin_Parms
		{
			AActor* OverlappedActor;
			AActor* OtherActor;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OverlappedActor;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AFinishLine_OnOverlapBegin_Statics::NewProp_OverlappedActor = { "OverlappedActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FinishLine_eventOnOverlapBegin_Parms, OverlappedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AFinishLine_OnOverlapBegin_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FinishLine_eventOnOverlapBegin_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFinishLine_OnOverlapBegin_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFinishLine_OnOverlapBegin_Statics::NewProp_OverlappedActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFinishLine_OnOverlapBegin_Statics::NewProp_OtherActor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFinishLine_OnOverlapBegin_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// overlap begin function\n" },
		{ "ModuleRelativePath", "Game/FinishLine.h" },
		{ "ToolTip", "overlap begin function" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AFinishLine_OnOverlapBegin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFinishLine, nullptr, "OnOverlapBegin", nullptr, nullptr, sizeof(FinishLine_eventOnOverlapBegin_Parms), Z_Construct_UFunction_AFinishLine_OnOverlapBegin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFinishLine_OnOverlapBegin_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFinishLine_OnOverlapBegin_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFinishLine_OnOverlapBegin_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFinishLine_OnOverlapBegin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AFinishLine_OnOverlapBegin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AFinishLine_NoRegister()
	{
		return AFinishLine::StaticClass();
	}
	struct Z_Construct_UClass_AFinishLine_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_m_vCheckPoints_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_vCheckPoints_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_m_vCheckPoints;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFinishLine_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ATriggerBox,
		(UObject* (*)())Z_Construct_UPackage__Script_Cars,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AFinishLine_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AFinishLine_OnOverlapBegin, "OnOverlapBegin" }, // 4040366557
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFinishLine_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Game/FinishLine.h" },
		{ "ModuleRelativePath", "Game/FinishLine.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFinishLine_Statics::NewProp_m_vCheckPoints_Inner = { "m_vCheckPoints", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_ACheckPoint_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFinishLine_Statics::NewProp_m_vCheckPoints_MetaData[] = {
		{ "Category", "FinishLine" },
		{ "ModuleRelativePath", "Game/FinishLine.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AFinishLine_Statics::NewProp_m_vCheckPoints = { "m_vCheckPoints", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFinishLine, m_vCheckPoints), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AFinishLine_Statics::NewProp_m_vCheckPoints_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFinishLine_Statics::NewProp_m_vCheckPoints_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFinishLine_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFinishLine_Statics::NewProp_m_vCheckPoints_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFinishLine_Statics::NewProp_m_vCheckPoints,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFinishLine_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFinishLine>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFinishLine_Statics::ClassParams = {
		&AFinishLine::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AFinishLine_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AFinishLine_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AFinishLine_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFinishLine_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFinishLine()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFinishLine_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFinishLine, 1938097354);
	template<> CARS_API UClass* StaticClass<AFinishLine>()
	{
		return AFinishLine::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFinishLine(Z_Construct_UClass_AFinishLine, &AFinishLine::StaticClass, TEXT("/Script/Cars"), TEXT("AFinishLine"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFinishLine);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
