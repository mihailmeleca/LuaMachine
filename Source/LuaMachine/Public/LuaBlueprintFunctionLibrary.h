// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LuaState.h"
#include "LuaValue.h"
#include "LuaBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class LUAMACHINE_API ULuaBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static FLuaValue LuaCreateString(FString String);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static FLuaValue LuaCreateNumber(float Value);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static FLuaValue LuaCreateInteger(int32 Value);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static FLuaValue LuaCreateBool(bool bInBool);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static FLuaValue LuaCreateTable();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static FLuaValue LuaCreateObject(UObject* InObject);

	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
	static FLuaValue LuaGetGlobalTableValue(UObject* WorldContextObject, TSubclassOf<ULuaState> State, FString Key);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static void LuaSetGlobalTableValue(UObject* WorldContextObject, TSubclassOf<ULuaState> State, FString Key, FLuaValue Value);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static FLuaValue LuaGetTableValue(UObject* WorldContextObject, TSubclassOf<ULuaState> State, FLuaValue Table, FString Key);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static FLuaValue LuaGetTableValueByIndex(UObject* WorldContextObject, TSubclassOf<ULuaState> State, FLuaValue Table, int32 Index);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static TArray<FLuaValue> LuaGetTableKeys(UObject* WorldContextObject, TSubclassOf<ULuaState> State, FLuaValue Table);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static TArray<FLuaValue> LuaGetTableValues(UObject* WorldContextObject, TSubclassOf<ULuaState> State, FLuaValue Table);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static FLuaValue LuaSetTableValue(UObject* WorldContextObject, TSubclassOf<ULuaState> State, FLuaValue Table, FString Key, FLuaValue Value);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", AutoCreateRefTerm = "Args"))
	static FLuaValue LuaCallGlobalFunction(UObject* WorldContextObject, TSubclassOf<ULuaState> LuaState, FString FunctionName, TArray<FLuaValue> Args);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", AutoCreateRefTerm = "Args"))
	static FLuaValue LuaCallLuaValueFunction(UObject* WorldContextObject, TSubclassOf<ULuaState> LuaState, FLuaValue Function, TArray<FLuaValue> Args);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static int32 LuaGetTop(UObject* WorldContextObject, TSubclassOf<ULuaState> State);

	UFUNCTION(BlueprintPure, meta=(BlueprintAutocast))
	static FString Conv_LuaValueToString(FLuaValue Value);

	UFUNCTION(BlueprintPure, meta = (BlueprintAutocast))
	static UObject* Conv_LuaValueToObject(FLuaValue Value);

	UFUNCTION(BlueprintPure, meta = (BlueprintAutocast))
	static UClass* Conv_LuaValueToClass(FLuaValue Value);

	UFUNCTION(BlueprintPure, meta = (BlueprintAutocast))
	static FLuaValue Conv_ObjectToLuaValue(UObject* Object);

	UFUNCTION(BlueprintPure, meta = (BlueprintAutocast))
	static int32 Conv_LuaValueToInt(FLuaValue Value);

	UFUNCTION(BlueprintPure, meta = (BlueprintAutocast))
	static float Conv_LuaValueToFloat(FLuaValue Value);

	UFUNCTION(BlueprintPure, meta = (BlueprintAutocast))
	static FLuaValue Conv_IntToLuaValue(int32 Value);
	
};
