// Fill out your copyright notice in the Description page of Project Settings.

#pragma once //prevents from including the same file twice

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyObject.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class FIRSTPROJECT_API UMyObject : public UObject
{
	GENERATED_BODY()
	
public:
	UMyObject();

	//BlueprintReadWrite, BlueprintReadOnly, BlueprintWriteOnly
	UPROPERTY(BlueprintReadOnly, Category = "MyVariables") //Category macro allows us to easily sort the variables & functions in our blueprint
	float MyFloat;

	UFUNCTION(BlueprintCallable, Category = "MyFunctions")
	void MyFunction();

};
