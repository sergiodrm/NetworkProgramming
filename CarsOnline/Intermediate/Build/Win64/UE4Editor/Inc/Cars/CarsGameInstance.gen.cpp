// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Cars/CarsGameInstance.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCarsGameInstance() {}
// Cross Module References
	CARS_API UClass* Z_Construct_UClass_UCarsGameInstance_NoRegister();
	CARS_API UClass* Z_Construct_UClass_UCarsGameInstance();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
	UPackage* Z_Construct_UPackage__Script_Cars();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UCarsGameInstance::execOnServerStartButtonClick)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnServerStartButtonClick();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCarsGameInstance::execOnClientButtonClick)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_sIP);
		P_GET_PROPERTY(FStrProperty,Z_Param_sPort);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnClientButtonClick(Z_Param_sIP,Z_Param_sPort);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCarsGameInstance::execOnServerButtonClick)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_sPort);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnServerButtonClick(Z_Param_sPort);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCarsGameInstance::execChangeMenuWidget)
	{
		P_GET_OBJECT(UClass,Z_Param_NewWidgetClass);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ChangeMenuWidget(Z_Param_NewWidgetClass);
		P_NATIVE_END;
	}
	void UCarsGameInstance::StaticRegisterNativesUCarsGameInstance()
	{
		UClass* Class = UCarsGameInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ChangeMenuWidget", &UCarsGameInstance::execChangeMenuWidget },
			{ "OnClientButtonClick", &UCarsGameInstance::execOnClientButtonClick },
			{ "OnServerButtonClick", &UCarsGameInstance::execOnServerButtonClick },
			{ "OnServerStartButtonClick", &UCarsGameInstance::execOnServerStartButtonClick },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCarsGameInstance_ChangeMenuWidget_Statics
	{
		struct CarsGameInstance_eventChangeMenuWidget_Parms
		{
			TSubclassOf<UUserWidget>  NewWidgetClass;
		};
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_NewWidgetClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UCarsGameInstance_ChangeMenuWidget_Statics::NewProp_NewWidgetClass = { "NewWidgetClass", nullptr, (EPropertyFlags)0x0014000000000080, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CarsGameInstance_eventChangeMenuWidget_Parms, NewWidgetClass), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCarsGameInstance_ChangeMenuWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCarsGameInstance_ChangeMenuWidget_Statics::NewProp_NewWidgetClass,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCarsGameInstance_ChangeMenuWidget_Statics::Function_MetaDataParams[] = {
		{ "Category", "CarsNet" },
		{ "ModuleRelativePath", "CarsGameInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UCarsGameInstance_ChangeMenuWidget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCarsGameInstance, nullptr, "ChangeMenuWidget", nullptr, nullptr, sizeof(CarsGameInstance_eventChangeMenuWidget_Parms), Z_Construct_UFunction_UCarsGameInstance_ChangeMenuWidget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCarsGameInstance_ChangeMenuWidget_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCarsGameInstance_ChangeMenuWidget_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCarsGameInstance_ChangeMenuWidget_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCarsGameInstance_ChangeMenuWidget()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCarsGameInstance_ChangeMenuWidget_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCarsGameInstance_OnClientButtonClick_Statics
	{
		struct CarsGameInstance_eventOnClientButtonClick_Parms
		{
			FString sIP;
			FString sPort;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_sIP;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_sPort;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCarsGameInstance_OnClientButtonClick_Statics::NewProp_sIP = { "sIP", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CarsGameInstance_eventOnClientButtonClick_Parms, sIP), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCarsGameInstance_OnClientButtonClick_Statics::NewProp_sPort = { "sPort", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CarsGameInstance_eventOnClientButtonClick_Parms, sPort), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCarsGameInstance_OnClientButtonClick_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCarsGameInstance_OnClientButtonClick_Statics::NewProp_sIP,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCarsGameInstance_OnClientButtonClick_Statics::NewProp_sPort,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCarsGameInstance_OnClientButtonClick_Statics::Function_MetaDataParams[] = {
		{ "Category", "CarsNet" },
		{ "ModuleRelativePath", "CarsGameInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UCarsGameInstance_OnClientButtonClick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCarsGameInstance, nullptr, "OnClientButtonClick", nullptr, nullptr, sizeof(CarsGameInstance_eventOnClientButtonClick_Parms), Z_Construct_UFunction_UCarsGameInstance_OnClientButtonClick_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCarsGameInstance_OnClientButtonClick_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCarsGameInstance_OnClientButtonClick_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCarsGameInstance_OnClientButtonClick_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCarsGameInstance_OnClientButtonClick()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCarsGameInstance_OnClientButtonClick_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCarsGameInstance_OnServerButtonClick_Statics
	{
		struct CarsGameInstance_eventOnServerButtonClick_Parms
		{
			FString sPort;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_sPort;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCarsGameInstance_OnServerButtonClick_Statics::NewProp_sPort = { "sPort", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CarsGameInstance_eventOnServerButtonClick_Parms, sPort), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCarsGameInstance_OnServerButtonClick_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCarsGameInstance_OnServerButtonClick_Statics::NewProp_sPort,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCarsGameInstance_OnServerButtonClick_Statics::Function_MetaDataParams[] = {
		{ "Category", "CarsNet" },
		{ "ModuleRelativePath", "CarsGameInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UCarsGameInstance_OnServerButtonClick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCarsGameInstance, nullptr, "OnServerButtonClick", nullptr, nullptr, sizeof(CarsGameInstance_eventOnServerButtonClick_Parms), Z_Construct_UFunction_UCarsGameInstance_OnServerButtonClick_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCarsGameInstance_OnServerButtonClick_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCarsGameInstance_OnServerButtonClick_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCarsGameInstance_OnServerButtonClick_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCarsGameInstance_OnServerButtonClick()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCarsGameInstance_OnServerButtonClick_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCarsGameInstance_OnServerStartButtonClick_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCarsGameInstance_OnServerStartButtonClick_Statics::Function_MetaDataParams[] = {
		{ "Category", "CarsNet" },
		{ "ModuleRelativePath", "CarsGameInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UCarsGameInstance_OnServerStartButtonClick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCarsGameInstance, nullptr, "OnServerStartButtonClick", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCarsGameInstance_OnServerStartButtonClick_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCarsGameInstance_OnServerStartButtonClick_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCarsGameInstance_OnServerStartButtonClick()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCarsGameInstance_OnServerStartButtonClick_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UCarsGameInstance_NoRegister()
	{
		return UCarsGameInstance::StaticClass();
	}
	struct Z_Construct_UClass_UCarsGameInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StartingWidgetClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_StartingWidgetClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentWidget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CurrentWidget;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCarsGameInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_Cars,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCarsGameInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCarsGameInstance_ChangeMenuWidget, "ChangeMenuWidget" }, // 2589450731
		{ &Z_Construct_UFunction_UCarsGameInstance_OnClientButtonClick, "OnClientButtonClick" }, // 1735537277
		{ &Z_Construct_UFunction_UCarsGameInstance_OnServerButtonClick, "OnServerButtonClick" }, // 1841593244
		{ &Z_Construct_UFunction_UCarsGameInstance_OnServerStartButtonClick, "OnServerStartButtonClick" }, // 1922858385
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCarsGameInstance_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
		{ "IncludePath", "CarsGameInstance.h" },
		{ "ModuleRelativePath", "CarsGameInstance.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCarsGameInstance_Statics::NewProp_StartingWidgetClass_MetaData[] = {
		{ "Category", "CarsNet" },
		{ "ModuleRelativePath", "CarsGameInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UCarsGameInstance_Statics::NewProp_StartingWidgetClass = { "StartingWidgetClass", nullptr, (EPropertyFlags)0x0024080000000015, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCarsGameInstance, StartingWidgetClass), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UCarsGameInstance_Statics::NewProp_StartingWidgetClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCarsGameInstance_Statics::NewProp_StartingWidgetClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCarsGameInstance_Statics::NewProp_CurrentWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CarsGameInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCarsGameInstance_Statics::NewProp_CurrentWidget = { "CurrentWidget", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCarsGameInstance, CurrentWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCarsGameInstance_Statics::NewProp_CurrentWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCarsGameInstance_Statics::NewProp_CurrentWidget_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCarsGameInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCarsGameInstance_Statics::NewProp_StartingWidgetClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCarsGameInstance_Statics::NewProp_CurrentWidget,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCarsGameInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCarsGameInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCarsGameInstance_Statics::ClassParams = {
		&UCarsGameInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UCarsGameInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UCarsGameInstance_Statics::PropPointers),
		0,
		0x009000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UCarsGameInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCarsGameInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCarsGameInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCarsGameInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCarsGameInstance, 1537806021);
	template<> CARS_API UClass* StaticClass<UCarsGameInstance>()
	{
		return UCarsGameInstance::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCarsGameInstance(Z_Construct_UClass_UCarsGameInstance, &UCarsGameInstance::StaticClass, TEXT("/Script/Cars"), TEXT("UCarsGameInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCarsGameInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
